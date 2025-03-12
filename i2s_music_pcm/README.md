# ESP32 Audio Playback with ES8388 Codec

This project demonstrates how to play embedded PCM audio on an ESP32 (Ai-thinker-audio-kit) using the ES8388 audio codec via I2S.

---

---

> ⚠️ **Before starting:**  
> Make sure you've completed the steps in  
> [`/AI_thinker_audio_board_template/README.md`](../README.md).  
> That sets up the board files and ES8388 support for ESP-ADF.

---

## 🧠 Features

- I2S audio output using the ES8388 codec
- Embedded `.pcm` audio file (compiled into the binary)
- Looping playback of sample audio
- Master I2S configuration with 16-bit stereo slot and 48kHz sample rate

---

## 📁 Structure

- `main.c`: Initializes the ES8388 codec and I2S, and starts audio playback.
- `output.pcm`: A sample raw PCM file to be embedded in the firmware.
- `CMakeLists.txt`: Must include the PCM file using `EMBED_FILES`.

---

## 🔧 How to Embed `output.pcm`

In `main/CMakeLists.txt`, the following line:

```cmake
-> set(COMPONENT_SRCS "main.c" EMBED_FILES "output.pcm") #This is where we include the pcm file
set(COMPONENT_ADD_INCLUDEDIRS .)

register_component()
```
Make sure the output.pcm file is located in the main directory.

In `main/main.c`, the following lines:
```C
-> extern const uint8_t music_pcm_start[] asm("_binary_output_pcm_start"); //Grabs the pcm file
-> extern const uint8_t music_pcm_end[]   asm("_binary_output_pcm_end"); //Grabs the pcm file
```
Make sure the output.pcm file is located in the main directory.

## ✅ Tested On
* Board: AI Thinker ESP32 Audio Kit (ES8388)
* ESP-IDF: v5.3.2
* ESP-ADF: Latest stable
* Output: Headphones via 3.5mm jack

## 🧩 Related Files
* globalVar.h: Contains constants like buffer size, timeouts, and clock configs.
* board.c/.h: Use the ones from /A1_thinker_audio_board_template to ensure proper ES8388 support.

## 🙌 Contributing
If you make improvements (e.g. stereo support, variable latency, filtering), feel free to open a PR!

Made with 🔉 by someone tired of digging through broken examples 😄
