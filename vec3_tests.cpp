#include <iostream>

#include "vec3.h"


using namespace std;


int main(int argc, char *argv[]) {
	vec3 v1(-1.0, -1.0, -1.0);
	vec3 v2(2.0, 2.0, 2.0);
	vec3 uvv(-15, 12, 9);
	vec3 a(1,2,3);
	vec3 b(4,5,6);
	
	vec3 result;
	rtnum m = 2.0;
	
	cout << "Negation" << endl;
	cout << "Vector: " << v1 << ", negated: " << (- v1)  << ", again: " << (-(- v1)) << endl;
	vec3 v4(-2.0, 1.0, 0);
	
	cout << "Vector: " << v4 << ", negated: " << (- v4)  << ", again: " << (-(- v4)) << endl;
	
	cout << endl << "Conversion to unit vec" << endl;
	// http://www.wolframalpha.com/input/?i=unit+vector(-15,+12,+9)
	cout << "Vector: " << uvv << ", unit vec: ";
	uvv.make_unit_vector();
	cout << uvv << endl;


	cout << endl << "Math ops, a(1,2,3)   b(4,5,6)" << endl;

	cout << "a + b: " << (a + b) << endl;
	cout << "a - b: " << (a - b) << endl;
	cout << "a * b: " << (a * b) << endl;
	cout << "a / b: " << (a / b) << endl;


	cout << endl << "Vector ops, a(1,2,3)   b(4,5,6)" << endl;
	// http://www.wolframalpha.com/input/?i=(1,+2,+3)+cross+(4,+5,+6)
	vec3 crossRes = cross(a, b);
	
	//http://www.wolframalpha.com/input/?i=(1,+2,+3)+dot+product+(4,+5,+6)
	rtnum dotRes = dot(a, b);
	cout << "a X b: " << crossRes << endl;
	cout << "a . b: " << dotRes << endl;

	
}
