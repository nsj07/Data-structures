#include <iostream>

using namespace std;

struct muNode
{
	int data;
	int ctr;
	muNode *next[10];
};
typedef muNode* MPTR;
struct queue{
	public:
		int size;
		int front;
		int rear;
		int elements[50];
		
		void enqueue(int x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		int dequeue(){
			int t;
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
		
		int Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isEmpty(){
			if(front==-1)return 1;
			else return 0;
		}
};

void fillList(MPTR m)
{
	cout << "Enter data followed by number of nodes\n";
	cin >> m->data >> m->ctr;
	if (m->ctr == 0)
	{
		m->next[0] = NULL;
	}
	else
	{
		for (int i = 0; i < m->ctr; i++)
		{
			m->next[i] = new muNode;
			cout << "Fill branch " << i + 1 <<" of the node with data "<<m->data<<endl;
			fillList(m->next[i]);
		}
	}
}

void print(MPTR m)
{
	if (m->ctr == 0)
	{
		cout << m->data << " ";
	}
	else
	{
		cout << m->data << " ";
		for (int i = 0; i < m->ctr; i++)
		{
			cout << endl;
			if (i != 0)
			{
				cout << "Branch " << i + 1 << " of the node with data " << m->data << endl;
			}
			print(m->next[i]);
			cout << endl;
		}
	}
}

void pathFinder(MPTR m,int req,struct queue q,bool &b)
{
	q.enqueue(m->data);
	if (m->data == req)
	{
		cout << "The required path is\n";
		while (!q.isEmpty())
		{
			cout << q.dequeue() << " ";
		}
		b = true;
		return;
	}
	if (b == false)
	{
		if (m->ctr == 0)
		{
			return;
		}
		else
		{
			for (int i = 0; i < m->ctr; i++)
			{
				pathFinder(m->next[i], req, q, b);
				if (b == true)
				{
					break;
				}
			}
		}
	}
}

int main()
{
	MPTR m = new muNode;
	
	fillList(m);
	queue q;
	q.size = 50;
	q.front = -1;
	q.rear = -1;
	cout << "Enter the number required\n";
	int z;
	cin >> z;
	bool b = false;
	pathFinder(m,z,q,b);
	if (b == false)
	{
		cout << "Key not found\n";
	}
	return 0;
}
