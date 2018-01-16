BIN = homerojump.exe
ICO = obj/icon.res
OBJ = obj/main.o obj/var.o obj/input.o obj/player.o obj/map.o $(ICO)
LIB = -lSDL2 -lSDL2_image -llibsdl2main -lgame
INC = -iquoteinclude

w32   = -m32
C++11 = -std=c++11
WINDOWS = -mwindows

CFLAGS = $(C++11) $(INC) $(w32)
LFLAGS = $(LIB) $(WINDOWS)
WRFLAGS  = -O coff

WINDRES = windres
GCC = $(mingw32)g++
RM  = rm -f -v
CP  = cp -v
MKDIR = mkdir -v


compile: $(BIN)

run: $(BIN)
	./$(BIN)

clear:
	$(RM) $(BIN) $(OBJ)

$(BIN): $(OBJ)
	$(GCC) -o $(BIN) $(OBJ) $(LFLAGS)

obj/player.o: include/player.h

obj/%.o: src/%.cpp include/game.h
	$(GCC) -c -o obj/$*.o src/$*.cpp $(CFLAGS)

obj/%.res: rec/%.rc
	$(WINDRES) -o obj/$*.res -i rec/$*.rc $(WRFLAGS)
