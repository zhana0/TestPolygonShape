#include "HelloWorldScene.h"
#include "ShapeCache.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Edge *edge = Edge::create();
    edge->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(edge);
    
    Sprite *flyman = Sprite::create("flyman.png");
    flyman->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(flyman);
    
    Sprite *football = Sprite::create("football.png");
    football->setPosition(visibleSize.width/2, visibleSize.height/2+200);
    addChild(football);
    
    ShapeCache::addShapeWithFileToSprite("flymanChipmunk.plist", flyman);
    ShapeCache::addShapeWithFileToSprite("football.plist", football);
    flyman->getPhysicsBody()->setDynamic(false);
    football->getPhysicsBody()->setDynamic(false);
    
    return true;
}







