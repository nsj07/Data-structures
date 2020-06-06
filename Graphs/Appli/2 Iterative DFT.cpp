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
class stack{
	public:
	int size;
	int top;
	int elements[50];
	stack(){
		top=-1;size=50;
	}
	void push(int x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	int pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	int Top(){
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

void DFT(bool G[][5],int u,int n,int visit[])
{
	int count=0,i;
	stack s;queue q;
	while(count!=n){
		s.push(u); q.enqueue(u);visit[u]=1;count++;
		while(!s.isempty()){
			u=s.pop();
			for(i=0;i<n;i++){
				if(G[u][i]&&!visit[i]){
					s.push(u);s.push(i);visit[i]=1;q.enqueue(i);count++;break;
				}
			}
		}
		for(i=0;i<n;i++){
			if(!visit[i]){
				u=i;break;
			}
		}
	}
	while(!q.isempty()){
		cout<<q.dequeue()+1;
		if(!q.isempty())cout<<"->";
	}cout<<"\n";
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
/*	bool G[][5]={{0,1,0,1,1},
				{1,0,1,1,1},
				{0,1,0,1,0},
				{1,1,1,0,1},
				{1,1,0,1,0},
				};*/			
				
	int i,n=5,visit[5]={0,0,0,0,0};
 	cout<<"DFT\n";
	DFT(G,0,n,visit);
}
