#include <iostream>
#include <vector>
#include <cmath>
using std::vector;


int getMaxProfit(const vector<int>& stockPrices);
int main() {
    vector<int> stockPrices{10, 7, 5, 8, 11, 9};
    int price = getMaxProfit(stockPrices);
    std::cout << price << std::endl;
    return 0;
}

int getMaxProfit(const vector<int>& stockPrices)
{
    int maxProfit = 0;

    // go through every time
    for (size_t outerTime = 0; outerTime < stockPrices.size();
         ++outerTime) {

        // for every time, go through every other time
        for (size_t innerTime = 0; innerTime < stockPrices.size();
             ++innerTime) {

            // for each pair, find the earlier and later times
            size_t earlierTime = std::min(outerTime, innerTime);
            size_t laterTime   = std::max(outerTime, innerTime);

            // and use those to find the earlier and later prices
            int earlierPrice = stockPrices[earlierTime];
            int laterPrice   = stockPrices[laterTime];

            // see what our profit would be if we bought at the
            // min price and sold at the current price
            int potentialProfit = laterPrice - earlierPrice;

            // update maxProfit if we can do better
            maxProfit = std::max(maxProfit, potentialProfit);
        }
    }

    return maxProfit;
}
// returns 6 (buying for $5 and selling for $11)