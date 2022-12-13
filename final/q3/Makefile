EXES += $(basename $(shell ls *.c))
LIBS += # some libs here

%: %.c
	gcc $< $(LIBS) -o $@

all: $(EXES)

clean: rm $(EXES)

.PHONY: all clean
