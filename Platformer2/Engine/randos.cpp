//OLD COLLISION, MIGHT NOT BE NECESSARY, REMOVE LATER IF NOT
//virtual bool  Collision(GameObject* obj) { return false; }

//OLD COLLISION DETECTION, KEEPING AROUND UNTIL COLLISION METHOD IS SOLIDIFIED


//Top = m_sprite.getPosition().y;
//Bottom = m_sprite.getPosition().y + m_sprite.getScale().y;
//Right = m_sprite.getPosition().x + m_sprite.getScale().x;
//Left = m_sprite.getPosition().x;

//bool  Platform::Collision(GameObject* obj)
//{
//	if ((obj->GetPos().y + obj->Top > Top) &&
//		(obj->GetPos().y  < Bottom) &&
//		(obj->GetPos().x + obj->Bottom  > Left) &&
//		(obj->GetPos().x < Right))
//	{
//		return true;
//	}
//
//	return false;
//}

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

//m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);