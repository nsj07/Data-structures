#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;

LPTR L1=NULL,L2=NULL;

void Insert (LPTR P,int x){
	LPTR T=new(lnode);
		T->data=x;
		T->next=NULL;
	if(P==NULL){		
		P==L1?L1=T:L2=T;
	}
	else{	
		LPTR X;	
		P==L1?X=L1:X=L2;
		while(X->next!=NULL)
		X=X->next;
		X->next=T;		
	}
}
void Insertboth(int x){
	LPTR T=new(lnode);
		T->data=x;
		T->next=NULL;
	LPTR P=L1,Q=L2;
	while(P->next!=NULL)
	P=P->next;
	while(Q->next!=NULL)
	Q=Q->next;
	P->next=T;Q->next=T;	
}
void print(LPTR P){
	while(P!=NULL){
		cout<<P->data<<endl;
		P=P->next;
	}
}
int countn(LPTR P){
	if(P==NULL)return 0;
	else return 1+countn(P->next);
}

LPTR common(LPTR P,LPTR Q){
	int n1=countn(L1),n2=countn(L2);
	cout<<n1<<"--"<<n2<<endl;
	int diff,i=1;
	if(n1>n2){
		diff=n1-n2;
		while(i<=diff)
		{
			P=P->next;i++;
		}
		while(P!=Q){
			P=P->next;
			Q=Q->next;
		}
		return P;
	}else{
		diff=n2-n1;
		while(i<=diff)
		{
			Q=Q->next;
			i++;
		}
		while(P!=Q){
			P=P->next;
			Q=Q->next;
		}return P;
	}	
}

int main(){
	Insert(L1,1);
	Insert(L1,2);
	Insert(L1,3);
	Insert(L1,4);
	Insert(L2,5);
	Insert(L2,6);
	Insert(L2,7);
	Insertboth(8);
	Insertboth(9);
	Insertboth(10);
	print(L1);
	print(L2);
	LPTR C=common(L1,L2);
	cout<<"Common node has value = "<<C->data<<endl;
	return 0;
}
