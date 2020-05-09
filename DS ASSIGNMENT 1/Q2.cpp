#include <iostream>
#include <fstream>
using namespace std; 


void inputInFile(){
  ofstream onfile;
  onfile.open ("Q2.txt");
  int num, seq;
  cin >> num;
  onfile << num <<endl;

  for(int i = 0; i < num; i++){
    cin >> seq;
    onfile << seq <<endl;
  }

  int n, queries, start, end, maxNum;
  cin >> n;
  onfile << n <<endl;
  for(int j = 0; j < n; j++){
    cin >> start >> end>> maxNum;
    onfile << start << " "<< end << " "<< maxNum <<endl;
  }

  onfile.close();
}
void outputToFile(int arry[],int n){
  ofstream onfile;
  onfile.open ("Q2_output.txt");

  for(int i = 0; i < n; i++){
    onfile << arry[i] <<endl;
  }
}

int processQuery(int start,int end,int maxNum, int arry[]){
  int count = 0;
  for(int i = start; i <= end; i++){
    if(arry[i] > maxNum) count++;
  }
  return count;
}
void inputFromFile(){
  int n;
  ifstream infile;
  infile.open ("Q2.txt");
  infile >> n;
  int arry[n];

  int val;
  for(int i = 0; i < n; i++){
    infile >> val;
    arry[i] = val;

  }
  n = 0;
  infile >> n;
  int start, end, maxNum, arryOfOutput[n];
  for(int j = 0; j < n; j++){
    infile >> start >> end >> maxNum;
    arryOfOutput[j] = processQuery(start,end,maxNum, arry);
  }
  outputToFile(arryOfOutput,n);

  for(int k = 0 ;k < n ; k++){
    cout<< arryOfOutput[k]<<endl;
  }



  infile.close();
}


int main(){
  //  inputInFile();

  inputFromFile();
  return 0;
}