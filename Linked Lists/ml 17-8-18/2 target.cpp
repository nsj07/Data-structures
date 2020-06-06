#include <iostream>
using namespace std;


struct mlnode{
	int data;
	int countn;
	mlnode *next[10];
};
typedef mlnode* LPTR;
struct s1{
	LPTR ml;
	int i;
};

class stack{
	public:
	int size;
	int top;
	s1 elements[50];
	stack(){
		size=50;
		top=-1;
	}	
	void push(s1 x){
	if(top==(size-1))
	cout<<"Stack is full\n";
	else
	elements[++top]=x;
}
s1 pop(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top--];
}
s1 Top(){
	if(top==-1)
	cout<<"Stack is empty\n";
	else
	return elements[top];
}
};
LPTR Insert(){
	LPTR head=NULL;
	cout<<"Enter count=1 for singlelink, or else other.\n";
	int count,x;
	cin>>count;
	if(count==1){
		cout<<"Value=";
		cin>>x;
		while(x!=-1){
			LPTR temp=new(mlnode);
			temp->data=x;
			temp->countn=1;
			temp->next[0]=NULL;
			if(head==NULL)
			head=temp;
			else{
				LPTR P=head;
				while(P->next[0]!=NULL)
				P=P->next[0];
				P->next[0]=temp;
			}
			cout<<"Count=";
			cin>>count;
			if(count==1){
				cout<<"Value=";
				cin>>x;
			}else{
				cout<<"Value=";
				cin>>x;
			LPTR temp=new(mlnode);
			temp->data=x;
			temp->countn=count;	
			int i=0;
			for(i=0;i<count;i++){
				cout<<"Enter contents of "<<i+1<<" list.\n";
				temp->next[i]=Insert();
			}
			if(head==NULL)
			head=temp;
			else{
				LPTR P=head;
				while(P->next[0]!=NULL)
				P=P->next[0];
				P->next[0]=temp;
			}						
			}
		}
	}else{
			cout<<"Value=";
			cin>>x;
			LPTR temp=new(mlnode);
			temp->data=x;
			temp->countn=count;	
			int i=0;
			for(i=0;i<count;i++){
			cout<<"Enter contents of "<<i+1<<" list.\n";
			temp->next[i]=Insert();	
		}
		if(head==NULL)
			head=temp;
			else{
				LPTR P=head;
				while(P->next[0]!=NULL)
				P=P->next[0];
				P->next[0]=temp;
			}
	}return head;
		
}

void check(stack &s,int n){
	s1 b=s.pop();int flag=0;
	for(;b.i<b.ml->countn;b.i++){
		LPTR P=b.ml->next[b.i];
		while(P->countn==1&&P!=NULL){
			if(P->data==n){
				flag=1;
				while(s.top!=-1){
					s1 c=s.pop();
					cout<<c.ml->data<<",";
					LPTR K=c.ml->next[c.i];
					if(s.top!=-1){
						while(K!=s.Top().ml){
							cout<<K->data<<",";
							K=K->next[0];
						}
					}else{
						while(K->data!=P->data){
							cout<<K->data<<",";
							K=K->next[0];
						}cout<<P->data<<endl;
					}
				}break;
			}else
			P=P->next[0];
		}if(flag==1)break;
		if(P->countn!=1){
			if(P->data==n){
				flag=1;
				while(s.top!=-1){
					s1 c=s.pop();
					cout<<c.ml->data<<",";
					LPTR K=c.ml->next[c.i];
					if(s.top!=-1){
						while(K!=s.Top().ml){
							cout<<K->data<<",";
							K=K->next[0];
						}
					}else{
						while(K->data!=P->data){
							cout<<K->data<<",";
							K=K->next[0];
						}cout<<P->data<<endl;
					}
				}break;	
			}
			s1 c;
			c.ml=P;c.i=0;
			s.push(b);s.push(c);
			check(s,n);
		}
		
	}if(flag==0)
	cout<<"Not found.\n";
}

int main(){
	stack s;
	LPTR L=Insert();
	cout<<"Enter the value to find.\n";
	int n;
	cin>>n;
	LPTR P=L;
	while(P!=NULL){
		if(P->data==n)cout<<P->data<<",";
		else if(P->countn==1){
			cout<<P->data<<",";
			P=P->next[0];
		}else{
			cout<<P->data<<",";
			s1 a;
			a.ml=P;a.i=0;s.push(a);
			check(s,n);
			P=NULL;
		}
	}
	
}

