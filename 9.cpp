#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int tree[3000];
int tree1[3000];
vector<bool> result;
void insert(int num,int t)
{
	if(tree[t]==0) tree[t]=num;
	else 
	{
		if(tree[t]>num) insert(num,t*2);
		else if(tree[t]<num)  insert(num,t*2+1);
	}
	
	
}
void insert2(int num,int t)
{
	if(tree1[t]==0) tree1[t]=num;
	else 
	{
		if(tree1[t]>num) insert2(num,t*2);
		else if(tree1[t]<num)  insert2(num,t*2+1);
	}
	
	
}
int main()
{
	int temp;
	scanf("%d",&temp);
	while(temp!=0)
	{
		int checknum;
		scanf("%d",&checknum);
		
		for(int i=0;i<temp;i++)
		{
			int insertnum;
			scanf("%d",&insertnum);
			insert(insertnum,1);
		}
		
		for(int j=0;j<checknum;j++)
		{
			for(int i=0;i<temp;i++)
			{
				int insertnum;
				scanf("%d",&insertnum);
				insert2(insertnum,1);
			}
			
			bool flag=true;
			for(int t=1;t<3000;t++)   //由于用的类似堆的数组存储形式 下标上限不一定是temp  发现测试点2下标最大在1001  用3000即可ac 
			{
				if(tree[t]!=tree1[t]) 
				{
					flag=false;
					break;	
				}
			}
			
			result.push_back(flag);
			memset(tree1,0,sizeof(tree1));
		}
		memset(tree,0,sizeof(tree));
		scanf("%d",&temp);
	}
	for(auto it=result.begin();it!=result.end();it++)
	{
		if((*it)==true) printf("Yes");
		else printf("No");
		if((it)!=(result.end()-1)) printf("\n");
	}
 } 
