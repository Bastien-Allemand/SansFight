#include "Component.h"
#include <iostream>

int Component::GetID() const
{
	return m_id;
}

void Component::SetID(int _id)
{
	m_id = _id;
}
