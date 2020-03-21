/***************************************************************
Play a musical composition in the background while
the main sketch code runs in the foreground.

The ArduboyPlaytune library must be installed to use this sketch
https://github.com/Arduboy/ArduboyPlayTune

The D-Pad buttons will move the text and play a tone.

The A button mutes the sound.
The screen is inverted when sound is muted.

The B button will turn sound back on if it's muted.

The score that is played contains two parts.
With the DevKit only one part is played.
***************************************************************/

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

// 2 Part Inventions No. 3 - J.S. Bach
const byte score[] PROGMEM = {
 2,154, 0x90,62, 0,166, 0x90,64, 0,166, 0x90,66, 0,166, 0x90,64, 0,166,
 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x90,62, 0,166, 0x90,69,
 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x91,50, 0x90,66,
 0,166, 0x91,52, 0x90,62, 0,166, 0x91,54, 0x90,69, 0,166, 0x91,52, 0,166,
 0x90,71, 0x91,55, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,55, 0x90,71,
 0,55, 0x90,73, 0,55, 0x91,50, 0x90,74, 0,166, 0x91,57, 0x90,73, 0,83,
 0x90,74, 0,83, 0x91,55, 0x90,73, 0,166, 0x91,54, 0x90,71, 0,83, 0x90,69,
 0,83, 0x91,52, 0,125, 0x80, 0,41, 0x90,73, 0x91,54, 0,166, 0x90,74, 0x91,50,
 0,166, 0x90,76, 0x91,57, 0,166, 0x90,73, 0,166, 0x91,45, 0x90,78, 0,166,
 0x90,74, 0,166, 0x91,57, 0x90,73, 0,166, 0x90,71, 0,138, 0x81, 0,27, 0x91,57,
 0x90,76, 0,166, 0x90,73, 0,166, 0x91,45, 0x90,74, 0,166, 0x90,71, 0,166,
 0x91,57, 0x90,69, 0,166, 0x90,68, 0,138, 0x81, 0,27, 0x91,57, 0x90,76, 0,166,
 0x90,73, 0,166, 0x91,45, 0x90,78, 0,166, 0x90,74, 0,166, 0x91,57, 0x90,73,
 0,166, 0x90,71, 0,138, 0x81, 0,27, 0x91,57, 0x90,76, 0,166, 0x90,73, 0,166,
 0x91,45, 0x90,74, 0,166, 0x90,71, 0,166, 0x91,57, 0x90,69, 0,166, 0x90,68,
 0,138, 0x81, 0,27, 0x91,57, 0x90,73, 0,166, 0x90,71, 0,166, 0x91,59, 0x90,74,
 0,166, 0x90,73, 0,166, 0x91,61, 0x90,71, 0,166, 0x90,69, 0,166, 0x91,62,
 0x90,78, 0,166, 0x91,61, 0,166, 0x90,68, 0x91,64, 0,166, 0x91,62, 0,166,
 0x90,69, 0x91,61, 0,166, 0x91,59, 0,166, 0x91,61, 0,27, 0x80, 0,27, 0x90,71,
 0,55, 0x90,69, 0,55, 0x91,62, 0x90,68, 0,55, 0x90,69, 0,55, 0x90,71,
 0,27, 0x80, 0,27, 0x90,71, 0x91,64, 1,77, 0x91,52, 0,166, 0x90,69, 0,166,
 0x91,57, 0x90,69, 0,166, 0x91,52, 0,166, 0x91,54, 0,166, 0x91,56, 0,166,
 0x91,57, 0x80, 0,166, 0x91,59, 0,166, 0x91,61, 0,166, 0x91,59, 0,166, 0x90,76,
 0x91,62, 0,166, 0x91,61, 0,166, 0x90,81, 0x91,59, 0,166, 0x91,57, 0,166,
 0x91,64, 0,166, 0x90,71, 0,166, 0x91,52, 0x90,73, 0,166, 0x90,75, 0,166,
 0x90,76, 0x81, 0,166, 0x90,78, 0,166, 0x90,79, 0,166, 0x90,78, 0,166, 0x91,59,
 0x90,81, 0,166, 0x90,79, 0,166, 0x91,64, 0x90,78, 0,166, 0x90,76, 0,166,
 0x90,83, 0,166, 0x91,54, 0,166, 0x90,71, 0x91,56, 0,166, 0x91,58, 0,166,
 0x91,59, 0x80, 0,166, 0x91,61, 0,166, 0x91,62, 0,166, 0x91,61, 0,166, 0x90,66,
 0x91,64, 0,166, 0x91,62, 0,166, 0x90,71, 0x91,61, 0,166, 0x91,59, 0,166,
 0x91,66, 0,166, 0x90,70, 0,166, 0x91,54, 0x90,71, 0,166, 0x90,73, 0,166,
 0x91,64, 0x90,74, 0,166, 0x90,76, 0,166, 0x91,62, 0x90,78, 0,166, 0x90,76,
 0,166, 0x91,71, 0x90,79, 0,166, 0x91,70, 0x90,78, 0,166, 0x91,71, 0x90,76,
 0,166, 0x90,74, 0,166, 0x91,61, 0x90,76, 0,166, 0x90,74, 0,166, 0x91,70,
 0x90,78, 0,166, 0x91,68, 0x90,76, 0,166, 0x91,70, 0x90,74, 0,166, 0x90,73,
 0,166, 0x91,71, 0x90,74, 0,166, 0x91,69, 0x90,73, 0,166, 0x91,67, 0x90,76,
 0,166, 0x91,66, 0x90,74, 0,166, 0x91,64, 0x90,73, 0,166, 0x91,62, 0x90,71,
 0,166, 0x91,64, 0x90,73, 0,166, 0x91,62, 0,166, 0x90,70, 0x91,66, 0,83,
 0x90,68, 0,83, 0x91,64, 0x90,70, 0,166, 0x91,62, 0x90,71, 0,166, 0x91,61,
 0,166, 0x91,62, 0,166, 0x90,73, 0x91,64, 0,138, 0x80, 0,27, 0x90,73, 0x91,66,
 0,83, 0x90,74, 0,83, 0x90,73, 0,166, 0x91,54, 0,166, 0x90,71, 0,166,
 0x91,59, 0,166, 0x90,66, 0,166, 0x91,54, 0x90,68, 0,166, 0x90,70, 0,166,
 0x91,50, 0x90,71, 0,166, 0x90,73, 0,166, 0x91,47, 0x90,74, 0,166, 0x90,73,
 0,166, 0x90,76, 0,166, 0x90,74, 0,166, 0x90,73, 0x81, 0,166, 0x90,71, 0,166,
 0x90,79, 0,166, 0x91,47, 0,166, 0x91,49, 0,166, 0x91,51, 0,166, 0x91,52,
 0,166, 0x91,54, 0,166, 0x91,55, 0,166, 0x91,54, 0,166, 0x91,57, 0,166,
 0x91,55, 0,166, 0x91,54, 0,166, 0x91,52, 0,166, 0x91,57, 0,138, 0x80, 0,27,
 0x90,64, 0,166, 0x90,66, 0,166, 0x90,68, 0,166, 0x90,69, 0,166, 0x90,71,
 0,166, 0x90,73, 0,166, 0x90,71, 0,166, 0x90,74, 0,166, 0x90,73, 0,166,
 0x90,71, 0,166, 0x90,69, 0,166, 0x90,78, 0,138, 0x81, 0,27, 0x91,45, 0,166,
 0x91,47, 0,166, 0x91,49, 0,166, 0x91,50, 0,166, 0x91,52, 0,166, 0x91,54,
 0,166, 0x91,52, 0,166, 0x91,55, 0,166, 0x91,54, 0,166, 0x91,52, 0,166,
 0x91,50, 0,166, 0x91,56, 0,138, 0x80, 0,27, 0x90,71, 0,166, 0x90,76, 0,166,
 0x91,52, 0x90,74, 0,166, 0x91,54, 0x90,73, 0,166, 0x91,56, 0x90,71, 0,166,
 0x91,57, 0x90,73, 0,166, 0x91,56, 0x90,71, 0,166, 0x91,54, 0x90,74, 0,166,
 0x91,52, 0x90,73, 0,166, 0x91,50, 0x90,71, 0,166, 0x91,54, 0x90,69, 0,166,
 0x91,52, 0x90,68, 0,83, 0x90,69, 0,83, 0x91,50, 0x90,68, 0,166, 0x91,49,
 0x90,64, 0,166, 0x91,47, 0,166, 0x90,69, 0x91,49, 0,166, 0x90,71, 0x91,45,
 0,166, 0x90,73, 0x91,57, 0,166, 0x90,71, 0,166, 0x91,54, 0x90,74, 0,166,
 0x90,73, 0,166, 0x91,49, 0x90,71, 0,166, 0x90,69, 0,166, 0x91,50, 0x90,78,
 0,166, 0x91,49, 0,166, 0x91,52, 0,166, 0x90,68, 0x91,50, 0,166, 0x90,69,
 0x91,49, 0,166, 0x90,68, 0x91,47, 0,166, 0x90,69, 0x91,49, 0,166, 0x90,74,
 0x91,50, 0,166, 0x90,71, 0x91,52, 1,77, 0x91,40, 0,166, 0x90,69, 0,138,
 0x80, 0,27, 0x90,69, 0x91,45, 0,166, 0x91,49, 0,166, 0x91,50, 0,166, 0x90,73,
 0x91,52, 0,166, 0x90,74, 0x91,54, 0,166, 0x90,76, 0x91,55, 0,166, 0x90,66,
 0x91,57, 0,166, 0x91,55, 0,166, 0x90,67, 0x91,59, 0,166, 0x91,57, 0,166,
 0x90,71, 0x91,55, 0,83, 0x90,69, 0,83, 0x91,54, 0x90,67, 0,83, 0x90,69,
 0,83, 0x91,55, 0x90,71, 0,166, 0x91,54, 0,166, 0x90,74, 0x91,57, 0,83,
 0x90,73, 0,83, 0x91,55, 0x90,71, 0,83, 0x90,73, 0,83, 0x91,54, 0x90,74,
 0,166, 0x91,52, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,166, 0x90,76,
 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,166, 0x90,74,
 0x91,50, 0,166, 0x90,76, 0x91,57, 0,166, 0x90,74, 0,166, 0x91,45, 0x90,73,
 0,166, 0x90,71, 0,166, 0x90,69, 0x81, 0,166, 0x90,67, 0,166, 0x90,66, 0,166,
 0x90,64, 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x90,62,
 0,166, 0x90,69, 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166,
 0x91,50, 0x90,66, 0,166, 0x91,52, 0x90,62, 0,166, 0x91,54, 0x90,69, 0,166,
 0x91,52, 0,166, 0x90,71, 0x91,55, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52,
 0,55, 0x90,71, 0,55, 0x90,73, 0,55, 0x91,50, 0x90,74, 0,166, 0x91,57,
 0x90,73, 0,83, 0x90,74, 0,83, 0x91,55, 0x90,73, 0,166, 0x91,54, 0x90,71,
 0,83, 0x90,69, 0,83, 0x91,52, 0,125, 0x80, 0,41, 0x90,74, 0x91,54, 0,166,
 0x91,50, 0,138, 0x80, 0,27, 0x90,74, 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62,
 0x91,59, 0,166, 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x91,52, 0,138,
 0x80, 0,27, 0x90,74, 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62, 0x91,55, 0,166,
 0x91,52, 0,166, 0x90,74, 0x91,50, 0,166, 0x91,49, 0,138, 0x80, 0,27, 0x90,74,
 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62, 0x91,59, 0,166, 0x91,55, 0,166,
 0x90,74, 0x91,54, 0,166, 0x91,52, 0,138, 0x80, 0,27, 0x90,74, 0x91,57, 0,166,
 0x91,54, 0,166, 0x90,62, 0x91,55, 0,166, 0x91,52, 0,166, 0x90,74, 0x91,50,
 0,166, 0x90,76, 0x91,49, 0,166, 0x90,78, 0x91,50, 0,166, 0x90,76, 0,166,
 0x91,52, 0x90,79, 0,166, 0x90,78, 0,166, 0x91,54, 0x90,76, 0,166, 0x90,74,
 0,166, 0x91,55, 0x90,83, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,57, 0,166,
 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x91,52, 0,166, 0x91,54, 0,27,
 0x80, 0,27, 0x90,76, 0,55, 0x90,74, 0,55, 0x91,55, 0x90,73, 0,55, 0x90,74,
 0,55, 0x90,76, 0,41, 0x80, 0,13, 0x90,76, 0x91,57, 1,77, 0x91,45, 0,166,
 0x90,74, 0,138, 0x80, 0,27, 0x90,74, 0x91,47, 0,166, 0x91,45, 0,166, 0x90,62,
 0x91,48, 0,166, 0x91,47, 0,166, 0x90,67, 0x91,45, 0,166, 0x91,43, 0,166,
 0x91,50, 0,166, 0x90,57, 0,166, 0x90,59, 0,166, 0x90,61, 0,166, 0x90,62,
 0,166, 0x90,64, 0,166, 0x90,66, 0,138, 0x81, 0,27, 0x91,49, 0x90,64, 0,166,
 0x91,47, 0x90,67, 0,166, 0x91,45, 0x90,66, 0,166, 0x91,43, 0x90,64, 0,166,
 0x91,42, 0x90,62, 0,166, 0x91,43, 0x90,71, 0,166, 0x91,42, 0,166, 0x91,45,
 0,166, 0x90,61, 0x91,43, 0,166, 0x90,62, 0x91,42, 0,166, 0x90,61, 0x91,40,
 0,166, 0x90,62, 0x91,42, 0,166, 0x90,67, 0x91,43, 0,166, 0x90,64, 0x91,45,
 1,244, 0x90,62, 0,138, 0x80, 0,27, 0x90,62, 0x91,38, 7,208, 0x80, 0x81,
 0xf0
};

Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);

void setup()
{
  arduboy.begin();

  arduboy.setFrameRate(25);
  arduboy.setTextSize(3);
#ifdef ADAFRUIT
  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMutesScore(true);       // mute the score when a tone is sounding
#endif
#endif

  arduboy.invert(!arduboy.audio.enabled()); // invert display if sound muted
}


int x = 20, y = 10; // initial text position

void loop()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  if (arduboy.pressed(UP_BUTTON)) {
    y-=1;
    tunes.tone(1175,300);
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    y+=1;
    tunes.tone(1397,300);
  } else if (arduboy.pressed(LEFT_BUTTON)) {
    x-=1;
    tunes.tone(1047,300);
  } else if (arduboy.pressed(RIGHT_BUTTON)) {
    x+=1;
    tunes.tone(1319,300);
  }

  if (arduboy.pressed(A_BUTTON)) {
    arduboy.invert(true);
    arduboy.audio.off();
  } else if (arduboy.pressed(B_BUTTON)) {
    arduboy.invert(false);
    arduboy.audio.on();
  }

  arduboy.clear();
  arduboy.setCursor(x,y);
  arduboy.print("Music");
  arduboy.setCursor(x+8,y+24);
  arduboy.print("Demo");
  arduboy.display();

  // play the tune if we aren't already
  if (!tunes.playing())
    tunes.playScore(score);
}
