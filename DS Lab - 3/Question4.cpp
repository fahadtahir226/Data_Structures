#include<iostream>
using namespace std;

void input(int A[][10],int row, int column)
{
	
	cout<<"enter values for matrix A"<<endl;
	
	int i,j;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			cout<<"row  "<<i+1<<" column "<<j+1<<" :- ";
			cin>>A[i][j];
		}
	}
	
}
void display(int A[][10],int row, int column)
{
	
	cout<<"values of matrix A: "<<endl;
	
	int i,j;
	
	for(i=0;i<row;i++)
	{
		cout<<"| ";
		for(j=0;j<column;j++)
		{
			cout<<" "<<A[i][j]<<"  ";
			
		}
		cout<<" |";
		cout<<endl;
	}
	
}

void sum(int A[][10],int row, int column)
{
	
	cout<<"sum of values of matrix A"<<endl;
	
	int i,j,sum=0;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			sum=sum+A[i][j];
		}
	}
	
	cout<<"sum =  "<<sum<<endl;
	
}
void sum_row(int A[][10],int row, int column)
{
	
	cout<<"row wise addition of matrix A"<<endl;
	
	int i,j,sum=0;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			sum=sum+A[i][j];
		}
		
		cout<<"sum of row  "<<i+1<<"=  "<<sum<<endl;
		sum=0;
	}
	
}
void sum_col(int A[][10],int row, int column)
{
	
	cout<<"column wise addition of matrix A"<<endl;
	
	int i,j,sum=0;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			sum=sum+A[j][i];
		}
		
		cout<<"sum of column  "<<i+1<<"=  "<<sum<<endl;
		sum=0;
	}
	
}

void transpose(int A[][10],int row, int column)
{
	int i,j;
	
	for(i=0;i<row;i++)
	{
		cout<<"| ";
		for(j=0;j<column;j++)
		{
			cout<<" "<<A[j][i]<<" ";
			
		}
		cout<<" |";
		cout<<endl;
	}
	
	
}

int main()
{
	int row,column;
	
	cout<<"enter no of rows of your matrix"<<endl;
	cin>>row;
	cout<<"enter no of column of your matrix"<<endl;
	cin>>column;
	
	int A[row][10];
	
	input(A,row,column);
	display(A,row,column);
	sum(A,row,column);
	sum_row(A,row,column);
	sum_col(A,row,column);
	transpose(A,row,column);
	
}
