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
int find(KDPTR T,int k[],int d)
{
	static int i=0;
	if(T!=NULL){
		if(k[i%d]<T->data[i%d]){
			i++;
			return find(T->lc,k,d);
		}
		else if(k[i%d]>T->data[i%d]){
			i++;
			return find(T->rc,k,d);
		}
		else{
			int j;
			for(j=0;j<d;j++){
				if(k[j]!=T->data[j])break;
			}
			if(j==d)return 1;
			else{
				i++;return find(T->lc,k,d);
			}
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
	cout<<"\n Enter the key to find.\n";
	for(j=0;j<d;j++)
	cin>>k[j];
	int f=find(T,k,d);
	f?cout<<"Found the key\n":cout<<"Not found\n";	
	
	return 0;
}
//20 5 10 3 18 70 70 15 4 10 80 36 40 30 10 80 25 15 25 32 20 85 30 75 -1 0 0
