#include <iostream>

// Strategy Interface
class SortStrategy {
public:
    virtual void sort(int arr[], int size) = 0;
    virtual ~SortStrategy() = default;
};

// Concrete Strategies
class QuickSort : public SortStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Using Quick Sort\n";
        // Actual sort logic...
    }
};

class BubbleSort : public SortStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Using Bubble Sort\n";
    }
};

// Context
class Sorter {
    SortStrategy* strategy;
public:
    void setStrategy(SortStrategy* s) { strategy = s; }
    void sortArray(int arr[], int size) {
        strategy->sort(arr, size);
    }
};

int main() {
    Sorter sorter;
    int arr[5] = {5, 2, 8, 1, 9};

    sorter.setStrategy(new QuickSort());
    sorter.sortArray(arr, 5);

    sorter.setStrategy(new BubbleSort());
    sorter.sortArray(arr, 5);

    return 0;
}
