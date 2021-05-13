#ifndef _RS485_H_
#define	_RS485_H_

#include "main.h"


typedef struct
{
    /* data */
    float temp1;    //测量值
    float temp2;    //温度
}SENSOR;

extern SENSOR sensor;

void Rxdata_process(void);



#endif

