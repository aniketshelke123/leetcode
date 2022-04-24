
# include <iostream>
# include <vector>

using namespace std;

bool searchmatrix(vector<vector<int>>& matrix, int target) {
    int start = 0;
	int end = matrix[0].size() - 1;  // here end is col len - 1

	while(start < matrix.size() && end >= 0){
		if (target == matrix[start][end]){
			return true;
		}
		else if(target < matrix[start][end]){
			end--;  // move left
		}
		else{
			start++;   // move down
		}
	}
	return false;   
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

    if (searchmatrix(matrix, target)){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }


    return 0;
}
