#include <iostream>
#include <queue>


void interleaveQueue(std::queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        std::cerr << "Queue length is not even" << std::endl;
        return;
    }

    std::queue<int> firstHalf;
    int halfSize = n / 2;

   
    for (int i = 0; i < halfSize; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

   
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); 
        firstHalf.pop();
        q.push(q.front());         
        q.pop();
    }
}


void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> q;

    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    std::cout << "Original Queue: ";
    printQueue(q);

    interleaveQueue(q);

    std::cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}

