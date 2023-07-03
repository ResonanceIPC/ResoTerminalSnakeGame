// Including global libraries
#include <stdio.h>

// Including local libraries
#include "../screen/screen.h"

// This is struct of Model for saving game data like width, height, symbols and
// colors
struct Model {
  int height;
  int width;
  int speed;
  char empty_char;
  char border_char;
  char snake_char;
  char apple_char;
  int empty_char_color;
  int border_char_color;
  int snake_char_color;
  int apple_char_color;
  int horizontal_border_width;
  int vertical_border_width;
  int selftouch;
};

// Makig active model
struct Model active_model = {};

// Function for setting up default active model
void set_default_active_model() {
  active_model.width = SCREEN_WIDTH;
  active_model.height = SCREEN_HEIGHT - 4;
  active_model.speed = 60;
  active_model.apple_char = 'T';
  active_model.empty_char = '.';
  active_model.border_char = '#';
  active_model.snake_char = '@';
  active_model.apple_char_color = RED;
  active_model.empty_char_color = MAGENTA;
  active_model.border_char_color = CYAN;
  active_model.snake_char_color = GREEN;
  active_model.vertical_border_width = 4;
  active_model.horizontal_border_width = 4;
  active_model.selftouch = 0;
}