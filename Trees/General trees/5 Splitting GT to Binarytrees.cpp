#include <iostream>
using namespace std;

struct gtnode{
	char data;
	gtnode* fc;
	gtnode* ns;
	int done;
	
};
typedef gtnode* GPTR;
typedef
struct btnode{
	btnode* lc;
	char data;
	btnode* rc;
	int x;
}* BTPTR;

void create(GPTR &T,char x)
{
	if(T==0){
		T=new gtnode();
		T->data=x;T->fc=0;T->ns=0;T->done=0;
		cout<<"Enter first child of "<<T->data<<endl;
		cin>>x;
		if(x!='.')create(T->fc,x);
		cout<<"Enter siblings of "<<T->data<<endl;
		cin>>x;
		if(x!='.')create(T->ns,x);
	}
}

class queue{
	public:
		int size;
		int front;
		int rear;
		GPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(GPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		GPTR dequeue(){
			GPTR t;
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
		
		GPTR Front(){
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

void print(GPTR T)
{
	queue q;
	q.enqueue(T);
	GPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		GPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			cout<<P->data<<"  ";
			if(P->fc!=0){
				P=P->fc;
				while(P){
					q.enqueue(P);P=P->ns;
				}
			}
		}
	}
}

GPTR onechild(GPTR G)
{
	G=G->fc;
	if(G){
		while(G&&G->done)G=G->ns;
	}
	return G;
}
GPTR anotherchild(GPTR G,GPTR temp)
{
	G=G->fc;
	if(G){
		if(G==temp)G=G->ns;
		while(G&&G->done){
			G=G->ns;
			if(G==temp)G=G->ns;
		}
	}
	return G;
}
int allchilddone(GPTR G)
{
	G=G->fc;
	if(G){
		while(G){
			if(!G->done)return 0;
			G=G->ns;
		}
	}
	return 1;
}
BTPTR split(GPTR G,BTPTR T)
{
	if(T==0&&G){
		T=new btnode();
		T->data=G->data;T->lc=0;T->rc=0;
		GPTR temp=onechild(G);
		T->lc=split(temp,T->lc);
		T->rc=split(anotherchild(G,temp),T->rc);
		if(allchilddone(G))
		G->done=1;
	}
	return T;
}

class btqueue{
	public:
		int size;
		int front;
		int rear;
		BTPTR elements[50];
		
		btqueue(){
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
static int z=1;
void inorder(BTPTR B)
{
	
	if(B!=NULL){
		inorder(B->lc);
		B->x=z++;
		inorder(B->rc);
	}
}
void printtree(BTPTR T)
{
	inorder(T);
	btqueue q;
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
int main()
{
	char x;GPTR G=0;
	cout<<"Enter the root value('.' if null)\n";
	cin>>x;
	if(x!='.')create(G,x);
	print(G);
	BTPTR T[10];
	int i,c=0;
	for(i=0;i<10;i++)T[i]=0;
	while(!G->done){
		T[c]=split(G,T[c]);
		c++;
	}
	for(i=0;i<c;i++){
		cout<<"--------Tree "<<i+1<<"------------\n";
		printtree(T[i]);cout<<endl;
		z=1;
	}
}
//ABF.G.H.I..C.DJKN.L.M....EO.PR.S.T..Q....
