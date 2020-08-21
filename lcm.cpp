#include <iostream>
using namespace std;

int main()
{
    long n1, n2, hcf, temp, lcm;


    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;
    
    while(hcf != temp)
    {
        if(hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    lcm = (n1 * n2) / hcf;

    cout <<lcm;
    return 0;
}
