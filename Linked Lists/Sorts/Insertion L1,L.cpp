#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;

LPTR Insert()
{
	LPTR L=NULL;
	cout<<"Enter value ,-1 to terminate.\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		LPTR temp=new(lnode);
		temp->data=n;temp->next=NULL;
		if(L==NULL)L=temp;
		else{
			LPTR X=L;
			while(X->next!=NULL)
			X=X->next;
			X->next=temp;
		}cout<<"Value=";cin>>n;
	}
	return L;
}
void print(LPTR P)
{
    while (P!=NULL)
    {
        cout << P->data << "  ";
        P = P->next;
    }
    cout << endl;
}
LPTR InsertionSort(LPTR L1)
{
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
	return L;
}
int main()
{
	LPTR L=Insert();
	print(L);
	LPTR L1=InsertionSort(L);
	cout<<"Sorted :\n";
	print(L1);
	return 0;
}
