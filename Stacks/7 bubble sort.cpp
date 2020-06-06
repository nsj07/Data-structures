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
void wap(int *x,int *y){
	int z=*x;
	*x=*y;
	*y=z;
}

int main(){
	stack s1,s2;
	cout<<"Enter the number of values.\n";
	int n,i;
	cin>>n;
	cout<<"Enter the values.\n";
	for(i=0;i<n;i++){
		int x;
		cin>>x;
		s1.push(x);
	}
	/*int pass,k;
	for(pass=1;pass<=n-1;pass++){
		for(k=0;k<n-pass;k++){
			if(s1.elements[k]>s1.elements[k+1]){
				int z;
				z=s1.elements[k];
				s1.elements[k]=s1.elements[k+1];
				s1.elements[k+1]=s1.elements[k];
			}
		}
		cout<<s1.Top()<<"--------\n";
		s2.push(s1.pop());
		
	}
	for(i=0;i<n;i++){
		cout<<s1.elements[i]<<",";
	}*/
	s2.push(s1.pop());
	while(!s1.isempty()){
		
		/*if(s2.Top()<s2.elements[s2.top-1]){
			s1.push(s2.pop());
			cout<<" here ";
		}*/
		
		if(s1.Top()<s2.Top()){
			int x=s1.Top(),y=s2.Top();
			wap(&x,&y);
			s1.pop();s2.pop();
			s1.push(x);
			s2.top!=-1?s1.push(y):s2.push(y);
			//s2.push(s1.pop());
		}
		
		
		else if(s1.Top()>=s2.Top()){
			s2.push(s1.pop());
		}
	}
	
	for(i=0;i<n;i++)
	cout<<s2.elements[i]<<",";
	cout<<endl;
	return 0;
}
