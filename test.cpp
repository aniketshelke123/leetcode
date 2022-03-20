# include <iostream>
# include<cstring>
# include <vector>
# include <algorithm>
using namespace std;

int max_num(int a, int b){
	if (a > b){
		return a;
	}
	else{
		return b;
	}
}

int lcs(char *str1, char *str2){
	int i, j, len1, len2;
	// len1 = str1.size();
	len1 = strlen(str1);
	len2 = strlen(str2);
	// len2 = str2.size();
	int arr[len1 + 1][len2 + 1];
	for (int i = 0; i <= len1; ++i){
		arr[i][0] = 0;
	}
	for (int i = 0; i <= len2; ++i){
		arr[0][i] = 0;
	}
	for (int i = 1; i <= len1; ++i){
		for (int j = 1; j <= len2; ++j){
			if (str1[i - 1] == str2[j - 1]){
				arr[i][j] = 1 + arr[i - 1][j - 1];
			}
			else{
				arr[i][j] = max_num(arr[i - 1][j], arr[i][j -1]);
			}
		}
	}
	return arr[len1][len2];
}

int main(){
	char str1[] = "hbcfgmnapq";
	char str2[] = "cbhgrsfnmq";
	int ans = lcs(str1, str2);
	cout << ans << endl;
	return 0;
}
