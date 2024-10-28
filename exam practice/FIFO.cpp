// // C++ program to demonstrate
// // working of FIFO
// // using Queue interface in C++

// #include<bits/stdc++.h>
// using namespace std;

// // print the elements of queue
// void print_queue(queue<int> q)
// {
// 	while (!q.empty())
// 	{
// 		cout << q.front() << " ";
// 		q.pop();
// 	}
// 	cout << endl;
// }

// // Driver code
// int main()
// {
// 	queue<int> q ;

// 	// Adds elements {0, 1, 2, 3, 4} to queue
// 	for (int i = 0; i < 5; i++)
// 		q.push(i);

// 	// Display contents of the queue.
// 	cout << "Elements of queue-";
		
// 	print_queue(q);

// 	// To remove the head of queue.
// 	// In this the oldest element '0' will be removed
// 	int removedele = q.front();
// 	q.pop();
// 	cout << "removed element-" << removedele << endl;

// 	print_queue(q);

// 	// To view the head of queue
// 	int head = q.front();
// 	cout << "head of queue-" << head << endl;

// 	// Rest all methods of collection interface,
// 	// Like size and contains can be used with this
// 	// implementation.
// 	int size = q.size();
// 	cout << "Size of queue-" << size;
		
// 	return 0;
// }

// // This code is contributed by Arnab Kundu

#include <iostream>
using namespace std;

int main() {
    int n, t1 = 9, t2 = 6,t3=3, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
		if(i == 3)
		{
			cout<<t3<<" ; ";
			continue;
		}
        nextTerm = t1 + t2+ t3;
        t1 = t2;
        t2 = t3;
		t3 = nextTerm;
        
        cout << nextTerm << ", ";
    }
    return 0;
}