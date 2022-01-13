#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][3];
    for (int j = 0; j<n; j++)
        scanf("%d%d%d", &a[j][0], &a[j][1], &a[j][2]);
    for (int j = 0; j<n; j++)
    {
        for (int k = j + 1; k<n; k++)
        {
            if (a[j][0] == a[k][0])
            {
                if (a[j][1] > a[k][1])
                {
                    int h = a[j][0], m = a[j][1], s = a[j][2];
                    a[j][0] = a[k][0];
                    a[j][1] = a[k][1];
                    a[j][2] = a[k][2];
                    a[k][0] = h;
                    a[k][1] = m;
                    a[k][2] = s;
                }
                else if(a[j][1] == a[k][1])
                {
                    if (a[j][2] > a[k][2])
                    {
                        int h = a[j][0], m = a[j][1], s = a[j][2];
                        a[j][0] = a[k][0];
                        a[j][1] = a[k][1];
                        a[j][2] = a[k][2];
                        a[k][0] = h;
                        a[k][1] = m;
                        a[k][2] = s;
                    }
                }
            }
            else if(a[j][0] > a[k][0])
            {
                int h = a[j][0], m = a[j][1], s = a[j][2];
                a[j][0] = a[k][0];
                a[j][1] = a[k][1];
                a[j][2] = a[k][2];
                a[k][0] = h;
                a[k][1] = m;
                a[k][2] = s;
            }
        }
    }
    for (int i = 0; i<n; i++)
    {
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
    }
}
