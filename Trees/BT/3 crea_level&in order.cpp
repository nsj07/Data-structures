#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	char data;
	int x;
};
typedef btnode* BTPTR;
class queue{
	public:
		int size;
		int front;
		int rear;
		BTPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(BTPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		BTPTR dequeue(){
			BTPTR t;
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
		
		BTPTR Front(){
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
void inorder(BTPTR B)
{
	
	if(B!=NULL){
		static int i=1;
		inorder(B->lc);
		B->x=i++;
		inorder(B->rc);
	}
}
void printtree(BTPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	BTPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		BTPTR P=q.dequeue();
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
			cout<<P->data;prev=P->x;
			if(P->lc!=NULL) q.enqueue(P->lc);
			if(P->rc!=NULL) q.enqueue(P->rc);
		}
	}
}
int Find(char ldr[],char x)
{
	int i=0;
	while(ldr[i]!=x)i++;
	//cout<<"i="<<i<<"ldr="<<ldr[i]<<endl;
	return i;
}
BTPTR create(BTPTR T,char level[],char ldr[],int l,int h,int k)
{
	static int ls=0,rs=0;
	if(l<=h&&(ls<strlen(level)||rs<strlen(level))){
		int i;
		if(k==0){
					T=new(btnode);
		T->data=level[0];T->lc=NULL;T->rc=NULL;
		i=Find(ldr,level[0]);
		}if(k==1){
			int b=l;ls=0;
			while(b<=h&&level[ls]!=ldr[b]){
				b++;
				if(b>h){
					ls++;b=l;
				}
			}
			i=b;
			T=new(btnode);
			T->data=level[ls];T->lc=NULL;T->rc=NULL;
		}
		if(k==2){
			int b=l;rs=0;
			while(b<=h&&level[rs]!=ldr[b]){
				b++;
				if(b>h){
					rs++;b=l;
				}
			}
			i=b;
			T=new(btnode);
			T->data=level[rs];T->lc=NULL;T->rc=NULL;
		}
		if(l==h)return T;
		T->lc=create(T->lc,level,ldr,l,i-1,1);
		T->rc=create(T->rc,level,ldr,i+1,h,2);
			return T;
	}else
	return NULL;
}
void serialize(BTPTR T)
{
	if(T!=NULL){
		cout<<T->data;
		serialize(T->lc);
		serialize(T->rc);
	}else{
		cout<<".";
	}
}
int main()
{
	cout<<"Enter the levelorder string\n";
	char level[20],ldr[20];
	cin>>level;
	cout<<"Enter the inorder string\n";
	cin>>ldr;
	int l=0,h=strlen(level)-1;
	BTPTR T=NULL;
	T=create(T,level,ldr,l,h,0);
	serialize(T);
	cout<<endl;
	printtree(T);
}
//dlr_preorder//ambdfjrhn
//ldr_inorder //bmfdajhrn
//lrd_post    //bfdmhnrja
//levelorder  //amjbdrfhn
