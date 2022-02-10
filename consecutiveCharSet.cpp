// program to find the set of same char in a string
// "babba" has 4 set = [b, a, bb, a]
// and their count is [1, 1, 2, 1]
// so the sumi is to make all numbers equal i.e [1+1, 1+1, 2, 1+1] = 3 is answer.
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void printVec(vector<int> const & ans){
	for (auto e: ans){
		cout << e << " ";
	}
	cout << endl;
}

void solution(string & S){
	int ans = 0;
	vector<int> vect;
	int n = S.size();

	for (int i = 0; i < n; i++){
		if (S[i] == S[i + 1]){
			ans++;
			continue;
		}
		else{
			ans++; 
			vect.push_back(ans);
			ans = 0;
		}
	}
	printVec(vect);

	// making all of numbber equal
	int maxi = *max_element(vect.begin(), vect.end());
	int sumi = 0;
	for (int i = 0; i < vect.size(); ++i){
		if (vect[i] < maxi){
			int diff = maxi - vect[i];
			sumi += diff;
		}
	}

	cout << sumi << endl;
}
int main()
{
	string S;
	cin >> S;
	solution(S);
	return 0;
}