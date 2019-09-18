#include<stdio.h>
#include<algorithm>

using namespace std;

int countnum[110000];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&countnum[i]);
	}
	sort(countnum,countnum+num);  //¿ìÅÅ 
	for(int i=0;i<num;i++)
	{
		printf("%d",countnum[i]);
		if(i!=num-1) printf(" ");
	}
 } 
