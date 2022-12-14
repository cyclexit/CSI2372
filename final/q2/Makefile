EXES += $(basename $(shell ls *.cpp))
LIBS += # some libs here

%: %.cpp
	g++ $< $(LIBS) -o $@ -std=c++11

all: $(EXES)

clean: rm $(EXES)

.PHONY: all clean
