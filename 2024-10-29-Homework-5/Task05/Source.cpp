#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    size_t n, cash = 0;
    std::cin >> n;
    std::vector<size_t> costs(n);
    
    for (size_t i = 0; i < n; ++i) 
    {
        std::cin >> *(costs.begin() + i);
    }

    auto current_day = costs.begin();
    while (current_day != costs.end()) 
    {
        auto next_sale_day = max_element(current_day, costs.end());
        cash += *next_sale_day * (std::distance(current_day, next_sale_day) + 1);
        current_day = std::next(next_sale_day);
    }

    std::cout << cash << std::endl;
    return 0;
}
