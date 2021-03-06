/* 
 * File:   configuration.h
 * Author: TERU
 *
 * Created on 2016/03/23, 0:16
 */

#ifndef CONFIGURATION_H
#define	CONFIGURATION_H


//デバイス環境
#include "p30F4012.h"


//環境構築
#define FORIG (1000000UL)
#define FOSC (FORIG*8/4) //10[MHz]*8[PLL]/4[DIV]=20[MHz] 

//10MHz*8(PLL)/4(divsion))

//デバイスを選択する
#define DEVICE_COMMON
//#define DEVICE_DRAGON

#if defined(DEVICE_COMMON)
#define PORT_TYPE_A
#elif defined(DEVICE_DRAGON)
#define PORT_TYPE_B
#define ADC_USE
#endif


//アドレス取得　ピン配置
#if defined(PORT_TYPE_A)
#define PIN_SEL1() PORTBbits.RB0
#define PIN_SEL2() PORTBbits.RB1
#define PIN_SEL4() PORTBbits.RB2
#define PIN_SEL8() PORTBbits.RB3
#define TRIS_SEL1(X) TRISBbits.TRISB0=(X)
#define TRIS_SEL2(X) TRISBbits.TRISB1=(X)
#define TRIS_SEL4(X) TRISBbits.TRISB2=(X)
#define TRIS_SEL8(X) TRISBbits.TRISB3=(X)
#elif defined(PORT_TYPE_B)

//TODO ピン配置を設定する
#endif
//Stoper
#define SW_ST()   PORTEbits.RE8

//LED
#define LED_RX      LATBbits.LATB5
#define LED_TX      LATBbits.LATB5
#define LED_ERROR   LATEbits.LATE5
#define LED_APP     LATBbits.LATB4

#define PIN_HIGH(x) ((x)=true)
#define PIN_LOW(x)  ((x)=false)
#define PIN_INV(x)  ((x)=(^x))

//PWM
#define ST_PIN      LATEbits.LATE4
//UART
#define RX_BUFFER_SIZE  (128) //受信バッファの一つ当たりの大きさ
#define TX_BUFFER_SIZE  (128)
#define CMD_LENGTH (32)        // システムが受け入れられる文字の最大数、
#define CMD_MAX     (32)        // 最大分割数(1LINEあたり)
#define FILE_MAX    (48)        // 最大ファイル数
#define MULTI_MAX (16) //同時に実行できるコマンドの最大値
#define WORD_MAX (32)   //argvの最大値
#define PATH_DEPTH_MAX (8)
#define QUICK_MAX (8) 
#define KEEP_MAX (16)     //保存できるコマンドの最大数

//EEPROM
#define EEPROM_BUFFER_SIZE (64) //EEPROMの書き込み用バッファ

//ADC





#endif	/* CONFIGURATION_H */

