#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
	int pos;
};
typedef btnode* BTPTR;
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
void create(BTPTR &T,int k)
{
	if(T==NULL){
		T=new(btnode);
		T->data=k;T->lc=NULL;T->rc=NULL;
	}
	cout<<"Inserting left child of "<<T->data<<" (else type 0)"<<endl;
	int s;cin>>s;
	if(s!=0){
		create(T->lc,s);
	}
	cout<<"Inserting right child of "<<T->data<<" (else type 0)"<<endl;
	cin>>s;
	if(s!=0){
		create(T->rc,s);
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
void assignpos(BTPTR T,int i,char x,int &min,int &max)
{
	if(T!=NULL){
		if(x=='c'){
			T->pos=i;min=i;max=i;
		}
		if(x=='l'){
			T->pos=i-1;i--;
			if(i<min)min=i;
		}
		if(x=='r'){
			T->pos=i+1;i++;
			if(i>max)max=i;
		}
		assignpos(T->lc,i,'l',min,max);
		assignpos(T->rc,i,'r',min,max);
	}
}
void top(BTPTR T,queue q[],int min)
{
	if(T!=NULL){
		q[T->pos-min].enqueue(T);
		top(T->lc,q,min);
		top(T->rc,q,min);
	}
}

int main()
{
	BTPTR T=NULL;
	cout<<"Enter root value.\n";
	int n,min,max;
	queue q[15];
	cin>>n;
	create(T,n);
	assignpos(T,0,'c',min,max);
	top(T,q,min);
	cout<<"Top view nodes are:\n";
	for(int i=0;i<=max-min;i++){
		cout<<q[i].Front()->data<<"  ";
	}cout<<endl;
	
}
