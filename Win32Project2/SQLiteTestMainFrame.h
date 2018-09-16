#ifndef _SQLITE_TEST_MAINFRAME_H
#define _SQLITE_TEST_MAINFRAME_H

#include <wx/wx.h>
#include <wx/toolbar.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/html/htmlwin.h>
#include <databaselayer/include/wx/generic/splitter.h>
#include "About.h"

class SQLiteTestMainFrame : public wxFrame
{	
	wxListBox * GroupsListBox;
	wxListView * ElementsListView;
	wxHtmlWindow * ElementInfoPanel;
	wxHtmlWindow * ImagePanel;
    wxHtmlWindow * GroupImagePanel;
	wxSplitterWindow *splitter;
	wxSplitterWindow *ElementInfoSplitter;
	wxSplitterWindow *Groupsplitter;
	wxSplitterWindow *Gcodesplitter;
	wxSplitterWindow *Elementsplitter;

    wxListView * GcodesListView;
	wxToolBarToolBase* About;
    wxToolBarToolBase* SearchElement;

    void CreateControls();
    wxToolBar * CreateToolBar();

	void FillGroupsList();
	void FillElementsList(int groupid);
	void FillGcodesList(int elementid);
public:
	SQLiteTestMainFrame();	
	bool Create(wxWindow * parent, wxWindowID id, const wxString & title);

	DECLARE_EVENT_TABLE()
	void OnExit(wxCommandEvent & event);
	void OnGroupListBoxSelected(wxCommandEvent & event);

	void OnElementListViewSelected(wxListEvent & event);
	void OnElementElementInfoPanelLinkClicked(wxHtmlLinkEvent & event);
	void OnGroupImagePanelLinkClicked(wxHtmlLinkEvent & event);
	void OnGcodeListViewSelected(wxListEvent & event);
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
