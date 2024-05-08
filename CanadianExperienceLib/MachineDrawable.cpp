/**
 * @file MachineDrawable.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"

using namespace std;

/**
 * Machine drawable constructor
 * @param name name of the machine
 * @param resourcesDir directory folder for the machine
 * @param machineNumber number of the machine
 * @param machineStartFrame start frame of the machine
 */
MachineDrawable::MachineDrawable(const std::wstring &name, std::wstring resourcesDir, int machineNumber, int machineStartFrame)
    : Drawable(name), mResourcesDir(resourcesDir), mStartFrame(machineStartFrame) {

    MachineSystemFactory factory(resourcesDir);
    mMachineSystem = factory.CreateMachineSystem();
    mMachineSystem->SetMachineNumber(machineNumber);

//    mImage = std::make_unique<wxImage>(resourcesDir, wxBITMAP_TYPE_ANY);
//    mCenter = mMachineSystem->GetLocation();
}

/**
 * Draw 2 machines in Canadian experience
 * @param graphics The Graphics object we are drawing on
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics) {

    mMachineSystem->SetFrameRate(mTimeline->GetFrameRate());
    auto frame = mTimeline->GetCurrentFrame();
//    auto currentTime = mTimeline->GetCurrentTime();
//    auto frameRate = mTimeline->GetFrameRate();

    if (frame >= mStartFrame)
    {
        mMachineSystem->SetMachineFrame(frame - mStartFrame);
    }
    else
    {
        mMachineSystem->SetMachineFrame(0);
    }

    double scale = 0.65f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachineSystem->SetLocation(wxPoint(0, 0));
    mMachineSystem->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Setter for machine frame
 * @param frame frame of the machine system
 */
void MachineDrawable::SetMachineFrame(int frame) {
    mMachineSystem->SetMachineFrame(frame);
}

/**
 * Setter for machine number
 * @param number number of the machine
 */
void MachineDrawable::SetMachineNumber(int number) {
    mMachineSystem->SetMachineNumber(number);
}

/**
 * Hit test for the machine, return false by default
 * @param pos position of the location
 * @return bool
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    /*
    double x = pos.x;
    double y = pos.y;

    // Translate(-mPlacedPosition)
    x -= mPlacedPosition.x;
    y -= mPlacedPosition.y;

    double sn = sin(mPlacedR);
    double cs = cos(mPlacedR);

    // Rotate(mPlacedR)
    double x1 = cs * x - sn * y;
    double y1 = sn * x + cs * y;

    // Translate(mCenter)
    x = x1 + mCenter.x;
    y = y1 + mCenter.y;


//    wxGraphicsMatrix mat;
//    mat.Translate(mCenter.x, mCenter.y);
//    mat.Rotate(mPlacedR);
//    mat.Translate(-mPlacedPosition.x, -mPlacedPosition.y);
//
//    wxDouble x = pos.x;
//    wxDouble y = pos.y;
//    mat.TransformPoint(&x, &y);

    double wid = mImage->GetWidth();
    double hit = mImage->GetHeight();

    // Test to see if x, y are in the image
    if (x < 0 || y < 0 || x >= wid || y >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mImage->IsTransparent((int)x, (int)y);
     */
    return false;
}

/**
 * Initialize timeline for the adapter class
 * @param timeline pointer to timeline
 */
void MachineDrawable::SetTimeline(Timeline *timeline) {
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}

/**
 * Display Machine Dialog
 */
void MachineDrawable::DisplayDialogBox()
{
    mMachineDialog->ShowModal();
}

/**
 * Set the machine dialog to be in machine system
 * @param window wxWindow, window
 */
void MachineDrawable::AccessDialogBox(wxWindow *window)
{
    mMachineDialog= make_shared<MachineDialog>(window, mMachineSystem);
}
