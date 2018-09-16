#include "EditGroupDialog.h"
#include "../EditGcodeDialog.h"

#include <wx/valgen.h>
#include <databaselayer/include/wx/filepicker.h>
#include <databaselayer/include/wx/wfstream.h>

enum
{
	ID_EGD_NAME_TEXTCTRL = 10001,
	ID_EGD_DESCRIPTION_TEXTCTRL,
	ID_EGD_GROUPID_TEXTCTRL

};

EditGroupDialog::EditGroupDialog(wxWindow * parent)
{
	Create(parent, wxID_ANY, _(" Group Adder"));
}

bool EditGroupDialog::Create(wxWindow * parent, wxWindowID id, const wxString title)
{
	bool res = wxDialog::Create(parent, id, title);
	if(res)
	{
		CreateControls();
	}
	return res;
}

void EditGroupDialog::CreateControls()
{
	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	wxStaticText * nameLabel = new wxStaticText(this, wxID_ANY, _("Name:"));
	wxStaticText * descriptionLabel = new wxStaticText(this, wxID_ANY, _("Description:"));
	wxStaticText * ImageGroup = new wxStaticText(this, wxID_ANY, _("ImageGroup:"));

	wxTextCtrl * nameEdit = new wxTextCtrl(this, ID_EGD_NAME_TEXTCTRL, wxEmptyString);
	wxTextCtrl * descriptionEdit = new wxTextCtrl(this, ID_EGD_DESCRIPTION_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(-1, 80), wxTE_MULTILINE);


	ImagePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a File"));

	nameEdit->SetValidator(wxGenericValidator(&GroupName));
	descriptionEdit->SetValidator(wxGenericValidator(&GroupDescription));


	wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(3, 2, 0, 0);

	fg_sizer->Add(nameLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(nameEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(ImageGroup, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	fg_sizer->Add(ImagePicker, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	fg_sizer->AddGrowableCol(1);

	sizer->Add(fg_sizer, 1, wxEXPAND|wxTOP|wxLEFT|wxRIGHT, 5);
	sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);
}


const wxString & EditGroupDialog::GetGroupName()
{
	return GroupName;
}


const wxString & EditGroupDialog::GetGroupDescription()
{
	return GroupDescription;
}


const wxString EditGroupDialog::GetImage()
{
	return ImagePicker->GetPath();

}

