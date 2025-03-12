# 🎙️ I2S Echo – Real-Time Mic-to-Speaker Loopback

This example demonstrates a simple **I2S microphone-to-speaker echo test** using the **AI Thinker ESP32 Audio Kit** with the **ES8388** codec.

---

> ⚠️ **Before starting:**  
> Make sure you've completed the steps in  
> [`/AI_thinker_audio_board_template/README.md`](../README.md).  
> That sets up the board files and ES8388 support for ESP-ADF.

---

## 🧠 What This Does

- Initializes the **ES8388 audio codec** (both ADC + DAC)
- Configures **I2S** in full-duplex mode (record + playback)
- Starts a loop that:
  - Reads microphone input via I2S
  - Writes it directly to the speaker/headphone output

Essentially, it creates a **real-time audio loopback** — you speak into the mic and hear it from the speaker/headphones with minimal delay.

---

## 🔧 How It Works (Code Breakdown)

### `es83188Init()`

- Initializes the **ES8388** codec in both **ADC** (mic input) and **DAC** (speaker output) modes.
- Sets it to **slave** I2S mode and **48kHz sample rate**.
- Turns on the codec and sets volume to 100%.

### `i2sInit()`

- Creates both **TX** and **RX** I2S channels (for sending and receiving audio).
- Configures I2S with:
  - **8000 Hz sample rate** (can be changed)
  - **Mono 16-bit Philips format**
  - GPIO pins:
    - `MCLK`: GPIO0
    - `BCLK`: GPIO27
    - `WS`: GPIO25
    - `DOUT`: GPIO26 (to speaker)
    - `DIN`: GPIO35 (from mic)

> 🔍 Make sure your hardware matches these pin assignments. Update if needed.

### `i2s_echo(void *args)`

- Allocates a buffer for reading microphone data
- Starts a loop:
  - Reads audio data from mic (`i2s_channel_read`)
  - Writes the same data to speaker (`i2s_channel_write`)
  - If read/write size doesn't match, logs a warning

### `app_main()`

- Initializes NVS (required for ESP-IDF)
- Calls both `es83188Init()` and `i2sInit()`
- Starts the echo loop in a FreeRTOS task

---

## 📌 Constants You Can Tune

Defined in your `globalVar.h` (not shown here):

```c
#define EXAMPLE_RECV_BUF_SIZE   1024
#define EXAMPLE_MCLK_MULTIPLE   I2S_MCLK_MULTIPLE_256
#define I2S_WRITE_TIMEOUT_MS    1000
```
- Increase EXAMPLE_RECV_BUF_SIZE for smoother playback
- Use I2S_MCLK_MULTIPLE_256 for better compatibility
- Tune sample rate in i2s_std_clk_config_t if needed (e.g. 16000, 44100)

## ⚠️ Gotchas & Tips
* Mic input may be quiet — use an external mic or preamp if needed.
* Echo delay is minimal, but noticeable with larger buffers or slower sample rates.
* If you hear popping or stuttering, try:
* Increasing I2S_WRITE_TIMEOUT_MS
* Using a higher sample rate (e.g. 16000)
* Doubling EXAMPLE_RECV_BUF_SIZE
* Confirm your I2S pins match the hardware. The AI Thinker board may differ slightly from default LyraT configs.

## ✅ Tested On
* Board: AI Thinker ESP32 Audio Kit (ES8388)
* ESP-IDF: v5.3.2
* ESP-ADF: Latest stable
* Mic: Onboard mic and external 3.5mm jack
* Output: Headphones via 3.5mm jack

## 🧩 Related Files
* globalVar.h: Contains constants like buffer size, timeouts, and clock configs.
* board.c/.h: Use the ones from /A1_thinker_audio_board_template to ensure proper ES8388 support.

#### 🙌 Contributing
If you make improvements (e.g. stereo support, variable latency, filtering), feel free to open a PR!

Made with 🔉 by someone tired of digging through broken examples 😄
