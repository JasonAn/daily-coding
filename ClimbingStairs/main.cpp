#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        if (n > 2){
            int T[n] = {};

            T[0] = 1;
            T[1] = 2;

            int i = 2;

            while(i < n){
                T[i] = T[i-1] + T[i-2];
                i++;
            }

            return T[n-1];
        }

        return 0;
    }
};

int main(){

    Solution a;
    cout << a.climbStairs(7);
}