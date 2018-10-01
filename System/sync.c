#include "sync.h"
#include "../Setting/configuration.h"
#include "shell_core.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct keeper{
    int argc;
    char* argv[WORD_MAX-1];
};

typedef struct keeper keeper_t;               //変数の型を定義
static char pool[KEEP_TXT_MAX];               //入力されたコマンドを保存する
static keeper_t keeped[KEEP_CMD_MAX];
static size_t *pool_it;   //poolの先頭の場所を指定
static size_t keep_used;  //FIFO(入った順番に出るやつ)


void keep_init(){
    keep_used = 0;
    pool_it = pool;
    //size_t volatile result = sizeof(keeped);//構造体のメモリを測定する関数
    //uart_putl("a");                         //breakpoint用の関数
}

int listen_sync(int argc, char** argv){
    if(argc < 1)return -1;                      //コマンドの値がない時にエラーを返す
    keeper_t *it;                               //keeper_t型のポインタを定義
    keeper_t *p;
    int cnt = 0;
    for(it = keeped;it < keep_used + keeped;it++,cnt++){
        status = shell_system_s(p -> argc,p -> argv[cnt]);//コマンドの実行部分
    }
    return 0;
}

int selected_keep(int argc,char** argv){
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
    pool_it = out;                              //先頭番地の値を更新
    target -> argc = argc - 1;                  //argcの値を減らす
    return 0;
}

