CC=g++
CFLAGS=-c
LDFLAGS=
EXECUTABLE=counting_point_mutations
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

