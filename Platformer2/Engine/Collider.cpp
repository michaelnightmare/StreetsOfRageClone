#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider & other)
{
	sf::Vector2f otherposition = other.GetPosition();
	sf::Vector2f otherHalfsize = other.GetHalfSize();
	sf::Vector2f thisposition = GetPosition();
	sf::Vector2f thisHalfsize = GetHalfSize();

	float deltaX = otherposition.x - thisposition.x;
	float deltaY = otherposition.y - thisposition.y;

	float intersectX = abs(deltaX) - (otherHalfsize.x + thisHalfsize.x);
	float intersectY = abs(deltaY) - (otherHalfsize.y + thisHalfsize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}

	return false;
}

bool Collider::PushCollision(Collider & other, float push)
{
	sf::Vector2f otherposition = other.GetPosition();
	sf::Vector2f otherHalfsize = other.GetHalfSize();
	sf::Vector2f thisposition = GetPosition();
	sf::Vector2f thisHalfsize = GetHalfSize();

	float deltaX = otherposition.x - thisposition.x;
	float deltaY = otherposition.y - thisposition.y;

	float intersectX = abs(deltaX) - (otherHalfsize.x + thisHalfsize.x);
	float intersectY = abs(deltaY) - (otherHalfsize.y + thisHalfsize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f,intersectY * (1.0f - push));
				other.Move(0.0f ,-intersectY * push);
			}
			else
			{
				Move(0.0f , -intersectY * (1.0f - push));
				other.Move(0.0f,intersectY * push);
			}
		}
		return true;
	}
	return false; 
}