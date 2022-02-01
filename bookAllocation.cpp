 # include <iostream>
 # include <vector>
 # include <algorithm>

using namespace std;
int ifPossible(vector <int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; ++i){
        if (pagesum + arr[i] <= mid){
            pagesum += arr[i];
        }
        else{
            studentCount++;
            if (studentCount > m || arr[i] > mid){
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        sum += arr[i];
    }
    int end = sum;

    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end){

        if (ifPossible(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    int NoofBooks = 4, NoofStudents = 2;
    vector <int> v {10, 20, 30, 40};
    cout << allocateBooks(v, NoofBooks, NoofStudents);


    return 0;
}