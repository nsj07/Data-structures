#include <iostream>
using namespace std;

union u{
	int i;
	struct lnode *blink;
};
struct lnode{
	int tag;
	union u data;
	lnode *next;
};
typedef lnode* LPTR;
void print(LPTR P)
{
    while (P!=NULL)
    {
        cout << P->data.i<< "  ";
        P = P->next;
    }
    cout << endl;
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
		temp->data.i=n;temp->next=NULL;temp->tag=1;
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

void addend(LPTR &P,int x)
{
	LPTR temp=new(lnode);
	temp->data.i=x;temp->next=NULL;temp->tag=0;
	if(P==NULL)P=temp;
	else{
		LPTR X=P;
		while(X->next!=NULL)X=X->next;
		X->next=temp;
	}
}
LPTR Radixsort(LPTR L,LPTR B)
{
	int i,k,per,div;
	for(i=0;i<5;i++)
	{
		per=1;
		for(k=0;k<=i;k++)per*=10;
		div=per/10;
		//cout<<"per="<<per<<endl;
		LPTR R=B;LPTR P=L;
		while(P!=NULL){
			R=B;
			int s=(P->data.i%per)/div,i=0;
			while(i!=s){
				R=R->next;i++;
			}
			addend(R->data.blink,P->data.i);
			//cout<<"r->blink\n";
			//print(R->blink);
			P=P->next;
		}
		L=NULL;R=B;
		while(R!=NULL){
			if(R->data.blink!=NULL)
			{
				if(L==NULL){
					L=R->data.blink;R->data.blink=NULL;
				}else{
					P=L;
					while(P->next!=NULL)P=P->next;
					P->next=R->data.blink;
					R->data.blink=NULL;
				}
				//cout<<"---------------\n";
				//print(L);
			}R=R->next;
		}
	}
	return L;
}


int main(){
	
	LPTR L=Insert();
	print(L);
	LPTR R=NULL;
	for(int i=0;i<=9;i++)
	{
		LPTR temp=new(lnode);
		temp->tag=0;
		temp->data.blink=NULL;temp->next=NULL;
		if(i==0)R=temp;
		else{
			LPTR P=R;
			while(P->next!=NULL)P=P->next;
			P->next=temp;
		}
	}
	L=Radixsort(L,R);
	cout<<"After radix sort:\n";
	print(L);
	return 0;
}
