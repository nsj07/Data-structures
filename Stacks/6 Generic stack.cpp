 #include <iostream>
#include <cstring>
using namespace std;

union u{
	int i;
	char c;
	float f;
	char str[10];
};

class stack{
	public:
	int size;
	int top,top2;
	int tag[50];
	u elements[50];
	
	stack(){
		top=-1;top2=-1;
		size=50;
	}
	
	void push(u l,int t){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else{
		if(t==1)elements[++top].i=l.i;
		else if(t==2)elements[++top].c=l.c;
		else if(t==3)elements[++top].f=l.f;
		else strcpy(elements[++top].str,l.str);
	}
	
}
u pop(int t){
	if(top==-1)
	cout<<"Stack is empty\n";
	else{
		if(t==1)
		return elements[top--];
		else if(t==2)
		return elements[top--];
		else if(t==3)
		return elements[top--];
		else 
		return elements[top--];
	}
	
}
u Top(int t){
	if(top==-1)
	cout<<"Stack is empty\n";
	else{
		if(t==1)
		return elements[top];
		else if(t==2)
		return elements[top];
		else if(t==3)
		return elements[top];
		else 
		return elements[top];
	}
	
}
void push2(int x){
	if(top2==(size-1))
	cout<<"Stack is full\n";
	else
	tag[++top2]=x;
}
int pop2(){
	if(top2==-1)
	cout<<"Stack is empty\n";
	else
	return tag[top2--];
}
int Top2(){
	if(top2==-1)
	cout<<"Stack is empty\n";
	else
	return tag[top2];
}
};

int main(){
	stack s;
	u l;
	cout<<"Enter no of elements to enter.\n";
	int i,n,t;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Enter the tag.\n";
		cin>>t;
		s.push2(t);
		cout<<"Enter the value.\n";
		if(t==1)cin>>l.i;
		else if(t==2)cin>>l.c;
		else if(t==3)cin>>l.f;
		else cin>>l.str;
		s.push(l,t);
	}
	while(s.top2!=-1){
		int t=s.pop2();
		if(t==1)cout<<s.pop(t).i<<endl;
		else if(t==2)cout<<s.pop(t).c<<endl;
		else if(t==3)cout<<s.pop(t).f<<endl;
		else cout<<s.pop(t).str<<endl;
		
	}
	return 0;
}

