all:
SRC_DIR		= src
BUILD_DIR	= build
NAME		= test.exe

DBG_DIR			= debug
DBG_PATH		= $(BUILD_DIR)/$(DBG_DIR)	
DBG_EXE			= $(DBG_PATH)/$(NAME)
DBG_CPPFLAGS	= -g -DDEBUG

RELEASE_DIR			= release
RELEASE_PATH		= $(BUILD_DIR)/$(RELEASE_DIR)
RELEASE_EXE			= $(RELEASE_PATH)/$(NAME)
RELEASE_CPPFLAGS	= -DNDEBUG


CC			= g++
CPPFLAGS	= -Wall -Werror -Wextra


CLUBCOLLECTOR_M = Clubcollector.cpp Clubcollector.hpp
CORE_M			= Core.cpp Core.hpp
PARSER_M		= Parser.cpp Parser.hpp

SRCFILES = $(CLUBCOLLECTOR_M) $(CORE_M) $(PARSERMODULE) 

debug:




release:

