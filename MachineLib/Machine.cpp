/**
 * @file Machine.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Machine.h"
#include "MachineSystem.h"
#include "Component.h"

/**
* Set the machine system that is using this machine
* @param machineSystem MachineSystem object
*/
void Machine::SetMachineSystem(MachineSystem *machineSystem)
{
    mMachineSystem = machineSystem;
}

/**
 * Add the component to the machine
 * @param component component of the snowblower machine
 */
void Machine::AddComponent(std::shared_ptr<Component> component) {
    mComponents.push_back(component);
}

/**
 * Draws the machine by drawing each of its components.
 * @param graphics The graphics context to draw on.
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics,0,0);
    }
}

/**
 * Set the new time for machine
 * @param time new time
 */
void Machine::SetTime(double time)
{
    for (auto component : mComponents)
    {
        component->SetTime(time);
    }
}

/**
 * Reset the machine
 */
void Machine::Reset()
{
    for (auto component : mComponents)
    {
        component->Reset();
    }
}

/**
 * Advance the machine used for snowblower
 * @param delta time difference
 */
void Machine::Advance(double delta)
{
    for (auto component : mComponents)
    {
        component->Advance(delta);
    }
}