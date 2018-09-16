#ifndef WIN32PROJECT2_COPIA_ABOUT_H
#define WIN32PROJECT2_COPIA_ABOUT_H


#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

class DialogAbout : public wxDialog
{
private:

protected:
    wxStaticText* staticText1;
    wxStaticText* staticText2;
    wxStaticText* staticText3;
    wxStaticText* staticText4;
    wxStaticText* staticText5;
    wxStaticText* staticText6;
    wxStaticText* staticText7;
    wxButton* m_button5;

public:

    DialogAbout( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 401,281 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~DialogAbout();

};



#endif
