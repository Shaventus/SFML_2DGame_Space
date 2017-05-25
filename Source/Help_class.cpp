#include "Help_class.h"

bool AABB(col_box &a,col_box &b)
{
    if(a.x > b.x && a.x < b.x + b.w && a.y > b.y && a.y < b.y + b.h) return true;
    else if(a.x < b.x + b.w && a.x + a.w > b.x + b.w && a.y > b.y && a.y < b.y + b.h) return true;
    else if(a.x > b.x && a.x < b.x + b.w && a.y < b.y + b.h && a.y + a.h > b.y + b.h) return true;
    else if(a.x < b.x + b.w && a.x + a.w > b.x + b.w && a.y < b.y + b.h && a.y + a.h > b.y + b.h) return true;
    else return false;

}

bool AABB(col_box &a,float x,float y,float size)
{
    if(a.x > x && a.x < x + size && a.y > y && a.y < y + size) return true;
    else if(a.x < x + size && a.x + a.w > x + size && a.y > y && a.y < y + size) return true;
    else if(a.x > x && a.x < x + size && a.y < y + size && a.y + a.h > y + size) return true;
    else if(a.x < x + size && a.x + a.w > x + size && a.y < y + size && a.y + a.h > y + size) return true;
    else return false;
}
