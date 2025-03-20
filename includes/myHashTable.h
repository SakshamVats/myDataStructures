#pragma once

#include <iostream>
#include <vector>
#include "../includes/myLinkedList.h"

class HashTable
{
private:
    std::vector<WeightedIntLinkedList> m_table{};
    static const int m_capacity{ 10 };

    static int hashFunction(int key);

public:
    HashTable();
    void insert(int key, int value);
    int search(int key);
    void remove(int key);
    void print();
};
