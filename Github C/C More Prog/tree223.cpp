
#include <iostream>
using namespace std;

int main()
{
    for(int i=5; i>=1; i--)
    {
        for(int j=i; j<5; j++)
        {
            cout << " ";
        }
        for(int k=1; k<=i; k++)
        {
            cout << "1";
        }
        cout << endl;
    }
    return 0;
}
