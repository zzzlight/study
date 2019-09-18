#include<iostream>

using namespace std;
struct Node
{
	char data;
	int child1=-1;
	int child2=-1;	
	char allchild1;
	char allchild2;
};
Node node1[100];
Node node2[100];

int main()
{
	int num1;
	cin>>num1;
	for(int i=0;i<num1;i++)
	{
		char temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		node1[i].data=temp1;
		if(temp2!='-')
		node1[i].child1=temp2-'0';
		else
		node1[i].child1=-1; 
		if(temp3!='-')
		node1[i].child2=temp3-'0';
		else
		node1[i].child2=-1; 
	}
	int num2;
	cin>>num2;
	for(int i=0;i<num2;i++)
	{
		char temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		node2[i].data=temp1;
		if(temp2!='-')
		node2[i].child1=temp2-'0';
		else
		node2[i].child1=-1; 
		if(temp3!='-')
		node2[i].child2=temp3-'0';
		else
		node2[i].child2=-1;
	}
	for(int i=0;i<num1;i++)
	{
		if(node1[i].child1!=-1)	
		node1[i].allchild1=node1[node1[i].child1].data;
		else
		node1[i].allchild1='-';
		if(node1[i].child2!=-1)
		node1[i].allchild2=node1[node1[i].child2].data;
		else
		node1[i].allchild2='-';
	}
	for(int i=0;i<num2;i++)
	{
		if(node2[i].child1!=-1)	
		node2[i].allchild1=node2[node2[i].child1].data;
		else
		node2[i].allchild1='-';
		if(node1[i].child2!=-1)
		node2[i].allchild2=node2[node2[i].child2].data;
		else
		node2[i].allchild2='-';
	}
	bool flag=true;
	int count=0;
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<num2;j++)
		{
			if(node1[i].data==node2[j].data)
			{
				if((node1[i].allchild1!=node2[j].allchild1&&node1[i].allchild2!=node2[j].allchild2)&&(node1[i].allchild2!=node2[j].allchild1&&node1[i].allchild1!=node2[j].allchild2))
				{
					flag=false;
				}
				else
				{
					count++;
				}
				
			}
		}
	}
	if(flag==false||(count!=num1||count!=num2)) cout<<"No";
	else cout<<"Yes";
 } 
