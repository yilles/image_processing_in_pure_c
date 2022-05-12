EXECUTABLE_NAME = main
DIR_SRC = src
DIR_INCLUDE = include
DIR_BIN = bin
DIR_INTERMEDIATE = obj
SRC_FILES = $(DIR_SRC)/main.c \
            $(DIR_SRC)/img_process.c

# Build application(Default)
build:
	@echo Build...
	gcc -o $(DIR_BIN)/$(EXECUTABLE_NAME) -I$(DIR_INCLUDE) $(SRC_FILES)

# Build debug application
debug:
	@echo Build debug version...
	gcc -o $(DIR_BIN)/$(EXECUTABLE_NAME) -DDEBUG -I$(DIR_INCLUDE) $(SRC_FILES)

run:
	@echo Run...
	./bin/main

## Create output directories
#create:
#echo Create...
#if not exist $(DIR_BIN) mkdir $(DIR_BIN)
#if not exist $(DIR_INTERMEDIATE) mkdir $(DIR_INTERMEDIATE)
#
## Delete output files
#clean:
#echo Clean...
#if exist $(DIR_BIN)\*.exe del $(DIR_BIN)\*.exe
#if exist $(DIR_INTERMEDIATE)\*.obj del /S /Q $(DIR_INTERMEDIATE)\*.obj
#
## Create directories and build application
#all: clean create build
