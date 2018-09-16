#ifndef WIN32PROJECT2_EDITGCODEDIALOG_H
#define WIN32PROJECT2_EDITGCODEDIALOG_H

#include <wx/wx.h>
#include <databaselayer/include/wx/filepicker.h>

class EditGcodeDialog : public wxDialog
{

    wxString code;
    wxFilePickerCtrl * gcodeFilePicker;

    void CreateControls();
public:

    EditGcodeDialog(wxWindow * parent);
    bool Create(wxWindow * parent, wxWindowID id, const wxString title);


    const wxString GetCode();


};

#endif
