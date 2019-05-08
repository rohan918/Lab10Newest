
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ADC.h"
#include "Systick.h"
#include "ST7735.h"
#include "PLL.h"
#include "UpdateState.h"
#include "Shoot.h"
#include "DAC.h"
#include "Sound.h"

void test_Sound (void);

void Init (void) {
	
	// Run all the initializations at the begining 
	PLL_Init(Bus80MHz);
	ST7735_InitR(INITR_REDTAB);
	EdgeCounter_Init();
	DAC_Init();
	Sound_Init();
	
	
}



void Init2 (void) {
  ADC_Init();
	SysTick_Init();
	Init_State();

	EdgeCounter_Init();
	
	
	
}




