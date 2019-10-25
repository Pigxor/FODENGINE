#include <iostream>
#include <fodengine/engine.h>
#include <memory>



int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::cout << "FODENGINE HELLO " << std::endl;

	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Triangle> component = entity->addComponent<Triangle>();
	
	engine->start();
	std::cout << "FINISHED UPDATING" << std::endl;



   system("PAUSE");
	
	return 0;
}