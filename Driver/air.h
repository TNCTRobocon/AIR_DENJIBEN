/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "../System/file.h"

file_t air_create();

void air_open(int argc,char** argv);
void air_close(int argc,char** argv);
void air_ready(int argc,char** argv);
void air_clear();
void air_go();

#endif	/* XC_HEADER_TEMPLATE_H */

