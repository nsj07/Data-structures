#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L1=NULL;
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
int main()
{
	LPTR L=Insert();
	LPTR P=L,prev=L;
	while(P!=NULL)
	{
		if(P->data<0){
			if(P==L){
				prev=P;P=P->next;
			}else{
				prev->next=P->next;
				P->next=L;
				L=P;
				P=prev->next;
			}
		}else{
			prev=P;
			P=P->next;
		}
	}
	cout<<"Sorted :\n";
	print(L);
	return 0;
}
