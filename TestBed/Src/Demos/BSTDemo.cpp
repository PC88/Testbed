#include "BSTDemo.h"



BSTDemo::BSTDemo()
{
	Box2DStart(); // create B2D demo world

	const b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	m_world->SetGravity(gravity);
}


BSTDemo::~BSTDemo()
{
	// clean up Box2D draw
	m_debugDraw.Destroy();
	Box2DEnd(); // deallocate demo b2World
}

void BSTDemo::Box2DStart()
{	///------------------------------ Box 2D setup ------------------------------------///
	m_gravity = b2Vec2(0.0, -10.0);
	m_world = new b2World(m_gravity);
	m_world->SetDebugDraw(&m_debugDraw);
	m_flags = 0;
	m_flags += m_settings.drawShapes * b2Draw::e_shapeBit;
	m_flags += m_settings.drawJoints * b2Draw::e_jointBit;
	m_flags += m_settings.drawAABBs  * b2Draw::e_aabbBit;
	m_flags += m_settings.drawCOMs   * b2Draw::e_centerOfMassBit;
	m_debugDraw.SetFlags(m_flags);
	m_debugDraw.Create();

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	m_velocityIterations = 6;
	m_positionIterations = 2;
	///------------------------------ Box 2D setup ------------------------------------//
}

void BSTDemo::Box2DEnd()
{
	delete m_world;
	m_world = nullptr;
}

void BSTDemo::Update(double interval)
{
	// Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
	m_world->Step(interval, m_velocityIterations, m_positionIterations);
}

void BSTDemo::Render()
{
	m_world->DrawDebugData();
	m_debugDraw.Flush();
}

void BSTDemo::Step(Settings* settings)
{

}
