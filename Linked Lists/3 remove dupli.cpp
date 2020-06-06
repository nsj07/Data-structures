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
	cout<<"Enter list of L1 in ascending order. Enter -1 to end.\n";
	int n,n2;
	cin>>n;
	while(n!=-1){
		Insert(L,n);
		cin>>n;
	}
	LPTR S=L,F=L->next;
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
