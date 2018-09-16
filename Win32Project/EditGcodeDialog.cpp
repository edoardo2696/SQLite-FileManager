#include <databaselayer/include/wx/valgen.h>
#include <databaselayer/include/wx/filepicker.h>
#include "EditGcodeDialog.h"

EditGcodeDialog::EditGcodeDialog(wxWindow * parent)
{
    Create(parent, wxID_ANY, "Gcode Adder");
}

bool EditGcodeDialog::Create(wxWindow * parent,
                             wxWindowID id, const wxString title)
{
    bool res = wxDialog::Create(parent, id, title);
    if(res)
    {
        CreateControls();
    }
    return res;
}

void EditGcodeDialog::CreateControls()
{
    wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);

    wxStaticText * code = new wxStaticText(this, wxID_ANY, _("Code:"));

    gcodeFilePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a File"));

    wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(3, 2, 0, 0);
    fg_sizer->Add(code, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->Add(gcodeFilePicker, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    fg_sizer->AddGrowableCol(1);
    sizer->Add(fg_sizer, 1, wxEXPAND|wxTOP|wxLEFT|wxRIGHT, 5);
    sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);

    sizer->Fit(this);
}



const wxString EditGcodeDialog::GetCode()
{
    return gcodeFilePicker->GetPath();
}
