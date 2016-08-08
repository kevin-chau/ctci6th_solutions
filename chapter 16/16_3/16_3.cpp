// Compute points of intersection of two lines, each given by a pair of points
#include <iostream>
using namespace std;

class point {
public:
	float x;
	float y;
	point(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void set(float x, float y){
		this->x = x;
		this->y = y;
	}
	void printPoint(){
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class line {
public:
	float slope;
	float yint;

	line (point * start, point * end) {
		float dy = end->y - start->y;
		float dx = end->x - start->x;
		slope = dy/dx;
		yint = end->y - slope*end->x;
	}
};

void swap (point * one, point * two){
	float x = one->x;
	float y = one->y;
	one->set(two->x, two->y);
	two->set(x,y);
}

bool isBetween(float start, float middle, float end) {
	if (start > end) {
		return end <= middle && middle <= start;
	} else {
		return start <= middle && middle <= end;
	}
}

bool isBetween(point * start, point * middle, point * end){
	return isBetween(start->x, middle->x, end->x) &&
		   isBetween(start->y, middle->y, end->y);
}

point * calculateIntersection(point * start1, point * end1, point * start2, point * end2) {
	// rearrage for point1 to be before point2 in order of x, and start is before end
	if(start1->x > end1->x) { swap(start1,end1); }
	if(start2->x > end2->x){ swap(start2,end2);}
	if(start1->x > start2->x){
		swap(start1, start2);
		swap(end1, end2);
	}

	line * line1 = new line(start1, end1);
	line * line2 = new line(start2, end2);

	if (line1->slope == line2->slope){
		if (line1->yint == line2->yint && isBetween(start1,start2,end1)){
			return start2;
		}
	}

	float x = (line2->yint - line1->yint) / (line1->slope - line2->slope);
	float y = x * line1->slope + line1->yint;
	point * intersection = new point(x,y);

	if (isBetween(start1, intersection, end1) && isBetween(start2, intersection, end2)){
		return intersection;
	}

	return nullptr;
}

int main () {

	point * P1 = new point (0.0f, 0.0f);
	point * P2 = new point (2.0f, 2.0f);

	point * P3 = new point (0.0f, 2.0f);
	point * P4 = new point (2.0f, 0.0f);

	point * intersection = calculateIntersection(P1,P2,P3,P4);
	if (intersection != nullptr){
		intersection->printPoint();
	}

}