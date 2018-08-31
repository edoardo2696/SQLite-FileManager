#include "SQLiteTestMainFrame.h"
#include "SQLiteTestApp.h"
#include "About.h"
#include "RecordIDClientData.h"
#include "EditGroupDialog.h"
#include "EditElementDialog.h"
#include "SearchElement.h"
#include <wx/splitter.h>


enum
{
	ID_GROUPS_LISTBOX = 10001,

	ID_ELEMENTS_LISTCTRL,
	ID_ELEMENT_INFO_PANEL,
	ID_ADD_GROUP,
	ID_DELETE_GROUP,
	ID_ADD_ELEMENT,
    ID_ADD_GCODE,
    ID_DELETE_GCODE,
	ID_ONABOUT,
    ID_SEARCH_ELEMENT,
	ID_DELETE_ELEMENT,
    ID_ELEMENT_IMAGE_PANEL,
    ID_GCODE_PANEL
};

BEGIN_EVENT_TABLE(SQLiteTestMainFrame, wxFrame)
EVT_MENU(wxID_EXIT, SQLiteTestMainFrame::OnExit)
EVT_LISTBOX(ID_GROUPS_LISTBOX, SQLiteTestMainFrame::OnGroupListBoxSelected)
EVT_LIST_ITEM_SELECTED(ID_ELEMENTS_LISTCTRL, SQLiteTestMainFrame::OnElementListViewSelected)
EVT_HTML_LINK_CLICKED(ID_ELEMENT_IMAGE_PANEL, SQLiteTestMainFrame::OnElementImagePanelLinkClicked)

EVT_MENU(ID_ADD_GROUP, SQLiteTestMainFrame::OnAddGroup)
EVT_MENU(ID_DELETE_GROUP, SQLiteTestMainFrame::OnRemoveGroup)
EVT_MENU(ID_ADD_ELEMENT, SQLiteTestMainFrame::OnAddElement)
EVT_MENU(ID_DELETE_ELEMENT, SQLiteTestMainFrame::OnRemoveElement)
EVT_MENU(ID_ONABOUT, SQLiteTestMainFrame::ShowAboutDialog)
EVT_MENU(ID_SEARCH_ELEMENT, SQLiteTestMainFrame::OnSearchElement)

EVT_UPDATE_UI(ID_DELETE_GROUP, SQLiteTestMainFrame::OnRemoveGroupUpdateUI)
EVT_UPDATE_UI(ID_ADD_ELEMENT, SQLiteTestMainFrame::OnAddElementUpdateUI)
EVT_UPDATE_UI(ID_DELETE_ELEMENT, SQLiteTestMainFrame::OnRemoveElementUpdateUI)
END_EVENT_TABLE()


// FRAME

SQLiteTestMainFrame::SQLiteTestMainFrame()
{
	Create(NULL, wxID_ANY, _("SQLite File Manager"));
}

bool SQLiteTestMainFrame::Create(wxWindow * parent, wxWindowID id, const wxString & title)
{
	bool res = wxFrame::Create(parent, id, title, wxDefaultPosition, wxSize(750, 550));
	if(res)
	{		
		CreateControls();
		FillGroupsList();
	}
	return res;
}

// CREATECONTROLS

void SQLiteTestMainFrame::CreateControls()
{
    {
        wxMenuBar * menuBar = new wxMenuBar;
        SetMenuBar(menuBar);
        wxMenu * fileMenu = new wxMenu;
        fileMenu->Append(wxID_EXIT, _("Exit\tAlt+F4"));
        menuBar->Append(fileMenu, _("File"));
    }

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	wxSplitterWindow * splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(500, 400), wxSP_3DSASH);
	splitter->SetMinimumPaneSize(100);
	sizer->Add(splitter, 1, wxEXPAND);

	wxSplitterWindow * Elementsplitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxSize(500, 400), wxSP_3DSASH);
    Elementsplitter->SetMinimumPaneSize(100);
    wxSplitterWindow * ElementInfoSplitter = new wxSplitterWindow(Elementsplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH);
    ElementInfoSplitter->SetMinimumPaneSize(100);


    GroupsListBox = new wxListBox(splitter, ID_GROUPS_LISTBOX, wxDefaultPosition, wxDefaultSize);
    ElementsListView = new wxListView(Elementsplitter, ID_ELEMENTS_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    {
        ElementsListView->InsertColumn(0, _("id"), wxLIST_FORMAT_LEFT, 120);
        ElementsListView->InsertColumn(1, _("groupid"), wxLIST_FORMAT_LEFT, 110);
        ElementsListView->InsertColumn(2, _("image"), wxLIST_FORMAT_LEFT, 130);

    }

    ElementImagePanel = new wxHtmlWindow(ElementInfoSplitter, ID_ELEMENT_IMAGE_PANEL);
    int fontsizes[] = {6, 8, 9, 10, 12, 16, 18};
    ElementImagePanel->SetFonts(wxT("Tahoma"), wxT("Tahoma"), fontsizes);

    ElementInfoPanel = new wxHtmlWindow(ElementInfoSplitter, ID_ELEMENT_INFO_PANEL);
    ElementInfoPanel->SetFonts(wxT("Tahoma"), wxT("Tahoma"), fontsizes);

    Elementsplitter->SetSashGravity(1.0);
    splitter->SplitVertically(GroupsListBox, Elementsplitter, 160);
    Elementsplitter->SplitHorizontally(ElementsListView, ElementInfoSplitter, Elementsplitter->GetSize().GetHeight());
    ElementInfoSplitter->SplitVertically(ElementInfoPanel, ElementImagePanel, 160);

    SetToolBar(CreateToolBar());

    CreateStatusBar(2);
    Centre();
}

// TOOLBAR

wxToolBar * SQLiteTestMainFrame::CreateToolBar()
{
	wxToolBar * toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, 
		wxDefaultSize, wxTB_FLAT|wxTB_TEXT);
	toolBar->AddTool(ID_ADD_GROUP, "AddGroup",
					 wxArtProvider::GetBitmap(wxART_ADD_BOOKMARK, wxART_FRAME_ICON), wxNullBitmap,
					 wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	toolBar->AddTool(ID_DELETE_GROUP, "RemoveGroup",
					 wxArtProvider::GetBitmap(wxART_DEL_BOOKMARK, wxART_FRAME_ICON), wxNullBitmap,
					 wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	toolBar->AddSeparator();
	toolBar->AddTool(ID_ADD_ELEMENT, "AddElement",
					 wxArtProvider::GetBitmap(wxART_NEW, wxART_FRAME_ICON), wxNullBitmap, wxITEM_NORMAL,
					 wxEmptyString, wxEmptyString, nullptr);
	toolBar->AddTool(ID_DELETE_ELEMENT, "RemoveElement",
					 wxArtProvider::GetBitmap(wxART_DELETE, wxART_FRAME_ICON), wxNullBitmap,
					 wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);
    toolBar->AddSeparator();
    /*toolBar->AddTool(ID_ADD_GCODE, "AddGcode",
                     wxArtProvider::GetBitmap(wxART_NEW_DIR, wxART_FRAME_ICON), wxNullBitmap,
                     wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

    toolBar->AddTool(ID_DELETE_GCODE, "RemoveGcode",
                     wxArtProvider::GetBitmap( wxART_ERROR, wxART_FRAME_ICON), wxNullBitmap,
                     wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);
*/
    SearchElement = toolBar->AddTool( ID_SEARCH_ELEMENT, "SearchElement", wxArtProvider::GetBitmap( wxART_FIND, wxART_FRAME_ICON ), wxNullBitmap,
                                      wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr );
	About = toolBar->AddTool( ID_ONABOUT, "About", wxArtProvider::GetBitmap( wxART_HELP_SIDE_PANEL, wxART_FRAME_ICON ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	toolBar->Realize();
	return toolBar;
}

// FILLGROUPLIST

void SQLiteTestMainFrame::FillGroupsList()
{	
	GroupsListBox->Freeze();
	GroupsListBox->Clear();	
	GroupRowSet * allGroups = wxGetApp().GetGroupTable()->All();
	for(unsigned long i = 0; i < allGroups->Count(); ++i)
	{
		GroupsListBox->Append(allGroups->Item(i)->name,
		        new RecordIDClientData(allGroups->Item(i)->id));
	}
	if(GroupsListBox->GetCount())
	{		
		GroupsListBox->SetSelection(0);
		RecordIDClientData * data = (RecordIDClientData *)
			GroupsListBox->GetClientObject(GroupsListBox->GetSelection());
		if(data)
		{

			FillElementsList(data->GetID());
		}
	}
	GroupsListBox->Thaw();
}

// FILLELEMENTLIST

void SQLiteTestMainFrame::FillElementsList(int groupid)
{
	ElementsListView->Freeze();
	ElementsListView->DeleteAllItems();
	GroupRow * thisGroup = wxGetApp().GetGroupTable()->Id(groupid);
	if(thisGroup)
	{
		ElementRowSet * allElements = thisGroup->GetElements();
		long item(0);
		for(unsigned long i = 0; i < allElements->Count(); ++i)
		{
            item = ElementsListView->InsertItem(item, allElements->Item(i)->id);

            ElementsListView->SetItem(item, 2, allElements->Item(i)->image);
            ElementsListView->SetItem(item, 1, wxString::Format(wxT("%i"),allElements->Item(i)->groupid));
            ElementsListView->SetItem(item, 0, wxString::Format(wxT("%i"),allElements->Item(i)->id));
            ElementsListView->SetItemData(item, (long)allElements->Item(i)->id);
		}
		if(ElementsListView->GetItemCount())
		{
			ElementsListView->Select(0);
		}
		else
		{
			ElementInfoPanel->SetPage(wxT("<html><body></body></html>"));
		}
	}
	ElementsListView->Thaw();
}

// ONGROUPLISTBOXSELECTED

void SQLiteTestMainFrame::OnGroupListBoxSelected(wxCommandEvent & event)
{
	RecordIDClientData * data = (RecordIDClientData *)event.GetClientObject();
	if(data)
	{
	    FillElementsList(data->GetID());
     }


}

// ONELEMENTLISTVIEWSELECTED


void SQLiteTestMainFrame::OnElementListViewSelected(wxListEvent & event)
{
	long Elementid = event.GetData();
	ElementRow * Element = wxGetApp().GetElementTable()->Id((int)Elementid);
	if(Element)
	{
		ElementInfoPanel->SetPage(wxString::Format(
			wxT("<html><body><h3>%d</h3></body></html>"),
			Element->id));

        ElementImagePanel->SetPage(wxString::Format(
                wxT("<html><body></body></html>")));


        ElementImagePanel->AppendToPage(wxString::Format(
                wxT("<b>Image:</b> <a href=\"%s\" ><img height=\"400\" width=\"400\"  src=\"%s\"/></a><br>"),
                Element->image.GetData(), Element->image.GetData()));
	}
	else
	{
		ElementInfoPanel->SetPage(
			_("<html><body><h3>Can't find info about selected Element</h3></body></html>"));
	}
}

// HTML PANEL

void SQLiteTestMainFrame::OnElementImagePanelLinkClicked(wxHtmlLinkEvent & event)
{
#if defined(__WXMSW__)
	ShellExecute(nullptr, nullptr, event.GetLinkInfo().GetHref().GetData(),
                 nullptr, nullptr, SW_SHOW);
#else
	wxExecute(event.GetLinkInfo().GetHref());
#endif
}

// ADD GROUP BUTTON

void SQLiteTestMainFrame::OnAddGroup(wxCommandEvent & event)
{
	EditGroupDialog * dlg = new EditGroupDialog(this);
	if(dlg->ShowModal() == wxID_OK)
	{
		GroupRow * newGroup = wxGetApp().GetGroupTable()->New();
		newGroup->name = dlg->GetGroupName();
		newGroup->description = dlg->GetGroupDescription();
		newGroup->Save();
		FillGroupsList();
	}
	dlg->Destroy();
}

//REMOVE GROUP BUTTON

void SQLiteTestMainFrame::OnRemoveGroup(wxCommandEvent & event)
{
	int selection = GroupsListBox->GetSelection();
	RecordIDClientData * data = (RecordIDClientData *)
		GroupsListBox->GetClientObject(selection);
	if(data)
	{
		GroupRow * thisGroup = wxGetApp().GetGroupTable()->Id(data->GetID());
		if(thisGroup && (wxMessageBox(_("Do you really want to delete this group?"),
			_("Delete group"), wxYES_NO) == wxYES))
		{
			ElementRowSet * thisElements = thisGroup->GetElements();
			for(unsigned long i = 0; i < thisElements->Count(); ++i)
			{
				thisElements->Item(i)->Delete();
			}
			thisGroup->Delete();
			GroupsListBox->Delete(selection);
			if(GroupsListBox->GetCount())
			{
				GroupsListBox->SetSelection(selection <
					(int)GroupsListBox->GetCount() ? selection : 0);
				data = (RecordIDClientData *)GroupsListBox->GetClientObject(
					GroupsListBox->GetSelection());
				if(data)
				{
					FillElementsList(data->GetID());
				}
			}
		}
	}
}

//ADD ELEMENT BUTTON

void SQLiteTestMainFrame::OnAddElement(wxCommandEvent & event)
{
	RecordIDClientData * data = (RecordIDClientData *)
		GroupsListBox->GetClientObject(GroupsListBox->GetSelection());
	if(data)
	{
		GroupRow * thisGroup = wxGetApp().GetGroupTable()->Id(data->GetID());
		if(thisGroup)
		{
			EditElementDialog * dlg = new EditElementDialog(this);
			if(dlg->ShowModal() == wxID_OK)
			{
				ElementRow * newElement = wxGetApp().GetElementTable()->New();
				newElement->groupid= thisGroup->id;

				newElement->Save();
				FillElementsList(thisGroup->id);
			}
			dlg->Destroy();
		}
	}
}

// REMOVE ELEMENT BUTTON

void SQLiteTestMainFrame::OnRemoveElement(wxCommandEvent & event)
{
	long selection = ElementsListView->GetFirstSelected();
	ElementRow * thisElement = wxGetApp().GetElementTable()->Id(
		(int)ElementsListView->GetItemData(selection));
	if(thisElement && (wxMessageBox(_("Do you really want to delete this record?"), 
		_("Delete Element"), wxYES_NO) == wxYES))
	{
		int groupid = thisElement->groupid;
		thisElement->Delete();
		ElementsListView->DeleteItem(selection);
		if(ElementsListView->GetItemCount())
		{
			ElementsListView->Select(wxMin(selection, ElementsListView->GetItemCount()-1));
		}
	}
}

// ABOUT BUTTON

void SQLiteTestMainFrame::ShowAboutDialog(wxCommandEvent &event) {
    DialogAbout about_dialog(this);
    about_dialog.ShowModal();
}


// UPDATE INFO

void SQLiteTestMainFrame::OnRemoveGroupUpdateUI(wxUpdateUIEvent & event)
{
	event.Enable(GroupsListBox->GetSelection() >= 0);
}

void SQLiteTestMainFrame::OnAddElementUpdateUI(wxUpdateUIEvent & event)
{
	event.Enable(GroupsListBox->GetSelection() >= 0);
}

void SQLiteTestMainFrame::OnRemoveElementUpdateUI(wxUpdateUIEvent & event)
{
	event.Enable(ElementsListView->GetFirstSelected() >= 0);
}

void SQLiteTestMainFrame::OnExit(wxCommandEvent & event)
{
	wxUnusedVar(event);
	Close();
}

void SQLiteTestMainFrame::OnSearchElement(wxCommandEvent &event) {
 SearchDialog about_dialog(this);
    about_dialog.ShowModal();

}

