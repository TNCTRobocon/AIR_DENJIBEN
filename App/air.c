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
int air_change(uint16_t bus,bool status);
static PSV excute_pair air_bin[] = {
    {"open",air_open},
    {"close",air_close},
    {"clear",air_clear}
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
int air_open(int argc,char** argv){
    int status = 0;
    if(argc <= 1)return 0;
        int i,bus;
        for(i = 1;i < argc;i++){
            bus = atoi(argv[i]);
            status = min(status,air_change(bus,true));
        }
    if(status >= 0)uart_putl("DONE");
    else uart_putl("ERROR");
    return 0;
}
/*個別に閉じる*/
int air_close(int argc,char** argv){
    int status = 0;
    if(argc <= 1)return 0;
        int i,bus;
        for(i = 1;i < argc;i++){
            bus = atoi(argv[i]);
            status = min(status,air_change(bus,true));
        }
    if(status >= 0)uart_putl("DONE");
    else uart_putl("ERROR");
    return 0;
}

/*全部閉じる*/
int air_clear(){
    int i = 0;
    bus1 = false;
    bus2 = false;
    bus3 = false;
    bus4 = false;
    bus5 = false;
    bus6 = false;
    for(i = 0;i < 7;i++)bus_status[i] = false;
    return 0;
}


int air_change(uint16_t bus,bool status){
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
            air_clear();
            return -1;
        }
    return 0;
}