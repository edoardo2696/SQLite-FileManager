#include <databaselayer/include/wx/valgen.h>
#include <databaselayer/include/wx/filepicker.h>
#include "EditGcodeDialog.h"

enum{
    ID_ELD_CODE_TEXTCTRL = 10001,

};
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

    wxStaticText * codeLabel = new wxStaticText(this, wxID_ANY, _("Name:"));


    wxTextCtrl * codeEdit = new wxTextCtrl(this, ID_ELD_CODE_TEXTCTRL, wxEmptyString);

    Gcode = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a File"));

    codeEdit->SetValidator(wxGenericValidator(code));



    wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(2, 2, 0, 0);

    fg_sizer->Add(codeLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->Add(codeEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);


    fg_sizer->Add(Gcode, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    fg_sizer->AddGrowableCol(1);


    fg_sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);
}



const wxString EditGcodeDialog::GetCode()
{
    return Gcode->GetPath();
}




