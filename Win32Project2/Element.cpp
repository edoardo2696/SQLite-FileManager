#include "Element.h"


Element::Element():wxSqliteActiveRecord(){
}

Element::Element(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password):wxSqliteActiveRecord(table,name,server,user,password){
}

Element::Element(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Element::Create(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password){
	return wxSqliteActiveRecord::Create(table,name,server,user,password);
}

ElementRow* Element::RowFromResult(DatabaseResultSet* result){
	ElementRow* row=new ElementRow(this);
	
	row->GetFromResult(result);
	
	return row;
}

ElementRow* Element::New(){
	ElementRow* newRow=new ElementRow(this);
	garbageRows.Add(newRow);
	return newRow;
}

ElementRow* Element::Id(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		ElementRow* row=RowFromResult(result);
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


bool Element::Delete(int key){
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


ElementRow* Element::Where(const wxString& whereClause){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str()));
		DatabaseResultSet* result= pStatement->ExecuteQuery();
	
		ElementRow* row=RowFromResult(result);
		
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

ElementRowSet* Element::WhereSet(const wxString& whereClause){
	ElementRowSet* rowSet=new ElementRowSet();
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


ElementRowSet* Element::All(){
	ElementRowSet* rowSet=new ElementRowSet();
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


ElementRow::ElementRow():wxActiveRecordRow(){
	bool newRow=true;
}

ElementRow::ElementRow(Element* activeRecord):wxActiveRecordRow(activeRecord){
	bool newRow=true;
}

ElementRow::ElementRow(const ElementRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;

	id=src.id;
	groupid=src.groupid;
    gcode=src.gcode;
    image=src.image;


}

ElementRow::ElementRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}


ElementRow& ElementRow::operator=(const ElementRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;

    id=src.id;
    groupid=src.groupid;
    gcode=src.gcode;
    image=src.image;


    return *this;
}

bool ElementRow::GetFromResult(DatabaseResultSet* result){

	newRow=false;
    try {
        id = result->GetResultInt(wxT("id"));
        groupid = result->GetResultInt(wxT("groupid"));
        image = result->GetResultString(wxT("image"));
        gcode = result->GetResultString(wxT("gcode"));
    } catch (DatabaseLayerException & e) {

    }

	return true;
}


bool ElementRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("INSERT INTO %s (groupid,image,gcode) VALUES (?,?,?)"),m_table.c_str()));
			pStatement->SetParamInt(1,groupid);
			pStatement->SetParamString(2,image);
			pStatement->SetParamString(3,gcode);

			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);


			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("UPDATE %s SET id=?,groupid=?,image=?,gcode=?, WHERE id=?"),m_table.c_str()));
            pStatement->SetParamInt(1,id);
            pStatement->SetParamInt(2,groupid);
            pStatement->SetParamString(3,image);
            pStatement->SetParamString(4,gcode);
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

bool ElementRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,id);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}


GroupRow* ElementRow::GetGroup(){
	GroupRow* owner= new GroupRow(m_database,wxT("groups"));
	PreparedStatement* pStatement=m_database->PrepareStatement(wxT("SELECT * FROM groups WHERE id=?"));
	pStatement->SetParamInt(1,groupid);
	pStatement->SetParamInt(1,groupid);
	DatabaseResultSet* result= pStatement->ExecuteQuery();

	result->Next();
	owner->GetFromResult(result);
	garbageRows.Add(owner);
	m_database->CloseResultSet(result);
	m_database->CloseStatement(pStatement);
	return owner;
}



ElementRowSet::ElementRowSet():wxActiveRecordRowSet(){
}

ElementRowSet::ElementRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

ElementRowSet::ElementRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

ElementRow* ElementRowSet::Item(unsigned long item){
	return (ElementRow*)wxActiveRecordRowSet::Item(item);
}

bool ElementRowSet::SaveAll(){
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


int ElementRowSet::CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	ElementRow** m_item1=(ElementRow**)item1;
	ElementRow** m_item2=(ElementRow**)item2;
	if((*m_item1)->id<(*m_item2)->id)
		return -1;
	else if((*m_item1)->id>(*m_item2)->id)
		return 1;
	else
		return 0;
}

int ElementRowSet::CMPFUNC_groupid(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	ElementRow** m_item1=(ElementRow**)item1;
	ElementRow** m_item2=(ElementRow**)item2;
	if((*m_item1)->groupid<(*m_item2)->groupid)
		return -1;
	else if((*m_item1)->groupid>(*m_item2)->groupid)
		return 1;
	else
		return 0;
}

int ElementRowSet::CMPFUNC_image(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	ElementRow** m_item1=(ElementRow**)item1;
	ElementRow** m_item2=(ElementRow**)item2;
	return (*m_item1)->image.Cmp((*m_item2)->image);
}


int ElementRowSet::CMPFUNC_gcode(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	ElementRow** m_item1=(ElementRow**)item1;
	ElementRow** m_item2=(ElementRow**)item2;
	return (*m_item1)->gcode.Cmp((*m_item2)->gcode);
}




CMPFUNC_proto ElementRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("id"))
		return (CMPFUNC_proto)CMPFUNC_id;
	else if(var==wxT("groupid"))
		return (CMPFUNC_proto)CMPFUNC_groupid;
	else if(var==wxT("image"))
		return (CMPFUNC_proto)CMPFUNC_image;
	else if(var==wxT("gcode"))
		return (CMPFUNC_proto)CMPFUNC_gcode;
	else
	return (CMPFUNC_proto)CMPFUNC_default;
}

