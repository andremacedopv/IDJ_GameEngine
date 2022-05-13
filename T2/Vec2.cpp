#include "./include/Vec2.h"
#include <math.h>

Vec2::Vec2() {
    x = 0;
    y = 0;
}

Vec2::Vec2(float xi, float yi) {
    x = xi;
    y = yi;
}

Vec2 Vec2::operator + (const Vec2 &obj) {
    Vec2 res;
    res.x = x + obj.x;
    res.y = y + obj.y;
    return res;
}

Vec2 Vec2::operator - (const Vec2 &obj) {
    Vec2 res;
    res.x = x - obj.x;
    res.y = y - obj.y;
    return res;
}

Vec2 Vec2::Multiply(float n) {
    Vec2 res;
    res.x = x * n;
    res.y = y * n;
    return res;
}

float Vec2::Magnitude() {
    return sqrt((x * x) + (y * y));
}

Vec2 Vec2::Normalize(Vec2 v) {
    Vec2 res;
    float a = v.Magnitude();
    res.x = v.x/a;
    res.y = v.y/a;
    return res;
}

float Vec2::Distance(Vec2 d) {
    float newx = x - d.x;
    float newy = y - d.y; 
    return sqrt((newx * newx) + (newy * newy));
}

float Vec2::Inclination() {
    return atan2(y, x);
}

float Vec2::Inclination(Vec2 v) {
    Vec2 res;
    res = v - *this;
    return res.Inclination();
}

Vec2 Vec2::Rotate(float a) {
    Vec2 res;
    res.x = x * std::cos(a) - y * std::sin(a);
    res.y = y * std::cos(a) + x * std::sin(a);
    return res;
}
