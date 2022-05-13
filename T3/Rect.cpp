#include "./include/Rect.h"

Rect::Rect() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rect::Rect(float xi, float yi, float wi, float hi) {
    x = xi;
    y = yi;
    w = wi;
    h = hi;
}

Rect Rect::operator + (Rect const &obj) {
    Rect res;
    res.x = x + obj.x;
    res.y = y + obj.y;
    res.w = w + obj.w;
    res.h = h + obj.h;
    return res;
}

Rect Rect::operator - (Rect const &obj){
    Rect res;
    res.x = x - obj.x;
    res.y = y - obj.y;
    res.w = w - obj.w;
    res.h = h - obj.h;
    return res;
}

Rect Rect::AddVec(Vec2 v) {
    Rect res = *this;
    res.x = x + v.x;
    res.y = y + v.y;
    return res;
}

Vec2 Rect::Center() {
    Vec2 res;
    res.x = x + (w/2);
    res.y = y + (h/2);
    return res;
}
    
float Rect::Distance(Rect r) {
    Vec2 o = this->Center();
    Vec2 d = r.Center();

    return o.Distance(d);
}
    
bool Rect::Inside(float xi, float yi) {
    if ((xi > x) && (xi < x + w) && (yi > y) && (yi < y + h))
        return true;
    return false;
}

bool Rect::Inside(Vec2 v) {
    return this->Inside(v.x, v.y);
}