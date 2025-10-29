CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
TASKS = task1 task2 task3 task4 task5 task6 task7
all: $(TASKS)
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
.PHONY: clean
clean:
	rm -f $(TASKS)
