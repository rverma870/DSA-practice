int maxProfit(vector<int>& prices)
 {
    int n = prices.size();
     if(n<=1)
         return 0;
     vector<int> noStock(n,0),inHand(n,0),Sold(n,0);

     noStock[0] = 0;
     inHand[0] = -prices[0];
     Sold[0] = 0;

     for(int i=1;i<n;++i)
     {
         noStock[i] = max(noStock[i-1],Sold[i-1]);
         inHand[i] = max(inHand[i-1],noStock[i-1]-prices[i]);
         Sold[i] = inHand[i-1]+prices[i];
     }
     int result = max(noStock[n-1],Sold[n-1]);
     return result;    }
