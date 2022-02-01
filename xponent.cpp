# include <iostream>
# include <vector>
# include <algorithm>
//2 ^ 16 = 2^8+2^8 =>(2^8)^2 => (2^4+2^4) => (2^4)^2 => 2^2+2^2 => (2^2)^2 => 2^1+2^1 => (2^1)^2 => 2^0+2^0 => (2^0)^2.
// so instead of performing 16 iterations we just performed 5 iteration.
// more efficient and required less time.

// if power (b) is even = (a)^b/2 * (a)^b/2
// if power (b) is odd = a * ((a)^b/2 * (a)^b/2) 
using namespace std;

int power(int a, int b){
    // base case
    if (b == 0){
        return 0;
    }
     
    if (b == 1){
        return a;
    }
    // recurssion 
    int ans = power(a, b/2);
    //cout << ans << endl;

    if (b & 1){ //  a  is odd
        return a * ans * ans;
    }
    else{
        return ans * ans;
    }

}
int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    int ans = power(a, b);
    cout << ans << endl;
    return 0;
}