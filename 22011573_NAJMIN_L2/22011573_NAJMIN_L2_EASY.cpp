#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix : ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the matrix row by row (separated by space) :\n";
    for (int row = 0; row < n; ++row) {
        cout << "Enter row " << row + 1 << " : ";
        for (int col = 0; col < n; ++col) {
            cin >> matrix[row][col];
        }
    }

    int primSum = 0, secSum = 0;
    for (int i = 0; i < n; ++i) {
        primSum += matrix[i][i];
        secSum += matrix[i][n - i - 1];
    }

    cout << "Primary Diagonal Sum : " << primSum << endl;
    cout << "Secondary Diagonal Sum : " << secSum << endl;

    return 0;
}