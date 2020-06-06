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
int degree(bool G[][12],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[v][i])c++;
	return c;
}


void DFT(bool G[][12],int u,int n,int count,queue q)
{
	if(count!=-1){
	//	cout<<"u="<<u+1<<endl;
		q.enqueue(u);
		int f=0;
		for(int i=0;i<n;i++){
			if(G[u][i]){
					G[u][i]=0;G[i][u]=0;
				//	cout<<u+1<<"->"<<i+1<<endl;
					DFT(G,i,n,count-1,q);f=1;
				//	G[u][i]=1;G[i][u]=1;			
			}
		}
		if((count!=-1&&f==0)){
			queue q2;
			while(!q.isempty()){
				if(degree(G,q.Front(),n)!=0){
					
					DFT(G,q.dequeue(),n,count,q2);
				}
				else{
					cout<<q.dequeue()+1<<"->";
				}
			}//cout<<endl;
		}
	}
}

int main()
{

	bool G[][12]={{0,0,1,1,0,0,0,0,0,0,0,0},
				{0,0,1,0,0,0,0,1,0,0,0,0},
				{1,1,0,1,0,1,1,0,1,0,0,0},
				{1,0,1,0,1,0,1,0,0,1,1,0},
				{0,0,0,1,0,0,0,0,0,1,0,0},
				{0,0,1,0,0,0,0,0,1,0,0,0},
				{0,0,1,1,0,0,0,0,1,1,0,0},
				{0,1,0,0,0,0,0,0,1,0,0,0},
				{0,0,1,0,0,1,1,1,0,1,0,1},
				{0,0,0,1,1,0,1,0,1,0,1,1},
				{0,0,0,1,0,0,0,0,0,1,0,0},
				{0,0,0,0,0,0,0,0,1,1,0,0},
				};		
				
	int i,n=12,v,visit[5]={0,0,0,0,0},sum=0,j,count;
	for(i=0;i<n;i++){
		j=degree(G,i,n);
		sum+=j;
		cout<<"Degree of "<<i+1<<" = "<<j<<endl;
	}count=sum/2;
	cout<<"count="<<count<<endl;

	queue q;
	DFT(G,4,n,count,q);

}
