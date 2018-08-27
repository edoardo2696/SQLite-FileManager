#include "EditElementDialog.h"
#include <wx/valgen.h>
#include <wx/filepicker.h>


enum
{
	ID_ELD_NAME_TEXTCTRL = 10001,
	ID_ELD_DESCRIPTION_TEXTCTRL,



};

EditElementDialog::EditElementDialog(wxWindow * parent)
{
	Create(parent, wxID_ANY, _("Editing Element"));
}

bool EditElementDialog::Create(wxWindow * parent, 
							  wxWindowID id, const wxString title)
{
	bool res = wxDialog::Create(parent, id, title);
	if(res)
	{
		CreateControls();
	}
	return res;
}

void EditElementDialog::CreateControls()
{
	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	wxStaticText * nameLabel = new wxStaticText(this, wxID_ANY, _("Name:"));
	wxStaticText * descriptionLabel = new wxStaticText(this, wxID_ANY, _("Description:"));
	wxStaticText * Image = new wxStaticText( this, wxID_ANY, wxT("Image"));
    wxStaticText * Gcode = new wxStaticText( this, wxID_ANY, wxT("Gcode"));

    wxTextCtrl * nameEdit = new wxTextCtrl(this, ID_ELD_NAME_TEXTCTRL, wxEmptyString);
	wxTextCtrl * descriptionEdit = new wxTextCtrl(this, ID_ELD_DESCRIPTION_TEXTCTRL, wxEmptyString);

	nameEdit->SetMinSize(wxSize(150,-1));
	nameEdit->SetValidator(wxGenericValidator(&Name));
	descriptionEdit->SetValidator(wxGenericValidator(&Description));


    wxFilePickerCtrl * FileDirCtrl = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a File"));
    wxFilePickerCtrl * GcodeDirCtrl = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a Gcode"));


	wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(5, 2, 0, 0);
	fg_sizer->Add(nameLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(nameEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(Image, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    fg_sizer->Add(FileDirCtrl, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    fg_sizer->Add(Gcode, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    fg_sizer->Add(GcodeDirCtrl, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
    fg_sizer->AddGrowableCol(1);




	sizer->Add(fg_sizer, 1, wxEXPAND|wxTOP|wxLEFT|wxRIGHT, 5);
	sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);

	sizer->Fit(this);
}

const wxString & EditElementDialog::GetName()
{
	return Name;
}

const wxString & EditElementDialog::GetDescription()
{
	return Description;
}

const wxString &EditElementDialog::GetFileImage() {
    return FileImage;
}

const wxString &EditElementDialog::GetGcodeFile() {
    return GcodeFile;
}

