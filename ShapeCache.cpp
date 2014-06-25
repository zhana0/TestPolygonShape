//
//  ShapeCache.cpp
//  TestPolygonShape
//
//  Created by zhana0 on 14-6-24.
//
//

#include "ShapeCache.h"

void ShapeCache::addShapeWithFileToSprite(std::string plist, cocos2d::Sprite *s){
    FileUtils *fu = FileUtils::getInstance();
    ValueMap root = fu->getValueMapFromFile(plist);
    
    auto bodies = root["bodies"].asValueMap();
    ValueMap fixtureDef;
    for (auto iter=bodies.begin(); iter!=bodies.end(); iter++) {
        fixtureDef = iter->second.asValueMap();
    }
    
    ValueMap item = fixtureDef["fixtures"].asValueVector()[0].asValueMap();
    s->setPhysicsBody(PhysicsBody::create());
    for (auto iter=item.begin(); iter!=item.end(); iter++) {
        std::string key = iter->first;
        auto type = iter->second;
        if (key == "polygons") {
            auto value = type.asValueVector();
            for (int i=0; i<value.size(); i++) {
                auto _item = value[i].asValueVector();
                Vec2 *vec = new Vec2[_item.size()];
                for (int j=0; j<_item.size(); j++) {
                    Point p = PointFromString(_item[j].asString().c_str());
                    vec[j] = Vec2(p.x, p.y);
                }
                s->getPhysicsBody()->addShape(PhysicsShapePolygon::create(vec, _item.size()));
            }
        }else if (key == "mass"){
            s->getPhysicsBody()->setMass(type.asInt());
        }else if (key == "friction"){
            auto shapes = s->getPhysicsBody()->getShapes();
            for (int i=0; i<shapes.size(); i++) {
                shapes.at(i)->setFriction(type.asInt());
            }
        }
        
    }
    
}
