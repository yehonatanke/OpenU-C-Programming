CC			= gcc
CFLAGS		= -ansi -pedantic -Wall
PROG_NAME	= get_name
OBJS		= get_name.o get_name_util.o
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj
BIN_DIR		= $(BUILD_DIR)/bin
ZIP_NAME	= mmn12.zip

.PHONY:	clean build_env all

all: build_env $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@

get_name.o: get_name.c constants.h get_name_util.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

get_name_util.o: get_name_util.c get_name_util.h constants.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

%.o:
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)

build_env:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

zip: clean
	rm -f $(ZIP_NAME)
	zip -r $(ZIP_NAME) *
#####
#CC          = gcc
#CFLAGS      = -ansi -pedantic -Wall
#PROG_NAME   = get_name
#OBJS        = get_name.o get_name_util.o
#BUILD_DIR   = build
#OBJ_DIR     = $(BUILD_DIR)/obj
#BIN_DIR     = $(BUILD_DIR)/bin
#ZIP_NAME    = mmn12.zip
#
#.PHONY: clean build_env all
#
#all: build_env $(PROG_NAME)
#
#$(PROG_NAME): $(OBJS)
#	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@
#
#get_name.o: get_name.c constants.h get_name_util.h
#	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@
#
#get_name_util.o: get_name_util.c get_name_util.h constants.h
#	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@
#
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@
#
#clean:
#	rm -rf $(BUILD_DIR)
#
#build_env:
#	mkdir -p $(BUILD_DIR)
#	mkdir -p $(BIN_DIR)
#	mkdir -p $(OBJ_DIR)
#
#zip: clean
#	rm -f $(ZIP_NAME)
#	zip -r $(ZIP_NAME) *
