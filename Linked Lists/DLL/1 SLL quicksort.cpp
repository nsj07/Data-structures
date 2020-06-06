#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
void swap(int &x,int &y)
{
	int z=x;x=y;y=z;
}
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
LPTR partition(LPTR l,LPTR h)
{
	int x=h->data;
	LPTR i=NULL;
	for(LPTR j=l;j!=h;j=j->next)
	{
		if(j->data<=x){
			if(i==NULL)i=l;
			else i=i->next;
			swap(i->data,j->data);
		}
	}if(i==NULL)i=l;else i=i->next;
	swap(i->data,h->data);
	return h;
}
void quicksort(LPTR l,LPTR h)
{
	LPTR J,P=l;
	if(h!=NULL&&l!=h&&h->next!=l){
		J=partition(l,h);
		while(P->next!=J)P=P->next;
		quicksort(l,P);
		quicksort(J->next,h);
	}
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

int main(){
	LPTR L=Insert(),H=L;
	while(H->next!=NULL)H=H->next;
	cout<<"Before sorting.\n";
	print(L);
	cout<<"After sorting.\n";
	quicksort(L,H);
	print(L);
	return 0;
}
