#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    std::vector<int> graph[512];
    int vertex;
    int edge;
public:
    int max;
    int min;
public:
    Graph() {
        std::cin >> vertex >> edge;

        for (int i = 0; i < edge; i++) {
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    void search_min(int start, int end) {
        std::vector<int> dist(vertex, 1000);
        std::vector<bool> used(vertex);
        dist[start] = 0;
        used[start] = true;

        std::priority_queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int v = -q.top();
            q.pop();
            for (auto& i : graph[v]) {
                if ((dist[v]+1) < dist[i] and !used[i]) {
                    q.push(-i);
                    dist[i] = dist[v]+1;
                    used[i] = true;
                }
            }
        }
        min = dist[end];
    }

    void deep_search(int index) {
        static std::vector<bool> used(vertex);
        used[index] = true;
        std::cout << index << " ";

        for (int i : graph[index]) {
            if (not used[i]) {
                deep_search(i);
                std::cout << index << " ";
            }
        }
    }

    void show() {
        for (int i = 0; i < vertex; i++) {
            std::cout << i << ": ";
            for (auto j : graph[i]) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    Graph o;
    o.show();
    std::cout << "Deep search: ";
    o.deep_search(2);

    std::cout << "\nSearch a min way: ";
    o.search_min(0, 7);
    std::cout << o.min << std::endl;

    return 0;
}
