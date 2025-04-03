#include <iostream> 
using namespace std;
typedef struct Point2D
{
	float x;
	float y;
};
int main()
{
	Point2D P[1];
	cout << "nhap diem thu nhat:";
	cin >> P[0].x >> P[0].y;
	cout << "diem P0 la:(" << P[0].x << "," << P[0].y << ")" << endl;
	cout << "nhap diem thu hai:";
	cin >> P[1].x >> P[1].y;
	cout << "diem P1 la:(" << P[1].x << "," << P[1].y << ")" << endl;
	return 0;
}
