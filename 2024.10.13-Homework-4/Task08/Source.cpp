#include <stdio.h>
#include <vector>

int main() 

{
    
  int n=0, m=0, i=0, j=0;
  scanf("%d", &n);
  
  vector<int> a(n);
    
  for(int i = 0; i < a.size(); ++i)
        scanf("%d", &a[i]);
        scanf("%d", &m);

    for(int h = 0; h < m; ++h) 
    {
        scanf("%d %d", &i, &j);
        for(int f = i - 1; f < j; ++f)
        printf("%d ", a[f]);
        printf("\n");
    }

    return EXIT_SUCCESS;
  
}
