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
#include <algorithm>

#include "strings.h"

/**
 * Método que recoge el fichero de entrada y contruye dos std::map en los que almacena 
 * tanto la cadena cruda, como los alfabetos de los que provienen
 * @param input_file. El archivo de entrada
*/
void Lenguaje::FileWrite(std::fstream& input_file) {
  std::string cadena_de_entrada{""};
  int localizador{0};

  while (std::getline(input_file, cadena_de_entrada)) {
    // Almacenamos la cadena primero
    cadenas_[localizador] = cadena_de_entrada;          

    // Calculamos y almacenamos el lenguaje del que proviene
    std::set<char> aux_lenguaje;
    for (char caracter: cadena_de_entrada) {
      aux_lenguaje.insert(caracter);
    }
    lenguaje_[localizador] = aux_lenguaje;

    ++localizador;
  }
}

void Lenguaje::PrintLenguajes() {
  bool first_character = true;
  for (const auto& entrada : lenguaje_) {
    const std::set<char>& lenguaje = entrada.second;
    std::cout << "{";
    for (char caracter: lenguaje) {
      if (first_character) {
        std::cout << caracter;
        first_character = false;
      } else { std::cout << ", " << caracter; }
    }
    std::cout << "}" << std::endl;
    first_character = true;
  }
}


void Lenguaje::PrintLength() {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    std::cout << cadena.length() << std::endl;
  }
}


void Lenguaje::PrintReverse() {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    std::string cadena_inversa = cadena;
    std::reverse(cadena_inversa.begin(), cadena_inversa.end());
    std::cout << cadena_inversa << std::endl;
  }
}