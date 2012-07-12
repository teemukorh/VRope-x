#include "vpoint.h"

static float vPointGravityX = 0.0f;
static float vPointGravityY = 9.8f;

using namespace cocos2d;

VPoint::VPoint()
{
}


VPoint::~VPoint()
{
}

void VPoint::setPos(float ax, float ay)
{
	x = oldx = ax;
	y = oldy = ay;
}

void VPoint::update()
{
	float tempx = x;
	float tempy = y;
	x += x - oldx;
	y += y - oldy;
	oldx = tempx;
	oldy = tempy;
}

void VPoint::applyGravity(float dt)
{
	x -= vPointGravityX*dt;
	y -= vPointGravityY*dt;
}

void VPoint::applyGravity(float dt, float gx, float gy)
{
	x -= gx*dt;
	y -= gy*dt;
}

void VPoint::applyGravityxdt(float gxdt, float gydt)
{
    x -= gxdt;
    y -= gydt;
}

void VPoint::setGravityX(float gx, float gy)
{
	vPointGravityX = gx;
	vPointGravityY = gy;        
}

CCPoint VPoint::getGravity()
{
    return CCPointMake(vPointGravityX, vPointGravityY);
}

