#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sub_array(int & Sub_sofar, int & non_con){
    int n;
    cin >> n;

    int T[n];
    int Sub_max[n];

    for(int i = 0; i< n; i++) {
        cin >> T[i];
        Sub_max[i] = 0;
    }


    Sub_max[0] = T[0];
    Sub_sofar = Sub_max[0];
//    Sub_max[0] = max(0, T[0]);
//    Sub_sofar = 0;

    for (int i = 1; i < n; i++){
        Sub_max[i] = max(Sub_max[i-1] + T[i], T[i]);
        Sub_sofar = max(Sub_max[i], Sub_sofar);
        //cout << Sub_sofar << endl;
    }

    //cout << Sub_sofar << " ";

    non_con = 0;

    for(int i = 0; i < n; i++)
        if (T[i] > 0) {
            non_con += T[i];
        }

    if (*max_element(T, T + n) <= 0)
        non_con = *max_element(T, T + n);

    return 0;
}

int main(){

    int n;
    cin >> n;

    int ans[n * 2] = {0};

    for (int i = 0; i < n; i++)
        sub_array(ans[i * 2], ans[i * 2 + 1]);

    for (int i = 0; i < n; i++)
        cout << ans[i * 2] << " " << ans[i * 2 + 1] << endl;

    return 0;
}
