#include "../Setting/configuration.h"
#include "ports.h"

void ports_setup(){
    //Switch (STOP)
    //Switch Address (Din)
    TRIS_SEL1(true);
    TRIS_SEL2(true);
    TRIS_SEL4(true);
    TRIS_SEL8(true);
    //ENCODER (Din)
    
    //LED(Dout)
    TRISBbits.TRISB5=false;//LED_ERROR
    TRISBbits.TRISB4=false;//LED_APP
    TRISBbits.TRISB5=false;//LED_RX
    TRISBbits.TRISB5=false;//LED_TX
    
    LATBbits.LATB5=false;
    LATBbits.LATB4=false;
    //UART
    TRISCbits.TRISC14=true;//RX
    TRISCbits.TRISC13=false;//TX

    //cylinder
    TRISEbits.TRISE0=false;
    TRISEbits.TRISE1=false;
    TRISEbits.TRISE2=false;
    TRISEbits.TRISE3=false;
    TRISEbits.TRISE4=false;
    TRISEbits.TRISE5=false;
    TRISEbits.TRISE8=false;
}

inline uint16_t port_address(){
    return  ((!PIN_SEL1())<<0)+
            ((!PIN_SEL2())<<1)+
            ((!PIN_SEL4())<<2)+
            ((!PIN_SEL8())<<3);   
}

inline void led_rx(bool fag){
    LED_RX=fag;
}

inline int16_t port_get(int idx){
    switch (idx){
        case 1:
            return PORTB;
        case 2:
            return PORTC;
        case 3:
            return PORTD;
        case 4:
            return PORTE;
        case 5:
            return PORTF;
        default:
            return -1;//ERROR
    }
}

inline bool pin_encode_idx(){
    return PORTBbits.RB3;
}
inline bool pin_encode_x(){
    return PORTBbits.RB4;
}
inline bool pin_encode_y(){
    return PORTBbits.RB5;
}