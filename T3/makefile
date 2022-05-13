IDIR =./include
CC=g++ -std=c++11
CFLAGS=-I$(IDIR) -Wpedantic -Wall -g

ODIR=obj

SDIR=src

LIBS=-lm -lSDL2 -lSDL2_image -lSDL2_mixer

_DEPS = Game.h Resources.h TileSet.h TileMap.h Sound.h Face.h Music.h GameObject.h Component.h Vec2.h Rect.h SDL_include.h Sprite.h State.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Game.o Sound.o Resources.o TileSet.o TileMap.o Face.o GameObject.o Component.o Vec2.o Rect.o Music.o Sprite.o State.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: game

$(ODIR)/%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(ODIR)/main.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ game *.o