CC = g++
CFLAGS = -c -Wall -Wextra

SOURCES = source
OBJECTS = build/main.o build/in_out.o build/solve.o build/tester.o build/utilities.o

EXECUTABLE = ss
BUILD_DIR = build

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SOURCES)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf build/ ss
