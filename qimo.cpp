#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
struct Node
{
	int data;
	Node* leftchild=NULL;
	Node* rightchild=NULL;
};
int num;
int postorder[100];
int inorder[100];
vector<int> preorder;
void dfs(Node* root)
{
	if(root==NULL) return ;
	preorder.push_back(root->data);
	dfs(root->leftchild);
	dfs(root->rightchild);
}
Node* create(int postl,int postr,int inl,int inr)
{
	if(postr<postl) return NULL;
	Node* mynode=new Node;
	mynode->leftchild=NULL;
	mynode->rightchild=NULL; 
	mynode->data=postorder[postr];
	int k;
	for(k=0;k<num;k++)
	{
		if(inorder[k]==postorder[postr]) break;
	}
	int numl=k-inl;
	mynode->rightchild=create(postl+numl,postr-1,inl+numl+1,inr);
	mynode->leftchild=create(postl,postl+numl-1,inl,k-1);
	return mynode;
}
int main()
{

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&inorder[i]);
	}
	Node* root=create(0,num-1,0,num-1);
	dfs(root);
	printf("Preorder: ");
	for(int i=0;i<preorder.size();i++)
	{
		printf("%d",preorder[i]);
		if(i!=preorder.size()-1) printf(" ");
	}
 } 
