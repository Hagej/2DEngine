#pragma once

#include <string>

namespace engine {

	inline std::string read_file(const char* filepath) {		

		FILE* file = fopen(filepath, "rt");		// Open file "read, textfile" mode
		fseek(file, 0, SEEK_END);				// Find EOF
		unsigned long length = ftell(file);		// Store length of file
		char* data = new char[length + 1];
		memset(data, 0, length + 1);			// Remove artifacts from fseek
		fseek(file, 0, SEEK_SET);				// Find beginning of file
		fread(data, 1, length, file);			// Read entire file
		fclose(file);							// Close file

		std::string result(data);				// Create string
		delete[] data;							// Delete data
		return result;							// Return result string

	}

}