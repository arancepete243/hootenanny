/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package hoot;

public class PbfInputFormat {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected PbfInputFormat(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(PbfInputFormat obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        hootJNI.delete_PbfInputFormat(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public static String className() {
    return hootJNI.PbfInputFormat_className();
  }

  public PbfInputFormat() {
    this(hootJNI.new_PbfInputFormat(), true);
  }

  public PbfInputSplit getSplit(int i) {
    return new PbfInputSplit(hootJNI.PbfInputFormat_getSplit(swigCPtr, this, i), false);
  }

  public int getSplitCount() {
    return hootJNI.PbfInputFormat_getSplitCount(swigCPtr, this);
  }

  public void setConfiguration(SWIGTYPE_p_pp__Configuration conf) {
    hootJNI.PbfInputFormat_setConfiguration(swigCPtr, this, SWIGTYPE_p_pp__Configuration.getCPtr(conf));
  }

}
