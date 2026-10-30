#include "pico/stdlib.h"
#include "../boards/custom_pico2.h" // Include the custom board header file

#define LED_PIN PICO_RGB_R_PIN // Use the custom RGB Red pin defined in custom_pico2.h

#define LED_DELAY_MS 250 // LED delay

// The RGB LED is common anode (anode tied to 3V3), so each channel is
// active low: driving a pin low turns it on, driving it high turns it off.
#define RGB_ON  false
#define RGB_OFF true

static void rgb_init(void) {
    const uint pins[] = {PICO_RGB_R_PIN, PICO_RGB_G_PIN, PICO_RGB_B_PIN};
    for (int i = 0; i < 3; i++) {
        gpio_init(pins[i]);
        gpio_put(pins[i], RGB_OFF); // set level before enabling output to avoid a flash
        gpio_set_dir(pins[i], GPIO_OUT);
    }
}

int main() {
    stdio_init_all();
    rgb_init();

    while (1) {
        gpio_put(LED_PIN, RGB_ON);
        sleep_ms(LED_DELAY_MS);
        gpio_put(LED_PIN, RGB_OFF);
        sleep_ms(LED_DELAY_MS);
    }
}
