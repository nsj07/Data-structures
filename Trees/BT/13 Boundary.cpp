#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
};
typedef btnode* BTPTR;

void create(BTPTR &T,char a[],int& i)
{
	if(i<strlen(a)){
		if(a[i]!='.'){
			T=new(btnode);
			T->data=a[i];
			T->lc=NULL;T->rc=NULL;
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
void leftedge(BTPTR B)
{
	if(B!=NULL){
		if(B->rc!=NULL||B->lc!=NULL)
		cout<<B->data<<"  ";
		leftedge(B->lc);
	}
}
void rightedge(BTPTR B,BTPTR root)
{
	if(B!=NULL){
		rightedge(B->rc,root);
		if((B->lc!=NULL||B->rc!=NULL)&&B!=root)
		cout<<B->data<<"  ";
	}
}
void leaves(BTPTR T)
{
	if(T!=NULL){
		if(T->lc==NULL&&T->rc==NULL){
			cout<<T->data<<"  ";
		}
		leaves(T->lc);
		leaves(T->rc);
	}
}
int main(){
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR T=NULL;int i=0;
	create(T,a,i);
	cout<<"Boundaries:\n";
	leftedge(T);leaves(T);rightedge(T,T);
}
//amb..df...j.rh..n..
