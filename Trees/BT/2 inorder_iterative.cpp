#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
};
typedef btnode* BTPTR;
class stack{
	public:
	int size;
	int top;
	BTPTR elements[50];
	stack(){
		top=-1;size=50;
	}
	void push(BTPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	BTPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	BTPTR Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
	int isempty(){
		if(top==-1)return 1;
		else return 0;
	}
};
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

int main(){
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR T=NULL;int i=0;
	create(T,a,i);
	cout<<"\nSerialising=\n";
	serialize(T);cout<<endl;
	stack s;
	cout<<"Preorder :\n";
	if(T!=NULL) s.push(T);
	while(!s.isempty()){
		BTPTR p=s.pop();
		cout<<p->data;
		if(p->rc!=NULL) s.push(p->rc);
		if(p->lc!=NULL) s.push(p->lc);
	}cout<<endl;
	cout<<"Inorder :\n";
	BTPTR p=T;
	s.push(p);
	while(!s.isempty()){
		while(p->lc!=NULL){
			s.push(p->lc);p=p->lc;
		}
		BTPTR m=s.pop();
		cout<<m->data;
		if(m->rc!=NULL){
			s.push(m->rc);p=m->rc;
		}
	}cout<<endl<<"Postorder :\n";
	stack s1;
	s.push(T);p=T;
	while(!s.isempty()){
		BTPTR k=s.pop();
		if(k->lc!=NULL)
		s.push(k->lc);
		if(k->rc!=NULL)
		s.push(k->rc);
		s1.push(k);
	}
	while(!s1.isempty())
	cout<<s1.pop()->data;
	cout<<endl;
}
//amb..df...j.rh..n..
