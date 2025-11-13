# Gesture-Controlled Robot Hand

A project to control a robotic hand via hand gestures using computer vision and Arduino.  
Developed by **Harsh Chitnis**, **Vrushank Arur**, and **Karan Rajput (2024)**.  
Licensed under the MIT License.

---

## 🔍 Overview
This project enables a robotic hand to mimic human gestures detected through a webcam.  
Using **computer vision** (Python) and **embedded control** (Arduino), it translates hand gestures into servo-motor movements in real time.

---

## ✅ Features
- Real-time gesture detection using a webcam.  
- Mapping of different gestures (e.g., fist, open palm, pointing) to servo positions.  
- Serial communication between Python and Arduino via USB.  
- Modular structure: `utlis.py` handles gesture logic, `RobotHandGestures.py` manages control flow, and `WORKING.ino` runs the servos.  
- Fully extensible for custom gestures and servo configurations.

---

## 📁 Repository Structure
```
/
├── LICENSE                # MIT License  
├── RobotHandGestures.py   # Main Python script for gesture detection & serial communication  
├── utlis.py               # Utility functions for hand landmark and gesture detection  
├── WORKING.ino            # Arduino sketch controlling servo motors  
└── README.md              # Project documentation  
```

---

## 🧮 Hardware Requirements
- Robotic hand with 5+ servo motors  
- Arduino Uno (or compatible board)  
- USB cable and power supply for servos  
- Webcam connected to PC  
- Jumper wires and breadboard (optional)  
- (Optional) 3D-printed or mechanical robotic hand structure  

---

## 💻 Software Requirements
**PC:**
- Python 3.x  
- Libraries:  
  ```bash
  pip install opencv-python mediapipe pyserial
  ```
- Arduino IDE for uploading the `.ino` file  

---

## 🔧 Setup & Usage

### 1️⃣ Prepare Hardware
- Assemble the robotic hand and connect servos to the Arduino.  
- Ensure servo power and connections are correct.  
- Connect Arduino to your PC and set the correct COM port.

### 2️⃣ Upload Arduino Code
1. Open `WORKING.ino` in Arduino IDE.  
2. Select the correct board and port.  
3. Upload the sketch to the Arduino.

### 3️⃣ Run the Python Script
```bash
python RobotHandGestures.py
```
- The webcam feed starts.  
- Detected gestures are sent to the Arduino.  
- The robotic hand moves to match your gesture.

---

## ✋ Supported Gestures
Default gestures include:
- **Open Palm** → all fingers extended  
- **Fist** → all fingers curled  
- **Individual Finger Control**  

You can easily add more gestures by editing `utlis.py` and updating mappings in `RobotHandGestures.py`.

---

## 🧠 How It Works
1. **Webcam** captures frames in real time.  
2. **Mediapipe/OpenCV** detects hand landmarks.  
3. **utlis.py** analyzes finger positions to classify gestures.  
4. **RobotHandGestures.py** sends corresponding serial commands to Arduino.  
5. **Arduino (WORKING.ino)** decodes commands and moves servos accordingly.

---

## 🧹 Customisation & Extensibility

### ➕ Add a New Gesture
1. Create a new function in `utlis.py` to recognize your gesture.  
2. Define a unique ID for it in `RobotHandGestures.py`.  
3. Update the servo mapping or command logic in `WORKING.ino`.

### 🔧 Modify Servo Layout
If your hand’s servo mapping differs:
- Edit servo pin assignments in `WORKING.ino`.  
- Adjust servo angles or gesture mapping in `RobotHandGestures.py`.

---

## 🧪 Calibration & Testing
- Test in consistent lighting for better gesture recognition.  
- Verify serial communication (check baud rate and COM port).  
- Calibrate each servo to ensure correct neutral and max angles.  
- Print debug outputs from Python and Arduino to troubleshoot.

---

## 🚀 Applications
- Sign-language recognition  
- Robotics & HCI experiments  
- Gesture-based robot control  
- Educational STEM projects  
- Assistive or prosthetic hand research  

---

## 📜 License
This project is licensed under the [MIT License](LICENSE).

---

## 🙏 Acknowledgements
Thanks to all contributors and testers who helped refine this project.  
If you find this useful, please ⭐ the repo or fork it for your own experiments!

---

**Last Updated:** 2024
