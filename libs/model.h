// Including libraries
#include <stdio.h>

// Defining data type for game model
typedef struct game_model {
	unsigned int height;
	unsigned int width;
	char alive_symbol;
	char dead_symbol;
	int alive_symbol_color;
	int dead_symbol_color;
	int * born_neighbours[9];
	int * survive_neighbours[9];
	int pattern;
	int density;
	int speed;
} Model;


