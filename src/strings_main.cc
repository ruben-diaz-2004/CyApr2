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
  CheckCorrectParameters(argc, argv, 4);

  std::ifstream input_file{argv[1]};
  std::ofstream output_file{argv[2]};
  output_file.clear();
  
  int opcode = std::stoi(argv[3]);
  Lenguaje lenguaje;
  lenguaje.FileWrite(input_file);

  switch (opcode) {
  case 1:
//  lenguaje.PrintLenguajes(output_file);
  output_file << lenguaje;
    break;
  case 2:
  lenguaje.PrintLength(output_file);
    break;
  case 3:
  lenguaje.PrintReverse(output_file);
    break;
  case 4:
  lenguaje.PrintPreffix(output_file);
    break;
  case 5:
  lenguaje.PrintSuffix(output_file);
    break;
  default:
  std::cerr << "Error al leer el opcode\n";
    break;
  }

  return 0;
}