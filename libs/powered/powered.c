// Including global libraries
#include <stdio.h>

// Including local libraries
#include "../screen/screen.h"

// Function for prining powered by pattern
void display_powered_by_pattern() {
  int height = SCREEN_HEIGHT;
  int width = SCREEN_WIDTH;
  // Printing powered by pattern when terminal size is maximum
  if (SCREEN_HEIGHT >= 30 && SCREEN_WIDTH >= 64) {
    for (int i = 0; i < (height / 2) - 15; i++) {
      printf("\n");
    }
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                         @@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                      @@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("         @@@@@@@@@@@                              @@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("       @@@@@@@@@@@@@@@@@@@@@@@                       @@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("     @@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@@     @@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@@     &@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@        @@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@                                    @@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf(
        "   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@     @@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf(
        "   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@     @@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@      @@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@     @@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@@@      @@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("     @@@@                          @@@@@@@@@@@@@@@      @@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("           @@@@@@@@@@@@@ R E S O N A N C E @@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                      @@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 32; i++) {
      printf(" ");
    }
    printf("                           @@@@@@@@@@@@@@\n");
  } 
  // Printing pattern when terminal size is medium
  else if (SCREEN_HEIGHT >= 20 && SCREEN_WIDTH >= 50) {
    CLEAR();
    for (int i = 0; i < (height / 2) - 10; i++) {
      printf("\n");
    }
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("                   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("             @@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("          @@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("        @@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("      @@@@@@@                   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@    @@@@@@@    @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@@@@@@@    @@@@@@@@@   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@@@@@@@    @@@@@@@@@   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("  @@@@@@@                        @@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("  @@@@@@@@@@@@@@@@@    @@@@   @@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("  @@@@@@@@@@@@@@@@@    @@@@@    @@@@@@@@@ \n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("   @@@@@@@@@@@@@@@@    @@@@@@@   @@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("   @@@                 @@@@@@@@@   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("        @@@@ R E S O N A N C E @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("          @@@@@@@@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("             @@@@@@@@@@@@@@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
    printf("                   @@@@@\n");
    for (int i = 0; i < (width / 2) - 20; i++) {
      printf(" ");
    }
  }
  // Printing powered by pattern for very small sizes of terminal
  else {
    CLEAR();
    for (int i = 0; i < (height / 2) - 1; i++) {
      printf("\n");
    }
    for (int i = 0; i < (width / 2) - 8; i++) {
      printf(" ");
    }
    printf("R E S O N A N C E\n");
  }
}