#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
struct lqueue{
	LPTR f;
	LPTR r;
};
struct lqueue LQ[10];
void print(LPTR L){
	while(L!=NULL){
		cout<<L->data<<"  ";
		L=L->next;
	}cout<<endl;
}
void lenqueue(lqueue &LQ,int x){
	LPTR temp=new(lnode);
	temp->data=x;temp->next=NULL;
	if(LQ.f==NULL)
	{
		LQ.f=temp;LQ.r=temp;
	}else{
		LQ.r->next=temp;
		LQ.r=temp;
	}
}
int ldequeue(lqueue &LQ){
	if(LQ.f==NULL)
	cout<<"Queue is empty.\n";
	else{
		int t=LQ.f->data;LPTR T=LQ.f;
		if(LQ.f==LQ.r){
			LQ.f=NULL;LQ.r=NULL;
		}else{
			LQ.f=LQ.f->next;
		}
		delete(T);
	}
}
int lisEmpty(lqueue &LQ){
	if(LQ.f==NULL)return 1;
	else return 0;
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
LPTR Radixsort(LPTR L,lqueue LQ[])
{
	int i,k,per,div;
	for(i=0;i<5;i++)
	{
		per=1;
		for(k=0;k<=i;k++)per*=10;
		div=per/10;
		//cout<<"per="<<per<<endl;
		LPTR P=L;
		while(P!=NULL){
			
			int s=(P->data%per)/div;
			lenqueue(LQ[s],P->data);
			
			//cout<<"r->blink\n";
			//print(R->blink);
			P=P->next;
		}
		L=NULL;
		for(int i=0;i<=9;i++){
			if(!lisEmpty(LQ[i]))
			{
				if(L==NULL){
					L=LQ[i].f;LQ[i].f=NULL;LQ[i].r=NULL;
				}else{
					P=L;
					while(P->next!=NULL)P=P->next;
					P->next=LQ[i].f;
					LQ[i].f=NULL;LQ[i].r=NULL;
				}
				//cout<<"---------------\n";
				//print(L);
			}
		}
	}
	return L;
}

int main(){
	
	LPTR L=Insert();
	print(L);
	
	for(int i=0;i<=9;i++)
	{
		LQ[i].f=NULL;LQ[i].r=NULL;
	}
	L=Radixsort(L,LQ);
	cout<<"After radix sort:\n";
	print(L);
	return 0;
}
