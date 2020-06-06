#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode* BSTPTR;


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
void printpreorder(BSTPTR B)
{
	if(B!=NULL){
		cout<<B->data<<"  ";
		printpreorder(B->lchild);
		printpreorder(B->rchild);
	}
}
void printpostorder(BSTPTR B)
{
	if(B!=NULL){
		printpostorder(B->lchild);
		printpostorder(B->rchild);
		cout<<B->data<<"  ";
	}
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
	if(top==-1)
	return 1;
	else return 0;
}
};
void printlevelorder(BSTPTR T)
{
	queue q;
	q.enqueue(T);
	BSTPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		BSTPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			cout<<P->data<<"  ";
			if(P->lchild!=NULL) q.enqueue(P->lchild);
			if(P->rchild!=NULL) q.enqueue(P->rchild);
		}
	}
}
void printlevelorderzigdown(BSTPTR T)
{
	stack s,s1;
	BSTPTR L=NULL;
	int i=0;
	s.push(L);s.push(T);
	while(!s.isEmpty()||!s1.isEmpty())
	{
		if(i%2==0){
			while(!s.isEmpty()){
				BSTPTR P=s.pop();
				if(s1.isEmpty()&&!s.isEmpty()) s1.push(L);
				if(P==NULL){
					cout<<endl;i++;
				}else{
					cout<<P->data<<"  ";
					if(P->rchild!=NULL) s1.push(P->rchild);
					if(P->lchild!=NULL) s1.push(P->lchild);
				}
			}
		}
		else{
			while(!s1.isEmpty()){
				BSTPTR P=s1.pop();
				if(s.isEmpty()&&!s1.isEmpty()) s.push(L);
				if(P==NULL){
					cout<<endl;i++;
				}else{
					cout<<P->data<<"  ";
					if(P->rchild!=NULL) s.push(P->rchild);
					if(P->lchild!=NULL) s.push(P->lchild);
				}
			}			
		}
	}
}
void printrev(BSTPTR P)
{
	queue q;stack s;
	q.enqueue(P);
	BSTPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		BSTPTR P=q.dequeue();
		if(P==NULL){
			if(!q.isempty())
			q.enqueue(P);
			s.push(P);
		}
		else{
			if(P->rchild!=NULL) q.enqueue(P->rchild);
			if(P->lchild!=NULL) q.enqueue(P->lchild);
			s.push(P);
		}
	}
	while(s.top!=-1){
		P=s.pop();
		if(P==NULL)cout<<endl;
		else
		cout<<P->data<<"  ";
	}
}
int maxv(BSTPTR P)
{
	if(P->rchild==NULL)
	return P->data;
	else
	return maxv(P->rchild);
}
int minv(BSTPTR P)
{
	if(P->lchild==NULL)
	return P->data;
	else
	return minv(P->lchild);
}
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
	return max(height(P->lchild),height(P->rchild))+1;
}
int search(BSTPTR P,int x)
{
	if(P!=NULL){
		if(P->data==x)return 1;
		else if(x<P->data)return search(P->lchild,x);
		else return search(P->rchild,x);
	}else
	return 0;
}
int checkbst(BSTPTR P)
{
	if(P!=NULL){
		
	}
}
int numleaves(BSTPTR P)
{
	if(P!=NULL){
		if(P->lchild==NULL&&P->rchild==NULL){
			return 1;
		}else{
			return numleaves(P->lchild)+numleaves(P->rchild);
		}
	}else{
		return 0;
	}
}
int numnonleaves(BSTPTR P)
{
	if(P!=NULL){
		if(P->lchild==NULL&&P->rchild==NULL)
		return 0;
		else
		return 1+numnonleaves(P->lchild)+numnonleaves(P->rchild);
	}else{
		return 0;
	}
}
int totalnodes(BSTPTR P)
{
	if(P!=NULL)
	return 1+totalnodes(P->lchild)+totalnodes(P->rchild);
	else
	return 0;
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
	cout<<"Inorder\n";
	printinorder(T);
	cout<<"\nPreorder\n";
	printpreorder(T);
	cout<<"\nPostorder\n";
	printpostorder(T);
	cout<<"\nPrint levelorder\n";
	printlevelorder(T);
	cout<<"\nPrint levelorder zigzag.\n";
	printlevelorderzigdown(T);
	cout<<"\n Print level reverse\n";
	printrev(T);
	int h=height(T);
	cout<<"\nHeight = "<<h<<endl;
	cout<<"Max = "<<maxv(T)<<endl;
	cout<<"Min = "<<minv(T)<<endl;
	int f=search(T,4),nleaves=numleaves(T),nnonleaves=numnonleaves(T);
	f?cout<<"found number\n":cout<<"Not found\n";
	cout<<"N. of leaves = "<<nleaves<<endl;
	cout<<"N. of non leaf nodes = "<<nnonleaves<<endl;
	int totaln=totalnodes(T);
	cout<<"Total no. of nodes = "<<totaln<<endl;
	
	return 0;
}
