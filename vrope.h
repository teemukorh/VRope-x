#pragma once

#include "vpoint.h"
#include "vstick.h"
#include "cocos2d.h"
#include "Box2D.h"

#include <vector>

//PTM_RATIO defined here is for testing purposes, it should obviously be the same as your box2d world or, better yet, import a common header where PTM_RATIO is defined
#define PTM_RATIO 100

class VRope
{
public:
    VRope(b2Body* body1, b2Body* body2, cocos2d::CCSpriteBatchNode* ropeBatchNode);
    VRope(b2Joint* joint, cocos2d::CCSpriteBatchNode* ropeBatchNode);
    VRope(const cocos2d::CCPoint& pointA, const cocos2d::CCPoint& pointB, cocos2d::CCSpriteBatchNode* ropeBatchNode);
    virtual ~VRope();

    void update(float dt);
    void updateWithPreIntegratedGravity(float dt); // Flightless, update rope by pre-integrating the gravity each step (optimised for changing gravity)
    void updateWithPreIntegratedGravity(float dt, float gravityX, float gravityY); // Flightless, update rope by pre-integrating the gravity each step (optimised for changing gravity)
    void updateWithPreIntegratedOriginGravity(float dt); // Flightless, update rope by pre-integrating the gravity each step (optimised for changing gravity)
    void reset();
    
    void createRope(const cocos2d::CCPoint& pointA, const cocos2d::CCPoint& pointB);
    void resetWithPoints(const cocos2d::CCPoint &pointA, const cocos2d::CCPoint& pointB);
    void updateWithPoints(const cocos2d::CCPoint& pointA, const cocos2d::CCPoint& pointB, float dt);
    void updateWithPoints(const cocos2d::CCPoint& pointA, const cocos2d::CCPoint& pointB, float gxdt, float gydt); // Flightless, update with support for pre-integrating the gravity each step (optimised for changing gravity)
    void debugDraw();
    void updateSprites();
    void removeSprites();

	int numPoints;
	
    // todo : needs to be ordered (NSMutableArray)?
    std::vector<VPoint*> vPoints;
    std::vector<VStick*> vSticks;
	std::vector<cocos2d::CCSprite*> ropeSprites;
	
    cocos2d::CCSpriteBatchNode* spriteSheet;
	float antiSagHack;
	b2Body *bodyA;
	b2Body *bodyB;
    b2Joint *jointAB;
};

