#pragma once
#include "Demos\Demo.h"
#include "Box2D\Box2D.h"
#include "Box2D\Common\DebugDraw.h"

class TrammelDemo :
	public Demo
{
public:
	TrammelDemo();
	virtual ~TrammelDemo();

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

	// static bodies -PC
	b2Body* staticBodyBottomRight = nullptr;
	b2Body* staticBodyBottomLeft = nullptr;
	b2Body* staticBodyTopRight = nullptr;
	b2Body* staticBodyTopLeft = nullptr;

	// static bodies -PC
	b2Body* bound1 = nullptr;
	b2Body* bound2 = nullptr;
	b2Body* bound3 = nullptr;
	b2Body* bound4 = nullptr;

	// Dynamic bodies -PC
	b2Body* m_sliderUD = nullptr;
	b2Body* m_sliderLR = nullptr;
	b2Body* rod = nullptr;
	b2Body* rodHandle = nullptr;

	// joints: constraints - PC
	b2RevoluteJoint* m_joint1 = nullptr;   // Shuttle/Slider pivot 1 -PC
	b2RevoluteJoint* m_joint2 = nullptr;   // Shuttle/Slider pivot 2 -PC
	b2PrismaticJoint* m_joint3 = nullptr;  // trammel constraint 1 -PC
	b2PrismaticJoint* m_joint4 = nullptr;  // trammel constraint 2 -PC
	b2DistanceJoint* m_joint5 = nullptr;   // connecting rod constraint 2 -PC
	b2RevoluteJoint* m_joint6 = nullptr;   // simulates force applied to the handle -PC
	b2DistanceJoint* m_joint7 = nullptr;   // constrains the handle to the rod -PC
};

