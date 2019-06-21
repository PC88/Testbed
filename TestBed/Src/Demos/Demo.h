#pragma once
#include "Demos\DemoSettings.h"
class Demo
{
public:
	Demo();
	virtual ~Demo();

	// methods are not pure virtual as they are intended to be non-necessity.

	virtual void ImGuiRender() {};                  // Interface for rendering UI on each of the demos
	virtual void Update(double interval) {};        // typical update method pattern.
	virtual void Render() {};                       // Rendering call for non UI elements
	virtual void Step(Settings* settings) {};       // this is a method emulated from B2D`s architecture serving to allow separate settings for each Demo 
	virtual void Box2DStart() {};                   // deals with box2D construction on a per demo basis
	virtual void Box2DEnd() {};                     // deals with destruction on a per demo basis

	Settings m_settings;                            // the settings for each demo
};

