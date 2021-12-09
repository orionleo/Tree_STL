#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    int height;
};
// Node *root = NULL;

template <typename T2>
struct list_Node
{
    T2 data;
    list_Node *next;
};

template <class T3>
class AvlTree
{
public:
    Node<T3> *my_root;
    AvlTree()
    {
        my_root = NULL;
        // my_root->height = 0;
    }

    AvlTree(AvlTree &obj)
    {
        this->my_root = obj.my_root;
    }

    Node<T3> *minNode(Node<T3> *root)
    {
        Node<T3> *current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }

        return current;
    }
    // This is to get the height of the root
    int get_height(Node<T3> *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return root->height;
    }
    int get_height()
    {
        return get_height(my_root);
    }

    // returns the balance of tree
    int get_balance(Node<T3> *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return get_height(root->left) - get_height(root->right);
    }

    Node<T3> *deleteNode(Node<T3> *root, T3 key)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // one child or no child case
            if (root->left == NULL || root->right == NULL)
            {
                Node<T3> *temp = root->left ? root->left : root->right;
                // no child case
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }

                // one child case
                else
                {
                    *root = *temp;
                    delete temp;
                }
            }

            // two child case
            else
            {
                Node<T3> *temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL)
        {
            return root;
        }

        root->height = 1 + max(get_height(root->left), get_height(root->right));

        int balance = get_balance(root);

        if (balance > 1 && get_balance(root->left) >= 0)
        {
            rightRotate(root);
        }

        if (balance > 1 && get_balance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && get_balance(root->right) <= 0)
        {
            return leftRotate(root);
        }

        if (balance < -1 && get_balance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void deleteNode(T3 key){
        my_root = deleteNode(my_root,key);
    }

    void storeAvlTreeNodes(Node<T3> *root, vector<Node<T3> *> &Nodes)
    {
        // Base case
        if (root == NULL)
            return;

        // Store Nodes in Inorder (which is sorted
        // order for AvlTree)
        storeAvlTreeNodes(root->left, Nodes);
        Nodes.push_back(root);
        storeAvlTreeNodes(root->right, Nodes);
    }

    Node<T3> *buildTreeUtil(vector<Node<T3> *> &Nodes, int start,
                            int end)
    {
        // base case
        if (start > end)
            return NULL;

        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        Node<T3> *root = Nodes[mid];

        /* Using index in Inorder traversal, construct
           left and right subtress */
        root->left = buildTreeUtil(Nodes, start, mid - 1);
        root->right = buildTreeUtil(Nodes, mid + 1, end);

        return root;
    }

    // This functions converts an unbalanced AvlTree to
    // a balanced AvlTree
    Node<T3> *buildTree(Node<T3> *root)
    {
        // Store Nodes of given AvlTree in sorted order
        vector<Node<T3> *> Nodes;
        storeAvlTreeNodes(root, Nodes);

        // Constructs AvlTree from Nodes[]
        int n = Nodes.size();
        return buildTreeUtil(Nodes, 0, n - 1);
    }

    Node<T3> *leftRotate(Node<T3> *x)
    {
        Node<T3> *y = x->right;
        Node<T3> *Temp = y->left;

        // perform rotation
        y->left = x;
        x->right = Temp;

        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    Node<T3> *rightRotate(Node<T3> *x)
    {
        Node<T3> *y = x->left;
        Node<T3> *Temp = y->right;

        // perform rotation
        y->right = x;
        x->left = Temp;

        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    // template<typename T3>
    void copyutil(Node<T3> *originalroot, vector<T3> &temp)
    {
        // cout<<originalroot->data<<" ";
        if (originalroot == NULL)
        {
            return;
        }
        temp.push_back(originalroot->data);
        copyutil(originalroot->left, temp);
        copyutil(originalroot->right, temp);
    }

    // template <typename T4>
    void copy(Node<T3> *originalroot, T3 min, T3 max)
    { //, Node<T3>*& treeNew = my_root //DONE

        if (originalroot == NULL)
        {
            return;
        }
        // cout<<"Original root= "<<originalroot->data<<"\n";
        vector<T3> vec;
        // cout<<"copyutil\n";
        copyutil(originalroot, vec);
        cout << endl;
        int n = vec.size();
        T3 arr[n];
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            arr[i] = vec[i];
            cout << vec[i] << " ";
        }
        cout << endl;
        constructTree(arr, n, min, max); // my_root =
    }
    // template <typename T5>
    Node<T3> *GetNewNode(T3 data)
    {
        Node<T3> *temp = new Node<T3>();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }
    // template <typename T3>
    list_Node<T3> *newNode(T3 val)
    {
        list_Node<T3> *temp = new list_Node<T3>();
        temp->data = val;
        temp->next = NULL;
        return temp;
    }

    // template <typename T7>
    Node<T3> *insert(T3 data, Node<T3> *root)
    { // REQUIRED AND DONE

        if (root == NULL)
        {
            root = GetNewNode(data);
        }
        else if (data <= root->data)
        {
            root->left = insert(data, root->left);
        }
        else
        {
            root->right = insert(data, root->right);
        }

        root->height = 1 + max(get_height(root->left), get_height(root->right));

        int balance = get_balance(root);

        if (balance > 1 && data < root->left->data)
        {
            return rightRotate(root);
        }

        if (balance < -1 && data > root->right->data)
        {
            return leftRotate(root);
        }

        if (balance > 1 && data > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && data < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void insert(T3 data)
    {
        my_root = insert(data, my_root);
    }

    //--------------------SEARCHING -------------------
    // template <typename T3>
    bool search(T3 data, Node<T3> *root)
    { // DONE
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        else if (data <= root->data)
        {
            return search(data, root->left);
        }
        else
        {
            return search(data, root->right);
        }
    }
    bool search(T3 data)
    {
        return search(data, my_root);
    }

    //---------------TRAVERSAL-------------------------
    // template <typename T3>
    void LevelOrder()
    {
        Node<T3> *root = my_root;
        if (root == NULL)
        {
            return;
        }
        queue<Node<T3> *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            Node<T3> *current = Q.front();
            cout << current->data << " ";
            if (current->left != NULL)
                Q.push(current->left);
            if (current->right != NULL)
                Q.push(current->right);
            Q.pop();
        }
    }
    // template <typename T3>
    void preorder(Node<T3> *root)
    {

        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void preorder()
    {
        preorder(my_root);
    }

    // template <typename T3>
    void inorder(Node<T3> *root)
    {

        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void inorder()
    {
        inorder(my_root);
    }
    // template <typename T3>
    void postorder(Node<T3> *root)
    {

        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void postorder()
    {
        postorder(my_root);
    }
    //---------------DELETION---------------------
    // template <typename T9>
    Node<T3> *Delete(T3 data, Node<T3> *root)
    { // REQUIRED AND DONE
        if (root == NULL)
            return root;
        else if (data < root->data)
        {
            root->left = Delete(data, root->left);
        }
        else if (data > root->data)
        {
            root->right = Delete(data, root->right);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                Node<T3> *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                Node<T3> *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node<T3> *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(temp->data, root->right);
            }
        }
        return root;
    }

    void Delete(T3 data)
    {
        my_root = Delete(data, my_root);
    }

    //------------------INORDER SUCCESSOR--------------------------
    // template<typename TT>
    Node<T3> *Find(T3 data, Node<T3> *root)
    {
        if (root == NULL)
            return NULL;
        else if (root->data == data)
            return root;
        else if (root->data < data)
            return Find(data, root->right);
        else
            return Find(data, root->left);
    }

    // Function to find Node with minimum value in a AvlTree
    //  template <typename T10>
    Node<T3> *FindMin(Node<T3> *root)
    {
        if (root == NULL)
            return NULL;
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    // Function to find Inorder Successor in a AvlTree
    //  template <typename T3>
    Node<T3> *Getsuccessor(T3 data, Node<T3> *root)
    { // DONE
        // Search the Node - O(h)
        Node<T3> *current = Find(data, root);
        if (current == NULL)
            return NULL;
        if (current->right != NULL)
        {                                   // Case 1: Node has right subtree
            return FindMin(current->right); // O(h)
        }
        else
        { // Case 2: No right subtree  - O(h)
            Node<T3> *successor = NULL;
            Node<T3> *ancestor = root;
            while (ancestor != current)
            {
                if (current->data < ancestor->data)
                {
                    successor = ancestor; // so far this is the deepest Node for which current Node is in left
                    ancestor = ancestor->left;
                }
                else
                    ancestor = ancestor->right;
            }
            return successor;
        }
    }

    Node<T3> *Getsuccessor(T3 data)
    {
        Node<T3> *temp = Getsuccessor(data, my_root);
        return temp;
    }

    void constructTree(T3 pre[], int size, T3 min, T3 max)
    {
        int preIndex = 0;
        sort(pre, pre + size);
        my_root = sortedArrayToAvlTree(pre, 0, size - 1);
    }

    //---------------AvlTree FROM SORTED LINKED LIST------------------------
    /* UTILITY FUNCTIONS */
    /* A utility function that returns
    count of Nodes in a given Linked List */
    // template <typename T14>
    int countNodes(list_Node<T3> *head)
    {
        int count = 0;
        list_Node<T3> *temp = head;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    // template <typename TT>
    Node<T3> *sortedListToAvlTree(list_Node<T3> *head)
    {
        /*Count the number of Nodes in Linked List */
        int n = countNodes(head);

        /* Construct AvlTree */
        return sortedListToAvlTreeRecur(&head, n);
    }

    /* The main function that constructs
    balanced AvlTree and returns root of it.
    head_ref --> Pointer to pointer to
    head Node of linked list n --> No.
    of Nodes in Linked List */
    // template <typename V>
    Node<T3> *sortedListToAvlTreeRecur(list_Node<T3> **head_ref, int n)
    {
        /* Base Case */
        if (n <= 0)
            return NULL;

        /* Recursively construct the left subtree */
        Node<T3> *left = sortedListToAvlTreeRecur(head_ref, n / 2);

        /* Allocate memory for root, and
        link the above constructed left
        subtree with root */
        Node<T3> *root = GetNewNode((*head_ref)->data);
        root->left = left;

        /* Change head pointer of Linked List
        for parent recursive calls */
        *head_ref = (*head_ref)->next;

        /* Recursively construct the right
            subtree and link it with root
            The number of Nodes in right subtree
            is total Nodes - Nodes in
            left subtree - 1 (for root) which is n-n/2-1*/
        root->right = sortedListToAvlTreeRecur(head_ref, n - n / 2 - 1);

        return root;
    }

    //----------------AvlTree FROM SORTED ARRAY------------------
    // template <typename V1>
    Node<T3> *sortedArrayToAvlTree(T3 arr[], int start, int end, bool val)
    {
        /* Base Case */
        if (start > end)
            return NULL;

        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        Node<T3> *root = GetNewNode(arr[mid]);

        /* Recursively construct the left subtree
        and make it left child of root */
        root->left = sortedArrayToAvlTree(arr, start,
                                          mid - 1, val);

        /* Recursively construct the right subtree
        and make it right child of root */
        root->right = sortedArrayToAvlTree(arr, mid + 1, end, val);

        return root;
    }

    void sortedArrayToAvlTree(T3 arr[], int start, int end)
    {
        my_root = sortedArrayToAvlTree(arr, start, end, true);
    }

    // Common Ancestor in a AvlTree
    // template <typename V2>
    Node<T3> *lca(T3 n1, T3 n2, Node<T3> *root)
    {
        if (root == NULL)
            return NULL;

        // If both n1 and n2 are smaller
        // than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            return lca(n1, n2, root->left);

        // If both n1 and n2 are greater than
        // root, then LCA lies in right
        if (root->data < n1 && root->data < n2)
            return lca(n1, n2, root->right);

        return root;
    }

    Node<T3> *lca(T3 n1, T3 n2)
    {
        return lca(n1, n2, my_root);
    }

    void printTree(Node<T3> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << ": ";
        if (root->left)
        {
            cout << "L-" << root->left->data << " ";
        }
        if (root->right)
        {
            cout << "R-" << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }
    void printTree()
    {
        printTree(my_root);
    }

    ~AvlTree()
    {
        if (my_root != NULL)
        {
            delete my_root->left;
            delete my_root->right;
        }
    }
};
