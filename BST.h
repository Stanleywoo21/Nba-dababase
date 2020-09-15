
#ifndef BST_h
#define BST_h
#include "BINARY_NODE.h"
#include <string>
#include <iostream>
#include "queue .h"

//template <typename T>
//class BST
//{
//private:
//    binaryNode<T>* rootPtr;
//    int count;
//
//protected:
//    //------------------------------------------------------------------
//    //  Protected Utility Methods Section.
//    //  Recursive helper functions  for the public methods.
//    //------------------------------------------------------------------
//    auto findLargest(binaryNode<T>* treePtr); //
//
//    int getHeight(binaryNode<T>* root);
//
//    bool searchBST(binaryNode<T>* root, T data); //
//
//    binaryNode<T>* insertBST(binaryNode<T>* root, T data); //
//
//    binaryNode<T>* deleteBST(binaryNode<T>* root, const T target); //
//
//    auto clearBST(binaryNode<T>* root); //
//
//    void breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const; //
//
//    void preorderTraverse(binaryNode<T>* root, std::ostream& os) const; //
//
//    void inorderTraverse(binaryNode<T>* root, std::ostream& os) const; //
//
//    void postorderTraverse(binaryNode<T>* root, std::ostream& os) const; //
//
//public:
//    //-------------------------------------------------------------------
//    //  Constructor and Destructor section
//    //-------------------------------------------------------------------
//    BST(); //
//    BST(const T data); //
//    ~BST(); //
//
//    //-------------------------------------------------------------------
//    //  Public Methods Functions
//    //-------------------------------------------------------------------
//    bool isEmpty() const; //
//    void add(const T data); //
//    void remove(const T  target); //
//
//    int getNumberOfNodes() { return count; }//
//    void clearBST() { return clearBST(rootPtr); } //
//    bool search(T input) { return searchBST(rootPtr, input); }//
//    int heightOfBST() { return getHeight(rootPtr); } //
//
//    //------------------------------------------------------------------
//    //  Public Traversals Section
//    //------------------------------------------------------------------
//    void displayBreadthFirst(std::ostream& os); //
//    void displayPreOrder(std::ostream& os) { preorderTraverse(rootPtr, os); } //
//    void displayInOrder(std::ostream& os) { inorderTraverse(rootPtr, os); } //
//    void displayPostOrder(std::ostream& os) { postorderTraverse(rootPtr, os); }//
//};
//
////------------------------------------------------------------------
////  Protected Utility Methods Section.
////  Recursive helper functions for the public methods.
////------------------------------------------------------------------
//
///* finds largest. Used to find inorder predecessor
//Pre: root - binarynode pointer
//Post:
//Return: binarynode pointer
//*/
//template <typename T>
//auto BST<T>::findLargest(binaryNode<T>* root)
//{
//    if (root->getRight() == nullptr)
//        return root;
//
//    return findLargest(root->getRight());
//}
//
///* gets the height of the BST
//Pre: *root  - binaryNode pointer
//Post:
//Return: return an int for count
//*/
//template<typename T>
//int BST<T>::getHeight(binaryNode<T>* root)
//{
//    if (root == NULL)
//        return 0;
//    else
//    {
//        int leftHeight = getHeight(root->getLeft());
//        int rightHeight = getHeight(root->getRight());
//        if (leftHeight > rightHeight)
//            return leftHeight + 1;
//        else
//            return rightHeight + 1;
//    }
//}
//
///* function is protected and is for inner use. search data in the BST
//Pre: *root - binarynode pointer
//     data  - data to be searched
//Post: check if the data is present in the BST
//Return: return a bool value.
//*/
//template <typename T>
//bool BST<T>::searchBST(binaryNode<T>* root, T data)
//{
//    if (root == nullptr)
//        return false;
//    else if (data < root->getData())
//        return searchBST(root->getLeft(), data);
//    else if (data > root->getData())
//        return searchBST(root->getRight(), data);
//    else
//        return true;
//}
//
///* function is protected and is for inner use. Inserts data into the BST
//Pre: *root - binarynode pointer
//     data  - data to be inserted
//Post: BST is now modified with new value
//Return:
//*/
//template <typename T>
//binaryNode<T>* BST<T>::insertBST(binaryNode<T>* root, T data)
//{
//    if (root == nullptr)
//    {
//        root = new binaryNode<T>(data);
//        root->setLeft(NULL);
//        root->setRight(NULL);
//    }
//    else
//    {
//        if (data < root->getData())
//            root->setLeft(insertBST(root->getLeft(), data));
//        else
//            root->setRight(insertBST(root->getRight(), data));
//    }
//    return root;
//}
//
///* function is protected and is for inner use. delete data from the BST
//Pre: *root - binarynode pointer
//     data  - data to be deleted
//Post: BST is now modified
//Return:
//*/
//template <typename T>
//binaryNode<T>* BST<T>::deleteBST(binaryNode<T>* root, const T data)
//{
//    if (root == nullptr)
//        return NULL;
//    else if (data < root->getData())
//        root->setLeft(deleteBST(root->getLeft(), data));
//    else if (data > root->getData())
//        root->setRight(deleteBST(root->getRight(), data));
//    else
//    {
//        if (root->getLeft() == nullptr)
//        {
//            binaryNode<T>* tmpPtr = root;
//            root = root->getRight();
//            delete tmpPtr;
//        }
//        else if (root->getLeft() == nullptr)
//        {
//            binaryNode<T>* tmpPtr = root;
//            root = root->getLeft();
//            delete tmpPtr;
//        }
//        else
//        {
//            binaryNode<T>* tmpPtr = findLargest(root->getLeft());
//            root->setData(tmpPtr->getData());
//            root->setLeft(deleteBST(root->getLeft(), tmpPtr->getData()));
//        }
//    }
//    return root;
//}
//
///* deletes everything in the tree
//Pre: root
//Post: BST is now empty with memory freed
//Return:
//*/
//template <typename T>
//auto BST<T>::clearBST(binaryNode<T>* root)
//{
//    if (root == nullptr)
//        return;
//
//    clearBST(root->getLeft());
//    clearBST(root->getRight());
//
//    delete root;
//    root = nullptr;
//    count = 0;
//}
//
///* Functions assigns preOrder data to os object
//Pre: *root - binarynode pointer
//     os - ostream operator by reference
//Post: os - now modified to have the proper data. Can be used for cout or file output
//Return:
//*/
//template<typename T>
//void BST<T>::breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const
//{
//    if (root == NULL)
//        return;
//    if (height == 1)
//        os << root->getData() << " ";
//    else if (height > 1)
//    {
//        breadthFirstTraverse(root->getLeft(), height - 1, os);
//        breadthFirstTraverse(root->getRight(), height - 1, os);
//    }
//}
//
///* Functions assigns preOrder data to os object
//Pre: *root - binarynode pointer
//     os - ostream operator by reference
//Post: os - now modified to have the proper data. Can be used for cout or file output
//Return:
//*/
//template <typename T>
//void BST<T>::preorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
//
//    os << root->getData() << " ";
//    preorderTraverse(root->getLeft(), os);
//    preorderTraverse(root->getRight(), os);
//}
//
///* Functions assigns preOrder data to os object
//Pre: *root - binarynode pointer
//     os - ostream operator by reference
//Post: os - now modified to have the proper data. Can be used for cout or file output
//Return:
//*/
//template <typename T>
//void BST<T>::inorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
//    
//    inorderTraverse(root->getLeft(), os);
//    os << root->getData() << " ";
//    inorderTraverse(root->getRight(), os);
//}
//
///* Functions assigns preOrder data to os object
//Pre: *root - binarynode pointer
//     os - ostream operator by reference
//Post: os - now modified to have the proper data. Can be used for cout or file output
//Return:
//*/
//template <typename T>
//void BST<T>::postorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
// 
//    postorderTraverse(root->getLeft(), os);
//    postorderTraverse(root->getRight(), os);
//    os << root->getData() << " ";
//}
////-------------------------------------------------------------------
////  Constructor and Destructor section
////-------------------------------------------------------------------
///* Default constructor
//Pre:
//Post: Root set to nullptr, count to be 0;
//Return:
//*/
//template<typename T>
//BST<T>::BST()
//{
//    rootPtr = nullptr;
//    count = 0;
//}
//
///* constructor
//Pre: data - data to be added
//Post: Root set to nullptr, count to be 1, left and right to null
//Return:
//*/
//template<typename T>
//BST<T>::BST(const T data)
//{
//    rootPtr = new binaryNode<T>(data);
//    rootPtr->setLeft(nullptr);
//    rootPtr->setRight(nullptr);
//    count = 1;
//}
//
///* Destructor
//Pre:
//Post: memory freed
//Return:
//*/
//template<typename T>
//BST<T>::~BST()
//{
//    clearBST();
//}
//
////-------------------------------------------------------------------
////  Public Methods Functions
////-------------------------------------------------------------------
///*
//Pre:
//Post:
//Return: bool - whether if the list is empty
//*/
//template<typename T>
//bool BST<T>::isEmpty() const
//{
//    if (rootPtr == nullptr)
//        return true;
//    else
//        return false;
//}
//
///* outer add function
//Pre: data - T data to be added
//Post:
//Return:
//*/
//template <typename T>
//void BST<T>::add(const T data)
//{
//    insertBST(rootPtr, data);
//    count++;
//}
//
///* outer remove function
//Pre: data - T data to be deleted
//Post:
//Return:
//*/
//template <typename T>
//void BST<T>::remove(const T data)
//{
//    deleteBST(rootPtr, data);
//    count--;
//}
//
//
////------------------------------------------------------------------
////  Public Traversals Section
////------------------------------------------------------------------
//template<typename T>
//void BST<T>::displayBreadthFirst(std::ostream& os)
//{
//    int height = heightOfBST();
//    for (int i = 0; i <= height; i++)
//        breadthFirstTraverse(rootPtr, i, os);
//}
//

//template <typename T>
//class BST
//{
//private:
//    binaryNode<T>* rootPtr;
//    int count;
//
//protected:
//    //------------------------------------------------------------------
//    //  Protected Utility Methods Section.
//    //  Recursive helper functions  for the public methods.
//    //------------------------------------------------------------------
//    /*
//    Pre: BinaryNode pointer
//    Post: Returns largest value in Binary tree
//    Return: largest value in Binary tree
//    */
//    auto findLargest(binaryNode<T>* treePtr);
//
//    /*
//    Pre: BinaryNode pointer
//    Post: Height of Binary Tree is returned
//    Return: Height of Binary Tree
//    */
//    int getHeight(binaryNode<T>* root);
//
//    /*
//    Pre: BinaryNode pointer and data being searched for
//    Post: Returns true if data exists in Binary tree
//    Return: True if data is in Binary tree, false otherwise
//    */
//    bool searchBST(binaryNode<T>* root, T data);
//
//    /*
//    Pre: BinaryNode pointer and data being inserted
//    Post: Inserts data into Binary Tree
//    Return: BinaryNode pointer
//    */
//    binaryNode<T>* insertBST(binaryNode<T>* root, T data);
//    /*
//    Pre: BinaryNode pointer and data being removed
//    Post: Removes data from Binary Tree
//    Return: BinaryNode pointer
//    */
//    binaryNode<T>* deleteBST(binaryNode<T>* root, const T data);
//
//
//    /*
//    Pre: BinaryNode pointer
//    Post: Clears Binary Search Tree
//    Return: Returns none when Binary Tree is cleared
//    */
//    auto clearBST(binaryNode<T>* root);
//
//    /*
//    Pre: BinaryNode pointer, height of tree, and ostream object
//    Post: Prints to screen and output file a breadth first traversal of binary tree,
//          by height
//    Return: None
//    */
//    void breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const;
//
//    void breadthFirstTraverseWithQueue(binaryNode<T>* root, std::ostream& os) const;
//
//    /*
//    Pre: BinaryNode pointer and ostream object
//    Post: Prints to screen and output file a preorder traversal of binary tree
//    Return: None
//    */
//    void preorderTraverse(binaryNode<T>* root, std::ostream& os) const;
//
//    /*
//    Pre: BinaryNode pointer and ostream object
//    Post: Prints to screen and output file a inorder traversal of binary tree
//    Return: None
//    */
//    void inorderTraverse(binaryNode<T>* root, std::ostream& os) const;
//
//    /*
//    Pre: BinaryNode pointer and ostream object
//    Post: Prints to screen and output file a postorder traversal of binary tree
//    Return: None
//    */
//    void postorderTraverse(binaryNode<T>* root, std::ostream& os) const;
//
//public:
//    //-------------------------------------------------------------------
//    //  Constructor and Destructor section
//    //-------------------------------------------------------------------
//    BST(); // Default Constructor
//    BST(const T data); // Overloaded Constructor
//    ~BST(); // Destructor
//
//    //-------------------------------------------------------------------
//    //  Public Methods Functions
//    //-------------------------------------------------------------------
//
//    /*
//    Pre: None
//    Post: Checks if rootPtr is NULL or not
//    Return: True if rootPTR is NULL, false otherwise
//    */
//    bool isEmpty() const;
//
//    /*
//    Pre: Data to be added
//    Post: insertBST function is called with rootPtr and data parameters
//          Count is also incremented
//    Return: None
//    */
//    void add(const T data);
//
//    /*
//    Pre: Data to be removed
//    Post: deleteBST function is called with rootPtr and data parameters
//          Count is also decremented
//    Return: None
//    */
//    void remove(const T data);
//
//    int getNumberOfNodes() { return count; } // Getter function for number of nodes
//
//    /*
//    Pre: None
//    Post: Calls clearBST helper with rootPtr parameter
//    Return: None
//    */
//    void clearBST() { return clearBST(rootPtr); }
//
//    /*
//    Pre: Input to be searched
//    Post: Calls searchBST helper with rootPtr and data being searched parameters
//    Return: True if input is found in binary tree, false otherwise
//    */
//    bool search(T input) { return searchBST(rootPtr, input); }
//
//    /*
//    Pre: None
//    Post: Calls getHeight helper with rootPtr parameter
//    Return: Height of Binary search tree
//    */
//    int heightOfBST() { return getHeight(rootPtr); }
//
//    //------------------------------------------------------------------
//    //  Public Traversals Section
//    //------------------------------------------------------------------
//
//    /*
//    Pre: ostream object
//    Post: Calls breadthFirstTraverse for each level of tree
//    Return: None
//    */
//    void displayBreadthFirst(std::ostream& os);
//
//
//    void displayBreadthFirstWithQueue(std::ostream& os);
//
//    /*
//    Pre: ostream object
//    Post: Calls preorderTraverse with rootPtr and ostream object parameters
//    Return: None
//    */
//    void displayPreOrder(std::ostream& os) { preorderTraverse(rootPtr, os); }
//
//    /*
//    Pre: ostream object
//    Post: Calls inorderTraverse with rootPtr and ostream object parameters
//    Return: None
//    */
//    void displayInOrder(std::ostream& os) { inorderTraverse(rootPtr, os); }
//
//    /*
//    Pre: ostream object
//    Post: Calls postorderTraverse with rootPtr and ostream object parameters
//    Return: None
//    */
//    void displayPostOrder(std::ostream& os) { postorderTraverse(rootPtr, os); }//
//
//
//};
//
////------------------------------------------------------------------
////  Protected Utility Methods Section.
////  Recursive helper functions for the public methods.
////------------------------------------------------------------------
//
//
//template <typename T>
///*==================================================================
//    if right of root is NULL
//        Return root
//    Return findLargest(right of root)
//*/
//auto BST<T>::findLargest(binaryNode<T>* root)
//{
//    if (root->getRight() == nullptr)
//        return root;
//
//    return findLargest(root->getRight());
//}
//
//
//template<typename T>
///*==================================================================
//    if root is NULL
//        Return 0
//    else
//        if left height is greater than right height
//            return left height + 1
//        else
//            return right height + 1
//*/
//int BST<T>::getHeight(binaryNode<T>* root)
//{
//    if (root == NULL)
//        return 0;
//    else
//    {
//        int leftHeight = getHeight(root->getLeft());
//        int rightHeight = getHeight(root->getRight());
//        if (leftHeight > rightHeight)
//            return leftHeight + 1;
//        else
//            return rightHeight + 1;
//    }
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Return false
//    else if data is less than root's data
//        Return searchBST(left of root, data)
//    else if data is greater than root's data
//        Return searchBST(right of root, data)
//    else
//        Return true
//*/
//bool BST<T>::searchBST(binaryNode<T>* root, T data)
//{
//    if (root == nullptr)
//        return false;
//    else if (data < root->getData())
//        return searchBST(root->getLeft(), data);
//    else if (data > root->getData())
//        return searchBST(root->getRight(), data);
//    else
//        return true;
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Create new BinaryNode called root and set its data
//        Set root's left to NULL
//        Set root's right to NULL
//    else
//        if data is less than root's data
//            Set root's left to insertBST(root's left, data)
//        else
//            Set root's right to insertBST(root's right, data)
//    Return root
//*/
//binaryNode<T>* BST<T>::insertBST(binaryNode<T>* root, T data)
//{
//    if (root == nullptr)
//    {
//        root = new binaryNode<T>(data);
//        root->setLeft(NULL);
//        root->setRight(NULL);
//    }
//    else
//    {
//        if (data < (root->getData()))
//            root->setLeft(insertBST(root->getLeft(), data));
//        else
//            root->setRight(insertBST(root->getRight(), data));
//    }
//    return root;
//}
//
///*==================================================================
//    if root is NULL
//        return NULL
//    else if data is less than root's data
//        set root's left to deleteBST(root's left, data)
//    else if data is greater than root's data
//        set root's right to deleteBST(root's right, data)
//    else
//        if root's left is NULL
//            Create temporary binaryNode pointer and set to root
//            Set root to root's right
//            Delete temporary pointer
//        else if root's left is NULL
//            Create temporary binaryNode pointer and set to root
//            Set root to root's left
//            Delete temporary pointer
//        else
//            //Create temporary binaryNode pointer and set to largest Node in tree
//            Set root's data to temporary pointer's data
//            Set root's left to deleteBST(root's left, temporary pointer's data)
//    Return root
//*/
//template <typename T>
//binaryNode<T>* BST<T>::deleteBST(binaryNode<T>* root, const T data)
//{
//    if (root == nullptr) {
//        return NULL;
//    }
//    else if (data < (root->getData())) {
//        root->setLeft(deleteBST(root->getLeft(), data));
//    }
//    else if (data > (root->getData())) {
//        root->setRight(deleteBST(root->getRight(), data));
//    }
//    else
//    {
//        if (root->getLeft() == nullptr)
//        {
//            binaryNode<T>* tmpPtr = root;
//            root = root->getRight();
//            delete tmpPtr;
//        }
//        else if (root->getLeft() == nullptr)
//        {
//            binaryNode<T>* tmpPtr = root;
//            root = root->getLeft();
//            delete tmpPtr;
//        }
//        else
//        {
//            binaryNode<T>* tmpPtr = findLargest(root->getLeft());
//            root->setData(tmpPtr->getData());
//            root->setLeft(deleteBST(root->getLeft(), tmpPtr->getData()));
//        }
//    }
//    return root;
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Return
//
//    Call clearBST(root's left)
//    Call clearBST(root's right)
//
//    Delete root
//    Set root to NULL
//    Set count to 0
//*/
//auto BST<T>::clearBST(binaryNode<T>* root)
//{
//    if (root == nullptr)
//        return;
//
//    clearBST(root->getLeft());
//    clearBST(root->getRight());
//
//    delete root;
//    root = nullptr;
//    count = 0;
//}
//
//template<typename T>
///*==================================================================
//    if root is NULL
//        Return
//    if height is 1
//        Print root's data
//    else if height is greater than 1
//        Call breadthFirstTraverse(root's left, height - 1, ostream object)
//        Call breadthFirstTraverse(root's right, height - 1, ostream object)
//*/
//void BST<T>::breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const
//{
//    if (root == NULL)
//        return;
//    if (height == 1) {
//        os << root->getData() << " ";
//    }
//    else if (height > 1)
//    {
//        breadthFirstTraverse(root->getLeft(), height - 1, os);
//        breadthFirstTraverse(root->getRight(), height - 1, os);
//    }
//
//}
//template <typename T>
//void BST<T>::breadthFirstTraverseWithQueue(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == NULL) {//empty check
//        std::cout << "Tree is empty" << std::endl;
//
//    }
//    else {
//        if (root == NULL) {//base check
//            return;
//        }
//        queue<binaryNode<T>*> *q = new queue<binaryNode<T>*>();//need to use a queue for this one
//        q->enqueue(root);
//
//        queue<std::string> *treeNodes = new queue<std::string>();
//
//        while (q->isEmpty() == false) {
//            int count = q->getCount();
//            int treeNodeCount = treeNodes->getCount();
//            while (treeNodeCount > 0) {
//                std::string treeNode = treeNodes->peekFront()->GetData();
//                treeNodes->dequeue();
//                os << treeNode;
//                treeNodeCount--;
//            }
//            os << std::endl;
//            while (count > 0) {
//                binaryNode<T>* first = q->peekFront()->GetData();
//                std::cout << first->getData()->getYear() << "-" << first->getData()->getChamp() << " ";
//                if (first->getLeft() != NULL) {//left check
//                    q->enqueue(first->getLeft());//enque left
//                    treeNodes->enqueue("/");
//                    if (first->getRight() != NULL) {
//                        treeNodes->enqueue("       ");
//                    }
//                }
//                if (first->getRight() != NULL) {//right check
//                    if (first->getLeft() == NULL) {
//                        treeNodes->enqueue("       ");
//                    }
//                    q->enqueue(first->getRight());//enque right
//                    treeNodes->enqueue("\\");
//                }
//                else {
//                    if (first->getLeft() != NULL) {
//                        treeNodes->enqueue("       ");
//                    }
//                }
//                q->dequeue();//remove that B
//                count--;
//            }
//            cout << endl;
//        }
//    }
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Return
//
//    Print root's data
//    Call preorderTraverse(root's left, ostream object)
//    Call preorderTraverse(root's right, ostream object)
//*/
//void BST<T>::preorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
//
//    os << root->getData() << "\n";
//    preorderTraverse(root->getLeft(), os);
//    preorderTraverse(root->getRight(), os);
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Return
//
//    Call inorderTraverse(root's left, ostream object)
//    Print root's data
//    Call inorderTraverse(root's right, ostream object)
//*/
//void BST<T>::inorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
//
//    inorderTraverse(root->getLeft(), os);
//    os << root->getData() << "\n";
//    inorderTraverse(root->getRight(), os);
//}
//
//template <typename T>
///*==================================================================
//    if root is NULL
//        Return
//
//    Call postorderTraverse(root's left, ostream object)
//    Call postorderTraverse(root's right, ostream object)
//    Print root's data
//*/
//void BST<T>::postorderTraverse(binaryNode<T>* root, std::ostream& os) const
//{
//    if (root == nullptr)
//        return;
//
//    postorderTraverse(root->getLeft(), os);
//    postorderTraverse(root->getRight(), os);
//    os << root->getData() << " ";
//}
////-------------------------------------------------------------------
////  Constructor and Destructor section
////-------------------------------------------------------------------
//template<typename T>
///*==================================================================
//    Set rootPtr to NULL
//    Set count to 0
//*/
//BST<T>::BST()
//{
//    rootPtr = nullptr;
//    count = 0;
//}
//
//template<typename T>
///*
//    Set rootPtr to new Node in binary tree with data
//    Set left of rootPtr to NULL
//    Set right of rootPtr to NULL
//    Set count to 1
//*/
//BST<T>::BST(const T data)
//{
//    rootPtr = new binaryNode<T>(data);
//    rootPtr->setLeft(nullptr);
//    rootPtr->setRight(nullptr);
//    count = 1;
//}
//
//template<typename T>
///*
//    Call clearBST()
//*/
//BST<T>::~BST()
//{
//    clearBST();
//}
//
////-------------------------------------------------------------------
////  Public Methods Functions
////-------------------------------------------------------------------
//template<typename T>
///*
//    if rootPtr is NULL
//        Return True
//    Else
//        Return False
//*/
//bool BST<T>::isEmpty() const
//{
//    if (rootPtr == nullptr)
//        return true;
//    else
//        return false;
//}
//
//template <typename T>
///*
//    Call insertBST(rootPtr, data)
//    Increment count by 1
//*/
//void BST<T>::add(const T data)
//{
//    insertBST(rootPtr, data);
//    count++;
//}
//
//template <typename T>
///*
//    Call deleteBST(rootPtr, data)
//    Decrement count by 1
//*/
//void BST<T>::remove(const T data)
//{
//    deleteBST(rootPtr, data);
//    count--;
//}
//
//
////------------------------------------------------------------------
////  Public Traversals Section
////------------------------------------------------------------------
//template<typename T>
///*
//    for i in range of height of BST
//        Call breadthFirstTraverse(rootPtr, i, ostream object)
//*/
//void BST<T>::displayBreadthFirst(std::ostream& os)
//{
//    int height = heightOfBST();
//    for (int i = 0; i <= height; i++) {
//        breadthFirstTraverse(rootPtr, i, os);
//        os << std::endl;
//    }
//}
//
//template<typename T>
//void BST<T>::displayBreadthFirstWithQueue(std::ostream& os)
//{
//    breadthFirstTraverseWithQueue(rootPtr, os);
//}

class Trunk
{
public:
    Trunk *prev;
    std::string str;
    
    Trunk() {
        
    }
    
    Trunk(Trunk *prev, std::string node)
    {
        this->prev = prev;
        this->str = node;
    }
    
};

template <typename T>
class BST
{
private:
    binaryNode<T>* rootPtr;
    int count;
    
protected:
    //------------------------------------------------------------------
    //  Protected Utility Methods Section.
    //  Recursive helper functions  for the public methods.
    //------------------------------------------------------------------
    /*
     Pre: BinaryNode pointer
     Post: Returns largest value in Binary tree
     Return: largest value in Binary tree
     */
    auto findLargest(binaryNode<T>* treePtr);
    
    /*
     Pre: BinaryNode pointer
     Post: Height of Binary Tree is returned
     Return: Height of Binary Tree
     */
    int getHeight(binaryNode<T>* root);
    
    /*
     Pre: BinaryNode pointer and data being searched for
     Post: Returns true if data exists in Binary tree
     Return: True if data is in Binary tree, false otherwise
     */
    BST<T>* searchBST(binaryNode<T>* root, T data);
    
    /*
     Pre: BinaryNode pointer and data being inserted
     Post: Inserts data into Binary Tree
     Return: BinaryNode pointer
     */
    binaryNode<T>* insertBST(binaryNode<T>* root, T data);
    /*
     Pre: BinaryNode pointer and data being removed
     Post: Removes data from Binary Tree
     Return: BinaryNode pointer
     */
    binaryNode<T>* deleteBST(binaryNode<T>* root, const T data);
    
    
    /*
     Pre: BinaryNode pointer
     Post: Clears Binary Search Tree
     Return: Returns none when Binary Tree is cleared
     */
    auto clearBST(binaryNode<T>* root);
    
    /*
     Pre: BinaryNode pointer, height of tree, and ostream object
     Post: Prints to screen and output file a breadth first traversal of binary tree,
     by height
     Return: None
     */
    void breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const;
    
    void breadthFirstTraverseWithQueue(binaryNode<T>* root, std::ostream& os) const;
    
    /*
     Pre: BinaryNode pointer and ostream object
     Post: Prints to screen and output file a preorder traversal of binary tree
     Return: None
     */
    void preorderTraverse(binaryNode<T>* root, std::ostream& os) const;
    
    /*
     Pre: BinaryNode pointer and ostream object
     Post: Prints to screen and output file a inorder traversal of binary tree
     Return: None
     */
    void inorderTraverse(binaryNode<T>* root, std::ostream& os) const;
    
    /*
     Pre: BinaryNode pointer and ostream object
     Post: Prints to screen and output file a postorder traversal of binary tree
     Return: None
     */
    void postorderTraverse(binaryNode<T>* root, T data, ostream &os) const;
    
    void printBranches(Trunk *p, std::ostream& os) const;
    
    void displayHorizontalTree(binaryNode<T>* root, Trunk *prev, bool isLeft, std::ostream& os) const;
    
public:
    //-------------------------------------------------------------------
    //  Constructor and Destructor section
    //-------------------------------------------------------------------
    BST(); // Default Constructor
    BST(const T data); // Overloaded Constructor
    BST(const BST *obj);
    ~BST(); // Destructor
    
    //-------------------------------------------------------------------
    //  Public Methods Functions
    //-------------------------------------------------------------------
    
    /*
     Pre: None
     Post: Checks if rootPtr is NULL or not
     Return: True if rootPTR is NULL, false otherwise
     */
    bool isEmpty() const;
    
    /*
     Pre: Data to be added
     Post: insertBST function is called with rootPtr and data parameters
     Count is also incremented
     Return: None
     */
    void add(const T data);
    
    /*
     Pre: Data to be removed
     Post: deleteBST function is called with rootPtr and data parameters
     Count is also decremented
     Return: None
     */
    void remove(const T data);
    
    int getNumberOfNodes() { return count; } // Getter function for number of nodes
    
    /*
     Pre: None
     Post: Calls clearBST helper with rootPtr parameter
     Return: None
     */
    void clearBST() { return clearBST(rootPtr); }
    
    /*
     Pre: Input to be searched
     Post: Calls searchBST helper with rootPtr and data being searched parameters
     Return: True if input is found in binary tree, false otherwise
     */
    BST* search(T input) { return searchBST(rootPtr, input); }
    
    /*
     Pre: None
     Post: Calls getHeight helper with rootPtr parameter
     Return: Height of Binary search tree
     */
    int heightOfBST() { return getHeight(rootPtr); }
    
    //------------------------------------------------------------------
    //  Public Traversals Section
    //------------------------------------------------------------------
    
    /*
     Pre: ostream object
     Post: Calls breadthFirstTraverse for each level of tree
     Return: None
     */
    void displayBreadthFirst(std::ostream& os);
    
    
    void displayBreadthFirstWithQueue(std::ostream& os);
    
    /*
     Pre: ostream object
     Post: Calls preorderTraverse with rootPtr and ostream object parameters
     Return: None
     */
    void displayPreOrder(std::ostream& os) { preorderTraverse(rootPtr, os); }
    
    /*
     Pre: ostream object
     Post: Calls inorderTraverse with rootPtr and ostream object parameters
     Return: None
     */
    void displayInOrder(std::ostream& os) { inorderTraverse(rootPtr, os); }
    
    /*
     Pre: ostream object
     Post: Calls postorderTraverse with rootPtr and ostream object parameters
     Return: None
     */
    
    void displayPostOrder(T data, std::ostream &os) {postorderTraverse(rootPtr, data, os);}
    
    void displayHorizontalTreeNoRoot(Trunk *previous, bool isLeft, std::ostream& os);
    
//    bool operator==(const T data);
};

//------------------------------------------------------------------
//  Protected Utility Methods Section.
//  Recursive helper functions for the public methods.
//------------------------------------------------------------------


template <typename T>
/*==================================================================
 if right of root is NULL
 Return root
 Return findLargest(right of root)
 */
auto BST<T>::findLargest(binaryNode<T>* root)
{
    if (root->getRight() == nullptr)
        return root;
    
    return findLargest(root->getRight());
}


template<typename T>
/*==================================================================
 if root is NULL
 Return 0
 else
 if left height is greater than right height
 return left height + 1
 else
 return right height + 1
 */
int BST<T>::getHeight(binaryNode<T>* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = getHeight(root->getLeft());
        int rightHeight = getHeight(root->getRight());
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

template <typename T>
/*==================================================================
 if root is NULL
 Return false
 else if data is less than root's data
 Return searchBST(left of root, data)
 else if data is greater than root's data
 Return searchBST(right of root, data)
 else
 Return true
 */
BST<T>* BST<T>::searchBST(binaryNode<T>* root, T data)
{
    if (root == nullptr)
        return nullptr;
    else if (data < root->getData())
        return searchBST(root->getLeft(), data);
    else if (data > root->getData())
        return searchBST(root->getRight(), data);
    else
        return root;
}

template <typename T>
/*==================================================================
 if root is NULL
 Create new BinaryNode called root and set its data
 Set root's left to NULL
 Set root's right to NULL
 else
 if data is less than root's data
 Set root's left to insertBST(root's left, data)
 else
 Set root's right to insertBST(root's right, data)
 Return root
 */
binaryNode<T>* BST<T>::insertBST(binaryNode<T>* root, T data)
{
    if (root == nullptr)
    {
        root = new binaryNode<T>(data);
        root->setLeft(NULL);
        root->setRight(NULL);
    }
    else
    {
        if (data < (root->getData()))
            root->setLeft(insertBST(root->getLeft(), data));
        else
            root->setRight(insertBST(root->getRight(), data));
    }
    return root;
}

//template <typename T>
//binaryNode<T>* BST<T>::insertBST(binaryNode<T>* root, T data)
//{
//    if (root == nullptr)
//    {
//        root = new binaryNode<T>(data);
//        root->setLeft(NULL);
//        root->setRight(NULL);
//    }
//    else
//    {
//        if (*data < (root->getData()))
//            root->setLeft(insertBST(root->getLeft(), data));
//        else
//            root->setRight(insertBST(root->getRight(), data));
//    }
//    return root;
//}
/*==================================================================
 if root is NULL
 return NULL
 else if data is less than root's data
 set root's left to deleteBST(root's left, data)
 else if data is greater than root's data
 set root's right to deleteBST(root's right, data)
 else
 if root's left is NULL
 Create temporary binaryNode pointer and set to root
 Set root to root's right
 Delete temporary pointer
 else if root's left is NULL
 Create temporary binaryNode pointer and set to root
 Set root to root's left
 Delete temporary pointer
 else
 //Create temporary binaryNode pointer and set to largest Node in tree
 Set root's data to temporary pointer's data
 Set root's left to deleteBST(root's left, temporary pointer's data)
 Return root
 */
template <typename T>
binaryNode<T>* BST<T>::deleteBST(binaryNode<T>* root, const T data)
{
    if (root == nullptr) {
        return NULL;
    }
    else if (*data < *(root->getData())) {
        root->setLeft(deleteBST(root->getLeft(), data));
    }
    else if (*data > *(root->getData())) {
        root->setRight(deleteBST(root->getRight(), data));
    }
    else
    {
        if (root->getLeft() == nullptr)
        {
            binaryNode<T>* tmpPtr = root;
            root = root->getRight();
            delete tmpPtr;
        }
        else if (root->getLeft() == nullptr)
        {
            binaryNode<T>* tmpPtr = root;
            root = root->getLeft();
            delete tmpPtr;
        }
        else
        {
            binaryNode<T>* tmpPtr = findLargest(root->getLeft());
            root->setData(tmpPtr->getData());
            root->setLeft(deleteBST(root->getLeft(), tmpPtr->getData()));
        }
    }
    return root;
}

template <typename T>
/*==================================================================
 if root is NULL
 Return
 
 Call clearBST(root's left)
 Call clearBST(root's right)
 
 Delete root
 Set root to NULL
 Set count to 0
 */
auto BST<T>::clearBST(binaryNode<T>* root)
{
    if (root == nullptr)
        return;
    
    clearBST(root->getLeft());
    clearBST(root->getRight());
    
    delete root;
    root = nullptr;
    count = 0;
}

template<typename T>
/*==================================================================
 if root is NULL
 Return
 if height is 1
 Print root's data
 else if height is greater than 1
 Call breadthFirstTraverse(root's left, height - 1, ostream object)
 Call breadthFirstTraverse(root's right, height - 1, ostream object)
 */
void BST<T>::breadthFirstTraverse(binaryNode<T>* root, int height, std::ostream& os) const
{
    if (root == NULL)
        return;
    if (height == 1) {
        os << root->getData() << " ";
    }
    else if (height > 1)
    {
        breadthFirstTraverse(root->getLeft(), height - 1, os);
        breadthFirstTraverse(root->getRight(), height - 1, os);
    }
    
}
template <typename T>
void BST<T>::breadthFirstTraverseWithQueue(binaryNode<T>* root, std::ostream& os) const
{
    if (root == NULL) {//empty check
        os << "Tree is empty" << std::endl;
        
    }
    else {
        if (root == NULL) {//base check
            return;
        }
        queue<binaryNode<T>*> *q = new queue<binaryNode<T>*>();//need to use a queue for this one
        q->enqueue(root);
        
        queue<std::string> *treeNodes = new queue<std::string>();
        
        while (q->isEmpty() == false) {
            int count = q->getCount();
            int treeNodeCount = treeNodes->getCount();
            while (treeNodeCount > 0) {
                std::string treeNode = treeNodes->peekFront()->GetData();
                treeNodes->dequeue();
                os << treeNode;
                treeNodeCount--;
            }
            os << std::endl;
            while (count > 0) {
                binaryNode<T>* first = q->peekFront()->GetData();
                os << first->getData()->year << "-" << first->getData()->champ << " ";
                if (first->getLeft() != NULL) {//left check
                    q->enqueue(first->getLeft());//enque left
                    treeNodes->enqueue("/");
                    if (first->getRight() != NULL) {
                        treeNodes->enqueue("       ");
                    }
                }
                else if (first->getLeft() == NULL) {
                    if (first->getRight() != NULL) {
                        treeNodes->enqueue("      ");
                    }
                }
                if (first->getRight() != NULL) {//right check
                    if (first->getLeft() == NULL) {
                        treeNodes->enqueue("  ");
                    }
                    q->enqueue(first->getRight());//enque right
                    treeNodes->enqueue(" \\  ");
                }
                else {
                    if (first->getLeft() != NULL) {
                        treeNodes->enqueue("       ");
                    }
                }
                q->dequeue();//remove
                count--;
            }
            cout << endl;
        }
    }
}

template <typename T>
void BST<T>::displayHorizontalTree(binaryNode<T>* root, Trunk *prev, bool isLeft, std::ostream& os) const {
    
    if (root == nullptr) {
        return;
    }
    string prev_str = "    ";
    Trunk *t = new Trunk(prev, prev_str);
    displayHorizontalTree(root->getLeft(), t, true, os);
    
    if (!prev) {
       t->str = "---";
    }
    else if (isLeft) {
        t->str = ".---";
        prev_str = "   |";
    }
    else {
        t->str = "`---";
        prev->str = prev_str;
    }
    
    printBranches(t, os);
    os << root->getData()->year << "-" << root->getData()->champ  << std::endl;
    
    if (prev) {
        prev->str = prev_str;
    }
    t->str = "   |";
    displayHorizontalTree(root->getRight(), t, false, os);
    
}

template <typename T>
void BST<T>::printBranches(Trunk *p, std::ostream& os) const {
    if (p == nullptr) {
        return;
    }
    printBranches(p->prev, os);
    os << p->str;
}

template <typename T>
/*==================================================================
 if root is NULL
 Return
 
 Print root's data
 Call preorderTraverse(root's left, ostream object)
 Call preorderTraverse(root's right, ostream object)
 */
void BST<T>::preorderTraverse(binaryNode<T>* root, std::ostream& os) const
{
    if (root == nullptr)
        return;
    
    os << root->getData() << "\n";
    preorderTraverse(root->getLeft(), os);
    preorderTraverse(root->getRight(), os);
}

template <typename T>
/*==================================================================
 if root is NULL
 Return
 
 Call inorderTraverse(root's left, ostream object)
 Print root's data
 Call inorderTraverse(root's right, ostream object)
 */
void BST<T>::inorderTraverse(binaryNode<T>* root, std::ostream& os) const
{
    if (root == nullptr)
        return;
    
    inorderTraverse(root->getLeft(), os);
    os << root->getData()  << " " << root << "\n";
    inorderTraverse(root->getRight(), os);
}


template <typename T>
/*==================================================================
 if root is NULL
 Return
 
 Call postorderTraverse(root's left, ostream object)
 Call postorderTraverse(root's right, ostream object)
 Print root's data
 */
void BST<T>::postorderTraverse(binaryNode<T>* root, T data, std::ostream &os) const
{
    if(root == NULL)
    {
        return;
    }
    std::cout  << "After null.\n";
    if(data == root->getData())
    {
        os << root << std::endl;
        std::cout << "Output done.\n";
        return;
    }
    std::cout << "After second\n";
    if (root == nullptr)
        return;
    
    postorderTraverse(root->getLeft(), data, os);
    postorderTraverse(root->getRight(), data, os);
}
//-------------------------------------------------------------------
//  Constructor and Destructor section
//-------------------------------------------------------------------
template<typename T>
/*==================================================================
 Set rootPtr to NULL
 Set count to 0
 */
BST<T>::BST()
{
    rootPtr = nullptr;
    count = 0;
}

template<typename T>
/*
 Set rootPtr to new Node in binary tree with data
 Set left of rootPtr to NULL
 Set right of rootPtr to NULL
 Set count to 1
 */
BST<T>::BST(const T data)
{
    rootPtr = new binaryNode<T>(data);
    rootPtr->setLeft(nullptr);
    rootPtr->setRight(nullptr);
    count = 1;
}

template<typename T>
BST<T>::BST(const BST<T> *obj)
{
    if(rootPtr == nullptr)
    {
        rootPtr = new binaryNode<T>(*obj);
        rootPtr->setLeft(NULL);
        rootPtr->setRight(NULL);
    }
    else
    {
        if(*obj < *rootPtr)
        {
            rootPtr->setLeft(insertBST(rootPtr->getLeft(), *obj));
        }
        else
        {
            rootPtr->setRight(insertBST(rootPtr->getRight(), *obj));
        }
    }
}

template<typename T>
/*
 Call clearBST()
 */
BST<T>::~BST()
{
    clearBST();
}

//-------------------------------------------------------------------
//  Public Methods Functions
//-------------------------------------------------------------------
template<typename T>
/*
 if rootPtr is NULL
 Return True
 Else
 Return False
 */
bool BST<T>::isEmpty() const
{
    if (rootPtr == nullptr)
        return true;
    else
        return false;
}

template <typename T>
/*
 Call insertBST(rootPtr, data)
 Increment count by 1
 */
void BST<T>::add(const T data)
{
    insertBST(rootPtr, data);
    count++;
}

template <typename T>
/*
 Call deleteBST(rootPtr, data)
 Decrement count by 1
 */
void BST<T>::remove(const T data)
{
    deleteBST(rootPtr, data);
    count--;
}


//------------------------------------------------------------------
//  Public Traversals Section
//------------------------------------------------------------------
template<typename T>
/*
 for i in range of height of BST
 Call breadthFirstTraverse(rootPtr, i, ostream object)
 */
void BST<T>::displayBreadthFirst(std::ostream& os)
{
    int height = heightOfBST();
    for (int i = 0; i <= height; i++) {
        breadthFirstTraverse(rootPtr, i, os);
        os << std::endl;
    }
}

template<typename T>
void BST<T>::displayBreadthFirstWithQueue(std::ostream& os)
{
    breadthFirstTraverseWithQueue(rootPtr, os);
}

template<typename T>
void BST<T>::displayHorizontalTreeNoRoot(Trunk *previous, bool isLeft, std::ostream &os) {
    displayHorizontalTree(rootPtr, nullptr, false, os);
}


#endif /* BST_h */
