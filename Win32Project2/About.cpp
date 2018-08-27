#include "About.h"


DialogAbout::DialogAbout( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, "About", pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer( wxVERTICAL );

    staticText1 = new wxStaticText( this, wxID_ANY, "wxSQLiteFileManager", wxDefaultPosition, wxDefaultSize, 0 );
    staticText1->Wrap( -1 );

    bSizer21->Add( staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer6->Add( bSizer21, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer22;
    bSizer22 = new wxBoxSizer( wxVERTICAL );
    staticText2 = new wxStaticText( this, wxID_ANY, "Version 1.0", wxDefaultPosition, wxDefaultSize, 0 );
    staticText2->Wrap( -1 );

    bSizer22->Add( staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer6->Add( bSizer22, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer23;
    bSizer23 = new wxBoxSizer( wxVERTICAL );
    staticText3 = new wxStaticText( this, wxID_ANY, "This program is licensed under the MICC Unifi Project", wxDefaultPosition, wxDefaultSize, 0 );
    staticText3->Wrap( -1 );
    bSizer23->Add( staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer6->Add( bSizer23, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer24;
    bSizer24 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer25;
    bSizer25 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer26;
    bSizer26 = new wxBoxSizer( wxVERTICAL );
    staticText4 = new wxStaticText( this, wxID_ANY, "Author:", wxDefaultPosition, wxDefaultSize, 0 );
    staticText4->Wrap( -1 );

    bSizer26->Add( staticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer25->Add( bSizer26, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer27;
    bSizer27 = new wxBoxSizer( wxVERTICAL );
    staticText5 = new wxStaticText( this, wxID_ANY, "Edoardo Luci", wxDefaultPosition, wxDefaultSize, 0 );
    staticText5->Wrap( -1 );

    bSizer27->Add( staticText5, 0, wxALL, 5 );
    bSizer25->Add( bSizer27, 1, wxEXPAND, 5 );
    bSizer24->Add( bSizer25, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer28;
    bSizer28 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer29;
    bSizer29 = new wxBoxSizer( wxVERTICAL );
    staticText6 = new wxStaticText( this, wxID_ANY, "E-mail:", wxDefaultPosition, wxDefaultSize, 0 );
    staticText6->Wrap( -1 );
    bSizer29->Add( staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer28->Add( bSizer29, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer30;
    bSizer30 = new wxBoxSizer( wxVERTICAL );
    staticText7 = new wxStaticText( this, wxID_ANY, "edoardo.luci@stud.unifi.it", wxDefaultPosition, wxDefaultSize, 0 );
    staticText7->Wrap( -1 );


    bSizer30->Add( staticText7, 0, wxALL, 5 );
    bSizer28->Add( bSizer30, 1, wxEXPAND, 5 );
    bSizer24->Add( bSizer28, 1, wxEXPAND, 5 );
    bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer31;
    bSizer31 = new wxBoxSizer( wxVERTICAL );
    m_button5 = new wxButton( this, wxID_OK, "OK", wxDefaultPosition, wxDefaultSize, 0 );
    bSizer31->Add( m_button5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    bSizer24->Add( bSizer31, 1, wxEXPAND, 5 );
    bSizer6->Add( bSizer24, 1, wxEXPAND, 5 );


    SetSizer( bSizer6 );
    Layout();
    Centre();
}

DialogAbout::~DialogAbout()
{
}