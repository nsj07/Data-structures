#include <iostream>
#include <cstring>
using namespace std;

class queue{
	public:
		int size;
		int front,rear;
		string elements[50];
		
		queue(){
			size=50;
			front=-1;rear=-1;
		}
		void enqueue(string s){
			if((rear+1)%size==front)cout<<"Full.\n";
			else{
				if(rear==-1)
					front =0;
				rear=(rear+1)%size;
				elements[rear]=s;
			}
		}
		
		string dequeue(){
			if(front==-1)
			cout<<"...Empty.\n";
			else{
				string x=elements[front];
				if(front==rear){
					front=-1;rear=-1;
				}else
				front=(front+1)%size;
				return x;
			}
			
		}
		
		string Front(){
			if(front==-1)
			cout<<"--Empty.\n";
			else{
				return elements[front];
			}
		}
};

int op(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return 1;
	else return 0;
}

string conv(queue q){
	if(q.front==q.rear)
	return q.dequeue();
	else{
		string t=q.dequeue(),t2,t3;
		if(op(t[0])){
			if(!op(q.Front()[0])){
				t2=q.dequeue();
				if(!op(q.Front()[0])){
					t3=q.dequeue();
					string temp=t2+t3;
					temp=temp+t;
					q.enqueue(temp);
					return conv(q);
				}else{
					q.enqueue(t);
					q.enqueue(t2);
					return conv(q);				}
			}else{
				q.enqueue(t);
				return conv(q);
			}
		}else{
			q.enqueue(t);
			return conv(q);
		}
	}
}

int main(){
	queue q;
	cout<<"Enter the prefix string.\n";
	string c;
	cin>>c;
	int i,n=c.length();
	for(i=0;i<n;i++){
		string s="";
		s+=c[i];
		q.enqueue(s);
	}
	string postfix=conv(q);
	cout<<"Postfix string= "<<postfix<<endl;
	return 0;
}
//**+AB-+CDEF
