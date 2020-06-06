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
void pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	top--;
}
char Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
int isempty(){
	if(top==-1)return 1;
	else return 0;
}
};
int ispair(char x,char y){
	if(x=='('&&y==')')
	return 1;
	else if(x=='{'&& y=='}')
	return 1;
	else if(x=='['&&y==']')
	return 1;
	else return 0;
}

int main(){
	stack s;
	s.top=-1;
	s.size=50;
	char c[25];
	cout<<"Enter the string of paranthesis to check balanced or not.\n";
	cin>>c;
	int n=strlen(c);
	//cout<<s.elements<<endl;
	int i=0;
	while(i<n){
		char x=c[i];
		if(x=='('||x=='{'||x=='[')
		s.push(x);
		else if(x==')'||x=='}'||x==']'){
			int y=ispair(s.Top(),x);
			
			if(s.top==-1||y!=1)
			{cout<<"Not balanced\n";
			break;}
			else
			s.pop();
		}
		i++;
	}
	s.isempty()?cout<<"Balanced\n":cout<<"Not balanced\n";
	return 0;
}

