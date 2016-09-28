INCLUDE_DIR=include

CC=gcc
CFLAGS=-I$(INCLUDE_DIR)
DEPS=$(shell find . -name '*.h')

VPATH=src:src/tunnel

TARGET=myexec


all: setup $(TARGET)

setup:
	@mkdir -p build/src/tunnel

.PHONY: setup

info:
	$(info ---------- SRCS ---------)
	$(info $(SRCS))
	$(info ---------- OBJS ---------)
	$(info $(OBJS))

.PHONY: info


$(BUILD_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@ 


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	$(info clean up)
	@find . -name '*.o' | xargs rm -rf
	@rm -rf build
	@mkdir build
	@rm $(TARGET)




.PHONY: clean

