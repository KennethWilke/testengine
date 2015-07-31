CC=gcc -Wall
CC_OBJ=$(CC) -c -o $@
CC_BIN=$(CC) -o $@ $(LIBRARIES)
OBJECTS=build/main.o build/window.o build/event.o build/drawing.o build/shaders.o
LIBRARIES=-lSDL2 -lGL -lGLU

all: bin/ build/ bin/test


bin/test: $(OBJECTS)
	$(CC_BIN) $(OBJECTS)


build/main.o: src/main.c src/main.h
	$(CC_OBJ) src/main.c

build/window.o: src/window.c src/window.h
	$(CC_OBJ) src/window.c

build/event.o: src/event.c src/event.h
	$(CC_OBJ) src/event.c

build/drawing.o: src/drawing.c src/drawing.h
	$(CC_OBJ) src/drawing.c

build/shaders.o: src/shaders.c src/shaders.h
	$(CC_OBJ) src/shaders.c

bin/:
	@ mkdir -v $@

build/:
	@ mkdir -v $@

clean:
	@ rm -rv build/ bin/
