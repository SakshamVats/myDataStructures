#include "../includes/myHashTable.h"

int HashTable::hashFunction(int key)
{
    return key % m_capacity;
}

HashTable::HashTable()
    : m_table(m_capacity)
{}

void HashTable::insert(int key, int value)
{
    int index{ hashFunction(key) };
    m_table[index].insertAtHead(key, value);
}

int HashTable::search(int key)
{
    int index{ hashFunction(key) };
    return m_table[index].search(key);
}

void HashTable::remove(int key)
{
    int index{ hashFunction(key) };
    m_table[index].remove(key);
}

void HashTable::print()
{
    for (int i{ 0 }; i < m_capacity; ++i)
    {
        std::cout << "Bucket " << i << ": ";
        m_table[i].print();
    }
}

