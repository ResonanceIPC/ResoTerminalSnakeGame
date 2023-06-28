// Including libraries
#include <time.h>
#include <stdio.h>
#include "model.h"
#include "screen.h"
#include "requests.h"
#include <stdlib.h>

// Defining macros for getting neighbours
#define UP_NEIGHBOUR(y, x) matrix[y-1][x] 
#define UP_LEFT_NEIGHBOUR(y, x) matrix[y-1][x-1] 
#define UP_RIGHT_NEIGHBOUR(y, x) matrix[y-1][x+1] 
#define DOWN_NEIGHBOUR(y, x) matrix[y+1][x] 
#define DOWN_LEFT_NEIGHBOUR(y, x) matrix[y+1][x-1] 
#define DOWN_RIGHT_NEIGHBOUR(y, x) matrix[y+1][x+1] 
#define LEFT_NEIGHBOUR(y, x) matrix[y][x-1] 
#define RIGHT_NEIGHBOUR(y, x) matrix[y][x+1]
#define NEIGHBOURS(y,x) \
	+ (y > 0 ? UP_NEIGHBOUR(y,x) : 0) \
	+ (x > 0 ? LEFT_NEIGHBOUR(y,x) : 0) \
       	+ (y < (rows-1) ? DOWN_NEIGHBOUR(y,x) : 0) \
       	+ (x < (columns-1) ? RIGHT_NEIGHBOUR(y,x) : 0) \
	+ (y > 0 && x > 0 ? UP_LEFT_NEIGHBOUR(y,x) : 0) \
	+ (y > 0 && x < (columns-1) ? UP_RIGHT_NEIGHBOUR(y,x) : 0) \
	+ (y < (rows-1) && x > 0 ? DOWN_LEFT_NEIGHBOUR(y,x) : 0) \
	+ (y < (rows-1) && x < (columns-1) ? DOWN_RIGHT_NEIGHBOUR(y,x) : 0) \

// Defining macro for getting cell status (alive or dead)
#define CELL(y, x) matrix[y][x]

/// Variables for saving died and alive symbols
char dead;
char alive;

// Variables for saving died and alive colors
int dead_color;
int alive_color;

// Variables for saving window lenght
unsigned int columns;
unsigned int rows;

// Arrays for saving in which neighbours count must cell survive or born
int born[9] = {};
int survive[9] = {};

// Variable for saving pointer to main matrice
unsigned int ** matrix;

// Function for setting matrice with given length
void setup(Model model) {

	// Setting length and width of matrix
	rows = model.height;
	columns = model.width;
	
	// Setting dead and alive characters
	dead = model.dead_symbol;
	alive = model.alive_symbol;
	
	// Setting dead and alive symbol colors	
	dead_color = model.dead_symbol_color;
	alive_color = model.alive_symbol_color;
	
	// Setting born and survive neighbours count
	for (int i = 0; i < 9; i++){born[i] = model.born_neighbours[i] != 0 ? 1 : 0;};
	for (int i = 0; i < 9; i++){ survive[i] = model.survive_neighbours[i] != 0 ?  1 : 0;};
	
	// Allocating memory for matrix
	matrix = (unsigned int **)malloc(rows * sizeof(unsigned int *));
	for (int i = 0; i < rows; i++) {
  		matrix[i] = (unsigned int *)malloc(columns * sizeof(unsigned int));
	}
	
	
	// Setting pattern of matrice
	
	// Filling with RANDOM pattern
	if (model.pattern == 0) {
	int random_number;
		srand(time(NULL));
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				random_number = rand() % 10000 + 1;
				if (random_number >= model.density){
					matrix[y][x] = 1;
				}
				else {
					matrix[y][x] = 0;
				}
			}
		}
	}
	// Filling with CENTER pattern
	else if (model.pattern == 1) {
					int center_x = (int)(model.width /2);
					int center_y = (int)(model.height /2);
					matrix[center_y][center_x] = 1;
	}
	// Filling with RANDOM pattern
	else if (model.pattern == 2) {
			matrix[0][0] = 1;
			matrix[0][model.width - 1] = 1;
			matrix[model.height - 1][0] = 1;
			matrix[model.height - 1][model.width - 1] = 1;
	}
	// Filling with CHESS pattern
	else if (model.pattern == 3) {
	int chess_index = 1;
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				chess_index = (chess_index == 0) ? 1 : 0;
				matrix[y][x] = chess_index;
			}
		}
	}

	// Patterns for models in game
	else if (model.pattern == 1001) {
		int center_x = (int)(model.width / 2);
		int center_y = (int)(model.height / 2);
		matrix[center_y][center_x] = 1;
		matrix[center_y+1][center_x] = 1;
		matrix[center_y+2][center_x] = 1;
		matrix[center_y][center_x-1] = 1;
		matrix[center_y][center_x-2] = 1;
		matrix[center_y+1][center_x-3] = 1;
		matrix[center_y+2][center_x-4] = 1;
		matrix[center_y+3][center_x-4] = 1;
		matrix[center_y+4][center_x-4] = 1;
		matrix[center_y+4][center_x-3] = 1;
		matrix[center_y+4][center_x-2] = 1;
		matrix[center_y+3][center_x-1] = 1;
	}

	// Patterns for models in game
	else if (model.pattern == 1002) {
		int center_x = (int)(model.width / 2);
		int center_y = (int)(model.height / 2);
		matrix[center_y-1][center_x-2] = 1;
		matrix[center_y-1][center_x-3] = 1;
		matrix[center_y-1][center_x-4] = 1;
		
		matrix[center_y-1][center_x+2] = 1;
		matrix[center_y-1][center_x+3] = 1;
		matrix[center_y-1][center_x+4] = 1;

		matrix[center_y+1][center_x-2] = 1;
		matrix[center_y+1][center_x-3] = 1;
		matrix[center_y+1][center_x-4] = 1;
		
		matrix[center_y+1][center_x+2] = 1;
		matrix[center_y+1][center_x+3] = 1;
		matrix[center_y+1][center_x+4] = 1;

		matrix[center_y+6][center_x-2] = 1;
		matrix[center_y+6][center_x-3] = 1;
		matrix[center_y+6][center_x-4] = 1;
	
		matrix[center_y+6][center_x+2] = 1;
		matrix[center_y+6][center_x+3] = 1;
		matrix[center_y+6][center_x+4] = 1;

		matrix[center_y-2][center_x-6] = 1;
		matrix[center_y-3][center_x-6] = 1;
		matrix[center_y-4][center_x-6] = 1;

		matrix[center_y-2][center_x-1] = 1;
		matrix[center_y-3][center_x-1] = 1;
		matrix[center_y-4][center_x-1] = 1;

		matrix[center_y-2][center_x+1] = 1;
		matrix[center_y-3][center_x+1] = 1;
		matrix[center_y-4][center_x+1] = 1;

		matrix[center_y-2][center_x+6] = 1;
		matrix[center_y-3][center_x+6] = 1;
		matrix[center_y-4][center_x+6] = 1;

		matrix[center_y+2][center_x-1] = 1;
		matrix[center_y+3][center_x-1] = 1;
		matrix[center_y+4][center_x-1] = 1;

		matrix[center_y+2][center_x+1] = 1;
		matrix[center_y+3][center_x+1] = 1;
		matrix[center_y+4][center_x+1] = 1;

		matrix[center_y+2][center_x-6] = 1;
		matrix[center_y+3][center_x-6] = 1;
		matrix[center_y+4][center_x-6] = 1;

		matrix[center_y+2][center_x+6] = 1;
		matrix[center_y+3][center_x+6] = 1;
		matrix[center_y+4][center_x+6] = 1;

		matrix[center_y-6][center_x+2] = 1;
		matrix[center_y-6][center_x+3] = 1;
		matrix[center_y-6][center_x+4] = 1;

		matrix[center_y-6][center_x-2] = 1;
		matrix[center_y-6][center_x-3] = 1;
		matrix[center_y-6][center_x-4] = 1;
	}
}

// Function for displaying matrice
void display_matrice(int clear_screen){
	// Resetting colors
	RESET_COLORS();
	// Clearing screen if needed
	if (clear_screen != 0){
		CLEAR();
	}
	// Looping and printing every character
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			if (matrix[y][x] == 0){
				SET_FOREGROUND_COLOR(dead_color, BRIGHT);
				printf("%c", dead);	
			}
			else if (matrix[y][x] == 1){
				SET_FOREGROUND_COLOR(alive_color, BRIGHT);
				printf("%c", alive);	
			}
		}
			printf("\n");
		
	}
	RESET_COLORS();
}

// Function for updating matrice 
void update_matrice(){
	// Defining variables for saving neighbours data and old matrix
	unsigned int neighbours[rows][columns];
	unsigned int old_matrix[rows][columns];
	unsigned int neighbours_count;
	// Looping and saving neighbours count
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < columns; x++){
		        old_matrix[y][x] = matrix[y][x];	
			neighbours_count = NEIGHBOURS(y, x);
			neighbours[y][x] = neighbours_count;
		}
	}

	// Looping and updating cells
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < columns; x++){
			neighbours_count = neighbours[y][x];
			if (old_matrix[y][x] == 0){
				if (born[neighbours_count] == 1){
					matrix[y][x] = 1;
				}
			}
			else if (old_matrix[y][x] == 1){
				if (survive[neighbours_count] == 0){
					matrix[y][x] = 0;
				}
			}
		}
	}
}
