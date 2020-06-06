#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
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
int main(){
	
	cout<<"Enter list of L1 in ascending order. Enter -1 to end.\n";
	int n,n2;
	cin>>n;
	while(n!=-1){
		Insert(L1,n);
		cin>>n;
	}
	//cout<<"------\n";
	print(L1);
	LPTR L=NULL,V=L1;
	while(V!=NULL){
		LPTR P=L,prev=P;
		LPTR temp=new(lnode);
		temp->data=V->data;
		temp->next=NULL;
		if(V==L1)
		{
			L=temp;
			P=temp;
		}
		else{
			while(P!=NULL){
				//cout<<"------\n";
				if(P->data<V->data){
					prev=P;
					P=P->next;
				}
				else{
					if(P==L){
						L=temp;
						temp->next=P;
					}else{
						prev->next=temp;
						temp->next=P;
					}break;
				//	P=P->next;
				}
			}
			if(P==NULL){
			prev->next=temp;
		}
		}//print(L);
		V=V->next;
	}
	cout<<"Sorted list\n";
	print(L);
	return  0;
}
