#include "sync.h"
#include "../Setting/configuration.h"
#include <stddef.h>
#include <string.h>

struct keeper{
    int argc;
    char* argv[WORD_MAX-1];
    //char text[CMD_LENGTH];
};

typedef struct keeper keeper_t;
static char pool[KEEP_TXT_MAX];
static keeper_t keeped[KEEP_CMD_MAX];
static size_t *pool_it;
static size_t keep_used;  //FIFO(入った順番に出るやつ)


void keep_init(){
    keep_used = 0;
    pool_it = pool;
    size_t volatile result = sizeof(keeped);
    uart_putl("a");
}

int listen_sync(int argc, char** argv){
    if(argc < 1)return -1;
    keeper_t *it;
    int cnt = 0;
    for(it = keeped;it < keep_used + keeped;it++,cnt++){
        
    }
    return 0;
}

int selected_keep(int argc,char** argv){
    if(keep_used >= KEEP_CMD_MAX)return -1;  //限界以上
    keeper_t *target = keeped;// used++;  //コマンドの代入
    char *out = pool_it;
    int pos;
    for(pos = 1;pos < argc;pos++){
        size_t len = strlen(argv[pos]);
        char *next = out+len;   //次の先頭
        if(next >= pool+KEEP_TXT_MAX)return -1;//error
        strcpy(out,argv[pos]);
        target -> argv[pos-1] = out;
        out = next;
    }
    pool_it = out;
    target -> argc = argc - 1;
    return 0;
}

