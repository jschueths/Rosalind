CC=g++
CFLAGS=-c
LDFLAGS=
EXECUTABLE=infer_mRNA
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@echo Linking: $@

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@
	@echo Compiling: $<

clean:
	rm -rf *.o $(EXECUTABLE)

