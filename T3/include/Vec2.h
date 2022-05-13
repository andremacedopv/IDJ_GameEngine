#ifndef VEC2_H_
#define VEC2_H_

class Vec2 {
public:
    float x, y;
    Vec2();
    Vec2(float xi, float yi);

    Vec2 operator + (Vec2 const &obj);
    Vec2 operator - (Vec2 const &obj);
    Vec2 & operator = (const Vec2& t) {
        x = t.x;
        y = t.y;
        
        return *this;
    }
    Vec2 Multiply(float n);
    float Magnitude();
    Vec2 Normalize(Vec2 v);
    float Distance(Vec2 d);
    float Inclination();
    float Inclination(Vec2 v);
    Vec2 Rotate(float a);

};

#endif
