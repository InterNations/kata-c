NAME = kata

CC      = /usr/bin/gcc
CFLAGS  = -Wall -strict
LDFLAGS = -l$(NAME)

APP_SRC =  src/main.c
APP_OBJ = $(APP_SRC:%.c=%.o)

TEST_SRC = tests/check_library.c
TEST_OBJ = $(TEST_SRC:%.c=%.o)
TEST_CFLAGS = $(CFLAGS) `pkg-config --cflags check`
TEST_LDFLAGS = $(LDFLAGS) `pkg-config --libs check`

LIB_SRC = src/library.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB_NAME = lib$(NAME).dylib
LIB_PATH = '$(CURDIR)/src/$(LIB_NAME)'

OBJ = $(LIB_OBJ) $(APP_OBJ) $(TEST_OBJ)

.PHONY: all check clean

all: kata checks

kata: src/$(LIB_NAME)
	$(CC) $(CFLAGS) $(APP_OBJ) -o $(NAME) -L '$(CURDIR)/src' $(LDFLAGS)

src/$(LIB_NAME): $(OBJ)
	$(CC) -dynamiclib -install_name $(LIB_PATH) -current_version 1.0 $(LIB_OBJ) -o src/$(LIB_NAME)

checks: src/$(LIB_NAME)
	$(CC) $(TEST_CFLAGS) $(TEST_OBJ) -o checks -L '$(CURDIR)/src' $(TEST_LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

tests/%.o: src/%.c
	$(CC) $(TEST_CFLAGS) -c $< -o $(<:%.c=%.)

clean:
	rm -rf $(NAME) $(OBJ) src/$(LIB_NAME) checks

check: all
	./checks
