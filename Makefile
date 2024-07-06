CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g -O3 -Iinclude/
TARGET_DIR=target/
SRC_DIR=src/

OBJS= main.o
EXE= calc

all: quick

$(EXE): target $(TARGET_DIR)$(OBJS)
	$(CC) $(CFLAGS) $(TARGET_DIR)$(OBJS) -o $(TARGET_DIR)$(EXE)

$(TARGET_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR) \
	rm ./$(EXE)

target:
	mkdir $(TARGET_DIR)

quick: $(EXE)
	cp $(TARGET_DIR)$(EXE) ./$(EXE)
