#include <iostream>
using namespace std;

struct dnode
{
    int data;
    struct dnode *right;
    struct dnode *left;
    int x;
};
 typedef dnode* DPTR;
 DPTR root=NULL;
class queue{
	public:
		int size;
		int front;
		int rear;
		DPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(DPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		DPTR dequeue(){
			DPTR t;
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
		
		DPTR Front(){
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
DPTR mid(DPTR L,DPTR R)
{
//	cout<<"L="<<L->data<<" R= "<<R->data<<endl;
	DPTR S=L,F=L,P;
	while(F!=R){		
		P=F->right;
		if(P==R){
			S=S->right;
			F=P;
		}else{
			S=S->right;
			F=P->right;
		}
	}
//	cout<<"S->data= "<<S->data<<endl;
return S;
}
DPTR createBST(DPTR L,DPTR R)
{
	DPTR P;
	if(R!=NULL&&L!=R&&L!=R->right)
	{
		P=mid(L,R);
//		cout<<"P-data="<<P->data<<" L="<<L->data<<" R= "<<R->data<<endl;
		P->left=createBST(L,P->left);
//		cout<<";;;;;;;;;;\n";
		P->right=createBST(P->right,R);
		
	}else{
		if(L==R){
			L->left=NULL;L->right=NULL;
			return L;
		}
		return NULL;
	}return P;
}
void printList(DPTR P)
{
    while (P!=NULL)
    {
        cout << P->data << "  ";
        P = P->right;
    }
    cout << endl;
}
DPTR Insert()
{
	DPTR D=NULL;
	int n;
	cin>>n;
	while(n!=-1)
	{
		DPTR temp=new(dnode);
		temp->data=n;temp->left=NULL;temp->right=NULL;
		if(D==NULL)D=temp;
		else{
			DPTR X=D;
			while(X->right!=NULL)
			X=X->right;
			X->right=temp;temp->left=X;
		}cin>>n;
	}
	return D;
}
void printinorder(DPTR B)
{
	if(B!=NULL){
		printinorder(B->left);
		cout<<B->data<<"  ";
		printinorder(B->right);
	}
}
DPTR minv(DPTR P)
{
	if(P->left==NULL)
	return P;
	else
	return minv(P->left);
}
void inorder(DPTR B)
{
	static int i=1;
	if(B!=NULL){
		inorder(B->left);
		B->x=i++;
		//cout<<B->data<<"  "<<B->x<<endl;
		inorder(B->right);
	}
}
void printtree(DPTR T)
{
	inorder(T);
	queue q;
	q.enqueue(T);
	DPTR L=NULL;
	q.enqueue(L);
	int prev=0,present;
	while(!q.isempty())
	{
		DPTR P=q.dequeue();
		if(P!=NULL)present=P->x;
		if(P==NULL){
			prev=0;
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			for(int i=1;i<=present-prev;i++)
			cout<<"   ";
			cout<<P->data;prev=P->x;
			if(P->left!=NULL) q.enqueue(P->left);
			if(P->right!=NULL) q.enqueue(P->right);
		}
	}
}
int main()
{
	cout<<"Enter values in ascending order ,-1 to terminate.\n";
	DPTR D=Insert(),X=D;
 	while(X->right!=NULL)
 	X=X->right;
//    cout << "Linked List before sorting \n";
    printList(D);
    cout<<endl;
    root=createBST(D,X);
    cout<<endl;
    printtree(root);
}
//2 5 6 9 12 16 18 20 36 45 -1
