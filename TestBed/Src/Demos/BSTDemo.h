#pragma once
#include "Demos\Demo.h"
#include "Box2D\Box2D.h"
#include "Box2D\Common\DebugDraw.h"


// TODO: look to refactor code of distributions, in to a serise of functions for readability
// REMINDER: left right by offset on gates, perhaps refactor values

class BSTDemo :
	public Demo
{
public:
	BSTDemo();
	virtual ~BSTDemo();

	// depth of tree
	// this means 7 nodes, 6 references. 
	// Visually that is 7 containers 6 Bridges
	static const int m_BSTdepth = 3; 

	static const uint32 m_elementCount = 8; // number of elements in BST, one over number of nodes to show insertions and deletions.
	static const uint32 m_elementContainerCount = 7; // number of edges needed to form a container, to represent a Node.
	static const uint32 m_elementReferences = m_BSTdepth * 2; // references = Depth * 2 - 2 refs per node

	enum // keeps track of the components making up the demo: all the node parts, and references
	{
		e_BSTDemoElements = m_elementCount,
		e_BSTDemoElementBridges = m_elementReferences,
		e_BSTDemoElementGateJoints = m_elementContainerCount, // same value for each Enum, just for clarity as the system has alot of parts.
		e_BSTDemoElementContainers = m_elementContainerCount,
		e_BSTDemoElementBodyJoints = m_elementContainerCount
	};

	enum // elements double per row, just a way to workout each row via elements
	{
		e_Row1Count = 1,
		e_Row2Count = 2,
		e_Row3Count = 4,
	};

	enum // just a convenient value for inner counters of the distribution algorithm
	{
		e_CounterTwo = 2,
		e_CounterFour = 4,
		e_CounterEight = 8
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
	const float m_BridgeOffset = 10.0f;
	// offset for Gates
	const float m_GateXOffset = 0.0f;  // worked out via chain positions
	const float m_GateYOffset = 25.0f; // worked out via chain positions
	// offset for inner gates
	const float m_InnerGateXOffset = 0.0f;  // worked out via chain positions
	const float m_InnerGateYOffset = 18.5f; // worked out via chain positions
	// offset for containers, they represent what the Nodes in a BST store.
	const float m_ContainerXOffset = 2.5f;
	const float m_ContainerYOffset = 18.5f;
	// offsets for the opposing container edges 
	// these need to be separate from containers
	// as joints do not collide with their bodies
	const float m_ContainerEdgeXOffset = -3.0f; // arbitrary for now 
	const float m_ContainerEdgeYOffset = 20.0f; // arbitrary for now
    // the offsets for the joint bodies which are the locking
	// mechanism for the Nodes
	const float m_ContainerJointXOffset = -3.0f; // arbitrary for now
	const float m_ContainerJointYOffset = 20.0f; // arbitrary for now
	// offsets for the revolute joints: sets the rotating point
	const float m_GateRJYOffset = 5.0f;
	const float m_GateRJXOffset = 0.0f;
	// inner gates
	const float m_InnerGateRJYOffset = -1.5f;
	const float m_InnerGateRJXOffset = 0.0f;


	// test measure
	b2Body* m_topBound = nullptr;    // top
	b2Body* m_bottomBound = nullptr; // bottom
	b2Body* m_leftBound = nullptr;   // left
	b2Body* m_rightBound = nullptr;  // right

	b2Body* m_InclineLoader = nullptr;
	// test measure

	/// B2D elements used in demo ///

	// Dynamic bodies -PC
	b2Body* m_elements[e_BSTDemoElements];
	b2Body* m_elementGates[e_BSTDemoElements]; // weighted gates

	// Static bodies -PC
	b2Body* m_elementBridges[e_BSTDemoElementBridges];       // static connecting bodies
	b2Body* m_elementContainers[e_BSTDemoElementContainers]; // the containers representing Nodes
	b2Body* m_elementContainerEdges[e_BSTDemoElementContainers];
	b2Body* m_elementJointBodies[e_BSTDemoElementBodyJoints];

	// Joints -PC
	b2RevoluteJoint* m_elementBridgeJoints[e_BSTDemoElementGateJoints]; // joints for the gates
	b2RevoluteJoint* m_elementNodeJoints[e_BSTDemoElementBodyJoints];   // joints for the nodes

};

