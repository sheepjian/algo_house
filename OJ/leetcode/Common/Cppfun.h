#ifndef CPPFUNCTION
#define CPPFUNCTION

#include <vector>
#include <stdio.h>
#include <string>

namespace cppFunction{
	std::vector<char*> split(std::string str, char* delimiter){
		std::vector<char*> res;
		char* s = const_cast<char*>(str.c_str());
		char* pch = std::strtok(s,delimiter);
		while(pch!=NULL) {
			res.push_back(pch);
			pch = std::strtok(NULL,delimiter);
		}
		return res;
	}
}


#endif