#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
class TreeNode{
    public:
        T data;
        vector <TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }
};

template <class TT>
class tree{
    public:
    TreeNode<TT>* my_root;
    TreeNode<TT>* Input(){
    TT data;
    cout<<"Enter the data: ";
    cin>>data;
    TreeNode<TT>* root = new TreeNode<TT>(data);
    fflush(stdin);
    int n;
    cout<<"Enter number of children: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<TT>* child = Input();
        root->children.push_back(child);
    }
    return  root;
}

    // template <typename TT>
    TreeNode<TT>* LevelInput(){
    queue<TreeNode<TT>*> q;
    TT data;
    cout<<"Enter the root data: ";
    cin>>data;
    TreeNode<TT>* root = new TreeNode<TT>(data);
    q.push(root);
    fflush(stdin);
    while(!q.empty()){
        TreeNode<TT>* frontval = q.front();
        q.pop();
    int n;
    cout<<"Enter number of children of "<<frontval->data<<" : ";
    cin>>n;
    for (int i = 0; i < n ; i++)
    {
        TT childval;
        cout<<"Enter child"<<i<<" of "<<frontval->data<<" : "; 
        cin>>childval;
        TreeNode<TT>* child = new TreeNode<TT>(childval); 
        frontval->children.push_back(child);
        q.push(child);
    }
    }
    return  root;
}
void Print(TreeNode<TT>* root){
    if(root==NULL)
        return;
    cout<<root->data<<": ";
        for(int i=0;i< root->children.size();i++){
         cout<<root->children[i]->data<<" ";   
        }
        cout<<endl;
    for(int i=0;i< root->children.size();i++){
        Print(root->children[i]);
    }
}
void Print(){
    Print(my_root);
}

int countnodes(TreeNode<TT>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+= countnodes(root->children[i]);
    }
    return ans;
}
int countnodes(){
    return countnodes(my_root);
}
};
