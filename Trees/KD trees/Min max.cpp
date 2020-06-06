#include <iostream>
using namespace std;

struct kdnode{
	kdnode* lc;
	int data[10];
	kdnode* rc;
};
typedef kdnode* KDPTR;

KDPTR create(KDPTR T,int k[],int d,int i)
{
	if(T==NULL){
		T=new(kdnode);
		T->lc=NULL;T->rc=NULL;int j=0;
		for(j=0;j<d;j++)
		T->data[j]=k[j];
	}
	else{
		if(k[i]<=T->data[i])
		T->lc=create(T->lc,k,d,(i+1)%d);
		else
		T->rc=create(T->rc,k,d,(i+1)%d);
	}
	return T;
}

void ppreorder(KDPTR T,int d)
{
	if(T!=NULL){
		int j;cout<<"(";
		for(j=0;j<d;j++)
		{
			cout<<T->data[j];
			j==d-1?cout<<"":cout<<",";
		}
		cout<<")  ";
		ppreorder(T->lc,d);
		ppreorder(T->rc,d);
	}
}
int minvalue(int x,int y,int z)
{
	if(x<y&&x<z)return x;
	else if(y<z&&y<x)return y;
	else if(z<x&&z<y)return z;
}
int min(KDPTR T,int i,int d,int j)
{
	if(T!=NULL){
		int m=T->data[i];
		if(j%d==i){
			if(T->lc!=NULL)return min(T->lc,i,d,j+1);
			else return m;
		}
		else{
			return minvalue(m,min(T->lc,i,d,j+1),min(T->rc,i,d,j+1));
		}
	}
	return 1000;
}
int maxvalue(int x,int y,int z)
{
	if(x>y&&x>z)return x;
	else if(y>z&&y>x)return y;
	else if(z>x&&z>y)return z;
}
int max(KDPTR T,int i,int d,int j)
{
	if(T!=NULL){
		int m=T->data[i];
		if(j%d==i){
			if(T->rc!=NULL)return max(T->rc,i,d,j+1);
			else return m;
		}
		else{
			return maxvalue(m,max(T->lc,i,d,j+1),max(T->rc,i,d,j+1));
		}
	}
	return 0;
}
int main()
{
	cout<<"Enter the dimension of kd tree \n";
	int d,j;
	cin>>d;int k[d];
	KDPTR T=NULL;
	cout<<"Enter the key values(-1 to terminate)\n";
	for(j=0;j<d;j++)
	cin>>k[j];
	while(k[0]!=-1){
		T=create(T,k,d,0);
		cout<<"Enter next key\n";
		for(j=0;j<d;j++)
		cin>>k[j];
	}
	ppreorder(T,d);	
	cout<<"\nMinimum values are:\n";
	for(int i=0;i<d;i++){
		cout<<"k["<<i+1<<"]="<<min(T,i,d,0)<<endl;
	}
	cout<<"\nMaximum values are:\n";
	for(int i=0;i<d;i++){
		cout<<"k["<<i+1<<"]="<<max(T,i,d,0)<<endl;
	}	
	return 0;
}
//3 20 5 10 3 18 70 70 15 4 10 80 36 40 30 10 80 25 15 25 32 20 85 30 75 -1 0 0
//2 20 50 3 18 40 5 10 80 70 3 80 25 2 60 -1 0
