#include <iostream>
using namespace std;

int find(int S[],int x)
{
//	x++;
	return (!S[x]?x:find(S,S[x]));
}
void mkunion(int S[],int x,int y)
{
//	x++;y++;
	if(!S[x]&&!S[y]){
		S[y]=find(S,x);
	//	cout<<"s["<<y<<"]="<<S[y]<<endl;
	}
	else if(S[x]&&S[y]){
		S[find(S,y)]=find(S,x);
	}
	else if(S[y]){
		S[x]=find(S,y);
	}
	else{
		S[y]=find(S,x);
	}
}
void sortedge(int edge[],int link[][2],int n)
{
	int pass,i;
	for(pass=1;pass<=n-1;pass++){
		for(i=0;i<n-pass;i++){
			if(edge[i]>edge[i+1]){
				swap(edge[i],edge[i+1]);
				swap(link[i][0],link[i+1][0]);
				swap(link[i][1],link[i+1][1]);
			}
		}
	}
//	for(i=0;i<n;i++){
//		cout<<edge[i]<<":"<<link[i][0]+1<<"->"<<link[i][1]+1<<endl;
//	}
}

void minspan(int G[][7],int S[],int edge[],int link[][2],int n,int totalv)
{
	sortedge(edge,link,n);
	int i=0,count=0;
	while(i<n&&count!=totalv-1){
		if(find(S,link[i][0])!=find(S,link[i][1])){
			mkunion(S,link[i][0],link[i][1]);
			cout<<link[i][0]<<"->"<<link[i][1]<<endl;count++;
		}
		i++;
	}
}

int main()
{
	int G[][7]={{0,2,4,1,0,0,0},
				{2,0,0,3,10,0,0},
				{4,0,0,2,0,5,0},
				{1,3,2,0,7,8,4},
				{0,10,0,7,0,0,6},
				{0,0,5,8,0,0,1},
				{0,0,0,4,6,1,0},
				};
	int S[8],i,j,n=7,c=0,edge[20],link[20][2];
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(G[i][j]){
				edge[c]=G[i][j];link[c][0]=i+1;link[c][1]=j+1;c++;
			}
		}
	}
	cout<<"Total edges="<<c<<endl;
	for(i=1;i<=n;i++){
		S[i]=0;
	}
	minspan(G,S,edge,link,c,n);
		
	for(i=1;i<=n;i++){
		cout<<i<<"="<<find(S,i)<<endl;
	}
}
