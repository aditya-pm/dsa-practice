// 121.

#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int maxProfit = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowest) lowest = prices[i];
            int currProfit = prices[i] - lowest;
            if (currProfit > maxProfit) maxProfit = currProfit;
        }
        return maxProfit;
    }
};