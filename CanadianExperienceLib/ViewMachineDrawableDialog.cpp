/**
 * @file ViewMachineDrawableDialog.cpp
 * @author Lance Y.
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>
#include <wx/xrc/xmlres.h>

#include "Picture.h"
#include "Actor.h"
#include "Drawable.h"
#include "ViewMachineDrawableDialog.h"

/**
 * Constructor
 * @param parent parent for mainframe
 */
ViewMachineDrawableDialog::ViewMachineDrawableDialog(wxFrame *parent) : wxScrolledCanvas(parent, wxID_ANY)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewMachineDrawableDialog::OnSelectMachine1, this, XRCID("Machine1"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewMachineDrawableDialog::OnSelectMachine2, this, XRCID("Machine2"));
}

/**
 * Action for selecting Machine1
 * @param event menu event click
 */
void ViewMachineDrawableDialog::OnSelectMachine1(wxCommandEvent &event)
{
    for(auto actor : *GetPicture())
    {
        if(actor->GetName() == L"Machine1")
        {
            actor->DisplayDialogBox();
            GetPicture()->UpdateObservers();
        }
    }
}

/**
 * Action for selecting Machine2
 * @param event menu event click
 */
void ViewMachineDrawableDialog::OnSelectMachine2(wxCommandEvent &event)
{
    for(auto actor : *GetPicture())
    {
        if(actor->GetName() == L"Machine2")
        {
            actor->DisplayDialogBox();
            GetPicture()->UpdateObservers();
        }
    }

}

/**
 * Update Observer
 */
void ViewMachineDrawableDialog::UpdateObserver()
{
    Refresh();
}
