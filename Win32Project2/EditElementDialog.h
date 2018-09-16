#ifndef _EDIT_Element_DIALOG_H
#define _EDIT_Element_DIALOG_H

#include <wx/wx.h>
#include <databaselayer/include/wx/filepicker.h>

class EditElementDialog : public wxDialog
{

	wxString Name;
	wxString Description;
	wxFilePickerCtrl * Image;

	void CreateControls();
public:
	EditElementDialog(wxWindow * parent);
	bool Create(wxWindow * parent, wxWindowID id, const wxString title);

	const wxString & GetName();
	const wxString & GetDescription();
    const wxString  GetImage();

};

#endif
