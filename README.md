# 🧠 AI Thinker ESP32 Audio Board Template – ES8388

A starter repo for developers working with the **AI Thinker ESP32 Audio Kit** (with the **ES8388** audio codec).  
Documentation is limited out there, so I made this to save you some headaches.

---

## ✅ Chip Check

Not sure if your board uses the **ES8388**? No worries — check the `Chip_check` folder for a quick I2C scanner script using ESP-IDF that will confirm it for you.

---

## 🔧 Requirements

- Basic knowledge of ESP-IDF (but honestly, just C/C++ basics are fine)
- ESP-ADF (you don’t need to know it deeply — it works out of the box)
- AI Thinker ESP32 Audio Kit (obviously 😅)

---

## 🚀 What This Template Covers

This helps new devs get up and running fast with the AI Thinker ESP32 Audio Kit.

### ✅ Examples included:

- 🎙️ **Microphone loopback (echo test)** – *Working*
- 🔊 **Bluetooth Audio:**
  - **A2DP** – *Works flawlessly*
  - **HFP** – *Speaker works, microphone is in progress*
  - **A2DP + HFP switching** – *Switching works, mic still buggy (let me know if you fix it!)*
- 💾 **Onboard SD Card** – *Working*
- 📁 **Playing `.pcm` files** – *Working*

---

## 🛠️ How to Use This Template

You’ll be replacing some default ADF board files so it works with your AI Thinker board.

### 1. Locate the `.espressif` Folder

- **Windows:**  
  `C:\Users\<YourUsername>\.espressif\`

- **Mac:**  
  `/Users/<YourUsername>/.espressif/`

- **Linux:**  
  `~/.espressif/`

---

### 2. Navigate to:

```bash
.espressif/esp-adf/components/audio_board/lyrat_v4_3
```
---

### 3. Delete the Following Files:
* board.c
* board.h
* board_def.h
* board_pins_config.c

### 4. From This Repo
Navigate to:

```bash
A1_thinker_audio_board_template/lyrat_v4_3
```
### 5. Copy and Paste:
Copy the following files:

* board.c
* board.h
* board_def.h
* board_pins_config.c
Paste them into:

```bash
.espressif/esp-adf/components/audio_board/lyrat_v4_3
```
### 6. All Done ✅
Now you can build and run any ESP-ADF example (like Bluetooth, SD, Recorder, etc.) and it’ll work with your AI Thinker board.

### 📌 Versions Tested With
* ESP-IDF: v5.3.2
* ESP-ADF: Whatever version came by default (should be compatible)

### 🤝 Contributing
Feel free to fork, PR, or open an issue if you’ve got ideas, fixes, or run into bugs. Even tips you learn the hard way are welcome — let’s help the next dev out.

Made with 💻 and 🔊 by someone who wanted better docs for this board and broken examples.
