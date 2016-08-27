#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int price_min = prices[0];
        int price_max = prices[0];

        for (auto i = prices.begin();  i < prices.end() ; i++) {
            if (price_max < *i)
                price_max = *i;
            if (price_min > *i)
                price_min = *i;
            price_max = price_max > *i ? price_max : *i;
            price_min = price_min < *i ? price_min : *i;
        }

        if (price_max > price_min)
            return price_max - price_min;
        else
            return 0;
    }
};

int main(){
    Solution a;
    vector<int> b = {1, 2, 3};

    cout << a.maxProfit(b);
}