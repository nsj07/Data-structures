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
LPTR Insert();
LPTR A,B,C,D;
void print(LPTR K){
	LPTR P=K;
	if(P==NULL)
	cout<<"}";
	else
	{
		
		if(P->data.c=='A'||P->data.c=='B'||P->data.c=='C'||P->data.c=='D'){
			char x=P->data.c;
			if(x=='A'){
				cout<<"{";
				print(A);print(P->next);
			}
			else if(x=='B'){
				cout<<"{";
				print(B);print(P->next);
			}
			else if(x=='C'){
			cout<<"{";
				print(C);print(P->next);
			}else if(x=='D'){
				cout<<"{";
				print(D);print(P->next);
			}
		}
		else{
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
}

LPTR Insert(){
	LPTR head=NULL;
	cout<<"Enter tag=0 for char and tag=1 for dlink\n";
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
	cout<<"A\n";
	A=Insert();
	cout<<"B\n";
	B=Insert();
	cout<<"C\n";
	C=Insert();
	cout<<"D\n";
	D=Insert();	
	cout<<"Done inserting.\n";
	cout<<"\nPrinting A:\n{";
	print(A);
	cout<<"\nPrinting B:\n{";
	print(B);
	cout<<"\nPrinting C:\n{";
	print(C);
	cout<<"\nPrinting D:\n{";
	print(D);
	return 0;
}
//{i b h C {j D}{k {B f}s}}
//{g h {k C} m}
//{n o p}
//{q r}
