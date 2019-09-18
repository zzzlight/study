#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	int data;
	int leftchild=-1;
	int rightchild=-1;
}node[200];
bool mark[200];
vector<int> result;
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		char temp1;
		char temp2;
		cin>>temp1>>temp2;
		
		if(temp1!='-')
		{
			node[i].leftchild=temp1-'0';
			mark[node[i].leftchild]=true;
		}
		if(temp2!='-')
		{
			node[i].rightchild=temp2-'0';
			mark[node[i].rightchild]=true;
		
		}
	}
	int root;
	for(int i=0;i<num;i++)
	{
		if(mark[i]==false)
		{
			root=i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(node[now].leftchild!=-1)
		{
			q.push(node[now].leftchild);
		}
		if(node[now].rightchild!=-1)
		{
			q.push(node[now].rightchild);
		}
		if(node[now].rightchild==-1&&node[now].leftchild==-1)
		{
			result.push_back(now);
		}
	}
	for(auto it=result.begin();it!=result.end();it++)
	{
		cout<<(*it);
		if(it!=result.end()-1) cout<<' ';
	}
}
