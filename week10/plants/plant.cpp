#include "plant.h"

Potato* Potato::_instance = nullptr;

Potato* Potato::instance()
{
    if(nullptr==_instance) _instance = new Potato();
    return _instance;
}
void Potato::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}

Pea* Pea::_instance = nullptr;
Pea* Pea::instance()
{
    if(nullptr==_instance) _instance = new Pea();
    return _instance;
}
void Pea::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}

Onion* Onion::_instance = nullptr;
Onion* Onion::instance()
{
    if(nullptr==_instance) _instance = new Onion();
    return _instance;
}
void Onion::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}

Rose* Rose::_instance = nullptr;
Rose* Rose::instance()
{
    if(nullptr==_instance) _instance = new Rose();
    return _instance;
}
void Rose::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}

Carnation* Carnation::_instance = nullptr;
Carnation* Carnation::instance()
{
    if(nullptr==_instance) _instance = new Carnation();
    return _instance;
}
void Carnation::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}

Tulip* Tulip::_instance = nullptr;
Tulip* Tulip::instance()
{
    if(nullptr==_instance) _instance = new Tulip();
    return _instance;
}
void Tulip::destroy()
{
    if(nullptr!=_instance) delete _instance;
	_instance = nullptr;
}
