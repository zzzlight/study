#include<stdio.h>
#include<queue>
#include<string.h> 
using namespace std;
bool G[50][50];
int line;
int potnum;
bool pre[50];
void dfs(int start)
{
	printf(" %d",start);
	pre[start]=true;
	for(int v=0;v<potnum;v++)
	{
		if(pre[v]==false&&G[start][v]==true)
		{
			dfs(v);
		}
	}
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	pre[start]=true;
	printf(" %d",start);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=0;v<potnum;v++)
		{
			if(pre[v]==false&&G[u][v]==true)
			{
				printf(" %d",v);
				q.push(v);
				pre[v]=true;
			}
		}
	}
}
int main()
{
	
	scanf("%d",&potnum);
	scanf("%d",&line);
	for(int i=0;i<line;i++)
	{
		int id1;
		int id2;
		scanf("%d",&id1);
		scanf("%d",&id2);
		G[id1][id2]=true;
		G[id2][id1]=true;
		
	}
	for(int i=0;i<potnum;i++)
	{
		if(pre[i]==false)
		{
			printf("{");
			dfs(i);
			printf(" }\n");
		}
	}
	memset(pre,0,sizeof(pre));
	for(int i=0;i<potnum;i++)
	{
		if(pre[i]==false)
		{
			printf("{");
			bfs(i);
			printf(" }\n");
		}	
	}
	
}
