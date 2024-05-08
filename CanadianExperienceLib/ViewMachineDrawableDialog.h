/**
 * @file ViewMachineDrawableDialog.h
 * @author Lance Y.
 *
 * Display machine drawable dialog
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_VIEWMACHINEDRAWABLEDIALOG_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_VIEWMACHINEDRAWABLEDIALOG_H

#include "PictureObserver.h"

class Actor;
class Drawable;

/**
 * View class for the machine drawable dialog
 */
class ViewMachineDrawableDialog final : public wxScrolledCanvas, public PictureObserver
{
private:

    void OnSelectMachine1(wxCommandEvent &event);
    void OnSelectMachine2(wxCommandEvent &event);
public:
    ViewMachineDrawableDialog(wxFrame* parent);
    void UpdateObserver() override;

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_VIEWMACHINEDRAWABLEDIALOG_H
