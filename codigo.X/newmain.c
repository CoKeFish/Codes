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

void TMR0_temporizador(void);

void main(void) {
    init_IO();
    TMR0_temporizador();
    
    while(1)
    {
        
        
    }
    
    return;
}

void __interrupt() INT_TMR0(void){
    static int count = 0;
    if(INTCONbits.TMR0IF == 1){
        if(count == 20)
        {
            ADis = ! ADis;
            count = 0;
        }
        //ADis = ! ADis; 
        count++;
        TMR0 = 60;
        INTCONbits.TMR0IF = 0;
    }
    
}

void TMR0_temporizador(void){
     
     OPTION_REGbits.TMR0CS = 0;          //Modo Temporizador
     OPTION_REGbits.PSA = 0;             //Prescaler habilitado
     OPTION_REGbits.PS = 0b111;          //Prescaler 1:256
     
     INTCONbits.GIE = 1;
     INTCONbits.PEIE = 1;
     INTCONbits.TMR0IE = 1;
     INTCONbits.TMR0IF = 0;
   
     TMR0 = 60;
     //T0CONbits.TMR0ON = 1; //Enciende TMR0   
}

