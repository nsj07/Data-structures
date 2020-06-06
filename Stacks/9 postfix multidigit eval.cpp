#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top;
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
int calc(int op1,int op2,char x){
	cout<<"op1="<<op1<<"  op2="<<op2<<endl;
	if(x=='+')return op1+op2;
	else if(x=='-')return op1-op2;
	else if(x=='*')return op1*op2;
	else if(x=='/')return op1/op2;
}

int isbreak(char x){
	if(x==' '||x=='+'||x=='-'||x=='*'||x=='/')return 1;
	else return 0;
}

int eval(stack s,char c[],int n){
	int i=0;
	while(i<n){
		if(!op(c[i])){
			int j=0,sum=0,k;
			while(!isbreak(c[i])){
				sum=sum*10+(c[i++]-48);
				
			};
			c[i]!=32?i=i+0:i++;
			
			cout<<"--"<<sum<<endl;
			s.push(sum);
		}
		else if(op(c[i])) {
			cout<<"op="<<c[i]<<endl;
			int a=calc(s.pop(),s.pop(),c[i]);
			cout<<".....a="<<a<<endl;
			s.push(a);
			i++;
		}
	}
	int b=s.pop();
	return b;;
}

int main(){
	stack s;
	s.top=-1;
	s.size=50;
	char c[50];
	cout<<"Enter the postfix string.\n";
	cin.getline(c,50,'\n');
	int n=strlen(c);
	cout<<"length="<<n<<endl;
	int ans=eval(s,c,n);
	cout<<"Answer="<<ans<<endl;
	return 0;
}
