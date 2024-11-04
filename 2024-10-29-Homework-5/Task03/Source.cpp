#include <iostream>
#include <vector>

int main() 
{
    int n=0;
    std::cin >> n;
    std::vector<int> threes;
    std::vector<int> fours;
    
    for (int i = 0; i < n; i++) 
    {
        int day;
        std::cin >> day;
        if (day % 2 == 0) 
        {
            fours.push_back(day);
        } else 
        {
            threes.push_back(day);
        }
    }

    for (int day : threes) 
    {
        std::cout << day << ' ';
    }
    std::cout << std::endl;

    for (int day : fours) 
    {
        std::cout << day << ' ';
    }
    std::cout << std::endl;

    if (fours.size() >= threes.size()) 
    {
        std::cout << "YES" << std::endl;
    } else 
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

