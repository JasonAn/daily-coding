#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
    int n;
    std::vector<int> parent;
    std::vector<int> heights;

public:
    void read() {
        std::cin >> n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> parent[i];
            heights[i] = 0;
        }
    }

    int compute_height() {
        // Replace this code with a faster implementation
        int maxHeight = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            int height = 0;

            int i = vertex;

            if (i != -1 && heights[parent[i]] > 0) {
                    height += heights[parent[i]] + 1;
                    break;
            }
            else if(i != -1 && heights[parent[i]] == 0) {
                height++;
                i = parent[i];
                }

            heights[i] = height;

            maxHeight = std::max(maxHeight, height);
        }
        return maxHeight;
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    TreeHeight tree;
    tree.read();
    std::cout << tree.compute_height() << std::endl;
}

