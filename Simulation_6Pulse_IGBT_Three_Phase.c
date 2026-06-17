/*
 * File: Simulation_6Pulse_IGBT_Three_Phase.c
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

#include "Simulation_6Pulse_IGBT_Three_Phase.h"
#include <math.h>
#include "Simulation_6Pulse_IGBT_Three_Phase_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_Simulation_6Pulse_IGBT_Thre_T Simulation_6Pulse_IGBT_Three__B;

/* Block states (default storage) */
DW_Simulation_6Pulse_IGBT_Thr_T Simulation_6Pulse_IGBT_Three_DW;

/* Real-time model */
static RT_MODEL_Simulation_6Pulse_IG_T Simulation_6Pulse_IGBT_Three_M_;
RT_MODEL_Simulation_6Pulse_IG_T *const Simulation_6Pulse_IGBT_Three_M =
  &Simulation_6Pulse_IGBT_Three_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void Simulation_6Pulse_IGBT_Three_Phase_step(void)
{
  real_T Va;
  real_T Vb;
  real_T Vc;

  /* S-Function (sfun_spssw_discc): '<S46>/State-Space' incorporates:
   *  Constant: '<S15>/DC'
   *  Constant: '<S48>/SwitchCurrents'
   */

  /* S-Function block: <S46>/State-Space */
  {
    real_T accum;

    /* Circuit has switches */
    int_T *switch_status = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS;
    int_T *switch_status_init = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;
    int_T *SwitchChange = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SW_CHG;
    int_T *gState = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.G_STATE;
    real_T *yswitch = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.Y_SWITCH;
    int_T *switchTypes = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_TYPES;
    int_T *idxOutSw = (int_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.IDX_OUT_SW;
    real_T *DxCol = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DX_COL;
    real_T *tmp2 = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP2;
    real_T *BDcol = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BD_COL;
    real_T *tmp1 = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP1;
    real_T *uswlast = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.USWLAST;
    int_T newState;
    int_T swChanged = 0;
    int loopsToDo = 20;
    real_T temp;

    /* keep an initial copy of switch_status*/
    memcpy(switch_status_init, switch_status, 6 * sizeof(int_T));
    memcpy(uswlast, &Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[0], 6*sizeof
           (real_T));
    do {
      if (loopsToDo == 1) {            /* Need to reset some variables: */
        swChanged = 0;

        /* return to the original switch status*/
        {
          int_T i1;
          for (i1=0; i1 < 6; i1++) {
            swChanged = ((SwitchChange[i1] = switch_status_init[i1] -
                          switch_status[i1]) != 0) ? 1 : swChanged;
            switch_status[i1] = switch_status_init[i1];
          }
        }
      } else {
        /*
         * Compute outputs:
         * ---------------
         */
        real_T *Cs = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS;
        real_T *Ds = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS;

        {
          int_T i1;
          real_T *y0 = &Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[0];
          for (i1=0; i1 < 15; i1++) {
            accum = 0.0;
            accum += *(Cs++) *
              Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0];
            accum += *(Cs++) *
              Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[1];

            {
              int_T i2;
              const real_T *u0 =
                Simulation_6Pulse_IGBT_T_ConstP.SwitchCurrents_Value;
              for (i2=0; i2 < 6; i2++) {
                accum += *(Ds++) * u0[i2];
              }

              accum += *(Ds++) * 100.0;
            }

            y0[i1] = accum;
          }
        }

        swChanged = 0;

        {
          int_T i1;
          real_T *y0 = &Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[0];
          for (i1=0; i1 < 6; i1++) {
            newState = ((y0[i1] > 0.0) && (gState[i1] > 0)) || (y0[i1] < 0.0) ?
              1 : (((y0[i1] > 0.0) && gState[i1] == 0) ? 0 : switch_status[i1]);
            swChanged = ((SwitchChange[i1] = newState - switch_status[i1]) != 0)
              ? 1 : swChanged;
            switch_status[i1] = newState;/* Keep new state */
          }
        }
      }

      /*
       * Compute new As, Bs, Cs and Ds matrixes:
       * --------------------------------------
       */
      if (swChanged) {
        real_T *As = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.AS;
        real_T *Cs = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS;
        real_T *Bs = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BS;
        real_T *Ds = (real_T*)
          Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS;
        real_T a1;

        {
          int_T i1;
          for (i1=0; i1 < 6; i1++) {
            if (SwitchChange[i1] != 0) {
              a1 = 1000.0*SwitchChange[i1];
              temp = 1/(1-Ds[i1*8]*a1);

              {
                int_T i2;
                for (i2=0; i2 < 15; i2++) {
                  DxCol[i2]= Ds[i2 * 7 + i1]*temp*a1;
                }
              }

              DxCol[i1] = temp;
              BDcol[0]= Bs[0 + i1]*a1;
              BDcol[1]= Bs[7 + i1]*a1;

              /* Copy row nSw of Cs into tmp1 and zero it out in Cs */
              memcpy(tmp1, &Cs[i1 * 2], 2 * sizeof(real_T));
              memset(&Cs[i1 * 2], '\0', 2 * sizeof(real_T));

              /* Copy row nSw of Ds into tmp2 and zero it out in Ds */
              memcpy(tmp2, &Ds[i1 * 7], 7 * sizeof(real_T));
              memset(&Ds[i1 * 7], '\0', 7 * sizeof(real_T));

              /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/
              {
                int_T i2;
                for (i2=0; i2 < 15; i2++) {
                  a1 = DxCol[i2];
                  Cs[i2 * 2 + 0] += a1 * tmp1[0];
                  Cs[i2 * 2 + 1] += a1 * tmp1[1];

                  {
                    int_T i3;
                    for (i3=0; i3 < 7; i3++) {
                      Ds[i2 * 7 + i3] += a1 * tmp2[i3];
                    }
                  }
                }
              }

              /* As = As + BdCol*Cs(nSw,:), Bs = Bs + BdCol*Ds(nSw,:) *************/
              a1 = BDcol[0];
              As[0 + 0] += a1 * Cs[i1 * 2 + 0];
              As[0 + 1] += a1 * Cs[i1 * 2 + 1];

              {
                int_T i2;
                for (i2=0; i2 < 7; i2++) {
                  Bs[0 + i2] += a1 * Ds[i1 * 7 + i2];
                }
              }

              a1 = BDcol[1];
              As[2 + 0] += a1 * Cs[i1 * 2 + 0];
              As[2 + 1] += a1 * Cs[i1 * 2 + 1];

              {
                int_T i2;
                for (i2=0; i2 < 7; i2++) {
                  Bs[7 + i2] += a1 * Ds[i1 * 7 + i2];
                }
              }
            }
          }
        }
      }                                /* if (swChanged) */
    } while (swChanged > 0 && --loopsToDo > 0);

    if (loopsToDo == 0) {
      real_T *Cs = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS;

      {
        int_T i1;
        real_T *y0 = &Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[0];
        for (i1=0; i1 < 15; i1++) {
          accum = 0.0;
          accum += *(Cs++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0];
          accum += *(Cs++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[1];

          {
            int_T i2;
            const real_T *u0 =
              Simulation_6Pulse_IGBT_T_ConstP.SwitchCurrents_Value;
            for (i2=0; i2 < 6; i2++) {
              accum += *(Ds++) * u0[i2];
            }

            accum += *(Ds++) * 100.0;
          }

          y0[i1] = accum;
        }
      }
    }

    /* Output new switches states */
    {
      int_T i1;
      real_T *y1 = &Simulation_6Pulse_IGBT_Three__B.StateSpace_o2[0];
      for (i1=0; i1 < 6; i1++) {
        y1[i1] = (real_T)switch_status[i1];
      }
    }
  }

  /* Switch: '<S20>/Switch' */
  if (Simulation_6Pulse_IGBT_Three__B.StateSpace_o2[2] >= 0.5) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Gain: '<S20>/1//Rsw'
     */
    Simulation_6Pulse_IGBT_Three__B.Switch = 1000.0 *
      Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[2];
  } else {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/0 4'
     */
    Simulation_6Pulse_IGBT_Three__B.Switch = 0.0;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S18>/Switch' */
  if (Simulation_6Pulse_IGBT_Three__B.StateSpace_o2[1] >= 0.5) {
    /* Switch: '<S18>/Switch' incorporates:
     *  Gain: '<S18>/1//Rsw'
     */
    Simulation_6Pulse_IGBT_Three__B.Switch_n = 1000.0 *
      Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[1];
  } else {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/0 4'
     */
    Simulation_6Pulse_IGBT_Three__B.Switch_n = 0.0;
  }

  /* End of Switch: '<S18>/Switch' */
  /* Gain: '<S10>/Kv1' */
  Simulation_6Pulse_IGBT_Three__B.Kv1[0] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[6];

  /* Gain: '<S10>/Kv' */
  Simulation_6Pulse_IGBT_Three__B.Kv[0] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[12];

  /* Gain: '<S10>/Kv1' */
  Simulation_6Pulse_IGBT_Three__B.Kv1[1] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[7];

  /* Gain: '<S10>/Kv' */
  Simulation_6Pulse_IGBT_Three__B.Kv[1] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[13];

  /* Gain: '<S10>/Kv1' */
  Simulation_6Pulse_IGBT_Three__B.Kv1[2] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[8];

  /* Gain: '<S10>/Kv' */
  Simulation_6Pulse_IGBT_Three__B.Kv[2] =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[14];

  /* SignalConversion: '<S9>/Output' incorporates:
   *  Clock: '<S9>/Clock'
   *  Constant: '<S9>/Constant'
   *  Lookup_n-D: '<S9>/Look-Up Table1'
   *  Math: '<S9>/Math Function'
   */
  Simulation_6Pulse_IGBT_Three__B.Output = look1_binlxpw(fmod
    (Simulation_6Pulse_IGBT_Three_M->Timing.t[0], 5.0E-5),
    Simulation_6Pulse_IGBT_T_ConstP.LookUpTable1_bp01Data,
    Simulation_6Pulse_IGBT_T_ConstP.LookUpTable1_tableData, 2UL);

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   *  DigitalClock: '<Root>/Digital Clock'
   *  Math: '<Root>/Math Function'
   *  Product: '<Root>/Product'
   */
  Simulation_6Pulse_IGBT_Three__B.Gain = rt_modd_snf
    (Simulation_6Pulse_IGBT_T_ConstB.Product1 *
     (((Simulation_6Pulse_IGBT_Three_M->Timing.clockTick1+
        Simulation_6Pulse_IGBT_Three_M->Timing.clockTickH1* 4294967296.0)) *
      1.0E-6), 1.0) * 6.2831853071795862;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Va = 0.8 * sin(Simulation_6Pulse_IGBT_Three__B.Gain);
  Vb = sin(Simulation_6Pulse_IGBT_Three__B.Gain - 2.0943951023931953) * 0.8;
  Vc = sin(Simulation_6Pulse_IGBT_Three__B.Gain + 2.0943951023931953) * 0.8;
  Simulation_6Pulse_IGBT_Three__B.p1 = (Va >
    Simulation_6Pulse_IGBT_Three__B.Output + 0.05);
  Simulation_6Pulse_IGBT_Three__B.p2 = (Va <
    Simulation_6Pulse_IGBT_Three__B.Output - 0.05);
  Simulation_6Pulse_IGBT_Three__B.p3 = (Vb >
    Simulation_6Pulse_IGBT_Three__B.Output + 0.05);
  Simulation_6Pulse_IGBT_Three__B.p4 = (Vb <
    Simulation_6Pulse_IGBT_Three__B.Output - 0.05);
  Simulation_6Pulse_IGBT_Three__B.p5 = (Vc >
    Simulation_6Pulse_IGBT_Three__B.Output + 0.05);
  Simulation_6Pulse_IGBT_Three__B.p6 = (Vc <
    Simulation_6Pulse_IGBT_Three__B.Output - 0.05);

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p1) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p2) {
      GpioDataRegs.GPASET.bit.GPIO1 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO1 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output2' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p3) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output3' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p4) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output4' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p5) {
      GpioDataRegs.GPASET.bit.GPIO4 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO4 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output5' */
  {
    if (Simulation_6Pulse_IGBT_Three__B.p6) {
      GpioDataRegs.GPASET.bit.GPIO5 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO5 = 1U;
    }
  }

  /* Gain: '<S11>/do not delete this gain' */
  Simulation_6Pulse_IGBT_Three__B.donotdeletethisgain =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[9];

  /* S-Function (sdspstatfcns): '<Root>/RMS' */
  Simulation_6Pulse_IGBT_Three__B.RMS = fabs
    (Simulation_6Pulse_IGBT_Three__B.donotdeletethisgain);

  /* Gain: '<S12>/do not delete this gain' */
  Simulation_6Pulse_IGBT_Three__B.donotdeletethisgain_h =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[10];

  /* Gain: '<S13>/do not delete this gain' */
  Simulation_6Pulse_IGBT_Three__B.donotdeletethisgain_c =
    Simulation_6Pulse_IGBT_Three__B.StateSpace_o1[11];

  /* Update for S-Function (sfun_spssw_discc): '<S46>/State-Space' incorporates:
   *  Constant: '<S15>/DC'
   *  Constant: '<S48>/SwitchCurrents'
   */

  /* S-Function block: <S46>/State-Space */
  {
    const real_T *As = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.AS;
    const real_T *Bs = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BS;
    real_T *xtmp = (real_T*)
      Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.XTMP;
    real_T accum;

    /* Calculate new states... */
    accum = 0.0;
    accum += *(As++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0];
    accum += *(As++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[1];

    {
      int_T i1;
      const real_T *u0 = Simulation_6Pulse_IGBT_T_ConstP.SwitchCurrents_Value;
      for (i1=0; i1 < 6; i1++) {
        accum += *(Bs++) * u0[i1];
      }

      accum += *(Bs++) * 100.0;
    }

    xtmp[0] = accum;
    accum = 0.0;
    accum += *(As++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0];
    accum += *(As++) * Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[1];

    {
      int_T i1;
      const real_T *u0 = Simulation_6Pulse_IGBT_T_ConstP.SwitchCurrents_Value;
      for (i1=0; i1 < 6; i1++) {
        accum += *(Bs++) * u0[i1];
      }

      accum += *(Bs++) * 100.0;
    }

    xtmp[1] = accum;
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0] = xtmp[0];
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[1] = xtmp[1];

    {
      int_T *gState = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.G_STATE;

      /* Store switch gates values for next step */
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p1;
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p3;
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p5;
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p2;
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p4;
      *(gState++) = (int_T) Simulation_6Pulse_IGBT_Three__B.p6;
    }
  }

  {                                    /* Sample time: [1.0E-6s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      (((Simulation_6Pulse_IGBT_Three_M->Timing.clockTick1+
         Simulation_6Pulse_IGBT_Three_M->Timing.clockTickH1* 4294967296.0) * 1)
       + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
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
  if (!(++Simulation_6Pulse_IGBT_Three_M->Timing.clockTick0)) {
    ++Simulation_6Pulse_IGBT_Three_M->Timing.clockTickH0;
  }

  Simulation_6Pulse_IGBT_Three_M->Timing.t[0] =
    Simulation_6Pulse_IGBT_Three_M->Timing.clockTick0 *
    Simulation_6Pulse_IGBT_Three_M->Timing.stepSize0 +
    Simulation_6Pulse_IGBT_Three_M->Timing.clockTickH0 *
    Simulation_6Pulse_IGBT_Three_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.0E-6s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-6, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Simulation_6Pulse_IGBT_Three_M->Timing.clockTick1++;
    if (!Simulation_6Pulse_IGBT_Three_M->Timing.clockTick1) {
      Simulation_6Pulse_IGBT_Three_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Simulation_6Pulse_IGBT_Three_Phase_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Simulation_6Pulse_IGBT_Three_M, 0,
                sizeof(RT_MODEL_Simulation_6Pulse_IG_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                          &Simulation_6Pulse_IGBT_Three_M->Timing.simTimeStep);
    rtsiSetTPtr(&Simulation_6Pulse_IGBT_Three_M->solverInfo, &rtmGetTPtr
                (Simulation_6Pulse_IGBT_Three_M));
    rtsiSetStepSizePtr(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                       &Simulation_6Pulse_IGBT_Three_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                          (&rtmGetErrorStatus(Simulation_6Pulse_IGBT_Three_M)));
    rtsiSetRTModelPtr(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                      Simulation_6Pulse_IGBT_Three_M);
  }

  rtsiSetSimTimeStep(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&Simulation_6Pulse_IGBT_Three_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Simulation_6Pulse_IGBT_Three_M->solverInfo, false);
  rtsiSetSolverName(&Simulation_6Pulse_IGBT_Three_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Simulation_6Pulse_IGBT_Three_M,
             &Simulation_6Pulse_IGBT_Three_M->Timing.tArray[0]);
  rtmSetTFinal(Simulation_6Pulse_IGBT_Three_M, 0.002);
  Simulation_6Pulse_IGBT_Three_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  Simulation_6Pulse_IGBT_Three_M->Sizes.checksums[0] = (2790590394U);
  Simulation_6Pulse_IGBT_Three_M->Sizes.checksums[1] = (1978874867U);
  Simulation_6Pulse_IGBT_Three_M->Sizes.checksums[2] = (2902001351U);
  Simulation_6Pulse_IGBT_Three_M->Sizes.checksums[3] = (899798885U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Simulation_6Pulse_IGBT_Three_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Simulation_6Pulse_IGBT_Three_M->extModeInfo,
      &Simulation_6Pulse_IGBT_Three_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Simulation_6Pulse_IGBT_Three_M->extModeInfo,
                        Simulation_6Pulse_IGBT_Three_M->Sizes.checksums);
    rteiSetTFinalTicks(Simulation_6Pulse_IGBT_Three_M->extModeInfo, 2000);
  }

  /* block I/O */
  (void) memset(((void *) &Simulation_6Pulse_IGBT_Three__B), 0,
                sizeof(B_Simulation_6Pulse_IGBT_Thre_T));

  /* states (dwork) */
  (void) memset((void *)&Simulation_6Pulse_IGBT_Three_DW, 0,
                sizeof(DW_Simulation_6Pulse_IGBT_Thr_T));

  /* Start for S-Function (sfun_spssw_discc): '<S46>/State-Space' incorporates:
   *  Constant: '<S15>/DC'
   *  Constant: '<S48>/SwitchCurrents'
   */

  /* S-Function block: <S46>/State-Space */
  {
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.AS = (real_T*)calloc(2 * 2,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BS = (real_T*)calloc(2 * 7,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS = (real_T*)calloc(15 * 2,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS = (real_T*)calloc(15 * 7,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DX_COL = (real_T*)calloc(15,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP2 = (real_T*)calloc(7,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BD_COL = (real_T*)calloc(2,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP1 = (real_T*)calloc(2,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.XTMP = (real_T*)calloc(2,
      sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS = (int_T*)
      calloc(6, sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SW_CHG = (int_T*)calloc(6,
      sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.G_STATE = (int_T*)calloc(6,
      sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.Y_SWITCH = (real_T*)calloc
      (6, sizeof(real_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_TYPES = (int_T*)
      calloc(6, sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.IDX_OUT_SW = (int_T*)calloc
      (6, sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS_INIT = (int_T*)
      calloc(6, sizeof(int_T));
    Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.USWLAST = (real_T*)calloc(6,
      sizeof(real_T));
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFF3U;
  GpioCtrlRegs.GPADIR.all |= 0x2U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output2' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPADIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output3' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFF3FU;
  GpioCtrlRegs.GPADIR.all |= 0x8U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output4' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFCFFU;
  GpioCtrlRegs.GPADIR.all |= 0x10U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output5' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFF3FFU;
  GpioCtrlRegs.GPADIR.all |= 0x20U;
  EDIS;

  /* InitializeConditions for S-Function (sfun_spssw_discc): '<S46>/State-Space' incorporates:
   *  Constant: '<S15>/DC'
   *  Constant: '<S48>/SwitchCurrents'
   */
  {
    int32_T i, j;
    real_T *As = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.AS;
    real_T *Bs = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BS;
    real_T *Cs = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS;
    real_T *Ds = (real_T*)Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS;
    real_T *X0 = (real_T*)&Simulation_6Pulse_IGBT_Three_DW.StateSpace_DSTATE[0];
    for (i = 0; i < 2; i++) {
      X0[i] = (Simulation_6Pulse_IGBT_T_ConstP.StateSpace_X0_param[i]);
    }

    /* Copy and transpose A and B */
    for (i=0; i<2; i++) {
      for (j=0; j<2; j++)
        As[i*2 + j] = (Simulation_6Pulse_IGBT_T_ConstP.StateSpace_AS_param[i + j*
                       2]);
      for (j=0; j<7; j++)
        Bs[i*7 + j] = (Simulation_6Pulse_IGBT_T_ConstP.StateSpace_BS_param[i + j*
                       2]);
    }

    /* Copy and transpose C */
    for (i=0; i<15; i++) {
      for (j=0; j<2; j++)
        Cs[i*2 + j] = (Simulation_6Pulse_IGBT_T_ConstP.StateSpace_CS_param[i + j*
                       15]);
    }

    /* Copy and transpose D */
    for (i=0; i<15; i++) {
      for (j=0; j<7; j++)
        Ds[i*7 + j] = (Simulation_6Pulse_IGBT_T_ConstP.StateSpace_DS_param[i + j*
                       15]);
    }

    {
      /* Switches work vectors */
      int_T *switch_status = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS;
      int_T *gState = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.G_STATE;
      real_T *yswitch = (real_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.Y_SWITCH;
      int_T *switchTypes = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_TYPES;
      int_T *idxOutSw = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.IDX_OUT_SW;
      int_T *switch_status_init = (int_T*)
        Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;

      /* Initialize work vectors */
      switch_status[0] = 0;
      switch_status_init[0] = 0;
      gState[0] = (int_T) 0.0;
      yswitch[0] = 1/0.001;
      switchTypes[0] = (int_T)7.0;
      idxOutSw[0] = ((int_T)0.0) - 1;
      switch_status[1] = 0;
      switch_status_init[1] = 0;
      gState[1] = (int_T) 0.0;
      yswitch[1] = 1/0.001;
      switchTypes[1] = (int_T)7.0;
      idxOutSw[1] = ((int_T)0.0) - 1;
      switch_status[2] = 0;
      switch_status_init[2] = 0;
      gState[2] = (int_T) 0.0;
      yswitch[2] = 1/0.001;
      switchTypes[2] = (int_T)7.0;
      idxOutSw[2] = ((int_T)0.0) - 1;
      switch_status[3] = 0;
      switch_status_init[3] = 0;
      gState[3] = (int_T) 0.0;
      yswitch[3] = 1/0.001;
      switchTypes[3] = (int_T)7.0;
      idxOutSw[3] = ((int_T)0.0) - 1;
      switch_status[4] = 0;
      switch_status_init[4] = 0;
      gState[4] = (int_T) 0.0;
      yswitch[4] = 1/0.001;
      switchTypes[4] = (int_T)7.0;
      idxOutSw[4] = ((int_T)0.0) - 1;
      switch_status[5] = 0;
      switch_status_init[5] = 0;
      gState[5] = (int_T) 0.0;
      yswitch[5] = 1/0.001;
      switchTypes[5] = (int_T)7.0;
      idxOutSw[5] = ((int_T)0.0) - 1;
    }
  }
}

/* Model terminate function */
void Simulation_6Pulse_IGBT_Three_Phase_terminate(void)
{
  /* Terminate for S-Function (sfun_spssw_discc): '<S46>/State-Space' incorporates:
   *  Constant: '<S15>/DC'
   *  Constant: '<S48>/SwitchCurrents'
   */

  /* S-Function block: <S46>/State-Space */
  {
    /* Free memory */
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.AS);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BS);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.CS);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DS);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.DX_COL);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP2);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.BD_COL);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.TMP1);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.XTMP);

    /*
     * Circuit has switches*/
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.G_STATE);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SW_CHG);
    free(Simulation_6Pulse_IGBT_Three_DW.StateSpace_PWORK.SWITCH_STATUS_INIT);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
