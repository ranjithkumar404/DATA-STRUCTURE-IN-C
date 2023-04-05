#include <stdio.h>
#include <string.h>
int a[100][100], v[50][50], n, count = 0, n;
void findpath(int m[50][50], int r, int c, int n)
{
    if (r == n - 1 && c == n - 1)
    {
        v[r][c] = 1;
        count++;
        printf("Solution %d \n ", count);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d /t", v[i][j]);
            }
            printf("\n");
        }
        v[r][c] = 0;
    }
    else
        v[r][c] = 1;

    if (r + 1 < n && v[r + 1][c] == 0 && m[r + 1][c] == 1)
        findpath(m, r + 1, c, n);
    if (c + 1 < n && v[r][c + 1] == 0 && m[r][c + 1] == 1)
        findpath(m, r, c + 1, n);
    if (r - 1 >= 0 && v[r - 1][c] == 0 && m[r - 1][c] == 1)
        findpath(m, r - 1, c, n);
    if (c - 1 >= 0 && v[r][c - 1] == 0 && m[r][c - 1] == 1)
        findpath(m, r, c - 1, n);
    v[r][c] = 0;
}
int main()
{
    int r, c;
    printf("Enter the size of the maze \n");
    scanf("%d", &n);
    printf("Enter the maze in the form of 1's and 0's (1->open & 0->close)");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }
    printf("Enter the entry point (i.e row value and column value) ");
    scanf("%d %d", &r, &c);
    if (n == 0 && count == 0)
        printf("no path found!!!");
    else
        findpath(a, r, c, n);
    return 0;
}
