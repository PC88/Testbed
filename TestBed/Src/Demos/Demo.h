#pragma once
#include "Demos\DemoSettings.h"
class Demo
{
public:
	Demo();
	virtual ~Demo();

	virtual void ImGuiRender() {};
	virtual void Update(double interval) {};
	virtual void Render() {};
	virtual void Box2DStart() {};
	virtual void Box2DEnd() {};

private:
	Settings m_settings;
};

