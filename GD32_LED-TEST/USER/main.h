
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


TaskHandle_t StartTask_Handler;         //������

#define START_TASK_PRIO         1       //�������ȼ�
#define START_STK_SIZE          512     //�����ջ��С
void start_task(void *pvParameters);    //������

