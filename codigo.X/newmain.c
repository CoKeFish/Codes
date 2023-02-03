/*
 * File:   newmain.c
 * Author: Rodion TC
 *
 * Created on 29 de enero de 2023, 12:27
 */


#include <xc.h>
#include "config.h"
#include "funtions_magic.h"
#include "init_IO.h"


void main(void) {
    init_IO();
    
    while(1)
    {
        long iADC = readADC();
        int *B = BinTOBcd(iADC);
        //int B[3] = {7, 8, 10};
        int* A = seg7(B);
        showNumbers(A);
        UART_print(ASCII_Con(B[2], B[1], B[0]));
        
    }
    
    return;
}
/*
void __interrupt() ISR_TIMER0(void){
    
    if(INTCONbits.TMR0IF == 1){
        
        LATBbits.LATB1 = ! LATBbits.LATB1; 
         TMR0L = 255;
        INTCONbits.TMR0IF = 0;
    }
    
}

void TMR0_temporizador(void){
     
     OPTION_REGbits.TMR0CS = 0;          //Modo Temporizador
     OPTION_REGbits.PSA = 0;             //Prescaler habilitado
     OPTION_REGbits.PS = 0b111;          //Prescaler 1:256   
   
     TMR0 = 0;
     T0CONbits.TMR0ON = 1; //Enciende TMR0   
}
*/
