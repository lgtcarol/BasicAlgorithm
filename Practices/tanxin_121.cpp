#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1 )
        	return 0;
		int profits = 0; 
        for(int i = 0; i < prices.size()-1; i++)
        {
        	int gap = prices[i+1] - prices[i];
			if(gap > 0)
				profits += gap;
		}
		if(profits < 0)
			return 0;
		else
			return profits;
    }
};
int main(void)
{
	vector<int> arr = {1,2,3,4,5};
	Solution T;
	cout << T.maxProfit(arr)<< endl;
	return 0;	
} 



