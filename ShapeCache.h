//
//  ShapeCache.h
//  TestPolygonShape
//
//  Created by zhana0 on 14-6-24.
//
//

#ifndef __TestPolygonShape__ShapeCache__
#define __TestPolygonShape__ShapeCache__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class CC_DLL ShapeCache : Ref{
private:
    
public:
    static void addShapeWithFileToSprite(std::string plist, Sprite *s);
};

#endif /* defined(__TestPolygonShape__ShapeCache__) */
