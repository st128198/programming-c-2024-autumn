#include <iostream>
int main()

{
  
    int K=0, W=0, a1=0, b1=0, a2=0, b2=0, a3=0, b3=0;
    scanf("%d %d %d %d %d %d %d %d", K, W, a1, b1, a2, b2, a3, b3);
   
    if (b1 + b2 + b3 >= K)
    {
        if (b1 + b2 >= K && a1 + a2 <= W)
    {
            printf ("YES");
            exit(0);
    }
    else if (b1 + b3 >= K && a1 + a3 <= W)
    {
            printf ("YES");
            exit(0);
    }
    else if (b2 + b3 >= K && a2 + a3 <= W)
    {   
            printf("YES");
            exit(0);
    }
    else if (b1 + b2 + b3 >= K && a1 + a2 + a3 <= W)
    {   
            printf("YES");
            exit(0);
    }
    else if (b1 >= K && a1 <= W)
    {
        printf("YES");
        exit(0);
    }
    else if (b2 >= K && a2 <= W)
    {
        printf("YES");
        exit(0);
    }
    else if (b3 >= K && a3 <= W)
    {
        printf("YES");
        exit(0);
    }
        printf("NO");
        return EXIT_SUCCESS;
        }
  
}
