/*
 * File:   main.c
 * Author: novel
 *
 * Created on April 24, 2019, 5:38 PM
 */


#include <xc.h>


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON          // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

# define _XTAL_FREQ 4000000

void main(void) {
    /*Tabla con los valores de los dígitos en 7 segmentos*/
    /* digito  =        0    1    2    3    4    5    6    7    8    9  */
    char display[10] = {0x3F,0x06,0xB5,0x4F,0x69,0x6D,0x5F,0x07,0x6F,0x6F};
    int medida = 0;
    
    /*INICIALIZACIÓN DE LOS PUERTOS*/
    TRISA=0b11101011;
    TRISC=0b00000000;//PORTC como salida
    TRISD=0b00000000;//PORTD como salida
    
    /*INICIALIZACIÓN DE INTERRUPCIONES*/
    INTCON=0;//limpieza del registro INTCON
    INTCONbits.GIE=1;//Habilitacion de interrupciones
    /*INICIALIZACIÓN DEL CONVERSOR ANALÓGICO A DIGITAL*/
    ADCON0=0b10000000; //Configuracion del registro ADCON0
    // un solo canal ADC
    ADCON1=0b10001110; //Configuracion del registro ADCON1
    // Justificado a la derecha
    
     while(1){
        for (int i = 0;i<10;i++){
            PORTC = display[i]; 
            __delay_ms(1000);
        }
     }

    
    /*ADCON0bits.ADON =1;
    __delay_ms(100);
   
    while(1){
         ADCON0bits.GO=1;//Inicia la conversión por ADC
         while (ADCON0bits.GO==1){}// espera a que la conversión esté lista
         medida = ADRESH*256 + ADRESL; //en medida se guarda el valor de la conversión

    }*/
    return;
}
