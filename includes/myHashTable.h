#pragma once

#include <iostream>
#include <vector>
#include "includes/myLinkedList.h"

class HashTable
{
private:
    std::vector<WeightedIntLinkedList> m_table{};
    static const int m_capacity{ 10 };

    static int hashFunction(int key)
    {
        return key % m_capacity;
    }

public:
    HashTable()
        : m_table(m_capacity)
    {}

    void insert(int key, int value)
    {
        int index{ hashFunction(key) };
        m_table[index].insertAtHead(key, value);
    }

    int search(int key)
    {
        int index{ hashFunction(key) };
        return m_table[index].search(key);
    }

    void remove(int key)
    {
        int index{ hashFunction(key) };
        m_table[index].remove(key);
    }

    void print()
    {
        for (int i{ 0 }; i < m_capacity; ++i)
        {
            std::cout << "Bucket " << i << ": ";
            m_table[i].print();
        }
    }
};
