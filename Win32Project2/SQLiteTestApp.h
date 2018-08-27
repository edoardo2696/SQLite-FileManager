#ifndef _SQLITE_TEST_APP_H
#define _SQLITE_TEST_APP_H

#include <wx/wx.h>
#include <DatabaseLayer.h>
#include <SqliteDatabaseLayer.h>
#include "Group.h"
#include "Element.h"

class SQLiteTestApp : public wxApp
{
	Group * GroupTable;
	Element * ElementTable;

	DatabaseLayer * Database;
public:
	virtual bool OnInit();
	virtual int OnExit();

	bool ConnectToDatabase();
	DatabaseLayer * GetDatabase();

	Group * GetGroupTable();
	Element * GetElementTable();

};

DECLARE_APP(SQLiteTestApp)

#endif