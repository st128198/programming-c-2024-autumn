#include <iostream>
#include <cmath>

using namespace std;

int main()

{
    
    double a, b, c;
    double x1, x2, d;
    cin >> a >> b >> c;
    if (!a && !b && !c) 
    {
        cout << -1;
        return 0;
    }

    if (a) 
    {
        d = b * b - 4.0 * a * c;
        if (d > 0) 
        {
            cout << 2 << endl;
            x1 = (-b - sqrt(d)) / (2 * a);
            x2 = (-b + sqrt(d)) / (2 * a);
            if (x1)
                cout << x1;
            else
                cout << 0;
            cout << endl;
            if (x2)
                cout << x2;
            else
                cout << 0;
        } 
        else if (!d) 
        {
            cout << 1 << endl;
            x1 = -b / (2 * a);
            if (x1)
                cout << x1;
            else
                cout << 0;
        } 
        else if (d < 0) 
        {
            cout << 0;
        }
    } 
    else if (b) 
    {
        cout << 1 << endl;
        if (c)
            x1 = -c / b;
        else
            x1 = 0;
        cout << x1;
    } 
    else if (c) 
    {
        cout << 0;
    }

    return EXIT_SUCCESS;
    
}
