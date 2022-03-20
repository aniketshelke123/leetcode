# include <iostream>
# include <vector>

using namespace std;

int countRotation(vector <int> v){
    int start = 0;
    int end = v.size() - 1;
    //int mid = start + (end - start) / 2;
    int mid = (start + end) / 2;
    int ans = 0;
    while (start <= end){
        if (mid == 0){
            return ans;
        }
        if (v[mid] < v[mid - 1]){
            ans = mid;
            return ans;
        }
        if (v[mid + 1] < v[mid]){
            ans = mid + 1;
            return ans;
        }
        if (v[end] > v[mid]){
            
        }
        int mid = (start + end) / 2;
        cout << start << " " << end << " " << mid << endl;
    }
    return ans;
}

int main()
{
    vector <int> v {3,4, 5, 1, 2};
    cout << countRotation(v)<< endl;
    return 0;
}