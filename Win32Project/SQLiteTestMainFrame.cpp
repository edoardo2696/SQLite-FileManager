#include "SQLiteTestMainFrame.h"

#include "About.h"
#include "RecordIDClientData.h"
#include "EditGroupDialog.h"
#include "EditElementDialog.h"
#include "EditGcodeDialog.h"
#include "Element.h"

#include <wx/splitter.h>
#include <SqlUnitTest.h>


enum
{
	ID_GROUPS_LISTBOX = 10001,

	ID_ELEMENTS_LISTCTRL,
	ID_INFO_PANEL,
	ID_ADD_GROUP,
	ID_DELETE_GROUP,
	ID_GCODES_LISTCTRL,
	ID_ADD_ELEMENT,
    ID_ADD_GCODE,
    ID_DELETE_GCODE,
	ID_ONABOUT,
    ID_DELETE_ELEMENT,
    ID_ELEMENT_IMAGE_PANEL,
    ID_GROUP_IMAGE_PANEL,
    ID_ONSEARCH
};

BEGIN_EVENT_TABLE(SQLiteTestMainFrame, wxFrame)
EVT_MENU(wxID_EXIT, SQLiteTestMainFrame::OnExit)
EVT_LISTBOX(ID_GROUPS_LISTBOX, SQLiteTestMainFrame::OnGroupListBoxSelected)
EVT_LIST_ITEM_SELECTED(ID_ELEMENTS_LISTCTRL, SQLiteTestMainFrame::OnElementListViewSelected)
EVT_LIST_ITEM_SELECTED(ID_GCODES_LISTCTRL, SQLiteTestMainFrame::OnGcodeListViewSelected)
EVT_HTML_LINK_CLICKED(ID_ELEMENT_IMAGE_PANEL, SQLiteTestMainFrame::OnImagePanelLinkClicked)
EVT_HTML_LINK_CLICKED(ID_INFO_PANEL, SQLiteTestMainFrame::OnInfoPanelLinkClicked)
EVT_HTML_LINK_CLICKED(ID_GROUP_IMAGE_PANEL, SQLiteTestMainFrame::OnGroupImagePanelLinkClicked)

EVT_MENU(ID_ADD_GROUP, SQLiteTestMainFrame::OnAddGroup)
EVT_MENU(ID_DELETE_GROUP, SQLiteTestMainFrame::OnRemoveGroup)
EVT_MENU(ID_ADD_ELEMENT, SQLiteTestMainFrame::OnAddElement)
EVT_MENU(ID_DELETE_ELEMENT, SQLiteTestMainFrame::OnRemoveElement)
EVT_MENU(ID_ADD_GCODE, SQLiteTestMainFrame::OnAddGcode)
EVT_MENU(ID_DELETE_GCODE, SQLiteTestMainFrame::OnRemoveGcode)
EVT_MENU(ID_ONABOUT, SQLiteTestMainFrame::ShowAboutDialog)


EVT_UPDATE_UI(ID_DELETE_GROUP, SQLiteTestMainFrame::OnRemoveGroupUpdateUI)
EVT_UPDATE_UI(ID_ADD_ELEMENT, SQLiteTestMainFrame::OnAddElementUpdateUI)
EVT_UPDATE_UI(ID_DELETE_ELEMENT, SQLiteTestMainFrame::OnRemoveElementUpdateUI)
EVT_UPDATE_UI(ID_DELETE_GCODE, SQLiteTestMainFrame::OnRemoveGcodeUpdateUI)
END_EVENT_TABLE()




SQLiteTestMainFrame::SQLiteTestMainFrame()
{
	Create(NULL, wxID_ANY, _("SQLite File Manager"));
}

bool SQLiteTestMainFrame::Create(wxWindow * parent, wxWindowID id, const wxString & title)
{
	bool res = wxFrame::Create(parent, id, title, wxDefaultPosition, wxSize(1000, 800));
	if(res)
	{		
		CreateControls();
		FillGroupsList();
	}
	return res;
}

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
    {
        splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(400, 300), wxSP_3DSASH);
        splitter->SetMinimumPaneSize(100);
        sizer->Add(splitter, 1, wxEXPAND);

        Elementsplitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxSize(400, 300), wxSP_3DSASH);
        Elementsplitter->SetMinimumPaneSize(100);

        Groupsplitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize,  wxSP_3DSASH);
        Groupsplitter->SetMinimumPaneSize(100);

        Gcodesplitter = new wxSplitterWindow(Elementsplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH);
        Gcodesplitter->SetMinimumPaneSize(100);

        ElementInfoSplitter = new wxSplitterWindow(Elementsplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH);
        ElementInfoSplitter->SetMinimumPaneSize(100);
    }
    {
        GroupsListBox = new wxListBox(Groupsplitter, ID_GROUPS_LISTBOX, wxDefaultPosition, wxDefaultSize);

        GcodesListView = new wxListView(Gcodesplitter, ID_GCODES_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
        {
            GcodesListView->InsertColumn(0, _("elementid"), wxLIST_FORMAT_CENTER, 80);
            GcodesListView->InsertColumn(1, _("code"), wxLIST_FORMAT_CENTER, 85);
        }
        ElementsListView = new wxListView(Gcodesplitter, ID_ELEMENTS_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
        {
            ElementsListView->InsertColumn(0, _("id"), wxLIST_FORMAT_CENTRE, 40);
            ElementsListView->InsertColumn(1, _("name"), wxLIST_FORMAT_CENTER, 50);
            ElementsListView->InsertColumn(2, _("description"), wxLIST_FORMAT_CENTER, 100);
            ElementsListView->InsertColumn(3, _("groupid"), wxLIST_FORMAT_CENTER, 75);
            ElementsListView->InsertColumn(4, _("image"), wxLIST_FORMAT_LEFT, 800);

        }
    }
    {
        GroupImagePanel = new wxHtmlWindow(Groupsplitter, ID_GROUP_IMAGE_PANEL);
        int fontsizes[] = {6, 8, 9, 10, 12, 16, 18};
        GroupImagePanel->SetFonts(wxT("Tahoma"), wxT("Tahoma"), fontsizes);

        ImagePanel = new wxHtmlWindow(ElementInfoSplitter, ID_ELEMENT_IMAGE_PANEL);
        ImagePanel->SetFonts(wxT("Tahoma"), wxT("Tahoma"), fontsizes);

        InfoPanel = new wxHtmlWindow(ElementInfoSplitter, ID_INFO_PANEL);
        InfoPanel->SetFonts(wxT("Tahoma"), wxT("Tahoma"), fontsizes);
    }
    {
        Groupsplitter->SplitHorizontally(GroupsListBox, GroupImagePanel, 160);
        Gcodesplitter->SplitVertically(ElementsListView, GcodesListView, 300);
        Elementsplitter->SetSashGravity(1.0);
        splitter->SplitVertically(Groupsplitter, Elementsplitter, 350);
        Elementsplitter->SplitHorizontally(Gcodesplitter, ElementInfoSplitter,88);
        ElementInfoSplitter->SplitVertically(InfoPanel, ImagePanel, 350);
    }
    SetToolBar(CreateToolBar());

    CreateStatusBar(2);
    Centre();
}

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
    toolBar->AddTool(ID_ADD_GCODE, "AddGcode",
                     wxArtProvider::GetBitmap(wxART_NEW_DIR, wxART_FRAME_ICON), wxNullBitmap,
                     wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

    toolBar->AddTool(ID_DELETE_GCODE, "RemoveGcode",
                     wxArtProvider::GetBitmap( wxART_ERROR, wxART_FRAME_ICON), wxNullBitmap,
                     wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	About = toolBar->AddTool( ID_ONABOUT, "About", wxArtProvider::GetBitmap( wxART_HELP_SIDE_PANEL, wxART_FRAME_ICON ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	toolBar->Realize();
	return toolBar;
}

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

            ElementsListView->SetItem(item, 4, allElements->Item(i)->image);
            ElementsListView->SetItem(item, 3, wxString::Format(wxT("%i"),allElements->Item(i)->groupid));
			ElementsListView->SetItem(item, 2, allElements->Item(i)->description);
            ElementsListView->SetItem(item, 1, allElements->Item(i)->name);
            ElementsListView->SetItem(item, 0, wxString::Format(wxT("%i"),allElements->Item(i)->id));
            ElementsListView->SetItemData(item, (long)allElements->Item(i)->id);
		}
		if(ElementsListView->GetItemCount())
		{
			ElementsListView->Select(0);
            RecordIDClientData * data = (RecordIDClientData *)
                    ElementsListView->GetClientObject(0);
            if(data)
            {

                FillGcodesList(data->GetID());
            }
		}
		else
		{
            InfoPanel->SetPage(wxT("<html><body></body></html>"));
		}
	}
	ElementsListView->Thaw();
}

void SQLiteTestMainFrame::FillGcodesList(int elementid)
{
    GcodesListView->Freeze();
    GcodesListView->DeleteAllItems();

    ElementRow * thisElement = wxGetApp().GetElementTable()->Id(elementid);
    if(thisElement)
    {
        GcodeRowSet * allGcodes = thisElement->GetGcodes();
        long item(0);
        for(unsigned long i = 0; i < allGcodes->Count(); ++i)
        { item = GcodesListView->InsertItem(item, allGcodes->Item(i)->id);
            GcodesListView->SetItem(item, 1, allGcodes->Item(i)->code);
            GcodesListView->SetItem(item, 0, wxString::Format(wxT("%i"),allGcodes->Item(i)->elementid));
            GcodesListView->SetItemData(item, (long)allGcodes->Item(i)->id);
        }

    } GcodesListView->Thaw();
}

void SQLiteTestMainFrame::OnGroupListBoxSelected(wxCommandEvent & event)
{

	RecordIDClientData * data = (RecordIDClientData *)event.GetClientObject();
	if(data)
	{
	    FillElementsList(data->GetID());
     }
    GroupRow * Group = wxGetApp().GetGroupTable()->Id(data->GetID());
    if(Group) {
        GroupImagePanel->SetPage(wxString::Format(
                wxT("<html><body><h3>%d</h3></body></html>")));
        GroupImagePanel->AppendToPage(wxString::Format(
                wxT("<b>Code:</b> %s<br>"),
                Group->code.GetData()));
        GroupImagePanel->AppendToPage(wxString::Format(
                wxT("<b>Name:</b> %s<br>"),
                Group->name.GetData()));
        GroupImagePanel->AppendToPage(wxString::Format(
                wxT("<b>Description:</b> %s<br>"),
                Group->description.GetData()));
        GroupImagePanel->AppendToPage(wxT("<hr>"));
        GroupImagePanel->AppendToPage(wxString::Format(
                wxT("<b>Image:</b> <a href=\"%s\" ><img height=\"300\" width=\"300\"  src=\"%s\"/></a><br>"),
                Group->image.GetData(), Group->image.GetData()));
    }
}

void SQLiteTestMainFrame::OnElementListViewSelected(wxListEvent & event)
{   long selection = ElementsListView->GetFirstSelected();
    if(selection != -1)
    {
        FillGcodesList((int)event.GetData());
    }
	long Elementid = event.GetData();
	ElementRow * Element = wxGetApp().GetElementTable()->Id((int)Elementid);
	if(Element)
	{
        InfoPanel->SetPage(wxString::Format(
			wxT("<html><body><h3>%d</h3></body></html>")));

        InfoPanel->AppendToPage(wxString::Format(
                wxT("<b>Groupid:</b> %d<br>"),
                Element->groupid));
        InfoPanel->AppendToPage(wxString::Format(
                wxT("<b>Name:</b> %s<br>"),
                Element->name.GetData()));
        InfoPanel->AppendToPage(wxString::Format(
                wxT("<b>Description:</b> %s<br>"),
                Element->description.GetData()));
        InfoPanel->AppendToPage(wxT("<hr>"));
        InfoPanel->AppendToPage(wxString::Format(
                wxT("<b>Image:</b> <a href=\"%s\" ><img height=\"300\" width=\"300\"  src=\"%s\"/></a><br>"),
                Element->image.GetData(), Element->image.GetData()));
	}
	else
	{
        InfoPanel->SetPage(
			_("<html><body><h3>Can't find info about selected Element</h3></body></html>"));
	}

}

void SQLiteTestMainFrame::OnGcodeListViewSelected(wxListEvent & event)
{
    long GcodeId = event.GetData();
    GcodeRow * Gcode = wxGetApp().GetGcodeTable()->Id((int)GcodeId);
    if(Gcode)
    {   ImagePanel->SetPage(wxString::Format(
                wxT("<html><body></body></html>")));

        ImagePanel->AppendToPage(wxString::Format(
                wxT("<b>TXT:</b><a href=\"%s\">%s</a><br>"),
                Gcode->code.GetData(), Gcode->code.GetData()));
    }
    else
    {
        ImagePanel->SetPage(
                _("<html><body><h3>Can't find info about selected Gcode</h3></body></html>"));
    }
}




void SQLiteTestMainFrame::OnGroupImagePanelLinkClicked(wxHtmlLinkEvent & event)
{
#if defined(__WXMSW__)
    ShellExecute(nullptr, nullptr, event.GetLinkInfo().GetHref().GetData(),
                 nullptr, nullptr, SW_SHOW);
#else
    wxExecute(event.GetLinkInfo().GetHref());
#endif
}

void SQLiteTestMainFrame::OnImagePanelLinkClicked(wxHtmlLinkEvent & event)
{
#if defined(__WXMSW__)
	ShellExecute(nullptr, nullptr, event.GetLinkInfo().GetHref().GetData(),
                 nullptr, nullptr, SW_SHOW);
#else
	wxExecute(event.GetLinkInfo().GetHref());
#endif
}

void SQLiteTestMainFrame::OnInfoPanelLinkClicked(wxHtmlLinkEvent & event)
{
#if defined(__WXMSW__)
    ShellExecute(nullptr, nullptr, event.GetLinkInfo().GetHref().GetData(),
                 nullptr, nullptr, SW_SHOW);
#else
    wxExecute(event.GetLinkInfo().GetHref());
#endif
}




void SQLiteTestMainFrame::OnAddGroup(wxCommandEvent & event)
{
    EditGroupDialog * dlg = new EditGroupDialog(this);
    if(dlg->ShowModal() == wxID_OK)
    {
        GroupRow * newGroup = wxGetApp().GetGroupTable()->New();
        newGroup->code = dlg->GetGroupCode();
        newGroup->name = dlg->GetGroupName();
        newGroup->description = dlg->GetGroupDescription();
        newGroup->image = dlg->GetImage();
        newGroup->Save();
        FillGroupsList();
    }
    dlg->Destroy();
}

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
                GroupsListBox->SetSelection(selection < (int)GroupsListBox->GetCount() ? selection : 0);
                data = (RecordIDClientData *)GroupsListBox->GetClientObject(GroupsListBox->GetSelection());
                if(data)
                {
                    FillElementsList(data->GetID());
                }
            }
        }
    }
}

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
                newElement->name= dlg->GetName();
                newElement->description= dlg->GetDescription();
                newElement->image = dlg->GetImage();
                newElement->Save();
                FillElementsList(thisGroup->id);
            }
            dlg->Destroy();
        }
    }
}

void SQLiteTestMainFrame::OnRemoveElement(wxCommandEvent & event)
{
    long selection = ElementsListView->GetFirstSelected();
    ElementRow * thisElement = wxGetApp().GetElementTable()->Id(
            (int)ElementsListView->GetItemData(selection));
    if(thisElement && (wxMessageBox(_("Do you really want to delete this record?"),
                                    _("Delete Element"), wxYES_NO) == wxYES))
    {
        GcodeRowSet * thisGcodes = thisElement->GetGcodes();
        for(unsigned long i = 0; i < thisGcodes->Count(); ++i)
        {
            thisGcodes->Item(i)->Delete();
        }
        thisElement->Delete();
        ElementsListView->DeleteItem(selection);
        if(ElementsListView->GetItemCount())
        {
            ElementsListView->Select(wxMin(selection, ElementsListView->GetItemCount()-1));
        }
    }
}

void SQLiteTestMainFrame::OnAddGcode(wxCommandEvent & event)
{
    long selection = ElementsListView->GetFirstSelected();

    if(selection != -1)
    {
        ElementRow * thisElement = wxGetApp().GetElementTable()->Id(
                (int)ElementsListView->GetItemData(selection));
        if(thisElement)
        {
            EditGcodeDialog * dlg = new EditGcodeDialog(this);
            if(dlg->ShowModal() == wxID_OK)
            {
                GcodeRow * newGcode = wxGetApp().GetGcodeTable()->New();

                newGcode->elementid= thisElement->id;
                newGcode->code= dlg->GetCode();
                newGcode->Save();
                FillGcodesList(thisElement->id);
            }
            dlg->Destroy();
        }
    }

}


void SQLiteTestMainFrame::OnRemoveGcode(wxCommandEvent & event)
{
    long selection = GcodesListView->GetFirstSelected();
    GcodeRow * thisGcodes = wxGetApp().GetGcodeTable()->Id(GcodesListView->GetId());
    if(thisGcodes && (wxMessageBox(_("Do you really want to delete this record?"),
                                    _("Delete Element"), wxYES_NO) == wxYES))
    {
        thisGcodes->Delete();

        GcodesListView->DeleteItem(selection);
        if(GcodesListView->GetItemCount())
        {
            GcodesListView->Select(wxMin(selection, GcodesListView->GetItemCount()-1));
        }
    }

}





void SQLiteTestMainFrame::ShowAboutDialog(wxCommandEvent &event)
{
    DialogAbout about_dialog(this);
    about_dialog.ShowModal();
}

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

void SQLiteTestMainFrame::OnRemoveGcodeUpdateUI(wxUpdateUIEvent & event)
{
    event.Enable(GcodesListView->GetFirstSelected() >= 0);
}
void SQLiteTestMainFrame::OnExit(wxCommandEvent & event)
{
	wxUnusedVar(event);
	Close();
}
