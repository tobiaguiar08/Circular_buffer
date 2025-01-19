include flags.make

PROJECT_NAME=circular_buffer

BIN_DIR=./bin
SRC_DIR=./src
INCLUDE_DIR=./include
TEST_DIR=./test

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
INC_DIRS=-I$(INCLUDE_DIR)

TARGET=$(PROJECT_NAME)$(TARGET_EXTENSION)

all : test default

default: create_bin 
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o $(BIN_DIR)/$(TARGET)
	- $(BIN_DIR)/$(TARGET)

create_bin:
	$(MKDIR) $(BIN_DIR)

test:
	$(MAKE) -C $(TEST_DIR)

clean:
	$(CLEANUP) $(BIN_DIR)/*$(TARGET_EXTENSION)
	rm -r $(BIN_DIR)
	$(MAKE) -C $(TEST_DIR) clean

.PHONY: default clean test
 