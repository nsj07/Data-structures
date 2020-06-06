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
		cout<<P->data<<"  ";
		P=P->next;
	}cout<<endl;
}
void addend(int x){
	LPTR P=L;
	while(P->next!=NULL)
	P=P->next;
	LPTR T=new(lnode);
	T->data=x;
	T->next=NULL;
	P->next=T;
}

int main(){
	cout<<"Enter the value.Enter -1 to end.\n";
	int n,c=0;
	cin>>n;
	while(n!=-1){
		Insert(n);
		c++;
		cout<<"Enter the value.Enter -1 to end.\n";
		cin>>n;
	}
	int i=0;
	LPTR P=L,P2,D;
	while(i<c){
		if(P->data%2==1){
			addend(P->data);
			if(P==L){
				L=P->next;
				D=P;
				P=P->next;
				delete(D);
			}else{
				LPTR P2=L;
				while(P2->next!=P)
				P2=P2->next;
				D=P;
				P2->next=P->next;
				P=P->next;
				delete(D);
			}
		}else{
			P=P->next;
		}i++;
	}
	print(L);
	
	return 0;
}
