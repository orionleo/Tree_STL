#include<bits/stdc++.h>
#include<iostream>
#include"Avltree.h"
#include"BST.h"
#include"Tree.h"

using namespace std;

int main()
{
    AvlTree<char> obj;
    obj.insert('D');
    obj.insert('C');
     obj.insert('A');
    obj.insert('F');
    obj.insert('G');
    obj.insert('H');
    obj.insert('B');
    obj.insert('J');
    cout << obj.search('D');
    cout << endl;
    cout << obj.search('Z');
    cout << endl;
    obj.printTree();//This is for a clear clarification of which node has 
    obj.deleteNode('J');
    cout<<endl<<endl;
    obj.printTree();//This is for a clear clarification of which node has 
    // obj.LevelOrder();
    // cout << endl;
    // obj.preorder();
    // cout << endl;
    // obj.postorder();
    // cout << endl;
    // obj.inorder();
    // cout << endl;
    // // obj.Delete('A');
    // node<char> *val = obj.Getsuccessor('C'); // to be checked;
    // cout << val->data << " \n";
    int arr[] = {int('A'), int('B'), int('C'), int('D'), int('F'), int('G'), int('H'), int('J')};

    // ERROR FROM HERE
    // val = obj.lca('G', 'J');
    // cout << val->data << " \n";
    AvlTree<int> obj2;
    obj2.sortedArrayToAvlTree(arr, 0, 7);
    obj2.printTree();
    // obj2.LevelOrder();
    // obj2.inorder();
    // AvlTree<char> obj3;
    // obj3.copy(obj.my_root, 'A', 'Z');
    // obj3.inorder();

    // BST<char> obj3;                     
    // obj3.insert('D');
    // obj3.insert('C');
    // obj3.insert('A');
    // obj3.insert('F');
    // obj3.insert('G');
    // obj3.insert('H');
    // obj3.insert('B');
    // obj3.insert('J');
    // cout<<obj3.search('D');
    // cout<<endl;
    // cout<<obj3.search('Z');
    // cout<<endl;
    // obj3.LevelOrder();
    // cout<<endl;
    // obj3.preorder();
    // cout<<endl;
    // obj3.postorder();
    // cout<<endl;
    // obj3.inorder();
    // cout<<endl;
    // // obj.Delete('A');
    // node<char>* val = obj3.Getsuccessor('C'); //to be checked
    // cout<<val->data<<" \n";
    // char arr2[] = {'A','B','C','D','F','G','H','J'};

    // //ERROR FROM HERE
    // val = obj3.lca('G','J');
    // cout<<val->data<<" \n";
    // BST<char> obj4;
    // obj4.sortedArrayToBST(arr2,0,7);
    // obj4.inorder();
    // BST<char> obj5;
    // obj5.copy(obj3.my_root,'A','Z');
    // obj5.inorder();

    // tree<char>t;
    // t.my_root = t.LevelInput();
    // cout<<endl<<endl;
    // t.Print();
    // cout<<endl<<endl<<t.countnodes();
    return 0;
}

                        
    //         F
    //     C       H
    //   A   D    G    J
    //     B           

    //         D
    //     C       F
    // A               G
    //                     H
    //     B                   J