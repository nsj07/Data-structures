#include <iostream>
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
LPTR L=0;
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
		cout<<T->data<<"  ";
		printlist(T->next);
	}
	else{
		cout<<"------000\n";
	}
}

void permute(int a[],int l,int r,string s[],int &j){
    int i;
    if(l==r){
        for(int i=0;i<=r;i++)
            s[j]+=a[i]+'0';
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
int s[15][5],y=0;
void DFT(bool G[][5],int u,int n,int visit[],int f,int &len,int p[])
{
	if(len!=n){
	//	cout<<"u="<<u+1<<endl;
		int temp[5],j,k=0,i,tempsiz=len,a[5];
		for( i=0;i<n;i++){
			temp[i]=visit[i];
			if(G[u][i]){
				if(!visit[i]){
					a[k++]=i;
				}
			}
		}
	//	cout<<"1\n";
		int count=0,sz=0;
		string *str;
		if(k){
			count=fact(k);
			str=new string[count];
	        permute(a,0,k-1,str,sz);
	    //    cout<<"cnt="<<count<<endl;
		}
	//	cout<<"2\n";
		for(i=0;i<count;i++){
		/*	for(j=0;j<k;j++)cout<<str[i][j]-'0'+1;
	        	cout<<endl;*/
			for(j=0;j<n;j++){
				visit[j]=temp[j];
			}len=tempsiz;
			for(int l=0;l<k;l++){
				if(G[u][str[i][l]-'0']&&!visit[str[i][l]-'0']){
					cout<<u+1<<"->"<<(str[i][l]-'0')+1<<endl;
					visit[str[i][l]-'0']=1;p[len]=str[i][l]-'0';len+=1;
					DFT(G,str[i][l]-'0',n,visit,1,len,p);
				}
			}
		}
	//	cout<<"3\n";
		if(f==0){
			cout<<"im here\n";
			cout<<endl;
			for( i=0;i<n;i++){
				if(!visit[i]){
					DFT(G,i,n,visit,0,len,p);
				}
			}
		}
	}
	else{
		int i,j;
		for(i=0;i<y;i++){
			for(j=0;j<n;j++){
				if(s[i][j]!=p[j])break;
			}
			if(j==n)break;
		}
		if(i==y){
			for(i=0;i<n;i++){
				s[y][i]=p[i];
				cout<<p[i]+1;
				if(i!=n-1)cout<<"->";
			}y++;cout<<endl;
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
/*	bool G[][5]={{0,1,0,1,0},
				{0,0,1,0,1},
				{1,0,0,1,0},
				{0,0,0,0,1},
				{0,0,0,0,0},
				};*/			
				
	int i,n=5,v,visit[5]={0,0,0,0,0},p[5],len=1;
	cout<<"DFT:\n";
	visit[0]=1;p[0]=0;
	DFT(G,0,n,visit,0,len,p);
}
