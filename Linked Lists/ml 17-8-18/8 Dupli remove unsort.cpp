#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L=NULL,L2=NULL;

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
	cout<<"Enter list of L1. Enter -1 to end.\n";
	int n,n2;
	cin>>n;	
	while(n!=-1){
		Insert(L,n);
		cin>>n;
	}
		LPTR P=L,R,F;
	int min,flag=0;
	while(P->next!=NULL){
		min=P->data;
		flag=0;
		F=P->next;
		while(F!=NULL){
			if(F->data<min){
				R=F;
				min=F->data;
				flag=1;
				F=F->next;
			}
			else
			F=F->next;
		}
		if(flag==1){
			swap(P->data,R->data);
		}
		P=P->next;
	}
	LPTR S=L;
	F=L->next;
	while(F!=NULL){
		if(S->data==F->data){
			LPTR D=F;
			S->next=F->next;
			F=F->next;
			delete(D);
		}else{
			S=S->next;
			F=F->next;
		}
	}
	cout<<"List without duplicates.\n";
	print(L);	
	return 0;
}
