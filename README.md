# TI TMS320F28335 DSP & Simulink Three-Phase Inverter Control

[![MATLAB](https://img.shields.io/badge/MATLAB-R2021a%2B-orange.svg)](https://www.mathworks.com/products/matlab.html)
[![CCS](https://img.shields.io/badge/Code%20Composer%20Studio-v10%2B-blue.svg)](https://www.ti.com/tool/CCSTUDIO)
[![Hardware](https://img.shields.io/badge/Hardware-TMS320F28335-red.svg)](https://www.ti.com/product/TMS320F28335)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A complete, production-ready three-phase inverter implementation leveraging the high-performance **TI TMS320F28335 DSP** (C2000 Delfino MCU) and **MATLAB/Simulink**. This repository bridges the gap between desktop simulation and real-time hardware-in-the-loop (HIL) or rapid control prototyping (RCP) for power electronics applications.

---

## 📌 Project Overview

This repository contains:
1. **Simulink Simulation Model (`.slx`):** A high-fidelity physical model of a 3-phase voltage source inverter (VSI) using a 6-pulse IGBT configuration, SPWM generation, and LC/RL filtering.
2. **DSP Firmware (CCS Project):** Optimized C-code and digital control loops targeted for the TMS320F28335 DSP to generate real-time PWM signals, read ADC feedback, and execute closed-loop control.
3. **Hardware Integration Guide:** Wiring diagrams and hardware configurations to deploy the model onto real power electronics testbenches.

---

## 🔍 System Architecture & Simulation

The power stage consists of a **Three-Phase Universal Bridge** using **6 IGBTs/Diodes**, driven by a **2nd-level SPWM (Sinusoidal Pulse Width Modulation)** generator. 

### Key Simulation Parameters
* **Grid/Source Voltage:** $25 \text{ kV}$ RMS (Line-to-Line) @ $60 \text{ Hz}$
* **Modulation Frequency (Carrier):** $1080 \text{ Hz}$ (Synchronized to DSP EPWM timers)
* **Load:** Series RL ($1\ \Omega$, $1\ \text{ mH}$)
* **Solver:** Continuous-time `powergui`

### 🖼️ Simulink Model Overview
Below is the overall schematic diagram of the 6-pulse IGBT 3-phase inverter in Simulink:

<img width="1203" height="798" alt="image" src="https://github.com/user-attachments/assets/07b9ff4b-b42c-45aa-9f28-6c5c8da5243c" />


---

## 📊 Simulation Results & Waveforms

The model simulates transient and steady-state responses of the inverter. Key outputs include Phase Voltages ($V_{abc}$), Line Currents ($I_{abc}$), and the DC-Link performance.

### 🖼️ Scope Outputs
Below are the measured output waveforms before/after the filter stages:

<img width="1920" height="928" alt="image" src="https://github.com/user-attachments/assets/8b6dfe02-59cb-4f40-bf5f-9f84b03616da" />


---

## 🛠️ Software & Hardware Requirements

### Software Stack
* **MATLAB / Simulink** (Recommended: R2021a or newer)
  * Simscape / Simscape Electrical (formerly SimPowerSystems)
  * Embedded Coder (for direct code generation)
* **TI Code Composer Studio (CCS)** (v10 or newer)
* **C2000 Ware** (for TI driver libraries)

### Target Hardware
* **DSP:** Texas Instruments TMS320F28335 ControlCARD or LaunchPad
* **Inverter Board:** Any standard 3-phase IGBT/MOSFET intelligent power module (IPM) with gate-driver inputs compatible with 3.3V/5V logic.

---

## 🚀 Getting Started

### 1. Running the Simulation
1. Open MATLAB and navigate to the project directory.
2. Open the Simulink model: `Simulation_6Pulse_IGBT_Three_Phase.slx`.
3. Double-click the `powergui` block to configure solver settings if needed.
4. Click **Run** ($\text{Ctrl+T}$) to view the Scope waveforms.

### 2. Generating & Deploying DSP Code
1. Open the Simulink Configuration Parameters ($\text{Ctrl+E}$).
2. Under **Hardware Implementation**, select **TI Delfino TMS320F2833x**.
3. Configure the **ePWM** blocks to match your hardware pinout (default uses `ePWM1`, `ePWM2`, and `ePWM3` for the three phases).
4. Click **Build Model** to automatically generate C code and create a CCS-compatible project.
5. Import the generated code into **Code Composer Studio** and flash it to your TMS320F28335 DSP.

---

## 🤝 Contributing
Contributions are highly welcome! If you find any issues, have suggestions for hardware optimizations, or want to add closed-loop FOC/SVPWM controllers, please open an **Issue** or submit a **Pull Request**.

---

## 📄 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
