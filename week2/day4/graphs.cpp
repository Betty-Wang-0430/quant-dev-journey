#include <iostream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        for (int neighbour : graph[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }  
}

void dfs(const std::vector<std::vector<int>>& graph, int current, std::vector<bool>& visited) {
    visited[current] = true;

    std::cout << current << " ";

    for (int neighbour : graph[current]) {
        if (!visited[neighbour]) {
            dfs(graph, neighbour, visited);
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph(4);
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    bfs(graph, 0);
    bfs(graph, 3);

    // dfs needs the same visited object throughout all the recursive calls
    dfs(graph, 0, visited);
    
}