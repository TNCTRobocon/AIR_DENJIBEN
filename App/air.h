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
#include "../System/shell_core.h"


file_t air_create();
file_t air_path_create();

int air_open(int argc,char** argv);
int air_close(int argc,char** argv); 
int air_clear();

#endif	/* XC_HEADER_TEMPLATE_H */

