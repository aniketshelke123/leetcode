# include <iostream>
# include <vector>

using namespace std;

void printLikeWave(vector<vector<int>> arr, int nRow, int mCol){
    vector <int> ans;

    for (int col = 0; col < mCol; ++col){
        if (col & 1){     // this means odd column
            for (int row = nRow - 1; row >= 0; row--){
                ans.push_back(arr[row][col]);

            }
        }
        else{
            for (int row = 0; row < nRow; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }

    cout << "The answer is: "  << endl;
    for (auto i: ans){
        cout << i << " ";
    }

}

int main()
{
    int nRows, nCol;
    cin >> nRows;
    cin >> nCol;
    vector<vector<int>> matrix(nRows, vector<int>(nCol,0));
    /*
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10}
    };
    */

    // take input in matrix   
    for (int i = 0; i < nRows; ++i){
        for (int j = 0; j < nCol; ++j){
            cin >> matrix[i][j];
        }
    }
    
    // print matrix
    cout << "Matrix is: " << endl;
    for (int i = 0; i < nRows; ++i){
        for (int j = 0; j < nCol; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 

    printLikeWave(matrix, nRows, nCol);
    
    return 0;

}