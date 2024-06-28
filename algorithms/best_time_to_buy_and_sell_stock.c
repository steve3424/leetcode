int maxProfit(int* prices, int pricesSize) {
    // N^2
    // int max = 0;
    // for (int i = 0; i < pricesSize; ++i) {
    //     for (int j = i + 1; j < pricesSize; ++j) {
    //         if (max < prices[j] - prices[i]) {
    //             max = prices[j] - prices[i];
    //         }
    //     }
    // }
    // return 0 <= max ? max : 0;

    // N
    int max = 0;
    int left = 0;
    int right = 1;
    while (right < pricesSize) {
        int profit = prices[right] - prices[left];
        if (profit < 0) {
            left = right;
        } else if (max < profit) {
            max = profit;
        }
        right++;
    }
    return 0 <= max ? max : 0;
}
