#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

void dfs(const vector<vector<int>>& adjMatrix, int startNode) {
    vector<bool> visited(adjMatrix.size(), false);
    stack<int> s;
    char labels[] = {'A', 'B', 'C', 'D', 'E'};

    s.push(startNode);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << labels[current] << " ";

            for (int neighbor = adjMatrix.size() - 1; neighbor >= 0; neighbor--) {
                if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> adjMatrix = {
        // Adjacency matrix here
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
        cout << "DFS traversal starting from " << input << ": ";
        dfs(adjMatrix, startIndex);
        cout << endl;
    } else {
        cout << "Invalid input. Please enter a letter from A to E." << endl;
    }

    return 0;
}
