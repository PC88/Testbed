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

	static const uint32 m_elementCount = 12; // number of elements in BST

	enum
	{
		e_BSTDemoElements = m_elementCount,
		e_BSTDemoElementBridges = m_elementCount,
		e_BSTDemoElementGateJoints = m_elementCount
	};

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

	// these are box2D meters
	const float m_width = 80.0f;
	const float m_height = 45.0f;

	// TODO: create measurements, of how to space out gates, and bridges.

	// test measure
	b2Body* m_topBound; // top
	b2Body* m_bottomBound; // bottom
	b2Body* m_leftBound; // left
	b2Body* m_rightBound; // right
	// test measure

	/// B2D elements used in demo ///

	// Dynamic bodies -PC
	b2Body* m_elements[e_BSTDemoElements];
	b2Body* m_elementGates[e_BSTDemoElements]; // weighted gates

	// Static bodies -PC
	b2Body* m_elementBridges[e_BSTDemoElementBridges]; // static connecting bodies

	// Joints -PC
	b2RevoluteJoint* m_elementBridgeJoints[e_BSTDemoElementGateJoints]; // joints for the gates

};

