#include <iostream>
using namespace std;


void shortest(int G[][7],int visit[],int prever[],int todis[],int curr,int goal,int n,int start)
{
	int i,min,loc;
	while(curr!=goal){
	//	cout<<"curr="<<curr<<"goal="<<goal<<endl;
		for(i=0;i<n;i++){
			if(G[curr][i]){
				if(!visit[i]){
					int sum=G[curr][i]+todis[curr];
					if(sum<todis[i]){
						todis[i]=sum;prever[i]=curr;
					//	cout<<"i="<<i<<" "<<sum<<" "<<curr<<endl;
					}
				}
			}
		}
		visit[curr]=1;
		min=100;
		for(i=0;i<n;i++){
			if(!visit[i]){
			//	cout<<"insi="<<i<<endl;
				if(todis[i]<min){
					min=todis[i];loc=i;
				//	cout<<"i="<<i<<"loc="<<loc<<endl;
				}
			}
		}
		curr=loc;
	}
	int t=prever[goal];
	cout<<goal+1<<"<-";
	while(t!=start){
		cout<<t+1<<"<-";
		t=prever[t];
	}cout<<start+1<<endl;
}
int main()
{
/*	bool G[][5]={{0,1,1,1,0},
				{1,0,1,0,1},
				{1,1,0,1,0},
				{1,0,1,0,1},
				{0,1,0,1,0},
				};*/
	int G[][7]={{0,2,0,1,0,0,0},
				{0,0,0,3,10,0,0},
				{4,0,0,0,0,5,0},
				{0,0,2,0,2,8,4},
				{0,0,0,0,0,0,6},
				{0,0,0,0,2,0,0},
				{0,0,0,0,0,1,0},
				};
/*	bool G[][12]={{0,0,1,1,0,0,0,0,0,0,0,0},
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
				};*/		
				
	int i,n=7,v,visit[7]={0,0,0,0,0,0,0},prever[7]={0,0,0,0,0,0,0},todis[7]={0,1000,1000,1000,1000,1000,1000};
	shortest(G,visit,prever,todis,0,5,7,0);
	
	
}
