/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.29
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package de.swarmnet.shawn;

public class NeighborhoodConst extends RefcntPointable {
  private long swigCPtr;

  protected NeighborhoodConst(long cPtr, boolean cMemoryOwn) {
    super(ShawnJNI.SWIGNeighborhoodConstUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(NeighborhoodConst obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      ShawnJNI.delete_NeighborhoodConst(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

  public NeighborhoodConst() {
    this(ShawnJNI.new_NeighborhoodConst(), true);
  }

}
