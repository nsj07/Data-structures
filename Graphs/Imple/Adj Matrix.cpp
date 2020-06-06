#include <iostream>
using namespace std;

typedef
struct lnode{
	int data;
	lnode* next;
}* LPTR;

class queue{
	public:
		int size;
		int front;
		int rear;
		int elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(int x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		int dequeue(){
			int t;
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
		
		int Front(){
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
LPTR L=0;
int degree(bool G[][5],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[v][i])c++;
	return c;
}
int indegree(bool G[][5],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[i][v])c++;
	return c;	
}
int outdegree(bool G[][5],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[v][i])c++;
	return c;	
}
void addlist(LPTR &T,int c)
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
int chklist(LPTR T,int c,int l)
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

int cycle(bool G[][5],int n,int v,int p,int flag)
{
	if(v<n){
		addlist(L,p);
		for(int i=0;i<n;i++){
			if(G[p][i]){
				if(!chklist(L,i,0))
				if(i==v||cycle(G,n,v,i,1)) 
				return 1;
			}
		}
		delendlist(L);
		if(flag==0){
			while(L!=0)delendlist(L);
			return cycle(G,n,v+1,v+1,0);
		}
	}
	return 0;
}

void print_allcycles(bool G[][5],int n,int v,int p,int flag,queue q)
{
	if(v<n){
		if(p==0&&flag==0)cout<<"Cycles from "<<v+1<<":\n";
		addlist(L,p);
		q.enqueue(p);
		for(int i=0;i<n;i++){
			if(G[p][i]){
				if(i==v){
					queue q2;
					while(!q.isempty()){
						cout<<q.Front()+1<<"  ";
						q2.enqueue(q.dequeue());
					}cout<<i+1<<endl;
					while(!q2.isempty()) q.enqueue(q2.dequeue());
				}
				else if(!chklist(L,i,0)){
					print_allcycles(G,n,v,i,1,q);
				}
			}
		}
		delendlist(L);
		if(flag==0){
			while(L!=0)delendlist(L);
			while(!q.isempty()) q.dequeue();
			cout<<"---------\n";
			if(v+2<=n)
			cout<<"Cycles from "<<v+2<<":\n";
			print_allcycles(G,n,v+1,v+1,0,q);
		}
	}
}

void print_paths(bool G[][5],int n,int p,int t,queue q)
{
		addlist(L,p);
		q.enqueue(p);
		for(int i=0;i<n;i++){
			if(G[p][i]){
				if(i==t){
					queue q2;
					while(!q.isempty()){
						cout<<q.Front()+1<<"  ";
						q2.enqueue(q.dequeue());
					}cout<<i+1<<endl;
					while(!q2.isempty()) q.enqueue(q2.dequeue());
				}
				else if(!chklist(L,i,1)){
					print_paths(G,n,i,t,q);
				}
			}
		}
		delendlist(L);
}
void allpaths(bool G[][5],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			queue q;
			if(i!=j){
				cout<<"Paths from "<<i+1<<" to "<<j+1<<":\n";
				print_paths(G,n,i,j,q);
			}
		}
	}
}

int symmetric(bool G[][5],int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++)
		if(G[i][j]!=G[j][i])
		return 0;
	}
	return 1;
}
int main()
{
/*	bool G[][5]={{0,1,1,1,0},
				{1,0,1,0,1},
				{1,1,0,1,0},
				{1,0,1,0,1},
				{0,1,0,1,0},
				};*/
	bool G[][5]={{0,1,0,1,0},
				{0,0,1,0,1},
				{1,0,0,1,0},
				{0,0,0,0,1},
				{0,0,0,0,0},
				};
/*	bool G[][5]={{0,1,0,0,0},
				{0,0,0,0,1},
				{0,1,0,0,1},
				{0,0,1,0,0},
				{0,0,0,1,0},
				};*/			
				
	int i,n=5,v;
	for(i=0;i<n;i++)
	cout<<"Degree of "<<i+1<<" = "<<degree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"InDegree of "<<i+1<<" = "<<indegree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"OutDegree of "<<i+1<<" = "<<outdegree(G,i,n)<<endl;
	allpaths(G,n);
	if(!symmetric(G,n)){
		cycle(G,n,0,0,0)?cout<<"Cyclic\n":cout<<"Acyclic\n";
		cout<<"Cyles are:\n";
		queue q;
		print_allcycles(G,n,0,0,0,q);
	}
	else
	cout<<"It's Undirected graph\n";
}
