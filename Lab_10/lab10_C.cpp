#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int left, right, largest;
        while (index < heap.size()) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            largest = index;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;
            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;
            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        cout << "Deleted: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    void search(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                cout << "Found " << value << " at index " << i << endl;
                return;
            }
        }
        cout << "Value not found!" << endl;
    }

    void heapSort() {
        vector<int> tempHeap = heap;
        vector<int> sorted;
        while (!tempHeap.empty()) {
            swap(tempHeap[0], tempHeap.back());
            sorted.push_back(tempHeap.back());
            tempHeap.pop_back();
            int index = 0, left, right, largest;
            while (index < tempHeap.size()) {
                left = 2 * index + 1;
                right = 2 * index + 2;
                largest = index;
                if (left < tempHeap.size() && tempHeap[left] > tempHeap[largest])
                    largest = left;
                if (right < tempHeap.size() && tempHeap[right] > tempHeap[largest])
                    largest = right;
                if (largest == index) break;
                swap(tempHeap[index], tempHeap[largest]);
                index = largest;
            }
        }
        cout << "Sorted elements: ";
        for (int val : sorted)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    int choice, value;
    do {
        cout << "\nPriority Queue (Max Heap) Operations:" << endl;
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            heap.insert(value);
            break;
        case 2:
            heap.deleteMax();
            break;
        case 3:
            heap.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            heap.search(value);
            break;
        case 5:
            heap.heapSort();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
