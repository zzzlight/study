#include<iostream>
#include<vector>

using namespace std;
vector<bool> result;
int father[10010];
int num;
bool isroot[10010];
int findfather(int x)
{
	int a=x;  //x用a备份 若不做合并此步不需要 
	while(x!=father[x])
	{
		x=father[x];   //x作为移动变量 
	}
	while(a!=father[a])
	{
		father[a]=x;
		a=father[a];   //每一次的路径上的点 都将其父亲节点设置为前面while找到的根 
	}
	return x;
}
bool check(int a,int b)
{
	int temp1=findfather(a);
	int temp2=findfather(b);  //更新一下  此题特供 
	if(father[a]==father[b])
	return true;
	else return false;
	
}
void connect(int a,int b)
{
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
	{
		father[faA]=father[faB];
	}
}
int checkcomponent()
{
	int count=0;
	for(int i=1;i<=num;i++)
	{
		if(isroot[i]==true) count++;
	}
	return count;
}
int main()
{

	cin>>num;
	for(int i=1;i<=num;i++)
	{
		father[i]=i;
	}
	char input;
	int componentnum=0;
	
	while(1)
	{
		cin>>input;
		if(input=='S') break;
		else if(input=='I')
		{
			int num1;
			int num2;
			cin>>num1;
			cin>>num2;
			connect(num1,num2);
		}
		else if(input=='C')
		{
			int num1;
			int num2;
			cin>>num1;
			cin>>num2;	
			bool r=check(num1,num2);
			result.push_back(r);
		}
	 } 
	 for(auto it=result.begin();it!=result.end();it++)
	 {
	 	if((*it)==true) cout<<"yes";
	 	else cout<<"no";
	 	cout<<endl;
	 }
	 for(int j=1;j<=num;j++)
	 {
	 	isroot[findfather(j)]=true;
	 }
	 componentnum=checkcomponent();
	 if(componentnum==1)
	 {
	 	cout<<"The network is connected.";
	 }
	 else
	 {
	 	cout<<"There are "<<componentnum<<" components.";
	 }
 } 
