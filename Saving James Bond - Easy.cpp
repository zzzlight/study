#include<stdio.h>
#include<queue>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;


int mydistance;
int potnum;

struct node
{
	int l;
	int r;
};
bool pre[102];
vector<node> pot;
vector<node> result;
bool judge(node test)
{
	if(test.l+mydistance>=50||test.l-mydistance<=-50||test.r+mydistance>=50||test.l-mydistance<=-50)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool jump(node u,node v)
{
	int juli=mydistance*mydistance;
	int cha=(u.l-v.l)*(u.l-v.l)+(u.r-v.r)*(u.r-v.r);
	if(cha<=juli)
	{
		return true;
	}
	else 
	return false;
}
bool firstjump(int x)
{
	int num1=(pot[x].l)*(pot[x].l);
	
	int num2=(pot[x].r)*(pot[x].r);
	int sum=(mydistance+7.5)*(mydistance+7.5);
	if(num1+num2<=sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool answer=false;
void dfs(int u)
{
	pre[u]=true;
	if(judge(pot[u]))  answer=true;
	for(int v=0;v<potnum;v++)
	{
		if(pre[v]==false&&jump(pot[u],pot[v]))
		{
			dfs(v);	
		}
	}
	

}
int main()
{
	scanf("%d",&potnum);
	scanf("%d",&mydistance);
	
	for(int i=0;i<potnum;i++)
	{
		int id1;
		int id2;
		node temp;
		scanf("%d",&id1);
		scanf("%d",&id2);
		temp.l=id1;
		temp.r=id2;
		pot.push_back(temp);
		
	}

	bool flag=false;
	for(int i=0;i<potnum;i++)
	{
	
		if(firstjump(i)&&pre[i]==false)
		{
			dfs(i);
			if(answer)
			{
				
				flag=true;
				break;
			}
			
		}
	 } 

	if(flag==true)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
		
 } 
