#include <iostream>
#include <cstring>
using namespace std;
union u{
	char data[15];
	struct trnode *ptr[4];
};

struct trnode{
	union u key;
	int tag;
	int com;
};
typedef trnode* TPTR;

int n;

int ri(char c,char arr[])
{
	int i=0;
	while(arr[i]!=c)i++;
	return i;
}

char* findone(TPTR T)
{
	if(T->tag!=0){
		int j=0;
		while(T->key.ptr[j]==0)j++;
		return findone(T->key.ptr[j]);
	}
	return T->key.data;
}
void Insert(TPTR &T,char c[],int i,char arr[],TPTR Parent)
{
	if(T==NULL){
		T=new trnode();
		T->tag=0;
		strcpy(T->key.data,c);
		T->com=i;
	}
	else{
		if(i==T->com&&T->tag!=0){
			if(T->tag==1&&i<strlen(c))
			Insert(T->key.ptr[ri(c[i],arr)],c,i+1,arr,T);
			else if(T->tag==1&&i==strlen(c))
			Insert(T->key.ptr[n],c,i+1,arr,T);
			else{
				char prev[15];
				strcpy(prev,T->key.data);
				delete(T);T=new trnode();
				T->tag=1;T->com=i;
				for(int l=0;l<n;l++)
				T->key.ptr[l]=0;
				Insert(T->key.ptr[ri(prev[i],arr)],prev,i+1,arr,T);
				Insert(T->key.ptr[ri(c[i],arr)],c,i+1,arr,T);
			}
		}
		else{
			char pstr[15];
			strcpy(pstr,findone(T));
			while(c[i]==pstr[i]&&i<T->com&&i<strlen(c))i++;
			if(i==T->com&&T->tag!=0)
			Insert(T,c,i,arr,Parent);
			else{
				TPTR N=new trnode();
				N->tag=1;N->com=i;
				int j;
				for(j=0;j<=n;j++) N->key.ptr[j]=0;
				j=0;
				while(Parent->key.ptr[j]!=T)j++;
				N->key.ptr[j]=T;
				T=N;
				Insert(T,c,i,arr,Parent);
			}
		}
	}
}

class queue{
	public:
		int size;
		int front;
		int rear;
		TPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(TPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		TPTR dequeue(){
			TPTR t;
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
		
		TPTR Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isempty(){
			if(front==-1)
			return 1;
			else return 0;
		}
};
static int z=0;
void printlevelorder(TPTR T)
{
	queue q;
	q.enqueue(T);
	TPTR L=NULL;
	q.enqueue(L);
	cout<<z++<<"-> ";
	while(!q.isempty())
	{
		TPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty()){
				cout<<z++<<"-> ";
				q.enqueue(P);
			}
		}
		else{
			int i=0;
			if(P->tag==1)
			for(i=0;i<=n;i++){
				//cout<<P->key[i]<<",";
				if(P->key.ptr[i]!=0) q.enqueue(P->key.ptr[i]);
			}
			else{
				cout<<"{"<<P->com<<","<<P->key.data<<"}\t";
			}
		}
	}
}
int main()
{
	cout<<"Start\n";
	char arr[]={'A','B','C'};
	char c[10][10]={"AAB","ABBBC","BAA","BCCAA","BC","CABB","A","ABB"};
	int i,v=8;
	n=sizeof(arr)/sizeof(arr[0]);
	TPTR T=0;
	T=new trnode();
	T->tag=1;
	for(i=0;i<=n;i++)
	T->key.ptr[i]=0;
	for(i=0;i<v;i++){
		cout<<"c="<<c[i]<<endl;
		Insert(T,c[i],0,arr,0);
		cout<<"---\n";
		printlevelorder(T);z=0;cout<<"\n";
	}
	cout<<"Level print:\n";
	printlevelorder(T);
}
