#include <iostream>
#include <cstring>
using namespace std;

struct tstnode{
	char data;
	tstnode* l;
	tstnode* c;
	tstnode* r;
	int end;
};
typedef tstnode* TST;

void Insert(TST &T,char c[],int i)
{
	if(T==0){
		T=new tstnode();
		T->l=0;T->c=0;T->r=0;
		T->data=c[i];T->end=0;
		if(i+1<strlen(c))
		Insert(T->c,c,i+1);
		else
		T->end=1;
	}
	else{
		if(c[i]<T->data&&i<strlen(c))
		Insert(T->l,c,i);
		else if(c[i]>T->data&&i<strlen(c))
		Insert(T->r,c,i);
		else{
			if(i+1<strlen(c))
			Insert(T->c,c,i+1);
			else
			T->end=1;
		}
	}
}

class queue{
	public:
		int size;
		int front;
		int rear;
		TST elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(TST x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		TST dequeue(){
			TST t;
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
		
		TST Front(){
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
void printlevelorder(TST T)
{
	queue q;
	q.enqueue(T);
	TST L=NULL;
	q.enqueue(L);
	cout<<z++<<"-> ";
	while(!q.isempty())
	{
		TST P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty()){
				cout<<z++<<"-> ";
				q.enqueue(P);
			}
		}
		else{
			cout<<P->data<<"  ";
			if(P->l!=0) q.enqueue(P->l);
			if(P->c!=0) q.enqueue(P->c);
			if(P->r!=0) q.enqueue(P->r);
		}
	}
}
int search(TST T,char c[],int i)
{
	if(T!=0){
		if(c[i]<T->data&&i<strlen(c))
		return search(T->l,c,i);
		else if(c[i]>T->data&&i<strlen(c))
		return search(T->r,c,i);
		else{
			if(i+1<strlen(c))
			return search(T->c,c,i+1);
			else
			return T->end;
		}
	}
	return 0;
}

int main()
{
	cout<<"Start\n";
	char c[][15]={"cat","bug","cags","up"},d[15];
	int i,j,k,n=sizeof(c)/sizeof(c[0]);
	cout<<"n="<<n<<endl;
	TST T=0;
	for(i=0;i<n;i++){
		Insert(T,c[i],0);
	}
	cout<<"Level print:\n";
	printlevelorder(T);cout<<endl;
	while(i!=-1){
		cout<<"Enter str to search=";
		cin>>d;
		search(T,d,0)?cout<<"Found\n":cout<<"Not found\n";
		cout<<"-1 to end\n";
		cin>>i;
	}
	
}
