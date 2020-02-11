#include<iostream>
#include<vector>
using namespace std;	

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}


int main()
{

	vector< vector<int> > myJaggedArry;
	int i;
	for(i=0;i<5;i++){
		vector<int> t;
		myJaggedArry.push_back(t);
	}
	i=0;
	int n,num;
	cout<<"How Many Numbers You Want to Insert: "<<endl;
	cin>>n;
	while(i<n){
		cout<<"Kindly Enter Number at Position ("<<i<<"): ";
		cin>>num;
		myJaggedArry[num%5].push_back(num);
		i++;
	}
	
	i=0;
	cout<< "All values input are divided by 5 and than placed according to the reminder of Their Index..."<<endl;
	while(i<n){
		cout<< myJaggedArry[i]  << endl;
		i++;
	}

	
	
 return 0;
}

