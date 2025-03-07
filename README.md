# A1_thinker_audio_board_template

###### ESP-IDF VERSION 5.3.2.
###### ESP-ADF VERSION -- Works with whatever comes with it I think.

#### This Template helps new developers working with A1-Thnker esp32-audio-kit, get a good Start.
* Example include:
  * Using the Microphone by echoeing. -- Working
  * Using the Bluetooth Stack -- A2DP works, HFP is a bit tricky getting the microphone to work.
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
