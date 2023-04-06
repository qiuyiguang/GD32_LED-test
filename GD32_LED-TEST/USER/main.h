
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


TaskHandle_t StartTask_Handler;         //任务句柄

#define START_TASK_PRIO         1       //任务优先级
#define START_STK_SIZE          512     //任务堆栈大小
void start_task(void *pvParameters);    //任务函数

