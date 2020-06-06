#include <iostream>
#include <cstring>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
	int pos;
};
typedef btnode* BTPTR;
class stack{
	public:
	int size;
	int top;
	BTPTR elements[50];
	stack(){
		top=-1;size=50;
	}	
	void push(BTPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	BTPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	BTPTR Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
	int isEmpty(){
		if(top==-1)return 1;
		else return 0;
	}
};
void create(BTPTR &T,int k)
{
	if(T==NULL){
		T=new(btnode);
		T->data=k;T->lc=NULL;T->rc=NULL;
	}
	cout<<"Inserting left child of "<<T->data<<" (else type 0)"<<endl;
	int s;cin>>s;
	if(s!=0){
		create(T->lc,s);
	}
	cout<<"Inserting right child of "<<T->data<<" (else type 0)"<<endl;
	cin>>s;
	if(s!=0){
		create(T->rc,s);
	}	
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
void assignpos(BTPTR T,int i,char x,int &min,int &max)
{
	if(T!=NULL){
		if(x=='c'){
			T->pos=i;min=i;max=i;
		}
		if(x=='l'){
			T->pos=i-1;i--;
			if(i<min)min=i;
		}
		if(x=='r'){
			T->pos=i+1;i++;
			if(i>max)max=i;
		}
		assignpos(T->lc,i,'l',min,max);
		assignpos(T->rc,i,'r',min,max);
	}
}
void bottom(BTPTR T,stack s[],int min)
{
	if(T!=NULL){
		s[T->pos-min].push(T);
		bottom(T->lc,s,min);
		bottom(T->rc,s,min);
	}
}

int main()
{
	BTPTR T=NULL;
	cout<<"Enter root value.\n";
	int n,min,max;
	stack s[15];
	cin>>n;
	create(T,n);
	assignpos(T,0,'c',min,max);
	bottom(T,s,min);
	cout<<"Bottom view nodes are:\n";
	for(int i=0;i<=max-min;i++){
		cout<<s[i].Top()->data<<"  ";
	}cout<<endl;
	
}
