#include "../includes/myAVLTree.h"

int AVLTree::getHeight(Node* node)
{
    return (node ? node->height : -1);
}

int AVLTree::balanceFactor(Node* node)
{
    return getHeight(node->left) - getHeight(node->right);
}

AVLTree::Node* AVLTree::rotateRight(Node* y)
{
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x)
{
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLTree::Node* AVLTree::insert(Node* root, int data)
{
    if (!root)
        return new Node{ data };

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    if (balance > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLTree::Node* AVLTree::findMin(Node* node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

AVLTree::Node* AVLTree::deleteNode(AVLTree::Node* root, int data)
{
    if (!root)
        return nullptr;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (!root->left || !root->right)
        {
            AVLTree::Node* temp = root->left ? root->left : root->right;

            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else
        {
            AVLTree::Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return nullptr;

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::inOrder(Node* root)
{
    if (root)
    {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

bool AVLTree::search(Node* root, int data)
{
    if (!root)
        return false;

    if (root->data == data)
        return true;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

void AVLTree::insert(int data)
{
    m_root = insert(m_root, data);
}

void AVLTree::remove(int data)
{
    m_root = deleteNode(m_root, data);
}

void AVLTree::display()
{
    inOrder(m_root);
    std::cout << std::endl;
}

bool AVLTree::find(int data)
{
    return search(m_root, data);
}

AVLTree::Node* AVLTree::getRoot()
{
    return m_root;
}
