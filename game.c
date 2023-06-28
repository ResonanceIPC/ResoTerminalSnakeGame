// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include "libs/screen.h"
#include "libs/defaults.h"
#include "libs/patterns.h"
#include "libs/model.h"
#include "libs/requests.h"

// Declaring functions
int main(void);

// Declaring functions
void update_matrice();
void display_matrice(int clear_screen);
void setup(Model model);

void set_default_model(Model *model, int index);
int * extract_neighbours_from_string(char * neighbours);
void set_terminal_sizes(void);


extern Model models;
extern Model default_models[10];

int ask_choice = 1;

// Main function from which everything starts
int main(void){
	// Setting terminal size
	set_terminal_sizes();

	// Defining neighbours count during which new cell will born
	int * born_symbols_pointer = extract_neighbours_from_string("3\0");
	//int * born_symbols_pointer = extract_neighbours_from_string("1\0");
	int born_symbols[9] = {};
	for (int i = 0; i < 9; i++){born_symbols[i] = born_symbols_pointer[i];};	

	// Defining neighbours count during which if cell is alive, it will survive
	int * survive_symbols_pointer = extract_neighbours_from_string("23\0");
	//int * survive_symbols_pointer = extract_neighbours_from_string("012345678\0");
	int survive_symbols[9] = {};
	for (int i = 0; i < 9; i++){survive_symbols[i] = survive_symbols_pointer[i];};

	// Defining active model which will be used from the start
	Model active = {};
	set_default_model(&active, STANDARD);	

	// Setting all parameters for starting
	setup(active);

	// Displaying start resonance animation
	display_start_animation(active.width, active.height);
	
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
			display_help();
			choice = -1;
			edit_choice = -1;
		}
		if (choice == 5) {
			int model =  display_default_models_menu();
			set_default_model(&active, model);
		}
		if (choice == 4 || !ask_choice) {
			ask_choice = 0;
			
			while (!(edit_choice >= 0 && edit_choice <= 8)) {
				edit_choice = get_option_to_edit(active);
			       	if (edit_choice == 0) {
					ask_choice = 1;
					choice = -1;
					edit_choice = -1;
					break;
				}	
				else if (edit_choice == 1){
					int height;
					height = request_height();
					active.height = height;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 2){
					int width;
					width = request_width();
					active.width = width;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 3){
					char alive = request_alive_symbol();
					scanf("%c", &alive);
					active.alive_symbol = alive;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 4){
					char dead = request_dead_symbol();
					scanf("%c", &dead);
					active.dead_symbol = dead;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 5){
					int color;
					color = request_alive_color();
					active.alive_symbol_color = color + 29;
					choice = -1;
	
					edit_choice = -1;
					break;
				}

				else if (edit_choice == 6){
					int color;
					color = request_dead_color();
					active.dead_symbol_color = color + 29;
					choice = -1;
	
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 7) {
					char * requested_born_neighbours = request_born_neighbours();
					char neighbours_array[20];
					for (int i = 0; i < 20; i++) {neighbours_array[i] = requested_born_neighbours[i];}
					int * born_symbols_pointer = extract_neighbours_from_string(neighbours_array);
					int born_symbols[9] = {};
					for (int i = 0; i < 9; i++) {born_symbols[i] = born_symbols_pointer[i];}
					for (int i = 0; i < 9; i++){
						active.born_neighbours[i] = born_symbols[i];
					}
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 8) {
					char * requested_survive_neighbours = request_survive_neighbours();
					char neighbours_array[20];
					for (int i = 0; i < 20; i++) {neighbours_array[i] = requested_survive_neighbours[i];}
					int * survive_symbols_pointer = extract_neighbours_from_string(neighbours_array);
					int survive_symbols[9] = {};
					for (int i = 0; i < 9; i++) {survive_symbols[i] = survive_symbols_pointer[i];}
					for (int i = 0; i < 9; i++){
						active.survive_neighbours[i] = survive_symbols[i];
					}
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 9){
					int pattern;
					pattern = request_pattern();
					active.pattern = pattern;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 91 && active.pattern == 0){
					int density;
					density = request_density();
					active.density = density;
					choice = -1;
					edit_choice = -1;
					break;
				}
				else if (edit_choice == 10){
					int speed;
					speed = request_speed();
					active.speed = speed;
					choice = -1;
					edit_choice = -1;
					break;
				}
			}	
		}
		if (choice == 1) {
			setup(active);
			while (1) {
				CLEAR();	
				display_matrice(0);
				FREEZE(500000 - 5000*active.speed);
				#ifdef DEBUG
					int j; scanf("%i", &j);
				#endif
				update_matrice();
			}	
		}
		
	}
	return 0;
}
