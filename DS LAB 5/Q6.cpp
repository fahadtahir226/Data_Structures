#include <iostream>
using namespace std;

bool palindrome(int first, int last, string str){
    if(first>=last){
        return true;
    }
    else{
        if(str[first]==str[last]){
            return palindrome(first+1,last-1, str);
        }
        else{
            return false;
        }
    }
}

int main(){
    string str;
    cin >> str;
    if(palindrome(0, str.length() - 1, str)){
        cout<<"Yes It is a palindrome"<<endl;
    }
    else{
        cout<< "No It is not a palindrome"<<endl;
    }
    return 0;
}