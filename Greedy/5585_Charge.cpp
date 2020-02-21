#include <iostream>
#define PAID 1000

using namespace std;

int main()
{
    int price{0};
    cin >> price;
    
    int exchange{PAID - price};
    int coinCNT{0};
    
    while(exchange)
    {
        if(500 <= exchange)
        {
            exchange -= 500;
        }
        else if(100 <= exchange)
        {
            exchange -= 100;
        }
        else if(50 <= exchange)
        {
            exchange -= 50;
        }
        else if(10 <= exchange)
        {
            exchange -= 10;
        }
        else if(5 <= exchange)
        {
            exchange -= 5;
        }
        else if(1 <= exchange)
        {
            exchange -= 1;
        }
        
        coinCNT++;
    }
    
    cout << coinCNT << endl;
    
    return 0;
}