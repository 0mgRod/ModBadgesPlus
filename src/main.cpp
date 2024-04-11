/*
Code by OmgRod
Thanks to iArtie on GitHub for the profile page modify code.
*/

#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
	bool init(int a1, bool a2) {
		if(!ProfilePage::init(a1, a2)) return false;

		auto nodelolas = (CCLayer*)this->getChildren()->objectAtIndex(0);

		nodelolas->removeChildByID("stats-menu");

		// auto myButton = CCMenuItemSpriteExtra::create(
		// 	CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
		// 	this,
		// 	menu_selector(MyMenuLayer::onMyButton)
		// );

		// auto menu = this->getChildByID("bottom-menu");
		// menu->addChild(myButton);

		// myButton->setID("my-button"_spr);

		// menu->updateLayout();

		return true;
	}
};
