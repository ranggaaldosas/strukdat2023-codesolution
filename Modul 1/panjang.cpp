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
};

int main() {
    SinglyList myList;
    myList.init();

    int distance;
    int totalDistance = 0;

    while (cin >> distance) {
        if (distance == 0) {
            break;
        }
        
        totalDistance++;
        myList.pushBack(distance);
    }

    cout << totalDistance << endl;

    return 0;
}
