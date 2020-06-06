#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
	int x;
};
typedef btnode* BTPTR;
static int i=1;
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

void inorder(BTPTR B)
{
	
	if(B!=NULL){
		inorder(B->lc);
		B->x=i++;
		inorder(B->rc);
	}
}
void printtree(BTPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	BTPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		BTPTR P=q.dequeue();
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
void printinorder(BTPTR B)
{
	if(B!=NULL){
		printinorder(B->lc);
		cout<<B->data<<"  ";
		printinorder(B->rc);
	}
}
BTPTR invert(BTPTR T)
{
	if(T!=NULL){
		BTPTR temp=T->lc;
		T->lc=T->rc;
		T->rc=temp;
		invert(T->lc);invert(T->rc);
	}
	return T;
}
int main(){
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR B=NULL,M=NULL;int i=0;
	create(B,a,i);
	BTPTR T=B;
	printinorder(B);cout<<"\nSerialising=\n";
	serialize(B);cout<<endl;
	printtree(B);cout<<endl;
	M=invert(T);
	//printtree(B);cout<<endl;
	i=1;
	//serialize(T);cout<<endl;	
	//serialize(M);cout<<endl;
	printtree(M);cout<<endl;
}
//amb..df...j.rh..n..
