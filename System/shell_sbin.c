#include "shell_sbin.h"
#include "../Setting/types.h"
#include <stdlib.h>
#include "../Driver/uart.h"
#include "shell_core.h"
#include "shell.h"
#include "../Driver/ports.h"
#include "../Setting/configuration.h"
#include "../App/air.h"
const static int16_t address_ofset=+32;

int16_t address_get(){
    //return address_ofset+port_address();
    return 32;
}

static PSV excute_pair lst_excute[]={
    {"rst",sbin_rst},
    {"sel",sbin_sel},
//    {"sync",sbin_sync},
    /*モタドラとの共存用*/
    {"mc",bin_nothing},
    {"reboot",bin_nothing},
    {"dt",bin_nothing}
};

file_t sbin_create(){
    file_t sbin;
    sbin = directory_create("sbin");
    directory_insert_excute(sbin,lst_excute,sizeof(lst_excute)/sizeof(lst_excute[0]));
    
    return sbin;
}

int sbin_rst(int argc,char** argv){
    __asm("RESET");//ソフトウェアにより強制リセット
    return 0;
}

int sbin_sel(int argc,char** argv){
    int16_t address;
    if (argc>1){
        address=atoi(argv[1]);
        if (address!=address_get()){
            //listem mode
            select_listen();
        }else if (address==0){
            //general call
            select_general();
        }else{
            //selected
            select_selected();
        }
    }else{
       //listen mode
        select_listen();
    }
    return 0;
}

int bin_nothing(){
    return 0;
}