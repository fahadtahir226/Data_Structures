#include <iostream>
using namespace std;
#include <string.h>
#include "StringADT.h"

int main(){
	StringADT str;
		string secondaryStr;
		str.read_String();
	
	
//	cin >> secondaryStr;
//	str.concatenate(abc);
	bool isInt  = str.is_Integer();
	if(isInt) {
		cout<<"Yes it is an Integer"<<endl;
		cout<< "Integer Form: " << str.to_Integer();	
	}
	else{
		cout<< "It is not Integer"<<endl;

	}
	string secStr;
	cout<< "Enter a string to compare to original: ";
	cin>> secStr;
	if(str.string_Equal(secStr)){
		cout<<"Yes They are Equal";
	}
	else{
		cout<<"No They are not equal";
	}
	
	
	
	return 0;
}
