#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lchild;
	int data;
	int x;
	bstnode *rchild;
};
typedef bstnode* BSTPTR;
class stack{
	public:
	int size;
	int top;
	int elements[50];
	stack(){
		top=-1;size=50;
	}
	void push(int x){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else
	elements[++top]=x;
}
int pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top--];
}
int Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
};
BSTPTR Insert(BSTPTR T,int k)
{
	if(T==NULL){
		T=new(bstnode);
		T->data=k;
		T->lchild=NULL;T->rchild=NULL;
	}
	else{
		if(k<T->data)
		T->lchild=Insert(T->lchild,k);
		else if(k>T->data)
		T->rchild=Insert(T->rchild,k);
		else
		cout<<"Duplicate is entered.\n";
	}
	return T;
}
void inorder(BSTPTR B,stack &s)
{
	
	if(B!=NULL){
		inorder(B->lchild,s);
		s.push(B->data);
		inorder(B->rchild,s);
	}
}


int main()
{
	stack s1,s2;
		BSTPTR T=NULL;
	T=Insert(T,18);
	T=Insert(T,12);
	T=Insert(T,36);
	T=Insert(T,5);
	T=Insert(T,16);
	T=Insert(T,20);
	T=Insert(T,45);
	T=Insert(T,2);
	T=Insert(T,9);
	T=Insert(T,6);
		BSTPTR T2=NULL;
	T2=Insert(T2,20);
	T2=Insert(T2,16);
	T2=Insert(T2,40);
	T2=Insert(T2,12);
	T2=Insert(T2,36);
	T2=Insert(T2,90);
	T2=Insert(T2,9);
	T2=Insert(T2,13);
	T2=Insert(T2,73);
	inorder(T,s1);inorder(T2,s2);
	cout<<"common nodes are:\n";
	while(s1.top!=-1&&s2.top!=-1){
		if(s1.Top()<s2.Top()) s2.pop();
		else if(s1.Top()>s2.Top()) s1.pop();
		else{
			cout<<s1.Top()<<endl;
			s1.pop();s2.pop();
		}
	}
	return 0;
}
