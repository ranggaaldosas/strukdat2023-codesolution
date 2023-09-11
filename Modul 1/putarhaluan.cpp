#include <iostream>

using namespace std;

struct SListNode 
{
    int data;
    SListNode *next;
}; 

struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushBack(int value)
    {
        SListNode *newNode = new SListNode;
        _size++;
        newNode->data = value;
        newNode->next = NULL;
            
        if (isEmpty()) 
            _head = newNode;
        else 
        {
            SListNode *temp = _head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void reverse()
    {
        SListNode *prev = NULL;
        SListNode *current = _head;
        SListNode *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        _head = prev;
    }

    void printList()
    {
        SListNode *current = _head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyList myList;
    myList.init();

    int value;
    cin >> value;
    while (value != 0) {
        myList.pushBack(value);
        cin >> value;
    }

    myList.reverse();
    myList.printList();

    return 0;
}
