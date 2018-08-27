#ifndef WIN32PROJECT2_COPIA_SEARCHELEMENT_H
#define WIN32PROJECT2_COPIA_SEARCHELEMENT_H

#include <wx/dialog.h>

class SearchDialog : public wxDialog
{

    void CreateControls();

public:

    SearchDialog(wxWindow * parent);
    bool Create(wxWindow * parent, wxWindowID id, const wxString title);

};



#endif
