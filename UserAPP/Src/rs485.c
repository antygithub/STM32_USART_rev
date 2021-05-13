#include "rs485.h"
#include "stm32f1xx_it.h"
#include "usart.h"


//读传感器命令
uint8_t Inquire1[8] = {0x01, 0x04, 0x00, 0x00, 0x00, 0x02, 0x71, 0xCB};
uint8_t Inquire2[8] = {0x01, 0x04, 0x00, 0x03, 0x00, 0x01, 0xC1, 0xCA};
SENSOR sensor;

//帧数据处理
void Rxdata_process(void)
{
  union Data
  {
    /* data */
    uint8_t rev[4];       //接收数据字符
    float   temp1;        //测量值
    uint16_t  temp2;      //温度值
  }data;
  
  //接收到查询数据指令
  if(USART2_rev.rxend_flag == 1)
  {
      if((USART2_rev.rx_buffer[3]) == 0x00)
      {
          //生成测量值
            HAL_UART_Transmit(&huart2, (uint8_t *)Inquire1, 8, 500);

      }
      else if((USART2_rev.rx_buffer[3]) == 0x03)
      {
          //生成温度值
            HAL_UART_Transmit(&huart2, (uint8_t *)Inquire2, 8, 500);
      }
  }
//   if(USART2_rev.rxend_flag == 1)
//     {
//         //接收到一帧数据
//         if((USART2_rev.rx_buffer[0] == 0x01) && (USART2_rev.rx_buffer[1] == 0x04) && (USART2_rev.rx_buffer[2] == 0x04))
//         {
//             //数据帧为测量值
//             data.rev[0] = USART2_rev.rx_buffer[5];
//             data.rev[1] = USART2_rev.rx_buffer[6];
//             data.rev[2] = USART2_rev.rx_buffer[3];
//             data.rev[3] = USART2_rev.rx_buffer[4];
//             printf("temp1:\t%.1f\r\n", data.temp1);   //打印测量值
//         }
//         else if((USART2_rev.rx_buffer[0] == 0x01) && (USART2_rev.rx_buffer[1] == 0x04) && (USART2_rev.rx_buffer[2] == 0x02))
//         {
//             //数据帧为温度值
//             data.rev[0] = USART2_rev.rx_buffer[3];
//             data.rev[1] = USART2_rev.rx_buffer[4];
//             printf("temp1:\t%d\r\n", data.temp2);     //打印温度值
//         }
//     }
}

//485读传感器
//不需要读传感器 使用单片机模拟传感器
//单片机串口收到主机485读数据指令 生成随机数据返回给上位机 以模拟传感器




