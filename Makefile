CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g -O3 -Iinclude/
TARGET_DIR=target/
SRC_DIR=src/

OBJ_FILES= main.o expression.o
OBJS=$(addprefix $(TARGET_DIR), $(OBJ_FILES))
EXE= calc

all: quick

$(EXE): target $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET_DIR)$(EXE)

$(TARGET_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR) \
	rm ./$(EXE)

target:
	mkdir $(TARGET_DIR)

quick: $(EXE)
	cp $(TARGET_DIR)$(EXE) ./$(EXE)
