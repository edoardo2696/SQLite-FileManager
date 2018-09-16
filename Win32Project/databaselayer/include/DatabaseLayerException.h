#ifndef __DATABASE_LAYER_EXCEPTION_H__
#define __DATABASE_LAYER_EXCEPTION_H__

#ifndef DONT_USE_DATABASE_LAYER_EXCEPTIONS

class DatabaseLayerException
{
public:
  DatabaseLayerException(int nCode, const wxString& strError)
  {
    m_nErrorCode = nCode;
    m_strErrorMessage = strError;
  }

  const wxString& GetErrorMessage() const { return m_strErrorMessage; }
  const int GetErrorCode() const { return m_nErrorCode; }
  

private:
  wxString m_strErrorMessage;
  int m_nErrorCode;  
};

#endif

#endif
