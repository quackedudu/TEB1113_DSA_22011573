#include <iostream>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;

void bfs(const vector<vector<int>>& adjMatrix, int startNode) {
    vector<bool> visited(adjMatrix.size(), false);
    queue<int> q;
    char labels[] = {'A', 'B', 'C', 'D', 'E'};

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << labels[current] << " ";

        for (int neighbor = 0; neighbor < adjMatrix.size(); neighbor++) {
            if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> adjMatrix = {
        // Put adjacency matrix here
        {0, 1, 1, 1, 0},  // A
        {1, 0, 0, 1, 1},  // B
        {1, 0, 0, 1, 0},  // C
        {1, 1, 1, 0, 1},  // D
        {0, 1, 0, 1, 0}   // E
    };

    char input;
    cout << "Enter starting vertex (A-E): ";
    cin >> input;
    input = toupper(input);

    if (input >= 'A' && input <= 'E') {
        int startIndex = input - 'A';
        cout << "BFS traversal starting from " << input << ": ";
        bfs(adjMatrix, startIndex);
        cout << endl;
    } else {
        cout << "Invalid input. Please enter a letter from A to E." << endl;
    }

    return 0;
}
