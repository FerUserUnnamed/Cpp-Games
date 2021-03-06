#include "Bullet.h"

BulletBase::~BulletBase(){}

SimpleBullet::SimpleBullet()
{
	spr = new sf::Sprite(resourses.getTexturePtr(Textures::Bullet)[0]);

	spr->setScale(2.f, 2.f);
	spr->setOrigin(spr->getTextureRect().height / 2.f, spr->getTextureRect().width / 2.f);


	std::cout << "SimpleBullet created!" << std::endl;
}

SimpleBullet::~SimpleBullet()
{
	delete spr;
	std::cout << "SimpleBullet deleted" << std::endl;
}

SuperBullet::SuperBullet()
{
	spr = new sf::Sprite(resourses.getTexturePtr(Textures::Bullet)[0]);

	spr->setScale(3.f, 3.f);
	spr->setOrigin(spr->getTextureRect().height / 2.f, spr->getTextureRect().width / 2.f);


	//std::cout << "SuperBullet created!" << std::endl;
}

SuperBullet::~SuperBullet()
{
	delete spr;
	std::cout << "SuperBullet deleted" << std::endl;
}

void BulletBase::draw(sf::RenderWindow & window)
{
		window.draw(*spr);
}

void BulletBase::update(const sf::Vector2f vector)
{
	spr->move(vector);
}

void BulletBase::rotate(actions action)
{
	switch (action)
	{

	case Entity::Left:
			spr->setRotation(270.f);
		break;
	case Entity::Right:
			spr->setRotation(90.f);
		break;
	case Entity::Up:
			spr->setRotation(0.f);
		break;
	case Entity::Down:
			spr->setRotation(180.f);
		break;
	}

}

sf::FloatRect	BulletBase::getGlobalBounds()
{
	return spr->getGlobalBounds();
}

sf::FloatRect	BulletBase::getLocalBounds()
{
	return spr->getLocalBounds();
}

void BulletBase::setPosition(float x, float y)
{
	spr->setPosition(x, y);
}
