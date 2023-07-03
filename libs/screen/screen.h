

// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Defining CLEAR  macros for linux and windows
#ifdef _WIN32
	#define CLEAR() system("cls")
#else 
	#define CLEAR() system("clear")
#endif

#define NEW_LINE printf("\n")

// Defining pattern for POWERED_BY pattern and function for displaying it
#define POWERED_BY_PATTERN   \
"                         @@@@@@@@@@@@@@@@\n" \
"                      @@@@@@@@@@@@@@@@@@@@@@@\n" \
"                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"         @@@@@@@@@@@                              @@@@@@@@\n"  \
"       @@@@@@@@@@@@@@@@@@@@@@@                       @@@@@@\n"  \
"      @@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@@@\n"  \
"     @@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@@     @@@@@@@\n"  \
"    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@@     &@@@@@@\n"  \
"    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@@@@@\n"  \
"   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@        @@@@@@@@@@\n"  \
"   @@@@@@@@@@                                    @@@@@@@@@@@@@@\n"  \
"   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@     @@@@@@@@@@@@@@@@@\n"  \
"   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@     @@@@@@@@@@@@@@@\n"  \
"   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@      @@@@@@@@@@@@\n"  \
"    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@     @@@@@@@@@@@\n"  \
"    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@      @@@@@@@@\n"  \
"     @@@@                          @@@@@@@@@@@@@@@      @@@@@@\n"  \
"     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"           @@@@@@@@@@@@@ R E S O N A N C E @@@@@@@@@@@@@@\n"  \
"             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"  \
"                      @@@@@@@@@@@@@@@@@@@@@@@\n"  \
"                           @@@@@@@@@@@@@@\n" 

#define DISPLAY_POWERED_BY_PATTERN() printf(POWERED_BY_PATTERN)


// Defining colors for printing and macros for displaying given color

//Defining BRIGHT and DARK color codes
#define DARK 0
#define BRIGHT 1

// Defining color codes
#define RESET          0
#define BLACK         30
#define RED           31
#define GREEN         32
#define YELLOW        33
#define BLUE          34
#define MAGENTA       35
#define CYAN          36
#define WHITE         37

// Defining macros for working with colors
#ifdef _WIN32
	#define SET_BACKGROUND_COLOR(color) printf("")
	#define SET_FOREGROUND_COLOR(color, brightness) printf("")
	#define RESET_COLORS() printf("")
#else 
	#define SET_BACKGROUND_COLOR(color) printf("\033[%im", color+10)
	#define SET_FOREGROUND_COLOR(color, brightness) printf("\033[%i;%im", brightness, color)
	#define RESET_COLORS() printf("\033[%im", RESET) 
#endif

// Defining macro for freezing screen
#define FREEZE(s) usleep(s);

// Defining extern variables and functions
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
void set_terminal_sizes(void);
