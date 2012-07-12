#pragma once

#include "cocos2d.h"

class VPoint
{
public:
    VPoint();
    virtual ~VPoint();

    void setPos(float ax, float ay);
    void update();
    void applyGravity(float dt);
    void applyGravity(float dt, float gx, float gy);
    void applyGravityxdt(float gxdt, float gydt);
   
    static void setGravityX(float gx, float gy);
    static cocos2d::CCPoint getGravity();

	float x,y,oldx,oldy;
};

