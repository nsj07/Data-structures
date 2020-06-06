#include <iostream>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;

void print(LPTR L){
	while(L!=NULL){
		cout<<L->data<<endl;
		L=L->next;
	}
}
void revprint(LPTR L){
	if(L!=NULL){
		revprint(L->next);
		cout<<L->data<<endl;
	}
}

int countn(LPTR L){
	if(L==NULL)return 0;
	else return 1+countn(L->next);
}

void addend(LPTR L,int x){
	while(L->next!=NULL)
	L=L->next;
	LPTR T=new(lnode);
	T->data=x;
	T->next=NULL;
	L->next=T;
}

void addfront(LPTR &L,int x){
	LPTR T=new(lnode);
	T->data=x;
	T->next=L;
	L=T;
}

void after(LPTR L,int x,int y){
	while(L->data!=x)
	L=L->next;
	LPTR T=new(lnode);
	T->data=y;
	T->next=L->next;
	L->next=T;
}

void addbefore(LPTR L,int x,int y){
	while(L->next->data!=y)
	L=L->next;
	LPTR T=new(lnode);
	T->data=x;
	T->next=L->next;
	L->next=T;
}

void deleten(LPTR L,int x){
	while(L->next->data!=x)L=L->next;
	LPTR T=L->next;
	L->next=L->next->next;
	delete(T);
}

int find(LPTR L,int x){
	if(L!=NULL){
		if(L->data==x)return 1;
		else return find(L->next,x);
	}
	else return 0;
}

int main(){
	LPTR L,T;
	L=NULL;
	cout<<"Enter the value or enter -1 to end.\n";
	int n;
	cin>>n;T=L;
	while(n!=-1){
		LPTR T2=new (lnode);
		T2->data=n;
		T2->next=NULL;
		if(L==NULL){
			L=T2;
			T=T2;
		}
		else{
			T->next=T2;
			T=T->next;
		}
		cout<<"Enter the value or enter -1 to end.\n";
		cin>>n;
	}
	addfront(L,10);
	addend(L,15);
	deleten(L,12);
	//after(L,15,16);
	//addbefore(L,51,11);
	print(L);
	cout<<"___\n";
	revprint(L);
	cout<<"___\n";
	int l=countn(L);
	cout<<"Lenght="<<l<<endl;
	find(L,152)?cout<<"found\n":cout<<"Not found\n";
	return 0;
}
