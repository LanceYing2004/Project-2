/**
 * @file Component.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Component.h"


/**
 * Set the machine for the components
 * @param machine pointer to the machine class
 */
void Component::SetMachine(Machine *machine)
{
    mMachine = machine;
}

/**
 * Draw component on the screen
 * @param graphics graphics used to draw the picture
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x + mLocation.x, y + mLocation.y);
}

/**
 * Set the new time/update time on the machine system
 * @param time new time
 */
void Component::SetTime(double time)
{

}

/**
 * Reset the machine system time
 */
void Component::Reset()
{

}

/**
 * Advance function used to draw the snow
 * @param delta time difference
 */
void Component::Advance(double delta)
{

}

