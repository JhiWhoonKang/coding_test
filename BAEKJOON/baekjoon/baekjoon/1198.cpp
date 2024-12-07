#include<iostream>;
#include<vector>;
#include<cmath>

using namespace std;

struct Point
{
	int x, y;
};

double three_points_area(Point& a, Point& b, Point& c)
{
	return abs(((a.x * b.y) + (b.x * c.y) + (c.x * a.y) - (b.x * a.y) - (c.x * b.y) - (a.x - c.y))) / 2.0;
}



int main(void)
{
	int N;
	cin >> N;
	vector<Point>coordinates(N);


	for (int i = 0; i < N; i++)
	{
		cin >> coordinates[i].x >> coordinates[i].y;
	}
	
	vector<double>areas(N, 0.0);

	for (int i = 0; i < N; i++)
	{
		areas[i] = three_points_area(coordinates[i], coordinates[i + 1], coordinates[i + 2]);
	}

	for (int i = 0; i < N; i++)
	{

	}


	return 0;
}