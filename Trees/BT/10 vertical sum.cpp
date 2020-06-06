#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
	int pos;
};
typedef btnode* BTPTR;
void create(BTPTR &T,int k)
{
	if(T==NULL){
		T=new(btnode);
		T->data=k;T->lc=NULL;T->rc=NULL;
	}
	cout<<"Inserting left child of "<<T->data<<" (else type 0)"<<endl;
	int s;cin>>s;
	if(s!=0){
		create(T->lc,s);
	}
	cout<<"Inserting right child of "<<T->data<<" (else type 0)"<<endl;
	cin>>s;
	if(s!=0){
		create(T->rc,s);
	}	
}
void serialize(BTPTR T)
{
	if(T!=NULL){
		cout<<T->data;
		serialize(T->lc);
		serialize(T->rc);
	}else{
		cout<<".";
	}
}
void assignpos(BTPTR T,int i,char x,int &min,int &max)
{
	if(T!=NULL){
		if(x=='c'){
			T->pos=i;min=i;max=i;
		}
		if(x=='l'){
			T->pos=i-1;i--;
			if(i<min)min=i;
		}
		if(x=='r'){
			T->pos=i+1;i++;
			if(i>max)max=i;
		}
		assignpos(T->lc,i,'l',min,max);
		assignpos(T->rc,i,'r',min,max);
	}
}
void vsum(BTPTR T,int sum[],int min)
{
	if(T!=NULL){
		sum[T->pos-min]+=T->data;
		vsum(T->lc,sum,min);
		vsum(T->rc,sum,min);
	}
}

int main()
{
	BTPTR T=NULL;
	cout<<"Enter root value.\n";
	int n,min,max,sum[15];
	cin>>n;
	create(T,n);
	for(int j=0;j<15;j++)sum[j]=0;
	assignpos(T,0,'c',min,max);
	vsum(T,sum,min);
	cout<<"Vertical sums are:\n";
	for(int i=0;i<=max-min;i++){
		cout<<sum[i]<<"  ";
	}cout<<endl;
	
}
