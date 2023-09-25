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

/**
 * Clase Lenguaje que almacena las cadenas de entrada
 * y produce sus respectivos lenguajes para después 
 * operar tanto con las cadenas crudas como con los lenguajes
*/
class Lenguaje {
  public:
  Lenguaje() { cadenas_.clear(), lenguaje_.clear(); }
  void FileWrite(std::ifstream& input_file);
  void PrintLenguajes(std::ofstream& output_file);
  void PrintLength(std::ofstream& output_file);
  void PrintReverse(std::ofstream& output_file);
  void PrintPreffix(std::ofstream& output_file);
  void PrintSuffix(std::ofstream& output_file);

  private:
  std::map<int, std::string> cadenas_;
  std::map<int, std::set<char>> lenguaje_;
};