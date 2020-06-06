#include <iostream>
using namespace std;

class queue{
	public:
		int size;
		int front;
		int rear;
		char elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(char x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		char dequeue(){
			char t;
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
		
		char Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isempty(){
			if(front==-1)return 1;
			else return 0;
		}
};
typedef
struct gnode{
	char data;
	gnode* dlink;
	struct adnode* next;
}* GPTR;

typedef
struct adnode{
	char data;
	adnode* next;
}* ADPTR;

typedef
struct lnode{
	char data;
	lnode* next;
}* LPTR;
LPTR L=0;
void Insertadj(ADPTR &T)
{
	char c;
	cin>>c;
	if(c!='0'){
		T=new adnode();
		T->data=c;T->next=0;
		Insertadj(T->next);
	}
}
void create(GPTR &G,char c)
{
	if(G==0){
		G=new gnode();
		G->data=c;G->dlink=0;G->next=0;
		cout<<"Enter all the nodes adj to "<<c<<" (0 to terminate)\n";
		Insertadj(G->next);
	}
	else{
		create(G->dlink,c);
	}
}

void print(GPTR G)
{
	if(G){
		cout<<G->data<<" -> ";
		ADPTR T=G->next;
		while(T){
			cout<<T->data<<"  ";T=T->next;
		}
		cout<<endl;
		print(G->dlink);
	}
}
void addlist(LPTR &T,char c)
{
	if(T==0){
		T=new lnode();T->data=c;T->next=0;
	}
	else
	addlist(T->next,c);
}
void delendlist(LPTR &T)
{
	if(T){
		LPTR X=T,Y=T;
		while(X->next!=0)X=X->next;
		while(Y->next!=X&&Y->next!=0)Y=Y->next;
		if(X==T)T=0;
		else Y->next=0;
		delete(X);
	}
}
int chklist(LPTR T,char c,int l)
{
	if(l==0){
			if(T){
			T=T->next;
			while(T){
				if(T->data==c)return 1;
				T=T->next;
			}
		}
	}
	if(l==1){
		if(T){
			while(T){
				if(T->data==c)return 1;
				T=T->next;
			}
		}
	}
	return 0;
}
void printlist(LPTR T){
	if(T){
		cout<<T->data<<"  ";
		printlist(T->next);
	}
	else{
		cout<<"------000\n";
	}
}

void BFT(GPTR G,char u,int n)
{
	GPTR G1=G;
	while(G1->data!=u) G1=G1->dlink;
	int count=0,f=0;
	addlist(L,u);
	queue q;
	while(count!=n){
		if(f==0)
		q.enqueue(u);
		else{
			G1=G;
			while(chklist(L,G1->data,1)){
				G1=G1->dlink;
			}
			u=G1->data;
			q.enqueue(u);
		}
		count++;
		while(!q.isempty()){
			f=1;
			u=q.dequeue();cout<<u<<endl;
			G1=G;
			while(G1->data!=u) G1=G1->dlink;
			ADPTR T=G1->next;
			while(T){
					if(!chklist(L,T->data,1)){
						addlist(L,T->data);q.enqueue(T->data);count++;
						cout<<"("<<u<<"->"<<T->data<<")"<<endl;
					}
				T=T->next;
			}
		}
	}
}

void DFT(GPTR G,char u,int f)
{
	GPTR G1=G;addlist(L,u);
	while(G1->data!=u) G1=G1->dlink;
	ADPTR T=G1->next;
	cout<<u<<"  ";
	while(T){
			if(!chklist(L,T->data,1)){
				DFT(G,T->data,1);
			}
		T=T->next;
	}
	if(f==0){
		G1=G;
		while(G1){
			if(!chklist(L,G1->data,1)) DFT(G,G1->data,0);
			G1=G1->dlink;
		}	
	}
}
int main()
{
	GPTR G=0;
	cout<<"Enter the vertices names (0 to end)\n";
	char c;cin>>c;
	while(c!='0'){
		create(G,c);
		cout<<"Enter nxt graph vertex\n";
		cin>>c;
	}
	print(G);
	BFT(G,'a',5);
	while(L!=0)delendlist(L);
	cout<<"DFT:\n";
	DFT(G,'a',0);

}
//a b d 0 b c e 0 c a d 0 d e 0 e 0 0
//a b c 0 b c 0 c 0 d e 0 e 0 0
