#include <iostream>
using namespace std;

void swap(int &x,int &y)
{
	int z=x;
	x=y;y=z;
}

int partition(int A[],int low,int high)
{
	int l,h,p;
	p=A[low];l=low+1;h=high;
	while(l<h)
	{
		while(A[l]<p)l++;
		while(A[h]>p)h--;
		if(l<h)swap(A[l],A[h]);
	}swap(A[low],A[h]);
	return h;
}
void quicksort(int A[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(A,low,high);
		quicksort(A,low,j-1);
		quicksort(A,j+1,high);
	}
}

int main(){
	int A[]={60,92,92,43,65,31,57,26,75};
	quicksort(A,0,8);
	for(int i=0;i<9;i++)
	cout<<A[i]<<",";
	cout<<endl;
	return 0;
}
