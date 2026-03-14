CC = tcc
CFLAGS = -Wall -g
#CC = gcc
#CFLAGS = -Wall -Wextra
LDFLAGS = 
SRC = src
BIN = bin

SRCS=$(wildcard $(SRC)/*.c)
BINS=$(SRCS:$(SRC)/%.c=%)

all: $(BINS)

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

clean:
	rm -r $(BIN)/*
