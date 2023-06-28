// Including libraries
#include "model.h"
#include "screen.h"
#include "requests.h"

extern Model models;

int * extract_neighbours_from_string(char * neighbours);

void set_default_model(Model *model, int index) {
	if (index == 0) {
		model->height = SCREEN_HEIGHT-2;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '@';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = CYAN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 0;
		model->density = 5000;
		model->speed = 80;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 0;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 1;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 0;
		model->survive_neighbours[6] = 0;
		model->survive_neighbours[7] = 0;
		model->survive_neighbours[8] = 0;
	}
	else if (index == 1) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '0';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = GREEN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 2;
		model->density = 0;
		model->speed = 80;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 1;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 0;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 0;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 1;
		model->survive_neighbours[1] = 1;
		model->survive_neighbours[2] = 1;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 1;
		model->survive_neighbours[5] = 1;
		model->survive_neighbours[6] = 1;
		model->survive_neighbours[7] = 1;
		model->survive_neighbours[8] = 1;
	}
	else if (index == 2) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = MAGENTA;
	    model->dead_symbol_color = BLACK;
		model->pattern = 3;
		model->density = 0;
		model->speed = 80;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 0;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 1;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 0;
		model->survive_neighbours[6] = 0;
		model->survive_neighbours[7] = 0;
		model->survive_neighbours[8] = 0;
	}
	else if (index == 3) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = CYAN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 0;
		model->density = 6;
		model->speed = 60;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 1;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 1;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 1;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 1;
		model->survive_neighbours[2] = 0;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 1;
		model->survive_neighbours[6] = 0;
		model->survive_neighbours[7] = 1;
		model->survive_neighbours[8] = 0;
	}
	else if (index == 4) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = CYAN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 0;
		model->density = 10;
		model->speed = 99;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 1;
		model->born_neighbours[6] = 1;
		model->born_neighbours[7] = 1;
		model->born_neighbours[8] = 1;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 0;
		model->survive_neighbours[3] = 0;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 1;
		model->survive_neighbours[6] = 1;
		model->survive_neighbours[7] = 1;
		model->survive_neighbours[8] = 1;
	}
	else if (index == 5) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = '.';
	    model->alive_symbol_color = YELLOW;
	    model->dead_symbol_color = BLACK;
		model->pattern = 0;
		model->density = 10;
		model->speed = 75;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 1;
		model->born_neighbours[7] = 1;
		model->born_neighbours[8] = 1;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 0;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 1;
		model->survive_neighbours[5] = 0;
		model->survive_neighbours[6] = 1;
		model->survive_neighbours[7] = 1;
		model->survive_neighbours[8] = 1;
	}

	// Models
	else if (index == 1001) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = GREEN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 1001;
		model->density = 0;
		model->speed = 90;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 0;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 1;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 0;
		model->survive_neighbours[6] = 0;
		model->survive_neighbours[7] = 0;
		model->survive_neighbours[8] = 0;
	}
	else if (index == 1002) {
		model->height = SCREEN_HEIGHT;
		model->width = SCREEN_WIDTH;
	    model->alive_symbol = '#';
	    model->dead_symbol = ' ';
	    model->alive_symbol_color = GREEN;
	    model->dead_symbol_color = BLACK;
		model->pattern = 1002;
		model->density = 0;
		model->speed = 80;
		model->born_neighbours[0] = 0;
		model->born_neighbours[1] = 0;
		model->born_neighbours[2] = 0;
		model->born_neighbours[3] = 1;
		model->born_neighbours[4] = 0;
		model->born_neighbours[5] = 0;
		model->born_neighbours[6] = 0;
		model->born_neighbours[7] = 0;
		model->born_neighbours[8] = 0;
		model->survive_neighbours[0] = 0;
		model->survive_neighbours[1] = 0;
		model->survive_neighbours[2] = 1;
		model->survive_neighbours[3] = 1;
		model->survive_neighbours[4] = 0;
		model->survive_neighbours[5] = 0;
		model->survive_neighbours[6] = 0;
		model->survive_neighbours[7] = 0;
		model->survive_neighbours[8] = 0;
	}
}
