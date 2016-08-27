#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int sz = prices.size();

        if (sz == 0 || sz == 1)
            return 0;

        int price_min = prices[0];

        int *profit = new int[sz]();
        profit[0] = 0;
        int best_return = 0;

        for (auto i = 0;  i < sz; i++) {
            if (price_min > *(prices.begin() + i))
                price_min = *(prices.begin() + i);

            if (i > 0) {
                if (*(prices.begin() + i) > profit[i - 1])
                    profit[i] = *(prices.begin() + i) - price_min;
                else
                    profit[i] = profit[i - 1];
            }

            best_return = best_return > profit[i] ? best_return : profit[i];


        }

        delete []profit;
        return best_return;

    }
};

int main(){
    Solution a;
    vector<int> b = {7, 1, 2, 6, 3};

    cout << a.maxProfit(b);
}