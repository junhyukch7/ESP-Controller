/*
 * ESP.cpp
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

#include "ESP.h"
#include "ESP_private.h"

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void ESPModelClass::step()
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<Root>/ESP Controller' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  /* Inport: '<Root>/Trigger' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&ESP_PrevZCX.ESPController_Trig_ZCE,
                     (ESP_U.Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Outport: '<Root>/ESP Moment' incorporates:
     *  Fcn: '<S1>/gamma_d'
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/SteerAngle'
     *  Inport: '<Root>/Vx'
     *  Inport: '<Root>/YawRate'
     *  Sum: '<S1>/Sum'
     */
    ESP_Y.ESPMoment = (ESP_U.Vx / (3.2 - -0.001624861291906968 * rt_powd_snf
      (ESP_U.Vx, 2.0)) * ESP_U.SteerAngle - ESP_U.YawRate) * ESP_P.Ke;
  }

  /* End of Outputs for SubSystem: '<Root>/ESP Controller' */

  /* Matfile logging */
  rt_UpdateTXYLogVars((&ESP_M)->rtwLogInfo, (&(&ESP_M)->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.4s, 0.0s] */
    if ((rtmGetTFinal((&ESP_M))!=-1) &&
        !((rtmGetTFinal((&ESP_M))-(&ESP_M)->Timing.taskTime0) > (&ESP_M)
          ->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus((&ESP_M), "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++(&ESP_M)->Timing.clockTick0)) {
    ++(&ESP_M)->Timing.clockTickH0;
  }

  (&ESP_M)->Timing.taskTime0 = (&ESP_M)->Timing.clockTick0 * (&ESP_M)
    ->Timing.stepSize0 + (&ESP_M)->Timing.clockTickH0 * (&ESP_M)
    ->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ESPModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal((&ESP_M), 20.0);
  (&ESP_M)->Timing.stepSize0 = 0.4;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&ESP_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&ESP_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&ESP_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&ESP_M)->rtwLogInfo, "tout");
    rtliSetLogX((&ESP_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&ESP_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&ESP_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&ESP_M)->rtwLogInfo, 0);
    rtliSetLogMaxRows((&ESP_M)->rtwLogInfo, 1000);
    rtliSetLogDecimation((&ESP_M)->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[1];
      rt_LoggedOutputSignalPtrs[0] = &ESP_Y.ESPMoment;
      rtliSetLogYSignalPtrs((&ESP_M)->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "ESP/ESP Moment" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo((&ESP_M)->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY((&ESP_M)->rtwLogInfo, "yout");
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&ESP_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&ESP_M)), (&ESP_M)->Timing.stepSize0, (&rtmGetErrorStatus((&ESP_M))));
  ESP_PrevZCX.ESPController_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void ESPModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
ESPModelClass::ESPModelClass():
  ESP_PrevZCX()
  ,ESP_U()
  ,ESP_Y()
  ,ESP_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
ESPModelClass::~ESPModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_ESP_T * ESPModelClass::getRTM()
{
  return (&ESP_M);
}
