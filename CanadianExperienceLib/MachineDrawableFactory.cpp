/**
 * @file MachineDrawableFactory.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "MachineDrawableFactory.h"
#include "MachineDrawable.h"
#include "Actor.h"

/**
 * Machine Drawable Factory constructor
 * @param name name of the machine
 * @param machineNumber machine number
 * @param machineStartFrame machine start frame
 */
MachineDrawableFactory::MachineDrawableFactory(std::wstring name, int machineNumber, int machineStartFrame)
{
    mName = name;
    mMachineNumber = machineNumber;
    mMachineStartFrame = machineStartFrame;
}

/**
 * This is a factory method that creates the MachineDrawable, with actor type.
 * @param resourcesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> MachineDrawableFactory::Create(std::wstring resourcesDir)
{

    auto actor = std::make_shared<Actor>(mName);

    auto adapter = std::make_shared<MachineDrawable>(L"Adapter", resourcesDir, mMachineNumber, mMachineStartFrame);

    actor->SetRoot(adapter);
    actor->AddDrawable(adapter);

    return actor;
}

