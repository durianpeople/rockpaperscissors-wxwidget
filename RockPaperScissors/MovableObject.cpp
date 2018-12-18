#include "MovableObject.h"

MovableObject::MovableObject(wxPoint position, wxSize size)
{
	this->position = position;
	this->size = size;
}

void MovableObject::setPosition(wxPoint position)
{
	this->position = position;
}

wxPoint MovableObject::getPosition()
{
	return this->position;
}

wxSize MovableObject::getSize()
{
	return wxSize();
}

bool MovableObject::collideWith(MovableObject * object)
{
	if ((this->position.x <= object->getPosition().x && object->getPosition().x <= this->position.x + this->size.x ||
		this->position.x <= object->getPosition().x + object->getSize().x && object->getPosition().x + object->getSize().x <= this->position.x + this->size.x) ||
		(this->position.y <= object->getPosition().y && object->getPosition().y <= this->position.y + this->size.y ||
			this->position.y <= object->getPosition().y + object->getSize().y && object->getPosition().y + object->getSize().y <= this->position.y + this->size.y)) {
		return true;
	}
	return false;
}
