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
  std::string outputText{""};
  int nText = inputText.size();
  size_t n{key};

  if (encrypt == false)
    {n = 0 - key;}

  // Loop over the input text

  for (int i{0}; i<nText; i++)
    {
      // Determine the new character and add to output string
      outputText += char(65+(int((inputText[i])-65-n))%26);
    }
  // Return output string
  return outputText;
}

   
