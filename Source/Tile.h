#pragma once
#include"Character.h"
class Tile:public Character
{
public:
	Tile() {}
	virtual ~Tile() {}

	virtual void Update() {};

	virtual void Render(const RenderContext& rc, ModelRenderer* renderer) {};
};