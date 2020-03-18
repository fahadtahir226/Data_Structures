#include <iostream>
using namespace std; 
// ^_^

class Stack {
  char arry[100];
  public:
  int size;
    Stack(){
      int i = 0;
      while(i==100) arry[i++] = ' '; 
      size = 0;
    }  
    void push(char data) {
      arry[size] = data;
      size++;
    } 
    int pop(){
      char temp = arry[size - 1];
      arry[size] = ' ';
      size--;
      return temp;
    }

    bool isEmpty(){
        if(size) return false;
        return true;
    }
    void displayRev(){
      for(int i = 0 ;i < size; i++) cout<<arry[i]<< " ";
    }
};


int prec(char c)
{
 if(c == '^')
 return 3;
 else if(c == '*' || c == '/')
 return 2;
 else if(c == '+' || c == '-')
 return 1;
 else
 return -1;
} 




int main(){
    Stack equation, operands, operators;

// a/b-(c+d)-e 

    equation.push('a');
    equation.push('/');
    equation.push('b');
    equation.push('-');
    equation.push('(');
    equation.push('c');
    equation.push('+');
    equation.push('d');
    equation.push(')');
    equation.push('-');
    equation.push('e');

    equation.displayRev();
    cout<<endl;


    while(!equation.isEmpty){







        // If the scanned character is operand

        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        
         ns+=s[i];
        // If the scanned character is ‘(’

        if(s[i] == '(')
         st.push('(');
        // If the scanned character is Operator

        If(s[i] == Operator) then
         while(!st.IsEmpty && prec(s[i]) <= prec(st.top())) do
         char c = st.top();
         st.pop();
         ns += c;
         end while
         st.push(s[i]);
        End if



        // If the scanned character is ‘)’

        if(s[i] == ')') then
         while(st.top() != '(') do
         char c = st.top();
         st.pop();
         ns += c;
         end while
         if(st.top() == '(') then
         char c = st.top();
         st.pop();
         end if
        End if









    }




    return 0;
}