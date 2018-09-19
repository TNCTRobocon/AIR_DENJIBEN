#include "Setting/configuration.h"
#include "Driver/driver.h"
#include "System/shell.h"
#include "Driver/uart.h"
#include "System/system.h"
#include <stdbool.h>
#include <stdlib.h>
#include "Driver/ports.h"
#include "Driver/timer.h"
#include "System/shell_sbin.h"

int main(){
    driver_setup();
    system_setup();
    uart_begin();
    uart_putl("started");
    for (;;){
        //while(!uart_depth());
        //uart_putc(uart_getc());
        system_process();
    }
    __asm("reset");//初期化
    return 0;//決してここまで来ない
}
