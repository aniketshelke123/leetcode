// This code doesn't work but logic is correct
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> & ans){
	// base case
	if(index >= nums.size()){
		ans.push_back(output);
		return;
	}

	// exclude 
	solve(nums, output, index + 1, ans);

	// include
	int element = nums[index];
	output.push_back(element);
	solve(nums, output, index + 1, ans);
}
		

vector<vector<int>> subset(vector<int> nums){
	vector<vector<int>> ans;
	vector<int> output;
	int index = 0;
	solve(nums, output, index, ans);

	// prints ans
	for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << "[" << ans[i][j] << "]" << " ";
        }   
    }
}

int main()
{

	// nums = [1, 2, 3]
	// output = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
	vector<int> nums = {1, 2, 3};

	for (auto e: nums){
		cout << e << " ";
	}
	subset(nums);
	
	return 0;
}
