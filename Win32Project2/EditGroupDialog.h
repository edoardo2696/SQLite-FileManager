#ifndef _EDIT_GROUP_DIALOG_H
#define _EDIT_GROUP_DIALOG_H

#include <wx/wx.h>

class EditGroupDialog : public wxDialog
{
	wxString GroupName;
	wxString GroupDescription;
	wxString ImageDirCtrl;

	void CreateControls();
public:
	EditGroupDialog(wxWindow * parent);
	bool Create(wxWindow * parent, wxWindowID id, const wxString title);

	const wxString & GetGroupName();
	void SetGroupName(const wxString & value);
	const wxString & GetGroupDescription();
	void SetGroupDescription(const wxString & value);
	const wxString & GetImageDirCtrl(wxCommandEvent& event);

};

#endif
