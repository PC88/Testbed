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

	static const uint32 m_elementCount = 9; // number of elements in BST

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
	// offset for bridges
	const float m_leftOffset = 10.0f;
	const float m_rightOffset = 10.0f;
	// offset for Gates
	const float m_GateOffset = 35.0f;

	// depth of tree
	const int m_BSTdepth = 4;

	// TODO: create measurements, of how to space out gates, and bridges.

	// test measure
	b2Body* m_topBound = nullptr; // top
	b2Body* m_bottomBound = nullptr; // bottom
	b2Body* m_leftBound = nullptr; // left
	b2Body* m_rightBound = nullptr; // right

	b2Body* m_InclineLoader = nullptr;
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

