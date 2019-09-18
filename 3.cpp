#include<stdio.h>
#include<algorithm>


using namespace std;



int input1[3020];
int input2[3020];
int output1[3020];
int output2[3020];
bool cmp1(int a,int b)
{
	return a>b;
}
int main()
{

	int num1;
	int num2;
	int t=0;
	scanf("%d",&num1);
	
	for(int i=0;i<num1;i++)
	{
		int temp1;
		int temp2;
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		input1[temp2+1000]+=temp1;
		output2[temp2+1000]+=temp1;
	}
	scanf("%d",&num2);
	for(int i=0;i<num2;i++)
	{
		int temp1;
		int temp2;
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		input2[temp2+1000]+=temp1;
 		output2[temp2+1000]+=temp1;
	}
	for(int i=3002;i>=0;i--)
	{
		if(input1[i]==0) continue;
		for(int j=3002;j>=0;j--)
		{
			if(input2[j]==0) continue;
			int temp1=i+j-1000;
			int temp2=input1[i]*input2[j];
			output1[temp1]+=temp2;
		}
		
	}
	int outputnum1=0;
	int outputnum2=0;
	for(int i=0;i<3002;i++)
	{
		if(output1[i]!=0)
		{
			outputnum1=i;
			break;
		}
	}
	for(int j=0;j<3002;j++)
	{
		if(output2[j]!=0)
		{
			outputnum2=j;
			break;
		}
	}
	if(outputnum1!=0)
	{	
	
	for(int t=3002;t>=0;t--)
	{
		if(output1[t]!=0)
		{
			printf("%d %d",output1[t],t-1000);
			if(t!=outputnum1)
			{
				printf(" ");
			}
		}
		
	}
	}
	else
	{
		printf("0 0");
	}
	printf("\n");
	if(outputnum2!=0)
	{
	for(int t=3002;t>=0;t--)
	{
		if(output2[t]!=0)
		{
			printf("%d %d",output2[t],t-1000);
			if(t!=outputnum2)
			{
				printf(" ");
			}
		}
		
	}
	}
	else
	{
		printf("0 0");
	}
 } 
