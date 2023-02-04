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
        
        
    }
    
    return;
}

void __interrupt() INT_TMR0(void){
    static int count = 0;
    if(INTCONbits.TMR0IF == 1){
        if(count == 20)
        {
            ADis = ! ADis;
            readADC();
            count = 0;
        }
        //ADis = ! ADis; 
        count++;
        TMR0 = 60;
        INTCONbits.TMR0IF = 0;
        return;
    }
    if(PIR1bits.ADIF == 1){
        
        BDis = ! BDis; 
        PIR1bits.ADIF = 0;
        ADCON0bits.ADON = 0;
        return;
    }
    
}



