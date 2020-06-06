//using LL is correct
#include <iostream>
using namespace std;

struct hcnode{
	hcnode* lc;
	char c;
	int i;
	hcnode* rc;
	int x;
};
typedef hcnode* HPTR;
class queue{
	public:
		int size;
		int front;
		int rear;
		HPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(HPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		HPTR dequeue(){
			HPTR t;
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
		
		HPTR Front(){
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

void inorder(HPTR B)
{
	
	if(B!=NULL){
		static int i=1;
		inorder(B->lc);
		B->x=i++;
		inorder(B->rc);
	}
}
void printtree(HPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	HPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		HPTR P=q.dequeue();
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
			cout<<P->c;prev=P->x;
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}
class stack{
	public:
	int size;
	int top;
	HPTR elements[50];
	stack(){
		top=-1;size=50;
	}	
	void push(HPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	HPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	HPTR Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
	int isEmpty(){
		if(top==-1)return 1;
		else return 0;
	}
};
void swap(HPTR &x,HPTR &y)
{
	HPTR t=x;x=y;y=t;
}
HPTR createtree(HPTR H[],int n)
{
	stack s;
	for(int i=n-1;i>=0;i--){
		s.push(H[i]);
		//cout<<H[i]->c<<endl;
	}
	while(s.top!=0){
		HPTR t1=s.pop(),t2=s.pop(),t=new(hcnode);
		t->lc=NULL;t->rc=NULL;t->c='*';
		t->i=t1->i+t2->i;
		if(t1->i<=t2->i){
			t->lc=t1;t->rc=t2;
		}
		else{
			t->lc=t2;t->rc=t1;
		}
		s.push(t);
	}
	return s.pop();
}
void displaybinary(HPTR T,char side,int c)
{
	if(T!=NULL){
		if(side=='l'){
			c=c*10;
			if(T->c!='*'){
				cout<<T->c<<"="<<c<<endl;
			}
		}
		else if(side=='r'){
			c=c*10+1;
			if(T->c!='*'){
				cout<<T->c<<"="<<c<<endl;
			}
		}
		displaybinary(T->lc,'l',c);
		displaybinary(T->rc,'r',c);
	}
}
int main()
{
	cout<<"Enter the number of characters.\n";
	int i,n,f,flag=0;
	cin>>n;
	HPTR H[n];
	cout<<"Enter the char and their freq\n";
	for(i=0;i<n;i++){
		H[i]=new(hcnode);
		H[i]->lc=NULL;H[i]->rc=NULL;
		cin>>H[i]->c;cin>>H[i]->i;
		cout<<"Next value\n";
	}
	//sorting
	for(int pass=1;pass<=n-1;pass++){
		flag=0;
		for(i=0;i<n-pass;i++){
			if(H[i]->i>H[i+1]->i){
				swap(H[i],H[i+1]);
				flag=1;
			}
		}
		if(flag==0)break;
	}
	HPTR root=NULL;
	root=createtree(H,n);
	printtree(root);cout<<"\n";
	displaybinary(root,'o',0);
}
//7t15a3m30j10k40p2s20
