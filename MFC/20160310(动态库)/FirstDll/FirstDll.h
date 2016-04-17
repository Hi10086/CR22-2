


#ifdef _USRDLL
  class  __declspec(dllexport) CTest
  {
  public:
    CTest();
    virtual ~CTest();
    virtual void ShowMsg();
  private:
    int m_nData;
    };

  extern __declspec(dllexport) int g_nNumber;
  __declspec(dllexport) void __stdcall ShowMsg();
  __declspec(dllexport) CTest* CreateObject();


#else

  class  __declspec(dllimport) CTest
  {
  public:
    CTest();
    virtual ~CTest();
    virtual void ShowMsg();
  private:
    int m_nData;
  };
  extern __declspec(dllimport) int g_nNumber;
  __declspec(dllimport) void __stdcall ShowMsg();
  __declspec(dllimport) CTest* CreateObject();
#endif
