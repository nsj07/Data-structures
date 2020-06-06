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

int main(){
	cout<<"Enter the no. of elements to enter.\n";
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		Insert(a);
	}
	cout<<"Enter the n th number of node from end.\n";
	int n;
	cin>>n;
	LPTR S=L,F=L;
	int i=1;
	while(i<n){
		F=F->next;
		i++;
	}
	while(F->next!=NULL){
		S=S->next;
		F=F->next;
	}
	cout<<"The "<<n<<" node from end is = "<<S->data;
	return 0;
}
