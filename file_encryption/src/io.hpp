#ifndef IO_HPP
#define IO_HPP


#include <fstream>
// #include <iostream>

class IO {
 public:
	std::fstream file_stream;

 public:
	IO(const char* file_name);
	~IO();
	std::fstream get_file_stream();
};


#endif
