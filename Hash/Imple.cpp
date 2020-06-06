#include <iostream>
using namespace std;

typedef
struct lnode{
	int data;
	lnode* next;
}* LPTR;
void addend(LPTR &L,int k)
{
	if(L==0){
		L=new lnode();L->data=k;L->next=0;
	}
	else
	addend(L->next,k);
}
void Insert(LPTR H[],int k)
{
	int r=k%10;
	addend(H[r],k);
}
int search(LPTR L,int k)
{
	if(L){
		
	}
}
int main()
{
	LPTR H[10];
	int i,n;
	for(i=0;i<10;i++)
	H[i]=0;
	cout<<"Enter values(-1 to end)\n";
	cin>>n;
	while(n!=-1){
		Insert(H,n);
		cin>>n;
	}
}
