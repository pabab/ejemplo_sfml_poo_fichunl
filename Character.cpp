#include "Character.h"
#include <SFML/Window/Keyboard.hpp>

Character::Character(const sf::Vector2f &pos){
	texChar.loadFromFile("assets/images/char.png");
	spChar.setTexture(texChar);
	spChar.setPosition(pos);
}

void Character::update(){
	// mover al personaje
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		spChar.move(-CHAR_VEL, 0);
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		spChar.move(CHAR_VEL, 0);
	}
	
	// limitar el movimiento del personaje a la ventana
	sf::Vector2f charPos = spChar.getPosition();
	if(charPos.x < 0) charPos.x = 0;
	if(charPos.x > 608) charPos.x = 608;
	spChar.setPosition(charPos);
}

void Character::draw(sf::RenderWindow &w){
	w.draw(spChar);
}

sf::Sprite &Character::getSprite(){
	return spChar;
}

bool Character::collidesWithBall(Ball *b){
	sf::FloatRect charRect = getSprite().getGlobalBounds();
	sf::FloatRect ballRect = b->getSprite().getGlobalBounds();
	return charRect.intersects(ballRect);
}
