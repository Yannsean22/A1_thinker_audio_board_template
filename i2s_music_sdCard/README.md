# 🎙️ I2S SDCard play

This example demonstrates a simple **I2S MUSIC PLAY FROM SDCARD** using the **AI Thinker ESP32 Audio Kit** with the **ES8388** codec.

---

> ⚠️ **Before starting:**  
> Make sure you've completed the steps in  
> [`/AI_thinker_audio_board_template/README.md`](../README.md).  
> That sets up the board files and ES8388 support for ESP-ADF.

---

---

 ## ⚠️ **Before starting:**  
  #### PLEASE MAKE SURE YOU HAVE ALL YOUR SWITCHES UP
  MOST IMPORTANT ONCE ARE:
  * 2 -> 'ON' -> DATA3
  * 3 -> 'ON' -> CMD
  * 4 -> 'ON' -> MTCK
  * 5 -> 'ON' -> MTDO 

---

I have noticed that this example is actually part of the ESP-ADF library, so it should work right we the correct files are placed


## ✅ Tested On
* Board: AI Thinker ESP32 Audio Kit (ES8388)
* ESP-IDF: v5.3.2
* ESP-ADF: Latest stable
* Output: Headphones via 3.5mm jack

## 🧩 Related Files
* globalVar.h: Contains constants like buffer size, timeouts, and clock configs.
* board.c/.h: Use the ones from /A1_thinker_audio_board_template to ensure proper ES8388 support.

#### 🙌 Contributing
If you make improvements (e.g. stereo support, variable latency, filtering), feel free to open a PR!

Made with 🔉 by someone tired of digging through broken examples 😄
