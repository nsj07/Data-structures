#include <iostream>
using namespace std;

typedef
struct lnode{
	int data;
	lnode* next;
}* LPTR;


int degree(bool G[][12],int v,int n)
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

LPTR L=0;
void splice(LPTR T)
{
	if(L){
		LPTR X=L,temp;
		while(X->data!=T->data)X=X->next;
		temp=X->next;
		X->next=T->next;
		while(T->next!=0)T=T->next;
		T->next=temp;
	}else{
		L=T;
	}
}

void DFT(bool G[][12],int u,int n,LPTR T,int &count)
{
	//cout<<u+1<<"-";
	//cout<<"count="<<count<<endl;
	addlist(T,u);
	for(int i=0;i<n;i++){
		if(G[u][i]){
				count--;
				G[u][i]=0;G[i][u]=0;
				DFT(G,i,n,T,count);			
		}
	}
	if(count!=-1){
		LPTR X=0;
		if(count!=-1){
			splice(T);
			if(count==0){
				count--;return;
			}
		}
		T=L;
		while(T&&degree(G,T?T->data:0,n)==0)T=T->next;
		if(T){
			DFT(G,T->data,n,X,count);			
		}
	//	count--;
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

	LPTR T=0;
	DFT(G,4,n,T,count);
	
	while(L!=0){
		cout<<L->data+1;
		if(L->next)cout<<"->";
		L=L->next;
	}
}
