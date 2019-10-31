// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Include fstream to deal with input/output file stream
#include <fstream>

// Include function hpp files
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  //Declare arguments in main scope

  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  //Perform processCommand first
  const bool processedOK { processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile) };
  if ( ! processedOK ) {
    std::cerr << "Problem processing command line arguments" << std::endl;
    return 1;
  }
   
  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Check file was correctly opened
  bool ok_to_read{false};
  bool ok_to_write{false};

  // Read in user input from stdin/file
  std::ifstream in_file {};
  if (!inputFile.empty()) {
    // Initialise input from file
    in_file.open(inputFile);

    // Returns true if input file was correctly opened
    ok_to_read = in_file.good();
    if ( ! ok_to_read ) {
      std::cerr << "[error] problem reading from file: " << inputFile << std::endl;
    }
  }

  // If ok_to_read true
  if (ok_to_read)
    {
  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
      while(in_file >> inputChar)
  {
    // Print input characters from file then transliterate text
    inputText += transformChar(inputChar);
  }
    }
  // Also need to deal with keyboard input text
  else {
   while(std::cin >> inputChar)
     {
       inputText += transformChar(inputChar);
     }
  }
     
  // Perform Caesar Cipher
  std::string outputText { runCaesarCipher(inputText, 1, false) };

  // Output the transliterated text
  // Warn that output file option not yet implemented
  std::ofstream out_file{};
  if (!outputFile.empty()) {
    // Initialise output to file
    out_file.open(outputFile);
    
    ok_to_write = out_file.good();
    if ( ! ok_to_write ) {
      std::cerr << "[error] problem writing to file: " << outputFile << std::endl;
    }
  }

    if(ok_to_write){
      // Now use output text since now have performed Caesar Cipher
      out_file << outputText;
    }
    else{
      std::cout << outputText << std::endl;
    }
    
  //Print outputText instead

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
