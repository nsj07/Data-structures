#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
	btnode* adj;
	btnode* dlink;
};
typedef btnode* BTPTR;
void create(BTPTR &T,char a[],int& i)
{
	if(i<strlen(a)){
		if(a[i]!='.'){
			T=new(btnode);
			T->data=a[i];
			T->lc=NULL;T->rc=NULL;T->adj=NULL;T->dlink=NULL;
			i++;
			create(T->lc,a,i);
			i++;
			create(T->rc,a,i);
		}
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

int height(BTPTR P)
{
	if(P==NULL)
	return -1;
	else
	return max(height(P->lc),height(P->rc))+1;
}
void levellinks(BTPTR T,BTPTR F[])
{
	static int k=0;F[k++]=T;
	int i=0,h=height(T),flag=0;
	BTPTR Par=T,P,NxtPar,D=T;
	while(i<h)
	{
		flag=0;
		while(Par!=NULL)
		{
			if(Par->lc!=NULL){
				if (flag==0){
					P=Par->lc;NxtPar=P;
					F[k++]=P;
					D->dlink=P;D=D->dlink;
				}
				if(Par->lc!=NULL&&flag==1){
					P->adj=Par->lc;
					P=P->adj;
				}
				if(Par->rc!=NULL){
					P->adj=Par->rc;
					P=P->adj;
				}flag=1;
			}
			else{
				if(flag==0){
					P=Par->rc;NxtPar=P;
					F[k++]=P;
					D->dlink=P;D=D->dlink;
				}
				if(flag==1){
					P->adj=Par->rc;
					P=P->adj;
				}flag=1;
			} 
			Par=Par->adj;
		}i++;
		Par=NxtPar;
		while(Par!=NULL)
		{
			if(Par->lc!=NULL||Par->rc!=NULL)
			break;
			else Par=Par->adj;
		}
	}
	
}
void levelorderrec(BTPTR T)
{
	if(T!=NULL){
		cout<<T->data<<"  ";
		if(T->adj!=NULL)
		levelorderrec(T->adj);
		if(T->dlink!=NULL){
			cout<<endl;
			levelorderrec(T->dlink);
		}
	}
}
int main()
{
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR T=NULL,F[10],K;
	int i=0;
	create(T,a,i);
	int h=height(T),n;
	cout<<"Height="<<h<<endl;
	levellinks(T,F);
	cout<<"Printing levelorder:\n";
	levelorderrec(T);	
}
//amb..df...j.rh..n..
