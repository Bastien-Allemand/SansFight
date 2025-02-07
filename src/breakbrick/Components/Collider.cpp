#include "Collider.h"
#include "Transform2d.h"
#include "SpriteRender.h"
#include "../Abstract/Behavior.h"
#include "../Abstract/iCollider.h"
#include <iostream>


bool Collider::CheckCollide(Collider* _collider){
    Transform2d* transform = Get<Transform2d>();
    SpriteRender* sprite = Get<SpriteRender>();

    if (!transform || !sprite || !sprite->GetSprite()){
        std::cout << "Erreur : Transform2d or SpriteRender = NULL" << std::endl;
        return false;
    }

    sf::FloatRect objBounds = sprite->GetSprite()->getGlobalBounds();
    objBounds = transform->getTransform().transformRect(objBounds);

    SpriteRender* otherSprite = _collider->Get<SpriteRender>();
    Transform2d* otherTransform2d = _collider->Get<Transform2d>();

    if (!otherTransform2d || !otherSprite || !otherSprite->GetSprite()){
        std::cout << "Erreur : Transform2d or SpriteRender = NULL" << std::endl;
        return false;
    }

    sf::FloatRect otherBounds = otherSprite->GetSprite()->getGlobalBounds();
    otherBounds = otherTransform2d->getTransform().transformRect(otherBounds);
    if (objBounds.intersects(otherBounds)){
        std::cout << "Collision Detected\n";
        return true;
    }
    else
        return false;

}

void Collider::CollisionEnter(Collider* _collider){
    Behavior* behavior = Get<Behavior>();
    if (behavior){
        iCollider* collideInterface = dynamic_cast<iCollider*>(behavior);
        if (collideInterface){
            std::cout << "OnCollide() Called for self\n";
            collideInterface->OnCollide(_collider);
        }
    }

    Behavior* otherBehavior = _collider->Get<Behavior>();
    if (otherBehavior){
        iCollider* otherCollideInterface = dynamic_cast<iCollider*>(otherBehavior);
        if (otherCollideInterface){
            std::cout << "OnCollide() Called for collided\n";
            otherCollideInterface->OnCollide(this);
        }
    }
}

void Collider::CollisionStay(Collider* _collider){}
void Collider::CollisionEnd(Collider* _collider){}
void Collider::Awake(){}
void Collider::Start(){}
