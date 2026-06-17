/*
 * File: Simulation_6Pulse_IGBT_Three_Phase.h
 *
 * Code generated for Simulink model 'Simulation_6Pulse_IGBT_Three_Phase'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jun 17 13:59:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Simulation_6Pulse_IGBT_Three_Phase_h_
#define Simulation_6Pulse_IGBT_Three_Phase_h_
#ifndef Simulation_6Pulse_IGBT_Three_Phase_COMMON_INCLUDES_
#define Simulation_6Pulse_IGBT_Three_Phase_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                 /* Simulation_6Pulse_IGBT_Three_Phase_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Simulation_6Pulse_IGBT_Three_Phase_types.h"
#include "rtGetNaN.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define Simulation_6Pulse_IGBT_Three_Phase_M (Simulation_6Pulse_IGBT_Three_M)

/* Block signals (default storage) */
typedef struct {
  real_T StateSpace_o1[15];            /* '<S46>/State-Space' */
  real_T StateSpace_o2[6];             /* '<S46>/State-Space' */
  real_T Switch;                       /* '<S20>/Switch' */
  real_T Switch_n;                     /* '<S18>/Switch' */
  real_T Kv1[3];                       /* '<S10>/Kv1' */
  real_T Kv[3];                        /* '<S10>/Kv' */
  real_T Output;                       /* '<S9>/Output' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T donotdeletethisgain;          /* '<S11>/do not delete this gain' */
  real_T RMS;                          /* '<Root>/RMS' */
  real_T donotdeletethisgain_h;        /* '<S12>/do not delete this gain' */
  real_T donotdeletethisgain_c;        /* '<S13>/do not delete this gain' */
  real_T p1;                           /* '<Root>/MATLAB Function' */
  real_T p2;                           /* '<Root>/MATLAB Function' */
  real_T p3;                           /* '<Root>/MATLAB Function' */
  real_T p4;                           /* '<Root>/MATLAB Function' */
  real_T p5;                           /* '<Root>/MATLAB Function' */
  real_T p6;                           /* '<Root>/MATLAB Function' */
} B_Simulation_6Pulse_IGBT_Thre_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T StateSpace_DSTATE[2];         /* '<S46>/State-Space' */
  real_T RMS_SqData;                   /* '<Root>/RMS' */
  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK;                  /* '<S46>/State-Space' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData[6];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<Root>/Digital Output1' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<Root>/Digital Output2' */
  int32_T DigitalOutput3_FRAC_LEN;     /* '<Root>/Digital Output3' */
  int32_T DigitalOutput4_FRAC_LEN;     /* '<Root>/Digital Output4' */
  int32_T DigitalOutput5_FRAC_LEN;     /* '<Root>/Digital Output5' */
  int_T StateSpace_IWORK[11];          /* '<S46>/State-Space' */
} DW_Simulation_6Pulse_IGBT_Thr_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product1;               /* '<Root>/Product1' */
} ConstB_Simulation_6Pulse_IGBT_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: zeros(6,1)
   * Referenced by: '<S48>/SwitchCurrents'
   */
  real_T SwitchCurrents_Value[6];

  /* Expression: S.A
   * Referenced by: '<S46>/State-Space'
   */
  real_T StateSpace_AS_param[4];

  /* Expression: S.B
   * Referenced by: '<S46>/State-Space'
   */
  real_T StateSpace_BS_param[14];

  /* Expression: S.C
   * Referenced by: '<S46>/State-Space'
   */
  real_T StateSpace_CS_param[30];

  /* Expression: S.D
   * Referenced by: '<S46>/State-Space'
   */
  real_T StateSpace_DS_param[105];

  /* Expression: S.x0
   * Referenced by: '<S46>/State-Space'
   */
  real_T StateSpace_X0_param[2];

  /* Expression: rep_seq_y
   * Referenced by: '<S9>/Look-Up Table1'
   */
  real_T LookUpTable1_tableData[3];

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S9>/Look-Up Table1'
   */
  real_T LookUpTable1_bp01Data[3];
} ConstP_Simulation_6Pulse_IGBT_T;

/* Real-time Model Data Structure */
struct tag_RTM_Simulation_6Pulse_IGB_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Simulation_6Pulse_IGBT_Thre_T Simulation_6Pulse_IGBT_Three__B;

/* Block states (default storage) */
extern DW_Simulation_6Pulse_IGBT_Thr_T Simulation_6Pulse_IGBT_Three_DW;
extern const ConstB_Simulation_6Pulse_IGBT_T Simulation_6Pulse_IGBT_T_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Simulation_6Pulse_IGBT_T Simulation_6Pulse_IGBT_T_ConstP;

/* Model entry point functions */
extern void Simulation_6Pulse_IGBT_Three_Phase_initialize(void);
extern void Simulation_6Pulse_IGBT_Three_Phase_step(void);
extern void Simulation_6Pulse_IGBT_Three_Phase_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Simulation_6Pulse_IG_T *const Simulation_6Pulse_IGBT_Three_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/0 4' : Unused code path elimination
 * Block '<S16>/1//Rsw' : Unused code path elimination
 * Block '<S16>/Switch' : Unused code path elimination
 * Block '<S22>/0 4' : Unused code path elimination
 * Block '<S22>/1//Rsw' : Unused code path elimination
 * Block '<S22>/Switch' : Unused code path elimination
 * Block '<S24>/0 4' : Unused code path elimination
 * Block '<S24>/1//Rsw' : Unused code path elimination
 * Block '<S24>/Switch' : Unused code path elimination
 * Block '<S26>/0 4' : Unused code path elimination
 * Block '<S26>/1//Rsw' : Unused code path elimination
 * Block '<S26>/Switch' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S32>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S33>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S34>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S35>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S36>/do not delete this gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Simulation_6Pulse_IGBT_Three_Phase'
 * '<S1>'   : 'Simulation_6Pulse_IGBT_Three_Phase/DC Voltage Source'
 * '<S2>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode'
 * '<S3>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode1'
 * '<S4>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode2'
 * '<S5>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode3'
 * '<S6>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode4'
 * '<S7>'   : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode5'
 * '<S8>'   : 'Simulation_6Pulse_IGBT_Three_Phase/MATLAB Function'
 * '<S9>'   : 'Simulation_6Pulse_IGBT_Three_Phase/Repeating Sequence'
 * '<S10>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement'
 * '<S11>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement'
 * '<S12>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement1'
 * '<S13>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement2'
 * '<S14>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui'
 * '<S15>'  : 'Simulation_6Pulse_IGBT_Three_Phase/DC Voltage Source/Model'
 * '<S16>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode/Model'
 * '<S17>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode/Model/Measurement list'
 * '<S18>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode1/Model'
 * '<S19>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode1/Model/Measurement list'
 * '<S20>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode2/Model'
 * '<S21>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode2/Model/Measurement list'
 * '<S22>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode3/Model'
 * '<S23>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode3/Model/Measurement list'
 * '<S24>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode4/Model'
 * '<S25>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode4/Model/Measurement list'
 * '<S26>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode5/Model'
 * '<S27>'  : 'Simulation_6Pulse_IGBT_Three_Phase/IGBT//Diode5/Model/Measurement list'
 * '<S28>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Mode I'
 * '<S29>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Mode V'
 * '<S30>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model'
 * '<S31>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I A:'
 * '<S32>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I B:'
 * '<S33>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I C:'
 * '<S34>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U AB:'
 * '<S35>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U BC:'
 * '<S36>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U CA:'
 * '<S37>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I A:/Model'
 * '<S38>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I B:/Model'
 * '<S39>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/I C:/Model'
 * '<S40>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U AB:/Model'
 * '<S41>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U BC:/Model'
 * '<S42>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Three-Phase V-I Measurement/Model/U CA:/Model'
 * '<S43>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement/Model'
 * '<S44>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement1/Model'
 * '<S45>'  : 'Simulation_6Pulse_IGBT_Three_Phase/Voltage Measurement2/Model'
 * '<S46>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui/EquivalentModel1'
 * '<S47>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui/EquivalentModel1/Gates'
 * '<S48>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui/EquivalentModel1/Sources'
 * '<S49>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui/EquivalentModel1/Status'
 * '<S50>'  : 'Simulation_6Pulse_IGBT_Three_Phase/powergui/EquivalentModel1/Yout'
 */
#endif                               /* Simulation_6Pulse_IGBT_Three_Phase_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
