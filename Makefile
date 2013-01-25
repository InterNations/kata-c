NAME = kata

#CC     = gcc
#CFLAGS = -Wall -strict
CC      = clang
CFLAGS  = -g
LDFLAGS = -l$(NAME)

APP_SRC =  src/main.c
APP_OBJ = $(APP_SRC:%.c=%.o)

TEST_NAME = testsuite
TEST_SRC = $(wildcard tests/check_*.c)
TEST_OBJ = $(TEST_SRC:%.c=%.o)
TEST_CFLAGS = $(CFLAGS) `pkg-config --cflags check`
TEST_LDFLAGS = $(LDFLAGS) `pkg-config --libs check`

LIB_SRC = src/library.c src/strmap.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB_NAME = lib$(NAME).dylib
LIB_PATH = '$(CURDIR)/src/$(LIB_NAME)'

OBJ = $(LIB_OBJ) $(APP_OBJ) $(TEST_OBJ)

.PHONY: all check clean

all: $(NAME) $(TEST_NAME)

kata: src/$(LIB_NAME) $(APP_OBJ)
	$(CC) $(CFLAGS) $(APP_OBJ) -o $(NAME) -L '$(CURDIR)/src' $(LDFLAGS)

src/$(LIB_NAME): $(LIB_OBJ)
	$(CC) -dynamiclib -install_name $(LIB_PATH) -current_version 1.0 $(LIB_OBJ) -o src/$(LIB_NAME)

$(TEST_NAME): src/$(LIB_NAME) $(TEST_OBJ)
	$(CC) $(TEST_CFLAGS) $(TEST_OBJ) -o $(TEST_NAME) -L '$(CURDIR)/src' $(TEST_LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

tests/%.o: src/%.c
	$(CC) $(TEST_CFLAGS) -c $< -o $(<:%.c=%.)

clean:
	rm -rf $(NAME) $(OBJ) src/$(LIB_NAME) $(TEST_NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)
