#include <iostream>
using namespace std;

struct tnode{
	char data;
	tnode* fc;
	tnode* ns;
	int received;
	int x;
};
typedef tnode* TPTR;

typedef
struct lnode{
	TPTR data;
	lnode *next;	
}* LPTR;

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
int no_child(TPTR T)
{
	if(T->fc){
		T=T->fc;
		int c=0;
		while(T){
			c++;T=T->ns;
		}
		return c;
	}return 0;
}
int maxnochild_des(TPTR T)
{
	int max=no_child(T);
	T=T->fc;
	while(T){
		if(maxnochild_des(T)>max)
		max=maxnochild_des(T);
		T=T->ns;
	}
	return max;
}
void addend(LPTR &L,TPTR T)
{
	if(L==0){
		L=new lnode();
		L->data=T;L->next=0;
	}
	else
	addend(L->next,T);
}
void del(LPTR &L,TPTR T)
{
	if(L->data==T){
		LPTR temp=L;
		L=L->next;delete(temp);
		return;	
	}
	del(L->next,T);
}
void pr(LPTR L)
{
	if(L){
		cout<<L->data->data<<" ";
		pr(L->next);
	}else cout<<"\n";
}
void signal(LPTR &L,int &time)
{
	if(L){
		cout<<"------------time="<<time<<"----------"<<endl;
		pr(L);
		LPTR L1=L;int g=0;
		while(L1&&L1->data->received){
		//	cout<<L1->data->data<<"--\n";
			TPTR T=L1->data->fc,loc;
			int cou=0,flag=0;
			while(T){
				if(!T->received){
					if((maxnochild_des(T)+height(T,0))>=cou){
						cou=maxnochild_des(T)+height(T,0)-1;
						loc=T;flag=1;
					}
				}
				T=T->ns;
			}
			if(flag){
				cout<<L1->data->data<<"-"<<loc->data<<endl;
				addend(L,loc);
				L1=L1->next;g=1;
			}
			else{
			//	cout<<"deleting="<<L1->data->data<<endl;
				LPTR temp=L1->next;
				del(L,L1->data);
				L1=temp;
			}
		}
		while(L1){
			L1->data->received=1;
			L1=L1->next;
		}
		if(g)
		time++;
		signal(L,time);
	}	
}
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
		T->data=x;T->fc=0;T->ns=0;T->received=0;
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

int main()
{
	char x;TPTR T=0;
	cout<<"Enter the root value('.' if null)\n";
	cin>>x;
	if(x!='.')create(T,x);
	print(T);
	cout<<"height="<<height(T,0)<<endl;
//	v_print(T);
	
	int time=0;
	LPTR L=0;addend(L,T);T->received=1;
	signal(L,time);
	cout<<"Time taken="<<time<<endl;
}
//ABI.K..ML.CR.SI...D..J.PN.G....
//AB.C.DE.FGH......
