#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L1=NULL,L2=NULL;

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
		Insert(L1,n);
		cin>>n;
	}
	cout<<"Enter list of L2 in ascending order. Enter -1 to end.\n";
	cin>>n2;
	while(n2!=-1){
		Insert(L2,n2);
		cin>>n2;
	}
	LPTR P=L1,Q=L2,prev1=P,prev2=Q;
	while(P!=NULL&&Q!=NULL){
		if(P->data<Q->data){
			prev1=P;
			P=P->next;			
		}		
		else{
			if(P==L1){
				LPTR temp=new(lnode),D;
				temp->data=Q->data;
				temp->next=P;
				L1=temp;
				P=temp;
				prev1=temp;
				D=Q;
				Q=Q->next;
				delete(D);
			}
			else{
				LPTR temp=new(lnode),D;
			temp->data=Q->data;
			temp->next=P;
			prev1->next=temp;
			prev1=prev1->next;
			D=Q;
			Q=Q->next;
			delete(D);
			}
		}
	}
	
	while(Q!=NULL){
		LPTR temp=new(lnode),D;
			temp->data=Q->data;
			temp->next=NULL;
			prev1->next=temp;
			prev1=prev1->next;
			D=Q;
			Q=Q->next;
			delete(D);	
	}
	cout<<"Merged list is=\n";
	print(L1);
	return 0;
}
