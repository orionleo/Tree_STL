#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct node{
    T data;
    node *left;
    node *right;
};
// node *root = NULL;

template<typename T2>
struct  list_node{
    T2 data;
    list_node *next;
};

template<class T3>
class BST{
public:
node<T3>* my_root;
BST(){
    my_root = NULL;
}

BST(BST &obj){
    this->my_root = obj.my_root;
}

    vector<T3> vec;
    void arrayFromBST(node<T3> *root){
        if(root==NULL){
            return;
        }
        arrayFromBST(root->left);
        vec.push_back(root->data);
        arrayFromBST(root->right);
    }
    vector<T3> get()
    {   vec.clear();
        arrayFromBST(my_root);
        return vec;
    } 
    
// template<typename T3>
void copyutil(node<T3>* originalroot , vector<T3> &temp){
    // cout<<originalroot->data<<" ";
    if(originalroot == NULL){
        return;
    }
    temp.push_back(originalroot->data);
    copyutil(originalroot->left,temp);
    copyutil(originalroot->right,temp);
}

// template <typename T4>
void copy(node<T3>* originalroot ,T3 min , T3 max){ //, node<T3>*& treeNew = my_root //DONE

    if(originalroot ==NULL){
        return;
    }
    vector<T3> vec;
    // cout<<"copyutil\n";
    copyutil(originalroot ,vec);
    cout<<endl;
    int n = vec.size();
    T3 arr[n];
    cout<<endl;
    cout<<endl;
    constructTree(arr,n,min,max); //my_root = 
    }

// template <typename T5>
node<T3>* GetNewNode(T3 data){
    node<T3>* temp = new node<T3>();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// template <typename T3>
list_node<T3>* newNode(T3 val){
    list_node<T3>* temp = new list_node<T3>();
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// template <typename T7>
node<T3>* insert( T3 data ,node<T3>* root){ // REQUIRED AND DONE
    
    if(root==NULL){
        root = GetNewNode(data);
    }
    else if(data <=root->data){
        root->left = insert(data ,root->left);
    }
    else{
        root->right = insert(data,root->right);
    }
    return root;

}

void insert(T3 data){
    my_root = insert(data, my_root);
}

//--------------------SEARCHING -------------------
// template <typename T3>
bool search(T3 data,node<T3>* root){ //DONE
    if(root== NULL)
        return false;
    if(root->data == data)
        return true;
    else if(data <= root->data){
        return search(data,root->left);
    }
    else{
        return search(data,root->right);
    }
}
bool search(T3 data){
    return search(data , my_root);
}

//---------------TRAVERSAL-------------------------
// template <typename T3>
void LevelOrder(){
    node<T3>* root = my_root;
    if(root==NULL){
        return;
    }
    queue<node<T3>*> Q;
    Q.push(root);
    while(!Q.empty()){
        node<T3>*current = Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
}
// template <typename T3>
void preorder(node<T3>* root){
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorder(){
    preorder(my_root);
}


// template <typename T3>
void inorder(node<T3>* root){
    
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void inorder(){
    inorder(my_root);
}
// template <typename T3>
void postorder(node<T3>* root){
    
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";  

}
void postorder(){
    postorder(my_root);
}
int count(node<T3>* root){
        if(root == NULL){
            return 0;
        }
        count+= (1+count(root->left));
        count+= (1+count(root->right));
        return count+1;
    }

    int count(){
        return count(my_root);
    }
//---------------DELETION---------------------
// template <typename T9>
node<T3> *Delete(T3 data, node<T3>* root){ //REQUIRED AND DONE
    if(root==NULL)
        return root;
    else if(data< root->data){
        root->left = Delete(data, root->left);
    }
    else if(data> root->data){
        root->right = Delete(data, root->right);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            node<T3>*temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            node<T3>*temp = root;
            root = root->left;
            delete temp;
        }
        else{
            node<T3>*temp  = FindMin(root->right);
            root->data  = temp->data;
            root->right = Delete( temp->data,root->right);
        } 
    }
    return root;
}

void Delete(T3 data){
    my_root =  Delete(data, my_root);
}


    T3 parentt(node<T3> *root,T3 key,T3 parent){
        if(root==NULL){
            return T3(-1);
        }

        if(root->data==key){
            return parent;
        }
        else{
            T3 left = parentt(root->left,key,root->data);
            T3 right = parentt(root->right,key,root->data);
            if(left==T3(-1) && right==T3(-1)){
                return -1;
            }
            else if(left==-1){
                return right;
            }
            else{
                return left;
            }
            
        }
    }

    T3 parent(T3 key){
        if(my_root->data == key){
            cout<<"\nRoot node does not have a parent";
            return T3(-1);
        }
        return parentt(my_root,key,T3(-1));
    }


//------------------INORDER SUCCESSOR--------------------------
// template<typename TT>
node<T3>* Find(T3 data , node<T3>* root) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(data, root->right);
	else return Find(data, root->left);
}

//Function to find Node with minimum value in a BST
// template <typename T10>
 node<T3>* FindMin(node<T3>* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

//Function to find Inorder Successor in a BST
// template <typename T3>
 node<T3>* Getsuccessor( T3 data, node<T3>* root) { //DONE
	// Search the Node - O(h)
	node<T3>* current = Find(data,root);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		 node<T3>* successor = NULL;
		 node<T3>* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

node<T3>* Getsuccessor( T3 data){
    node<T3>* temp = Getsuccessor(data, my_root);
    return temp;
}

//------------CONSTRUCT TREE FROM PREORDER---------------------
// template <typename T12> ////////////////////////////
node<T3>* constructTreeUtil(T3 pre[], int* preIndex, T3 key, //preindex ka dekhna hai //TO BE CHECKED
                        T3 min, T3 max, int size)
{
    // Base case
    node<T3>* root = NULL;
    if (*preIndex >= size)
        return NULL;
 
    // node* root = NULL; //NO NEED TO MAKE ROOT IN THIS CASE
 
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key >= min && key <= max) {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = GetNewNode(key);
        *preIndex = *preIndex + 1;
 
        if (*preIndex < size) {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = constructTreeUtil(pre, preIndex,
                                           pre[*preIndex],
                                           min, key, size);
        }
        if (*preIndex < size) {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = constructTreeUtil(pre, preIndex,
                                            pre[*preIndex],
                                            key, max, size);
        }
        // return root;
    }
    return root;
}
 
// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
// template <typename T13>
void constructTree(T3 pre[], int size , T3 min , T3 max)
{
    int preIndex = 0;
    my_root =  constructTreeUtil(pre, &preIndex, pre[0], min, max, size);
}



//---------------BST FROM SORTED LINKED LIST------------------------
/* UTILITY FUNCTIONS */
/* A utility function that returns
count of nodes in a given Linked List */
// template <typename T14>
int countnodes(list_node<T3>*head)
{
    int count = 0;
    list_node<T3>*temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// template <typename TT>
node<T3>* sortedListToBST(list_node<T3>*head)
{
    /*Count the number of nodes in Linked List */
    int n = countnodes(head);
 
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}
 
/* The main function that constructs
balanced BST and returns root of it.
head_ref --> Pointer to pointer to
head node of linked list n --> No.
of nodes in Linked List */
// template <typename V>
node<T3>* sortedListToBSTRecur(list_node<T3>**head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    node<T3>*left = sortedListToBSTRecur(head_ref, n/2);
 
    /* Allocate memory for root, and
    link the above constructed left
    subtree with root */
    node<T3>*root = GetNewNode((*head_ref)->data);
    root->left = left;
 
    /* Change head pointer of Linked List
    for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right
        subtree and link it with root
        The number of nodes in right subtree
        is total nodes - nodes in
        left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);
 
    return root;
}
 



//----------------BST FROM SORTED ARRAY------------------
// template <typename V1>
node<T3>* sortedArrayToBST(T3 arr[],int start, int end , bool val)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    node<T3>*root = GetNewNode(arr[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1,val);
 
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end,val);
 
    return root;
}

void sortedArrayToBST(T3 arr[],int start, int end){
    my_root = sortedArrayToBST(arr , start,end,true);
}

// Common Ancestor in a BST
// template <typename V2>
node<T3>*lca(T3 n1, T3 n2, node<T3>* root)
{
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca( n1, n2,root->left);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca( n1, n2, root->right);
 
    return root;
}

node<T3>* lca(T3 n1, T3 n2){
    return lca(n1,n2,my_root);
}



~BST(){
    if(my_root!=NULL){
    delete my_root->left;
    delete my_root->right;
    }
}
};

