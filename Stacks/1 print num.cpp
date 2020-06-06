#include <iostream>
using namespace std;

class stack{
	public:
	int size;
	int top;
	int elements[50];
	stack(){
		top=-1;size=50;
	}
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
	int isempty(){
		if(top==-1) return 1;
		else return 0;
	}
};


int main(){
	
	stack s;
	s.top=-1;s.size=50;
	cout<<"Enter the no. to print\n";
	int n;
	cin>>n;
	while(n!=0){
		s.push(n%10);
		n=n/10;
	}
	while(s.top!=-1){
		int x=s.pop();
		cout<<x<<",";
	}	
	cout<<endl;
	return 0;
}
