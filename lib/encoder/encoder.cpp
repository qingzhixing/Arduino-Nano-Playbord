#include "encoder.h"
#include <Arduino.h>

static int16_t encoder_last_state;
static int16_t encoder_state;
static EncoderKeyCallback on_encoder_press_callback;
static EncoderKeyCallback on_encoder_release_callback;
static EncoderTurnCallback on_encoder_turn_callback;
static bool encoder_last_turn_direction;
static bool encoder_key_last_state;

static void empty_key_callback() {}
static void empty_turn_callback(bool) {}

void on_encoder_key_pressed(EncoderKeyCallback callback)
{
    on_encoder_press_callback = callback;
}

void on_encoder_key_released(EncoderKeyCallback callback)
{
    on_encoder_release_callback = callback;
}

void on_encoder_turned(EncoderTurnCallback callback)
{
    on_encoder_turn_callback = callback;
}

void encoder_init()
{
    pinMode(ENCODER_S1, INPUT_PULLUP);
    pinMode(ENCODER_S2, INPUT_PULLUP);
    pinMode(ENCODER_KEY, INPUT_PULLUP);

    encoder_state = digitalRead(ENCODER_S1);
    encoder_last_state = encoder_state;
    encoder_key_last_state = digitalRead(ENCODER_KEY);

    on_encoder_press_callback = empty_key_callback;
    on_encoder_release_callback = empty_key_callback;
    on_encoder_turn_callback = empty_turn_callback;
}

void encoder_update()
{
    encoder_state = digitalRead(ENCODER_S1);
    bool updated = false;
    if (encoder_state != encoder_last_state)
    {
        updated = true;
        // clockwise turn
        if (digitalRead(ENCODER_S2) == encoder_state)
        {
            encoder_last_turn_direction = true;
        }
        // counterclockwise turn
        else
        {
            encoder_last_turn_direction = false;
        }
    }
    encoder_last_state = encoder_state;
    if (updated)
    {
        on_encoder_turn_callback(encoder_last_turn_direction);
    }
    bool key_state = digitalRead(ENCODER_KEY);
    if (key_state != encoder_key_last_state)
    {
        encoder_key_last_state = key_state;
        if (key_state == ENCODER_KEY_PRESSED_LEVEL)
            on_encoder_press_callback();
        else
            on_encoder_release_callback();
    }
}

bool is_encoder_pressed()
{
    return digitalRead(ENCODER_KEY) == ENCODER_KEY_PRESSED_LEVEL;
}

bool get_encoder_turn_direction()
{
    return encoder_last_turn_direction;
}