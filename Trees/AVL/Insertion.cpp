#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lc;
	int data;
	bstnode *rc;
	int x;
};
typedef bstnode* BSTPTR;
class stack{
	public:
	int size;
	int top;
	BSTPTR elements[50];
	stack(){
		top=-1;size=50;
	}	
	void push(BSTPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	BSTPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	BSTPTR Top(){
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
int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}

int height(BSTPTR P)
{
	if(P==NULL)
	return -1;
	else
	return max(height(P->lc),height(P->rc))+1;
}
int checkavl(BSTPTR T)
{
	if(T!=NULL){
		int h1,h2,d;
		h1=height(T->lc);h2=height(T->rc);
		d=h1-h2;
		//cout<<"d====="<<d<<endl;
		if(d==1||d==0||d==-1)
		return 1;
		else return 0;
	}
}
BSTPTR rotation(BSTPTR k3,BSTPTR k1,BSTPTR k2)
{
	
	if(k2->data>k3->data&&k2->data>k1->data){
		k3->rc=k1->lc;k1->lc=k3;
		return k1;
	}
	else if(k2->data<k3->data&&k2->data<k1->data){
		k3->lc=k1->rc;k1->rc=k3;
		return k1;
	}
	else if(k2->data>k3->data&&k2->data<k1->data){
		k3->rc=k2->lc;
		k2->lc=k3;
		k1->lc=k2->rc;
		k2->rc=k1;
		return k2;
	}
	else{
		k3->lc=k2->rc;
		k2->rc=k3;
		k1->rc=k2->lc;
		k2->lc=k1;
		return k2;
	}
}

BSTPTR Insert(BSTPTR T,int k,class stack &s)
{
	if(T==NULL){
		T=new(bstnode);
		T->data=k;
		T->lc=NULL;T->rc=NULL;
	}
	else{
		if(k<T->data)
		T->lc=Insert(T->lc,k,s);
		else if(k>T->data)
		T->rc=Insert(T->rc,k,s);
		else
		cout<<"Duplicate is entered.\n";
	}
	//cout<<"T->data==="<<T->data<<endl;
	s.push(T);
	int c=checkavl(T);
//	cout<<"c="<<c<<endl;
	if(c==0){
		BSTPTR k3=s.pop(),k1=s.pop(),k2=s.pop();
		//cout<<"k3="<<k3->data<<"  k1="<<k1->data<<"  k2="<<k2->data<<endl;
		return rotation(k3,k1,k2);
	}
	return T;
}

class queue{
	public:
		int size;
		int front;
		int rear;
		BSTPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(BSTPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		BSTPTR dequeue(){
			BSTPTR t;
			if(front==-1)cout<<"Empty\n";
			else{
				t=elements[front];
				if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				else front =(front+1)%size;
				return t;
			}
		}
		
		BSTPTR Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isempty(){
			if(front==-1)
			return 1;
			else return 0;
		}
};

void inorder(BSTPTR B)
{
	
	if(B!=NULL){
		static int i=1;
		inorder(B->lc);
		B->x=i++;
		inorder(B->rc);
	}
}
void printtree(BSTPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	BSTPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		BSTPTR P=q.dequeue();
		if(P!=NULL)present=P->x;
		if(P==NULL){
			prev=0;
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			for(int i=1;i<=present-prev;i++)
			cout<<"  ";
			cout<<P->data;prev=P->x;
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}
int main()
{
	cout<<"Enter the values to insert in tree(-1 to end).\n";
	BSTPTR T=NULL,D;stack s;
	int n;cin>>n;
	while(n!=-1)
	{
		T=Insert(T,n,s);
		while(!s.isEmpty())
		D=s.pop();
		cin>>n;
	}
	cout<<"Tree print is:\n";
	printtree(T);
	
}
