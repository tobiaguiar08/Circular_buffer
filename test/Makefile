# =========================================================================
#   Unity - A Test Framework for C
#   ThrowTheSwitch.org
#   Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
#   SPDX-License-Identifier: MIT
# =========================================================================

include ../flags.make

UNITY_ROOT=./unity
SRC_DIR=../src
INCLUDE_DIR=../include


TARGET_BASE1=test1
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1= ./test_buffer_node.c $(UNITY_ROOT)/unity.c $(SRC_DIR)/buffer_node.c
INC_DIRS=-I$(UNITY_ROOT) -I$(INCLUDE_DIR)
SYMBOLS=

all: default clean

default: $(SRC_FILES1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1)

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default