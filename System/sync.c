#include "sync.h"
#include "../Setting/configuration.h"
#include <stddef.h>
#include <string.h>

struct keeper{
    int argc;
    char* argv[WORD_MAX-1];
    //char text[CMD_LENGTH];
};

<<<<<<< HEAD
typedef struct keeper keeper_t;               //変数の方を定義
static char pool[KEEP_TXT_MAX];               //入力されたコマンドを保存する
static keeper_t keeped[KEEP_CMD_MAX];
static size_t *pool_it;   //poolの先頭の場所を指定
=======
typedef struct keeper keeper_t;
static char pool[KEEP_TXT_MAX];
static keeper_t keeped[KEEP_CMD_MAX];
static size_t *pool_it;
>>>>>>> ba27f8d9bc09f50da486fc0c8091c9a75ec587c1
static size_t keep_used;  //FIFO(入った順番に出るやつ)


void keep_init(){
    keep_used = 0;
    pool_it = pool;
<<<<<<< HEAD
    //size_t volatile result = sizeof(keeped);//構造体のメモリを測定する関数
    //uart_putl("a");                         //breakpoint用の関数
=======
    //size_t volatile result = sizeof(keeped);
    //uart_putl("a");
>>>>>>> ba27f8d9bc09f50da486fc0c8091c9a75ec587c1
}

int listen_sync(int argc, char** argv){
    if(argc < 1)return -1;
    keeper_t *it;
    int cnt = 0;
    for(it = keeped;it < keep_used + keeped;it++,cnt++){
<<<<<<< HEAD

=======
        
>>>>>>> ba27f8d9bc09f50da486fc0c8091c9a75ec587c1
    }
    return 0;
}

int selected_keep(int argc,char** argv){
<<<<<<< HEAD
    if(keep_used >= KEEP_CMD_MAX)return -1;     //限界以上
    keeper_t *target = keeped;                  //コマンドの代入
    char *out = pool_it;                        //先頭の番地を指定
    int pos;
    for(pos = 1;pos < argc;pos++){
        size_t len = strlen(argv[pos]);         //文字列の長さを計測
        char *next = out+len;                   //次の先頭
        if(next >= pool+KEEP_TXT_MAX)return -1; //error
        strcpy(out,argv[pos]);                  //outにコピー
        target -> argv[pos-1] = out;            //構造体のargv[]に代入
        out = next;                             //outの更新
    }
    pool_it = out;     //
    target -> argc = argc - 1;    //argcの値を減らす
    return 0;
}
=======
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

>>>>>>> ba27f8d9bc09f50da486fc0c8091c9a75ec587c1