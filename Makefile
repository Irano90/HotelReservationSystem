CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC = src/main.cpp src/Kamar.cpp src/Tamu.cpp src/Hotel.cpp src/Reservasi.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = hotel

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)

