CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lSDL2 -lSDL2main

SRCDIR = src
OBJDIR = obj

SOURCES := $(shell find $(SRCDIR) -name "*.cpp")

OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

INCLUDE_PATHS := $(shell find $(SRCDIR) -type d)
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_PATHS))

TARGET = game

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

rebuild: clean all

print:
	echo $(SOURCES)
	echo "-----------------------------"
	echo $(OBJECTS)

.PHONY: all clean rebuild print