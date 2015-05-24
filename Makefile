NAME = test
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix bin/,$(notdir $(CPP_FILES:.cpp=.o)))
RM = rm -f
CXXFLAGS = -Iinclude -Wall -Werror

debug: CXXFLAGS += -DDEBUG

all: $(OBJ_FILES)
	g++ -std=c++11 -g  $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

debug: all

bin/%.o: src/%.cpp
	g++ -std=c++11 $(CXXFLAGS) -g -c -o $@ $<
clean:
	-$(RM) bin/*~
	-$(RM) bin/\#*
	-$(RM) bin/*.o
	-$(RM) bin/*.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

rebug: fclean debug all
