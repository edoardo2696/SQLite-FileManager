#ifndef __GROUP_
#define __GROUP_
#include "wxActiveRecord.h"
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/datetime.h>
#include "Element.h"

class Group;
class GroupRow;
class GroupRowSet;

class Element;
class ElementRow;
class ElementRowSet;

class Group: public wxSqliteActiveRecord
		{
protected:
	GroupRow* RowFromResult(DatabaseResultSet* result);
public:
	Group();
	Group(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	Group(DatabaseLayer* database,const wxString& table);
	bool Create(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	GroupRow* New();
	GroupRow* Id(int key);

	bool Delete(int key);

	GroupRow* Where(const wxString& whereClause);
	GroupRowSet* WhereSet(const wxString& whereClause);
	GroupRowSet* All(); 

};
class GroupRow: public wxActiveRecordRow{
public:
	GroupRow();
	GroupRow(const GroupRow& src);
	GroupRow(Group* activeRecord);
	GroupRow(DatabaseLayer* database,const wxString& table);
	GroupRow& operator=(const GroupRow& src);
	bool GetFromResult(DatabaseResultSet* result);
public:
	wxString name;
	wxString description;
	wxString image;
	wxString code;
	int id;

public:
	ElementRowSet* GetElements();

	bool Save();
	bool Delete();

};
class GroupRowSet: public wxActiveRecordRowSet{
public:
	GroupRowSet();
	GroupRowSet(wxActiveRecord* activeRecord);
	GroupRowSet(DatabaseLayer* database,const wxString& table);
	virtual GroupRow* Item(unsigned long item);
	virtual bool SaveAll();
protected:
	static int CMPFUNC_name(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_description(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
    static int CMPFUNC_image(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_code(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	virtual CMPFUNC_proto GetCmpFunc(const wxString& var) const;

};

#endif