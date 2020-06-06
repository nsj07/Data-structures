#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lchild;
	int data;
	int x;
	bstnode *rchild;
};
typedef bstnode* BSTPTR;
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
		inorder(B->lchild);
		B->x=i++;
		inorder(B->rchild);
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
			cout<<"   ";
			cout<<P->data;prev=P->x;
			if(P->lchild!=NULL) q.enqueue(P->lchild);
			if(P->rchild!=NULL) q.enqueue(P->rchild);
		}
	}
}
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
void inordermove(BSTPTR B,BSTPTR T)
{
	
	if(B!=NULL){
		inordermove(B->lchild,T);
		T=Insert(T,B->data);
		inordermove(B->rchild,T);
	}
}


int main()
{
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
	inordermove(T2,T);
	printtree(T);
	
}
