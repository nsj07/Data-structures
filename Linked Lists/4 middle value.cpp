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

int main(){
	LPTR S,F,P;
	Insert(10);
	Insert(11);
	Insert(12);
	Insert(13);
	Insert(14);
	Insert(15);
	Insert(16);
	Insert(17);
	int flag=0;
	S=L;F=L;
	while(F->next!=NULL){		
		P=F->next;
		if(P->next==NULL){
			F=P;
			flag=1;
			cout<<"The middle values are "<<S->data<<" and "<<S->next->data<<endl;
		}else{
			S=S->next;
			F=P->next;
		}
	}
	if(flag==0)
	cout<<"The middle value is = "<<S->data<<endl;
	
	return 0;
}
