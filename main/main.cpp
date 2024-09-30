#include "Arduino.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <Adafruit_NeoPixel.h>

// 定义灯带引脚和 LED 数量
#define LED_PIN    13
#define LED_COUNT  8


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

extern "C" void app_main()
{
    initArduino();
    Serial.begin(115200);
    while(!Serial){
        //等待串口初始化完成
    }

    Serial.println("Starting LED control");

    strip.begin();
    strip.show();  // 初始化所有像素为"关"


    for(;;){
        // 设置所有 LED 为红色
        for (int i = 0; i < LED_COUNT; i++) {
            strip.setPixelColor(i, strip.Color(255, 0, 0));  // 红色
        }
        strip.show();  // 更新显示
        delay(1000);
        
        // 设置所有 LED 为绿色
        for (int i = 0; i < LED_COUNT; i++) {
            strip.setPixelColor(i, strip.Color(0, 255, 0));  // 绿色
        }
        strip.show();
        delay(1000);
    }

}