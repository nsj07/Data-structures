#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;

LPTR L=NULL;
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
		cout<<P->data<<",";
		P=P->next;
	}cout<<endl;
}
int countn(LPTR L){
	if(L==NULL)return 0;
	else return 1+countn(L->next);
}

LPTR revrec(LPTR P){
	LPTR L;
	if(P->next==NULL)return P;
	else{
	L=revrec(P->next);
	P->next->next=P;
	P->next=NULL;
	}return L;
}
void revprint(LPTR L){
	if(L!=NULL){
		revprint(L->next);
		cout<<L->data;
	}
}
int main(){
	cout<<"Enter list of L1. Enter -1 to end.\n";
	int n,n2;
	cin>>n;
	
	while(n!=-1){
		Insert(L1,n);
		cin>>n;
	}
	cout<<"Enter list of L2. Enter -1 to end.\n";
	cin>>n2;
	while(n2!=-1){
		Insert(L2,n2);
		cin>>n2;
	}
	print(L1);print(L2);
	L1=revrec(L1);L2=revrec(L2);
	//print(L1);print(L2);
	int l1=countn(L1),l2=countn(L2),carry=0;
	LPTR P=L1,Q=L2,L3=NULL;		
	if(l1>l2){
		while(Q!=NULL){
			int sum=P->data+Q->data+carry;
			Insert(L3,sum%10);
			carry=sum/10;
			P=P->next;Q=Q->next;
		}while(P!=NULL){
			int sum=P->data+carry;
			Insert(L3,sum%10);
			carry=sum/10;
			P=P->next;			
		}if(carry!=0)
		Insert(L3,carry);
	}
	else{
		while(P!=NULL){
			int sum=P->data+Q->data+carry;
			Insert(L3,sum%10);
			carry=sum/10;
			P=P->next;Q=Q->next;
		}while(Q!=NULL){
			int sum=Q->data+carry;
			Insert(L3,sum%10);
			carry=sum/10;
			Q=Q->next;			
		}if(carry!=0)
		Insert(L3,carry);		
	}
	cout<<"Sum=";
	revprint(L3);
	return 0;
}
