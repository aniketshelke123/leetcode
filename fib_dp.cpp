# include <iostream>
# include <vector>

using namespace std;


void fib(long long n, long long f[]){
    f[0] = 0;
    f[1] = 1;

    for (long long i = 2 ; i <= n; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    
    // prints fib series upto n
    for (long long i = 0; i <= n; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    cout << "Fib at index n is: " << f[n];
}

int main()
{
    long long n;
    long long f[100];

    cin >> n;
    
    fib(n, f);

    return 0;
}
