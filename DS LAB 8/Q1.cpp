#include <iostream>
#include <stdlib.h>
using namespace std;

typedef void (*Function) (int array[],int size);

void Bubble_Sort(int array[], int size);
void Modified_Bubble_Sort(int array[], int size);
void Selection_Sort(int array[], int size);
void Insertion_Sort(int array[], int size);
void Display(int array[], int size);

//   ************************************************************ Bubble Sort
void Bubble_Sort(int array[], int size){
    int temp, swap = 0, compare = 0;
    Display(array, size);
    for(int i = 0; i < size; i++){

        for(int j = size - 1; j >  i - 1; j--){

            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+ 1];
                array[j + 1] = temp;
                // cout<< "Swaping: " << array[j] << " with " << array[j + 1]<<endl;
                swap++;
            }
            compare++;

        }
    }
    cout<< "Swapings: "<< swap<< " - Comparisons: "<< compare<<endl;
}


//   ************************************************************ Modified Bubble Sort
void Modified_Bubble_Sort (int array[], int size){
    int temp, swap = 0, compare = 0, again = true;
    Display(array, size);
    for(int i = 0; i < size && again; i++){
        again = false;
        for(int j = size - 1; j >  i - 1; j--){

            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+ 1];
                array[j + 1] = temp;
                // cout<< "Swaping: " << array[j] << " with " << array[j + 1]<<endl;
                again = true;
                swap++;
            }
            compare++;

        }
    }
    cout<< "Swapings: "<< swap<< " - Comparisons: "<< compare<<endl;
}

//   ************************************************************ Selection Sort
void Selection_Sort(int array[], int size){
    int min, index, temp, swap = 0, compare = 0;
    for(int i=0;i < size ; i++){
        min = array[i];
        index = i;
        
        for(int j = i; j < size; j++){
            if(array[j] < min) {
                min = array[j];
                index = j;
            }
        compare++;
        }
        swap++;
        temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
    cout<< "Swapings: "<< swap<< " - Comparisons: "<< compare<<endl;
}
//   ************************************************************ Insertion Sort
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
        Display(array, size);
    }
    cout<< "Swapings: "<< swap<< " - Comparisons: "<< compare<<endl;
}

void generateRandomArry(int array[], int size){
    for(int i = 0; i < size; i++){
        array[i] = 1 + (rand() % 20);  
    }
}

void Display(int array[], int size){
    for(int i = 0 ; i < size; i++){
        cout<< array[i];
        if(i + 1 < size) cout<< " - "; 
    }
    cout << endl;
}


int main(){

Function sortingfunctions[4] = {
    Bubble_Sort,
    Modified_Bubble_Sort, 
    Selection_Sort, 
    Insertion_Sort
};
int i = 0, size = 20;
// int array[size] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
// int array[size] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
// int array[size] = {3,5,6,11,12,15,16,19,19,20,28,42,39,40,34,44,47,49};
int array[size];
generateRandomArry(array, size);
Display(array, size);

    cout<<"Select Which Sorting You Want To Use: "<<endl;
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Modified Bubble Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Insertion Sort"<<endl;
    cin>> i ;
    sortingfunctions[i - 1](array, size);
    Display(array, size);

    return 0;
}