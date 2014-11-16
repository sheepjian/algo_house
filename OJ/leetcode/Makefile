CC=g++
CFLAGS=-I. -std=c++11 

SRC=$(wildcard ./*/*.cpp)
#FILES=$(notdir $(SRC))
#OBJS=$(patsubst %.cpp,Obj/%.o,$(FILES) )
BINS=$(patsubst %.cpp,%,$(SRC) )

all: $(BINS)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@



.PHONY: clean

clean: 
	rm -f Obj/*.o Bin/*






