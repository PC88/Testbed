#include "TrammelDemo.h"


TrammelDemo::TrammelDemo()
{
	Box2DStart(); // create B2D demo world

	// we desire to simulate a top down mechanism, however box2D is by default side on. Hence we must disable the force of gravity -PC
    const b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
	m_world->SetGravity(gravity);


	/// BOUNDARIES -PC
	// bottom boundary -PC
	{

		b2EdgeShape shape;
		shape.Set(b2Vec2(-40.0f, -3.0f), b2Vec2(40.0f, -3.0f)); // Distance modified so the bound1 is half the extent of the slider up, this Elipsograph shape is held -PC

		b2BodyDef bd;
		bound1 = m_world->CreateBody(&bd);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f;// Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders

		bound1->CreateFixture(&fd);
	}

	// left boundary -PC
	{

		b2EdgeShape shape;
		shape.Set(b2Vec2(-15.0f, -40.0f), b2Vec2(-15.0f, 40.0f)); // Distance modified so the bound1 is half the exstend of the slider up, this Elipsograph shape is held -PC

		b2BodyDef bd;
		bound2 = m_world->CreateBody(&bd);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f;// Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders

		bound2->CreateFixture(&fd);
	}

	// top boundary -PC
	{

		b2EdgeShape shape;
		shape.Set(b2Vec2(-40.0f, 27.0f), b2Vec2(40.0f, 27.0f)); // Distance modified so the bound1 is half the exstend of the slider up, this Elipsograph shape is held -PC

		b2BodyDef bd;
		bound3 = m_world->CreateBody(&bd);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f;// Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders

		bound3->CreateFixture(&fd);
	}

	// right boundary -PC
	{

		b2EdgeShape shape;
		shape.Set(b2Vec2(15.0f, -40.0f), b2Vec2(15.0f, 40.0f)); // Distance modified so the bound1 is half the extent of the slider up, this Elipsograph shape is held -PC

		b2BodyDef bd;
		bound4 = m_world->CreateBody(&bd);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders

		bound4->CreateFixture(&fd);
	}
	/// BOUNDARIES -PC

	/// DEFINE STATIC BODIES: TRAMMEL WALLS -PC
	// define the static surrounding bodies: TL -PC
	{

		b2PolygonShape shape;
		shape.SetAsBox(5.0f, 5.0f);

		b2BodyDef bd;
		bd.position.Set(-7.1f, 19.1f); // 19.1 this makes it so its very close but not quite touching,  -PC
		staticBodyTopLeft = m_world->CreateBody(&bd);
		// implicitly static body -PC

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f;// Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders

		staticBodyTopLeft->CreateFixture(&fd);
	}

	// define the static surrounding bodies: TR -PC
	{

		b2PolygonShape shape;
		shape.SetAsBox(5.0f, 5.0f);

		b2BodyDef bd;
		bd.position.Set(7.1f, 19.1f); // 19.1 this makes it so its very close but not quite touching,  -PC
		staticBodyTopRight = m_world->CreateBody(&bd);
		// implicitly static body -PC

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f;// Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels -PC
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders  -PC

		staticBodyTopRight->CreateFixture(&fd);
	}

	// define the static surrounding bodies: BL -PC
	{
		b2PolygonShape shape;
		shape.SetAsBox(5.0f, 5.0f);

		b2BodyDef bd;
		bd.position.Set(-7.1f, 4.9f); // 4.9 this makes it so its very close but not quite touching, -PC
		staticBodyBottomLeft = m_world->CreateBody(&bd);
		// implicitly static body -PC

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels -PC
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders  -PC

		staticBodyBottomLeft->CreateFixture(&fd);
	}

	// define the static surrounding bodies: BR -PC
	{

		b2PolygonShape shape;
		shape.SetAsBox(5.0f, 5.0f);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0002; // 0x0002 = trammels -PC
		fd.filter.maskBits = 0x0004;     // 0x0004 = sliders  -PC

		b2BodyDef bd;
		bd.position.Set(7.1f, 4.9f); // 4.9 this makes it so its very close but not quite touching, 
									 // as the Trammels are simulated with prismatic joints and dont need friction to be constrained -PC
		staticBodyBottomRight = m_world->CreateBody(&bd);
		// implicitly static body -PC

		staticBodyBottomRight->CreateFixture(&fd);
	}
	/// DEFINE STATIC BODIES: TRAMMEL WALLS -PC

	/// DEFINE DYNAMIC BODIES -PC
	// up-down slider -PC
	{
		b2PolygonShape shape;
		shape.SetAsBox(2.0f, 3.0f);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0004;       // 0x0004 = sliders  -PC
		fd.filter.maskBits = 0x0002;           // 0x0002 = trammels -PC

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(0.0f, 12.0f);
		m_sliderUD = m_world->CreateBody(&bd);
		m_sliderUD->SetGravityScale(0.0f);
		m_sliderUD->CreateFixture(&fd);

		// m_sliderUD joints: the up-down slider -PC
		b2PrismaticJointDef pjd;
		pjd.Initialize(bound1, m_sliderUD, m_sliderUD->GetPosition(), b2Vec2(0.0f, 1.0f));

		m_joint3 = (b2PrismaticJoint*)m_world->CreateJoint(&pjd);
	}

	// left-right slider -PC
	{
		b2PolygonShape shape;
		shape.SetAsBox(3.0f, 2.0f);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		fd.filter.categoryBits = 0x0004;       // 0x0004 = sliders  -PC
		fd.filter.maskBits = 0x0002;           // 0x0002 = trammels -PC

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(-12.0f, 12.0f);
		m_sliderLR = m_world->CreateBody(&bd);
		m_sliderLR->SetGravityScale(0.0f);
		m_sliderLR->CreateFixture(&fd);

		//m_sliderLR joints: the left-right slider -PC
		b2PrismaticJointDef pjd1;
		pjd1.Initialize(bound2, m_sliderLR, m_sliderLR->GetPosition(), b2Vec2(1.0f, 0.0f));

		m_joint4 = (b2PrismaticJoint*)m_world->CreateJoint(&pjd1);
	}

	// connecting rod PC
	{
		b2PolygonShape shape;
		shape.SetAsBox(17.0f, 1.0f);

		b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
		fd.shape = &shape;
		fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
		// This is commented out but left here purely for explanation -PC
		// the Rod and Handle we dont want colliding with other bodies, because we are top down
		// and they overlap: hence we do not put them in any of the filters shown below
		//fd.filter.categoryBits = 0x0004;       // 0x0004 = sliders  -PC
		//fd.filter.maskBits = 0x0002;           // 0x0002 = trammels -PC

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(2.0f, 12.0f);
		rod = m_world->CreateBody(&bd);
		rod->CreateFixture(&fd);


		// ROD joints --- Two Revolute, One distance, Zero Prismatic --- These are the Constraints modeled in the requirements for the project -PC

		// revolute joint for slider one(UpDown) -PC
		b2RevoluteJointDef rjd1;
		rjd1.Initialize(m_sliderUD, rod, m_sliderUD->GetWorldCenter()); // take the two bodies and "constrain" them at the m_sliderUD`s center of mass. -PC
		rjd1.enableMotor = false;
		m_joint1 = (b2RevoluteJoint*)m_world->CreateJoint(&rjd1);

		// revolute joint for slider two(LeftRight) -PC
		b2RevoluteJointDef rjd2;
		rjd2.Initialize(m_sliderLR, rod, m_sliderLR->GetWorldCenter()); // take the two bodies and "constrain" them at the m_sliderLR`s center of mass. -PC
		m_joint2 = (b2RevoluteJoint*)m_world->CreateJoint(&rjd2);

		// distance joint between the sliders -PC
		b2DistanceJointDef djd;
		djd.Initialize(m_sliderUD, m_sliderLR, m_sliderUD->GetWorldCenter(), m_sliderLR->GetWorldCenter()); // take m_sliderUD and m_sliderLR, and make the distance from both objects center of mass fixed -PC
		m_joint5 = (b2DistanceJoint*)m_world->CreateJoint(&djd);

		// the handle for the rod, this body and its motor mimic the effect of a force operating the trammel
		// this could be simply a hand, or a mechanical arm etc. - PC
		{
			b2PolygonShape shape;
			shape.SetAsBox(1.0f, 3.0f);

			b2FixtureDef fd; // create a fixture manually, to mask collisions -PC
			fd.shape = &shape;
			fd.density = 2.0f; // Density is kept uniform on objects for stability - PC
			// This is commented out but left here purely for explanation -PC
			// the Rod and Handle we dont want colliding with other bodies, because we are top down
			// and they overlap: hence we do not put them in any of the filters shown below
			//fd.filter.categoryBits = 0x0004;       // 0x0004 = sliders  -PC
			//fd.filter.maskBits = 0x0002;           // 0x0002 = trammels -PC

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(19.5f, 12.0f);
			rodHandle = m_world->CreateBody(&bd);
			rodHandle->SetGravityScale(0.0f);
			rodHandle->CreateFixture(&fd);

			// distance joint between the rods center and the handles center -PC
			b2DistanceJointDef djd;
			djd.Initialize(rodHandle, rod, rodHandle->GetWorldCenter(), rod->GetWorldCenter()); // get both centers as each respective end of the distance joint -PC
			m_joint7 = (b2DistanceJoint*)m_world->CreateJoint(&djd);

			// revolute joint for the handle to simulate a rotatry force moving the connected arm of the trammel -PC
			// this does have "helicopter" effect on the end of the trammel as it rotates the conjoined elements,
			// the end result however is exactly as intended, I just chose to separate the arm and the handle as  I 
			// cannot have a literal hand move the trammel and thus have the force applied explicitly to the rodhandle
			// simulate it.
			b2RevoluteJointDef rjd2;
			rjd2.Initialize(rodHandle, rod, rodHandle->GetWorldCenter()); // take the two bodies and "constrain" them at the m_sliderLR`s center of mass. -PC
			rjd2.motorSpeed = 1000.0f * b2_pi;
			rjd2.maxMotorTorque = 10000.0f;
			rjd2.enableMotor = true;
			m_joint6 = (b2RevoluteJoint*)m_world->CreateJoint(&rjd2);
		}
	}
}

TrammelDemo::~TrammelDemo()
{
	// clean up Box2D draw
	m_debugDraw.Destroy();
	Box2DEnd(); // deallocate demo b2World
}

void TrammelDemo::Box2DStart()
{
	///------------------------------ Box 2D setup ------------------------------------///
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

void TrammelDemo::Box2DEnd()
{
	delete m_world;
	m_world = nullptr;
}

void TrammelDemo::Update(double interval)
{
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	m_world->Step(interval, m_velocityIterations, m_positionIterations);
}

void TrammelDemo::Render()
{
	m_world->DrawDebugData();
	m_debugDraw.Flush();
}

void TrammelDemo::Step(Settings* settings)
{

}
