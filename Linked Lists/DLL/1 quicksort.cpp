#include <iostream>
using namespace std;

struct dnode
{
	struct dnode *left;
	int data;
	struct dnode *right;
};
typedef dnode* DPTR;
void swap(int &x,int &y)
{
	int z=x;
	x=y;y=z;
}
DPTR Insert(){
	DPTR D=NULL;
	cout<<"Enter value ,-1 to terminate.\n";
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
		}cout<<"Value=";cin>>n;
	}
	return D;
}
void print(DPTR D)
{
	while(D!=NULL){
		cout<<D->data<<",";
		D=D->right;
	}cout<<endl;
}
DPTR partition(DPTR l,DPTR h)
{
	int x  = l->data;   
    DPTR i = h->right;    
    for (DPTR j = h; j != l; j = j->left)
    {
        if (j->data <= x)
        {            
            i = (i == NULL)? l : i->left; 
            swap((i->data), (j->data));
        }
    }
    i = (i == NULL)? l : i->left;
    swap((i->data), (h->data));
    return i;
}
void quicksort(DPTR low,DPTR high)
{
	DPTR J;
	if(high->right!=low&&high!=NULL&&low!=high){
		cout<<"__________\n";
		J=partition(low,high);
		cout<<J->data<<"----\n";
		quicksort(low,J->left);
		quicksort(J->right,high);
	}
}

int main(){
	DPTR D=Insert(),X=D;
	print(D);
	while(X->right!=NULL)
	X=X->right;
	cout<<"sort\n";
	quicksort(D,X);
	cout<<"Sorted:\n";
	print(D);
	return 0;
}
