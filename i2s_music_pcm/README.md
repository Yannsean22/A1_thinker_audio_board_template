# ESP32 Audio Playback with ES8388 Codec

This project demonstrates how to play embedded PCM audio on an ESP32 (Ai-thinker-audio-kit) using the ES8388 audio codec via I2S.

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
