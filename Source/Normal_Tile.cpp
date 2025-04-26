#include "Normal_Tile.h"

Normal_Tile::Normal_Tile(int x,int y)
{
	position.x = x;
	position.y = y;
	model = new Model("Data/Model/floor/floor.mdl");
}

Normal_Tile::~Normal_Tile()
{
	delete model;
}

void Normal_Tile::Update()
{
	UpdateTransform();

	model->UpdateTransform();
}

void Normal_Tile::Render(const RenderContext& rc, ModelRenderer* renderer)
{
	int a = 0;
}
