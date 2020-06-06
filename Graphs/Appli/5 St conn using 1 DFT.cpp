#include <iostream>
using namespace std;

class queue{
	public:
		int size;
		int front;
		int rear;int count;
		int elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;count=0;
		}
		
		void enqueue(int x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				count++;
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		int dequeue(){
			int t;
			if(front==-1)cout<<"Empty\n";
			else{
				count--;
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

int indegree(bool G[][10],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[i][v])c++;
	return c;	
}
int outdegree(bool G[][10],int v,int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	if(G[v][i])c++;
	return c;	
}

void DFT(bool G[][10],int u,int n,int visit[],int f,int start,queue q,queue q2[],int &in)
{
	if(start==u&&f!=0){
//		cout<<"in="<<in<<endl;
		q2[in++]=q;
	}
	else{
		int i;
		if(f!=0)
		visit[u]=1;int flag=0;
//		cout<<"f="<<f<<endl;
//		for(int g=0;g<n;g++){
//			cout<<"vis"<<g+1<<"="<<visit[g]<<"  ";
//		}cout<<"\n";
		q.enqueue(u);
//		cout<<u+1<<"  ";
		for(i=0;i<n;i++){
			if(G[u][i]){
				if(!visit[i]){
					flag=1;
					DFT(G,i,n,visit,1,start,q,q2,in);
				}
			}
		}
		if(flag==1)
		visit[u]=0;
		else{
			cout<<"{"<<char(65+u)<<"}\n";
		}
		if(f==0){
			int max=0,h,loc;
			for(h=0;h<in;h++){
				if(q2[h].count>max){
					max=q2[h].count;loc=h;
				}	
			}
			cout<<"{";
			while(!q2[loc].isempty()){
				visit[q2[loc].Front()]=1;
				cout<<char(q2[loc].dequeue()+65)<<" ";
			}
			cout<<"}\n";
			for(int i=0;i<n;i++){
				if(!visit[i]){
					if(outdegree(G,i,n)==0){
						cout<<"{"<<char(65+i)<<"}\n";
						visit[i]=1;
					}
					else if(indegree(G,i,n)==0){
						cout<<"{"<<char(65+i)<<"}\n";
						visit[i]=1;
					}
					else{
						while(!q.isempty())q.dequeue();
						for(h=0;h<in;h++){
							while(!q2[h].isempty())q2[h].dequeue();
						}in=0;
						DFT(G,i,n,visit,0,i,q,q2,in);
					}
				}
			}
		}
	}	
}

int main()
{

	bool G[][10]={{0,1,0,1,0,0,0,0,0,0},
					{0,0,1,0,0,1,0,0,0,0},
					{1,0,0,1,1,0,0,0,0,0},
					{0,0,0,0,1,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0},
					{0,0,0,0,0,1,0,1,0,0},
					{0,0,0,0,0,1,0,0,0,1},
					{0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,1,0}	};
	
	int n=10,visit[10],i,j;
		for(i=0;i<n;i++){
			visit[i]=0;
		}
	queue q,q2[10];int in=0;
	DFT(G,0,n,visit,0,0,q,q2,in);					
}
