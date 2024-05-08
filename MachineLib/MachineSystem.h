/**
 * @file MachineSystem.h
 * @author Lance Y.
 *
 * A system that manage all parts of the machines
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H

#include "IMachineSystem.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"

class Machine;

/**
 * Machine System of the machine, inherited from IMachineSystem
 */
class MachineSystem : public IMachineSystem
{

private:
    /// position of the Machine System
    wxPoint mPosition;

    /// Frame for the machine
    double mFrame = 0;

    /// Frame rate for the machine
    double mFrameRate = 30;

    /// Number of flags
    int mFlag = 0;

    /// Time for the Machine System
    double mTime = 0;

    /// The associated machine
    std::shared_ptr<Machine> mMachine;

    /// Directory
    std::wstring mResourcesDir;

public:

    MachineSystem(std::wstring resourcesDir);


    void SetLocation(wxPoint location) override;
    wxPoint GetLocation() override;
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    void SetMachineFrame(int frame) override;
    void SetFrameRate(double rate) override;
    void SetMachineNumber(int machine) override;
    int GetMachineNumber() override;
    double GetMachineTime() override;
    void SetFlag(int flag) override;

    void SetMachine(std::shared_ptr<Machine> machine);
    void Reset();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
