#ifndef RECT_H_
#define RECT_H_

#include "Vec2.h"

class Rect {
public:
    float x, y, w, h;
    Rect();
    Rect(float xi, float yi, float wi, float hi);

    Rect operator + (Rect const &obj);
    Rect operator - (Rect const &obj);
    Rect & operator = (const Rect& t) {
        x = t.x;
        y = t.y;
        w = t.w;
        h = t.h;
        
        return *this;
    }
    Rect AddVec(Vec2 v);
    Vec2 Center();
    float Distance(Rect r);
    bool Inside(float xi, float yi);
    bool Inside(Vec2 v);
};

#endif
