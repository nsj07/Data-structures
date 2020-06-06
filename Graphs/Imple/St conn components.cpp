#include <iostream>
using namespace std;

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

static int l=1;
void DFT(bool G[][10],int u,int n,int visit[],int value[],int f,stack &s)
{
	if(visit[u]==0){
		visit[u]=1;
		s.push(u);
		for(int i=0;i<n;i++){
			if(G[u][i]){
				if(!visit[i]){
					DFT(G,i,n,visit,value,1,s);
				}
			}
		}
		if(f==0){
			cout<<endl;
		while(!s.isempty()){
			value[s.pop()]=l++;
		}
			for(int i=0;i<n;i++){
				if(!visit[i]){
					DFT(G,i,n,visit,value,0,s);
				}
			}
		}
	}
}

void printDFT(bool G[][10],int u,int n,int visit[],int value[],int f)
{
	if(visit[u]==0){
		visit[u]=1;
		cout<<char(u+65)<<"  ";
		for(int i=0;i<n;i++){
			if(G[u][i]){
				if(!visit[i]){
					printDFT(G,i,n,visit,value,1);
				}
			}
		}
//		value[u]=l++;
		if(f==0){
			cout<<"}"<<endl;
			for(int i=n;i>=0;i--){
				for(int j=0;j<n;j++){
					if(value[j]==i){
						if(!visit[j]){
							cout<<"{";
							printDFT(G,j,n,visit,value,0);
						}
					}
				}
			}
		}
	}
}
void reverse(bool G1[][10],bool G[][10],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			G1[i][j]=G[j][i];
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

	bool G[][10]={{0,1,0,1,0,0,0,0,0,0},
					{0,0,1,0,0,1,0,0,0,0},
					{1,0,0,1,1,0,0,0,0,0},
					{0,0,0,0,1,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0},
					{0,0,0,0,0,1,0,1,0,0},
					{0,0,0,0,0,1,0,0,0,1},
					{0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,1,0}	},G1[10][10];			
		int n=10,visit[10],i,value[10];
		for(i=0;i<n;i++){
			value[i]=0;visit[i]=0;
		}
	stack s;	
	DFT(G,0,n,visit,value,0,s);
	for(i=0;i<n;i++){
	//	cout<<value[i]<<" ";
			visit[i]=0;
		}cout<<endl;
		reverse(G1,G,n);
		for(i=0;i<n;i++){
			if(value[i]==n)break;
		}cout<<"{";
		printDFT(G1,i,n,visit,value,0);
}
