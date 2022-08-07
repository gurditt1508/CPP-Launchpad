/*
	Given N cartesian points in a 2D plane, count the number of axis parallel rectangles that
	can be formed. 
	
	Example
	
	Input : {(0, 0), (0, 1), (1, 1), (1, 0), (2, 1), (2, 0), (3, 1), (3, 0)}
	Output: 6

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void printPoint() {
		cout << "(" << x << ", " << y << ")";
	}
};

class PointCompare {
	public :

		bool operator()(Point p1, Point p2) const {
			if(p1.x == p2.x) {
				return p1.y > p2.y;
			}
			return p1.x > p2.x;
		}

};

int main() {

	vector<Point> points{Point(1, 1), 
						 Point(1, 2), 
						 Point(2, 1),
						 Point(2, 2),
						 Point(3, 1),
						 Point(3, 2)};

	set<Point, PointCompare> plane(points.begin(), points.end());

	int count = 0;
	int n = points.size();

	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			Point p1 = points[i];
			Point p2 = points[j];
			if(p1.x != p2.x && p1.y != p2.y) {
				Point p3 = Point(p1.x, p2.y);
				Point p4 = Point(p2.x, p1.y);

				if(plane.find(p3) != plane.end() && 
				   plane.find(p4) != plane.end()) {
					count++;
				}
			}
		}
	}

	cout << "count : " << count/2 << endl;

	return 0;
}