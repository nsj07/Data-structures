#include <iostream>
#include <cstring>
using namespace std;

class stack{
	public:
	int size;
	int top;
	char elements[50];
	
	stack(){
		size=50;
		top=-1;
		
	}	
	void push(char x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	char pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	char Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
	int isempty(){
		if(top==-1)return 1;
		else return 0;
	}
};

class queue{
	public:
		int size;
		int front;
		int rear;
		char elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(char x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		char dequeue(){
			char t;
			if(front==-1)cout<<"Empty\n";
			else{
				t=elements[front];
				if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				else front =(front+1)%size;
				return t;
			}
		}
		
		char Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
};
int main(){
	cout<<"Enter the string.\n";
	char c[50];
	cin>>c;
	stack s;
	queue q;
	int n=strlen(c),i;
	for(i=0;i<n;i++){
		s.push(c[i]);
	}
	
	while(s.top!=-1){
		char x=s.pop(),y;
		if(s.top==-1)break;
		while(s.top!=0)
		q.enqueue(s.pop());
		y=s.pop();
		
		if(x==y){
			while(q.front!=-1)
			s.push(q.dequeue());
		}
		
		else{
			cout<<"Not palindrome.\n";
			break;
		}
	}
	if(s.top==-1 && q.front==-1)
	cout<<"Palindrome.\n";
	
	return 0;
}
