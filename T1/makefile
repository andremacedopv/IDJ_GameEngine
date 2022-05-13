IDIR =./include
CC=g++ -std=c++11
CFLAGS=-I$(IDIR) -Wpedantic -Wall -g

ODIR=obj

SDIR=src

LIBS=-lm -lSDL2 -lSDL2_image -lSDL2_mixer

_DEPS = Game.h Music.h SDL_include.h Sprite.h State.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Game.o Music.o Sprite.o State.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: game

$(ODIR)/%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(ODIR)/main.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ game *.o