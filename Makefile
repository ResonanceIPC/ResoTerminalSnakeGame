CC = gcc
CFLAGS = -w
LIBS = -lm

SRCDIR = .
LIBDIR = libs

SRC_FILES = $(SRCDIR)/game.c $(LIBDIR)/requests.c $(LIBDIR)/defaults.c $(LIBDIR)/matrice.c $(LIBDIR)/powered.c

GameOfLife: $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o GameOfLife $(LIBS)

clean:
	rm -f GameOfLife
