// Including global libraries
#include <stdio.h>

// Including local libraries
#include "libs/apple/apple.h"
#include "libs/defaults/defaults.h"
#include "libs/joystick/joystick.h"
#include "libs/matrice/matrice.h"
#include "libs/model/model.h"
#include "libs/requests/requests.h"
#include "libs/screen/screen.h"
#include "libs/snake/snake.h"

// Declaring variables for working with loops
int ask_choice = 1;

// Function for settuping base objects
void base_setup() {
  setup_matrice();
  setup_snake();
  reset_points();
  generate_apple();
}

// Function for printing game over animation
int display_game_over_animation() {
  SET_FOREGROUND_COLOR(RED, 1);
  for (int i = 0; i < SCREEN_HEIGHT / 2 - 7; i++) {
    printf("\n");
  };
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf("┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n");
  printf("\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(GREEN, 1);
  printf("            Points - %4i          \n\n", points);
  SET_FOREGROUND_COLOR(YELLOW, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 18; i++) {
    printf(" ");
  };
  printf(" [New Game] - 1     |    [Quit] - 2 \n");
  printf("\n\n");
  for (int i = 0; i < SCREEN_WIDTH / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(MAGENTA, 1);
  int value;
  scanf("%i", &value);
  return value;
}

// Function for printing help data
int display_help_data() {
  CLEAR();
  SET_FOREGROUND_COLOR(GREEN, 1);
  for (int i = 0; i < SCREEN_HEIGHT / 2 - 11; i++) {
    printf("\n");
  };

  SET_FOREGROUND_COLOR(YELLOW, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 10; i++) {
    printf(" ");
  };
  printf("Configurations\n\n");
  SET_FOREGROUND_COLOR(GREEN, 1);

  SET_FOREGROUND_COLOR(BLUE, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("Snake Game is a classic arcade game where the player controls a "
         "snake   \n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("that moves around the screen, eating food to grow longer. The "
         "objective \n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("is to guide the snake without colliding with the walls or its own "
         "body. \n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("As the snake grows, the game becomes more challenging. The game ends "
         "if. \n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("the snake collides. The goal is to achieve the highest score by "
         "consuming \n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("as much food as possible. It requires quick reflexes and strategic "
         "thinking.\n\n");
  SET_FOREGROUND_COLOR(GREEN, 1);

  SET_FOREGROUND_COLOR(YELLOW, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 5; i++) {
    printf(" ");
  };
  printf("[CONTROLS]\n");
  SET_FOREGROUND_COLOR(GREEN, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf(
      ". "
      "-------------------------------------------------------------------.\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| [Esc] [F1][F2][F3][F4][F5][F6][F7][F8][F9][F0][F10][F11][F12] o o "
         "o|\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("|                                                                    "
         "|\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| [`][1][2][3][4][5][6][7][8][9][0][-][=][_<_] [I][H][U] "
         "[N][/][*][-]|\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| "
         "[|-][Q][\033[31;1mW\033[32;1m][E][R][T][Y][U][\033[31;1mI\033[32;1m]["
         "O][P][{][}] | | [D][E][D] [7][8][9]|+||\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| "
         "[CAP][\033[31;1mA\033[32;1m][\033[31;1mS\033[32;1m][\033[31;1mD\033["
         "32;1m][F][G][H][\033[31;1mJ\033[32;1m][\033[31;1mK\033[32;1m][\033["
         "31;1mL\033[32;1m][;]['][#]|_|           [4][5][6]|_||\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| [^][\\][Z][X][C][V][B][N][M][,][.][/][__^__]     "
         "[\033[31;1m^\033[32;1m]    [1][2][3]| ||\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("| [c]   [a][________________________][a]   [c] "
         "[\033[31;1m<\033[32;1m][\033[31;1mV\033[32;1m][\033[31;1m>\033[32;1m]"
         " [ 0  ][.]|_||\n");
  for (int i = 0; i < SCREEN_WIDTH / 2 - 35; i++) {
    printf(" ");
  };
  printf("`--------------------------------------------------------------------"
         "'\n");

  SET_FOREGROUND_COLOR(YELLOW, 1);
  for (int i = 0; i < SCREEN_WIDTH / 2 - 8; i++) {
    printf(" ");
  };
  printf("0 - to [BACK].\n\n");

  for (int i = 0; i < SCREEN_WIDTH / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(MAGENTA, 1);
  int value;
  scanf("%i", &value);
  return value;
}

// Function for printing player achievments in game (mainly points)
void show_game_data() {
  // Printing new line with full background color
  SET_BACKGROUND_COLOR(active_model.border_char_color);
  for (int i = 0; i < active_model.width; i++) {
    printf(" ");
  }
  RESET_COLORS();

  NEW_LINE;

  // Printing a half of new line with full background color
  SET_BACKGROUND_COLOR(active_model.border_char_color);
  for (int i = 0; i < (active_model.width - 14) / 2; i++) {
    printf(" ");
  }
  RESET_COLORS();

  // Function for displaying points
  SET_FOREGROUND_COLOR(WHITE, 1);
  printf(" Points:   ");
  SET_FOREGROUND_COLOR(WHITE, 1);
  printf("%-3i", points);

  // Printing a half of new line with full background color
  SET_BACKGROUND_COLOR(active_model.border_char_color);
  for (int i = 0; i < (active_model.width - 13) / 2; i++) {
    printf(" ");
  }
  RESET_COLORS();

  // Printing new line with full background color
  SET_BACKGROUND_COLOR(active_model.border_char_color);
  for (int i = 0; i < (active_model.width); i++) {
    printf(" ");
  }
  RESET_COLORS();

  NEW_LINE;
}

// Main function from which the game starts
int main(void) {
  // Setting up terminal sizes
  set_terminal_sizes();
  set_default_active_model();
  set_universe(0);
  base_setup();
  display_start_animation(SCREEN_HEIGHT, SCREEN_WIDTH);
  int feedback = 0;
  int a = 0;

  // Displaying main menu for asking what to do
  int choice = -1;
  int edit_choice = -1;
  while (!(choice >= 0 && choice <= 4)) {
    if (ask_choice) {
      choice = display_main_menu();
    }
    if (choice == 2) {
      exit(0);
    }
    if (choice == 3) {
      display_help_data();
      choice = -1;
      edit_choice = -1;
    }
    if (choice == 5) {
      int universe = display_universes_menu();
      set_universe(universe);
      base_setup();
    }
    if (choice == 4 || !ask_choice) {
      ask_choice = 0;
      while (!(edit_choice >= 0 && edit_choice <= 8)) {
        edit_choice = get_option_to_edit();
        if (edit_choice == 0) {
          ask_choice = 1;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 1) {
          int height;
          height = request_height();
          active_model.height = height;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 2) {
          int width;
          width = request_width();
          active_model.width = width;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 3) {
          int speed;
          speed = request_speed();
          active_model.speed = speed;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 4) {
          char empty = request_empty_symbol();
          scanf("%c", &empty);
          active_model.empty_char = empty;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 5) {
          char border = request_border_symbol();
          scanf("%c", &border);
          active_model.border_char = border;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 6) {
          char snake = request_snake_symbol();
          scanf("%c", &snake);
          active_model.snake_char = snake;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 7) {
          char apple = request_apple_symbol();
          scanf("%c", &apple);
          active_model.apple_char = apple;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 8) {
          int color;
          color = request_empty_symbol_color();
          active_model.empty_char_color = color + 29;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 9) {
          int color;
          color = request_border_symbol_color();
          active_model.border_char_color = color + 29;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 10) {
          int color;
          color = request_snake_symbol_color();
          active_model.snake_char_color = color + 29;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 11) {
          int color;
          color = request_apple_symbol_color();
          active_model.apple_char_color = color + 29;
          choice = -1;
          edit_choice = -1;
          break;
        } else if (edit_choice == 12) {
          int selftouch;
          selftouch = request_selftouch();
          active_model.selftouch = selftouch;
          choice = -1;
          edit_choice = -1;
          break;
        }
      }
      base_setup();
    }
    if (choice == 1) {
      int feedback = 0;
      while (!feedback) {

        // Clearing and displating new matrice with game data
        CLEAR();
        display_matrice();
        show_game_data();

        // Showing apple
        show_apple();

        // Freezing for few milliseconds for changing speed
        FREEZE(500000 - 5000 * active_model.speed);

        // Doing step
        feedback = do_step();

        // Detecting keypresses
        int key = get_key_pressed();
        if (key == UP || key == DOWN || key == LEFT || key == RIGHT) {
          change_direction(key);
        }
        if (key == QUIT) {
          choice = -1;
          edit_choice = -1;
          base_setup();
          break;
        }
      }
      CLEAR();
      SET_FOREGROUND_COLOR(GREEN, 1);
      int game_over_feedback = display_game_over_animation();
      if (game_over_feedback == 1) {
        choice = -1;
        edit_choice = -1;
        base_setup();
      } else {
        exit(0);
      }
    }
  }
  return 0;
}
