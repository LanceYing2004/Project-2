/**
 * @file MachineDrawableFactory.h
 * @author Lance Y.
 *
 * Factory for Machine Drawable.
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H

class MachineDrawable;
class Actor;

/**
 * Class used to create MachineDrawable, the adapter class.
 */
class MachineDrawableFactory
{
private:
    /// machine number
    int mMachineNumber;
    /// start frame of the machine
    int mMachineStartFrame;
    /// name for the machine
    std::wstring mName;


public:
    MachineDrawableFactory(std::wstring name, int machineNumber, int machineStartFrame);
    std::shared_ptr<Actor> Create(std::wstring resourcesDir);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H
