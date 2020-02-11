#include<iostream>
using namespace std;

void left_sum(int A[][10],int row)
{
	int i,j,sum=0;
	
	for(i=0;i<row;i++)
	{
	sum=sum+A[i][i];
	}
		cout<<"sum of left diagonal=   "<<sum<<endl;
	
}

void right_sum(int A[][10],int row)
{
		
	int a,b,i,j,sum=0;
	a=row-1;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			b=i+j;
			
			if(a==b)
			{
			sum=sum+A[j][i];
			}
		}
		
	}
		cout<<"sum of column  "<<sum<<endl;

	
}

int main()
{
	int row;
	int i,j;
	
	cout<<"enter no of rows of your matrix"<<endl;
	cin>>row;
	cout<<"square matrix has same row and column size"<<endl;
	
	int A[row][10];
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			cout<<"row  "<<i+1<<" column "<<j+1<<" :- ";
			cin>>A[i][j];
		}
	}

	left_sum(A,row);
	right_sum(A,row);
}
