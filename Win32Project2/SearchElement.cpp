#include <wx/wx.h>
#include "SearchElement.h"
enum {
    ID_GROUPCHOICE_TEXTCTRL,
    ID_NAME_TEXTCTRL,

};

SearchDialog::SearchDialog(wxWindow * parent)
{
    Create(parent, wxID_ANY, _("Seaching Element"));
}

bool SearchDialog::Create(wxWindow * parent,
                               wxWindowID id, const wxString title)
{
    bool res = wxDialog::Create(parent, id, title);
    if(res)
    {
        CreateControls();
    }
    return res;
}

void SearchDialog::CreateControls()
{
    wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);

    wxStaticText * name = new wxStaticText(this, wxID_ANY, "Name:");
    wxTextCtrl * nameText = new wxTextCtrl(this, ID_NAME_TEXTCTRL, wxEmptyString);

    wxStaticText * group = new wxStaticText(this, wxID_ANY, "Group:");
    wxChoice * GroupChoice = new wxChoice(this, ID_GROUPCHOICE_TEXTCTRL, (const wxPoint &) wxEmptyString);

    wxFlexGridSizer * fg_sizer = new wxFlexGridSizer(3, 2, 0, 0);
    fg_sizer->Add(name, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->Add(nameText, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->Add(group, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->Add(GroupChoice, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    fg_sizer->AddGrowableCol(1);

    sizer->Add(fg_sizer, 1, wxEXPAND|wxTOP|wxLEFT|wxRIGHT, 5);
    sizer->Add(CreateButtonSizer(wxID_OK|wxID_CANCEL), 0, wxALIGN_RIGHT|wxALL, 5);


}

