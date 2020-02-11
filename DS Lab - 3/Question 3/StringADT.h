#ifndef STRINGADT_H
#define STRINGADT_H

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class StringADT {
	
	int len;
	string inputString;
	public:
		StringADT();
		bool is_Integer();
		int to_Integer ();
		void read_String();
		void concatenate(string);
		bool string_Greater (string);
		bool string_Smaller (string);
		bool string_Equal (string);

	
};




#endif

