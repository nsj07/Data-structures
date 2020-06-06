#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
};
typedef btnode* BTPTR;

void create(BTPTR &T,int k)
{
	if(T==NULL){
		T=new(btnode);
		T->data=k;T->lc=NULL;T->rc=NULL;
	}
	cout<<"Do u want to insert(else 0) in left child of "<<T->data<<endl;
	int s;cin>>s;
	if(s!=0){
		create(T->lc,s);
	}
	cout<<"Do u want to insert(else 0) in right child of "<<T->data<<endl;
	cin>>s;
	if(s!=0){
		create(T->rc,s);
	}	
}
void serialize(BTPTR T)
{
	if(T!=NULL){
		cout<<T->data<<" ";
		serialize(T->lc);
		serialize(T->rc);
	}else{
		cout<<".";
	}
}
void store(BTPTR B,int a[],int &n)
{
	static int i=0;
	if(B!=NULL){
		store(B->lc,a,n);
		a[i++]=B->data;n++;
		store(B->rc,a,n);
	}
}
void inordertrav(BTPTR B,int a[])
{static int j=0;
	if(B!=NULL){
		inordertrav(B->lc,a);
		B->data=a[j++];
		inordertrav(B->rc,a);
	}
}
void printinorder(BTPTR B)
{
	if(B!=NULL){
		printinorder(B->lc);
		cout<<B->data<<" ";
		printinorder(B->rc);
	}
}
int main(){
	cout<<"Enter the root value\n";
	int r,a[20],n=0;
	cin>>r;
	BTPTR T=NULL;int i=0;
	create(T,r);
	cout<<"\nSerialising=\n";
	serialize(T);cout<<endl;
	store(T,a,n);
	cout<<n<<endl;
	int pass=1;
	for(pass=1;pass<=n-1;pass++){
		for(i=0;i<n-pass;i++){
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
			}
		}
	}
	inordertrav(T,a);
	cout<<"\nSerialising=\n";
	serialize(T);cout<<endl;
}
