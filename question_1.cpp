#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int elem) {
    if (s.empty()) {
        s.push(elem);
    } else {
        int topElem = s.top();
        s.pop();
        insertAtBottom(s, elem);
        s.push(topElem);
    }
}


void reverseStack(std::stack<int>& s) {
    if (!s.empty()) {
        int topElem = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, topElem);
    }
}


void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
int main() {
    std::stack<int> s;   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    std::cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
