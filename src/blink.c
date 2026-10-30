#include "pico/stdlib.h"

#define USR_LED_PIN 19

#define LED_DELAY_MS 250 // LED delay

int main() {
    stdio_init_all();
    gpio_init(USR_LED_PIN);
    gpio_set_dir(USR_LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(USR_LED_PIN, true);
        sleep_ms(LED_DELAY_MS);
        gpio_put(USR_LED_PIN, false);
        sleep_ms(LED_DELAY_MS);
    }
}