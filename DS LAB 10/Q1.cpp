#include<iostream>
using namespace std;

int HashFunction(int arry[], int size, int num){
    if(arry[ num % size ] == 0) arry[ num % size ] = num;
    else{
        cout<<"Colision, Value wasted : "<<num<<" because "<<arry[num % size] << " is already there..."<<endl;
        return 1;
    }
    return 0;
}
int primeFunction(int arry[], int prime, int num){
    if(arry[ num % prime ] == 0) arry[ num % prime ] = num;
    else{
        cout<<"Colision, Value wasted : "<<num<<" because "<<arry[num % prime] << " is already there..."<<endl;
        return 1;
    }
    return 0;
}
int findPrime(int num){
    if(num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0) return num;
    else{
        return findPrime(num + 1);
    }
    return num; 
}
int main(){

    int temp[10], count = 0, i = 0 ;
    for(i = 0; i< 10; i++){
        temp[i] = 0;
    }
    i = 0;
// Mod Function
    // count+= HashFunction(temp, 10, 39);
    // count+= HashFunction(temp, 10, 45);
    // count+= HashFunction(temp, 10, 67);
    // count+= HashFunction(temp, 10, 23);
    // count+= HashFunction(temp, 10, 12);
    // count+= HashFunction(temp, 10, 13);
    // count+= HashFunction(temp, 10, 15);
    // count+= HashFunction(temp, 10, 18);
    // count+= HashFunction(temp, 10, 19);
    // count+= HashFunction(temp, 10, 34);
    
// Prime Function
    int num = findPrime(10 + 1);
    count+= primeFunction(temp, num, 39);
    count+= primeFunction(temp, num, 45);
    count+= primeFunction(temp, num, 67);
    count+= primeFunction(temp, num, 23);
    count+= primeFunction(temp, num, 12);
    count+= primeFunction(temp, num, 13);
    count+= primeFunction(temp, num, 15);
    count+= primeFunction(temp, num, 18);
    count+= primeFunction(temp, num, 19);
    count+= primeFunction(temp, num, 34);



    for(i=0; i< 10; i++){
        cout<< temp[i] << " ";
    }
    cout<<endl<< "Collisions: " << count<<endl;
    return 0;
}