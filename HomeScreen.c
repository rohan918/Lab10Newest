#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ST7735.h"
#include "Shoot.h"

char notReady1[20] = "Player 1 Not Ready";

char notReady2[20] = "Player 2 Not Ready";

char Ready1[20] = "Player 1 Ready!";

char Ready2[20] = "Player 2 Ready!";

extern int shootFlag;

extern int shootFlag2;

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void drawHome(void) {
	ST7735_FillScreen (0);
	
	ST7735_SetCursor(6,3);
	ST7735_OutString("Thug Tanks");
	ST7735_SetCursor(1,5);
	ST7735_OutString("Shoot to get ready!");
	
	
	if (shootFlag == 0) {
		ST7735_SetCursor(2,8);
	  ST7735_OutString(notReady1);
		
	} else {
		ST7735_SetCursor(4,8);
		ST7735_OutString(Ready1);
		
	}
	
	
	 if (shootFlag2 == 0) {
		 ST7735_SetCursor(2,10);
		 ST7735_OutString(notReady2);
		
	} else {
		ST7735_SetCursor(4,10);
		ST7735_OutString(Ready2);
		
	}
	

	
}



void waitForReady(void) {
	drawHome();
	while (shootFlag == 0 && shootFlag2 == 0) {}
	drawHome();
	while (shootFlag == 0 || shootFlag2 == 0) {}
		DisableInterrupts();
	  drawHome();
		shootFlag = 0;
		shootFlag2 = 0;
		

		
  uint32_t delay =  10000000;	
		
		while (delay != 0) {
			delay --;
		}



		
	
	
	
}



void endScreen (int player1, int player2) {
	
	ST7735_FillScreen(0);
	if (player2 == 0) {
		
		ST7735_SetCursor(3,6);
		ST7735_OutString("Player 1 Wins!!");
		ST7735_SetCursor(3,8);
		ST7735_OutString("Player 2 sucks");
		
		
		
	} else {
		ST7735_SetCursor(3,6);
		ST7735_OutString("Player 2 Wins!!");
		ST7735_SetCursor(3,8);
		ST7735_OutString("Player 1 sucks");
		
	}
	
	ST7735_SetCursor(1,10);
	ST7735_OutString("Reset to play again");
	
	
	
}
