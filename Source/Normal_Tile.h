#pragma once
#include"Tile.h"
#include "System/ModelRenderer.h"
class Normal_Tile:public Tile
{
public:
	Normal_Tile(int x,int y);
	~Normal_Tile();

	void Update();

	void Render(const RenderContext& rc, ModelRenderer* renderer);
private:
	Model* model;
};