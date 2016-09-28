INCLUDE_DIR=include
SOURCE_DIR=src
BUILD_DIR=build

CC=gcc
CFLAGS=-I$(INCLUDE_DIR)
DEPS=$(shell find . -name '*.h')
SRCS= $(wildcard *.c) $(wildcard $(SOURCE_DIR)/**/*.c) 
#SRCS=$(shell find . -name '*.c')

OBJS=$(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

TARGET=mylib

.PHONY: setup

all: setup info $(TARGET)

setup:
	mkdir -p build/src/tunnel

info:
	$(info ---------- src ----------)
	$(info $(SRCS))
	$(info ---------------------OBJ)
	$(info $(OBJS))

.PHONY: info


$(BUILD_DIR)/%.o: %.c $(DEPS)
	echo "$@"
	$(CC) -c $< $(CFLAGS) -o $@ 


$(TARGET): $(OBJS)
	@echo "$^"
	$(CC) $(CFLAGS) $^ -o $@


clean:
	find . -name '*.o' | xargs rm -rf
	rm -rf build
	mkdir build
	rm $(TARGET)




.PHONY: clean

