/*
Code by OmgRod
Thanks to iArtie on GitHub for the profile page modify code.
*/

#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/utils/web.hpp>
#include <chrono>
#include <thread>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
	static void onModify(auto& self) {
        self.setHookPriority("GJGarageLayer::init", -10000);
    }

	int accID;

	bool init(int a1, bool a2) {
		if(!ProfilePage::init(a1, a2)) return false;

		accID = a1;

		return true;
	}

	void loadPageFromUserInfo(GJUserScore* asas)
	{

		ProfilePage::loadPageFromUserInfo(asas);

		auto nodelolas = (CCLayer*)this->getChildren()->objectAtIndex(0);

		auto winSize = CCDirector::sharedDirector()->getWinSize();

		auto username = nodelolas->getChildByID("username-label");

		// Fetch creator points asynchronously with improved error handling
                web::AsyncWebRequest()
                    .bodyRaw(fmt::format("secret=Wmfd2893gb7&targetAccountID={}", accID))
                    .userAgent("")
                    .method("POST")
                    .fetch("https://ksr.ps.fhgdps.com/getGJUserInfo20.php") // Modify this code for your own GDPS (if you want)
                    .text()
                    .then([=](std::string const& response) {
                        // Extract the badge value from the response
						std::string badgeValue;
						std::istringstream iss(response);
						std::string token;
						while (std::getline(iss, token, ':')) {
							if (token == "49") {
								// Extract the next token as the badge value
								if (std::getline(iss, badgeValue, ':')) {
									break;
								}
							}
						}

						// Convert the badge value to an integer
						int badgeIntValue;
						try {
							badgeIntValue = std::stoi(badgeValue);
						} catch (const std::invalid_argument& e) {
							// Handle the case where badge value is not a valid integer
							std::cerr << "Error: Invalid badge value: " << badgeValue << std::endl;
							return; // or handle the error appropriately
						}

						std::cout << "Extracted badge string: " << badgeIntValue << std::endl;

						try {
							// Depending on the value of creatorPoints, create the appropriate modBadge
							if (badgeIntValue == 100) {
								auto modBadge = CCSprite::create("modBadge_01_002.png"_spr);
								// modBadge->setPositionY(username->getPositionY());
								// modBadge->setPositionX(username->getPositionX() - (username->getContentWidth() / 2));

								modBadge->setPosition(nodelolas->getChildByID("mod-badge")->getPosition());

								nodelolas->removeChildByID("mod-badge");

								nodelolas->addChild(modBadge);

								nodelolas->updateLayout();

								std::cout << "Loaded mod badge -1" << std::endl;
							} else if (badgeIntValue == 101) {
								auto modBadge = CCSprite::create("modBadge_02_002.png"_spr);
								// modBadge->setPositionY(username->getPositionY());
								// modBadge->setPositionX(username->getPositionX() - (username->getContentWidth() / 2));

								modBadge->setPosition(nodelolas->getChildByID("mod-badge")->getPosition());

								nodelolas->removeChildByID("mod-badge");

								nodelolas->addChild(modBadge);

								nodelolas->updateLayout();

								std::cout << "Loaded mod badge -2" << std::endl;
							} else if (badgeIntValue == 102) {
								auto modBadge = CCSprite::create("modBadge_03_002.png"_spr);
								// modBadge->setPositionY(username->getPositionY());
								// modBadge->setPositionX(username->getPositionX() - (username->getContentWidth() / 2));

								modBadge->setPosition(nodelolas->getChildByID("mod-badge")->getPosition());

								nodelolas->removeChildByID("mod-badge");

								nodelolas->addChild(modBadge);

								nodelolas->updateLayout();

								std::cout << "Loaded mod badge -3" << std::endl;
							} else {
								// Handle other cases or log a warning if needed
							}
						} catch (const std::invalid_argument& e) {
							// Handle the case where badgeStr is not a valid integer
							// Log an error message or handle it appropriately
							std::cerr << "Error: Invalid creator points string: " << badgeIntValue << std::endl;
						}
                    })
                    .expect([](std::string const& error) {
                        std::cerr << "Failed to fetch creator points: " << error << std::endl;
                    });
	}
};
