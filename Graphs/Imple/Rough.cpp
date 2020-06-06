#include <iostream>
using namespace std;

typedef
struct lnode{
	int data;
	lnode* next;
}* LPTR;


void addlist(LPTR &T,int c)
{
	if(T==0){
		T=new lnode();T->data=c;T->next=0;
	}
	else
	addlist(T->next,c);
}
void print(LPTR L)
{
	if(L){
		cout<<L->data<<" ";
		print(L->next);
	}
	else
	cout<<endl;
}

int main()
{
	LPTR L=0;
	addlist(L,1);
	addlist(L,2);
	addlist(L,3);
	print(L);
	addlist(L,4);
	addlist(L,5);
	print(L);
}
