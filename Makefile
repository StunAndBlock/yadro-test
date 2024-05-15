.PHONY: all clean debug prep release rebuild

SRC_DIR		= src
BUILD_DIR	= build
OBJ_DIR		= obj
NAME		= test.exe

DBG_DIR			= debug
DBG_PATH		= $(BUILD_DIR)/$(DBG_DIR)
DBG_OBJ_PATH	= $(OBJ_DIR)/$(DBG_DIR)
DBG_EXE			= $(DBG_PATH)/$(NAME)
DBG_CPPFLAGS	= -g -DDEBUG


RELEASE_DIR			= release
RELEASE_PATH		= $(BUILD_DIR)/$(RELEASE_DIR)
RELEASE_OBJ_PATH	= $(OBJ_DIR)/$(RELEASE_DIR)
RELEASE_EXE			= $(RELEASE_PATH)/$(NAME)
RELEASE_CPPFLAGS	= -DNDEBUG

CC			= g++
CPPFLAGS	= -Wall


MAIN_M			=main.cpp
MAIN_O			=main.o
CLUBCOLLECTOR_M =ClubCollector.cpp ClubCollector.hpp
CLUBCOLLECTOR_O =ClubCollector.o
CORE_M			=Core.cpp Core.hpp CoreData.hpp
CORE_O			=Core.o
PARSER_M		=Parser.cpp Parser.hpp
PARSER_O		=Parser.o
ERRORHANDLER_M  = ErrorHandler.cpp ErrorHandler.hpp
ERRORHANDLER_O  = ErrorHandler.o
TMEXTENSION_M  = TmExtension.cpp TmExtension.hpp
TMEXTENSION_O  = TmExtension.o



SRC_FILES = $(addprefix $(SRC_DIR)/,$(MAIN_M) $(CLUBCOLLECTOR_M) $(CORE_M) $(PARSER_M) $(ERRORHANDLER_M) $(TMEXTENSION_M))

OBJS = $(MAIN_O) $(CLUBCOLLECTOR_O) $(CORE_O) $(PARSER_O) $(ERRORHANDLER_O) $(TMEXTENSION_O)
DBG_OBJS = $(addprefix $(DBG_OBJ_PATH)/,$(OBJS))
RELEASE_OBJS = $(addprefix $(RELEASE_OBJ_PATH)/,$(OBJS))


all: release

debug: prep $(DBG_EXE)

$(DBG_EXE): $(DBG_OBJS)
	$(CC) $^ $(CPPFLAGS) $(DBG_CPPFLAGS) -o $@

$(DBG_OBJS): $(SRC_FILES)
	$(CC) -c $(@:$(DBG_OBJ_PATH)%.o=$(SRC_DIR)%.cpp) $(CPPFLAGS) $(DBG_CPPFLAGS) -o $@

release: prep $(RELEASE_EXE)

$(RELEASE_EXE): $(RELEASE_OBJS)
	$(CC) $^ $(CPPFLAGS) $(RELEASE_CPPFLAGS) -o $@

$(RELEASE_OBJS): $(SRC_FILES)
	$(CC) -c $(@:$(RELEASE_OBJ_PATH)%.o=$(SRC_DIR)%.cpp) $(CPPFLAGS) $(RELEASE_CPPFLAGS) -o $@




prep:
	@mkdir -p $(DBG_PATH) $(DBG_OBJ_PATH) $(RELEASE_PATH) $(RELEASE_OBJ_PATH)

rebuild: clean all

clean:
	rm -rf $(RELEASE_EXE) $(DBG_EXE) $(OBJ_DIR)
