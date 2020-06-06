#include <iostream>
using namespace std;

typedef
struct lnode{
	int data;int todis;
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
void printlist(LPTR T){
	if(T){
		cout<<T->data+1<<"  ";
		printlist(T->next);
	}
	else{
		cout<<"------000\n";
	}
}

void addlist(LPTR &T,int c,int todist)
{
	if(T==0){
		T=new lnode();T->data=c;T->todis=todist;T->next=0;
	}
	else{
		if(todist<=T->todis){
			LPTR temp=new lnode();
			temp->data=c;temp->todis=todist;temp->next=T;
			T=temp;
		}
		else{
			addlist(T->next,c,todist);
		}
	}
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

void BFT_shortpath(int G[][7],int visit[],int prever[],int todis[],int curr,int goal,int n,int start)
{
	int i,min,loc;queue q;
	q.enqueue(curr);
	while(curr!=goal){
	//	cout<<"curr="<<curr<<"goal="<<goal<<endl;
		curr=q.dequeue();
		LPTR L=0,X;
		for(i=0;i<n;i++){
			if(G[curr][i]){
				if(!visit[i]){
					int sum=G[curr][i]+todis[curr];
					if(sum<todis[i]){
						todis[i]=sum;prever[i]=curr;
					//	cout<<"i="<<i<<" "<<sum<<" "<<curr<<endl;
					}
					addlist(L,i,todis[i]);
				}
			}
		}
		visit[curr]=1;
		X=L;
//		cout<<"curr="<<curr+1<<endl;
		while(X){
		//	cout<<"i="<<X->data<<endl;
			q.enqueue(X->data);X=X->next;
		}
//		printlist(L);
//		cout<<"\n-----\n";
		while(L)delendlist(L);
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
				{4,0,0,0,0,1,0},
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
	cout<<"Shorest path:\n";
	BFT_shortpath(G,visit,prever,todis,0,5,7,0);
	
	
}
