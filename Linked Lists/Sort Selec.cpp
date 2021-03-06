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
		cout<<P->data<<endl;
		P=P->next;
	}
}
void swap(int &x,int &y){
	int z=x;
	x=y;
	y=z;
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

	cout<<"Sorted list.\n";
	print(L);
	return 0;
}
