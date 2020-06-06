#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
	btnode* adj;
};
typedef btnode* BTPTR;
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
void levellinks(BTPTR T,BTPTR F[])
{
	queue q;
	q.enqueue(T);
	BTPTR L=NULL;
	q.enqueue(L);
	int i=0;
	F[i++]=T;
	while(!q.isempty())
	{
		BTPTR P=q.dequeue();
		if(P==NULL){
			//cout<<endl;
			if(!q.isempty())
			{
				q.enqueue(P);
				F[i++]=q.Front();
			}
		}
		else{
			P->adj=q.Front();
			//cout<<P->data<<"  ";
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}
int height(BTPTR P)
{
	if(P==NULL)
	return -1;
	else
	return max(height(P->lc),height(P->rc))+1;
}

int main()
{
	cout<<"Enter the preorder string\n";
	char a[25];
	cin>>a;
	BTPTR T=NULL,F[10],P;int i=0,h;
	create(T,a,i);
	h=height(T);
	cout<<"Height of tree= "<<h<<endl;
	levellinks(T,F);
	//for(int j=0;j<=h;j++)
	//cout<<F[j]->data<<"  ";cout<<endl;
	cout<<"Enter the level number to display links.\n";int n;
	cin>>n;	
	P=F[n];
	while(P!=NULL){
		cout<<P->data<<"  ";
		P=P->adj;
	}	cout<<endl;
}
//amb..df...j.rh..n..
