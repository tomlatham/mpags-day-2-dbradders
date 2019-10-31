// Process command line function

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

#include "ProcessCommandLine.hpp"

bool processCommandLine(
			const std::vector<std::string>& args,
			bool& helpRequested,
			bool& versionRequested,
			std::string& inputFileName,
			std::string& outputFileName )
{
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nargs {args.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nargs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
  return false;
	// exit main with non-zero return to indicate failure

      }
      else {
	// Got filename, so assign value and advance past it
	inputFileName = args[i+1];
	++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nargs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
  return false;
	// exit main with non-zero return to indicate failure

      }
      else {
	// Got filename, so assign value and advance past it
	outputFileName = args[i+1];
	++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return false;
    }
  }

  return true;
}

