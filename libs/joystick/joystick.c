// Including global libraries
#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

// Including local libraries
#include "joystick.h"

int last_key = -100;

// Function for detecting key press
int get_key_pressed() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);  // Set non-blocking input
    int key = getch();
    endwin();
    if (key == ERR){
        return -1;
    }
    // Arrow key detecting (FUCK they come with three following chars! :( )
    if (key == 0x1B){
        key = getch();
        if (key == 0x5b){
            key=getch();
        }
    }
    // Switch for detecting joystick keypresses
    switch (key) {
        case 'w':
        case 'i':
        case 0x41:
            if (last_key == UP){return get_key_pressed();};
            last_key = UP;
            return UP;
            break;
        case 's':
        case 'k':
        case 0x42:
            if (last_key == DOWN){return get_key_pressed();};
            last_key = DOWN;
            return DOWN;
            break;
        case 'd':
        case 'l':
        case 0x43:
            if (last_key == RIGHT){return get_key_pressed();};
            last_key = RIGHT;
            return RIGHT;
            break;
        case 'a':
        case 'j':
        case 0x44:
            if (last_key == LEFT){return get_key_pressed();};
            last_key = LEFT;
            return LEFT;
            break;
        case 'q':
            return QUIT;
            break;
    }
    endwin();
    return -1;
}