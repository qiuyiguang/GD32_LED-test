#include "main.h"
#include "gd32f4xx.h"

#define LED_GPIO_PORT   GPIOA
#define LED_PIN         GPIO_PIN_12


void delay(uint16_t time)
{
    uint16_t i = 0;
    while(time--)
    {
        i = 12000;
        while(i--);
    }
    
}

void LED_Off(void)
{
    GPIO_BOP(LED_GPIO_PORT) = LED_PIN;
}

void LED_On(void)
{
    
    GPIO_BC(LED_GPIO_PORT) = LED_PIN;
}

void LED_init()
{
    rcu_periph_clock_enable(RCU_GPIOA); 
    rcu_periph_clock_enable(RCU_USART0);
    rcu_periph_clock_enable(RCU_SYSCFG);
    rcu_periph_clock_enable(RCU_PMU);
    gpio_mode_set(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, LED_PIN);
    gpio_output_options_set(LED_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, LED_PIN);

    //GPIO_BOP(LED_GPIO_PORT) = LED_PIN;
    LED_Off();
}

void start_task(void *pvParameters)
{
    LED_init();
    while(1)
    {
    
        LED_On();
        vTaskDelay(500);
        LED_Off();
        vTaskDelay(500);
        
   }
    
}
int main()
{
//    LED_init();
//    while(1)
//    {
//    
//        LED_On();
//        delay(500);
//        LED_Off();
//        delay(500);
//        
//    }
    
    xTaskCreate((TaskFunction_t )start_task,            
            (const char* )"start_task",             
            (uint16_t )START_STK_SIZE,              
            (void* )NULL,                           
            (UBaseType_t )START_TASK_PRIO,          
            (TaskHandle_t* )&StartTask_Handler);     

   
    vTaskStartScheduler();

}

