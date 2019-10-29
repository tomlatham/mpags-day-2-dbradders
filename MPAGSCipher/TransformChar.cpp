// Transliterate function

// Include headers

#include <iostream>
#include <cctype>
#include <string>

// Note that quotes used rather than angle brackets as this header is
// internal to our project rather than external

#include "TransformChar.hpp"

std::string transformChar (const char inputChar){
      // Uppercase alphabetic characters
  std::string inputText;
    if (std::isalpha(inputChar)) {
      inputText += std::toupper(inputChar);
      }

    // Transliterate digits to English words
    else{
    switch (inputChar) {
      case '0':
	inputText += "ZERO";
	break;
      case '1':
	inputText += "ONE";
	break;
      case '2':
	inputText += "TWO";
	break;
      case '3':
	inputText += "THREE";
	break;
      case '4':
	inputText += "FOUR";
	break;
      case '5':
	inputText += "FIVE";
	break;
      case '6':
	inputText += "SIX";
	break;
      case '7':
	inputText += "SEVEN";
	break;
      case '8':
	inputText += "EIGHT";
	break;
      case '9':
	inputText += "NINE";
	break;
    }}

    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.

  return inputText;

}
