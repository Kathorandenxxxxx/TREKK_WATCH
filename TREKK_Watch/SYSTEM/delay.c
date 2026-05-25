#include "delay.h"
#include "sys.h"

void delay_init(void)
{
    /* Configure SysTick to generate an interrupt every 1 ms */
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
     /* Configure the SysTick to have interrupt in 1ms time basis*/
    HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
}

void delay_us(u32 us)
{
    u32 ticks;
    u32 told, tnow, tcnt = 0;
    u32 reload = SysTick->LOAD; // LOAD的值
    ticks = us * SYS_CLK;
    told = SysTick->VAL; // 刚进入时的计数值
    while (1)
    {
        tnow = SysTick->VAL; // 当前的计数值
        if (tnow != told)
        {
            if (tnow < told)
                tcnt += told - tnow; // 这里注意一下SYSTICK是递减的
            else
                tcnt += reload - tnow + told;
            told = tnow;
            if (tcnt >= ticks)
                break; // 时间超过/等于要延迟的时间，退出
        }
    }

}

void delay_ms(u32 ms)
{
    u32 i;
    for (i = 0; i < ms; i++)
    {
        delay_us(1000);
    }
}
