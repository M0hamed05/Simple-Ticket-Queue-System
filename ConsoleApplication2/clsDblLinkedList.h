#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
private:
    int _Size;
public:

    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL)
        {
            head->prev = new_node;
        }
        head = new_node;
        _Size++;
    }

    Node* Find(T value)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->value == value) return current;
            current = current->next;
        }

        return NULL;
    }

    void InsertAfter(Node* current, T value)
    {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = current->next;
        new_node->prev = current;

        if (current->next != NULL)
        {
            current->next->prev = new_node;
        }
        current->next = new_node;
        _Size++;
    }

    void InsertAtEnd(T value)
    {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = NULL;

        if (head == NULL)
        {

            new_node->prev = NULL;
            head = new_node;
            _Size++;
            return;
        }

        Node* lastnode = head;
        while (lastnode->next != NULL)
            lastnode = lastnode->next;

        lastnode->next = new_node;
        new_node->prev = lastnode;
        _Size++;


    }

    void DeleteNode(Node* nodetodelete)
    {
        if (head == NULL || nodetodelete == NULL)
            return;

        if (head == nodetodelete)
            head = nodetodelete->next;

        if (nodetodelete->next != NULL)
            nodetodelete->next->prev = nodetodelete->prev;

        if (nodetodelete->prev != NULL)
            nodetodelete->prev->next = nodetodelete->next;

        delete nodetodelete;
        _Size--;

    }

    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            _Size--;
            return;
        }

        Node* current = head;

        while (current->next->next != NULL)
        {
            current = current->next;

        }
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;

    }

    void PrintList()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0) ? true : false;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    Node* GetNode(int Index)
    {
        if (Index > _Size - 1 || Index < 0) return NULL;

        Node* current = head;
        int counter = 0;

        while (current != NULL)
        {
            if (counter == Index)
                break;

            current = current->next;
            counter++;
        }

        return current;
    }

    T GetItem(int Index)
    {
        if (Index > _Size - 1 || Index < 0) return NULL;

        Node* current = head;
        int counter = 0;

        while (current != NULL)
        {
            if (counter == Index) return current->value;
            
            counter++;
            current = current->next;
        }

        return NULL;
    }

    void UpdateItem(int Index, T value)
    {
        if (Index > _Size - 1 || Index < 0) return;

        Node* current = head;
        int counter = 0;

        while (current != NULL)
        {
            if (counter == Index)  current->value = value;

            counter++;
            current = current->next;
        }
    }

    bool InsertAfter(int Index, T value)
    {
        if (Index > _Size - 1 || Index < 0) return false;

        Node* current = head;
        int counter = 0;

        while (current != NULL)
        {
            if (counter == Index) 
            {
                InsertAfter(current, value);
                return true;
            }
            counter++;
            current = current->next;
        }
        return false;
    }
};