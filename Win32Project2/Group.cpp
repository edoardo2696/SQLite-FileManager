#include "Group.h"

Group::Group():wxSqliteActiveRecord(){
}

Group::Group(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password):wxSqliteActiveRecord(table,name,server,user,password){
}

Group::Group(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Group::Create(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password){
	return wxSqliteActiveRecord::Create(table,name,server,user,password);
}

GroupRow* Group::RowFromResult(DatabaseResultSet* result){
	GroupRow* row=new GroupRow(this);
	
	row->GetFromResult(result);
	
	return row;
}

GroupRow* Group::New(){
	GroupRow* newRow=new GroupRow(this);
	garbageRows.Add(newRow);
	return newRow;
}

GroupRow* Group::Id(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format("SELECT * FROM %s WHERE id=?",m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		GroupRow* row=RowFromResult(result);
		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return NULL;
	}
}


bool Group::Delete(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}


GroupRow* Group::Where(const wxString& whereClause){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str()));
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		GroupRow* row=RowFromResult(result);

		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}

GroupRowSet* Group::WhereSet(const wxString& whereClause){
	GroupRowSet* rowSet=new GroupRowSet();
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str()));
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}

		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return rowSet;

	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}


GroupRowSet* Group::All(){
	GroupRowSet* rowSet=new GroupRowSet();
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s"),m_table.c_str()));
		DatabaseResultSet* result= pStatement->ExecuteQuery();
		
		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}
		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);	
		return rowSet;
		
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}


GroupRow::GroupRow():wxActiveRecordRow(){
	bool newRow=true;
}

GroupRow::GroupRow(Group* activeRecord):wxActiveRecordRow(activeRecord){
	bool newRow=true;
}

GroupRow::GroupRow(const GroupRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;
	
	name=src.name;
	description=src.description;
	image=src.image;
	id=src.id;

}

GroupRow::GroupRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}
	

GroupRow& GroupRow::operator=(const GroupRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;
	
	name=src.name;
	description=src.description;
	image=src.image;
	id=src.id;


	return *this;
}

bool GroupRow::GetFromResult(DatabaseResultSet* result){
	
	newRow=false;
		name=result->GetResultString("name");
	description=result->GetResultString("description");
	image=result->GetResultString("image");
	id=result->GetResultInt("id");


	return true;
}
	

bool GroupRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format("INSERT INTO %s (name,description,image) VALUES (?,?,?)",m_table.c_str()));
			pStatement->SetParamString(1,name);
			pStatement->SetParamString(2,description);
			pStatement->SetParamString(3,image);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

			
			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format("UPDATE %s SET name=?,description=?,image=? WHERE id=?",m_table.c_str()));
			pStatement->SetParamString(1,name);
			pStatement->SetParamString(2,description);
			pStatement->SetParamString(3,image);
			pStatement->SetParamInt(4,id);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

		}
		
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

bool GroupRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format("DELETE FROM %s WHERE id=?",m_table.c_str()));
		pStatement->SetParamInt(1,id);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}


ElementRowSet* GroupRow::GetElements(){
	ElementRowSet* set= new ElementRowSet(m_database,"elements");
	PreparedStatement* pStatement=m_database->PrepareStatement("SELECT * FROM elements WHERE groupid=?");
	pStatement->SetParamInt(1,id);
	DatabaseResultSet* result= pStatement->ExecuteQuery();

	while(result->Next()){
		ElementRow* toAdd=new ElementRow(m_database,"elements");
		toAdd->GetFromResult(result);
		set->Add(toAdd);
	}
	garbageRowSets.Add(set);
	m_database->CloseResultSet(result);
	m_database->CloseStatement(pStatement);
	return set;
}



GroupRowSet::GroupRowSet():wxActiveRecordRowSet(){
}

GroupRowSet::GroupRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

GroupRowSet::GroupRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

GroupRow* GroupRowSet::Item(unsigned long item){
	return (GroupRow*)wxActiveRecordRowSet::Item(item);
}

bool GroupRowSet::SaveAll(){
	try{
		m_database->BeginTransaction();
		for(unsigned long i=0;i<Count();i++)
			Item(i)->Save();
		m_database->Commit();
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		m_database->RollBack();
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

int GroupRowSet::CMPFUNC_name(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GroupRow** m_item1=(GroupRow**)item1;
	GroupRow** m_item2=(GroupRow**)item2;
	return (*m_item1)->name.Cmp((*m_item2)->name);
}

int GroupRowSet::CMPFUNC_description(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GroupRow** m_item1=(GroupRow**)item1;
	GroupRow** m_item2=(GroupRow**)item2;
	return (*m_item1)->description.Cmp((*m_item2)->description);
}

int GroupRowSet::CMPFUNC_image(wxActiveRecordRow** item1,wxActiveRecordRow** item2) {
	GroupRow **m_item1 = (GroupRow **) item1;
	GroupRow **m_item2 = (GroupRow **) item2;
	return (*m_item1)->image.Cmp((*m_item2)->image);
}


int GroupRowSet::CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GroupRow** m_item1=(GroupRow**)item1;
	GroupRow** m_item2=(GroupRow**)item2;
	if((*m_item1)->id<(*m_item2)->id)
		return -1;
	else if((*m_item1)->id>(*m_item2)->id)
		return 1;
	else
		return 0;
}

CMPFUNC_proto GroupRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("name"))
		return (CMPFUNC_proto)CMPFUNC_name;
	else if(var==wxT("description"))
		return (CMPFUNC_proto)CMPFUNC_description;
	else if(var==wxT("image"))
		return (CMPFUNC_proto)CMPFUNC_image;
	else if(var==wxT("id"))
		return (CMPFUNC_proto)CMPFUNC_id;
	else 
	return (CMPFUNC_proto)CMPFUNC_default;
}

