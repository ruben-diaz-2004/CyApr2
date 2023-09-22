/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  * @brief Este programa lee ficheros de texto que contienen especificaciones de
  * cadenas junto con sus respectivos alfabetos. Y es capaz de realizar varias 
  * comprobaciones básicas sobre ellas
  */

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "strings.h"


int main(int argc, char *argv[]) {
  CheckCorrectParameters(argc, argv, 2);

  std::fstream input_file{argv[1]};
  
  Lenguaje lenguaje;
  lenguaje.FileWrite(input_file);
  lenguaje.PrintLenguajes();
  lenguaje.PrintLength();
  lenguaje.PrintReverse();
  
  return 0;
}