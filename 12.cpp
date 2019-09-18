#include<stdio.h> 


int root;
int n;
int m;
int heap[1200];
int j=0;

void insert(int t)
{
	
	j++;
	int tempj=j;
	for(;heap[tempj/2]>t;tempj=tempj/2)
	{
		heap[tempj]=heap[tempj/2];
	}
	heap[tempj]=t;
}
void output(int start)
{
	int t=start;
	while(start>0)
	{
		if(t!=start) printf(" ");
		printf("%d",heap[start]);
		start=start/2;
	}
}
int main()
{
	heap[0]=-12000;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(temp);
	}
	
	for(int j=0;j<m;j++)
	{
		int testtemp;
		scanf("%d",&testtemp);
		output(testtemp);
		if(j!=m-1) printf("\n");
	}
}
