#include <iostream>
using namespace std;

int sumOfNum(int remainin, int toAdd, int sum){
	sum+=toAdd;
	if(remainin !=0){
		return sumOfNum(remainin/10,remainin % 10, sum);
	}
	return sum;
}

int digit_root(int n){
	if(n / 10 != 0){
		return digit_root(sumOfNum(n,0,0));
	}
	return n;
}



int main(){
	cout << digit_root(12345);
	return 0;
}
