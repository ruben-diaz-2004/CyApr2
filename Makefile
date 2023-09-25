# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# 
# @author Rubén Díaz Marrero
# @date 25/09/2023
# 

CXX = g++
CXXFLAGS = -Wall -std=c++17 -g 



all: p02_strings

p02_strings: src/strings_main.cc src/strings.cc 
		$(CXX) $(CXXFLAGS) -o $@ $^
	
#multiple_grades_main.o: src/multiple_grades_main.cc
#		$(CXX) $(CXXFLAGS) -c $^

#multiple_grades.o: src/multiple_grades.cc
#		$(CXX) $(CXXFLAGS) -c $^
	
.PHONY: all clean
clean:
		rm -f src/*.o
		rm -f p02_strings