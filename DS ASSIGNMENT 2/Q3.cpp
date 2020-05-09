#include <iostream>
#include <cstring>
#include<fstream>
#define size 100

using namespace std;

bool validation(int axes_x, int axes_y){
		if (axes_x < 0 || axes_y < 0 || axes_x >= 4 || axes_y >= 7)
		return false;
	else
		return true;
}



void paths(char arr[][size], int axes_x, int axes_y,int r, int c, char vis[][size], int& cunt)
{	
	static int w=0;	
	
		
	if (axes_x == r - 1 && arr[axes_x][axes_y] == 'e') 
	{
		cunt++; if(cunt==1){system("CLS");
		}	
		cout<<endl<<w<<"# cost---------------\n";
		w=0;return;
	} 	
	vis[axes_x][axes_y] = '1'; 
if (validation(axes_x,axes_y) && arr[axes_x][axes_y]=='1') 
	{	
		// go down
		if ( vis[axes_x + 1][axes_y]=='0' && axes_x + 1 < r){
			paths(arr, axes_x + 1, axes_y, r, c, vis, cunt);
			cout<<"("<<axes_x+1 <<","<<axes_y<<") ";
		}
		
		// go up 
		if (axes_x - 1 >= 0 && vis[axes_x - 1][axes_y]=='0'){
			paths(arr, axes_x - 1, axes_y, r, c, vis, cunt);
			cout<<"("<<axes_x-1 <<","<<axes_y<<") ";
		}if (axes_y + 1 < c && vis[axes_x][axes_y + 1]=='0'){
			paths(arr, axes_x, axes_y + 1, r, c, vis, cunt);
			cout<<"("<<axes_x <<","<<axes_y +1<<") ";
		}if (axes_y - 1 >= 0 && vis[axes_x][axes_y - 1]=='0'){
			paths(arr, axes_x, axes_y - 1, r, c, vis, cunt);
			cout<<"("<<axes_x+1 <<","<<axes_y-1<<") ";
		}	}
	w++;	vis[axes_x][axes_y] = '0';
}


void rep(){
		int ent;
		cout<<"File opened press any key to continue\t";
	cin>>ent;
	cout<<endl;
	}

int set0( char ch[][size], int r, int c){
		for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		ch[i][j]='0';}		
	}
}



int main()
{

	ifstream inf;
	inf.open("maze_test.txt");
	if(inf.fail()){
		cerr<<"Error opening file"<<endl;
		exit(1);
	}
	int m,n;
	inf>>m>>n;
	char array1[n][size];
	char array2[n][size];
		
	system("PAUSE");
	set0(array2,m,n);
	
	while(!inf.eof()){
		for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		inf>>array1[i][j];
		}		
	}
	}
	
	cout<<"\t Ready steady \n";

	int ctr = 0;
	ofstream file;
	file.open("Q2.txt");
	file<<"output\n\n\n"<<endl;
	file<<"\t";
	file.close();
	paths(array1, 0, 0,m,n, array2, ctr);
	return 0;
}