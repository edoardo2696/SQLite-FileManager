#include <wx/image.h>
#include <DatabaseLayerException.h>
#include "SQLiteTestApp.h"
#include "SQLiteTestMainFrame.h"

IMPLEMENT_APP(SQLiteTestApp)

bool SQLiteTestApp::OnInit()
{
	if(!ConnectToDatabase())
	{
		wxFAIL_MSG(_("Error connecting to database!"));
		return false;
	}
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxJPEGHandler);

    auto * frame = new SQLiteTestMainFrame;
	SetTopWindow(frame);
	frame->Show();

	return true;
}

int SQLiteTestApp::OnExit()
{
	wxDELETE(ElementTable);
	wxDELETE(GroupTable);
	if(Database)
	{
		if(Database->IsOpen())
		{
            Database->Close();
		}
		wxDELETE(Database);
	}
	return wxApp::OnExit();
}

bool SQLiteTestApp::ConnectToDatabase()
{
    Database = new SqliteDatabaseLayer();
	wxString db_filename(wxT("SQLiteFileManager.db"));
	PreparedStatement * pStatement(nullptr);
	bool bCreate = !wxFileExists(db_filename);
	if(bCreate)
	{
		wxMessageBox(_("Database does not exist... recreating."));
	}
	try
	{
        Database->Open(db_filename);

		try
		{
            Database->RunQuery(wxT("CREATE TABLE groups (id INTEGER PRIMARY KEY NOT NULL UNIQUE, name VARCHAR(128) NOT NULL UNIQUE, description VARCHAR(512))"));
		}
		catch(DatabaseLayerException & e) {wxUnusedVar(e);}
		try
		{
            Database->RunQuery(wxT("CREATE TABLE elements (id INTEGER PRIMARY KEY NOT NULL UNIQUE, groupid INTEGER NOT NULL REFERENCES groups (id), image VARCHAR(128), gcode VARCHAR(128))"));
		}
        catch(DatabaseLayerException & e) {wxUnusedVar(e);}
      // try
      //  {
      //     Database->RunQuery(wxT("CREATE TABLE gcode (elementid INTEGER PRIMARY KEY NOT NULL UNIQUE, gcode  VARCHAR(128))"));
      //  }
      //  catch(DatabaseLayerException & e) {wxUnusedVar(e);}
		if(bCreate)
		{
            Database->RunQuery(
				wxT("INSERT INTO groups(id, name, description) VALUES (1, 'Group', 'My groups')"));
			pStatement = Database->PrepareStatement(
				wxT("INSERT INTO elements(id, groupid, image, gcode) VALUES (?,?,?,?)"));
          //  pStatement = Database->PrepareStatement(
          //          wxT("INSERT INTO gcode(elementid, gcode) VALUES (?,?)"));
			if (pStatement)
			{
				pStatement->SetParamInt(1, 1);
				pStatement->SetParamInt(2, 1);
				pStatement->SetParamString(3, "5822091.8_8.jpg");
                pStatement->SetParamInt(4, 1);

				pStatement->RunQuery();
                Database->CloseStatement(pStatement);
				pStatement = nullptr;
			}

		}
	}
	catch(DatabaseLayerException & e)
	{
		wxUnusedVar(e);
		if(pStatement) 
		{
            Database->CloseStatement(pStatement);
			pStatement = nullptr;
		}
		wxFAIL_MSG(e.GetErrorMessage());
		return false;
	}
	try
	{
        GroupTable = new Group(wxGetApp().GetDatabase(), wxT("groups"));
		ElementTable = new Element(wxGetApp().GetDatabase(), wxT("elements"));

	}
	catch(DatabaseLayerException & e)
	{
		wxActiveRecord::ProcessException(e);
	}
	return true;
}

DatabaseLayer * SQLiteTestApp::GetDatabase()
{
	return Database;
}

Group * SQLiteTestApp::GetGroupTable()
{
	return GroupTable;
}

Element * SQLiteTestApp::GetElementTable()
{
	return ElementTable;
}
