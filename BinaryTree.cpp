#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

node *newnode(int d)
{
	node *t = new node;
	t->data = d;
	t->left = t->right = NULL;
	return t;
}

class Tree
{
	node *root;
	public:
		Tree()
		{
			root=NULL;
		}
		void insert(int a);	//insert a node from left to right
		
		void preorder();
		void inorder();
		void postorder();

		int size();
		
		//level order output
		friend ostream &operator<<(ostream &output,const Tree &T)
		{
			output<<"Binary Tree Object - Size : "T.size()<<", [ ";
			queue<node*> Q;
			node *temp = T.root;
			Q.push(temp);
			while(!Q.empty())
			{
				temp = Q.front();
				Q.pop();
				output<<temp->data<<",";
				if(temp->left)
					Q.push(temp->left);
				if(temp->right)
					Q.push(temp->right);
			}
			output<<"\b ] ";
			output<<endl;
		}
};

int Tree::size()
{
	int count=0;
	node *t = root;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		t = Q.front();
		count++;
		Q.pop();
		if(t->left) Q.push(t->left);
		if(t->right) Q.push(t->right);
	}
	return count;
}

void Tree::insert(int a)
{
	node *d = newnode(a);
	if(root==NULL)
	{
		root=d;
		return;
	}
	queue<node*> Q;
	node *temp = root;
	Q.push(temp);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(!temp->left){
			temp->left = d;
			break;
		}
		else if(!temp->right){
			temp->right = d;
			break;
		}
		else{
			if(temp->left)
				Q.push(temp->left);
			if(temp->right)
				Q.push(temp->right);
		}
	}
}

void Tree::preorder()
{
	stack<node*> S;
	node *temp;
	S.push(root);
	while(!S.empty())
	{
		temp = S.top();
		cout<<temp->data<<" ";
		S.pop();
		if(temp->right)
			S.push(temp->right);
		if(temp->left)
			S.push(temp->left);
	}
	cout<<endl;
}

int main()
{
	Tree T;
	for(int i=0;i<10;i++)
	{
		T.insert(i+1);
	}
	T.preorder();
	cout<<endl<<T.size()<<endl;
	return 0;
}
