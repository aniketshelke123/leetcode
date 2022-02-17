# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int isSafe(int newx, int newy, int n, vector<vector<int>> visited, vector<vector<int>> matrix){
	if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0 ) && (matrix[newx][newy] == 1)){
		return true;
	}
	else{
		return false;
	}
}

void solve(int n, vector<vector<int>> matrix, vector<string> & ans, int x, int y, string path, vector<vector<int>> visited){
	// base case
	if (x == n - 1 && y == n - 1){
		ans.push_back(path);
		return;
	}

	visited[x][y] = 1;

	// down
	int newx = x + 1;
	int newy = y;
	if (isSafe(newx, newy, n, visited, matrix)){
		path.push_back('D');
		solve(n, matrix, ans, newx, newy, path, visited);
		path.pop_back();
	}

	// right
	newx = x;
	newy = y + 1;
	if (isSafe(newx, newy, n, visited, matrix)){
		path.push_back('R');
		solve(n, matrix, ans, newx, newy, path, visited);
		path.pop_back();
	}

	// left 
	newx = x;
	newy = y - 1;
	if (isSafe(newx, newy, n, visited, matrix)){
		path.push_back('L');
		solve(n, matrix, ans, newx, newy, path, visited);
		path.pop_back();
	}
	
	// UP
	newx = x - 1;
	newy = y;
	if (isSafe(newx, newy, n, visited, matrix)){
		path.push_back('U');
		solve(n, matrix, ans, newx, newy, path, visited);
		path.pop_back();
	}

	visited[x][y] = 0;


}

int main()
{
	int n = 4;

    vector<vector<int>> matrix
    {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1}
	};
	vector<vector <int>> visited = matrix;


	// assing visited as 0
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			visited[i][j] = 0;
		}
	}

	vector <string> ans;
	int srcx = 0;
	int srcy = 0;
	string path = "";
	solve(n, matrix, ans, srcx, srcy, path, visited); 

	// printing ans;
	for (auto e: ans){
		cout << e << endl;
	}

	return 0;
}

