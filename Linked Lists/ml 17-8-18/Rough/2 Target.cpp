#include <iostream>
using namespace std;

struct muNode
{
	int data;
	int ctr;
	muNode *next[10];
};

struct queue
{
	int front;
	int rear;
	int size;
	int elements[50];
};

void enqueue(queue &q, int x)
{
	if ((q.rear + 1) % q.size == q.front)
	{
		cout << "Queue is full\n";
	}
	else
	{
		if (q.front == -1)
		{
			q.front++;
		}
		q.rear = (q.rear + 1) % q.size;
		q.elements[q.rear] = x;
	}
}

int dequeue(queue &q)
{
	if (q.front == -1)
	{
		cout << "Queue is empty\n";
	}
	else
	{
		int temp = q.elements[q.front];
		if (q.front == q.rear)
		{
			q.front = -1;
			q.rear = -1;
		}
		else
		{
			q.front = (q.front + 1) % q.size;
		}
		return temp;
	}
}

bool isEmpty(queue q)
{
	if (q.front == -1)
	{
		return 1;
	}
	return 0;
}
void fillList(muNode *m,int &x)
{
	cout << "Enter data followed by number of nodes\n";
	cin >> m->data >> m->ctr;
	x++;
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
			fillList(m->next[i],x);
		}
	}
}

void print(muNode *m)
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
void pathFinder(muNode *m,int req, queue q,bool &b)
{
	enqueue(q, m->data);
	if (m->data == req)
	{
		cout << "The required path is\n";
		while (!isEmpty(q))
		{
			cout << dequeue(q) << " ";
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
	muNode *m = new muNode;
	int x = 0,y = 0;
	fillList(m,x);
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
