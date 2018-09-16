#ifndef WIN32PROJECT2_EDITGCODEDIALOG_H
#define WIN32PROJECT2_EDITGCODEDIALOG_H


#include <wx/wx.h>

class EditGcodeDialog : public wxDialog
{

    int * code;
    wxFilePickerCtrl * Gcode;

    void CreateControls();
public:

    EditGcodeDialog(wxWindow * parent);
    bool Create(wxWindow * parent, wxWindowID id, const wxString title);


    const wxString GetCode();


};

#endif
