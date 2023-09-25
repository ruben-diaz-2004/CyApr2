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
void Lenguaje::FileWrite(std::ifstream& input_file) {
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


/**
 * Método que imprime los lenguajes almacenados en la clase
 * @param output_file. Fichero de salida donde imprimir los lenguajes
*/
void Lenguaje::PrintLenguajes(std::ofstream& output_file) {
  bool first_character = true;
  for (const auto& entrada : lenguaje_) {
    const std::set<char>& lenguaje = entrada.second;
    output_file << "{";
    for (char caracter: lenguaje) {
      if (first_character) {
        output_file << caracter;
        first_character = false;
      } else { output_file << ", " << caracter; }
    }
    output_file << "}" << std::endl;
    first_character = true;
  }
  output_file << std::endl;
}


/**
 * Método que imprime la longitud de las cadenas de entrada
 * @param output_file. Fichero de salida.
*/
void Lenguaje::PrintLength(std::ofstream& output_file) {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    output_file << cadena.length() << std::endl;
  }
}


/**
 * Método que imprime las cadenas de forma inversa
 * Utiliza la librería <algorithm>
 * @param output_file. Fichero de salida donde imprimir las cadenas
*/
void Lenguaje::PrintReverse(std::ofstream& output_file) {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    std::string cadena_inversa = cadena;
    std::reverse(cadena_inversa.begin(), cadena_inversa.end());
    output_file << cadena_inversa << std::endl;
  }
}


/**
 * Método que imprime los prefijos posibles de las cadenas
 * @param output_file. Fichero de salida donde imprimir los prefijos
*/
void Lenguaje::PrintPreffix(std::ofstream& output_file) {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    output_file << "{&";
    for (int longitud{1}; longitud <= cadena.length(); ++longitud) {
      std::string prefijo = cadena.substr(0, longitud);
      output_file << ", " << prefijo;
    }
    output_file << "}" << std::endl;
  }
}


/**
 * Método que imprime los sufijos posibles de las cadenas
 * @param output_file. Fichero de salida donde imprimir los sufijos
*/
void Lenguaje::PrintSuffix(std::ofstream& output_file) {
  for (const auto& entrada: cadenas_) {
    const std::string& cadena = entrada.second;
    output_file << "{&";
    for (int i = (cadena.length() - 1); i >= 0; --i) {
      std::string suffix = cadena.substr(i);
      output_file << ", " << suffix;
    }
    output_file << "}" << std::endl;
  }
}