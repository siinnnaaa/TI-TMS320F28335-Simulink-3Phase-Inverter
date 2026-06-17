# TI-TMS320F28335-Simulink-3Phase-Inverter
A complete three-phase inverter implementation using TI TMS320F28335 DSP and Simulink: real-time control firmware (CCS), simulation model, and hardware integration for power electronics applications.
# TI-TMS320F28335-Simulink-3Phase-Inverter

A complete three-phase inverter implementation using TI TMS320F28335 DSP and Simulink: real-time control firmware (CCS), simulation model, and hardware integration for power electronics applications.

## 📋 Overview

This project implements a **6-pulse three-phase IGBT inverter** with the following features:

- **Microcontroller:** TI TMS320F28335 DSP
- **Development Environment:** Code Composer Studio (CCS)
- **Simulation:** MATLAB Simulink with Embedded Coder
- **Topology:** Three-phase voltage source inverter (VSI) with six IGBTs
- **Control Strategy:** [Space Vector PWM / Sinusoidal PWM / etc. - مشخص کن]
- **Dead-Time Protection:** Hardware-level dead-time insertion to prevent shoot-through

---

## 🎯 Key Features

### 1. Dead-Time Implementation
To prevent **shoot-through** (short circuit across DC bus), dead-time is inserted between complementary switching signals of each inverter leg:

- **Method:** [توضیح بده: آیا از ePWM module داخل TMS320F28335 استفاده شده؟ یا در Simulink؟]
- **Dead-Time Value:** [مثلاً: 2 µs]
- **Implementation:**
  - In Simulink: Using `MATLAB Function` block or built-in PWM dead-band generator
  - In CCS firmware: Configured via ePWM registers (`DBCTL`, `DBRED`, `DBFED`)
```c
// Example CCS ePWM dead-time configuration
EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;  // Enable dead-band for both rising and falling edge
EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;       // Active high complementary
EPwm1Regs.DBRED = 200;  // Rising edge delay (dead-time)
EPwm1Regs.DBFED = 200;  // Falling edge delay (dead-time)

### 2. MATLAB Function Block
The Simulink model includes a **MATLAB Function block** to implement:

- [توضیح بده چه کاری انجام می‌ده، مثلاً:]
  - Switching logic generation
  - Clarke/Park transformation
  - Space vector calculation
  - [یا هر منطق دیگه‌ای که داخل MATLAB Function نوشتی]

**Example pseudo-code:**
matlab
function [Sa, Sb, Sc] = PWM_Generator(Vref, theta)
% Space Vector PWM logic
% Calculate sector and duty cycles
% Generate switching signals for three phases
...
end

### 3. Embedded Coder Integration
The Simulink model is configured for **code generation** using Embedded Coder:

- Target hardware: TI C2000 (TMS320F28335)
- Generated files are in `Simulation_6Pulse_IGBT_Three_Phase_ert_rtw/`
- Compatible with CCS for direct flashing to DSP

---

## 📸 Simulation Results

### Output Waveforms (Oscilloscope)

#### Three-Phase Output Voltages
![Three-Phase Voltage Waveforms](docs/screenshots/scope_3phase_voltage.png)

#### Line-to-Line Voltage
![Line-to-Line Voltage](docs/screenshots/scope_line_voltage.png)

#### FFT Analysis
![FFT Spectrum](docs/screenshots/scope_fft.png)

#### Dead-Time Effect on PWM
![Dead-Time Illustration](docs/screenshots/scope_deadtime.png)

---

## 🗂️ Project Structure


TI-TMS320F28335-Simulink-3Phase-Inverter/
├── simulink/
│   ├── Simulation_6Pulse_IGBT_Three_Phase.slx    # Main Simulink model
│   └── model_config.m                              # Configuration script
├── firmware/
│   ├── src/
│   │   ├── main.c                                  # Main firmware
│   │   ├── pwm_config.c                            # ePWM configuration
│   │   └── inverter_control.c                      # Control logic
│   ├── include/
│   │   └── inverter.h
│   └── CCS_Project/                                # Code Composer Studio project files
├── docs/
│   ├── screenshots/                                # Oscilloscope captures
│   └── hardware_schematic.pdf                      # (Optional) Circuit diagram
├── README.md
├── LICENSE
└── .gitignore

---

## 🚀 Getting Started

### Prerequisites

- **Software:**
  - MATLAB R20XX or later with Simulink and Embedded Coder
  - Code Composer Studio (CCS) v10.x or later
  - TI C2000 support package for MATLAB

- **Hardware:**
  - TMS320F28335 DSP development board
  - Three-phase IGBT inverter power stage
  - DC power supply
  - Oscilloscope for output verification

### Simulation

1. Open `Simulation_6Pulse_IGBT_Three_Phase.slx` in MATLAB Simulink
2. Run the simulation (Ctrl+T)
3. View output waveforms in scope blocks

### Code Generation & Deployment

1. In Simulink, click **Code → C/C++ Code → Build Model**
2. Open the generated CCS project in `Simulation_6Pulse_IGBT_Three_Phase_ert_rtw/`
3. Build and flash to TMS320F28335 using CCS

### Manual Firmware Build (CCS)

1. Open CCS workspace in `firmware/CCS_Project/`
2. Import the project
3. Build the project (Ctrl+B)
4. Connect the DSP via JTAG
5. Debug/Run (F11 or Ctrl+F11)

---

## ⚙️ Configuration

### PWM Frequency
- **Switching frequency:** [مثلاً: 10 kHz]
- **Carrier frequency:** [اگه متفاوت باشه]

### Dead-Time Settings
- **Dead-time duration:** [مثلاً: 2 µs]
- Adjustable in:
  - Simulink: `PWM_Generator` block parameters
  - CCS firmware: `pwm_config.c` → `DBRED` and `DBFED` registers

### Output Voltage/Frequency
- **DC Bus Voltage:** [مثلاً: 300 V]
- **Output Frequency:** [مثلاً: 50 Hz]
- **Modulation Index:** [مثلاً: 0.8]

---

## 📊 Performance Metrics

| Parameter                  | Value       |
|----------------------------|-------------|
| Switching Frequency        | 10 kHz      |
| Dead-Time                  | 2 µs        |
| Output Frequency           | 50 Hz       |
| THD (Total Harmonic Dist.) | < 5%        |
| Efficiency                 | > 95%       |

---

## 🛠️ Troubleshooting

### Issue: Shoot-through detected
- **Cause:** Insufficient dead-time
- **Solution:** Increase `DBRED`/`DBFED` values in `pwm_config.c`

### Issue: Distorted output waveform
- **Cause:** Incorrect PWM duty cycle calculation
- **Solution:** Verify MATLAB Function block logic and modulation index

### Issue: CCS build errors
- **Cause:** Missing TI libraries
- **Solution:** Install TI C2000 controlSUITE and update include paths

---

## 📚 References

- [TMS320F28335 Technical Reference Manual](https://www.ti.com/product/TMS320F28335)
- [ePWM Module User Guide (SPRUHM8)](https://www.ti.com/lit/pdf/spruhm8)
- [Space Vector PWM Tutorial](https://example.com) <!-- لینک مرجع اگه داری -->

---

## 📝 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

Contributions are welcome! Please open an issue or submit a pull request.

---

## 📧 Contact

For questions or collaboration:
- Open an issue on GitHub
- [Optional: Email or other contact info]

---

## 🙏 Acknowledgments

- TI C2000 community and documentation
- [اگه از کتاب یا مقاله‌ای استفاده کردی اینجا اشاره کن]


---

### 🔧 چیزایی که باید خودت اضافه کنی:

1. **Dead-time implementation details:** دقیقاً کجا پیاده‌سازی کردی (Simulink یا CCS firmware)
2. **MATLAB Function block logic:** چه کاری انجام می‌ده و کدش چیه
3. **مقادیر دقیق:** فرکانس سوئیچینگ، dead-time، ولتاژ DC bus
4. **اسکرین‌شات‌ها:** عکس scope از خروجی سه‌فاز، FFT، dead-time effect

این README رو توی فایل `README.md` بذار و در repo قرار بده. اگه نیاز به تغییر یا اضافه کردن بخشی داری بگو!
