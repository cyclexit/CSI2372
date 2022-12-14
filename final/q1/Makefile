EXES += $(basename $(shell ls *.c))
LIBS += # some libs here

%: %.cpp
	g++ $< $(LIBS) -o $@ -std=c++11

all: $(EXES)

clean: rm $(EXES)

.PHONY: all clean
