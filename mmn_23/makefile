CC			= gcc
CFLAGS		= -ansi -pedantic -Wall
PROG_NAME	= index
OBJS		= index.o error_utility.o utility.o hash_utility.o
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj
BIN_DIR		= $(BUILD_DIR)/bin
ZIP_NAME	= mmn23.zip

.PHONY:	clean build_env all

all: build_env $(PROG_NAME)


$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@

index.o: index.c index.h globals.h utility.h error_utility.h constants.h \
  hash_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

utility.o: utility.c utility.h globals.h constants.h error_utility.h \
  hash_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

hash_utility.o: hash_utility.c hash_utility.h globals.h utility.h \
  constants.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

error_utility.o: error_utility.c error_utility.h
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
