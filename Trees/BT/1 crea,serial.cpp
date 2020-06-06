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
void printinorder(BTPTR B)
{
	if(B!=NULL){
		printinorder(B->lc);
		cout<<B->data<<"  ";
		printinorder(B->rc);
	}
}
void printpostorder(BTPTR B)
{
	if(B!=NULL){
		printpostorder(B->lc);
		printpostorder(B->rc);
		cout<<B->data<<"  ";
	}
}
int main(){
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR T=NULL;int i=0;
	create(T,a,i);
	printinorder(T);cout<<"\nSerialising=\n";
	serialize(T);cout<<endl;
	printpostorder(T);
}
//amb..df...j.rh..n..
