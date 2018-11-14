#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node{
	struct node *left;
	struct node *right;
	int name;
};
struct node *root=NULL;
void inserts(int str)
{
	struct node *ptr,*temp,*prev;
	ptr=new node;
	ptr->name=str;
	ptr->left=NULL;
	ptr->right=NULL;
	if(root==NULL)
	{
		root=ptr;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			prev=temp;
			if(str<temp->name)
			temp=temp->left;
			else
			temp=temp->right;
		}
		if(ptr->name<prev->name)
		{
			prev->left=ptr;
		}
		else
		{
			prev->right=ptr;
		}
	}
}
void preorder(struct node*root)
{
	if(root!=NULL)
	{
		cout<<root->name<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->name<<" ";
	}
}
void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->name<<" ";
		inorder(root->right);
	}
}
void deletion(int str)
{
    int x;
	struct node *temp,*prev,*base;
	if(root==NULL)
	{
		cout<<"Underflow";
		return;
	}
	temp=root;
	while((str!=temp->name)&&(temp!=NULL))
	{
		prev=temp;
		if(str<temp->name)
		temp=temp->left;
		else
		temp=temp->right;
	}
	if(temp==NULL||str!=temp->name)
	{
		cout<<"Not found";
		return;
	}
	if(temp->left==NULL&&temp->right==NULL)
	{
		if(temp==root)
		{
			root=NULL;
			return;
		}
		if(str<prev->name)
		{
			prev->left=NULL;
		}
		else
		{
			prev->right=NULL;
		}
	}
	else if(temp->left!=NULL && temp->right!=NULL)
	{
		base=temp;
		temp=temp->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		x=temp->name;
		deletion(x);
		base->name=x;
	}
	else
	{
		if(temp==root)
		{
			if(temp->left!=NULL)
			{
				root=temp->left;
			}
			else
			{
				root=temp->right;
			}
		}
		else
		{
			if(temp->name<prev->name)
			{
				if(temp->left!=NULL)
				{
					prev->left=temp->left;
					temp->left=NULL;
					delete temp;
				}
				else
				{
					prev->left=temp->right;
					temp->right=NULL;
					delete temp;
				}
			}
			else
			{
				if(temp->left!=NULL)
				{
					prev->right=temp->left;
					temp->left=NULL;
					delete temp;
				}
				else
				{
					prev->right=temp->right;
					temp->right=NULL;
					delete temp;
				}
			}
		}
	}
}
int main()
{
	int item;
	int choice;
	while(1)
	{
			cout<<"1. for insertion \n";
			cout<<"2. for deletion\n";
			cout<<"3. for postorder traversing\n";
			cout<<"4. for preorder traversing\n";
			cout<<"5. for inorder traversing\n";
			cout<<"   Enter c to exit\n";
			cout<<"enter the choice\n";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"enter element you want to insert";
					cin>>item;
                    inserts(item);
					break;
				case 2:
					cout<<"enter element you want to delete";
					cin>>item;
					deletion(item);
					break;
				case 3:
					postorder(root);
					getch();
					break;
				case 4:
					preorder(root);
					getch();
					break;
				case 5:
					inorder(root);
					getch();
					break;
				default:
					exit(0);
			}
			system("CLS");
	}

}
