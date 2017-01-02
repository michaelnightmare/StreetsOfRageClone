//	Constrain to not go through platform
//	if (Thomas.getPosition().x + Thomas.getSize().x > platform.getPosition().x )
//	{
//		Thomas.setFillColor(sf::Color::Blue);
//	}
//	else
//	{
//		Thomas.setFillColor(sf::Color::Green);
//	}

///*	if (Thomas.getPosition().y + Thomas.getSize().y > platform.getPosition().y)
//	{
//		Thomas.setFillColor(sf::Color::Blue);
//	}
//	else
//	{
//		Thomas.setFillColor(sf::Color::Green);
//	}*/
//	
//	if (Thomas.getPosition().y + Thomas.getSize().y < platform.getPosition().y +platform.getSize().y)
//	{
//		Thomas.setFillColor(sf::Color::Blue);
//	}
//	else if(Thomas.getPosition().y + Thomas.getSize().y > platform.getPosition().y + platform.getSize().y)
//	{
//		Thomas.setFillColor(sf::Color::Green);
//	}
//	

//OLD COLLISION, MIGHT NOT BE NECESSARY, REMOVE LATER IF NOT
//virtual bool  Collision(GameObject* obj) { return false; }


//OLD COLLISION DETECTION, KEEPING AROUND UNTIL COLLISION METHOD IS SOLIDIFIED

//for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
//{
//	GameObject* current = m_owner->m_gameObjects[i];
//	if (current != this)
//	{
//		if (current->Collision(this))
//		{
//			m_pos.x -= m_movement.x;
//			break;
//		}
//	}	
//}

//OLD COLLISION DETECTION, KEEPING AROUND UNTIL COLLISION METHOD IS SOLIDIFIED

//for (int i = 0; i < m_owner->m_gameObjects.size(); i++)
//{
//	GameObject* current = m_owner->m_gameObjects[i];
//	
//	if (current != this)
//	{
//		if (current->Collision(this))
//		{
//			m_pos.y -= m_movement.y;
//			m_vel.y = 0;
//			isgrounded = true; 
//		
//			break;
//		}
//	}
//}