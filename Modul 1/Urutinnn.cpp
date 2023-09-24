#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT_COUNT = 1000;

struct Stack {
    int data[MAX_INPUT_COUNT];
    int top;

    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top < MAX_INPUT_COUNT - 1) {
            top++;
            data[top] = value;
        } else {
            cout << "Stack overflow. Input count exceeded the maximum limit of " << MAX_INPUT_COUNT << "." << endl;
            exit(1);
        }
    }

    int pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            cout << "Stack underflow. Trying to pop from an empty stack." << endl;
            exit(1);
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

void sortStack(Stack &input) {
    Stack tmpStack;

    while (!input.isEmpty()) {
        int tmp = input.pop();

        while (!tmpStack.isEmpty() && tmpStack.data[tmpStack.top] > tmp) {
            input.push(tmpStack.pop());
        }

        tmpStack.push(tmp);
    }

    while (!tmpStack.isEmpty()) {
        input.push(tmpStack.pop());
    }
}

int main() {
    Stack input;
    string inputStr;
    int inputCount = 0; 

    while (true) {
        cin >> inputStr;

        if (inputStr == "done") {
            break;
        }

        if (inputCount >= MAX_INPUT_COUNT) {
            cout << "Input count exceeded the maximum limit of " << MAX_INPUT_COUNT << "." << endl;
            return 1; 
        }

        int num = stoi(inputStr); 
        input.push(num);
        inputCount++;
    }

    sortStack(input);

    while (!input.isEmpty()) {
        cout << input.pop() << " ";
    }

    cout << endl;

    return 0;
}