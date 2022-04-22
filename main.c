#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
    //create n-by-C matrix M
    int** M = (int**) malloc((n+1) * sizeof(int*));
    for (int index=0; index<=n; ++index)
    {
        M[index] = (int*) malloc((C+1) * sizeof(int));
    }

    int i, c;

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
   {
       for (c = 0; c <= C; c++)
       {
           if (i==0 || c==0)
               M[i][c] = 0;
           else if (s[i] <= c)
                 M[i][c] = max(v[i] + M[i-1][c-s[i]], M[i-1][c]);
           else
                 M[i][c] = M[i-1][c];
       }
   }
   return M[n][C];
}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
