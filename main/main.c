#include <stdio.h>
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 2

#define LITTLE_TO_BIG_ENDIAN(buff)   (buff[0] |(buff[1]<<8) | (buff[2]<<16) | (buff[3]<<24));



void app_main(void){

  gpio_pad_select_gpio(PIN);
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

  int isOn = 0;
  int delay = 0;

  while (true){
    isOn = !isOn;

    if(isOn == true)
      delay = 80;
    else 
      delay = 8000;

    gpio_set_level(PIN,isOn);
    vTaskDelay (delay/portTICK_PERIOD_MS);
  }

}

