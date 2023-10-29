LIBS = -lraylib -lGL
INCLUDES = -I/include
LIBFOLDER = -L/usr/local/lib
OUTPUT = ./main
PARAMS = -fdiagnostics-color=always 
FILES = *.cpp

build:
	g++ $(PARAMS) -g $(FILES) -o $(OUTPUT) $(LIBFOLDER) $(LIBS) $(INCLUDES)

run:
	$(OUTPUT)
