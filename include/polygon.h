#include <stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))


#define INF 1000



struct Point;

typedef struct Point
{
    int x;
    int y;
} Point;

bool onSegment(Point p, Point q, Point r);

int orientation(Point p, Point q, Point r);

bool doIntersect(Point p1, Point q1, Point p2, Point q2);

bool isInside(Point polygon[], int n, Point p);

int pnpoly(int n, Point polygon[], Point p);
