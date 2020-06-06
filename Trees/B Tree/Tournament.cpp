#include <iostream>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
};
typedef btnode* BTPTR;

int max(int x,int y){
	if(x>y) return x;
	else return y;
}

BTPTR create(BTPTR T,int arr[],int n)
{
	static int i=0,l=3;
	if(T==NULL&&n<=l){
		T=new btnode();
		T->lc=0;T->rc=0;
		if(n==l)
		T->data=arr[i++];
		else{
			T->lc=create(T->lc,arr,n+1);
			T->rc=create(T->rc,arr,n+1);
			T->data=max(T->lc->data,T->rc->data);
		}
	}
	return T;
}

class queue{
	public:
		int size;
		int front;
		int rear;
		BTPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(BTPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		BTPTR dequeue(){
			BTPTR t;
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
		
		BTPTR Front(){
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

void printlevelorder(BTPTR T)
{
	queue q;
	q.enqueue(T);
	BTPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		BTPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			cout<<P->data<<"  ";
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}
int main()
{
	int arr[]={6,3,9,2,7,5,2,8},n=sizeof(arr)/sizeof(arr[0]);
	BTPTR T=0;
	T=create(T,arr,0);
	cout<<"Print level order\n";
	printlevelorder(T);
}

