#include <cstdio>
#include <algorithm>

#define MAX 500001

using namespace std;

int main()
{
    int N, M;
    int array1[MAX];
    int array2[MAX];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array1[i]);
    }

    sort(array1, array1 + N);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &array2[i]);
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d ", binary_search(array1, array1 + N, array2[i]));
    }

    return 0;
}