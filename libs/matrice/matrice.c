// Including global libraries
#include <stdio.h>

// Including local libraries
#include "matrice.h"
#include "../model/model.h"
#include "../apple/apple.h"
#include "../screen/screen.h"

// Declaring gloval variables
int *matrice;
int matrice_array[10000000];

// Function for setting border on the edges of the matrice
void set_edge_borders(int horizontal_width, int vertical_width) {
    for (int i = 0; i < horizontal_width; i++) {
        for (int j = 0; j < active_model.width; j++) {
            matrice[CELL(i, j)] = 1;
        }
    }
    for (int i = 0; i < horizontal_width; i++) {
        for (int j = 0; j < active_model.width; j++) {
            matrice[CELL(active_model.height-horizontal_width+i, j)] = 1;
        }
    }
    for (int i = 0; i < vertical_width; i++) {
        for (int j = 0; j < active_model.height; j++) {
            matrice[CELL(j, i)] = 1;
        }
    } 
    for (int i = 0; i < vertical_width; i++) {
        for (int j = 0; j < active_model.height; j++) {
            matrice[CELL(j, active_model.width-vertical_width+i)] = 1;
        }
    }  
}

// Function for setting up matrice
void setup_matrice(void) {
    matrice = &matrice_array[0];
    for (int y = 0; y < active_model.height; y++){
        for (int x = 0; x < active_model.width; x++){
            matrice[CELL(y, x)] = 0;
        }
    }
    set_edge_borders(active_model.horizontal_border_width, active_model.vertical_border_width);
}

// Function for displaying matrice
void display_matrice(void) {
    CLEAR();
    for (int y = 0; y < active_model.height; y++){
        for (int x = 0; x < active_model.width; x++){
            if (matrice[CELL(y,x)] == 0) {
                SET_FOREGROUND_COLOR(active_model.empty_char_color, 0);
                printf("%c",active_model.empty_char);
            }
            else if (matrice[CELL(y,x)] == 1) {
                SET_FOREGROUND_COLOR(active_model.border_char_color, 1);
                printf("%c",active_model.border_char);
            }
            else if (matrice[CELL(y,x)] == 2) {
                SET_FOREGROUND_COLOR(active_model.snake_char_color, 1);
                printf("%c",active_model.snake_char);
            }
            else if (matrice[CELL(y,x)] == 3) {
                SET_FOREGROUND_COLOR(active_model.apple_char_color, 1);
                printf("%c",active_model.apple_char);
            }
        }
        printf("\n");
    }
}