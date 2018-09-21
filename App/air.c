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

static int bus_status[6] = {0,0,0,0,0,0};

static PSV excute_pair air_bin[] = {
    {"open",air_open},
    {"close",air_close},
    //{"ready",air_ready},
    {"clear",air_clear}//,
    //{"ready2",air_ready2},
    //{"go",air_go}
};

/*static PSV excute_pair path[] = {
    {"on",air_go},
    {"clear",air_clear}
};*/

file_t air_create() {
    file_t air;
    air = directory_create("air");
    directory_insert_excute(air,air_bin,sizeof(air_bin)/sizeof(air_bin[0]));
    return air;
}

/*file_t air_path_create() {
    file_t air_path;
    air_path = directory_create("air_path");
    directory_insert_excute(air_path,path,sizeof(path)/sizeof(path[0]));
    return air_path;
}*/
/*個別に開く*/
void air_open(int argc,char** argv){
    static uint16_t bus;
    if(argc == 2){
        bus = atoi(argv[1]);
        air_change(bus,true);
    }else if(argc >= 3){
        int i,bus;
        for(i = argc;i > 0;i--){
            bus_status[i] = atoi(argv[i]);
            air_change(bus_status[i],true);
        }
    }
}
/*個別に閉じる*/
void air_close(int argc,char** argv){
    uint16_t bus;
    if(argc == 2){
        bus = atoi(argv[1]);
        air_change(bus,false);
    }else if(argc >= 3){
        int i,bus;
        for(i = argc;i > 0;i--){
            bus_status[i] = atoi(argv[i]);
            air_change(bus_status[i],false);
        }
    }
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
    for(i = 0;i < 7;i++)bus_status[i] = false;
}


void air_change(uint16_t bus,bool status){
    switch(bus){
        case 1:
            bus1 = status;
            break;
        case 2:
            bus2 = status;
            break;
        case 3:
            bus3 = status;
            break;
        case 4:
            bus4 = status;
            break;
        case 5:
            bus5 = status;
            break;
        case 6:
            bus6 = status;
            break;
        default:
            //uart_putl("ERROR ALL BUS CLOSED");
            air_clear();
            break;
        }
}