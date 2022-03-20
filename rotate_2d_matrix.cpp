# include <bits/stdc++.h>
# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <string>
# include <ctype.h>
# define lli long long int
# define li long int
#define ld long double
using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
 
	int n = matrix.size();

    // before matrix
    cout << "Matrix is: " << endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 
	// to rotate the matrix to right first transpose and then reverse
	// transpose matrix
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			swap(matrix[i][j], matrix[j][i]);

		}
	}

    // reverse matrix to rotate to right
	int r1,r2, c1, c2;
	c1 = 0;
	c2 = n - 1;
	while(c1 < c2){
		r1 = 0; r2 = 0;
		while(r1 < n && r2 < n){
			swap(matrix[r1][c1], matrix[r2][c2]);
			r1++;
			r2++;
		}
		c1++;
		c2--;
	}

    // print after matrix
    cout << "Matrix is: " << endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }        
}
int main()
{
	
    vector<vector<int>> matrix
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10}
	};

	rotate(matrix);
	return 0;
}


