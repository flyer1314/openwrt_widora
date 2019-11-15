SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CC = mipsel-openwrt-linux-gcc
CFLAG = -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^ $(CFLAG)

clean:
	$(RM) a.out .*.*.sw? $(BIN)

.PHONY:clean all
