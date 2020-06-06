#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
	lnode *next2;
};
typedef lnode* LPTR;
LPTR L1=NULL;

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
		cout<<P->data<<",";
		P=P->next;
	}cout<<endl;
}
void assign(LPTR P)
{
	if(P->next->next==NULL)
	{
		LPTR X=L1;
		while(X->next->next!=P)
		X=X->next;
		P->next2=X;P->next->next2=NULL;
	}else
	{
		P->next2=P->next->next;
		assign(P->next);
	}
}
void printa(LPTR P){
	LPTR Q=P->next;
	cout<<"one is:\n";
	while(P!=NULL){
		cout<<P->data<<",";
		if(P->next2->next2==P){
			cout<<P->next2->data<<",";
			break;
		}
		else{
			P=P->next2;
		}
	}cout<<endl;
	cout<<"second is:\n";
	while(Q!=NULL){
		cout<<Q->data<<",";
		if(Q->next2->next2==Q){
			cout<<Q->next2->data<<",";
			break;
		}
		else{
			Q=Q->next2;
		}
	}cout<<endl;
}
int main(){
	
	cout<<"Enter list of L1 in ascending order. Enter -1 to end.\n";
	int n,n2;
	cin>>n;
	while(n!=-1){
		Insert(L1,n);
		cin>>n;
	}
	assign(L1);
	print(L1);
	cout<<"Rand\n";
	printa(L1);
	return 0;
	
}
