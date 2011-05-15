#include <iostream>
using namespace std;
 
int coins[8] = {200, 100, 50, 20, 10, 5,2,1};
 
int findposs(int money, int maxcoin)
{
    int sum = 0;
    // if(maxcoin == 8) return 0;
    for(int i = maxcoin; i<8;i++)
    {
        if (money-coins[i] == 0) sum+=1;
        if (money-coins[i] > 0) sum+=findposs(money-coins[i], i);
    }
    return sum;     
}
 
int main()
{
    cout<<findposs(200, 0)<<endl;
}
