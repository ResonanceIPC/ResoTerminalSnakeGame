// Declaring variables for global use
extern int *matrice;

// Declaring functions for global use
void setup_matrice(void);
void display_matrice(void);

// Defining macros or global use
#define CELL(y, x) (((y)*SCREEN_WIDTH) + (x))