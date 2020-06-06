#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L=NULL,L2=NULL;
class stack{
	public:
	int size;
	int top;
	LPTR elements[50];
	stack(){
		top=-1;size=50;
	}
	
	void push(LPTR x){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else
	elements[++top]=x;
}
LPTR pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top--];
}
LPTR Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
};
void Insert (LPTR &P,int x){
	LPTR T=new(lnode),X;
		T->data=x;
		T->next=NULL;
	if(P==NULL){		
		P=T;
	}
	else{		
		X=P;
		while(X->next!=NULL)
		X=X->next;
		X->next=T;		
	}
}
void print(LPTR P){
	while(P!=NULL){
		cout<<P->data<<endl;
		P=P->next;
	}
}

int main(){
	stack s1,s2;
	cout<<"Enter list of L. Enter -1 to end.\n";
	int n,n2,flag;
	cin>>n;	
	while(n!=-1){
		Insert(L,n);
		cin>>n;
	}
	print(L);
	LPTR P=L,prev=L;
	s1.push(L);P=L->next;prev=L;
	while(P!=NULL){
		cout<<"--\n";
		flag=0;
		while(s1.top!=-1){
			LPTR T=s1.pop();
			if(T->data==P->data){
				flag=1;
				LPTR D=P;
				prev->next=P->next;
				P=P->next;
				delete(D);
			}else{
				s2.push(T);prev=P;P=P->next;
			}while(s2.top!=-1)
			s1.push(s2.pop());
		}
	}
	cout<<"The list is \n";
	print(L);
}
