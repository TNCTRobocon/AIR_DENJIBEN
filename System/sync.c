#include "sync.h"
#include "../Setting/configuration.h"
#include <stddef.h>
#include <string.h>

struct keeper{
    int argc;
    char* argv[WORD_MAX-1];
    char text[CMD_LENGTH];
};

typedef struct keeper keeper_t;

static keeper_t keeped[KEEP_MAX];
static size_t used;  //FIFO(入った順番に出るやつ)


void keep_init(){
    used = 0;
}

int listen_sync(int argc, char** argv){
    if(argc < 1)return -1;
    keeper_t *it;
    int cnt = 0;
    for(it = keeped;it < used + keeped;it++,cnt++){
        
    }
    return 0;
}

int selected_keep(int argc,char** argv){
    if(used >= KEEP_MAX)return -1;  //限界以上
    keeper_t *target = keeper+used;   //コマンドの代入
    used++;
    char *out = target->text;
    int pos;
    for(pos = 1;pos < argc;pos++){
        size_t len = strlen(argv[pos]);
        strcpy(out,argv[pos]);
        target -> argv[pos-1] = out;
        out += len;
    }
    target -> argc = argc - 1;
    return 0;
}

