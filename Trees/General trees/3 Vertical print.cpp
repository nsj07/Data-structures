#include <iostream>
using namespace std;

struct tnode{
	char data;
	tnode* fc;
	tnode* ns;
	int x;
};

typedef tnode* TPTR;
class stack{
	public:
	int size;
	int top;
	TPTR elements[50];
	stack(){
		top=-1;size=50;
	}
	void push(TPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	TPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	TPTR Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
	int isempty(){
		if(top==-1) return 1;
		else return 0;
	}
};
void create(TPTR &T,char x)
{
	if(T==0){
		T=new tnode();
		T->data=x;T->fc=0;T->ns=0;
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
		TPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(TPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		TPTR dequeue(){
			TPTR t;
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
		
		TPTR Front(){
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

void print(TPTR T)
{
	queue q;
	q.enqueue(T);
	TPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		TPTR P=q.dequeue();
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
int maxof(int x,int y)
{
	return x>y?x:y;
}
int height(TPTR T,int f)
{
	if(T==0&&f==0) return -1;
	else if(T==0&&f==1) return 0;
	return maxof(1+height(T->fc,0),height(T->ns,1));
}
int depth(TPTR T,TPTR X,int d)
{
	if(T){
		if(T==X)return d;
		int fc,ns;
		fc=depth(T->fc,X,d+1);
		ns=depth(T->ns,X,d);
		if(fc!=-1)return fc;
		else return ns;
	}
	return -1;
}
int grandchild(TPTR T)
{
	if(T->fc==0)return 0;
	if(T){
		TPTR G=T->fc;
		while(G){
			if(G->fc!=0)return 1;
			G=G->ns;
		}
	}
}
int child(TPTR T)
{
	return T->fc?1:0;
}
void v_print(TPTR T)
{
	if(T){
		stack s;s.push((T));
		int d,i;
		while(!s.isempty()){
			TPTR G=s.pop();d=depth(T,G,0);
			for(i=0;i<d;i++)cout<<" ";
			cout<<G->data<<endl;
			if(!grandchild(G)&&child(G)){
				for(i=0;i<d+1;i++)cout<<" ";
				G=G->fc;int h=0;
				while(G){
					cout<<G->data;G=G->ns;
					h=1;
				}				
				cout<<endl;
			}
			else{
				stack *s1=new stack();
				G=G->fc;
				while(G){
					s1->push(G);G=G->ns;
				}
				while(!s1->isempty()) s.push(s1->pop());
				delete(s1);
			}
		}
	}
}
int main()
{
	char x;TPTR T=0;
	cout<<"Enter the root value('.' if null)\n";
	cin>>x;
	if(x!='.')create(T,x);
	print(T);
	cout<<"height="<<height(T,0)<<endl;
	v_print(T);
}
//ABI.K..ML.CR.SI...D..J.PN.G....
