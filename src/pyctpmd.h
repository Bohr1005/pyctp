#include "ThostFtdcMdApi.h"
#include "pybind11/pybind11.h"
#include <iostream>

namespace py = pybind11;

class PyMdApi : public CThostFtdcMdSpi
{
private:
    CThostFtdcMdApi* api;                //API����
    bool active = false;                //����״̬

public:
    PyMdApi()
    {
    };

    ~PyMdApi()
    {
        if (active)
        {
            exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API�ص�����
    //-------------------------------------------------------------------------------------

    ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void OnFrontConnected() ;

    ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ���������
    ///@param nReason ����ԭ��
    ///        0x1001 �����ʧ��
    ///        0x1002 ����дʧ��
    ///        0x2001 ����������ʱ
    ///        0x2002 ��������ʧ��
    ///        0x2003 �յ�������
    virtual void OnFrontDisconnected(int nReason) ;

    ///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
    ///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
    virtual void OnHeartBeatWarning(int nTimeLapse) ;


    ///��¼������Ӧ
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///�ǳ�������Ӧ
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///����Ӧ��
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///��������Ӧ��
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///ȡ����������Ӧ��
    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///����ѯ��Ӧ��
    virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///ȡ������ѯ��Ӧ��
    virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    ///�������֪ͨ
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) ;

    ///ѯ��֪ͨ
    virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) ;

    //-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
    //-------------------------------------------------------------------------------------

    virtual void OnRspUserLogin(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRspUserLogout(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRspError(const py::dict &error, int reqid, bool last) {};

    virtual void OnRspSubMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRspUnSubMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRspSubForQuoteRsp(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRspUnSubForQuoteRsp(const py::dict &data, const py::dict &error, int reqid, bool last) {};

    virtual void OnRtnDepthMarketData(const py::dict &data) {};

    virtual void OnRtnForQuoteRsp(const py::dict &data) {};

    //-------------------------------------------------------------------------------------
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------

    void createFtdcMdApi(std::string pszFlowPath = "");

    void release();

    void init();

    int join();

    void exit();

    std::string GetApiVersion();

    std::string getTradingDay();

    void registerFront(std::string pszFrontAddress);

    int subscribeMarketData(std::string instrumentID);

    int unSubscribeMarketData(std::string instrumentID);

    int subscribeForQuoteRsp(std::string instrumentID);

    int unSubscribeForQuoteRsp(std::string instrumentID);

    int reqUserLogin(const py::dict &req, int reqid);

    int reqUserLogout(const py::dict &req, int reqid);
};

class PyMDWrapper: public PyMdApi
{
public:

    void OnFrontConnected() override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnFrontConnected);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnFrontDisconnected(int reqid) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnFrontDisconnected, reqid);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnHeartBeatWarning(int reqid) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnHeartBeatWarning, reqid);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUserLogin(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspUserLogin, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUserLogout(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspUserLogout, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspError(const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspError, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspSubMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspSubMarketData, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUnSubMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspUnSubMarketData, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspSubForQuoteRsp(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspSubForQuoteRsp, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUnSubForQuoteRsp(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRspUnSubForQuoteRsp, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnDepthMarketData(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRtnDepthMarketData, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnForQuoteRsp(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyMdApi, OnRtnForQuoteRsp, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };
};