#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n;
int queen[100];
void nqueen(int k);
int main(){
cin>>n;

nqueen(0);

return 0;
} //����������nqueen��0��ʼ�� 
void nqueen(int k) //��0-k-1�ں�����£��ڵ�k�м����Ļʺ� 
{
		int i;
		if(k==n){ //N���ʺ��Ѿ��ں� 
			for(i=0;i<n;i++)
			
				cout<<queen[i]+1<<" ";
				cout<<endl;
				return ;
			 
		}  //�Ѿ��ں� 


		for(i=0;i<n;i++){

		int j;
		for(j=0;j<k;j++){
			if(queen[j]==i  || abs(queen[j]-i)==abs(k-j))
			{
				break;
			} // �����ֲ����Ϲ��� 
		}
		if(j==k){
			queen[k]=i;
			nqueen(k+1);
		}
		}//���м��� 
		
		
	}

