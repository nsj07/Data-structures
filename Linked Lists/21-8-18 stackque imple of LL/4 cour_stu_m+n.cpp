#include <iostream>
#include <cstring>
using namespace std;

struct lnode{
	
	char cour[10];
	char stu[10];
	lnode *next;
	lnode *dlink;
};
typedef lnode* LPTR;
struct nnode{
	char data[10];
	LPTR dlink;
	nnode *next;
};
typedef nnode* NPTR;
NPTR S=NULL,C=NULL;
void printname(NPTR L){
	while(L!=NULL){
		cout<<L->data<<"  ";
		L=L->next;
	}cout<<endl;
}
NPTR Insertname(){
	cout<<"Enter name, 0 to terminate.\n";
	char s[10];
	cin>>s;
	NPTR P=NULL;
	while(s[0]!='0')
	{
		NPTR temp=new(nnode);
		strcpy(temp->data,s);temp->dlink=NULL;temp->next=NULL;
		if(P==NULL)P=temp;
		else
		{
			NPTR X=P;
			while(X->next!=NULL)X=X->next;
			X->next=temp;
		}
		cout<<"Name=";cin>>s;
	}
	return P;
}
void assign(NPTR &S,NPTR &C)
{
	NPTR s=S,c=C;
	while(s!=NULL)
	{
		cout<<"Enter 1 if "<<s->data<<" choosen a course or not else 0.\n";
		while(c!=NULL)
		{
			cout<<c->data<<" = ";
			int i;
			cin>>i;
			if(i==1){
			LPTR temp=new(lnode);
			//cout<<c->data<<" = ";cin>>temp->data;
			temp->next=NULL;temp->dlink=NULL;
			strcpy(temp->cour,c->data);
			strcpy(temp->stu,s->data);
			if(c->dlink==NULL) c->dlink=temp;
			else{
				LPTR X=c->dlink;
				while(X->next!=NULL)X=X->next;
				X->next=temp;
			}
			if(s->dlink==NULL) s->dlink=temp;
			else{
				LPTR X=s->dlink;
				while(X->dlink!=NULL)X=X->dlink;
				X->dlink=temp;
			}
			}
			
			c=c->next;
		}s=s->next;c=C;
	}
}
void display(NPTR S,NPTR C)
{
	NPTR s=S,c=C;
	cout<<"\nStudents are :\n";
	printname(s);
	cout<<"Courses are :\n";
	printname(c);
	cout<<"Courses taken by respective students are:\n";
	while(s!=NULL)
	{
		cout<<s->data<<" : ";
		LPTR L=s->dlink;
		while(L!=NULL)
		{
			cout<<L->cour<<" ";
			L=L->dlink;
		}s=s->next;
		cout<<endl;
	}
	s=S;c=C;
	cout<<"Students who taken respective courses.\n";
	while(c!=NULL)
	{
		cout<<c->data<<" : ";
		LPTR L=c->dlink;
		while(L!=NULL)
		{
			cout<<L->stu<<" ";
			L=L->next;
		}c=c->next;
		cout<<endl;
	}
}

int main(){
	cout<<"Enter student names.\n";
	S=Insertname();
	printname(S);
	cout<<"Enter courses names.\n";
	C=Insertname();
	assign(S,C);
	display(S,C);
	
	return 0;
}
