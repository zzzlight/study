#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct Node
{
	char data;
	int weight;
}node[1000];
int main()
 {
 	int num;
 	cin>>num;
 	for(int i=0;i<num;i++)
 	{
 		cin>>node[i].data;
 		cin>>node[i].weight;
	 }
//	 createhuffmantree();
	// chushi=wpl();
 	int testnum;
 	cin>>testnum;
 	for(int j=0;j<testnum;j++)
 	{
 		for(int i=0;i<num;i++)
 		{
			 char temp1;
			 int temp2[100];
 			cin>>temp1;
 			char temp;
 			temp=getchar();
 			int t=0;
 			while(temp!='\n')
 			{
 				temp2[t]=temp-'0';   //0处存的\n 1-(t-1)位才是 
 				t++;
 				temp=getchar();
			 }
		//	 bool flag=creattree();
			 
			 // flag=true&&wpl==chushi yes else  no
			 
 			
		 }
	 }
 }
