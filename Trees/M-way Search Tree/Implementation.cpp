#include <iostream>
using namespace std;

static int m=4;

struct mnode{
	int key[10];
	struct mnode *ptr[10];
};
typedef mnode* MPTR;

class queue{
	public:
		int size;
		int front;
		int rear;
		MPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(MPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		MPTR dequeue(){
			MPTR t;
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
		
		MPTR Front(){
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

MPTR Insert(MPTR T,int k)
{
	if(T==NULL){
		T=new mnode();
		T->key[0]=1;T->key[1]=k;
		for(int i=0;i<m;i++)
		T->ptr[i]=0;
	}
	else{
		int i=1;
		while(i<=T->key[0]){
			if(T->key[i]>k)
			break;
			i++;
		}
		if(T->key[0]==m-1){
			T->ptr[i-1]=Insert(T->ptr[i-1],k);
		}
		else  if(T->key[0]<m-1){
			for(int j=T->key[0]+1;j>i;j--)
			T->key[j]=T->key[j-1];
			T->key[i]=k;
			T->key[0]++;
		}
	}
	return T;
}

void sortorder(MPTR T)
{
	if(T!=NULL){
		for(int i=0;i<T->key[0];i++){
			sortorder(T->ptr[i]);
			cout<<T->key[i+1]<<"  ";
		}
		sortorder(T->ptr[T->key[0]]);
	}
}

int find(MPTR T,int k)
{
	if(T!=NULL){
		int i;
		for(i=1;i<=T->key[0];i++)
		{
			if(T->key[i]==k)
			return 1;
			if(T->key[i]>k)
			return find(T->ptr[i-1],k);
		}
		if(i>T->key[0])
		return find(T->ptr[i-1],k);
	}
	return 0;
}

int mtmin(MPTR T)
{
	if(T!=NULL){
		if(T->ptr[0]==NULL)
		return T->key[1];
		else
		return mtmin(T->ptr[0]);
	}
}

int mtmax(MPTR T)
{
	if(T!=NULL){
		if(T->ptr[m-1]==NULL)
		return T->key[T->key[0]];
		else
		return mtmax(T->ptr[m-1]);
	}
}

MPTR del(MPTR T,int k)
{
	if(T!=NULL){
		int i;
		for(i=1;i<=T->key[0];i++)
		{
			if(T->key[i]==k)
			{
				if(T->ptr[i]!=0){
					T->key[i]=mtmin(T->ptr[i]);
					T->ptr[i]=del(T->ptr[i],T->key[i]);
				}
				else if(T->ptr[i-1]!=0){
					T->key[i]=mtmax(T->ptr[i-1]);
					T->ptr[i-1]=del(T->ptr[i-1],T->key[i]);
				}
				else{
					if(T->key[0]==1){
						delete T;return NULL;
					}
					else{
						for(int j=i;j<T->key[0];j++)
						T->key[j]=T->key[j+1];
						T->key[0]--;
					}
				}
			}
			if(T->key[i]>k)
			T->ptr[i-1]=del(T->ptr[i-1],k);
		}
		if(i>T->key[0])
		T->ptr[i-1]=del(T->ptr[i-1],k);
	}
	return T;
}

void printlevelorder(MPTR T)
{
	queue q;
	q.enqueue(T);
	MPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		MPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			int i=1;
			for(i=1;i<=P->key[0];i++){
				cout<<P->key[i]<<",";
				if(P->ptr[i-1]!=0) q.enqueue(P->ptr[i-1]);
			}
			cout<<"     ";		
			if(P->ptr[i-1]!=0) q.enqueue(P->ptr[i-1]);
		}
	}
}
int main()
{
	MPTR T=NULL;
	cout<<"Enter values (-1 to end).\n";
	int n;
	cin>>n;
	while(n!=-1){
		T=Insert(T,n);
		cin>>n;
	}
	cout<<"Sort order\n";
	sortorder(T);
	cout<<"\nLevel order:\n";
	printlevelorder(T);
	cout<<"\nEnter no. to find=";cin>>n;
	int f=find(T,n);
	f?cout<<"Found\n":cout<<"Not found\n";
	cout<<"Min value="<<mtmin(T);
	cout<<"\nMax value="<<mtmax(T)<<endl;
	cout<<"Enter value to delete=";cin>>n;
	T=del(T,n);cout<<"\n";
	sortorder(T);
	cout<<"\nLevel order:\n";
	printlevelorder(T);
	return 0;
}
