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
  CheckCorrectParameters(argc, argv, 3);

  std::fstream input_file{argv[1]};
  std::fstream output_file{argv[2]};
  
  Lenguaje lenguaje;
  lenguaje.FileWrite(input_file);
  lenguaje.PrintLenguajes(output_file);
  lenguaje.PrintLength(output_file);
  lenguaje.PrintReverse(output_file);
  lenguaje.PrintPreffix(output_file);
  lenguaje.PrintSuffix(output_file);

  return 0;
}