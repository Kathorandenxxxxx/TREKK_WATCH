#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "sys.h"

void delay_init(void);
void delay_ms(u32 ms);
void delay_us(u32 us);

#ifdef __cplusplus
}
#endif


#endif 
