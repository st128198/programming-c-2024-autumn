#include <iostream>
#include <vector>

int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++) 
    {
        std::cin >> *(numbers.data() + i);
    }

    int sum_positive = 0;
    int min_index = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++) 
    {
        if (*(numbers.data() + i) > 0) 
        {
            sum_positive += *(numbers.data() + i);
        }
        if (*(numbers.data() + i) < *(numbers.data() + min_index)) 
        {
            min_index = i;
        }
        if (*(numbers.data() + i) > *(numbers.data() + max_index)) 
        {
            max_index = i;
        }
    }

    if (min_index > max_index) 
    {
        std::swap(min_index, max_index);
    }

    long long product = 1;
    for (int i = min_index + 1; i < max_index; i++) 
    {
        product *= *(numbers.data() + i);
    }

    std::cout << sum_positive << " " << product << std::endl;

    return 0;
}
