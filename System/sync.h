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

void keep_init();
int listen_sync(int argc, char** argv);
int selected_keep(int argc,char** argv);

#endif	/* XC_HEADER_TEMPLATE_H */

