#include "EntityManager.h"

// VERY INCOMPLETE
#include "Entity.h"// not sure




std::shared_ptr<Entity> EntityManager::addEntity(std::string tag)
{
	auto e = std::shared_ptr<Entity>(new Entity());
	return e;
}
