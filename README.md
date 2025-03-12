# AI_thinker_ESP32_audio_board_template - ES8388
###### The AI_Thinker board I am using has the ES8388 Audio codec, if you are not sure about yours that is OK. Under "Chip check" there you can find out
###### ESP-IDF VERSION 5.3.2.
###### ESP-ADF VERSION -- Works with whatever comes with it I think.

#### This Template helps new developers working with A1-Thnker esp32-audio-kit, get a good Start.
* Example include:
  * Using the Microphone by echoeing. -- Working.
  * Using the Bluetooth Stack:
     * A2DP: Words flawlessly.
     * HFP: Speakers work, working on microphone.
     * A2DP & HFP: Swithing profile works, still have microphone issues I am working on -- lmk if you fix it!! 
  * Using the onBoard SdCard.-- Working.
  * Using a .pcm file -- Working.
 
### USAGE:
* Find '.espressif'
  * Windows: Usually under C:\Users\ 'Your user or profile name'\.espressif\
  * MAC: Usually under /'Your user or profile name'/.espressif/
  * Linux: Goodluck, haha will update this when I get back to linux.
*  From .espressif navigate to esp-adf -> components -> audio_board -> lyrat_v4_3
* Delete:
  * board.c
  * board.h
  * board_def.h
  * board_pins_config.c
* Open a new window:
  * Windows: Explore
  * Mac: Finder
  * Linux: Whatever file explore you are using or use a terminal for these next steps
* In the new window go to the Downloaded and extracted "A1_thinker_audio_board_template" folder
* Navigate to lyrat_v4_3
* Copy:
  * board.c
  * board.h
  * board_def.h
  * board_pins_config.c
* Past those files in .espressif -> esp-adf -> components -> audio_board -> lyrat_v4_3
* All done!!! you can now close all windows related to this process and choose whatever example suits you.
