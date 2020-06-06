#include <iostream>
using namespace std;

class stack{
	public:
	int size;
	int top[50];
	int elements[1000];
	
	void push(int x,int num){
		int n=num-1;
	if(top[n]==(size*num)-1)
	cout<<"Stack is full\n";
	else
	elements[++top[n]]=x;
}
int pop(int num){
	int n=num-1;
	if(top[n]==(size*n)-1)
	cout<<"Stack is empty\n";
	else
	return elements[top[n]--];
}
int Top(int num){
	int n=num-1;
	if(top[n]==(size*n)-1)
	cout<<"Stack is empty\n";
	else
	return elements[top[n]];
}
};

int main(){
	
	stack s;
	cout<<"Enter the number of stacks.\n";
	int n,i;
	cin>>n;
	s.size=1000/n;
	for(i=0;i<n;i++)
	s.top[i]=(s.size*i)-1;
	char test,test2;
	do{
		int x,n;
		cout<<"Enter num to push and also stack num.\n";
		cin>>x>>n;
		s.push(x,n);
		//cout<<"---"<<s.Top(n)<<endl;
		cout<<"To push another enter 'a' or else 'q'.\n";
		cin>>test;
	}while(test=='A'||test=='a');
	cout<<"To pop a num enter 'p'.\n";
	cin>>test2;
	while(test2=='p'||test2=='P'){
		cout<<"Enter stack num to pop.\n";
		int l;
		cin>>l;
		cout<<s.pop(l)<<endl;
		cout<<"To pop another enter 'p'.\n";
		cin>>test2;
	}
	
	return 0;
}
