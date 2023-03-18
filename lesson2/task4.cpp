
#include <iostream>
#include <cstdlib>
#include <cmath>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1) * (y2 - y1));
}

double triangle_square(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double da = distance(xa, ya, xb, yb), db = distance(xa, ya, xc, yc), dc = distance(xb, yb, xc, yc);
    double p = (da + db + dc) / 2;

    return sqrt(p * (p - da) * (p - db) * (p - dc));
}

int main()
{
    char letters[3]{'A', 'B', 'C'};

    double coords[6];

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Input coordinates of point " << letters[i] << std::endl;
        std::cin >> coords[2 * i] >> coords[2 * i + 1];
        std::cout << std::endl;
    }

    std::cout << "Square is " << triangle_square(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5]);
}