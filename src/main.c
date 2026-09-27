#include "sdk_project_config.h"

int main(void)
{
    CLOCK_DRV_Init(&clockMan1_InitConfig0);
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    PWM_Init(&pwm_pal_1_instance, &pwm_pal_1_configs);
    while(1)
    {
        for(uint16_t duty = 0; duty <= 1000; duty += 25)
        {
            PWM_UpdateDuty(&pwm_pal_1_instance, 0u, duty);
            OSIF_TimeDelay(50);
        }

        for(uint16_t duty = 1000; duty > 0; duty -= 25)
        {
            PWM_UpdateDuty(&pwm_pal_1_instance, 0u, duty);
            OSIF_TimeDelay(50);
        }
    }
}
