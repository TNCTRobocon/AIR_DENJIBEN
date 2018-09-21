#include "system.h"
#include "shell.h"
#include "../Driver/uart.h"
#include "../Setting/configuration.h"
#include <stdlib.h>
#include <string.h>

void system_setup(){
    shell_init();   
}

void system_process(){
    char buf[CMD_LENGTH];
    if (uart_have('\r')){
        uart_gets(buf,sizeof(buf));
        //uart_putl(buf);
        shell_system(buf);
    }
}
