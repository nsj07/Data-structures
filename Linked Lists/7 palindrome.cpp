#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top;
	char elements[50];
	stack(){
		top=-1;
		size=50;
	}	
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
int isempty(){
	if(top==-1)return 1;
	else return 0;
}
};

struct lnode{
	char data;
	lnode *next;
};
typedef lnode* LPTR;

LPTR L=NULL;

void Insert (char x){
	LPTR T=new(lnode);
		T->data=x;
		T->next=NULL;
	if(L==NULL){		
		L=T;
	}
	else{
		LPTR P;		
		P=L;
		while(P->next!=NULL)
		P=P->next;
		P->next=T;
	}
}

int main(){
	stack s;
	cout<<"Enter the string to check palindrome or not.\n";
	char c[25];
	cin>>c;
	int i=0;
	while(c[i]!='\0'){
		Insert(c[i++]);
	}
	LPTR S,F,P;
	int flag=0;
	S=L;F=L;
	s.push(S->data);
	while(F->next!=NULL){		
		P=F->next;
		if(P->next==NULL){
			F=P;
			flag=1;				
		}else{
			S=S->next;
			s.push(S->data);
			F=P->next;
		}
	}if(flag==0) s.pop();
	while(S->next!=NULL){
		S=S->next;
		if(s.Top()==S->data)
		s.pop();
		else{
			cout<<"Not palindrome.\n";
			break;
		}
	}
	if(s.isempty())cout<<"Palindrome.\n";
	return 0;
}
