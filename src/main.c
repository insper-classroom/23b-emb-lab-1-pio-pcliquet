/**
 * 5 semestre - Eng. da Computação - Insper
 * Rafael Corsi - rafael.corsi@insper.edu.br
 *
 * Projeto 0 para a placa SAME70-XPLD
 *
 * Objetivo :
 *  - Introduzir ASF e HAL
 *  - Configuracao de clock
 *  - Configuracao pino In/Out
 *
 * Material :
 *  - Kit: ATMEL SAME70-XPLD - ARM CORTEX M7
 */

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/
//Led 1
#define LED_PIO_1      PIOA
#define LED_PIO_ID_1   ID_PIOA
#define LED_IDX_1      0
#define LED_IDX_MASK_1 (1 << LED_IDX_1)

//Led 2
#define LED_PIO_2      PIOB
#define LED_PIO_ID_2   ID_PIOB
#define LED_IDX_2      2
#define LED_IDX_MASK_2 (1 << LED_IDX_2)

//Led 3
#define LED_PIO_3      PIOC
#define LED_PIO_ID_3   ID_PIOC
#define LED_IDX_3      30
#define LED_IDX_MASK_3 (1 << LED_IDX_3)

// Botão 1
#define BUT_PIO_1      PIOA
#define BUT_PIO_ID_1   ID_PIOA
#define BUT_IDX_1      0
#define BUT_IDX_MASK_1 (1 << BUT_IDX_1)

// Botão 2
#define BUT_PIO_2      PIOC
#define BUT_PIO_ID_2   ID_PIOC
#define BUT_IDX_2      31
#define BUT_IDX_MASK_2 (1 << BUT_IDX_2)

// Botão 3
#define BUT_PIO_3      PIOA
#define BUT_PIO_ID_3   ID_PIOA
#define BUT_IDX_3      19
#define BUT_IDX_MASK_3 (1 << BUT_IDX_3)


// Função de inicialização do uC
void init(void){
	// Initialize the board clock
	sysclk_init();

	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
	init();

	// Ativa PIOs 1
	pmc_enable_periph_clk(LED_PIO_ID_1);
	pmc_enable_periph_clk(BUT_PIO_ID_1);
  
	// Ativa PIOs 2
	pmc_enable_periph_clk(LED_PIO_ID_2);
	pmc_enable_periph_clk(BUT_PIO_ID_2);
	
	// Ativa PIOs 3
	pmc_enable_periph_clk(LED_PIO_ID_3);
	pmc_enable_periph_clk(BUT_PIO_ID_3);

	// Configura Pinos 1 
	pio_configure(LED_PIO_1, PIO_OUTPUT_0, LED_IDX_MASK_1, PIO_DEFAULT);
	pio_configure(BUT_PIO_1, PIO_INPUT, BUT_IDX_MASK_1, PIO_PULLUP);
	
	// Configura Pinos 2
	pio_configure(LED_PIO_2, PIO_OUTPUT_0, LED_IDX_MASK_2, PIO_DEFAULT);
	pio_configure(BUT_PIO_2, PIO_INPUT, BUT_IDX_MASK_2, PIO_PULLUP);
	
	// Configura Pinos 3
	pio_configure(LED_PIO_3, PIO_OUTPUT_0, LED_IDX_MASK_3, PIO_DEFAULT);
	pio_configure(BUT_PIO_3, PIO_INPUT, BUT_IDX_MASK_3, PIO_PULLUP);
	
	
	// SUPER LOOP
	// aplicacoes embarcadas no devem sair do while(1).
	while(1) {
		
		
		// Verifica valor do pino que o botão está conectado
		if(!pio_get(BUT_PIO_1, PIO_INPUT, BUT_IDX_MASK_1)) {
			// Pisca LED
			for (int i=0; i<10; i++) {
				pio_clear(LED_PIO_1, LED_IDX_MASK_1);  // Limpa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
				pio_set(LED_PIO_1, LED_IDX_MASK_1);    // Ativa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
			}
		} 
		if(!pio_get(BUT_PIO_2, PIO_INPUT, BUT_IDX_MASK_2)) {
			// Pisca LED
			for (int i=0; i<10; i++) {
				pio_clear(LED_PIO_2, LED_IDX_MASK_2);  // Limpa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
				pio_set(LED_PIO_2, LED_IDX_MASK_2);    // Ativa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
			}
		}
		if(!pio_get(BUT_PIO_3, PIO_INPUT, BUT_IDX_MASK_3)) {
			// Pisca LED
			for (int i=0; i<10; i++) {
				pio_clear(LED_PIO_3, LED_IDX_MASK_3);  // Limpa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
				pio_set(LED_PIO_3, LED_IDX_MASK_3);    // Ativa o pino LED_PIO_PIN
				delay_ms(500);                         // delay
			}
		}	
		
			else  {
			// Ativa o pino LED_IDX (par apagar)
			pio_set(LED_PIO_1, LED_IDX_MASK_1);
			pio_set(LED_PIO_2, LED_IDX_MASK_2);
			pio_set(LED_PIO_3, LED_IDX_MASK_3);
		}
  }
  return 0;
}
