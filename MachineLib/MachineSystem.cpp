/**
 * @file MachineSystem.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "MachineSystem.h"
#include "Machine.h"

/**
 * Constructor for Machine system
 * @param resourcesDir directory for storing all the images
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
}

/**
 * Set location for the Machine System
 * @param location location of the machine
 */
void MachineSystem::SetLocation(wxPoint location)
{
    mPosition = location;
}

/**
 * Get location for the Machine System
 * @return location wxPoint of the machine
 */
wxPoint MachineSystem::GetLocation()
{
    return wxPoint();
}

/**
 * Draw the machine
 * @param graphics Graphics context to draw on.
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    // This will put the machine where it is supposed to be drawn
    graphics->PushState();
    graphics->Translate(mPosition.x, mPosition.y);

    mMachine->Draw(graphics);

    graphics->PopState();
}

/**
 * Set Machine Frame
 * @param frame frame of the machine system
 */
void MachineSystem::SetMachineFrame(int frame)
{
    if (frame < mFrame)
    {
        Reset();
        mFrame = frame;
        mTime = mFrame / mFrameRate;
        mMachine->SetTime(mTime);
        return;
    }

    while (mFrame < frame) {
        mFrame++;
        mTime = mFrame / mFrameRate;
        mMachine->SetTime(mTime);
        mMachine->Advance(1.0 / mFrameRate);
    }
}

/**
 * Set the frame rate of the machine system
 * @param rate rate of the machine system
 */
void MachineSystem::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

/**
 * Set the machine number, creating the appropriate machine
 * @param machine Machine number
 */
void MachineSystem::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        Machine1Factory factory1(mResourcesDir);
        auto machine1 = factory1.Create();
        SetMachine(machine1);
    }
    else
    {
        Machine2Factory factory2(mResourcesDir);
        auto machine2 = factory2.Create();
        SetMachine(machine2);
    }
}

/**
 * Get the number of machine
 * @return int machine number
 */
int MachineSystem::GetMachineNumber()
{
    if (mMachine != nullptr)
    {
        return mMachine->GetMachineNumber();
    }
    else
    {
        // Error value
        return 0;
    }
}

/**
 * Getter for machine time
 * @return double mTime
 */
double MachineSystem::GetMachineTime()
{
    return mTime;
}

/**
 * Set the flag for Machine System, unused function
 * @param flag number of flags
 */
void MachineSystem::SetFlag(int flag)
{

}

/**
* Set the MachineSystem to Machine association
* @param machine Machine object to set
*/
void MachineSystem::SetMachine(std::shared_ptr<Machine> machine)
{
    mMachine = machine;
}

/**
 * Reset the time for the machine system
 */
void MachineSystem::Reset()
{
    mTime = 0;
    mMachine->Reset();
}

