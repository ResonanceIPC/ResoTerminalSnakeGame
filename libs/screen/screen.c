// Including global libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "screen.h"

// Including local libraries
/* No local libraries imported yet */

int SCREEN_HEIGHT;
int SCREEN_WIDTH;

// Function for setting up terminal sizes
void set_terminal_sizes(void) {
  struct winsize size;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) != -1) {
    SCREEN_HEIGHT = size.ws_row;
    SCREEN_WIDTH = size.ws_col;
  }
  if (SCREEN_WIDTH < 29 || SCREEN_HEIGHT < 15) {
    CLEAR();
    printf("\nSmall       :( ");
    printf("\nTerminal    :( ");
    printf("\nSize        :( ");
    exit(0);
  }
}