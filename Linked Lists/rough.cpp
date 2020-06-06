#include<iostream>
using namespace std;
struct lnode{
	int data;
	lnode*next;
};
typedef lnode* LPTR;
LPTR L1=NULL;
void insert(LPTR &P,int x)
{
	LPTR t=new(lnode);
	t->data=x;
	t->next=NULL;
	if(P==NULL)
	{
		P=t;
	}
	else
	{
		LPTR X;
		X=P;
		while(X->next!=NULL)
        X=X->next;
        X->next=t;
	}
}
void print(LPTR P)
{
	while(P!=NULL)
	{
		cout<<P->data<<"\n";
		P=P->next;
	}
}
int main()
{
	cout<<"enter the L1 list ,enter -1 to end \n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		insert(L1,n);
		cin>>n;
	}
	LPTR S,F=L1->next;
	while(F!=NULL){
		if(S->data==F->data)
		{
			LPTR D=F;
			S->next=F->next;
			F=F->next;
			delete(D);
		}
		else{
			S=S->next;
			F=F->next;
		}
	}
	cout<<"merged list \n";
	print(L1);
}
