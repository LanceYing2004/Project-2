/**
 * @file MachineDrawable.h
 * @author Lance Y.
 *
 * The adapter class connecting between CanadianExp. to MachineLib.
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H

#include <machine-api.h>
#include "Drawable.h"

/**
 * MachineDrawable, a.k.a. adapter class. Inherited from Drawable.
 */
class MachineDrawable : public Drawable
{
private:
    /// Resource Directory of the file
    std::wstring mResourcesDir;

    /// Smart pointer to machine system
    std::shared_ptr<IMachineSystem> mMachineSystem;

    /// pointer to the timeline
    Timeline *mTimeline = nullptr;

    /// starting frame
    int mStartFrame = 0;

    /// Pointer to machine dialog
    std::shared_ptr<MachineDialog> mMachineDialog;

//    wxPoint mCenter = wxPoint(0, 0);
//
//    /// The underlying image we are drawing
//    std::unique_ptr<wxImage> mImage;
public:

    MachineDrawable(const std::wstring &name, std::wstring resourcesDir, int machineNumber, int machineStartFrame);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;

    void SetMachineFrame(int frame);
    void SetMachineNumber(int number);

    void SetTimeline(Timeline *timeline) override;

    void DisplayDialogBox() override;
    void AccessDialogBox(wxWindow *window) override;
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
