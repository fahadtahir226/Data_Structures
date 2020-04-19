#include <iostream>
#include <stdlib.h>
using namespace std;


void Display(int array[], int size);
void Insertion_Sort(int array[], int size){
    int key,j,  temp, swap = 0, compare = 0;
    for(int i = 1 ;  i < size ; i++){
        key = array[i];
        for(j = i ; j > 0 ; j--){
            compare++;
            if(array[j - 1] < key) break;
            array[j] = array[j - 1];
        }
        swap++;
        array[j] = key;
    }
    // cout<< "Swapings: "<< swap<< " - Comparisons: "<< compare<<endl;
}

void generateRandomArry(int array[], int size){
    for(int i = 0; i < size; i++){
        array[i] = 1 + (rand() % 20);  
    }
}

int BinarySearch(int array[], int num, int size,int freq){
    // cout<< "Here in Binary Search"<<endl;
    int left = 0, right = size - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(left == right && array[mid] != num) {
            cout<< freq;
            return freq;
        };
        if(array[mid] < num){
            right = mid;
        }
        else if(array[mid] > num){
            left = mid;
        }
        else if(array[mid] == num){    
            freq++;
            array[mid] = -1;
            BinarySearch(array, num, size, freq);
        }
    }
    return freq;
}

void FreqFun(int array[],int size){
    for(int i = 0; i < size; i++){
        cout<< "Here"<<endl;
        if(array[i] % 2 == 0){
            BinarySearch(array, array[i], size, 0);
        }

    }
}
void Display(int array[], int size){
    for(int i = 0 ; i < size; i++){
        cout<< array[i];
        if(i + 1 < size) cout<< " - "; 
    }
    cout << endl;
    return;
}


int main(){

    int array[10];
    generateRandomArry(array, 10);
    Display(array, 10);
    Insertion_Sort(array, 10);
    Display(array, 10);
    cout<<"Here"<<endl;
    // int Freq = 0;
    FreqFun(array, 10);
    return 0;
}

