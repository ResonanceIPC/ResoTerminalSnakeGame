// Including global libraries
#include <stdio.h>

// Including local libraries
#include "../apple/apple.h"
#include "../joystick/joystick.h"
#include "../matrice/matrice.h"
#include "../model/model.h"
#include "../screen/screen.h"

// Declaring variables for snake
int head_x;
int head_y;
int length = 0;
int direction = 2;
int apple_touched = 0;
int coordinates[100000][2] = {};

// Function which adds snake to matrice for printing
void add_snake_to_matrice() {
  for (int i = 0; i < length; i++) {
    matrice[CELL(coordinates[i][0], coordinates[i][1])] = 2;
  }
}

// Function which removes snake from matrice for printing
void remove_snake_from_matrice() {
  for (int i = 0; i < length; i++) {
    matrice[CELL(coordinates[i][0], coordinates[i][1])] = 0;
  }
}

// This function does base setup for snake like giving a start coodinates
void setup_snake() {
  length = 3;
  direction = RIGHT;
  head_y = (int)((active_model.height) / 2);
  head_x = (int)((active_model.width) / 2) + 2;
  coordinates[0][0] = head_y;
  coordinates[0][1] = head_x - 2;
  coordinates[1][0] = head_y;
  coordinates[1][1] = head_x - 1;
  coordinates[2][0] = head_y;
  coordinates[2][1] = head_x;
  add_snake_to_matrice();
}

// Function for checking if it touches itself or no
int check_selftouch(int y, int x) {
  for (int i = 0; i < length; i++) {
    if (y == coordinates[i][0] && x == coordinates[i][1]) {
      return 1;
    }
  }
  return 0;
}

// Gets direction of snake and makes next step for snake
int do_step() {
  remove_snake_from_matrice();
  switch (direction) {
  case DOWN:
    head_y++;
    break;
  case UP:
    head_y--;
    break;
  case LEFT:
    head_x--;
    break;
  case RIGHT:
    head_x++;
    break;
  }
  if (active_model.selftouch == 1) {
    if (check_selftouch(head_y, head_x) == 1) {
      return 1;
    }
  }
  if (apple_touched) {
    length++;
    apple_touched = 0;
  } else {
    for (int i = 1; i < (length); i++) {
      coordinates[i - 1][0] = coordinates[i][0];
      coordinates[i - 1][1] = coordinates[i][1];
    }
  }
  coordinates[length - 1][0] = head_y;
  coordinates[length - 1][1] = head_x;
  // Check for apple touch
  if (matrice[CELL(head_y, head_x)] == 3) {
    points++;
    apple_touched = 1;
    generate_apple();
  } else if (matrice[CELL(head_y, head_x)] != 0) {
    return 1;
  }
  add_snake_to_matrice();
  return 0;
}

// Function for changing direction of snake
void change_direction(int new_direction) {
  switch (new_direction) {
  case DOWN:
    if (direction != UP && direction != DOWN) {
      direction = DOWN;
    }
    break;
  case UP:
    if (direction != UP && direction != DOWN) {
      direction = UP;
    }
    break;
  case LEFT:
    if (direction != LEFT && direction != RIGHT) {
      direction = LEFT;
    }
    break;
  case RIGHT:
    if (direction != LEFT && direction != RIGHT) {
      direction = RIGHT;
    }
    break;
  }
}