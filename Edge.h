//
//  Edge.h
//  TestPolygonShape
//
//  Created by zhana0 on 14-6-23.
//
//

#ifndef __TestPolygonShape__Edge__
#define __TestPolygonShape__Edge__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Edge :public Node {
    
public:
    virtual bool init();
    CREATE_FUNC(Edge);
};

#endif /* defined(__TestPolygonShape__Edge__) */
