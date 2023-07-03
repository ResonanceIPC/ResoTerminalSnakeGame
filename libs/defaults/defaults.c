// Including global libraries
#include <stdio.h>

// Including local libraries
#include "../model/model.h"
#include "../screen/screen.h"

// Universe model for FIELD
struct Model universe_0 = {
        .selftouch = 0,
        .empty_char = ' ',
        .border_char = '#',
        .snake_char = '0',
        .apple_char = '@',
        .empty_char_color = GREEN,
        .border_char_color = GREEN,
        .snake_char_color = YELLOW,
        .apple_char_color = RED,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// Universe model for HELL
struct Model universe_1 = {
        .selftouch = 0,
        .empty_char = ' ',
        .border_char = '@',
        .snake_char = '#',
        .apple_char = '*',
        .empty_char_color = BLACK,
        .border_char_color = RED,
        .snake_char_color = RED,
        .apple_char_color = MAGENTA,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// Universe model for SPACE
struct Model universe_2 = {
        .selftouch = 0,
        .empty_char = ' ',
        .border_char = '!',
        .snake_char = 'H',
        .apple_char = '*',
        .empty_char_color = BLACK,
        .border_char_color = WHITE,
        .snake_char_color = WHITE,
        .apple_char_color = WHITE,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// Universe model for OCEAN
struct Model universe_3 = {
        .selftouch = 0,
        .empty_char = ' ',
        .border_char = '8',
        .snake_char = '=',
        .apple_char = '*',
        .empty_char_color = CYAN,
        .border_char_color = BLUE,
        .snake_char_color = GREEN,
        .apple_char_color = YELLOW,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// Universe model for DESERT
struct Model universe_4 = {
        .selftouch = 0,
        .empty_char = ' ',
        .border_char = '+',
        .snake_char = 'x',
        .apple_char = 'W',
        .empty_char_color = YELLOW,
        .border_char_color = YELLOW,
        .snake_char_color = YELLOW,
        .apple_char_color = YELLOW,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// Universe model for UNDERGROUND
struct Model universe_5 = {
        .selftouch = 0,
        .empty_char = '#',
        .border_char = ' ',
        .snake_char = ' ',
        .apple_char = ' ',
        .empty_char_color = YELLOW,
        .border_char_color = YELLOW,
        .snake_char_color = YELLOW,
        .apple_char_color = YELLOW,
        .horizontal_border_width = 3,
        .vertical_border_width = 6,
};

// This function is for updating universe data for playing
void update_universe_data(struct Model model) {
    active_model.empty_char = model.empty_char;
    active_model.snake_char = model.snake_char;
    active_model.apple_char = model.apple_char;
    active_model.border_char = model.border_char;
    active_model.empty_char_color = model.empty_char_color;
    active_model.snake_char_color = model.snake_char_color;
    active_model.apple_char_color = model.apple_char_color;
    active_model.border_char_color = model.border_char_color;
    active_model.horizontal_border_width = model.horizontal_border_width;
    active_model.vertical_border_width = model.vertical_border_width;
}

// Function which will set universe by index
void set_universe(int universe) {
    switch (universe) {
        case 0:
            update_universe_data(universe_0);
            break;
        case 1:
            update_universe_data(universe_1);
            break;
        case 2:
            update_universe_data(universe_2);
            break;
        case 3:
            update_universe_data(universe_3);
            break;
        case 4:
            update_universe_data(universe_4);
            break;
        case 5:
            update_universe_data(universe_5);
            break;
    }
}



