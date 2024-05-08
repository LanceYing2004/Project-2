/**
 * @file Machine.h
 * @author Lance Y.
 *
 * Class for Machine
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

#include "MachineSystem.h"

class MachineSystem;
class Component;

/**
 * Class for individual machine
 */
class Machine
{
private:
    /// Machine number
    int mMachineNumber;

    /// The machine system that is controlling this machine
    MachineSystem* mMachineSystem = nullptr;

    /// Components for the machine
    std::vector<std::shared_ptr<Component>> mComponents;


public:
    /**
     * Constructor
     * @param machineNumber The machine number to set
     */
    Machine(int machineNumber) : mMachineNumber(machineNumber) {}

    void SetMachineSystem(MachineSystem *machineSystem);

    /**
     * Getter for machine number
     * @return machine number
     */
    int GetMachineNumber() const { return mMachineNumber; }
    /**
     * Setter for machine number
     * @param machineNumber machine number
     */
    void SetMachineNumber(int machineNumber) {mMachineNumber = machineNumber; }

    void AddComponent(std::shared_ptr<Component> component);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void SetTime(double time);
    void Reset();
    void Advance(double delta);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
