#include<iostream>
#include<stack>
#include<string> 
#include<vector>
using namespace std;

int preorder[100];
int midorder[100];
int postorder[100];
vector<int> result;
struct Tree
{
	int leftchild=-1;
	int rightchild=-1;
}tree[100];
int create(int prel,int prer,int midl,int midr)
{
	if(prel>prer) return -1;
	int rt;
	rt=preorder[prel];
	int k;
	for(k=midl;k<=midr;k++)
	{
		if(midorder[k]==preorder[prel])
		break;
	}
	tree[rt].leftchild=create(prel+1,prel+k-midl,midl,k-1);
	tree[rt].rightchild=create(prel+k-midl+1,prer,k+1,midr);
	return rt;
}
void postordertra(int root)
{
	if(root==-1) return;
	if(tree[root].leftchild!=-1)
	{
		postordertra(tree[root].leftchild);
	}
	if(tree[root].rightchild!=-1)
	{
		postordertra(tree[root].rightchild);
	 } 
	 result.push_back(root);
}
int main()
{
	int num1;
	stack<int> st;
	cin>>num1;
	int t=0;
	int x=0;
	for(int i=0;i<2*num1;i++)
	{
		string temp;
		int temp2;
		int temp3;
		cin>>temp;
		if(temp=="Push")
		{
			cin>>temp2;
			preorder[t++]=temp2;
			st.push(temp2);
		}
		else
		{
			temp3=st.top();
			st.pop();
			midorder[x++]=temp3;
		}
		
	}
	int root=create(0,num1-1,0,num1-1);
	postordertra(root); 
	for(int i=0;i<num1;i++)
	{
		cout<<result[i];
		if(i!=num1-1) cout<<" ";
	}
 } 
