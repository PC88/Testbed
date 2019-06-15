#pragma once
#include "Box2D/Box2D.h"
class Demo
{
public:
	Demo();
	virtual ~Demo();

	virtual void ImGuiRender() {};
	virtual void Update(double interval) {};
	virtual void Render() {};
	b2World* m_world; // TODO: this needs to be non null
};

