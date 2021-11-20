#include <cstdio>
#include <cmath>

#define MAX 987654321

using namespace std;

int main()
{
    double Ax, Ay, Az;
    double Bx, By, Bz;
    double Cx, Cy, Cz;
    double Mx, My, Mz;

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Az, &Bx, &By, &Bz, &Cx, &Cy, &Cz);

    double minimum = MAX;

    for (long i = MAX; i > 0; i--)
    {
        Mx = (Ax + Bx) / 2;
        My = (Ay + By) / 2;
        Mz = (Az + Bz) / 2;

        double dist = sqrt(pow(Cx - Mx, 2) + pow(Cy - My, 2) + pow(Cz - Mz, 2));

        if (minimum > dist)
        {
            minimum = dist;
        }
        else if (fabs(minimum - dist) <= 0.000001)
        {
            break;
        }

        double distFromA = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2) + pow(Az - Cz, 2));
        double distFromB = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2) + pow(Bz - Cz, 2));

        if (distFromA > distFromB)
        {
            Ax = Mx;
            Ay = My;
            Az = Mz;
        }
        else
        {
            Bx = Mx;
            By = My;
            Bz = Mz;
        }
    }

    printf("%f\n", minimum);

    return 0;
}