# MACROS DEFINITION

# PROJECT PROPERTIES
FILES = .\src\main.cpp .\src\SdlManager.cpp
CUSTOM_HEADERS_PATH = .\include

# COMPILER PROPERTIES
COMPILER = g++ -std=c++11
FLAGS = -w
LIB_PATHS = -LC:\Dev\Libraries\SDL2-2.0.3\i686-w64-mingw32\lib
LIB_NAMES = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
INCLUDES = -IC:\Dev\Libraries\SDL2-2.0.3\i686-w64-mingw32\include\SDL2 -I$(CUSTOM_HEADERS_PATH)
OUTPUT = .\bin\out.exe

# COMMANDS

all: compile run

compile: $(FILES)
	$(COMPILER) $(FILES) $(INCLUDES) $(LIB_PATHS) $(FLAGS) $(LIB_NAMES) -o $(OUTPUT)
	
run: $(OUTPUT)
	$(OUTPUT)