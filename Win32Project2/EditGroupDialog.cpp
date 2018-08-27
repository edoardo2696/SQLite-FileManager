#include "EditGroupDialog.h"
#include <wx/valgen.h>
#include <databaselayer/include/wx/filepicker.h>
#include <databaselayer/include/wx/wfstream.h>

enum
{
	ID_EGD_NAME_TEXTCTRL = 10001,
	ID_EGD_DESCRIPTION_TEXTCTRL,
	ID_EGD_IMAGE_CHOICE
};

EditGroupDialog::EditGroupDialog(wxWindow * parent)
{
	Create(parent, wxID_ANY, _("Editing group"));
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


	wxFilePickerCtrl * ImageDirCtrl = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a File"));
	nameEdit->SetValidator(wxGenericValidator(&GroupName));
	descriptionEdit->SetValidator(wxGenericValidator(&GroupDescription));

	wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(3, 2, 0, 0);
	fg_sizer->Add(nameLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(nameEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionLabel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(descriptionEdit, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	fg_sizer->Add(ImageGroup, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	fg_sizer->Add(ImageDirCtrl, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	fg_sizer->AddGrowableCol(1);

	sizer->Add(fg_sizer, 1, wxEXPAND|wxTOP|wxLEFT|wxRIGHT, 5);
	sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);
}

const wxString & EditGroupDialog::GetGroupName()
{
	return GroupName;
}

void EditGroupDialog::SetGroupName(const wxString & value)
{
	GroupName = value;
}

const wxString & EditGroupDialog::GetGroupDescription()
{
	return GroupDescription;
}

void EditGroupDialog::SetGroupDescription(const wxString & value)
{
	GroupDescription = value;
}

const wxString &EditGroupDialog::GetImageDirCtrl(wxCommandEvent& event)
{ /*wxFileDialog openFileDialog(this, ("Open JPEG file"), "", "", "JPEG files (*.jpg)|*jpg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
		if(openFileDialog.ShowModal() == wxID_CANCEL)
			return ImageDirCtrl;
		wxFileInputStream input_stream(openFileDialog.GetPath());

		if(!input_stream.IsOk())
		{
			wxLogError("Cannot Open File '%s'.", openFileDialog.GetPath());
					}*/
    return ImageDirCtrl;
}

