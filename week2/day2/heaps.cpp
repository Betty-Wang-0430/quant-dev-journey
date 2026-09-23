/*

## Heaps & Priority Queues

A **heap** is a data structure where the largest or smallest element is kept at the top.

### Max Heap

* Largest element is at the top.
* Parent is always ≥ its children.
* `top()` gives the largest element.

### Min Heap

* Smallest element is at the top.
* Parent is always ≤ its children.
* `top()` gives the smallest element.

### `std::priority_queue`

C++ provides a priority queue using a heap.

```cpp
std::priority_queue<int> pq;
```

Default = **max heap**.

```cpp
pq.push(10);   // insert
pq.top();      // look at largest
pq.pop();      // remove largest
```

Min heap:

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

### Complexity

| Operation | Complexity |
| --------- | ---------: |
| `top()`   |       O(1) |
| `push()`  |   O(log n) |
| `pop()`   |   O(log n) |

### When to use a heap

Use a heap when you repeatedly need the **largest or smallest element** while also adding/removing elements.

### Important

* **Heap** = data structure
* **Heap sort** = sorting algorithm that uses a heap
* A heap is **not fully sorted**; only the top element is guaranteed to be the minimum/maximum.


*/

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    pq.push(4);
    pq.push(10);
    pq.push(2);
    pq.push(7);
    pq.push(5);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    std::cout << "\n";

    return 0;
}