#include "vector.h"
#include <cmath>

double Vector3::getLenght() const{
	return std::sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3& Vector3::operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 crossProduct(const Vector3& a, const Vector3& b){
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

double dotProduct(const Vector3 &a, const Vector3 &b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 operator*(double scalar, const Vector3& vector){
	return {
		scalar * vector.x,
		scalar * vector.y,
		scalar * vector.z
	};
}

Vector3 operator+(const Vector3& a, const Vector3& b){
	return {
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	};
}

Vector3 operator-(const Vector3& a, const Vector3& b){
	return {
		a.x - b.x,
		a.y - b.y,
		a.z - b.z 
	};
}

angle operator+(const angle& a, const angle& b){
	return {
		a.phi_x + b.phi_x,
		a.phi_y + b.phi_y
	};
}

angle operator*(double scalar, const angle& _angle){
	return {
		_angle.phi_x * scalar,
		_angle.phi_y * scalar
	};
}

angle& angle::operator+=(const angle &a){
	phi_x += a.phi_x;
	phi_y += a.phi_y;

	return *this;
}