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
        heights.resize(n);
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

            while (i != -1){
                if (heights[parent[i]] > 0){
                    //std::cout << parent[i] << std::endl;
                    height += heights[parent[i]] + 1;
                    break;}
                else {
//                    std::cout << parent[i] << std::endl;
                    height++;
                    i = parent[i];
                    }
            }

            heights[i] = height;
            write();
            //maxHeight = std::max(maxHeight, height);
            //std::cout << maxHeight << std::endl;
        }
        return maxHeight;
    }

    void write(){
        for (auto i = 0; i < n; i++)
            std::cout << heights[i] << " ";
        std::cout << std::endl;
    }

};

int main() {
    std::ios_base::sync_with_stdio(0);
    TreeHeight tree;
    tree.read();
    std::cout << tree.compute_height() << std::endl;
    return 0;
}

