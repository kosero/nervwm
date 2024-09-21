CC = gcc
CFLAGS = -I/usr/include/wlroots-0.19 -I/usr/include/pixman-1 -I./include -DWLR_USE_UNSTABLE
LDFLAGS = -lpixman-1 -lwlroots-0.19 -lwayland-server

SRC = src/server.c src/output.c
OBJ = $(SRC:.c=.o)
TARGET = nervwm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean
