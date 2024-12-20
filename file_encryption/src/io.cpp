#include "io.hpp"

#include <fstream>
#include <iostream>

IO::IO(const char* file_name) {
	file_stream.open(file_name, std::ios::in | std::ios::out | std::ios::binary);
	if (!file_stream.is_open()) {
		std::cerr << "Error: Could not open file" << '\n';
	}
}

std::fstream IO::get_file_stream() {
	return std::move(file_stream);
}


IO::~IO() {
	if (file_stream.is_open()) {
		file_stream.close();
	}
}
