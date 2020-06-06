#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top;
	char elements[50];
	
	void push(char x){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else
	elements[++top]=x;
}
char pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top--];
}
char Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
};
int oprnd(char c){
	if(c>='0'&&c<='9')
	return 1;
	else return 0;
}
int oprtr(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
	return 1;
	else return 0;
}
int isgreat(char x,char y){
	if((x=='+'||x=='-')&&(y=='*'||y=='/'))return 1;
	else return 0;
}

int main(){
	stack s;
	s.top=-1;s.size=50;
	cout<<"Enter the infix string.\n";
	char c[50];
	cin>>c;
	int n=strlen(c);
	
	int i=0;
	while(i<n){
		if(oprnd(c[i]))cout<<c[i];
		else if(oprtr(c[i])){
			if(s.top==-1||c[i]=='(')
			s.push(c[i]);
			else if(c[i]==')'){
				while (s.Top()!='(')
				cout<<s.pop();
				s.pop();
			}			
			else if(s.Top()=='(')
			s.push(c[i]);
			
			else if(isgreat(s.Top(),c[i]))
			s.push(c[i]);
			else{
				while(!isgreat(s.Top(),c[i])&&s.Top()!='('){
					
					if(s.top!=-1)
					cout<<s.pop();
					if(s.top==-1)break;
				}
				
				s.push(c[i]);
			}
		}
		i++;
	}
	while(s.top!=-1){
		cout<<s.pop();
	}cout<<endl;
	
	return 0;
}
//1+2*3-(4*5/6)+7-8
