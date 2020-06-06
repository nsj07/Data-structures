#include <iostream>
using namespace std;

class stack{
	public:
	int size1;
	int size2;
	int top1;
	int top2;
	int elements[50];
	
	stack(){
		size1=25;size2=25;
		top1=25;
		top2=24;
	}
	
	void push1(int x){
	if(top1==0)
	cout<<"Stack is full\n";
	else
	elements[--top1]=x;
}
int pop1(){
	if(top1==25)
	cout<<"Stack is empty\n";
	else
	return elements[top1++];
}
int Top1(){
	if(top1==25)
	cout<<"Stack is empty\n";
	else
	return elements[top1];
}
void push2(int x){
	if(top2==49)
	cout<<"Stack is full\n";
	else
	elements[++top2]=x;
}
int pop2(){
	if(top2==24)
	cout<<"Stack is empty\n";
	else
	return elements[top2--];
}
int Top2(){
	if(top2==24)
	cout<<"Stack is empty\n";
	else
	return elements[top2];
}
};

int main(){
	stack s;
	s.push1(5);
	s.push1(10);
	s.push1(12);
	s.push2(23);
	s.push2(86);
	s.push2(78);
	cout<<s.Top1()<<"--"<<s.Top2()<<endl;
	s.pop1();s.pop2();
	cout<<s.Top1()<<"--"<<s.Top2()<<endl;
	return 0;
}
