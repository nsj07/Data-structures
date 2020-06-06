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

void permute(int a[],int l,int r,string s[],int &j){
    int i;
    if(l==r){
        for(int i=0;i<=r;i++)
            s[j]+=a[i]+'0';
            cout<<"s="<<s[j]<<endl;
            j+=1;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(a[l],a[i]);
            permute(a,l+1,r,s,j);
            swap(a[i],a[l]); //backtrack
        }
    }
}
int fact(int n){
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}

void topo(bool G[][6],int indegree[],int n,int p[],int len)
{	
	if(len!=n){
	//	cout<<"pppp\n";
		int i,j,k,a[6],tem[6];
		for(i=0;i<n;i++)tem[i]=indegree[i];
		j=0;
		for(i=0;i<n;i++){
			if(indegree[i]==0){
				a[j]=i;j+=1;
			}
		}
		for(i=0;i<j;i++){
		//	cout<<"in\n";
			for(k=0;k<n;k++)indegree[k]=tem[k];
			p[len]=a[i];
		//	cout<<a[i]<<" ";
			indegree[a[i]]=-1;
			for(k=0;k<n;k++){
				if(G[a[i]][k])indegree[k]--;
			}
			topo(G,indegree,n,p,len+1);
		//	cout<<endl;
		}
	}
	else{
		for(int i=0;i<n;i++){
			cout<<p[i]<<" ";
		}cout<<endl;
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
	int indegree[]={0,0,0,0,0,0},tempin[]={0,0,0,0,0,0},n=6,i,j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j]){
				indegree[j]++;
				tempin[j]++;
			}
		}
	}
	j=0;
	int len=0,p[6],a[6],k=0;
	for(i=0;i<n;i++){
		if(indegree[i]==0){
			a[j]=i;j+=1;
		}
	}
//	cout<<"j="<<j<<endl;
	for(i=0;i<j;i++){
		for(k=0;k<n;k++)indegree[k]=tempin[k];
		p[len]=a[i];
	//	cout<<a[i]<<" ";
		indegree[a[i]]=-1;
		for(k=0;k<n;k++){
			if(G[a[i]][k])indegree[k]--;
		}
		topo(G,indegree,n,p,len+1);
	//	cout<<endl;
	}
}
