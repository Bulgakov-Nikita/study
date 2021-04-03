#include <iostream>
#include <vector>
#include <map>

class Graph {
private:
    std::map<int, std::vector<int>> graph;
public:
    void create() {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    void show() {
        for (auto & i  : graph) {
            std::cout << i.first << ": |";
            for (auto & j : i.second) {
                std::cout << j << "|";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    Graph obj;
    obj.create();
    obj.show();

    return 0;
}
