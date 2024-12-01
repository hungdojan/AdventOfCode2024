CXX=g++
CXXFLAGS=-std=c++11

# update variables below
SRC_FILE= # dayX.cpp
INPUT_FILE= # ./input.txt

all: ./task

run: ./task
	./task < $(INPUT_FILE)
# run: script.py
# 	python script.py < input.txt

./task: $(SRC_FILE)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f ./task
