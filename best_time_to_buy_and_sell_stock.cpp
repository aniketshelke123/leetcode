# include <iostream>
# include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
        
    int maxi = 0;
    int min = prices[0];
    
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] < min){
            min = prices[i];
        }
        else{
            if (prices[i] - min > maxi){
                maxi = prices[i] - min;
            }
        }
    }
    
    return maxi;
}

int main()
{
    vector <int> prices {7, 1, 2, 4, 5, 3, 6};
    cout << "The max profit is: " <<maxProfit(prices);
    return 0;
}