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

void rev(LPTR P){
	LPTR prev,curr,next;
	prev=NULL;
	curr=P;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}L=prev;
}

int main(){
	Insert(10);
	Insert(11);
	Insert(12);
	Insert(13);
	Insert(14);
	rev(L);
	print(L);
	return 0;
}
