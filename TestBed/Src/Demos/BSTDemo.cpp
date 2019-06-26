#include "BSTDemo.h"



BSTDemo::BSTDemo()
{
	Box2DStart(); // create B2D demo world

	const b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	m_world->SetGravity(gravity);

	// from TL to TR bounds measurements in B2D meters are Width = 80, Height = 45.
	/// DEMO Boundaries ///
	{
		{ // top bound
			b2PolygonShape shape;
			shape.SetAsBox(m_width, 0.1f);

			b2BodyDef bd;
			bd.position.Set(0.0f, m_height);
			m_topBound = m_world->CreateBody(&bd);

			m_topBound->CreateFixture(&shape, 1.0f);
		}

		{ // bottom bound
			b2PolygonShape shape;
			shape.SetAsBox(m_width, 0.1f);

			b2BodyDef bd;
			bd.position.Set(0.0f, -5.0f);
			m_bottomBound = m_world->CreateBody(&bd);

			m_bottomBound->CreateFixture(&shape, 1.0f);
		}

		{ // left bound
			b2PolygonShape shape;
			shape.SetAsBox(0.1f, m_height);

			b2BodyDef bd;
			bd.position.Set(-(m_width / 2), 0.0f);
			m_leftBound = m_world->CreateBody(&bd);

			m_leftBound->CreateFixture(&shape, 1.0f);
		}

		{ // right bound
			b2PolygonShape shape;
			shape.SetAsBox(0.1f, m_height);

			b2BodyDef bd;
			bd.position.Set(m_width / 2, 0.0f);
			m_rightBound = m_world->CreateBody(&bd);

			m_rightBound->CreateFixture(&shape, 1.0f);
		}
	}
	/// DEMO Boundaries ///

	/// DEFINE DYNAMIC BODIES ///
	{
		// define the elements that will be in the tree
		for (int32 i = 0; i < e_BSTDemoElements; ++i)
		{
			b2PolygonShape shape;
			shape.SetAsBox(1.5f, 1.5f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-m_width / (i + 1), 35.0f);

			m_elements[i] = m_world->CreateBody(&bd);

			m_elements[i]->CreateFixture(&shape, 1.0f);

			//m_elements[i]->SetLinearVelocity(b2Vec2(0.0f, -50.0f));
		}

		// define the dynamic gates which hold objects
		for (int32 i = 0; i < e_BSTDemoElementGateJoints; ++i)
		{
			b2PolygonShape shape;
			shape.SetAsBox(3.5f, 0.5f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(float((i * i) / m_width), m_height / (i + 1));

			m_elementGates[i] = m_world->CreateBody(&bd);

			m_elementGates[i]->CreateFixture(&shape, 1.0f);
		}
	}
	/// DEFINE DYNAMIC BODIES ///

	/// DEFINE STATIC BODIES ///
	// define the static bridges which visualize the references to sub-nodes
	{
		for (int32 i = 0; i < e_BSTDemoElementBridges; ++i)
		{
			b2EdgeShape shape;
			shape.Set(b2Vec2(-5.0f, 22.0f), b2Vec2(5.0f, 22.0f));

			b2BodyDef bd;
			bd.type = b2_staticBody;
			if ((m_width * i) / 8 != 0)
			{
				// (((m_width * i)/8)/2)
				int calc = (int((m_width * i) / 8) % 2);
				if (  calc == 0   )
				{
					bd.position.Set(-((m_width * i) / 8), -(m_height * i) / 8);
				} 
				else
				{
					bd.position.Set((m_width * i) / 8, -(m_height * i) / 8);
				}
			}
			else
			{
				bd.position.Set((m_width * i) / 8, (m_height * i) / 8);
			}

			m_elementBridges[i] = m_world->CreateBody(&bd);

			m_elementBridges[i]->CreateFixture(&shape, 1.0f);
		}
		{
			b2EdgeShape shape;
			shape.Set(b2Vec2(-(m_width/6) - m_width/6, m_height - 10.0f), b2Vec2(m_width/6 - m_width / 6, m_height - 15.0f));

			b2BodyDef bd;
			bd.type = b2_staticBody;
			bd.position.Set(0.0f, 10.0f);

			m_InclineLoader= m_world->CreateBody(&bd);

			m_InclineLoader->CreateFixture(&shape, 1.0f);
		}
	}
	/// DEFINE STATIC BODIES ///
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
