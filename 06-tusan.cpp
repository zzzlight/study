#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;


bool node[10001][10001];
bool inque[10001];
int layer[10001];
int potnum;
int edgenum;
int BFS(int start)
{
	memset(layer,0,10001);
	memset(inque,0,10001);
	int num=0;
	queue<int> q;
	q.push(start);
	inque[start]=true;
	while(!q.empty())
	{
		int u=q.front();
		//printf(" %d(%d) ",u,layer[u]);
		q.pop();
		for(int v=1;v<=potnum;v++)
		{
			if(inque[v]==false&&node[u][v]!=false)
			{
				inque[v]=true;
				layer[v]=layer[u]+1;
				q.push(v);
			}
		 } 
		 
	}
	for(int t=1;t<=potnum;t++)
	{
		if(layer[t]<=6&&layer[t]>0) num++;
	}
	return num+1;
}
int main()
{
	
	scanf("%d",&potnum);
	scanf("%d",&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d",&id1);
		scanf("%d",&id2);
		node[id1][id2]=true;
		node[id2][id1]=true;
	 } 
	 for(int j=1;j<=potnum;j++)
	 {
	 	double result;
	 	int temp;
	 	temp=BFS(j);
	 	result=(double)temp/potnum*100;
		printf("%d: %0.2lf%%",j,result);
			 if(j!=potnum) printf("\n");  
		 
		                 
	 }
 } 
