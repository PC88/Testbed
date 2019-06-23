#pragma once
#include "Demos\Demo.h"
#include "Box2D\Box2D.h"
#include "Box2D\Common\DebugDraw.h"

class BSTDemo :
	public Demo
{
public:
	BSTDemo();
	virtual ~BSTDemo();

	void Box2DStart() override;
	void Box2DEnd() override;
	void Update(double interval) override;
	void Render() override;
	void Step(Settings* settings) override;

	b2Vec2 m_gravity;
	b2World* m_world = nullptr;
	DebugDraw m_debugDraw;
	uint32 m_flags;
	uint32 m_velocityIterations; // usually 6
	uint32 m_positionIterations; // usually 2
};

