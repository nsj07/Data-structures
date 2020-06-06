#include <iostream>
using namespace std;

struct hcnode{
	hcnode* lc;
	char c;
	int i;
	hcnode* rc;
	int x;
};

typedef hcnode* HPTR;
struct lnode{
	HPTR data;
	lnode* next;
};
typedef lnode* LPTR;
LPTR Insert(LPTR L,HPTR H)
{
	LPTR temp=new(lnode);
	temp->data=H;temp->next=NULL;
	if(L==NULL)L=temp;
	else{
		LPTR X=L;
		while(X->next!=NULL)
		X=X->next;
		X->next=temp;
	}		
	return L;
}
class queue{
	public:
		int size;
		int front;
		int rear;
		HPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(HPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		HPTR dequeue(){
			HPTR t;
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
		
		HPTR Front(){
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

void inorder(HPTR B)
{
	
	if(B!=NULL){
		static int i=1;
		inorder(B->lc);
		B->x=i++;
		inorder(B->rc);
	}
}
void printtree(HPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	HPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		HPTR P=q.dequeue();
		if(P!=NULL)present=P->x;
		if(P==NULL){
			prev=0;
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			for(int i=1;i<=present-prev;i++)
			cout<<"  ";
			cout<<P->c;prev=P->x;
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}

void swap(HPTR &x,HPTR &y)
{
	HPTR t=x;x=y;y=t;
}
LPTR sortinsert(LPTR L,LPTR temp)
{
	LPTR prev=L,T=L;
	while(T!=NULL){
		if(temp->data->i>=T->data->i){
			prev=T;T=T->next;
		}
		else{
			if(T==L){
				L=temp;
				temp->next=T;
			}
			else{
				prev->next=temp;
				temp->next=T;
			}break;
		}
	}
	if(T==NULL){
		if(L==NULL)
		L=temp;
		else
		prev->next=temp;
	}
	return L;
}
HPTR createtree(LPTR L)
{
	while(L->next!=NULL){
		LPTR T=L;
		HPTR t1=L->data,t2;
		L=L->next;delete(T);T=L;
		t2=L->data;
		L=L->next;delete(T);
		HPTR t=new(hcnode);
		t->lc=t1;t->rc=t2;t->c='*';
		t->i=t1->i+t2->i;
		//cout<<"______"<<t->i<<endl;
		LPTR temp=new(lnode);temp->data=t;temp->next=NULL;
		L=sortinsert(L,temp);
		//cout<<"======"<<L->data->c<<"="<<L->data->i<<endl;
	}
	//cout<<"LLL="<<L->data->i<<endl;
	return L->data;
}
void displaybinary(HPTR T,char side,string c)
{
	if(T!=NULL){
		if(side=='l'){
			c=c+"0";
			if(T->c!='*'){
				cout<<T->c<<"="<<c<<endl;
			}
		}
		else if(side=='r'){
			c=c+"1";
			if(T->c!='*'){
				cout<<T->c<<"="<<c<<endl;
			}
		}
		displaybinary(T->lc,'l',c);
		displaybinary(T->rc,'r',c);
	}
}
int main()
{
	cout<<"Enter the number of characters.\n";
	int i,n,f,flag=0;
	LPTR L=NULL,T;
	cin>>n;
	HPTR H[n];
	cout<<"Enter the char and their freq\n";
	for(i=0;i<n;i++){
		H[i]=new(hcnode);
		H[i]->lc=NULL;H[i]->rc=NULL;
		cin>>H[i]->c;cin>>H[i]->i;
		cout<<"Next value\n";
	}
	//sorting
	for(int pass=1;pass<=n-1;pass++){
		flag=0;
		for(i=0;i<n-pass;i++){
			if(H[i]->i>H[i+1]->i){
				swap(H[i],H[i+1]);
				flag=1;
			}
		}
		if(flag==0)break;
	}
	for(i=0;i<n;i++){
		L=Insert(L,H[i]);
	}T=L;
	cout<<"---\n";

	HPTR root=NULL;
	root=createtree(L);
	printtree(root);cout<<"\n";
	displaybinary(root,'o',"");
}
//7t15a3m30j10k40p2s20
