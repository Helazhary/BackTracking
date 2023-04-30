#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

int Knapsack(vector<Item>& items, int W, int idx = 0, int valueSoFar = 0) {
    // base case: no more items left or no capacity left
    if (idx == items.size() || W == 0) {
        return valueSoFar;
    }

    // check if including the current item is beneficial
    if (items[idx].weight <= W) {
        int include = Knapsack(items, W - items[idx].weight, idx + 1, valueSoFar + items[idx].value);
        int exclude = Knapsack(items, W, idx + 1, valueSoFar);
        return max(include, exclude);
    } else { // exclude the current item as it cannot fit in the remaining capacity
        return Knapsack(items, W, idx + 1, valueSoFar);
    }
}

int main() {
    // create a vector of items
    vector<Item> items = {{2, 10}, {5, 20}, {7, 30}, {3, 15}};

    int W = 10; // maximum capacity of the knapsack
    int maxValue = Knapsack(items, W);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
