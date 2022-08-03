// Includes that are built in to C++
#include <string>
#include <stdint.h>

// Includes from other projects
#include <StandardFileIO.h>
#include <StandardLogger.h>

// Includes from within this project
#include "Parser/Parser.h"
#include "Compiler/Compiler.h"
#include "OSSpecific.h"

#ifndef MAX_FILE_SIZE
#define MAX_FILE_SIZE 26214400
#endif


int main(int argc, char** argv) {
	F515_StandardLogger::Logger logger;
	F515_StandardFileIO::FileIO fileIO;
	F515_OSSpecific::OSUtils    utils;
	F515_Compiler::Compiler     compiler;
	F515_Parser::ItemList       list;
	F515_Parser::Parser         parser;
	F515_Parser::Lexer          lexer;
	F515_Parser::Node           startNode;
	std::string                 outName;
	std::string                 ASMOut;
	uint64_t                    status;

	/* Commented out until every thing is ready;

	// If no extra arguments are supplied.
	if (argc == 1) {
		logger.fatal("Name of file to compile not specified!");
		return 1;
	}

	// If more than 1 extra argument is specified
	if (argc > 2) {
		if (argc == 4) {
			if (argv[2] != "-o") {
				logger.fatal("Unknown arg!");
				return 1;
			} else {
				outName = argv[3];
			}
		} else {
			logger.fatal("Too many args!");
			return 1;
		}
	}

	// Any other argument number occurs
	if (argc < 1 || argc > 4) {
		logger.fatal("Argument Error");
		return 1;
	}

	*/

	std::string file = /*argv[1]*/  "path/to/input"; /* put path here -- TESTING ONLY */

	if (fileIO.fileSizeInBytes(file) > MAX_FILE_SIZE) {
		logger.fatal("Max file size for compiling is 25MB");
		return 1;
	}

	std::string code = fileIO.ReadFile(file);

	status = lexer.convert((uint8_t*)code.c_str(), code.length(), &list);
	if (status != 0) {
		std::string i = "Lexer returned ";
		i.append(std::to_string(status));
		logger.error(i);
		return 1;
	}

	status = parser.parse(list, &startNode);
	if (status != 0) {
		std::string i = "Parser returned ";
		i.append(std::to_string(status));
		logger.error(i);
		return 1;
	}

	status = compiler.compile(startNode, &ASMOut);
	if (status != 0) {
		std::string i = "Compiler returned ";
		i.append(std::to_string(status));
		logger.error(i);
		return 1;
	}

	/*
	logger.info("Converting...");
	std::string CPP_code = converter.F515ScriptToCPPScript(code);
	logger.info("Successfully Converted!");

	const char* temp_path;

	if (PLATFORM == 0) { // WINDOWS
		temp_path = "TEMP\\temp.cpp";
	}
	else {
		temp_path = "TEMP/temp.cpp";
	}

	
	
	ifdef F515_PLATFORM_WINDOWS
	fileIO.MakeDir("TEMP");
	logger.info("directory made");
	fileIO.WriteFile(CPP_code, temp_path);

	if (PLATFORM == 0) { // WINDOWS
		logger.info("Compiling...");
		windowsUtils.RunProcess("cmd /k \" g++ TEMP\\temp.cpp -o hi\"", std::to_string(NULL), 0, true);
	}

	fileIO.RemoveDir("TEMP", true);
	endif

	*/

	while (true);

	return 0;
}