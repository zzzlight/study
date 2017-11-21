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
} //主函数调用nqueen从0开始算 
void nqueen(int k) //在0-k-1摆好情况下，摆第k行及其后的皇后 
{
		int i;
		if(k==n){ //N个皇后已经摆好 
			for(i=0;i<n;i++)
			
				cout<<queen[i]+1<<" ";
				cout<<endl;
				return ;
			 
		}  //已经摆好 


		for(i=0;i<n;i++){

		int j;
		for(j=0;j<k;j++){
			if(queen[j]==i  || abs(queen[j]-i)==abs(k-j))
			{
				break;
			} // 若发现不符合规则 
		}
		if(j==k){
			queen[k]=i;
			nqueen(k+1);
		}
		}//按列计算 
		
		
	}

