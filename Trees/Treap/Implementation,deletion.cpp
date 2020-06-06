#include <iostream>
using namespace std;

struct trpnode{
	trpnode* lc;
	char k1;
	int k2;
	trpnode* rc;
};
typedef trpnode* BTPTR;

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
	int isEmpty(){
		if(top==-1)return 1;
		else return 0;
	}
};
int min(int x,int y)
{
	if(x<y)
	return x;
	else return y;
}
int chktrp(BTPTR T)
{
	if(T!=0){
		if(T->lc!=0){
			if(T->k1<T->lc->k1)
			return 0;
			if(T->k2>T->lc->k2)
			return 0;
		}
		if(T->rc!=0){
			if(T->k1>T->rc->k1)
			return 0;
			if(T->k2>T->rc->k2)
			return 0;
		}
		return min(chktrp(T->lc),chktrp(T->rc));
	}
	return 1;
}
BTPTR create(BTPTR T,char k1,int k2,stack &s)
{
	if(T==0){
		T=new trpnode();
		T->k1=k1;T->k2=k2;
		T->lc=0;T->rc=0;
	}
	else{
		if(k1<T->k1)
		T->lc=create(T->lc,k1,k2,s);
		else if(k1>T->k1)
		T->rc=create(T->rc,k1,k2,s);
		else
		cout<<"Duplicate \n";
	}
	s.push(T);
	int f=chktrp(T);
	if(!f){
		BTPTR t1=s.pop(),t2=s.pop();
		if(t1->k1<t2->k1){
			t1->rc=t2->lc;
			t2->lc=t1;
		}
		else{
			t1->lc=t2->rc;
			t2->rc=t1;
		}
		s.push(t2);
		return t2;
	}
	return T;
}

BTPTR del(BTPTR T,char k1)
{
	if(T!=0){
		if(T->k1==k1){
			BTPTR P;char l1;int l2;
			if(T->lc==0&&T->rc==0){
				delete(T);return 0;
			}
			else if(T->lc==0){
				l1=T->k1;l2=T->k2;
				T->k1=T->rc->k1;T->k2=T->rc->k2;
				T->rc->k1=l1;T->rc->k2=l2;
				T->rc=del(T->rc,l1);
			}
			else if(T->rc==0){
				l1=T->k1;l2=T->k2;
				T->k1=T->lc->k1;T->k2=T->lc->k2;
				T->lc->k1=l1;T->lc->k2=l2;
				T->lc=del(T->lc,l1);				
			}
			else{
				if(T->rc->k2<T->lc->k2){
					l1=T->k1;l2=T->k2;
					T->k1=T->rc->k1;T->k2=T->rc->k2;
					T->rc->k1=l1;T->rc->k2=l2;
					T->rc=del(T->rc,l1);
				}
				else{
					l1=T->k1;l2=T->k2;
					T->k1=T->lc->k1;T->k2=T->lc->k2;
					T->lc->k1=l1;T->lc->k2=l2;
					T->lc=del(T->lc,l1);
				}
			}
		}
		else{
			if(k1<T->k1)
			T->lc=del(T->lc,k1);
			else
			T->rc=del(T->rc,k1);
		}
	}
	return T;
}
void preorder(BTPTR T)
{
	if(T!=0){
		cout<<T->k1<<","<<T->k2<<"  ";
		preorder(T->lc);
		preorder(T->rc);
	}
}
int main()
{
	BTPTR T=0;
	stack s;
	cout<<"Enter k1 and k2(k1=0 to end)\n";
	char k1;int k2;
	cin>>k1>>k2;
	while(k1!='0'){
		T=create(T,k1,k2,s);
		while(!s.isEmpty())
		s.pop();
		cin>>k1;
		if(k1=='0')break;
		cin>>k2;
	}
	preorder(T);
	cout<<"\nEnter k1 to delete=";cin>>k1;
	T=del(T,k1);
	preorder(T);
	
}
