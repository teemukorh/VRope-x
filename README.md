VRope-x
=======

(Cocos2d-x)[http://www.cocos2d-x.com] /c++ port of simple rope system for [cocos2d](http://www.cocos2d-iphone.org) using [Verlet Integration](http://en.wikipedia.org/wiki/Verlet_integration).

The VRope-x was ported to Cocos2d-x (v2.0) by [Creeng Ltd.](http://www.creeng.com).

The port was made from [VRope 0.4](https://github.com/mb1/VRope) made by Flightless, which was a modified version of the original implementation. The Flightless
version added a MIT license, which is also contained in this ported version.

Usage
-----

### Create

    // Create joint
    b2RopeJoint* bodyAbodyBJoint = (b2RopeJoint*) world->CreateJoint(&jd); 

    // Create batchnode and vrope for joint (can also be made between two bodies)
    CCSpriteBatchNode* batch = dynamic_cast<CCSpriteBatchNode*> (getChildByTag(KTagRopeBatchNode));
    VRope* verlet = new VRope(bodyAbodyBJoint, batch); 


### Updating (called from update loop)
    
    // Update the verlets in the game loop
    verlet->update(dt);
    verlet->updateSprites();

See more usage examples from the original authors pages.