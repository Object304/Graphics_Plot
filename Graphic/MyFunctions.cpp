#include "MyFunctions.h"
#include <cmath>
double sinc(double x) {
	return x = 0 ? 1 : sin(x) / x;
}
double sqr(double x) {
	return x * x;
}
double F1(double x) {
	return sin(x * x) * cos(x);
}
double F2(double x) {
	return cos(5 * x * x * x + 3 * x * x + 2);
}
double F3(double x) {
	return abs(sin(x) * x);
}
double F4(double x) {
	return pow(sqrt(x * x), 5) + 5 * x;
}
double F5(double x) {
	return sin(x) * abs(x * x + 5 * x + 1);
}