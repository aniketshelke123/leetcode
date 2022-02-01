
# include <iostream>
# include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    int start = 0;
    int end = (row * col) - 1;
    int mid_index = start + (end - start) / 2;
    
    while (start <= end){
        
        int mid_ele = matrix[mid_index / col][mid_index % col];
        
        if (mid_ele == target){
            return 1;
        }
        
        if (mid_ele < target){
            start = mid_index + 1;
        }
        
        else{
            end = mid_index - 1;
        }
        mid_index = start + (end - start) / 2;
    }
    return 0;
    
}
    
int main()
{
    int target = 5;
    vector<vector<int>> matrix 
    {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    if (searchMatrix(matrix, target)){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }


    return 0;
}