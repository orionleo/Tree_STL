# New-Trees-Header-File
We have made a new custom made header file for Trees Data Structure in C++.
 
Custom Libararies are available for BINARY SEARCH TREE, TREES and AVL.



# Binary Search Tree :

To use this header file copy the below given code in your header file 
```
#include"BST.h"
```

Here is a brief description of all the functions available in this header file :

### Step 1 : Create an Object of BST class and specify the data type in it :

`BST<data_type> obj_name;`

For exmaple,
`BST<char> obj3;` will create a BST in which each data will be of char type and object name is obj3. <br/> 
<br/>
Now you can freely use obj3, i.e, object name to invoke all the functions. Let's have a look at all the functions which are available to us. <br/>
<br/>

#### > insert
Inorder to insert any data in the binary search tree, follow this syntax :
```
obj_name.insert(data);
```
For example, `obj3.insert('D');` will insert D in the Binary Search Tree.
<br/>

#### > search
Inorder to check if any data in the BST, follow this syntax :
```
obj_name.search(data);
```
For example, `obj3.search('D');` will return 1 if it is present and 0 if it isn't present.
<br/>

#### > Delete
Inorder to Delete any data in the binary tree, follow this syntax :
```
obj_name.Delete(data);
```
For example, `obj3.Delete('D');` will delete D from the Binary Search Tree.
<br/>

### > Traversals 

Syntax for various traversals :

```
obj_name.traversal_name();
```
For Example :

```
    obj3.LevelOrder();
    cout<<endl;
    obj3.preorder();
    cout<<endl;
    obj3.postorder();
    cout<<endl;
    obj3.inorder();
    cout<<endl;
```
This will print all traversals as per the name.
<br/>

#### > Get Successor
Inorder to get any successor in the binary search tree, follow this syntax :
```
obj_name.getSuccessor(data);
```
For example, `obj3.getSuccessor('D');` will get successor of  D from the Binary Search Tree.
<br/>
Then, you can store it and print it, like :
```
 node<char>* val = obj3.Getsuccessor('C');
    cout<<val->data<<" \n";
```
<br/>
#### > Least Common Ancestor
Inorder to get the least common ancestor of 2 nodes in the binary search tree, follow this syntax :
```
obj_name.lca(node1, node2);
```
For example, `obj3.lca('G', 'J');` will get least common anchestor of  G and J from the Binary Search Tree.
Then, you can store it and print it, like :
```
 val = obj3.lca('G','J');
 cout<<val->data<<" \n";
```
<br/>

#### > BST from a sorted Array
Inorder to get a BST from a sorted array, follow this syntax :
```
obj_name.sortedArrayToBST(array, start_index, end_index);
```
For example, `obj4.sortedArrayToBST(arr2,0,7);` will create a Binary Search Tree using a sorted array of 8 elements.
<br/>

#### > Copy
Inorder to copy from a BST to another BST, follow this syntax :
```
obj_name_final.copy(sourceBST_name.my_root, 'A', 'Z');
```
For example, `obj5.copy(obj3.my_root,'A','Z');` will create a Binary Search Tree in 'obj5' using BST from 'obj3'.
<br/>



<br/>
# Tree :

To use this header file copy the below given code in your header file 
```
#include"Tree.h"
```

Here is a brief description of all the functions available in this header file :

### Step 1 : Create an Object of tree class and specify the data type in it :

`tree<data_type> obj_name;`

For exmaple,
`tree<char> t;` will create a tree in which each data will be of char type and object name is t. <br/> 
<br/>
Now you can freely use t, i.e, object name to invoke all the functions. Let's have a look at all the functions which are available to us. <br/>
<br/>
#### > Print
To print in tree, follow this syntax :
```
obj_name.Print();
```
For example, `t.print();` will print in the Tree.
<br/>





# AVL :


To use this header file copy the below given code in your header file 
```
#include"Avltree.h"
```

Here is a brief description of all the functions available in this header file :

### Step 1 : Create an Object of AVL class and specify the data type in it :

`AvlTree<data_type> obj_name;`

For exmaple,
`AvlTree<char> obj;` will create a AVL in which each data will be of char type and object name is 'obj'. <br/> 
<br/>
Now you can freely use 'obj', i.e, object name to invoke all the functions. Let's have a look at all the functions which are available to us. <br/>
<br/>

#### > insert
Inorder to insert any data in the AVL, follow this syntax :
```
obj_name.insert(data);
```
For example, `obj.insert('D');` will insert D in the AVL.
<br/>

#### > search
Inorder to check if any data in the AVL, follow this syntax :
```
obj_name.search(data);
```
For example, `obj.search('D');` will return 1 if it is present and 0 if it isn't present.
<br/>

#### > Delete
Inorder to Delete any node in the AVL, follow this syntax :
```
obj_name.deleteNode(data);
```
For example, `obj.deleteNode('D');` will delete D from the AVL.
<br/>

### > Traversals 

Syntax for various traversals :

```
obj_name.traversal_name();
```
For Example :

```
    obj3.LevelOrder();
    cout<<endl;
    obj3.preorder();
    cout<<endl;
    obj3.postorder();
    cout<<endl;
    obj3.inorder();
    cout<<endl;
```
This will print all traversals as per the name.
<br/>
#### > Print
To print tree, follow this syntax :
```
obj_name.printTree();
```
For example, `t.printTree();` will print in the Tree.
<br/>

