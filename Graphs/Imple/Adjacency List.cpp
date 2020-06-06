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
int cycle(GPTR G,GPTR V,char p,int flag)
{
	if(V){
		GPTR G1=G;
		while(G1->data!=p)G1=G1->dlink;
		addlist(L,G1->data);
		ADPTR T=G1->next;
		while(T){
			if(!chklist(L,T->data,0)){
				if(T->data==V->data||cycle(G,V,T->data,1))
				return 1;
			}
			T=T->next;
		}delendlist(L);
		if(flag==0){
			return cycle(G,V->dlink,V->dlink?V->dlink->data:'0',0);
		}
	}
	return 0;
}

int chkpath(GPTR G,char c,GPTR D)
{
	GPTR G1=G;
	while(G1->data!=c)G1=G1->dlink;
	addlist(L,G1->data);
//	printlist(L);cout<<endl;
	ADPTR T=G1->next;
	while(T){
		if(!chklist(L,T->data,1)){
			if(T->data==D->data||chkpath(G,T->data,D))
			return 1;
		}
		T=T->next;
	}delendlist(L);
//	printlist(L);cout<<endl;
	return 0;
}

int strongly_conn(GPTR G)
{
	if(G){
		GPTR G1=G;
		while(G1){
			GPTR T=G;
			while(T){
			//	cout<<"G1="<<G1->data<<" T="<<T->data<<endl;
			//	cout<<"t\n";
				if(T!=G1)
				if(!chkpath(G,G1->data,T)) return 0;
				T=T->dlink;
				while(L!=0)delendlist(L);
			//	printlist(L);cout<<endl;
			}
			//cout<<"---\n";
			G1=G1->dlink;
		}
	}
	return 1;
}

void print_paths(GPTR G,char c1,char c2,queue q)
{
	GPTR G1=G;
	while(G1->data!=c1)G1=G1->dlink;
	q.enqueue(c1);addlist(L,c1);
	ADPTR T=G1->next;
	while(T){
		if(T->data==c2){
			queue q2;
			while(!q.isempty()){
				cout<<q.Front()<<"  ";
				q2.enqueue(q.dequeue());
			}cout<<c2<<endl;
			while(!q2.isempty())
			q.enqueue(q2.dequeue());
		}
		else if(!chklist(L,T->data,1))
		print_paths(G,T->data,c2,q);
		T=T->next;
	}delendlist(L);
}

void allpaths(GPTR G)
{
		if(G){
		GPTR G1=G;
		while(G1){
			GPTR T=G;
			while(T){
				if(T!=G1)
				{
					queue q;cout<<"From "<<G1->data<<" to "<<T->data<<endl;
					print_paths(G,G1->data,T->data,q);
				}
				T=T->dlink;
			}
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
//	queue q;
	allpaths(G);
	strongly_conn(G)?cout<<"Strongly connected\n":cout<<"Not Strongly connected\n";
	cycle(G,G,G->data,0)?cout<<"Cyclic\n":cout<<"Acyclic\n";
}
//a b c d 0 b a c e 0 c a b d 0 d a c e 0 e b d 0 0
