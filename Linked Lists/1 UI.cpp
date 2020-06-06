#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L1=NULL,L2=NULL,U=NULL,I=NULL;

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
void u(LPTR P,LPTR Q){
	while(P!=NULL&&Q!=NULL){
		if(P->data<Q->data){
			Insert(U,P->data);
			P=P->next;
		}else if(P->data>Q->data){
			Insert(U,Q->data);
			Q=Q->next;
		}else{
			Insert(U,P->data);
			P=P->next;
			Q=Q->next;
		}
	}
	while(P!=NULL){
		Insert(U,P->data);
			P=P->next;
	}
	while(Q!=NULL){
		Insert(U,Q->data);
			Q=Q->next;
	}
}
void i(LPTR P,LPTR Q){
	int flag=0;
	while(P!=NULL&&Q!=NULL){
		if(P->data<Q->data){
			P=P->next;
		}else if(P->data>Q->data){
			Q=Q->next;
		}else{
			Insert(I,P->data);
			P=P->next;
			Q=Q->next;
			flag=1;
		}
	}
	if(flag==0)
	cout<<"No common elements.\n";
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
	//Union
	u(L1,L2);
	cout<<"Union of L1 and L2\n";
	print(U);
	cout<<"Intersection of L1 and L2\n";
	i(L1,L2);
	print(I);
	
	return 0;
}


