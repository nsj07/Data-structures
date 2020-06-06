#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top=-1;
	int elements[25];
	
	void push(int x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	int pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	int Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
};
int op(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/')
	return 1;
	else return 0;
}
int calc(int op2,int op1,char x){
	if(x=='+')return op1+op2;
	else if(x=='-')return op1-op2;
	else if(x=='*')return op1*op2;
	else if(x=='/')return op1/op2;
}

int eval(stack s,char c[],int n){
	int i=0;
	while(i<n){
		if(c[i]>='0'&&c[i]<='9')
		s.push(c[i]-48);
		else if(op(c[i])){
			int a=calc(s.pop(),s.pop(),c[i]);
			s.push(a);
		}i++;
	}
	int b=s.pop();
	return b;
}

int main(){
	stack s;
	//s.top=-1;
	s.size=25;
	char c[25];
	cout<<"Enter the postfix string.\n";
	cin>>c;
	int n=strlen(c);
	cout<<"length="<<n<<endl;
	int ans=eval(s,c,n);
	cout<<"Answer="<<ans<<endl;
	return 0;
}
