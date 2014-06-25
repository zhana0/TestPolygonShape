//
//  Edge.cpp
//  TestPolygonShape
//
//  Created by zhana0 on 14-6-23.
//
//

#include "Edge.h"

bool Edge::init(){
    Node::init();
    
    Size size = Director::getInstance()->getVisibleSize();
    
    setPhysicsBody(PhysicsBody::createEdgeBox(size));
    
    return true;
}