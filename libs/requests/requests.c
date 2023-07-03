// Including global libraries
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

// Including local libraries
#include "../matrice/matrice.h"
#include "../model/model.h"
#include "../powered/powered.h"
#include "../screen/screen.h"

// Defining color names
char colors_names[10][30] = {"BLACK", "RED",     "GREEN", "YELLOW",
                             "BLUE",  "MAGENTA", "CYAN",  "WHITE"};

// Main function for getting height from user
int request_height(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║         Enter height       ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int height = 0;
  scanf("%i", &height);
  RESET_COLORS();
  return height;
}

// Main function for getting width from user
int request_width(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║         Enter width        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int width = 0;
  scanf("%i", &width);
  RESET_COLORS();
  return width;
}

// Main function for getting speed from user
int request_speed(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║         Enter speed        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║   (number from 0 to 100)   ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║      (higher -> faster)    ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int speed = 0;
  scanf("%i", &speed);
  RESET_COLORS();
  return speed;
}

// Main function for getting alive symbol from user
char request_empty_symbol(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║      Enter empty symbol    ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  char symbol;
  scanf("%c", &symbol);
  RESET_COLORS();
  return symbol;
}

// Main function for getting alive symbol from user
char request_border_symbol(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║     Enter border symbol    ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  char symbol;
  scanf("%c", &symbol);
  RESET_COLORS();
  return symbol;
}

// Main function for getting alive symbol from user
char request_snake_symbol(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║      Enter snake symbol    ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  char symbol;
  scanf("%c", &symbol);
  RESET_COLORS();
  return symbol;
}

// Main function for getting alive symbol from user
char request_apple_symbol(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║      Enter apple symbol    ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  char symbol;
  scanf("%c", &symbol);
  RESET_COLORS();
  return symbol;
}

// Main function for getting dead cell color from user
int request_empty_symbol_color(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  Enter empty symbol color  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║                            ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLACK  - 1 | RED     - 2  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int color = 0;
  scanf("%i", &color);
  RESET_COLORS();
  return color;
}

// Main function for getting dead cell color from user
int request_border_symbol_color(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  Enter border symbol color ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║                            ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLACK  - 1 | RED     - 2  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int color = 0;
  scanf("%i", &color);
  RESET_COLORS();
  return color;
}

// Main function for getting dead cell color from user
int request_snake_symbol_color(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  Enter snake symbol color  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║                            ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLACK  - 1 | RED     - 2  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int color = 0;
  scanf("%i", &color);
  RESET_COLORS();
  return color;
}

// Main function for getting dead cell color from user
int request_apple_symbol_color(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
  // Printing data what we want from user
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╔════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  Enter apple symbol color  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║                            ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLACK  - 1 | RED     - 2  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++) {
    printf(" ");
  }
  printf("╚════════════════════════════╝\n");
  printf("\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  }
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  // Getting result from user, resetting color and resetting colors
  int color = 0;
  scanf("%i", &color);
  RESET_COLORS();
  return color;
}

// Function for displaying menu where user can edit values of model
int get_option_to_edit(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  for (int i = 0; i < (SCREEN_HEIGHT - 14) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 24) / 2; i++) {
    printf("=");
  };
  printf("  Enter option to edit  ");
  for (int i = 0; i < (SCREEN_WIDTH - 24) / 2; i++) {
    printf("=");
  };
  printf("\n\n");
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("0. Back\n");

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("1. Change height");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%29i\n", active_model.height);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("2. Change width", active_model.width);
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%30i\n", active_model.width);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  // Printing speed option
  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("3. Change speed", active_model.speed);
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%30i\n", active_model.speed);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("4. Change empty symbol");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%23c\n", active_model.empty_char);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("5. Change border symbol");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%22c\n", active_model.border_char);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("6. Change snake symbol");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%23c\n", active_model.snake_char);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("7. Change apple symbol");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%23c\n", active_model.apple_char);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("8. Change empty symbol color");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%17s\n", colors_names[active_model.empty_char_color - 30]);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("9. Change border symbol color");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%16s\n", colors_names[active_model.border_char_color - 30]);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("10. Change snake symbol color");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%16s\n", colors_names[active_model.snake_char_color - 30]);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("11. Change apple symbol color");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%16s\n", colors_names[active_model.apple_char_color - 30]);
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  for (int i = 0; i < (SCREEN_WIDTH - 40) / 2; i++) {
    printf(" ");
  };
  printf("12. Turn selftouch on or off");
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  printf("%17s\n", active_model.selftouch == 0 ? "OFF" : "ON");
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);

  printf("\n");

  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  for (int i = 0; i < (SCREEN_WIDTH); i++) {
    printf("=");
  };
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(RED, BRIGHT);

  int option;
  scanf("%i", &option);
  RESET_COLORS();
  return option;
}

// Function for main menu
int display_main_menu(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("╔════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║        Menu            ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("╠════════════════════════╣\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║ 1. Start               ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║ 2. Exit                ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║ 3. Help                ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║ 4. Change parameters   ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("║ 5. Set universe        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 26) / 2; i++) {
    printf(" ");
  };
  printf("╚════════════════════════╝\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  int option;
  scanf("%i", &option);
  RESET_COLORS();
  return option;
}

// Function for displaying start RESONANCE animation
void display_start_animation(void) {
  CLEAR();
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  display_powered_by_pattern();
  FREEZE(500000);
  CLEAR();
  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  display_powered_by_pattern();
  FREEZE(210000);
  CLEAR();
  SET_FOREGROUND_COLOR(GREEN, BRIGHT);
  display_powered_by_pattern();
  FREEZE(500000);
}

// Function for main menu
int display_universes_menu(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╔════════════════════════════════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║                         Universes                      ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╠════════════════════════════════════════════════════════╣\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      0. - Field                                        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      1. - Hell                                         ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      2. - Space                                        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      3. - Ocean                                        ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      4. - Desert                                       ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║      5. - Underground                                  ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╚════════════════════════════════════════════════════════╝\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  int option;
  scanf("%i", &option);
  RESET_COLORS();
  return option;
}

// Function for requesting selftouch parameter
int request_selftouch(void) {
  // Clearing screen and setting foreground color
  CLEAR();
  SET_FOREGROUND_COLOR(CYAN, BRIGHT);
  for (int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++) {
    printf("\n");
  }
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╔════════════════════════════════════════════════════════╗\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║                  Die when touching itself              ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╠════════════════════════════════════════════════════════╣\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("║              ON - 1      |       OFF - 0               ║\n");
  for (int i = 0; i < (SCREEN_WIDTH - 58) / 2; i++) {
    printf(" ");
  };
  printf("╚════════════════════════════════════════════════════════╝\n");
  for (int i = 0; i < (SCREEN_WIDTH) / 2; i++) {
    printf(" ");
  };
  SET_FOREGROUND_COLOR(RED, BRIGHT);
  int option;
  scanf("%i", &option);
  RESET_COLORS();
  return option;
}