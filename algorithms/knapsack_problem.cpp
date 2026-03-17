#include <algorithm>
#include <iostream>
using namespace std;

struct Item {
    int weight;
    int profit;
    float ratio;
};

// Sort items based on profit/weight ratio (descending)
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    sort(items, items + n, compare);

    float totalProfit = 0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            cout << "Item with weight " << items[i].weight
                 << " and profit " << items[i].profit
                 << " selected completely\n";

            W -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            float fraction = (float)W / items[i].weight;

            cout << "Item with weight " << items[i].weight
                 << " and profit " << items[i].profit
                 << " selected fractionally\n";

            totalProfit += items[i].profit * fraction;
            break;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
