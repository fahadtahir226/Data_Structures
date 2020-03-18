#include <iostream>
using namespace std;

void displayTail(int i){
	if(i>0){
		cout<< i << " - ";
		displayTail(i-1);		
	}
	return;
}

void displayNontail(int i){
	if(i>0){
		displayNontail(i-1);		
		cout<< i << " - ";
	}
	return;
}
int main(){
	cout<<endl<<"Now Non tail :"<<endl;
	displayNontail(5);
	cout<<endl<<"Now tail :"<<endl;
	displayTail(5);
	
	
}
