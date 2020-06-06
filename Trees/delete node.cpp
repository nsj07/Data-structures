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

BSTPTR search(BSTPTR P,int x,BSTPTR &p)
{
	cout<<"p="<<p->data<<endl;
	if(P!=NULL){
		if(P->data==x)return P;
		else if(x<P->data)return search(P->lchild,x,P);
		else return search(P->rchild,x,P);
	}
	
	else
	return NULL;
}
BSTPTR minv(BSTPTR P)
{
	if(P->lchild==NULL)
	return P;
	else
	return minv(P->lchild);
}
BSTPTR del(BSTPTR P,int n)
{
	if(P==NULL)return NULL;
	else{
		if(n<P->data) P->lchild=del(P->lchild,n);
		else if(n>P->data) P->rchild=del(P->rchild,n);
		else{
			if(P->lchild==NULL&&P->rchild==NULL){
				delete(P);
				return NULL;
			}else if(P->lchild==NULL){
				BSTPTR D=P;
				P=P->rchild;
				delete(D);
			}else if(P->rchild==NULL){
				BSTPTR D=P;
				P=P->lchild;
				delete(D);
			}else{
				BSTPTR temp=minv(P->rchild);
				P->data=temp->data;
				P->rchild=del(P->rchild,temp->data);
			}
		}
		return P;
	}
}
void inorder(BSTPTR B)
{
	static int i=1;
	if(B!=NULL){
		inorder(B->lchild);
		B->x=i++;
		//cout<<B->data<<"  "<<B->x<<endl;
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

int main()
{
	BSTPTR T=NULL;
	T=Insert(T,5);
	T=Insert(T,3);
	T=Insert(T,1);
	T=Insert(T,4);
	T=Insert(T,2);
	T=Insert(T,8);
	T=Insert(T,6);
	T=Insert(T,9);
	T=Insert(T,7);
	printtree(T);
	
	cout<<endl;
	cout<<"enter no. to delete.";
	int n;
	cin>>n;
	T=del(T,n);	
	printtree(T);
}
