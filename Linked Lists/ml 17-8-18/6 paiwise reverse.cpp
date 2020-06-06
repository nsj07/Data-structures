#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L=NULL;

LPTR Insert(){
	LPTR P=NULL;
	cout<<"Enter value ,-1 to terminate list.\n";
	int n;
	cin>>n;
	while(n!=-1){
		LPTR temp=new(lnode);
		temp->data=n;
		temp->next=NULL;
		if(P==NULL)
		P=temp;
		else{
			LPTR X=P;
			while(X->next!=NULL)
			X=X->next;
			X->next=temp;
		}
		cout<<"Enter value:";
		cin>>n;
	}
	return P;
}
void print(LPTR P){
	while(P!=NULL){
		cout<<P->data<<",";
		P=P->next;
	}cout<<endl;
}

LPTR pairrev(LPTR P){
	if(P->next==NULL)
	return P;
	else
	{
		LPTR N=P->next;
		P->next->next!=NULL?P->next=pairrev(P->next->next): P->next=NULL;
		N->next=P;
		return N;
	}
}

int main(){
	LPTR L=NULL;
	L=Insert();
	cout<<"Without reversing.\n";
	print(L);
	L=pairrev(L);
	cout<<"With pairwise reversing.\n";
	print(L);
	return 0;
}
