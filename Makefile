# שמות הקבצים
TARGET = squaremat
TEST_TARGET = tests

# קבצי קוד
SRCS = main.cpp SquareMat.cpp
TEST_SRCS = tests.cpp SquareMat.cpp

# הגדרות קומפילציה
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# הפקודה: make Main
Main: $(TARGET)
	./$(TARGET)

# קומפילציה של squaremat
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# הפקודה: make test
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# קומפילציה של tests
$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET)

# הפקודה: make valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# הפקודה: make clean
clean:
	rm -f $(TARGET) $(TEST_TARGET)




# TARGET = squaremat
# TEST_TARGET = tests

# SRCS = main.cpp SquareMat.cpp
# TEST_SRCS = tests.cpp SquareMat.cpp

# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -g

# all: $(TARGET)

# $(TARGET): $(SRCS)
# 	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# test: $(TEST_TARGET)
# 	./$(TEST_TARGET)

# $(TEST_TARGET): $(TEST_SRCS)
# 	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET)

# valgrind: $(TARGET)
# 	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# clean:
# 	rm -f $(TARGET) $(TEST_TARGET)
