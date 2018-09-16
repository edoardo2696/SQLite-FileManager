#ifndef _EDIT_GROUP_DIALOG_H
#define _EDIT_GROUP_DIALOG_H

#include <wx/wx.h>
#include <databaselayer/include/wx/filepicker.h>

class EditGroupDialog : public wxDialog
{

	wxString GroupName;
	wxString GroupDescription;
	wxFilePickerCtrl * ImagePicker;

	void CreateControls();
public:
	EditGroupDialog(wxWindow * parent);
	bool Create(wxWindow * parent, wxWindowID id, const wxString title);


	const wxString & GetGroupName();

	const wxString & GetGroupDescription();

	const wxString GetImage();

};

#endif
