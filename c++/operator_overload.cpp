#include <iostream>

class Vector2d {
	double x, y;
public:
	Vector2d(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	double& operator[](int i);
	const double& operator[](int i)const;
	Vector2d& operator= (Vector2d &v);
};
double& Vector2d::operator[](int i) {
	if (i == 0) return x;
	else if (i == 1) return y;
	else throw "out of range";
}
const double& Vector2d::operator[](int i) const {
	if (i == 0) return x;
	else if (i == 1) return y;
	else throw "out of range";
}
Vector2d& Vector2d::operator= (Vector2d &v){
	x = v.x+10; y = v.y;
	return *this;
}

int main() {
	Vector2d u, v(2.5, 3.7);
	std::cout << u[0] << "," << u[1] << "\n";
	u = v; //operator=
	std::cout << u[0] << "," << u[1] << "\n";
	return 0;
}