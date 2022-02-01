# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

char get_max_occ_char(string s){
    int arr[26] = {0};
    // create an array of count of chars
    for (int i = 0; i < s.length(); ++i){
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        //cout << number << endl;
        arr[number]++;
    }
    /*
    for (int j = 0; j < 26; ++j){
        cout << arr[j] << " ";
    }
    cout << endl;
    */

    // getting the max occ char lexographically from arr[]
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; ++i){
        if (maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    return 'a' + ans;
}
    
int main()
{
    string s;
    cin >> s;
    cout << get_max_occ_char(s);
}