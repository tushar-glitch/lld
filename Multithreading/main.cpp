#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void function1() {
    // Simulate work
    for (int i = 0; i < 5000000; i++);
}
void function2() {
    // Simulate work
    for (int i = 0; i < 5000000; i++);
}

int main() {
    auto start = chrono::high_resolution_clock::now(); // Start time

    thread firstThread(function1); // Call your function
    thread secondThread(function2); // Call your function
    
    firstThread.join();
    secondThread.join();
    auto end = chrono::high_resolution_clock::now();   // End time
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
