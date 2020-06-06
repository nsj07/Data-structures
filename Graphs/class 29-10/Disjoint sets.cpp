#include <iostream>
using namespace std;

int find(int S[],int x)
{
	return (!S[x]?x:find(S,S[x]));
}
void mkunion(int S[],int x,int y)
{
	if(!S[x]&&!S[y]){
		S[y]=find(S,x);
		cout<<"s["<<y<<"]="<<S[y]<<endl;
	}
	else if(S[x]&&S[y]){
		S[find(S,x)]=find(S,y);
	}
	else if(S[y]){
		S[x]=find(S,y);
	}
	else{
		S[y]=find(S,x);
	}
}

int main()
{
	int S[10],i,j,n=9;
	for(i=1;i<=n;i++){
		S[i]=0;
	}
	mkunion(S,1,7);
	mkunion(S,1,5);
	mkunion(S,6,8);
	mkunion(S,2,6);
	for(i=1;i<=n;i++){
		cout<<i<<"="<<find(S,i)<<endl;
	}
}
