#include <iostream>
#include <stdio.h>
int main()

{
    
  int n=0, v=0, c=0;
    scanf("%d", &n);
    for(int i=0; i<n*n; i++)
    {
        scanf("%d", &v);
        if(v==1)
        {
            c++;
        }
    }
    printf("%d", c/2);

return EXIT_SUCCESS;

}
