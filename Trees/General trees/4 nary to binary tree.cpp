#include <iostream>
using namespace std;

typedef
struct nary{
	int data;
	int count;
	nary *ptr[10];
}* NPTR;

void create(NPTR T,int x,int c)
{
	T->data=x;T->count=c;int i;
	for(i=0;i<c;i++) T->ptr[i]=0;
	for(i=0;i<T->count;i++){
		cout<<"Entering "<<i+1<<" link of node "<<T->data<<endl;
		cin>>x>>c;
		T->ptr[i]=new nary();
		create(T->ptr[i],x,c);
	}
}

class queue{
	public:
		int size;
		int front;
		int rear;
		NPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(NPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		NPTR dequeue(){
			NPTR t;
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
		
		NPTR Front(){
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

void print(NPTR T)
{
	queue q;
	q.enqueue(T);
	NPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		NPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			cout<<P->data<<"  ";
			int i;
			for(i=0;i<P->count;i++){
				if(P->ptr[i]){
					q.enqueue(P->ptr[i]);
				}
			}
		}
	}
}

void printgt(NPTR T)
{
	queue q;
	q.enqueue(T);
	NPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		NPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			cout<<P->data<<"  ";
			if(P->ptr[0]!=0){
				P=P->ptr[0];
				while(P){
					q.enqueue(P);P=P->ptr[1];
				}
			}
		}
	}
}
void convert(NPTR &T)
{
	if(T->ptr[0])convert(T->ptr[0]);
	for(int i=0;i<T->count-1;i++){
		T->ptr[i]->ptr[1]=T->ptr[i+1];
		convert(T->ptr[i+1]);
	}
	T->ptr[1]=0;
}
void preordernary(NPTR T){
	if(T){
		cout<<T->data<<" ";
		int i;
		for(i=0;i<T->count;i++)
		preordernary(T->ptr[i]);
	}
}
void preorder(NPTR T){
	if(T){
		cout<<T->data<<" ";
		preorder(T->ptr[0]);
		preorder(T->ptr[1]);
	}
}
void inorder(NPTR T){
	if(T){
		inorder(T->ptr[0]);
		cout<<T->data<<" ";
		inorder(T->ptr[1]);
	}
}
void postordernary(NPTR T)
{
	if(T){
		int i;
		for(i=0;i<T->count;i++)
		postordernary(T->ptr[i]);
		cout<<T->data<<" ";
	}
}

int main()
{
	NPTR T=0;
	T=new nary();
	int x,c;
	cout<<"Enter node value and no.of children(0 if no children)\n";
	cin>>x>>c;
	create(T,x,c);
	print(T);
	cout<<"Preorder nary:";preordernary(T);cout<<"\n";
	cout<<"Postorder nary:";postordernary(T);cout<<"\n";
	convert(T);
	printgt(T);
	cout<<"Preorder binarytree:";preorder(T);cout<<"\n";
	cout<<"Inorder binarytree:";inorder(T);cout<<"\n";
	
}
//1 4 2 2 6 0 7 0 3 1 8 0 4 0 5 3 9 0 10 0 11 0
