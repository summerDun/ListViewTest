#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	{
		auto& body = _skins[(int)SkinType::UPPER_BODY];
		body.push_back("Girl_UpperBody01");
		body.push_back("Girl_UpperBody02");

		auto& pants = _skins[(int)SkinType::PANTS];
		pants.push_back("Girl_LowerBody01");
		pants.push_back("Girl_LowerBody02");

		auto& shoes = _skins[(int)SkinType::SHOES];
		shoes.push_back("Girl_Shoes01");
		shoes.push_back("Girl_Shoes02");

		auto& hair = _skins[(int)SkinType::HAIR];
		hair.push_back("Girl_Hair01");
		hair.push_back("Girl_Hair02");

		auto& face = _skins[(int)SkinType::FACE];
		face.push_back("Girl_Face01");
		face.push_back("Girl_Face02");

		auto& hand = _skins[(int)SkinType::HAND];
		hand.push_back("Girl_Hand01");
		hand.push_back("Girl_Hand02");

		auto& glasses = _skins[(int)SkinType::GLASSES];
		glasses.push_back("");
		glasses.push_back("Girl_Glasses01");

		memset(_curSkin, 0, (int)SkinType::MAX_TYPE * sizeof(int));

	}

	Widget* panel = GUIReader::getInstance()->widgetFromBinaryFile("ListView_1.csb");
	this->addChild(panel, 2);

	ListView* listView = (ListView*)Helper::seekWidgetByName(panel, "Panel_4");

// 	ListView* listView = ListView::create();
// 	listView->setClippingEnabled(false);
// 	listView->setGravity(cocos2d::ui::ListView::Gravity::CENTER_HORIZONTAL);
// 	listView->setContentSize(panelBG->getContentSize());
// 	CCLOG("size.w = %f, size.h = %f", listView->getContentSize().width, listView->getContentSize().height);
	listView->setItemsMargin(5);
	Widget* itemList = GUIReader::getInstance()->widgetFromBinaryFile("Item.csb");
	//this->addChild(listView, 3);
	itemList->setAnchorPoint(Vec2(0.5,0.5));
	itemList->setScale(0.8);
	listView->setItemModel(itemList);
	for (int i = 1; i <= 5;i++)
	{
		Button* btn = (Button*)Helper::seekWidgetByName(itemList, "btn_Item");
		btn->setTag(i);
		btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::item,this));
		listView->pushBackDefaultItem();//这个得放在后面，因为放在前面的话已经把itemList给Pushback了，但是它的btn没有添加响应事件，所以会有一个按钮
	}
    return true;
}

void HelloWorld::item(Ref* sender, Widget::TouchEventType evt)
{
	int tag = ((Button*)sender)->getTag();
	CCLOG("tag = %d", tag);
	if (tag == 1)
	{
		for (int j = 0; j < (int)SkinType::MAX_TYPE; j++) {
			CCLOG("_skins[j].at(%d) = %d", j, _skins[j].at(_curSkin[j]));
// 			if (_skins[j].at(j) == NULL)
// 			{
// 				isVisible = true;
// 				break;
// 			}
		}
	}
	else if (tag == 2)
		CCLOG("22222222222");
	else if (tag == 3)
		CCLOG("33333");
	else if (tag == 4)
		CCLOG("44444444");
	else
		CCLOG("555555555");

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
