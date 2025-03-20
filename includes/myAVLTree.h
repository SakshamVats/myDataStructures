#pragma once

#include <iostream>
#include <algorithm>

class AVLTree
{
private:
    struct Node
    {
        int data{ 0 };
        Node* left{ nullptr };
        Node* right{ nullptr };
        int height{ 0 };
    };

    Node* m_root{ nullptr };

    int getHeight(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* root, int data);
    Node* deleteNode(Node* root, int data);
    Node* findMin(Node* node);
    void inOrder(Node* root);
    bool search(Node* root, int data);

public:
    void insert(int data);
    void remove(int data);
    void display();
    bool find(int data);
    Node* getRoot();
};
