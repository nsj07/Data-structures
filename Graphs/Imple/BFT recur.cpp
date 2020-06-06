#include <iostream>
#include <cstring>
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
//LPTR L=0;
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
void dellist(LPTR &T,int v)
{
	if(T){
		LPTR X=T,prev=T,temp;
		while(X->data!=v&&X!=0){
			prev=X;
			X=X->next;
		}
		if(X==T){
			T=T->next;
		}
		else prev->next=X->next;
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
		cout<<T->data+1<<"  ";
		printlist(T->next);
	}
	else{
		cout<<"------000\n";
	}
}

void permutate(char c[5],int l,int r,char per[][5],int &s)
{
	if(l==r)
	{
//		cout<<"perm="<<c<<" r="<<r<<endl;
		strcpy(per[s++],c);
	}
	else{
		for(int i=l;i<=r;i++){
			swap(c[l],c[i]);
			permutate(c,l+1,r,per,s);
			swap(c[i],c[l]);
		}
	}
}
void rmvisit(LPTR L,int visit[],int n)
{
//	for(int i=0;i<n;i++)visit[i]=0;
	while(L){
		visit[L->data]=0;L=L->next;
	}
}
void BFT(bool G[][5],int u,int n,int visit[],queue q,int flag,LPTR L)
{
	if(flag==0){
		q.enqueue(u);
		visit[u]=1;
		addlist(L,u);
	}
	int f=0,count=0;char c[5];
	u=q.dequeue();cout<<u+1<<endl;
	L=0;
	for(int i=0;i<n;i++){
		if(G[u][i]){
			if(!visit[i]){
				visit[i]=1;addlist(L,i);
				c[count++]=i+48;
				cout<<"("<<u+1<<"->"<<i+1<<")"<<endl;
				f=1;
			}
		}
	}
	if(f==1){
		cout<<">>>>";printlist(L);cout<<endl;
		char per[20][5];int s=0;
		cout<<"coun="<<count<<endl;
		permutate(c,0,count-1,per,s);
		cout<<"per[0]="<<per[0]<<endl;
		for(int b=0;b<s;b++){
			for(int k=0;k<count;k++){
				cout<<per[b][k]-48+1;
				q.enqueue(per[b][k]-48);
			}cout<<endl;
			BFT(G,u,n,visit,q,1,L);
		//	cout<<per[b]<<"rmng-----";printlist(L);cout<<endl;
			rmvisit(L,visit,n);
			for(int k=0;k<n;k++){
				cout<<"visit"<<k+1<<"="<<visit[k]<<"  ";
			}cout<<endl;
		}s=0;
	}
/*	if(flag==0){
		int i;
		for(i=0;i<n;i++){
			if(!visit[i])break;
		}
		if(i!=n){
			while(!q.isempty()) q.dequeue();
			BFT(G,i,n,visit,q,L,0);
		}
	}*/	
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
	bool G[][5]={{0,1,0,1,0},
				{0,0,1,0,1},
				{1,0,0,1,0},
				{0,0,0,0,1},
				{0,0,0,0,0},
				};
/*	bool G[][5]={{0,1,0,0,0},
				{0,0,1,0,0},
				{0,0,0,1,0},
				{1,0,0,0,0},
				{0,0,1,0,0},
				};*/			
				
	int i,n=5,v,visit[5]={0,0,0,0,0};
/*	for(i=0;i<n;i++)
	cout<<"Degree of "<<i+1<<" = "<<degree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"InDegree of "<<i+1<<" = "<<indegree(G,i,n)<<endl;
	for(i=0;i<n;i++)
	cout<<"OutDegree of "<<i+1<<" = "<<outdegree(G,i,n)<<endl;*/
	queue q;LPTR L=0;
	BFT(G,0,n,visit,q,0,L);
//	cout<<"\nDFT:\n";
//	for(i=0;i<n;i++)visit[i]=0;
//	DFT(G,0,n,visit,0);
}
