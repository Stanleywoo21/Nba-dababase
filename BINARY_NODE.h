#ifndef BINARY_NODE_h
#define BINARY_NODE_h
template <typename T>
class binaryNode {
private:
    T data;
    binaryNode* left;
    binaryNode* right;

public:
    binaryNode();

    binaryNode(const T nodeData);

    void setData(const T d);

    T& getData();

    binaryNode* getLeft() const;
    binaryNode* getRight() const;

    void setLeft(binaryNode* leftPtr);
    void setRight(binaryNode* rightPtr);
    ~binaryNode();
};

/*Constructor for binaryNode.
Pre:
Post: left, right - set to null
Return:
*/
template <typename T>
binaryNode<T>::binaryNode()
{
    data = 0;
    left = nullptr;
    right = nullptr;
}

/*Constructor for LinkNode.
Pre:
Post: left, right - set to null
Return:
*/
template <typename T>
binaryNode<T>::binaryNode(T nodeData)
{
    data = nodeData;
    left = nullptr;
    right = nullptr;
}

/*
Pre:d - data to set in a node
Post: assign given data to a node
Return:
*/
template <typename T>
void binaryNode<T>::setData(T d)
{
    data = d;
}

/*
Pre:
Post:
Return: data in a node
*/
template <typename T>
T& binaryNode<T>::getData()
{
    return data;
}

/*
Pre:
Post:
Return: return pointer
*/
template <typename T>
binaryNode<T>* binaryNode<T>::getLeft() const
{
    return left;
}

/*
Pre:
Post:
Return: return pointer
*/
template <typename T>
binaryNode<T>* binaryNode<T>::getRight() const
{
    return right;
}

/*
Pre: leftPtr
post: assign th egiven address to a left pointer
Return:
*/
template <typename T>
void binaryNode<T>::setLeft(binaryNode* leftPtr)
{
    left = leftPtr;
}

/*
Pre: rightptr
post: assign th egiven address to a right pointer
Return:
*/
template <typename T>
void binaryNode<T>::setRight(binaryNode* rightPtr)
{
    right = rightPtr;
}


template <typename T>
binaryNode<T>::~binaryNode()
{
}


#endif /* BINARY_NODE_h */
