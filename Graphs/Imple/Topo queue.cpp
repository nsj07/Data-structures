#include <iostream>
using namespace std;

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

void topo(bool G[][6],int indegree[],int n)
{
	queue q;
	int i,count=0,j,u;
	for(i=0;i<n;i++){
		if(indegree[i]==0) q.enqueue(i);
	}
	while(!q.isempty()){
		u=q.dequeue();cout<<u<<" ";
		for(i=0;i<n;i++){
			if(G[u][i]){
				indegree[i]--;
				if(indegree[i]==0) q.enqueue(i);
			}
		}
	}
}
int main()
{
	bool G[][6]={{0,0,0,0,0,0},
					{0,0,0,0,0,0},		
					{0,0,0,1,0,0},
					{0,1,0,0,0,0},
					{1,1,0,0,0,0},
					{1,0,1,0,0,0}
					};
	int indegree[]={0,0,0,0,0,0},n=6,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j])
			indegree[j]++;
		}
	}
	topo(G,indegree,n);
}
