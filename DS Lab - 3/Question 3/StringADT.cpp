#include "StringADT.h"

StringADT::StringADT(){
	
}
void StringADT::read_String(){
	cin >> inputString;
	len = inputString.length();
//	cout<< "You Entered: " << inputString;
	return;
}

void StringADT::concatenate(string newStr){
	
	inputString+= newStr;
	len = inputString.length();
	cout << inputString<< endl;
	return;
}

bool StringADT::is_Integer(){
	bool isInt = true;
	int i=0;
	while(isInt && i<len){
		if(inputString[i] < 48 || inputString[i] > 57) isInt = false;
		i++;
	}
	return isInt;
}


int StringADT::to_Integer(){
	if(is_Integer()) {
		int x = 0,j = 0;
		for(int i = len - 1;i>=0;i--){
			x += (inputString[i] - 48) * pow(10,j++);
		}
		return x;
	}
	return 0;	
}
bool StringADT::string_Greater (string secStr){
	if(len > secStr.length()){
		return true;
	}	
	return false;
}

bool StringADT::string_Smaller(string secStr){
	if(len<secStr.length()) return true;
	return false;
}

bool StringADT::string_Equal(string secStr){
	bool isEql = true;
	int i=0;
	if(secStr.length()==len){
		while(isEql && i<len) {
			if(secStr[i]!=inputString[i]) isEql = false;
			i++;
		}
	}
	else{
		return false;
	}
	return isEql;
}









