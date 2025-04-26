#pragma once
#include"Map.h"
#include<vector>
class MapManager
{
public:
	static MapManager& Instance()
	{
		static MapManager instance;
		return instance;
	}

	void Update();

	void Render();


private:
	MapManager();
	~MapManager(){}

	std::vector<Map> maps;
};