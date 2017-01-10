#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
	Top = body.getPosition().y;
	Bottom = body.getPosition().y + body.getSize().y;
	Right = body.getPosition().x + body.getSize().x;
	Left = body.getPosition().x;
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider & other)
{
	// What I thought would be a better collision (typical Rect to Rect behavior)
	// Have the Body in GameObjects constructer filling to Red,
	// Rect size seems to match up, but strange behavior is still happening...
	// For instance, made a cout in the player's collidedwith function... almost always colliding with platform
	// Aside from when you move to far left of the screen, the top half seems to behave as it should.... MUST FIX

	if ((Left < other.Left + other.Right) &&
		(Left + Right > other.Left) &&
		(Top < other.Top + other.Bottom) &&
		(Top + Bottom > other.Top))
		{
			return true;
		}
	
	return false;

	//Pushing this as is, if we need to swap back to the old method all the code is intact in Push Collision Function
	// V V V V V V V V V V (take everything aside from the push behavior)
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