#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}


void partition3(vector<int> &a, int l, int r){
    int v = a[l];

    int i = l;
    int lo = l;
    int hi = r;

    while(i <= hi)
    {
        if (a[i] < v)
        {
            swap(a[i], a[lo]);
            i++;
            lo++;
        }
        else if(a[i] > v)
        {
            swap(a[i], a[hi]);
            hi--;
        }
        else{
            i++;
        }

//        for (auto i = l; i <= r; i++)
//            cout << a[i] << " ";
//            cout << endl;
    }

}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

//    for (auto i = l; i <= r; i++)
//        cout << a[i] << " ";
//    cout << endl;

    partition3(a, l, r);

    partition3(a, l, k - 1);
    partition3(a, m + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size()-1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
