#include <iostream>
using namespace std;

class stack{
	public:
	int size;
	int top;
	string elements[50];
	
	void push(string x){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else
	elements[++top]=x;
}
string pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top--];
}
string Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
};

int op(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')return 1;
	else return 0;
}
int main(){
	stack s;
	cout<<"Enter the prefix string.\n";
	string str;
	cin>>str;
	int n=str.length(),i=n-1;
	while(i>=0){
		
		if(!op(str[i])){
			string temp;
			temp=str[i];
			
			s.push(temp);
		}
		else{
			string temp,t1=s.pop(),t2=s.pop();
			temp = t1+t2;
			temp+=str[i];
		
			s.push(temp);
		}i--;
	}
	cout<<"Postfix string = "<<s.pop()<<endl;
	return 0;
}
//**+AB-+CDEF
