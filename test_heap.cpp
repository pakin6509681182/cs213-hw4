#include <iostream>  // This includes the standard library for input/output streams.
#include <queue>     // This includes the standard library for queue container.

int main() {  // This is the main function where the program starts execution.

    // Create a priority queue using a max heap
    std::priority_queue<int> pq;  // This declares a priority queue of integers. By default, it is a max heap.

    // Insert elements into the priority queue
    pq.push(10);  // This inserts the integer 10 into the priority queue.
    pq.push(30);  // This inserts the integer 30 into the priority queue.
    pq.push(20);  // This inserts the integer 20 into the priority queue.
    pq.push(5);   // This inserts the integer 5 into the priority queue.

    // Print the top element of the priority queue
    std::cout << "Top element: " << pq.top() << std::endl;  // This prints the top element of the priority queue, which is the maximum element (30 in this case).

    // Remove the top element from the priority queue
    pq.pop();  // This removes the top element from the priority queue.

    // Print the top element again
    std::cout << "Top element after pop: " << pq.top() << std::endl;  // This prints the top element of the priority queue after the previous top element has been removed. Now, the top element is 20.

    return 0;  // This indicates that the program has executed successfully.
}