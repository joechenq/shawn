/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#ifndef __SHAWN_APPS_LOCALIZATION_MODULES_DISTANCE_GPSFREE_LCS_MODULE_H
#define __SHAWN_APPS_LOCALIZATION_MODULES_DISTANCE_GPSFREE_LCS_MODULE_H

#include "_apps_enable_cmake.h"
#ifdef ENABLE_LOCALIZATION

#include "sys/node.h"
#include "apps/localization/modules/localization_module.h"
#include "apps/localization/messages/distance/localization_gpsfree_lcs_messages.h"
#include "apps/localization/util/localization_defutils.h"


namespace localization
{

   /// Module that implements GPS-free Local Coordinate System building
   /** This module implements the algorithm to get a local coordinate system
    *  just like described in <em>GPS-free positioning in moblie ad hoc
    *  networks</em> by Capkun, Hamdi, Hubeaux.
    *
    *  At first nodes build their 2-hop neighborhood by sending an initial
    *  message, receive initial messages from neighbors and send again a
    *  message contending constructed neighborhood to surrounding nodes.
    *
    *  After that nodes build their local coordinate system. [...]
    *  <hr>
    *
    *  <b>Comment by the author</b>
    *  This is not a full implementation of the above mentioned paper. Up to
    *  now there are two parts missing: On the one hand (just a little thing)
    *  the computation per triangulation of unknown nodes (the stuff with the
    *  node k, which is not neighbor of p and q and should be computed by
    *  using the position of node i and two other nodes for which the
    *  positions are already obtained) has not be done. On the other hand
    *  (the big part) the whole stuff with the Location Reference Group is
    *  still missing.
    *
    *  I think, that these parts are useless unless the algorithm has been
    *  optimized in two ways. First the nearly unrelevant one: By choosing
    *  nodes p and q to maximize the number of regular nodes in the LVS
    *  (see LocalizationGPSfreeLCSModule::build_lcs()), the
    *  "up-to-now-solution" is a very unfortunaletly one, because the
    *  computation overhead is really big. Second (in my opinion the main
    *  argument against using this algorithm unless there appears a better
    *  solution) there is a problem with the triangulisation in the paper
    *  (see formula (3), deciding, on which side of the x-axis a node is
    *  located) and errors in distance measurement. The author mentioned, that
    *  the two angles can not be equal in practice and that some differences
    *  should be tolerated. Unfortunaletly I hadn't found any <em>epsilon</em>
    *  leading to satisfactorily solutions. Maybe it is an approach to look
    *  at the papers of K. Langendoen and D. Niculesco and their handling
    *  of the similar "euclidean-problem".
    */
   class LocalizationGPSfreeLCSModule
      : public LocalizationModule
   {

   public:

      ///@name construction / destruction
      ///@{
      ///
      LocalizationGPSfreeLCSModule();
      ///
      virtual ~LocalizationGPSfreeLCSModule();
      ///@}


      ///@name standard methods startup/simulation steps
      ///@{
      /** Read given parameters.
       *
       *  \sa init_parameters(), LocalizationModule::boot()
       */
      virtual void boot( void ) throw();
      /** Handling of GPS-free-LCS-Messages.
       *
       *  \sa LocalizationModule::process_message()
       */
      virtual bool process_message( const shawn::ConstMessageHandle& ) throw();
      /** Check, whether state can be set to finished or not. Moreover, send
       *  initial messages and build local coordinate system.
       *
       *  \sa LocalizationModule::work()
       */
      virtual void work( void ) throw();
      ///@}


      ///@name module status info
      ///@{
      /** \return \c true, if module is finished. \c false otherwise
       *  \sa LocalizationModule::finished()
       */
      virtual bool finished( void ) throw();
      ///@}
		virtual void rollback( void ) throw();

   protected:

      ///@name processing gpsfree lcs messages
      ///@{
      /** This method processes initial messages. Source of message is added
       *  to neighborhood.
       *
       *  \sa LocalizationEuclideanInitMessage
       */
      virtual bool process_gpsfree_lcs_init_message(
            const LocalizationGPSfreeLCSInitMessage& )
         throw();
      /** This method broadcasts the neighborhood generated by the initial
       *  messages.
       *
       *  \sa LocalizationEuclideanNeighborMessage
       */
      virtual void broadcast_neighborhood( void ) throw();
      /** This method processes neighborhood messages. The neighbors of
       *  message source are added to neighborhood.
       *
       *  \sa LocalizationEuclideanNeighborMessage
       */
      virtual bool process_gpsfree_lcs_neighbor_message(
            const LocalizationGPSfreeLCSNeighborMessage& )
         throw();
      ///@}

      ///@name work
      ///@{
      /** Build a local coordinate system just like described in the paper.
       */
      virtual void build_lcs( void ) throw();
      ///@}

      ///@name initial methods
      ///@{
      /** Read the given parameters, which have been set via simulator
       *  commands or configuration file.
       */
      virtual void init_parameters( void ) throw();
      ///@}


   private:

      enum GPSfreeLCSState
      {
         gflcs_init,
         gflcs_wait_bc,
         gflcs_broadcast,
         gflcs_wait_w,
         gflcs_work,
         gflcs_finished
      };


      GPSfreeLCSState state_;

      int last_useful_msg_;

   };

}// namespace localization
#endif
#endif
/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/localization/modules/distance/localization_gpsfree_lcs_module.h,v $
 * Version $Revision: 197 $
 * Date    $Date: 2008-04-29 17:40:51 +0200 (Tue, 29 Apr 2008) $
 *-----------------------------------------------------------------------
 * $Log: localization_gpsfree_lcs_module.h,v $
 *-----------------------------------------------------------------------*/
