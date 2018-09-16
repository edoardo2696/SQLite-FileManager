#ifndef __ELEMENT_
#define __ELEMENT_

#include "wxActiveRecord.h"
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/datetime.h>
#include "Group.h"
#include "Gcode.h"

class Element;
class ElementRow;
class ElementRowSet;

class Group;
class GroupRow;
class GroupRowSet;
class Gcode;
class GcodeRow;
class GcodeRowSet;

class Element: public wxSqliteActiveRecord{
protected:
	ElementRow* RowFromResult(DatabaseResultSet* result);
public:
	Element();
	Element(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	Element(DatabaseLayer* database,const wxString& table);
	bool Create(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	ElementRow* New();
	ElementRow* Id(int key);

	bool Delete(int key);

	ElementRow* Where(const wxString& whereClause);
	ElementRowSet* WhereSet(const wxString& whereClause);
	ElementRowSet* All(); 

};
class ElementRow: public wxActiveRecordRow{
public:
	ElementRow();
	ElementRow(const ElementRow& src);
	ElementRow(Element* activeRecord);
	ElementRow(DatabaseLayer* database,const wxString& table);
	ElementRow& operator=(const ElementRow& src);
	bool GetFromResult(DatabaseResultSet* result);
public:
	int id;
	wxString name;
	wxString description;
	int groupid;
	wxString image;

public:
	GroupRow* GetGroup();
	GcodeRowSet* GetGcodes();

	bool Save();
	bool Delete();


};
class ElementRowSet: public wxActiveRecordRowSet{
public:
	ElementRowSet();
	ElementRowSet(wxActiveRecord* activeRecord);
	ElementRowSet(DatabaseLayer* database,const wxString& table);
	virtual ElementRow* Item(unsigned long item);
	virtual bool SaveAll();
protected:
	static int CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_name(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_description(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_groupid(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_image(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	virtual CMPFUNC_proto GetCmpFunc(const wxString& var) const;

};

#endif