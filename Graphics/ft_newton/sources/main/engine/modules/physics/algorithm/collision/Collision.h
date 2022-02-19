#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/modules/physics/algorithm/collision/Contact.h"

class engine::physics::Collision final
{
public :

	Collision(const Contact &contact) : _contacts { contact }, _collider1(nullptr), _collider2(nullptr)
	{}

	Collision(vector<Contact> &&contacts) : _contacts(move(contacts)), _collider1(nullptr), _collider2(nullptr)
	{}

	inline const vector<Contact> &getContacts() const
	{
		return _contacts;
	}

	inline void complementWithColliders(Collider *collider1, Collider *collider2)
	{
		_collider1 = collider1;
		_collider2 = collider2;
	}

	inline void inverseNormals()
	{
		for (auto &contact : _contacts)
			contact.normal *= -1.f;
	}

	inline Collider *getCollider1() const
	{
		return _collider1;
	}

	inline Collider *getCollider2() const
	{
		return _collider2;
	}

private :

	vector<Contact> _contacts;
	Collider *_collider1;
	Collider *_collider2;

	Collision(vector<Contact> &&contacts, Collider *collider1, Collider *collider2) : _contacts(move(contacts)), _collider1(collider1), _collider2(collider2)
	{}
};