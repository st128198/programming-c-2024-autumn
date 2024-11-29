#include <iostream>
#include <cmath>

int main() 

{
    
    int h = 0;
    int a = 0;
    int b = 0;
    std::cin >> h >> a >> b;

    if (a >= h) 
        {
        std::cout << 1 << std::endl;
        } 
    
    else 
        {
        int c = a - b;
        int d = std::ceil(double(h - a) / c) + 1;//std::ceil это округление числа вверх до ближайшего целого
        std::cout << d<< std::endl;
        }

    return 0;

}
