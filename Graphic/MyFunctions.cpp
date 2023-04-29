#include "MyFunctions.h"
#include <cmath>
double sinc(double x) {
	return x = 0 ? 1 : sin(x) / x;
}
double sqr(double x) {
	return x * x;
}
double F1(double x) {
	return x * abs(- 3 * x * x + 5 * x + 2) - 3;
}
double F2(double x) {
	return x * cos(abs(x * x - 3));
}
double F3(double x) {
	return abs(sin(x) * x) - 5;
}
double F4(double x) {
	return pow(sqrt(x * x), 5) + 5 * x;
}
double F5(double x) {
	return sqrt(x * x * abs(sin(x))) - 5;
}