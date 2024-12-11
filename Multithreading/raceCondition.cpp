#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int global_count = 0;
void function1() {
    // Simulate work
    for (int i = 0; i <= 20000000; i++){
        global_count++;
    }
}
void function2() {
    // Simulate work
    for (int i = 1; i <= 20000000; i++){
        global_count++;
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now(); // Start time

    thread firstThread(function1); // Call your function
    thread secondThread(function2); // Call your function
    
    firstThread.join();
    secondThread.join();
    
    cout<<global_count<<endl;
    
    auto end = chrono::high_resolution_clock::now();   // End time
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
