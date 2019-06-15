#pragma once
#include "Demos\Demo.h"
#include "Box2D\Box2D.h"

class TrammelDemo :
	public Demo
{
public:
	TrammelDemo();
	virtual ~TrammelDemo();


	// static bodies -PC
	b2Body* staticBodyBottomRight;
	b2Body* staticBodyBottomLeft;
	b2Body* staticBodyTopRight;
	b2Body* staticBodyTopLeft;

	// static bodies -PC
	b2Body* bound1 = nullptr;
	b2Body* bound2 = nullptr;
	b2Body* bound3 = nullptr;
	b2Body* bound4 = nullptr;

	// Dynamic bodies -PC
	b2Body* m_sliderUD;
	b2Body* m_sliderLR;
	b2Body* rod;
	b2Body* rodHandle;

	// joints: constraints - PC
	b2RevoluteJoint* m_joint1 = nullptr;   // Shuttle/Slider pivot 1 -PC
	b2RevoluteJoint* m_joint2 = nullptr;   // Shuttle/Slider pivot 2 -PC
	b2PrismaticJoint* m_joint3 = nullptr;  // trammel constraint 1 -PC
	b2PrismaticJoint* m_joint4 = nullptr;  // trammel constraint 2 -PC
	b2DistanceJoint* m_joint5 = nullptr;   // connecting rod constraint 2 -PC
	b2RevoluteJoint* m_joint6 = nullptr;   // simulates force applied to the handle -PC
	b2DistanceJoint* m_joint7 = nullptr;   // constrains the handle to the rod -PC
};

