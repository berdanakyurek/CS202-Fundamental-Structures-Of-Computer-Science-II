#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree tree;
    tree.add(31);
    tree.add(7);
    tree.add(56);
    tree.add(2);
    tree.add(1);
    tree.add(41);
    tree.add(45);
    tree.add(10);
    tree.add(70);
    tree.add(42);
    tree.add(38);
    tree.add(9);
    
    
    cout << tree.contains(1)<<endl;
    cout << tree.contains(31)<<endl;
    cout << tree.contains(9)<<endl;
    cout << tree.contains(10)<<endl;
    cout << tree.contains(70)<<endl;
    cout << tree.contains(999)<<endl;
    tree.preorderTraverse();
    tree.inorderTraverse();
    tree.postorderTraverse();
    tree.levelorderTraverse();

    
    cout << endl;
    tree.preorderTraverse();
    tree.inorderTraverse();
    tree.postorderTraverse();
    tree.levelorderTraverse();

    tree.mirror();

    cout << endl;
    tree.preorderTraverse();
    tree.inorderTraverse();
    tree.postorderTraverse();
    tree.levelorderTraverse();

    tree.mirror();

    cout << endl;
    tree.preorderTraverse();
    tree.inorderTraverse();
    tree.postorderTraverse();
    tree.levelorderTraverse();

    cout << tree.span(1,999999) <<endl;
    cout << tree.getNumberOfNodes() <<endl;
    return 0;
}