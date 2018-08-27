#ifndef _EDIT_Element_DIALOG_H
#define _EDIT_Element_DIALOG_H

#include <wx/wx.h>

class EditElementDialog : public wxDialog
{
	wxString Name;
	wxString Description;
    wxString FileImage;
    wxString GcodeFile;
	void CreateControls();
public:
	EditElementDialog(wxWindow * parent);
	bool Create(wxWindow * parent, wxWindowID id, const wxString title);

	const wxString & GetName();
	const wxString & GetDescription();
    const wxString & GetFileImage();
    const wxString & GetGcodeFile();

};

#endif
