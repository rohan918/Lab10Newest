
#include "ST7735.h"
#ifndef __SOUND__ // do not include more than once
#define __SOUND__

void Sound_Init(void);
void Sound_Play(uint8_t soundNumber, uint32_t period);
void Sound_Shoot(void);
void Sound_Killed(void);
void Sound_Explosion(void);

#endif
