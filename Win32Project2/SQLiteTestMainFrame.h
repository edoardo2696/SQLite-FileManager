#ifndef _SQLITE_TEST_MAINFRAME_H
#define _SQLITE_TEST_MAINFRAME_H

#include <wx/wx.h>
#include <wx/toolbar.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/html/htmlwin.h>
#include "About.h"

class SQLiteTestMainFrame : public wxFrame
{	
	wxListBox * GroupsListBox;
	wxListView * ElementsListView;
	wxHtmlWindow * ElementInfoPanel;
	wxHtmlWindow * ElementImagePanel;
    wxHtmlWindow * GroupImagePanel;

	wxToolBarToolBase* About;
    wxToolBarToolBase* SearchElement;

    void CreateControls();
    wxToolBar * CreateToolBar();

	void FillGroupsList();
	void FillElementsList(int groupid);

public:
	SQLiteTestMainFrame();	
	bool Create(wxWindow * parent, wxWindowID id, const wxString & title);

	DECLARE_EVENT_TABLE()
	void OnExit(wxCommandEvent & event);
	void OnGroupListBoxSelected(wxCommandEvent & event);
	void OnElementListViewSelected(wxListEvent & event);
	void OnElementImagePanelLinkClicked(wxHtmlLinkEvent & event);

	void OnSearchElement( wxCommandEvent & event);
    void ShowAboutDialog( wxCommandEvent& event );
	void OnAddGroup(wxCommandEvent & event);
	void OnRemoveGroup(wxCommandEvent & event);

	void OnAddElement(wxCommandEvent & event);
	void OnRemoveElement(wxCommandEvent & event);
    void OnAddGcode(wxCommandEvent & event);
    void OnRemoveGcode(wxCommandEvent & event);
	
	void OnRemoveGroupUpdateUI(wxUpdateUIEvent & event);
	void OnAddElementUpdateUI(wxUpdateUIEvent & event);
	void OnRemoveElementUpdateUI(wxUpdateUIEvent & event);
};

#endif
