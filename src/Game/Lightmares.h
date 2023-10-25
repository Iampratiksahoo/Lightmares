#pragma once
#include <vector>

class GameObject;
class Lightmares
{
public:
	Lightmares();
	~Lightmares();

	void Setup();
	void Run();

private:

	void Update();
	void Draw();

	void AddGameObject(GameObject* gameObject);

private:
	std::vector<GameObject*> mGameObjects;
};

