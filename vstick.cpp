#include "vstick.h"

using namespace cocos2d;

VStick::VStick()
{
}

VStick::VStick(VPoint* argA, VPoint* argB)
    : pointA(argA), pointB(argB)
{
    hypotenuse = ccpDistance(ccp(pointA->x,pointA->y),ccp(pointB->x,pointB->y));
}

VStick::~VStick()
{
}

void VStick::contract()
{
    float dx = pointB->x - pointA->x;
	float dy = pointB->y - pointA->y;
	float h = ccpDistance(ccp(pointA->x,pointA->y),ccp(pointB->x,pointB->y));
	float diff = hypotenuse - h;
	float offx = (diff * dx / h) * 0.5;
	float offy = (diff * dy / h) * 0.5;
	pointA->x-=offx;
	pointA->y-=offy;
	pointB->x+=offx;
	pointB->y+=offy;

}

VPoint* VStick::getPointA()
{
    return pointA;
}

VPoint* VStick::getPointB()
{
    return pointB;
}
