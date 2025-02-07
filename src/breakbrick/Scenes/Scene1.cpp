#include "Scene1.h"
#include "Scene3.h"
#include "../Components/Transform2d.h"
#include "../Components/Collider.h"
#include "../Behavior/BallBehavior.h"
#include "../Behavior/BricksBehavior.h"
#include "../Behavior/PlayerBehavior.h"
#include "../Behavior/ScoreBehavior.h"
#include "../Components/SpriteRender.h"

Scene1::Scene1() : Scene(){}
Scene1::~Scene1(){}

void Scene1::Init(){
	Component* player = CreateEntity();
	player->Add<PlayerBehavior>();
	player->Get<Transform2d>()->setPosition(350, 550);

	Component* ball = CreateEntity();
	ball->Get<Transform2d>()->setPosition(700, 200);
	ball->Add<BallBehavior>();

	
	Component* leftWall = CreateEntity();
	leftWall->Add<Collider>();
	leftWall->Add<SpriteRender>();
	leftWall->Get<SpriteRender>()->SetTexture("../../../res/LRWall.png");
	leftWall->Get<SpriteRender>()->GetSprite()->setColor(sf::Color(0, 0, 0));
	leftWall->Get<Transform2d>()->setPosition(sf::Vector2f(0, 10));
	leftWall->Get<Transform2d>()->setScale(1, 600);

	Component* topWall = CreateEntity();
	topWall->Add<Collider>();
	topWall->Add<SpriteRender>();
	topWall->Get<SpriteRender>()->SetTexture("../../../res/UDWall.png");
	topWall->Get<SpriteRender>()->GetSprite()->setColor(sf::Color(0, 0, 0));
	topWall->Get<Transform2d>()->setPosition(sf::Vector2f(10, 0));
	topWall->Get<Transform2d>()->setScale(600, 1);

	Component* rightWall = CreateEntity();
	rightWall->Add<Collider>();
	rightWall->Add<SpriteRender>();
	rightWall->Get<SpriteRender>()->SetTexture("../../../res/LRWall.png");
	rightWall->Get<SpriteRender>()->GetSprite()->setColor(sf::Color(0, 0, 0));
	rightWall->Get<Transform2d>()->setPosition(sf::Vector2f(800, 10));
	rightWall->Get<Transform2d>()->setScale(1, 800);

	Component* score = CreateEntity();
	score->Add<ScoreBehavior>();
	score->Get<Transform2d>()->setPosition(sf::Vector2f(550, 550));

	CreateBricks();

}

void Scene1::CreateBricks(){
	sf::Texture* bricks_texture = new sf::Texture();
	bricks_texture->loadFromFile("../../../res/Bricks.png");
	int startX = 10;
	int startY = 10;
	int spacingX = 170; 
	int spacingY = 70;

	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 5; j++)		{
			Component* brick = CreateEntity();
			brick->Add<BricksBehavior>();
			brick->Get<SpriteRender>()->SetTexture(bricks_texture);
			brick->Get<Transform2d>()->setPosition(sf::Vector2f(startX + j * spacingX, startY + i * spacingY));
		}
	}
}


