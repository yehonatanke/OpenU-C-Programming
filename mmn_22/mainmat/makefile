CC			= gcc
CFLAGS		= -ansi -pedantic -Wall
PROG_NAME	= mainmat
OBJS		= mainmat.o error_utility.o mymat.o tables_utility.o utility.o process_input.o
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj
BIN_DIR		= $(BUILD_DIR)/bin
ZIP_NAME	= mmn22.zip

.PHONY:	clean build_env all

all: build_env $(PROG_NAME)


$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@

mainmat.o: mainmat.c mainmat.h utility.h globals.h mymat.h \
  process_input.h message_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

error_utility.o: error_utility.c error_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

mymat.o: mymat.c utility.h globals.h mymat.h constants.h \
  message_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

tables_utility.o: tables_utility.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

utility.o: utility.c utility.h globals.h mymat.h error_utility.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

process_input.o: process_input.c process_input.h utility.h globals.h \
  mymat.h constants.h error_utility.h message_utility.h
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
