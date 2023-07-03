// Including global libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Including local libraries
#include "../matrice/matrice.h"
#include "../model/model.h"
#include "../screen/screen.h"

// Declaring variables for global use
int apple_y;
int apple_x;
int points = 3;

// Function for resetting points
void reset_points(void) {
  points = 3;
}

// Function for generating
void generate_apple(void) {
  srand(time(0));
  int random_x = 0;
  int random_y = 0;
  do {
    random_y = (rand() % (active_model.height - active_model.horizontal_border_width ) ) + active_model.horizontal_border_width;
    random_x = (rand() % (active_model.width - active_model.vertical_border_width ) ) + active_model.vertical_border_width;
  } while (matrice[CELL(random_y, random_x)] != 0);
  matrice[CELL(random_y, random_x)] = 3;
  apple_y = random_y;
  apple_x = random_x;
}

// Function for checking that apple must be seen
void show_apple(void) {
  matrice[CELL(apple_y, apple_x)] = 3;
}