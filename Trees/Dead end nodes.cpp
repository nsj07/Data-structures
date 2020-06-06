#include <iostream>

using namespace std;

struct bstnode{
    bstnode * lchild;
    int data;
    int min;
    int max;
    bstnode * rchild;
};

typedef bstnode* BSTPTR;

BSTPTR assign(BSTPTR T);
BSTPTR create(BSTPTR T,int k,int min,int max,BSTPTR root)
{
	if(T==NULL){
        T=new bstnode;
        T->data=k;T->min=min;T->max=max;
        T->lchild=NULL;
        T->rchild=NULL;
        if(min==max)
        cout<<"Deadend node\n";
        else{
        	//root=assign(root);
        	if(min<=k-1)
        	cout<<"Range of lchild=["<<min<<","<<k-1<<"]\n";
        	else
        	cout<<"Lchild not possible\n";
        	if(k+1<=max)
        	cout<<"Range of rchild=["<<k+1<<","<<max<<"]\n";
        	else 
        	cout<<"Rchild not possible\n";
		}
    }
    else{
    	if(k<T->data)
    	T->lchild=create(T->lchild,k,min,T->data-1,root);
    	else if(k>T->data)
    	T->rchild=create(T->rchild,k,T->data+1,max,root);
    	else
    	cout<<"Duplicate\n";
	}
	return T;
}
int min(BSTPTR T)
{
	if(T!=0){
		if(T->lchild==0)
		return T->data;
		else return min(T->lchild);
	}
}

int max(BSTPTR T)
{
	if(T!=0){
		if(T->rchild==0)
		return T->data;
		else return max(T->rchild);
	}
}
BSTPTR assign(BSTPTR T)
{
	if(T!=0){
		if(T->lchild!=0){
			T->min=max(T->lchild)+1;
		}
		if(T->rchild!=0){
			T->max=min(T->rchild)-1;
		}
		T->lchild=assign(T->lchild);
		T->rchild=assign(T->rchild);
	}
	return T;
}
void deadend(BSTPTR T)
{
	if(T!=0){
		if(T->max==T->min)
		cout<<T->data<<"  ";
		deadend(T->lchild);
		deadend(T->rchild);
	}
}
void dead(BSTPTR T,int mn,int mx)
{
	if(T!=0){
		dead(T->lchild,mn,T->data-1);
		dead(T->rchild,T->data+1,mx);
		if(T->lchild!=0)
		mn=max(T->lchild)+1;
		if(T->rchild!=0)
		mx=min(T->rchild)-1;
		if(mn==mx)
		cout<<T->data<<"  ";
		
	}
}
int main()
{
	cout<<"Enter values(-1 to end)\n";
	int n;BSTPTR T=0;
	cin>>n;
	while(n!=-1){
		T=create(T,n,1,100,T);
		T=assign(T);
		cin>>n;
	}
	cout<<"Deadend nodes are:\n";
	dead(T,1,100);
}
