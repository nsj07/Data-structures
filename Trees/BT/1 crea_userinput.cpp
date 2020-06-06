#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
};
typedef btnode* BTPTR;
void create(BTPTR &T,char k)
{
	if(T==NULL){
		T=new(btnode);
		T->data=k;T->lc=NULL;T->rc=NULL;
	}
	cout<<"Inserting left child of "<<T->data<<" else type 0"<<endl;
	char s;cin>>s;
	if(s!='0'){
		create(T->lc,s);
	}
	cout<<"Inserting right child of "<<T->data<<" else type 0"<<endl;
	cin>>s;
	if(s!='0'){
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
void printinorder(BTPTR B)
{
	if(B!=NULL){
		printinorder(B->lc);
		cout<<B->data<<"  ";
		printinorder(B->rc);
	}
}
int main()
{
	BTPTR T=NULL;
	create(T,'A');
	printinorder(T);cout<<"\nSerialising=\n";
	serialize(T);	
}
