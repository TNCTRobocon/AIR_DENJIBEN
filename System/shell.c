#include "shell.h"
#include "shell_bin.h"
#include "shell_sbin.h"
#include <stddef.h>
#include "../App/air.h"
#include "shell_core.h"
#include "sync.h"
#include <string.h>
#include <stdio.h>

static float temp = 100;

static void shell_listen(){
    file_t root,sbin;//,air;
    path_init();//これまでの構成を破棄
    root=path_root();
    directory_insert(root,sbin=sbin_create());
    directory_registor(sbin);
}

static void shell_selected(){
    file_t root,env,bin,sbin,air;
    path_init();//これまでの構成を破棄
    root=path_root();
    directory_insert(root,bin=bin_create());
    directory_registor(bin);
    directory_insert(root,sbin=sbin_create());
    directory_registor(sbin);
    
    directory_insert(root,air=air_create());
    directory_registor(air);
    
    directory_insert(root, env = directory_create("env"));
    {
        directory_insert(root, float_create("temp", &temp, AccessReadAndWrite));
    }
}

void shell_init() {
    //keep_init();
    select_listen_set(shell_listen);
    select_general_set(shell_selected);
    select_selected_set(shell_selected);
    //select_selected();
    select_listen();
    //shell_listen();//listenモードで起動
}

