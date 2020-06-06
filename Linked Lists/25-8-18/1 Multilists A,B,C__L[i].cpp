#include <iostream>
using namespace std;

union u{
	char c;
	struct mlnode *dlink;
};
struct mlnode{
	union u data;
	int tag;
	mlnode *next;
};
typedef mlnode* LPTR;
LPTR L[10];
char l[10];
LPTR Insert()
{
	char c;
	cin>>c;
	LPTR temp=new(mlnode);temp->next=NULL;
	if(c=='{'){
		temp->tag=1;
		temp->data.dlink=Insert();
		temp->next=Insert();
	}
	else if(c>=65&&c<=90){
		int j=0;
		while(l[j]!=c)j++;
		if(L[j]==NULL){
		cout<<"Enter elements of "<<c<<endl;
		temp->tag=1;
		temp->data.dlink=Insert();		
		L[j]=temp->data.dlink;
		}
		else{
			temp->tag=1;
		temp->data.dlink=L[j];	
		}
		temp->next=Insert();
	}
	else if(c>=97&&c<=122){
		temp->tag=0;temp->data.c=c;
		temp->next=Insert();
	}
	else if(c=='}'){
		return NULL;
	}
	return temp;
}
void print(LPTR K)
{
	
	if(K!=NULL){
		if(K->tag==0){
			cout<<K->data.c<<" ";
			print(K->next);
		}else{
			cout<<"{";
			print(K->data.dlink);
			print(K->next);
		}
		return;
	}
	else{
		cout<<"}";
		return;
	}
	cout<<endl;
}

int main()
{
	cout<<"Enter the number of list names.\n";
	int i,n;
	cin>>n;
	cout<<"Enter the list names in capitals.\n";
	for(i=0;i<n;i++){
		cin>>l[i];L[i]=NULL;
	}	
	for(i=0;i<n;i++)
	{
		if(L[i]==NULL){
			cout<<"Insert elements of "<<l[i]<<endl;
			L[i]=Insert();
		}
	}
	for(i=0;i<n;i++){
		cout<<"Printing "<<l[i]<<":\n";
	cout<<"{";
	print(L[i]);
	cout<<endl;
	}	
	
	return 0;
}
