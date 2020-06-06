#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
struct bnode{
	LPTR blink;
	bnode *right;
	bnode *left;
};
typedef bnode* BPTR;
void print(LPTR P)
{
    while (P!=NULL)
    {
        cout << P->data << "  ";
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

void addend(LPTR &P,int x)
{
	LPTR temp=new(lnode);
	temp->data=x;temp->next=NULL;
	if(P==NULL)P=temp;
	else{
		LPTR X=P;
		while(X->next!=NULL)X=X->next;
		X->next=temp;
	}
}
LPTR Radixsort(LPTR L,BPTR B)
{
	int i,k,per,div,j;
	for(i=0;i<5;i++)
	{
		per=1;
		for(k=0;k<=i;k++)per*=10;
		div=per/10;
		//cout<<"per="<<per<<endl;
		BPTR R=B;LPTR P=L;j=0;
		while(P!=NULL){
			int s=(P->data%per)/div;
			if(s>=j){
				while(s!=j){
					R=R->right;j++;
				}
			}else{
				while(s!=j){
					R=R->left;j--;
				}
			}
			addend(R->blink,P->data);
			//cout<<"r->blink\n";
			//print(R->blink);
			P=P->next;
		}
		L=NULL;R=B;
		while(R!=NULL){
			if(R->blink!=NULL)
			{
				if(L==NULL){
					L=R->blink;R->blink=NULL;
				}else{
					P=L;
					while(P->next!=NULL)P=P->next;
					P->next=R->blink;
					R->blink=NULL;
				}
				//cout<<"---------------\n";
				//print(L);
			}R=R->right;
		}
	}
	return L;
}


int main(){
	
	LPTR L=Insert();
	print(L);
	BPTR R=NULL;
	for(int i=0;i<=9;i++)
	{
		BPTR temp=new(bnode);
		temp->right=NULL;temp->left=NULL;
		temp->blink=NULL;
		if(i==0)R=temp;
		else{
			BPTR P=R;
			while(P->right!=NULL)P=P->right;
			P->right=temp;temp->left=P;
		}
	}
	L=Radixsort(L,R);
	cout<<"After radix sort:\n";
	print(L);
	return 0;
}
