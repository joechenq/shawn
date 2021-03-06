/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.29
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package de.swarmnet.shawn;

public class Processor extends RefcntPointable {
  private long swigCPtr;

  protected Processor(long cPtr, boolean cMemoryOwn) {
    super(ShawnJNI.SWIGProcessorUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Processor obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      ShawnJNI.delete_Processor(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

  public Processor() {
    this(ShawnJNI.new_Processor(), true);
  }

  public void set_owner(Node arg0) {
    ShawnJNI.Processor_set_owner(swigCPtr, Node.getCPtr(arg0));
  }

  public Node owner() {
    return new Node(ShawnJNI.Processor_owner(swigCPtr), false);
  }

  public Node owner_w() {
    return new Node(ShawnJNI.Processor_owner_w(swigCPtr), false);
  }

  public void special_boot() {
    ShawnJNI.Processor_special_boot(swigCPtr);
  }

  public void boot() {
    ShawnJNI.Processor_boot(swigCPtr);
  }

  public boolean process_message(SWIGTYPE_p_shawn__RefcntPointerTshawn__Message_const_t arg0) {
    return ShawnJNI.Processor_process_message(swigCPtr, SWIGTYPE_p_shawn__RefcntPointerTshawn__Message_const_t.getCPtr(arg0));
  }

  public void work() {
    ShawnJNI.Processor_work(swigCPtr);
  }

  public int id() {
    return ShawnJNI.Processor_id(swigCPtr);
  }

  public Processor.ProcessorState state() {
    return Processor.ProcessorState.swigToEnum(ShawnJNI.Processor_state(swigCPtr));
  }

  public boolean auto_terminate() {
    return ShawnJNI.Processor_auto_terminate(swigCPtr);
  }

  public int simulation_round() {
    return ShawnJNI.Processor_simulation_round(swigCPtr);
  }

  public void sync_to_tags(TagContainer arg0) {
    ShawnJNI.Processor_sync_to_tags(swigCPtr, TagContainer.getCPtr(arg0));
  }

  public void sync_from_tags(TagContainer arg0) {
    ShawnJNI.Processor_sync_from_tags(swigCPtr, TagContainer.getCPtr(arg0));
  }

  public final static class ProcessorState {
    public final static ProcessorState Active = new ProcessorState("Active");
    public final static ProcessorState Sleeping = new ProcessorState("Sleeping");
    public final static ProcessorState Inactive = new ProcessorState("Inactive");

    public final int swigValue() {
      return swigValue;
    }

    public String toString() {
      return swigName;
    }

    public static ProcessorState swigToEnum(int swigValue) {
      if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
        return swigValues[swigValue];
      for (int i = 0; i < swigValues.length; i++)
        if (swigValues[i].swigValue == swigValue)
          return swigValues[i];
      throw new IllegalArgumentException("No enum " + ProcessorState.class + " with value " + swigValue);
    }

    private ProcessorState(String swigName) {
      this.swigName = swigName;
      this.swigValue = swigNext++;
    }

    private ProcessorState(String swigName, int swigValue) {
      this.swigName = swigName;
      this.swigValue = swigValue;
      swigNext = swigValue+1;
    }

    private ProcessorState(String swigName, ProcessorState swigEnum) {
      this.swigName = swigName;
      this.swigValue = swigEnum.swigValue;
      swigNext = this.swigValue+1;
    }

    private static ProcessorState[] swigValues = { Active, Sleeping, Inactive };
    private static int swigNext = 0;
    private final int swigValue;
    private final String swigName;
  }

}
