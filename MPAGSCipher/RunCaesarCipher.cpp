// Caeser Cipher Function //

// Include Relevant Header Files
#include <iostream>
#include <string>
#include <cctype>

#include "RunCaesarCipher.hpp"

// Declare funciton

std::string runCaesarCipher(const std::string& inputText,
			    const size_t key, const bool encrypt)
{
  // Create the alphabet container and output string
  const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  const std::string::size_type alphabetSize {alphabet.size()};

  std::string outputText{""};

  // Truncate the key to the range 0 - 25
  size_t shift{key % alphabetSize};
  if (encrypt == false)
    {
      shift = alphabetSize - shift;
    }

  // Or, in one line, which also allows the variable to be declared const:
  // const size_t shift{ encrypt ? key % alphabetSize : alphabetSize - (key % alphabetSize) };

  // Loop over the input text

  for ( char inChar : inputText )
  {
    for (std::string::size_type i{0}; i<alphabetSize; i++)
    {
      if ( inChar == alphabet[i] ) {
        // Determine the new character and add to output string
        outputText += alphabet[(i + shift) % alphabetSize];
        break;
      }
    }
  }
  // Return output string
  return outputText;
}

   
