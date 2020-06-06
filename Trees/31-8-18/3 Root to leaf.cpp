#include <iostream>
using namespace std;

struct bstnode{
	bstnode *lchild;
	int data;
	int sum;
	bstnode *rchild;
};
typedef bstnode* BSTPTR;
struct queue{
	public:
		int size;
		int front;
		int rear;
		int elements[50];
		queue(){
			front=-1;rear=-1;size=50;
		}
		void enqueue(int x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}		
		int dequeue(){
			int t;
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
		int Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isEmpty(){
			if(front==-1)return 1;
			else return 0;
		}
};
BSTPTR Insert(BSTPTR T,int k,int s,int &max)
{
	if(T==NULL){
		T=new(bstnode);
		T->data=k;
		T->lchild=NULL;T->rchild=NULL;
		s+=k;
		T->sum=s;
		if(s > max)max=s;
	}
	else{
		if(k<T->data){
			s+=T->data;
			T->lchild=Insert(T->lchild,k,s,max);
		}		
		else if(k>T->data){
			s+=T->data;
			T->rchild=Insert(T->rchild,k,s,max);
		}		
		else
		cout<<"Duplicate is entered.\n";
	}
	return T;
}

BSTPTR search(BSTPTR P,int x)
{
	if(P!=NULL){
		if(P->data==x)return P;
		else if(x<P->data)return search(P->lchild,x);
		else return search(P->rchild,x);
	}else
	return NULL;
}
void printinorder(BSTPTR B)
{
	if(B!=NULL){
		printinorder(B->lchild);
		cout<<B->data<<"  ";
		printinorder(B->rchild);
	}
}
void pathFinder(BSTPTR m,int req,struct queue q,bool &b)
{
	if(m!=NULL){
		q.enqueue(m->data);
		if (m->data == req)
		{
			cout << "The required path is\n";
			while (!q.isEmpty())
			{
				cout << q.dequeue() << " ";
			}
			b = true;
			return;
		}
		if (b == false)
		{
			if (m == NULL)
			{
				return;
			}
			else
			{
					pathFinder(m->lchild, req, q, b);
					if (b == true)
					{
						return;
					}
					pathFinder(m->rchild, req, q, b);
					if (b == true)
					{
						return;
					}			
				
			}
		}
	}

}

int main()
{
	int max=0;
		BSTPTR T=NULL;
	T=Insert(T,18,0,max);
	T=Insert(T,12,0,max);
	T=Insert(T,36,0,max);
	T=Insert(T,5,0,max);
	T=Insert(T,16,0,max);
	T=Insert(T,20,0,max);
	T=Insert(T,45,0,max);
	T=Insert(T,2,0,max);
	T=Insert(T,9,0,max);
	T=Insert(T,6,0,max);
	cout<<"The nodes are\n";
	printinorder(T);cout<<endl;
	cout<<"Max value from root to node="<<max<<endl;
	cout<<"Enter the node value to know the sum from root(-1 to end)\n";
	int n=0,f=0 ;
	while(n!=-1){
		cin>>n;
		if(n==-1)break;
		BSTPTR S=search(T,n);
		if(S==NULL){
			cout<<"Node not found\n";continue;
		}
		cout<<"Sum from root to node = "<<S->sum<<endl; 
		
	}
	queue q;bool b=false;
	cout<<"Enter path to find(-1 to terminate)=";
	while(f!=-1){
		cin>>f;
		if(f==-1)break;
		pathFinder(T,f,q,b);cout<<endl;
		if(b==false)cout<<"Node not found\n";
		b=false;
	}
	cout<<"Done\n";
}
