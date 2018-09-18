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
    {"go",air_go}
};

file_t air_create() {
    file_t air;
    air = directory_create("air");
    directory_insert_excute(air,air_bin,sizeof(air_bin)/sizeof(air_bin[0]));
    return air;
}

void air_open(int argc,char** argv){
    uint16_t bus = atoi(argv[1]);
    switch(bus){
        case 1:
            bus1 = true;
            break;
        case 2:
            bus2 = true;
            break;
        case 3:
            bus3 = true;
            break;
        case 4:
            bus4 = true;
            break;
        case 5:
            bus5 = true;
            break;
        case 6:
            bus6 = true;
            break;
        case 7:
            bus7 = true;
            break;
        default:
            uart_putl("ERROR ALL BUS CLOSED");
            air_clear();
            break;
    }
    uart_putl("OPENED");
}

void air_close(int argc,char** argv){
    uint16_t bus = atoi(argv[1]);
    switch(bus){
        case 1:
            bus1 = false;
            break;
        case 2:
            bus2 = false;
            break;
        case 3:
            bus3 = false;
            break;
        case 4:
            bus4 = false;
            break;
        case 5:
            bus5 = false;
            break;
        case 6:
            bus6 = false;
            break;
        case 7:
            bus7 = false;
            break;
        default:
            uart_putl("ERROR ALL BUS CLOSED");
            air_clear();
            break;
    }
    uart_putl("CLOSED");
}

void air_ready(int argc,char** argv){
    uint16_t bus_on;
    uint16_t i;
    for(i = argc;i > 0;i--){
        bus_on=atoi(argv[i]);
        bus_status[bus_on] = true;
    }
    uart_putl("ready");
}

void air_go(){
    bus1 = bus_status[0];
    bus2 = bus_status[1];
    bus3 = bus_status[2];
    bus4 = bus_status[3];
    bus5 = bus_status[4];
    bus6 = bus_status[5];
    bus7 = bus_status[6];
    uart_putl("go");
}

void air_clear(){
    bus1 = false;
    bus2 = false;
    bus3 = false;
    bus4 = false;
    bus5 = false;
    bus6 = false;
    bus7 = false;
}