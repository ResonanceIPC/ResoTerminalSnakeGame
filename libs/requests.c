// Including libraries
#include <stdio.h>
#include "screen.h"
#include "model.h"
#include "powered.h"
#include <sys/ioctl.h>
#include <unistd.h>

int SCREEN_HEIGHT;
int SCREEN_WIDTH;

extern Model models;

char patterns_names[10][30] = {"RANDOM", "CENTER", "CORNERS", "CHESS"};
char colors_names[10][30] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE"};

void set_terminal_sizes(void) {
    struct winsize size;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) != -1) {
        SCREEN_HEIGHT = size.ws_row;
        SCREEN_WIDTH = size.ws_col;
    }
}

// Function which will extract neighbours count from string given by user
int * extract_neighbours_from_string(char neighbours[]) {
	int i = 0;
	int index;
	int * neighbours_pointer;
	int neighbours_indexes[9] = {};
	// Looping and defining in which neighbour count will something happen (born or survive)
	while (neighbours[i] != '\0'){
		if (neighbours[i]  >= '0' && neighbours[i] <= '8'){
			index = ((int) neighbours[i]) - 48;
			neighbours_indexes[index] = 1;
		}
		i++;
	}
	// Assigning array to pointer and returning
	neighbours_pointer = &neighbours_indexes;
	return neighbours_pointer;
}

// Main function for getting height from user
int request_height(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║         Enter height       ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int height = 0;
    scanf("%i", &height);
    RESET_COLORS();
    return height;
}

// Main function for getting pattern from user
int request_pattern(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║        Enter Pattern       ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  RANDOM - 0  |  CENTER - 1 ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  CORNERS - 2 |  CHESS - 3  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int pattern = 0;
    scanf("%i", &pattern);
    RESET_COLORS();
    return pattern;
}

// Main function for getting width from user
int request_width(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║         Enter width        ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int width = 0;
    scanf("%i", &width);
    RESET_COLORS();
    return width;
}

// Main function for getting density from user
int request_density(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║         Enter densiy       ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  (number from 0 to 10000)  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║      (higher -> denser)    ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int density = 0;
    scanf("%i", &density);
    RESET_COLORS();
    return density;
}

// Main function for getting speed from user
int request_speed(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║         Enter speed        ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   (number from 0 to 100)   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║      (higher -> faster)    ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int speed = 0;
    scanf("%i", &speed);
    RESET_COLORS();
    return speed;
}

// Main function for getting alive symbol from user
char request_alive_symbol(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   Enter alive cell symbol  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    char symbol;
    scanf("%c", &symbol);
    RESET_COLORS();
    return symbol;
}

// Main function for getting dead symbol from user
char request_dead_symbol(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   Enter dead cell symbol   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    char symbol;
    scanf("%c", &symbol);
    RESET_COLORS();
    return symbol;
}

// Main function for getting alive cell color from user
int request_alive_color(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   Enter alive cell color   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  BLACK  - 1 | RED     - 2  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int color = 0;
    scanf("%i", &color);
    RESET_COLORS();
    return color;
}

// Main function for getting dead cell color from user
int request_dead_color(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║    Enter dead cell color   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  BLACK  - 1 | RED     - 2  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  GREEN  - 3 | YELLOW  - 4  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  BLUE   - 5 | MAGENTA - 6  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  CYAN   - 7 | WHITE   - 8  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    int color = 0;
    scanf("%i", &color);
    RESET_COLORS();
    return color;
}

// Main function for getting born neighbours
char ** request_born_neighbours(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   Enter neighbours count   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║ when a new cell must born  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║          (like 23)         ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    char neighbours[9];
    scanf("%s", &neighbours);
    RESET_COLORS();
    char ** neighbours_pointer = &neighbours;
    return neighbours_pointer;
}


// Main function for getting survive neighbours
char ** request_survive_neighbours(void) {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║   Enter neighbours count   ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║  when a cell must survive  ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║          (like 23)         ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    // Getting result from user, resetting color and resetting colors
    char neighbours[9];
    scanf("%s", &neighbours);
    RESET_COLORS();
    char ** neighbours_pointer = &neighbours;
    return neighbours_pointer;
}

// Function for displaying menu where user can edit values of model
int get_option_to_edit(Model model){
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(CYAN, BRIGHT);
    for(int i = 0; i < (SCREEN_HEIGHT - 14) / 2; i++){printf("\n");}
    for (int i = 0; i < (SCREEN_WIDTH - 24) / 2;i++){printf("=");};
    printf("  Enter option to edit  ");
    for (int i = 0; i < (SCREEN_WIDTH - 24) / 2;i++){printf("=");};
    printf("\n\n");
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("0. Back\n");

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};    
    printf("1. Change height");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%29i\n", model.height);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    
    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("2. Change width", model.width);
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%30i\n", model.width);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("3. Change alive symbol");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%23c\n", model.alive_symbol);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("4. Change dead symbol");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%22c\n", model.dead_symbol);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("5. Change alive cell color");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%19s\n", colors_names[model.alive_symbol_color - 30]);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("6. Change dead cell color");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%20s\n", colors_names[model.dead_symbol_color - 30]);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("7. Change born rules");
    int neighbours_working_count = 0;
    for (int i = 0; i < 7; i ++){if(model.born_neighbours[i] == 1) {neighbours_working_count++;};}
    // printf("+ %i +", neighbours_working_count);
    for (int i = 0; i < 25 - neighbours_working_count; i ++){printf(" ");}
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    for (int i = 0; i < 9; i ++){if (model.born_neighbours[i] != 0) {printf("%i", i);};}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    printf("\n");

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("8. Change survive rules");
    neighbours_working_count = 0;
    for (int i = 0; i < 7; i ++){if(model.survive_neighbours[i] == 1) {neighbours_working_count++;};}
    for (int i = 0; i < 22 - neighbours_working_count; i ++){printf(" ");}
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    for (int i = 0; i < 9; i ++){if (model.survive_neighbours[i] != 0) {printf("%i", i);};}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    printf("\n");

    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("9. Change pattern");
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%28s\n", patterns_names[model.pattern]);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);

    if (model.pattern == 0) {
        for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
        printf("    91. Change RANDOM pattern density");
        SET_FOREGROUND_COLOR(RED, BRIGHT);
        printf("%8i\n", model.density);
        SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    }

    // Printing speed option
    for (int i = 0; i < (SCREEN_WIDTH - 40) / 2;i++){printf(" ");};
    printf("10. Change speed", model.speed);
    SET_FOREGROUND_COLOR(RED, BRIGHT);
    printf("%29i\n", model.speed);
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    printf("\n");

    SET_FOREGROUND_COLOR(CYAN, BRIGHT);
    for (int i = 0; i < (SCREEN_WIDTH);i++){printf("=");};
    for (int i = 0; i < (SCREEN_WIDTH) / 2;i++){printf(" ");};
    SET_FOREGROUND_COLOR(RED, BRIGHT);

    int option;
    scanf("%i", &option);
    RESET_COLORS();
    return option;
}

// Function for main menu
int display_main_menu() {
    	// Clearing screen and setting foreground color
    	CLEAR();
    	SET_FOREGROUND_COLOR(CYAN, BRIGHT);
    	for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
	    for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
	    printf("╔════════════════════════╗\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║        Menu            ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("╠════════════════════════╣\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║ 1. Start               ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║ 2. Exit                ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║ 3. Help                ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║ 4. Change parameters   ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("║ 5. Set default models  ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 26) / 2;i++){printf(" ");};
        printf("╚════════════════════════╝\n");	
    	for (int i = 0; i < (SCREEN_WIDTH) / 2;i++){printf(" ");};
	SET_FOREGROUND_COLOR(RED, BRIGHT);
    	int option;
    	scanf("%i", &option);
    	RESET_COLORS();
    	return option;
}

// Function for displaying start RESONANCE animation
void display_start_animation(int width, int height) {
	CLEAR();
	SET_FOREGROUND_COLOR(GREEN, BRIGHT);
	display_powered_by_pattern(width, height);
	FREEZE(500000);
	CLEAR();
	SET_FOREGROUND_COLOR(CYAN, BRIGHT);
	display_powered_by_pattern(width, height);
	FREEZE(210000);
	CLEAR();
	SET_FOREGROUND_COLOR(GREEN, BRIGHT);
	display_powered_by_pattern(width, height);
	FREEZE(500000);
}

// Function for main menu
int display_default_models_menu() {
    	// Clearing screen and setting foreground color
    	CLEAR();
    	SET_FOREGROUND_COLOR(CYAN, BRIGHT);
    	for(int i = 0; i < (SCREEN_HEIGHT - 8) / 2; i++){printf("\n");}
	    for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
	    printf("╔════════════════════════════════════════════════════════╗\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║                      Default models                    ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("╠════════════════════════════════════════════════════════╣\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      0. - STANDARD                                     ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║           1001 - REPLICATOR MODEL                      ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║           1002 - PULSAR                                ║\n");
        for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║                                                        ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      1. - LIFE WITHOUT DEATH                           ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      2. - GENERATOR                                    ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      3. - REPLICATOR                                   ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      4. - CELL                                         ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("║      5. - Day and night                                ║\n");
    	for (int i = 0; i < (SCREEN_WIDTH - 58) / 2;i++){printf(" ");};
        printf("╚════════════════════════════════════════════════════════╝\n");	
    	for (int i = 0; i < (SCREEN_WIDTH) / 2;i++){printf(" ");};
	    SET_FOREGROUND_COLOR(RED, BRIGHT);
    	int option;
    	scanf("%i", &option);
    	RESET_COLORS();
    	return option;
}

// Display help request
void display_help() {
    // Clearing screen and setting foreground color
    CLEAR();
    SET_FOREGROUND_COLOR(YELLOW, BRIGHT);
    // Printing data what we want from user
    for(int i = 0; i < (SCREEN_HEIGHT - 3) / 2; i++){printf("\n");}
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╔════════════════════════════╗\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║     Open README.md file    ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║                            ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("║         (0 to exit)        ║\n");
    for(int i = 0; i < (SCREEN_WIDTH - 28) / 2; i++){printf(" ");}
    printf("╚════════════════════════════╝\n");
    printf("\n");
    for(int i = 0; i < (SCREEN_WIDTH) / 2; i++){printf(" ");}
    SET_FOREGROUND_COLOR(GREEN, BRIGHT);
    while (1) {
        // Check if the enter key is pressed
        if (getchar() == '0') {
            break;  // Exit the loop
        }
    }
    RESET_COLORS();
}