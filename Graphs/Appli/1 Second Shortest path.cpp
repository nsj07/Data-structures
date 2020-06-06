#include <iostream>
using namespace std;


void shortest(int G[][7],int visit[],int prever[],int todis[],int curr,int goal,int n,int start,int &count)
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
//	cout<<goal+1<<"<-";
	count++;
	while(t!=start){
//		cout<<t+1<<"<-";
		t=prever[t];
		count++;
	}
//	cout<<start+1<<endl;
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
				{0,0,0,0,0,0,0},
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
				
	int i,n=7,v,visit[7]={0,0,0,0,0,0,0},prever[7]={0,0,0,0,0,0,0},todis[7]={0,1000,1000,1000,1000,1000,1000},goal=5,start=0;
	int prver[7]={0,0,0,0,0,0,0},totaldis[7]={0,1000,1000,1000,1000,1000,1000},count=0,w,cou;
	shortest(G,visit,prever,todis,0,5,7,0,count);
	cout<<"Shortest path:\n";
	cout<<"Weight="<<todis[goal]<<" : ";
	int t=prever[goal];
	cout<<goal+1<<"<-";
	while(t!=start){
		cout<<t+1<<"<-";
		t=prever[t];
	}cout<<start+1<<endl;
	
	t=prever[goal];
	int t2=goal,c=count,weight=100,result[7]={0,0,0,0,0,0,0};
	while(c>0){
		
		w=G[t][t2];G[t][t2]=0;
		
		int	visit[]={0,0,0,0,0,0,0},prver[]={0,0,0,0,0,0,0};
		totaldis[0]=0;
		for(i=1;i<n;i++)totaldis[i]=1000;
		shortest(G,visit,prver,totaldis,start,goal,n,start,cou);
		
		if(totaldis[goal]<weight){
			weight=totaldis[goal];
			for(int h=0;h<n;h++)result[h]=prver[h];
		}G[t][t2]=w;
		t2=t;t=prever[t];c--;
	}
	cout<<"second shortest distance:\n";
	cout<<"Weight="<<weight<<" : ";
	t=result[goal];
	cout<<goal+1<<"<-";
	while(t!=start){
		cout<<t+1<<"<-";
		t=result[t];
	}cout<<start+1<<endl;
}
