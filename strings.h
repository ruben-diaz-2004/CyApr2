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
#include <map>
#include <set>

class Lenguaje {
  public:
  Lenguaje() { cadenas_.clear(), lenguaje_.clear(); }
  void FileWrite(std::fstream& input_file);
  void PrintLenguajes(std::fstream& output_file);
  void PrintLength(std::fstream& output_file);
  void PrintReverse(std::fstream& output_file);
  void PrintPreffix(std::fstream& output_file);
  void PrintSuffix(std::fstream& output_file);

  private:
  std::map<int, std::string> cadenas_;
  std::map<int, std::set<char>> lenguaje_;
};