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

void print(LPTR P){
	if(P==NULL)
	cout<<"}";
	else
	{
		if(P->tag==1){
			cout<<"{";
			print(P->data.dlink);
			print(P->next->next);
		}
		else{
			cout<<P->data.c;
			print(P->next);
		}
	}
}

LPTR Insert(){
	LPTR head=NULL;
	//cout<<"Enter tag=0 for char and tag=1 for dlink\n";
	int tag;
	char c;
	cout<<"Tag=";
	cin>>tag;
	if(tag==0){
		cout<<"Char=";
		cin>>c;
		while(c!='0'){
			LPTR temp=new(mlnode);
			temp->tag=0;
			temp->data.c=c;
			temp->next=NULL;
			if(head==NULL)
			head=temp;
			else{
				LPTR P=head;
				while(P->next!=NULL)
				P=P->next;
				P->next=temp;
			}
			//cout<<"Enter tag=0 for char and tag=1 for dlink\n";
			cout<<"Tag=";
			cin>>tag;
			if(tag==0)
			{
				cout<<"Char=";
				cin>>c;
			}
			else{
				LPTR temp=new(mlnode);
				temp->tag=1;
				temp->data.dlink=Insert();
				temp->next=NULL;
				if(head==NULL)
				head=temp;
				else{
					LPTR P=head;
					while(P->next!=NULL)
					P=P->next;
					P->next=temp;
				}
			}
		}
	}else{
				LPTR temp=new(mlnode);
				temp->tag=1;
				temp->data.dlink=Insert();
				temp->next=NULL;
				if(head==NULL)
				head=temp;
				else{
					LPTR P=head;
					while(P->next!=NULL)
					P=P->next;
					P->next=temp;
				}				
	}
	return head;
}
int main(){
	cout<<"Start.\n";
	LPTR L=Insert();
	cout<<"Done inserting.\n{";
	print(L);
	return 0;
}
