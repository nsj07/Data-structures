#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;

LPTR L=NULL;

void Insert (int x){
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

void print(LPTR P){
	while(P!=NULL){
		cout<<P->data<<endl;
		P=P->next;
	}
}

void revrec(LPTR P){
	if(P->next==NULL)L=P;
	else{
	revrec(P->next);
	P->next->next=P;
	P->next=NULL;
	}
}

int main(){
	Insert(9);
	Insert(11);
	Insert(12);
	Insert(14);
	Insert(25);
	cout<<"Before reversing.\n";
	print(L);
	cout<<"After reversing.\n";
	revrec(L);
	print(L);
	return 0;
}
