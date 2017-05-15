#include "gpio.h"
#include "timer.h"
#include "midi.h"
#include "led.h"

#define CHANNEL_KEY    0
#define CHANNEL_BEATS  9

typedef enum {
  BEATS_KICK = 36,
  BEATS_SNARE =  38,
  BEATS_LOTOM = 43,
  BEATS_HITOM = 50,
  BEATS_CLHAT = 42,
  BEATS_OPHAT = 46,
  BEATS_CLAP  = 39
} beats_t;

uint8_t beats[] = {
  BEATS_KICK,
  BEATS_SNARE,
  BEATS_LOTOM,
  BEATS_HITOM,
  BEATS_CLHAT,
  BEATS_OPHAT,
  BEATS_CLAP
};

typedef enum {
  ZERO = 0,
  G3 = 55,
  A3 = 57,
  B3 = 59,
  C4 = 60,
  D4 = 62,
  E4 = 64,
  F4 = 65
} notes_t;

typedef struct {
  notes_t note;
  unsigned time;
} press_t;

#define HLF_NOTE 1000000
#define QTR_NOTE 500000
#define PAUSE    200000

press_t notes[] = {
  {B3, QTR_NOTE},
  {A3, QTR_NOTE},
  {G3, QTR_NOTE},
  {A3, QTR_NOTE},
  {B3, QTR_NOTE},
  {B3, QTR_NOTE},
  {B3, HLF_NOTE},
  {A3, QTR_NOTE},
  {A3, QTR_NOTE},
  {A3, HLF_NOTE},
  {B3, QTR_NOTE},
  {D4, QTR_NOTE},
  {D4, HLF_NOTE},
  {B3, QTR_NOTE},
  {A3, QTR_NOTE},
  {G3, QTR_NOTE},
  {A3, QTR_NOTE},
  {B3, QTR_NOTE},
  {B3, QTR_NOTE},
  {B3, QTR_NOTE},
  {B3, QTR_NOTE},
  {A3, QTR_NOTE},
  {A3, QTR_NOTE},
  {B3, QTR_NOTE},
  {A3, QTR_NOTE},
  {G3, HLF_NOTE},
};
  

void main() {
  gpio_init();
  timer_init();
  midi_init();
  /*  midi_set_channel(CHANNEL_BEATS);

  while (1) {
    unsigned i;
    for (i = 0; i < sizeof(beats); i++) {
      midi_note_on(beats[i], 64);
      delay_ms(250);
      midi_note_off(beats[i], 64);
      led_toggle();
    }
    }*/
  
  while (1) {
    unsigned i;
    unsigned len = sizeof(notes) / sizeof(press_t);
    for (i = 0; i < len; i ++) {
      press_t* press = &notes[i];
      midi_note_on(press->note, 64);
      delay_us(press->time);
      midi_note_off(press->note, 64);
      led_toggle();
    }
    delay_ms(4000);
  }
}
