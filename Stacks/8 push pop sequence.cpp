#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top;
	int elements[50];
	
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

int main(){
	stack s;
	s.top=-1;s.size=50;
	char c[25];
	cout<<"Enter the sequence.\n";
	cin>>c;
	int n=strlen(c);
	int i,j,k=1;
	for(i=0;i<n;i++){
		j=c[i]-48;
		while(k<=j){
			s.push(k++);
		}
		if(s.Top()==j){
			s.pop();
		}else{
			cout<<"Not possible.\n";
			break;
		}
	}
	if(s.top==-1)
	cout<<"Sequence is possible.\n";
	return 0;
}
