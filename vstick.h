#pragma once

#include "cocos2d.h"

#include "vpoint.h"

class VStick
{
public:
    VStick();
    VStick(VPoint* argA, VPoint* argB);
    virtual ~VStick();

    void contract();
    VPoint* getPointA();
    VPoint* getPointB();

	VPoint *pointA;
	VPoint *pointB;
	float hypotenuse;

};

