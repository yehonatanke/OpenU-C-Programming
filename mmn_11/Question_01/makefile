CC		= gcc
CFLAGS		= -ansi -pedantic -Wall
PROG_NAME	= doll
OBJS		= doll.o
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj
BIN_DIR		= $(BUILD_DIR)/bin
ZIP_NAME	= mmn11.zip

.PHONY:	clean build_env all

all: build_env $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@

doll.o: doll.c
	$(CC) $(CFLAGS) -c doll.c -o $(OBJ_DIR)/doll.o

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