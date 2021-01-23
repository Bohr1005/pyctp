#include "pyctpmd.h"
#include "utils.h"
#include <iostream>

///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void PyMdApi::OnFrontConnected() { py::gil_scoped_acquire acquire; };

void PyMdApi::OnFrontDisconnected(int nReason) { py::gil_scoped_acquire acquire; };

void PyMdApi::OnHeartBeatWarning(int nTimeLapse) { py::gil_scoped_acquire acquire; };

void PyMdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pRspUserLogin)
    {
        data["TradingDay"] = toUtf(pRspUserLogin->TradingDay);
        data["LoginTime"] = toUtf(pRspUserLogin->LoginTime);
        data["BrokerID"] = toUtf(pRspUserLogin->BrokerID);
        data["UserID"] = toUtf(pRspUserLogin->UserID);
        data["SystemName"] = toUtf(pRspUserLogin->SystemName);
        data["FrontID"] = pRspUserLogin->FrontID;
        data["SessionID"] = pRspUserLogin->SessionID;
        data["MaxOrderRef"] = toUtf(pRspUserLogin->MaxOrderRef);
        data["SHFETime"] = toUtf(pRspUserLogin->SHFETime);
        data["DCETime"] = toUtf(pRspUserLogin->DCETime);
        data["CZCETime"] = toUtf(pRspUserLogin->CZCETime);
        data["FFEXTime"] = toUtf(pRspUserLogin->FFEXTime);
        data["INETime"] = toUtf(pRspUserLogin->INETime);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUserLogin(data,error,nRequestID,bIsLast);
};

void PyMdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pUserLogout)
    {
        data["BrokerID"] = toUtf(pUserLogout->BrokerID);
        data["UserID"] = toUtf(pUserLogout->UserID);
    }   
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUserLogout(data, error,nRequestID,bIsLast);
};

void PyMdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspError(error,nRequestID,bIsLast);
};

void PyMdApi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pSpecificInstrument)
    {
        data["InstrumentID"] = toUtf(pSpecificInstrument->InstrumentID);
    }   
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspSubMarketData(data, error,nRequestID,bIsLast);
};

void PyMdApi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pSpecificInstrument)
    {
        data["InstrumentID"] = toUtf(pSpecificInstrument->InstrumentID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUnSubMarketData(data, error,nRequestID,bIsLast);
};

void PyMdApi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pSpecificInstrument)
    {
        data["InstrumentID"] = toUtf(pSpecificInstrument->InstrumentID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspSubForQuoteRsp(data, error,nRequestID,bIsLast);
};

void PyMdApi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pSpecificInstrument)
    {
        data["InstrumentID"] = toUtf(pSpecificInstrument->InstrumentID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUnSubForQuoteRsp(data, error,nRequestID,bIsLast);
};

void PyMdApi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pDepthMarketData)
    {
        data["TradingDay"] = toUtf(pDepthMarketData->TradingDay);
        data["InstrumentID"] = toUtf(pDepthMarketData->InstrumentID);
        data["ExchangeID"] = toUtf(pDepthMarketData->ExchangeID);
        data["ExchangeInstID"] = toUtf(pDepthMarketData->ExchangeInstID);
        data["LastPrice"] = pDepthMarketData->LastPrice;
        data["PreSettlementPrice"] = pDepthMarketData->PreSettlementPrice;
        data["PreClosePrice"] = pDepthMarketData->PreClosePrice;
        data["PreOpenInterest"] = pDepthMarketData->PreOpenInterest;
        data["OpenPrice"] = pDepthMarketData->OpenPrice;
        data["HighestPrice"] = pDepthMarketData->HighestPrice;
        data["LowestPrice"] = pDepthMarketData->LowestPrice;
        data["Volume"] = pDepthMarketData->Volume;
        data["Turnover"] = pDepthMarketData->Turnover;
        data["OpenInterest"] = pDepthMarketData->OpenInterest;
        data["ClosePrice"] = pDepthMarketData->ClosePrice;
        data["SettlementPrice"] = pDepthMarketData->SettlementPrice;
        data["UpperLimitPrice"] = pDepthMarketData->UpperLimitPrice;
        data["LowerLimitPrice"] = pDepthMarketData->LowerLimitPrice;
        data["PreDelta"] = pDepthMarketData->PreDelta;
        data["CurrDelta"] = pDepthMarketData->CurrDelta;
        data["UpdateTime"] = toUtf(pDepthMarketData->UpdateTime);
        data["UpdateMillisec"] = pDepthMarketData->UpdateMillisec;
        data["BidPrice1"] = pDepthMarketData->BidPrice1;
        data["BidVolume1"] = pDepthMarketData->BidVolume1;
        data["AskPrice1"] = pDepthMarketData->AskPrice1;
        data["AskVolume1"] = pDepthMarketData->AskVolume1;
        data["BidPrice2"] = pDepthMarketData->BidPrice2;
        data["BidVolume2"] = pDepthMarketData->BidVolume2;
        data["AskPrice2"] = pDepthMarketData->AskPrice2;
        data["AskVolume2"] = pDepthMarketData->AskVolume2;
        data["BidPrice3"] = pDepthMarketData->BidPrice3;
        data["BidVolume3"] = pDepthMarketData->BidVolume3;
        data["AskPrice3"] = pDepthMarketData->AskPrice3;
        data["AskVolume3"] = pDepthMarketData->AskVolume3;
        data["BidPrice4"] = pDepthMarketData->BidPrice4;
        data["BidVolume4"] = pDepthMarketData->BidVolume4;
        data["AskPrice4"] = pDepthMarketData->AskPrice4;
        data["AskVolume4"] = pDepthMarketData->AskVolume4;
        data["BidPrice5"] = pDepthMarketData->BidPrice5;
        data["BidVolume5"] = pDepthMarketData->BidVolume5;
        data["AskPrice5"] = pDepthMarketData->AskPrice5;
        data["AskVolume5"] = pDepthMarketData->AskVolume5;
        data["AveragePrice"] = pDepthMarketData->AveragePrice;
        data["ActionDay"] = toUtf(pDepthMarketData->ActionDay);
    }
    OnRtnDepthMarketData(data);
};

void PyMdApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
    py::gil_scoped_acquire acquire; 
    py::dict data;
    if (pForQuoteRsp)
    {
        data["TradingDay"] = toUtf(pForQuoteRsp->TradingDay);
        data["InstrumentID"] = toUtf(pForQuoteRsp->InstrumentID);
        data["ForQuoteSysID"] = toUtf(pForQuoteRsp->ForQuoteSysID);
        data["ForQuoteTime"] = toUtf(pForQuoteRsp->ForQuoteTime);
        data["ActionDay"] = toUtf(pForQuoteRsp->ActionDay);
        data["ExchangeID"] = toUtf(pForQuoteRsp->ExchangeID);
    }
    OnRtnForQuoteRsp(data);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void PyMdApi::createFtdcMdApi(std::string pszFlowPath)
{
    api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str());
    api->RegisterSpi(this);
};

void PyMdApi::release()
{
    api->Release();
};

void PyMdApi::init()
{
    api->Init();
    active = true;
};

int PyMdApi::join()
{
    int i = api->Join();
    return i;
};

void PyMdApi::exit()
{
    active = false;
    api->RegisterSpi(NULL);
    api->Release();
    api = NULL;
};

std::string PyMdApi::GetApiVersion()
{
    std::string ver = api->GetApiVersion();
    return ver;
};

std::string PyMdApi::getTradingDay()
{
    std::string day = api->GetTradingDay();
    return day;
};

void PyMdApi::registerFront(std::string pszFrontAddress)
{
    api->RegisterFront((char*)pszFrontAddress.c_str());
};

int PyMdApi::subscribeMarketData(std::string instrumentID)
{
    char* buffer = (char*) instrumentID.c_str();
    char* myreq[1] = { buffer };
    int i = api->SubscribeMarketData(myreq, 1);
    return i;
};

int PyMdApi::unSubscribeMarketData(std::string instrumentID)
{
    char* buffer = (char*)instrumentID.c_str();
    char* myreq[1] = { buffer };;
    int i = api->UnSubscribeMarketData(myreq, 1);
    return i;
};

int PyMdApi::subscribeForQuoteRsp(std::string instrumentID)
{
    char* buffer = (char*)instrumentID.c_str();
    char* myreq[1] = { buffer };
    int i = api->SubscribeForQuoteRsp(myreq, 1);
    return i;
};

int PyMdApi::unSubscribeForQuoteRsp(std::string instrumentID)
{
    char* buffer = (char*)instrumentID.c_str();
    char* myreq[1] = { buffer };;
    int i = api->UnSubscribeForQuoteRsp(myreq, 1);
    return i;
};

int PyMdApi::reqUserLogin(const py::dict &req, int reqid)
{
    CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "Password", myreq.Password);
    getString(req, "UserProductInfo", myreq.UserProductInfo);
    getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
    getString(req, "ProtocolInfo", myreq.ProtocolInfo);
    getString(req, "MacAddress", myreq.MacAddress);
    getString(req, "OneTimePassword", myreq.OneTimePassword);
    getString(req, "ClientIPAddress", myreq.ClientIPAddress);
    getString(req, "LoginRemark", myreq.LoginRemark);
    int i = api->ReqUserLogin(&myreq, reqid);
    return i;
};

int PyMdApi::reqUserLogout(const py::dict &req, int reqid)
{
    CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    int i = api->ReqUserLogout(&myreq, reqid);
    return i;
};



