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

int main(){
	Insert(10);
	Insert(11);
	Insert(12);
	Insert(13);
	Insert(14);
	Insert(15);
	Insert(16);
	Insert(17);
	Insert(18);
	Insert(19);
	Insert(20);
	int i=1;
	LPTR P=L;
	while(i<=3){
		P=P->next;i++;
	}
	LPTR Q=L;
	while(Q->next!=NULL)
	Q=Q->next;
	Q->next=P;
	int flag=0;
	LPTR S=L,F=L;
	S=S->next;F=F->next->next;
	while(F->next!=NULL &&S!=F){
		S=S->next;
		F=F->next->next;
	}
	if(S==F)
	cout<<"Loop found.\n";
	else
	cout<<"Not Found.\n";
	LPTR X,Y;
	X=S,Y=L;
	if(S==F){
		while(X!=Y){
			X=X->next;
			Y=Y->next;
		}
		cout<<"Starting value of loop = "<<X->data<<endl;
	}
	P=L;
	int j=0,l=0;
	while(P->next!=NULL&&j<2){
		l++;
		if(P->next==X)j++;
		P=P->next;
	}cout<<"Length = "<<l<<endl;
	return 0;
}
