#ifndef VECTOR_H
#define VECTOR_H

struct Vector3{
    double x, y, z;

    double getLenght() const;

    Vector3& operator+=(const Vector3 &v);
};

Vector3 crossProduct(const Vector3& a, const Vector3& b);

double dotProduct(const Vector3& a, const Vector3& b);

Vector3 operator*(double scalar, const Vector3& vector);

Vector3 operator+(const Vector3& a, const Vector3& b);

Vector3 operator-(const Vector3& a, const Vector3& b);

struct angle{
    double phi_x, phi_y;

    angle& operator+=(const angle &a);
};

angle operator+(const angle& a, const angle& b);

angle operator*(double scalar, const angle& vector);

#endif