#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lchild;
	int data;
	bstnode *rchild;
	int x;
};
typedef bstnode* BSTPTR;
BSTPTR root=NULL;
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
void printinorder(BSTPTR B)
{
	if(B!=NULL){
		printinorder(B->lchild);
		cout<<B->data<<"  ";
		printinorder(B->rchild);
	}
}
BSTPTR createBST(BSTPTR T,int a[],int l,int h)
{
	if(l<=h){
		int mid=(l+h+1)/2;
		//cout<<l<<"..."<<h<<"....."<<a[mid]<<endl;
		T=Insert(T,a[mid]);
		T=createBST(T,a,l,mid-1);
		T=createBST(T,a,mid+1,h);
	}	
	return T;
}
int main()
{
	int a[20]={1,2,3,4,5,6,7,8,9};
	root=createBST(root,a,0,8);
	printinorder(root);
	cout<<endl;
	printtree(root);
	return 0;
}
