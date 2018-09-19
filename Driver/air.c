#include "air.h"
#include "../System/shell_core.h"
#include "../Setting/types.h"
#include "../Driver/uart.h"
#include <stdlib.h>

#define bus1 LATEbits.LATE0
#define bus2 LATEbits.LATE1
#define bus3 LATEbits.LATE2
#define bus4 LATEbits.LATE3
#define bus5 LATEbits.LATE4
#define bus6 LATEbits.LATE5
#define bus7 LATEbits.LATE8

int bus_status[7] = {0,0,0,0,0,0,0};

static PSV excute_pair air_bin[] = {
    {"open",air_open},
    {"close",air_close},
    {"ready",air_ready},
    {"clear",air_clear},
    {"ready2",air_ready2},
    {"go",air_go}
};

file_t air_create() {
    file_t air;
    air = directory_create("air");
    directory_insert_excute(air,air_bin,sizeof(air_bin)/sizeof(air_bin[0]));
    return air;
}
/*個別に開く*/
void air_open(int argc,char** argv){
    uint16_t bus = atoi(argv[1]);
    switch(bus){
        case 1:
            bus1 = true;
            //uart_putl("BUS1 OPENED");
            break;
        case 2:
            bus2 = true;
            //uart_putl("BUS2 OPENED");
            break;
        case 3:
            bus3 = true;
            //uart_putl("BUS3 OPENED");
            break;
        case 4:
            bus4 = true;
            //uart_putl("BUS4 OPENED");
            break;
        case 5:
            bus5 = true;
            //uart_putl("BUS5 OPENED");
            break;
        case 6:
            bus6 = true;
            //uart_putl("BUS6 OPENED");
            break;
        case 7:
            bus7 = true;
            //uart_putl("BUS7 OPENED");
            break;
        default:
            uart_putl("ERROR ALL BUS CLOSED");
            air_clear();
            break;
    }
}
/*個別に閉じる*/
void air_close(int argc,char** argv){
    uint16_t bus = atoi(argv[1]);
    switch(bus){
        case 1:
            bus1 = false;
            //uart_putl("BUS1 CLOSED");
            break;
        case 2:
            bus2 = false;
            //uart_putl("BUS2 CLOSED");
            break;
        case 3:
            bus3 = false;
            //uart_putl("BUS3 CLOSED");
            break;
        case 4:
            bus4 = false;
            //uart_putl("BUS4 CLOSED");
            break;
        case 5:
            bus5 = false;
            //uart_putl("BUS5 CLOSED");
            break;
        case 6:
            bus6 = false;
            //uart_putl("BUS6 CLOSED");
            break;
        case 7:
            bus7 = false;
            //uart_putl("BUS7 CLOSED");
            break;
        default:
            uart_putl("ERROR ALL BUS CLOSED");
            air_clear();
            break;
    }
}
/*同時に開く用の関数*/
void air_ready(int argc,char** argv){
    uint16_t bus_on;
    uint16_t i;
    if(ready_check() >= 0){
            for(i = 0;i < 7;i++)bus_status[i] = false;
    }
    for(i = argc;i > 0;i--){
        bus_on=atoi(argv[i])-1;
        bus_status[bus_on] = true;
    }
}

void air_ready2(int argc,char** argv){
    uint16_t bus_on;
    uint16_t i;
    for(i = argc;i > 0;i--){
        bus_on=atoi(argv[i])-1;
        bus_status[bus_on] = false;
    }
}
/*同時に開く用の関数*/
void air_go(){
    bus1 = bus_status[0];
    bus2 = bus_status[1];
    bus3 = bus_status[2];
    bus4 = bus_status[3];
    bus5 = bus_status[4];
    bus6 = bus_status[5];
    bus7 = bus_status[6];
}
/*全部閉じる*/
void air_clear(){
    int i = 0;
    bus1 = false;
    bus2 = false;
    bus3 = false;
    bus4 = false;
    bus5 = false;
    bus6 = false;
    bus7 = false;
    for(i = 0;i < 7;i++)bus_status[i] = false;
}

int ready_check(){
    int i;
    int sum = 0;
    for(i = 0;i < 7;i++)sum = sum+bus_status[i];
    return sum;
}