NAME = kata

CC      = /usr/bin/gcc
CFLAGS  = -Wall -strict
LDFLAGS = -l$(NAME)

APP_SRC =  src/main.c
LIB_SRC = src/library.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB_NAME = lib$(NAME).dylib
LIB_PATH = '$(CURDIR)/$(LIB_NAME)'
APP_OBJ = $(APP_SRC:%.c=%.o)
OBJ = $(LIB_OBJ) $(APP_OBJ)

all: library
	$(CC) $(CFLAGS) $(APP_OBJ) -o $(NAME) -L '$(CURDIR)/src' $(LDFLAGS)

library: $(OBJ)
	$(CC) -dynamiclib -install_name $(LIB_PATH) -current_version 1.0 $(LIB_OBJ) -o src/$(LIB_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

.PHONY: clean
clean:
	rm -rf $(NAME) $(OBJ) src/$(LIB_NAME)

.PHONY: check
check:
