CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iinclude

SRCDIR = src
BUILDDIR = bin
TARGET = $(BUILDDIR)/drt

SRCS = $(wildcard $(SRCDIR)/*.cpp) $(wildcard src/models/*.cpp)
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: all
	./$(TARGET)
