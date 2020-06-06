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
void BFT(bool G[][5],int u,int n)
{
	int count=0,f=0,visit[5]={0,0,0,0,0};
	queue q;
	while(count!=n){
		if(f==0)
		q.enqueue(u);
		else{
			int i;
			for(i=0;i<n;i++)
			if(!visit[i])break;
			u=i;
			q.enqueue(u);
		}
		visit[u]=1;
		count++;
		while(!q.isempty()){
			f=1;
			u=q.dequeue();cout<<u+1<<endl;
			for(int i=0;i<n;i++){
				if(G[u][i]){
					if(!visit[i]){
						visit[i]=1;q.enqueue(i);count++;
						cout<<"("<<u+1<<"->"<<i+1<<")"<<endl;
					}
				}
			}
		}
	}
}

void DFT(bool G[][5],int u,int n,int visit[],int f)
{
	visit[u]=1;
	cout<<u+1<<"  ";
	for(int i=0;i<n;i++){
		if(G[u][i]){
			if(!visit[i]){
				DFT(G,i,n,visit,1);
			}
		}
	}
	if(f==0){
		cout<<endl;
		for(int i=0;i<n;i++){
			if(!visit[i]){
				DFT(G,i,n,visit,0);
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
/*	bool G[][5]={{0,1,0,1,0},
				{0,0,1,0,1},
				{1,0,0,1,0},
				{0,0,0,0,1},
				{0,0,0,0,0},
				};*/
	bool G[][5]={{0,1,0,1,1},
				{1,0,1,1,1},
				{0,1,0,1,0},
				{1,1,1,0,1},
				{1,1,0,1,0},
				};			
				
	int i,n=5,v,visit[5]={0,0,0,0,0};
	for(i=0;i<n;i++)
	cout<<"Degree of "<<i+1<<" = "<<degree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"InDegree of "<<i+1<<" = "<<indegree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"OutDegree of "<<i+1<<" = "<<outdegree(G,i,n)<<endl;
	BFT(G,0,n);cout<<"\nDFT:\n";
	DFT(G,0,n,visit,0);
}
