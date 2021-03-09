/*
 * ESP.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ESP".
 *
 * Model version              : 1.62
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Mar  8 19:43:05 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ESP_h_
#define RTW_HEADER_ESP_h_
#include <cmath>
#include <math.h>
#include <cfloat>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "ESP_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ESPController_Trig_ZCE;   /* '<Root>/ESP Controller' */
} PrevZCX_ESP_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T YawRate;                      /* '<Root>/YawRate' */
  real_T Vx;                           /* '<Root>/Vx' */
  real_T SteerAngle;                   /* '<Root>/SteerAngle' */
  real_T Trigger;                      /* '<Root>/Trigger' */
} ExtU_ESP_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ESPMoment;                    /* '<Root>/ESP Moment' */
} ExtY_ESP_T;

/* Parameters (default storage) */
struct P_ESP_T_ {
  real_T Ke;                           /* Variable: Ke
                                        * Referenced by: '<S1>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ESP_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Class declaration for model ESP */
class ESPModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ESPModelClass();

  /* Destructor */
  ~ESPModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_ESP_T* pExtU_ESP_T)
  {
    ESP_U = *pExtU_ESP_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_ESP_T & getExternalOutputs() const
  {
    return ESP_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_ESP_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_ESP_T ESP_P;
  PrevZCX_ESP_T ESP_PrevZCX;           /* Triggered events */

  /* External inputs */
  ExtU_ESP_T ESP_U;

  /* External outputs */
  ExtY_ESP_T ESP_Y;

  /* Real-Time Model */
  RT_MODEL_ESP_T ESP_M;
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('laterl_model_esp/ESP Controller')    - opens subsystem laterl_model_esp/ESP Controller
 * hilite_system('laterl_model_esp/ESP Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'laterl_model_esp'
 * '<S1>'   : 'laterl_model_esp/ESP Controller'
 */
#endif                                 /* RTW_HEADER_ESP_h_ */
