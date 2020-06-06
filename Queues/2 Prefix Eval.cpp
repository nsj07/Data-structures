#include <iostream>
#include <cstring>
using namespace std;

struct s1{
	char c;
	int i;
	int t;
};

s1 eval(s1 y,s1 z,s1 x){
	s1 ans;
	if(x.c=='+') ans.i=y.i+z.i;
	else if(x.c=='-') ans.i=y.i-z.i;
	else if(x.c=='*') ans.i=y.i*z.i;
	else ans.i=y.i/z.i ;
	ans.t=2;
	return ans;
}


class queue{
	public:
		int size;
		int front,rear;
		s1 elements[50];
		
		queue(){
			size=50;
			front=-1;rear=-1;
		}
		void enqueue(s1 s){
			if((rear+1)%size==front)cout<<"Full.\n";
			else{
				if(rear==-1)
					front =0;
				rear=(rear+1)%size;
				
				if(s.t==1){
					elements[rear].c=s.c;
					elements[rear].t=s.t;
				}else{
					elements[rear].i=s.i;
					elements[rear].t=s.t;
				}
			}
		}
		
		s1 dequeue(){
			if(front==-1)
			cout<<"...Empty.\n";
			else{
				s1 x=elements[front];
				if(front==rear){
					front=-1;rear=-1;
				}else
				front=(front+1)%size;
				return x;
			}
			
		}
		
		s1 Front(){
			if(front==-1)
			cout<<"--Empty.\n";
			else{
				return elements[front];
			}
		}
};

void assign(char x,queue &q){
	s1 s;
	if(x=='+'||x=='-'||x=='*'||x=='/'){
		s.c=x;
		s.t=1;
	}
	else{
		s.i=x-48;
		s.t=2;
	}
	q.enqueue(s);
}
int main(){
	queue q;
	s1 s;
	char c[50];
	cout<<"Enter the prefix string.\n";
	cin>>c;
	int n=strlen(c),i;
	for(i=0;i<n;i++){
		assign(c[i],q);
	}
	
	while(q.front!=q.rear){
		s1 x=q.dequeue(),y,z;
		if(x.t==1){
			if(q.Front().t==2){
				y=q.dequeue();
				if(q.Front().t==2){
					z=q.dequeue();
					q.enqueue(eval(y,z,x));
				}
				else{
					q.enqueue(x);
					q.enqueue(y);
				}
			}
			else{
				q.enqueue(x);
			}
		}
		else{
			q.enqueue(x);
		}
	}
	cout<<"Answer="<<q.Front().i<<endl;
	return 0;
}
