#include <iostream>
using namespace std;

struct btnode{
	btnode* lc;
	btnode* rc;
	int data;
};
typedef btnode* BTPTR;
void Insert(int H[],int n,int k)
{
	H[n]=k;
	if(n>0&&H[(n-1)/2]>H[n])
	{
		swap(H[(n-1)/2],H[n]);
		Insert(H,(n-1)/2,H[(n-1)/2]);
	}
}
void percolatedown(int H[],int n,int total)
{
	int l=(2*n+1),r=(2*n+2);
	if(H[n]>H[l]&&H[n]>H[r]&&l<total&&r<total){
		if(H[l]<H[r]){
			swap(H[n],H[l]);
			percolatedown(H,l,total);
		}
		else{
			swap(H[n],H[r]);
			percolatedown(H,r,total);
		}
	}
	else if(H[n]>H[l]&&l<total){
		swap(H[n],H[l]);
		percolatedown(H,l,total);
	}
	else if(H[n]>H[r]&&r<total){
		swap(H[n],H[r]);
		percolatedown(H,r,total);		
	}
}
void Heapsort(int H[],int n)
{
	if(n!=0){
		cout<<H[0]<<"  ";
		H[0]=H[n-1];
		percolatedown(H,0,n-1);
		Heapsort(H,n-1);
	}
}
BTPTR heaptree(BTPTR T,int H[],int i,int n)
{
	if(T==NULL&&i<n){
		T=new btnode();
		T->lc=NULL;T->rc=NULL;
		T->data=H[i];
		if(2*i+1<n)
		T->lc=heaptree(T->lc,H,2*i+1,n);
		if(2*i+2<n)
		T->rc=heaptree(T->rc,H,2*i+2,n);
	}
	return T;
}
void ppreorder(BTPTR T)
{
	if(T!=NULL){
		cout<<T->data<<"  ";
		ppreorder(T->lc);
		ppreorder(T->rc);
	}
}
int min(int x,int y)
{
	if(x<y)return x;
	else return y;
}
int checkheaptree(BTPTR T)
{
	if(T!=NULL){
		if(T->lc!=NULL&&T->rc!=NULL){
			if(T->lc->data>T->data&&T->rc->data>T->data)
			return min(checkheaptree(T->lc),checkheaptree(T->rc));
			else return 0;
		}
		else if(T->lc!=NULL){
			if(T->lc->data>T->data)
			return checkheaptree(T->lc);
			else return 0;
		}
		else if(T->rc!=NULL){
			if(T->rc->data>T->data)
			return checkheaptree(T->rc);
		}
	}
	return 1;
}
int main()
{
	int k,H[50],n=0;
	cout<<"Enter the values(-1 to terminate)\n";
	cin>>k;
	while(k!=-1){
		Insert(H,n,k);
		n++;
		cin>>k;
	}
	cout<<"Values in array:\n";
	for(int i=0;i<n;i++)
	cout<<H[i]<<"  ";
	cout<<"\nPreorder:\n";
	BTPTR T=NULL;
	T=heaptree(T,H,0,n);
	ppreorder(T);cout<<"\n";
	int c=checkheaptree(T);
	c?cout<<"It is a heap tree\n":"Not a heap tree\n";
	cout<<endl<<"Heap sorting:\n";
	Heapsort(H,n);	
	return 0;
	
}
//7 21 5 10 2 36 18 3 1 -1
