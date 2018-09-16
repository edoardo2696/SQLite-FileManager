#include <wx/image.h>
#include <DatabaseLayerException.h>
#include "SqlUnitTest.h"
#include "SQLiteTestMainFrame.h"

IMPLEMENT_APP(SqlUnitTest)

bool SqlUnitTest::OnInit()
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

int SqlUnitTest::OnExit()
{
	wxDELETE(ElementTable);
	wxDELETE(GroupTable);
	wxDELETE(GcodeTable);
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

bool SqlUnitTest::ConnectToDatabase()
{
    Database = new SqliteDatabaseLayer();
	wxString db_name("SQLiteFileManager.db");
	PreparedStatement * Statement(nullptr);
	bool Create = !wxFileExists(db_name);
	if(Create)
	{
		wxMessageBox(_("Database does not exist... recreating."));
	}
	try
	{
        Database->Open(db_name);

		try
		{
            Database->RunQuery(wxT("CREATE TABLE groups (id INTEGER PRIMARY KEY NOT NULL UNIQUE,"
								   " code VARCHAR(128) NOT NULL UNIQUE,"
		                           " name VARCHAR(128)  UNIQUE,"
	                               " description VARCHAR(512),"
                                   " image VARCHAR(128))"));
		}
		catch(DatabaseLayerException & e) {wxUnusedVar(e);}
		try
		{
            Database->RunQuery(wxT("CREATE TABLE elements (id INTEGER PRIMARY KEY NOT NULL UNIQUE,"
								   " name VARCHAR(128) NOT NULL UNIQUE,"
		                           " description VARCHAR(512),"
							       " groupid INTEGER NOT NULL REFERENCES groups (id),"
			                       " image VARCHAR(128))"));
		}
        catch(DatabaseLayerException & e) {wxUnusedVar(e);}
      try {
          Database->RunQuery(
                  wxT("CREATE TABLE gcodes (id INTEGER PRIMARY KEY NOT NULL UNIQUE,"
					  " elementid INTEGER NOT NULL REFERENCES elements (id),"
	                  " code  VARCHAR(128) NOT NULL UNIQUE)"));

          }
        catch(DatabaseLayerException & e) {wxUnusedVar(e);}

	}

	catch(DatabaseLayerException & e)
	{
		wxUnusedVar(e);
		if(Statement)
		{
            Database->CloseStatement(Statement);
			Statement = nullptr;
		}
		wxFAIL_MSG(e.GetErrorMessage());
		return false;
	}
	try
	{
        GroupTable = new Group(wxGetApp().GetDatabase(), "groups");
		ElementTable = new Element(wxGetApp().GetDatabase(), "elements");
        GcodeTable = new Gcode(wxGetApp().GetDatabase(), "gcodes");

	}
	catch(DatabaseLayerException & e)
	{
		wxActiveRecord::ProcessException(e);
	}
	return true;
}

DatabaseLayer * SqlUnitTest::GetDatabase()
{
	return Database;
}

Group * SqlUnitTest::GetGroupTable()
{
	return GroupTable;
}

Element * SqlUnitTest::GetElementTable()
{
	return ElementTable;
}

Gcode *SqlUnitTest::GetGcodeTable() {
    return GcodeTable;
}
