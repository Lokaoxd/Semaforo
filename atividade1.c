#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

const uint led_pin_red   = 11;
const uint led_pin_green = 13;
const uint led_pin_yellow  = 12;

int state = 0;

bool repeating_timer_callback(struct repeating_timer *t);

int main()
{
    stdio_init_all();

    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);
    gpio_init(led_pin_yellow);
    gpio_set_dir(led_pin_yellow, GPIO_OUT);
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    gpio_put(led_pin_yellow, false);
    gpio_put(led_pin_green, false);
    gpio_put(led_pin_red, false);

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Sistema de semáforo executando corretamente!\n");
        sleep_ms(1000);
    }
}

bool repeating_timer_callback(struct repeating_timer *t){

    if (state == 0){
        gpio_put(led_pin_green, false);
        gpio_put(led_pin_red, true);
        state = 1;
    }
    else if (state == 1){
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_yellow, true);
        state = 2;
    }
    else if (state == 2){
        gpio_put(led_pin_yellow, false);
        gpio_put(led_pin_green, true);
        state = 0;
    }

    return true;
}
