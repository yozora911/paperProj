#pragma once

#include"Tile.h"
#include<vector>

class Tile_Manager
{
public:
	static Tile_Manager& Instance()
	{
		static Tile_Manager instance;
		return instance;
	}

	void Update();

	void Render(const RenderContext& rc, ModelRenderer* renderer);

	void Add();

private:
	Tile_Manager();
	~Tile_Manager() {};

	std::vector<Tile*> tiles;
};