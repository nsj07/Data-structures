#include <iostream>
using namespace std;

class stack{
	public:
	int size;
	int top;
	int elements[50];
	
	stack(){
		top=-1;
		size=50;
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
	return top==-1?1:0;
}
};

int main()
{
	int a[10],n;
	stack s1,s2;
	cout<<"Enter no. of values.\n";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];s1.push(a[i]);
	}
	
	int i=0;
	for(i=0;i<n;i++){
		if(i%2==0){
			while(!s1.isempty()){
				int t=s1.pop();
				if(s2.isempty())
				s2.push(t);
				else{
					if(s2.Top()>t){
						int temp=s2.pop();
						s2.push(t);s2.push(temp);
					}else{
						s2.push(t);
					}
				}
			}
			a[n-1-i]=s2.pop();
		}else{
			while(!s2.isempty()){
				int t=s2.pop();
				if(s1.isempty())
				s1.push(t);
				else{
					if(s1.Top()>t){
						int temp=s1.pop();
						s1.push(t);s1.push(temp);
					}else{
						s1.push(t);
					}
				}
			}
			a[n-1-i]=s1.pop();			
		}
	}
	cout<<"Bubble sort:\n";
	for(i=0;i<n;i++)cout<<a[i]<<"  ";
	cout<<endl;
	return 0;
}
