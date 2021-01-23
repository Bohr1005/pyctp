#include "pyctptd.h"
#include "utils.h"

void PyTdApi::OnFrontConnected(){ py::gil_scoped_acquire acquire; }

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void PyTdApi::OnFrontDisconnected(int nReason){ py::gil_scoped_acquire acquire; }

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void PyTdApi::OnHeartBeatWarning(int nTimeLapse){ py::gil_scoped_acquire acquire; }

///客户端认证响应
void PyTdApi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspAuthenticateField)
    {
        data["BrokerID"] = toUtf(pRspAuthenticateField->BrokerID);
        data["UserID"] = toUtf(pRspAuthenticateField->UserID);
        data["UserProductInfo"] = toUtf(pRspAuthenticateField->UserProductInfo);
        data["AppID"] = toUtf(pRspAuthenticateField->AppID);
        data["AppType"] = pRspAuthenticateField->AppType;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspAuthenticate(data,error,nRequestID,bIsLast);
}

///登录请求响应
void PyTdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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
}

///登出请求响应
void PyTdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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
    OnRspUserLogout(data,error,nRequestID,bIsLast);
}

///用户口令更新请求响应
void PyTdApi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pUserPasswordUpdate)
    {
        data["BrokerID"] = toUtf(pUserPasswordUpdate->BrokerID);
        data["UserID"] = toUtf(pUserPasswordUpdate->UserID);
        data["OldPassword"] = toUtf(pUserPasswordUpdate->OldPassword);
        data["NewPassword"] = toUtf(pUserPasswordUpdate->NewPassword);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUserPasswordUpdate(data,error,nRequestID,bIsLast);
}

///资金账户口令更新请求响应
void PyTdApi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingAccountPasswordUpdate)
    {
        data["BrokerID"] = toUtf(pTradingAccountPasswordUpdate->BrokerID);
        data["AccountID"] = toUtf(pTradingAccountPasswordUpdate->AccountID);
        data["OldPassword"] = toUtf(pTradingAccountPasswordUpdate->OldPassword);
        data["NewPassword"] = toUtf(pTradingAccountPasswordUpdate->NewPassword);
        data["CurrencyID"] = toUtf(pTradingAccountPasswordUpdate->CurrencyID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspTradingAccountPasswordUpdate(data,error,nRequestID,bIsLast);
}

///查询用户当前支持的认证模式的回复
void PyTdApi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspUserAuthMethod)
    {
        data["UsableAuthMethod"] = pRspUserAuthMethod->UsableAuthMethod;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspUserAuthMethod(data,error,nRequestID,bIsLast);
}

///获取图形验证码请求的回复
void PyTdApi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspGenUserCaptcha)
    {
        data["BrokerID"] = toUtf(pRspGenUserCaptcha->BrokerID);
        data["UserID"] = toUtf(pRspGenUserCaptcha->UserID);
        data["CaptchaInfoLen"] = pRspGenUserCaptcha->CaptchaInfoLen;
        data["CaptchaInfo"] = toUtf(pRspGenUserCaptcha->CaptchaInfo);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspGenUserCaptcha(data,error,nRequestID,bIsLast);
}

///获取短信验证码请求的回复
void PyTdApi::OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspGenUserText)
    {
        data["UserTextSeq"] = pRspGenUserText->UserTextSeq;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspGenUserText(data,error,nRequestID,bIsLast);
}

///报单录入请求响应
void PyTdApi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOrder)
    {
        data["BrokerID"] = toUtf(pInputOrder->BrokerID);
        data["InvestorID"] = toUtf(pInputOrder->InvestorID);
        data["InstrumentID"] = toUtf(pInputOrder->InstrumentID);
        data["OrderRef"] = toUtf(pInputOrder->OrderRef);
        data["UserID"] = toUtf(pInputOrder->UserID);
        data["OrderPriceType"] = pInputOrder->OrderPriceType;
        data["Direction"] = pInputOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pInputOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pInputOrder->CombHedgeFlag);
        data["LimitPrice"] = pInputOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pInputOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pInputOrder->TimeCondition;
        data["GTDDate"] = toUtf(pInputOrder->GTDDate);
        data["VolumeCondition"] = pInputOrder->VolumeCondition;
        data["MinVolume"] = pInputOrder->MinVolume;
        data["ContingentCondition"] = pInputOrder->ContingentCondition;
        data["StopPrice"] = pInputOrder->StopPrice;
        data["ForceCloseReason"] = pInputOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pInputOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pInputOrder->BusinessUnit);
        data["RequestID"] = pInputOrder->RequestID;
        data["UserForceClose"] = pInputOrder->UserForceClose;
        data["IsSwapOrder"] = pInputOrder->IsSwapOrder;
        data["ExchangeID"] = toUtf(pInputOrder->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputOrder->InvestUnitID);
        data["AccountID"] = toUtf(pInputOrder->AccountID);
        data["CurrencyID"] = toUtf(pInputOrder->CurrencyID);
        data["ClientID"] = toUtf(pInputOrder->ClientID);
        data["IPAddress"] = toUtf(pInputOrder->IPAddress);
        data["MacAddress"] = toUtf(pInputOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspOrderInsert(data,error,nRequestID,bIsLast);
}

///预埋单录入请求响应
void PyTdApi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pParkedOrder)
    {
        data["BrokerID"] = toUtf(pParkedOrder->BrokerID);
        data["InvestorID"] = toUtf(pParkedOrder->InvestorID);
        data["InstrumentID"] = toUtf(pParkedOrder->InstrumentID);
        data["OrderRef"] = toUtf(pParkedOrder->OrderRef);
        data["UserID"] = toUtf(pParkedOrder->UserID);
        data["OrderPriceType"] = pParkedOrder->OrderPriceType;
        data["Direction"] = pParkedOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pParkedOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pParkedOrder->CombHedgeFlag);
        data["LimitPrice"] = pParkedOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pParkedOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pParkedOrder->TimeCondition;
        data["GTDDate"] = toUtf(pParkedOrder->GTDDate);
        data["VolumeCondition"] = pParkedOrder->VolumeCondition;
        data["MinVolume"] = pParkedOrder->MinVolume;
        data["ContingentCondition"] = pParkedOrder->ContingentCondition;
        data["StopPrice"] = pParkedOrder->StopPrice;
        data["ForceCloseReason"] = pParkedOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pParkedOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pParkedOrder->BusinessUnit);
        data["RequestID"] = pParkedOrder->RequestID;
        data["UserForceClose"] = pParkedOrder->UserForceClose;
        data["ExchangeID"] = toUtf(pParkedOrder->ExchangeID);
        data["ParkedOrderID"] = toUtf(pParkedOrder->ParkedOrderID);
        data["UserType"] = pParkedOrder->UserType;
        data["Status"] = pParkedOrder->Status;
        data["ErrorID"] = pParkedOrder->ErrorID;
        data["ErrorMsg"] = toUtf(pParkedOrder->ErrorMsg);
        data["IsSwapOrder"] = pParkedOrder->IsSwapOrder;
        data["AccountID"] = toUtf(pParkedOrder->AccountID);
        data["CurrencyID"] = toUtf(pParkedOrder->CurrencyID);
        data["ClientID"] = toUtf(pParkedOrder->ClientID);
        data["InvestUnitID"] = toUtf(pParkedOrder->InvestUnitID);
        data["IPAddress"] = toUtf(pParkedOrder->IPAddress);
        data["MacAddress"] = toUtf(pParkedOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspParkedOrderInsert(data,error,nRequestID,bIsLast);
}

///预埋撤单录入请求响应
void PyTdApi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pParkedOrderAction)
    {
        data["BrokerID"] = toUtf(pParkedOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pParkedOrderAction->InvestorID);
        data["OrderActionRef"] = pParkedOrderAction->OrderActionRef;
        data["OrderRef"] = toUtf(pParkedOrderAction->OrderRef);
        data["RequestID"] = pParkedOrderAction->RequestID;
        data["FrontID"] = pParkedOrderAction->FrontID;
        data["SessionID"] = pParkedOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pParkedOrderAction->ExchangeID);
        data["OrderSysID"] = toUtf(pParkedOrderAction->OrderSysID);
        data["ActionFlag"] = pParkedOrderAction->ActionFlag;
        data["LimitPrice"] = pParkedOrderAction->LimitPrice;
        data["VolumeChange"] = pParkedOrderAction->VolumeChange;
        data["UserID"] = toUtf(pParkedOrderAction->UserID);
        data["InstrumentID"] = toUtf(pParkedOrderAction->InstrumentID);
        data["ParkedOrderActionID"] = toUtf(pParkedOrderAction->ParkedOrderActionID);
        data["UserType"] = pParkedOrderAction->UserType;
        data["Status"] = pParkedOrderAction->Status;
        data["ErrorID"] = pParkedOrderAction->ErrorID;
        data["ErrorMsg"] = toUtf(pParkedOrderAction->ErrorMsg);
        data["InvestUnitID"] = toUtf(pParkedOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pParkedOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pParkedOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspParkedOrderAction(data,error,nRequestID,bIsLast);
}

///报单操作请求响应
void PyTdApi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOrderAction)
    {
        data["BrokerID"] = toUtf(pInputOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pInputOrderAction->InvestorID);
        data["OrderActionRef"] = pInputOrderAction->OrderActionRef;
        data["OrderRef"] = toUtf(pInputOrderAction->OrderRef);
        data["RequestID"] = pInputOrderAction->RequestID;
        data["FrontID"] = pInputOrderAction->FrontID;
        data["SessionID"] = pInputOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pInputOrderAction->ExchangeID);
        data["OrderSysID"] = toUtf(pInputOrderAction->OrderSysID);
        data["ActionFlag"] = pInputOrderAction->ActionFlag;
        data["LimitPrice"] = pInputOrderAction->LimitPrice;
        data["VolumeChange"] = pInputOrderAction->VolumeChange;
        data["UserID"] = toUtf(pInputOrderAction->UserID);
        data["InstrumentID"] = toUtf(pInputOrderAction->InstrumentID);
        data["InvestUnitID"] = toUtf(pInputOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pInputOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pInputOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspOrderAction(data,error,nRequestID,bIsLast);
}

///查询最大报单数量响应
void PyTdApi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pQryMaxOrderVolume)
    {
        data["BrokerID"] = toUtf(pQryMaxOrderVolume->BrokerID);
        data["InvestorID"] = toUtf(pQryMaxOrderVolume->InvestorID);
        data["InstrumentID"] = toUtf(pQryMaxOrderVolume->InstrumentID);
        data["Direction"] = pQryMaxOrderVolume->Direction;
        data["OffsetFlag"] = pQryMaxOrderVolume->OffsetFlag;
        data["HedgeFlag"] = pQryMaxOrderVolume->HedgeFlag;
        data["MaxVolume"] = pQryMaxOrderVolume->MaxVolume;
        data["ExchangeID"] = toUtf(pQryMaxOrderVolume->ExchangeID);
        data["InvestUnitID"] = toUtf(pQryMaxOrderVolume->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryMaxOrderVolume(data,error,nRequestID,bIsLast);
}

///投资者结算结果确认响应
void PyTdApi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSettlementInfoConfirm)
    {
        data["BrokerID"] = toUtf(pSettlementInfoConfirm->BrokerID);
        data["InvestorID"] = toUtf(pSettlementInfoConfirm->InvestorID);
        data["ConfirmDate"] = toUtf(pSettlementInfoConfirm->ConfirmDate);
        data["ConfirmTime"] = toUtf(pSettlementInfoConfirm->ConfirmTime);
        data["SettlementID"] = pSettlementInfoConfirm->SettlementID;
        data["AccountID"] = toUtf(pSettlementInfoConfirm->AccountID);
        data["CurrencyID"] = toUtf(pSettlementInfoConfirm->CurrencyID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspSettlementInfoConfirm(data,error,nRequestID,bIsLast);
}

///删除预埋单响应
void PyTdApi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRemoveParkedOrder)
    {
        data["BrokerID"] = toUtf(pRemoveParkedOrder->BrokerID);
        data["InvestorID"] = toUtf(pRemoveParkedOrder->InvestorID);
        data["ParkedOrderID"] = toUtf(pRemoveParkedOrder->ParkedOrderID);
        data["InvestUnitID"] = toUtf(pRemoveParkedOrder->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspRemoveParkedOrder(data,error,nRequestID,bIsLast);
}

///删除预埋撤单响应
void PyTdApi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRemoveParkedOrderAction)
    {
        data["BrokerID"] = toUtf(pRemoveParkedOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pRemoveParkedOrderAction->InvestorID);
        data["ParkedOrderActionID"] = toUtf(pRemoveParkedOrderAction->ParkedOrderActionID);
        data["InvestUnitID"] = toUtf(pRemoveParkedOrderAction->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspRemoveParkedOrderAction(data,error,nRequestID,bIsLast);
}

///执行宣告录入请求响应
void PyTdApi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputExecOrder)
    {
        data["BrokerID"] = toUtf(pInputExecOrder->BrokerID);
        data["InvestorID"] = toUtf(pInputExecOrder->InvestorID);
        data["InstrumentID"] = toUtf(pInputExecOrder->InstrumentID);
        data["ExecOrderRef"] = toUtf(pInputExecOrder->ExecOrderRef);
        data["UserID"] = toUtf(pInputExecOrder->UserID);
        data["Volume"] = pInputExecOrder->Volume;
        data["RequestID"] = pInputExecOrder->RequestID;
        data["BusinessUnit"] = toUtf(pInputExecOrder->BusinessUnit);
        data["OffsetFlag"] = pInputExecOrder->OffsetFlag;
        data["HedgeFlag"] = pInputExecOrder->HedgeFlag;
        data["ActionType"] = pInputExecOrder->ActionType;
        data["PosiDirection"] = pInputExecOrder->PosiDirection;
        data["ReservePositionFlag"] = pInputExecOrder->ReservePositionFlag;
        data["CloseFlag"] = pInputExecOrder->CloseFlag;
        data["ExchangeID"] = toUtf(pInputExecOrder->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputExecOrder->InvestUnitID);
        data["AccountID"] = toUtf(pInputExecOrder->AccountID);
        data["CurrencyID"] = toUtf(pInputExecOrder->CurrencyID);
        data["ClientID"] = toUtf(pInputExecOrder->ClientID);
        data["IPAddress"] = toUtf(pInputExecOrder->IPAddress);
        data["MacAddress"] = toUtf(pInputExecOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspExecOrderInsert(data,error,nRequestID,bIsLast);
}

///执行宣告操作请求响应
void PyTdApi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputExecOrderAction)
    {
        data["BrokerID"] = toUtf(pInputExecOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pInputExecOrderAction->InvestorID);
        data["ExecOrderActionRef"] = pInputExecOrderAction->ExecOrderActionRef;
        data["ExecOrderRef"] = toUtf(pInputExecOrderAction->ExecOrderRef);
        data["RequestID"] = pInputExecOrderAction->RequestID;
        data["FrontID"] = pInputExecOrderAction->FrontID;
        data["SessionID"] = pInputExecOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pInputExecOrderAction->ExchangeID);
        data["ExecOrderSysID"] = toUtf(pInputExecOrderAction->ExecOrderSysID);
        data["ActionFlag"] = pInputExecOrderAction->ActionFlag;
        data["UserID"] = toUtf(pInputExecOrderAction->UserID);
        data["InstrumentID"] = toUtf(pInputExecOrderAction->InstrumentID);
        data["InvestUnitID"] = toUtf(pInputExecOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pInputExecOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pInputExecOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspExecOrderAction(data,error,nRequestID,bIsLast);
}

///询价录入请求响应
void PyTdApi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputForQuote)
    {
        data["BrokerID"] = toUtf(pInputForQuote->BrokerID);
        data["InvestorID"] = toUtf(pInputForQuote->InvestorID);
        data["InstrumentID"] = toUtf(pInputForQuote->InstrumentID);
        data["ForQuoteRef"] = toUtf(pInputForQuote->ForQuoteRef);
        data["UserID"] = toUtf(pInputForQuote->UserID);
        data["ExchangeID"] = toUtf(pInputForQuote->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputForQuote->InvestUnitID);
        data["IPAddress"] = toUtf(pInputForQuote->IPAddress);
        data["MacAddress"] = toUtf(pInputForQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspForQuoteInsert(data,error,nRequestID,bIsLast);
}

///报价录入请求响应
void PyTdApi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputQuote)
    {
        data["BrokerID"] = toUtf(pInputQuote->BrokerID);
        data["InvestorID"] = toUtf(pInputQuote->InvestorID);
        data["InstrumentID"] = toUtf(pInputQuote->InstrumentID);
        data["QuoteRef"] = toUtf(pInputQuote->QuoteRef);
        data["UserID"] = toUtf(pInputQuote->UserID);
        data["AskPrice"] = pInputQuote->AskPrice;
        data["BidPrice"] = pInputQuote->BidPrice;
        data["AskVolume"] = pInputQuote->AskVolume;
        data["BidVolume"] = pInputQuote->BidVolume;
        data["RequestID"] = pInputQuote->RequestID;
        data["BusinessUnit"] = toUtf(pInputQuote->BusinessUnit);
        data["AskOffsetFlag"] = pInputQuote->AskOffsetFlag;
        data["BidOffsetFlag"] = pInputQuote->BidOffsetFlag;
        data["AskHedgeFlag"] = pInputQuote->AskHedgeFlag;
        data["BidHedgeFlag"] = pInputQuote->BidHedgeFlag;
        data["AskOrderRef"] = toUtf(pInputQuote->AskOrderRef);
        data["BidOrderRef"] = toUtf(pInputQuote->BidOrderRef);
        data["ForQuoteSysID"] = toUtf(pInputQuote->ForQuoteSysID);
        data["ExchangeID"] = toUtf(pInputQuote->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputQuote->InvestUnitID);
        data["ClientID"] = toUtf(pInputQuote->ClientID);
        data["IPAddress"] = toUtf(pInputQuote->IPAddress);
        data["MacAddress"] = toUtf(pInputQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQuoteInsert(data,error,nRequestID,bIsLast);
}

///报价操作请求响应
void PyTdApi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputQuoteAction)
    {
        data["BrokerID"] = toUtf(pInputQuoteAction->BrokerID);
        data["InvestorID"] = toUtf(pInputQuoteAction->InvestorID);
        data["QuoteActionRef"] = pInputQuoteAction->QuoteActionRef;
        data["QuoteRef"] = toUtf(pInputQuoteAction->QuoteRef);
        data["RequestID"] = pInputQuoteAction->RequestID;
        data["FrontID"] = pInputQuoteAction->FrontID;
        data["SessionID"] = pInputQuoteAction->SessionID;
        data["ExchangeID"] = toUtf(pInputQuoteAction->ExchangeID);
        data["QuoteSysID"] = toUtf(pInputQuoteAction->QuoteSysID);
        data["ActionFlag"] = pInputQuoteAction->ActionFlag;
        data["UserID"] = toUtf(pInputQuoteAction->UserID);
        data["InstrumentID"] = toUtf(pInputQuoteAction->InstrumentID);
        data["InvestUnitID"] = toUtf(pInputQuoteAction->InvestUnitID);
        data["ClientID"] = toUtf(pInputQuoteAction->ClientID);
        data["IPAddress"] = toUtf(pInputQuoteAction->IPAddress);
        data["MacAddress"] = toUtf(pInputQuoteAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQuoteAction(data,error,nRequestID,bIsLast);
}

///批量报单操作请求响应
void PyTdApi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputBatchOrderAction)
    {
        data["BrokerID"] = toUtf(pInputBatchOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pInputBatchOrderAction->InvestorID);
        data["OrderActionRef"] = pInputBatchOrderAction->OrderActionRef;
        data["RequestID"] = pInputBatchOrderAction->RequestID;
        data["FrontID"] = pInputBatchOrderAction->FrontID;
        data["SessionID"] = pInputBatchOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pInputBatchOrderAction->ExchangeID);
        data["UserID"] = toUtf(pInputBatchOrderAction->UserID);
        data["InvestUnitID"] = toUtf(pInputBatchOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pInputBatchOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pInputBatchOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspBatchOrderAction(data,error,nRequestID,bIsLast);
}

///期权自对冲录入请求响应
void PyTdApi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOptionSelfClose)
    {
        data["BrokerID"] = toUtf(pInputOptionSelfClose->BrokerID);
        data["InvestorID"] = toUtf(pInputOptionSelfClose->InvestorID);
        data["InstrumentID"] = toUtf(pInputOptionSelfClose->InstrumentID);
        data["OptionSelfCloseRef"] = toUtf(pInputOptionSelfClose->OptionSelfCloseRef);
        data["UserID"] = toUtf(pInputOptionSelfClose->UserID);
        data["Volume"] = pInputOptionSelfClose->Volume;
        data["RequestID"] = pInputOptionSelfClose->RequestID;
        data["BusinessUnit"] = toUtf(pInputOptionSelfClose->BusinessUnit);
        data["HedgeFlag"] = pInputOptionSelfClose->HedgeFlag;
        data["OptSelfCloseFlag"] = pInputOptionSelfClose->OptSelfCloseFlag;
        data["ExchangeID"] = toUtf(pInputOptionSelfClose->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputOptionSelfClose->InvestUnitID);
        data["AccountID"] = toUtf(pInputOptionSelfClose->AccountID);
        data["CurrencyID"] = toUtf(pInputOptionSelfClose->CurrencyID);
        data["ClientID"] = toUtf(pInputOptionSelfClose->ClientID);
        data["IPAddress"] = toUtf(pInputOptionSelfClose->IPAddress);
        data["MacAddress"] = toUtf(pInputOptionSelfClose->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspOptionSelfCloseInsert(data,error,nRequestID,bIsLast);
}

///期权自对冲操作请求响应
void PyTdApi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOptionSelfCloseAction)
    {
        data["BrokerID"] = toUtf(pInputOptionSelfCloseAction->BrokerID);
        data["InvestorID"] = toUtf(pInputOptionSelfCloseAction->InvestorID);
        data["OptionSelfCloseActionRef"] = pInputOptionSelfCloseAction->OptionSelfCloseActionRef;
        data["OptionSelfCloseRef"] = toUtf(pInputOptionSelfCloseAction->OptionSelfCloseRef);
        data["RequestID"] = pInputOptionSelfCloseAction->RequestID;
        data["FrontID"] = pInputOptionSelfCloseAction->FrontID;
        data["SessionID"] = pInputOptionSelfCloseAction->SessionID;
        data["ExchangeID"] = toUtf(pInputOptionSelfCloseAction->ExchangeID);
        data["OptionSelfCloseSysID"] = toUtf(pInputOptionSelfCloseAction->OptionSelfCloseSysID);
        data["ActionFlag"] = pInputOptionSelfCloseAction->ActionFlag;
        data["UserID"] = toUtf(pInputOptionSelfCloseAction->UserID);
        data["InstrumentID"] = toUtf(pInputOptionSelfCloseAction->InstrumentID);
        data["InvestUnitID"] = toUtf(pInputOptionSelfCloseAction->InvestUnitID);
        data["IPAddress"] = toUtf(pInputOptionSelfCloseAction->IPAddress);
        data["MacAddress"] = toUtf(pInputOptionSelfCloseAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspOptionSelfCloseAction(data,error,nRequestID,bIsLast);
}

///申请组合录入请求响应
void PyTdApi::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputCombAction)
    {
        data["BrokerID"] = toUtf(pInputCombAction->BrokerID);
        data["InvestorID"] = toUtf(pInputCombAction->InvestorID);
        data["InstrumentID"] = toUtf(pInputCombAction->InstrumentID);
        data["CombActionRef"] = toUtf(pInputCombAction->CombActionRef);
        data["UserID"] = toUtf(pInputCombAction->UserID);
        data["Direction"] = pInputCombAction->Direction;
        data["Volume"] = pInputCombAction->Volume;
        data["CombDirection"] = pInputCombAction->CombDirection;
        data["HedgeFlag"] = pInputCombAction->HedgeFlag;
        data["ExchangeID"] = toUtf(pInputCombAction->ExchangeID);
        data["IPAddress"] = toUtf(pInputCombAction->IPAddress);
        data["MacAddress"] = toUtf(pInputCombAction->MacAddress);
        data["InvestUnitID"] = toUtf(pInputCombAction->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspCombActionInsert(data,error,nRequestID,bIsLast);
}

///请求查询报单响应
void PyTdApi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOrder)
    {
        data["BrokerID"] = toUtf(pOrder->BrokerID);
        data["InvestorID"] = toUtf(pOrder->InvestorID);
        data["InstrumentID"] = toUtf(pOrder->InstrumentID);
        data["OrderRef"] = toUtf(pOrder->OrderRef);
        data["UserID"] = toUtf(pOrder->UserID);
        data["OrderPriceType"] = pOrder->OrderPriceType;
        data["Direction"] = pOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pOrder->CombHedgeFlag);
        data["LimitPrice"] = pOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pOrder->TimeCondition;
        data["GTDDate"] = toUtf(pOrder->GTDDate);
        data["VolumeCondition"] = pOrder->VolumeCondition;
        data["MinVolume"] = pOrder->MinVolume;
        data["ContingentCondition"] = pOrder->ContingentCondition;
        data["StopPrice"] = pOrder->StopPrice;
        data["ForceCloseReason"] = pOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pOrder->BusinessUnit);
        data["RequestID"] = pOrder->RequestID;
        data["OrderLocalID"] = toUtf(pOrder->OrderLocalID);
        data["ExchangeID"] = toUtf(pOrder->ExchangeID);
        data["ParticipantID"] = toUtf(pOrder->ParticipantID);
        data["ClientID"] = toUtf(pOrder->ClientID);
        data["ExchangeInstID"] = toUtf(pOrder->ExchangeInstID);
        data["TraderID"] = toUtf(pOrder->TraderID);
        data["InstallID"] = pOrder->InstallID;
        data["OrderSubmitStatus"] = pOrder->OrderSubmitStatus;
        data["NotifySequence"] = pOrder->NotifySequence;
        data["TradingDay"] = toUtf(pOrder->TradingDay);
        data["SettlementID"] = pOrder->SettlementID;
        data["OrderSysID"] = toUtf(pOrder->OrderSysID);
        data["OrderSource"] = pOrder->OrderSource;
        data["OrderStatus"] = pOrder->OrderStatus;
        data["OrderType"] = pOrder->OrderType;
        data["VolumeTraded"] = pOrder->VolumeTraded;
        data["VolumeTotal"] = pOrder->VolumeTotal;
        data["InsertDate"] = toUtf(pOrder->InsertDate);
        data["InsertTime"] = toUtf(pOrder->InsertTime);
        data["ActiveTime"] = toUtf(pOrder->ActiveTime);
        data["SuspendTime"] = toUtf(pOrder->SuspendTime);
        data["UpdateTime"] = toUtf(pOrder->UpdateTime);
        data["CancelTime"] = toUtf(pOrder->CancelTime);
        data["ActiveTraderID"] = toUtf(pOrder->ActiveTraderID);
        data["ClearingPartID"] = toUtf(pOrder->ClearingPartID);
        data["SequenceNo"] = pOrder->SequenceNo;
        data["FrontID"] = pOrder->FrontID;
        data["SessionID"] = pOrder->SessionID;
        data["UserProductInfo"] = toUtf(pOrder->UserProductInfo);
        data["StatusMsg"] = toUtf(pOrder->StatusMsg);
        data["UserForceClose"] = pOrder->UserForceClose;
        data["ActiveUserID"] = toUtf(pOrder->ActiveUserID);
        data["BrokerOrderSeq"] = pOrder->BrokerOrderSeq;
        data["RelativeOrderSysID"] = toUtf(pOrder->RelativeOrderSysID);
        data["ZCETotalTradedVolume"] = pOrder->ZCETotalTradedVolume;
        data["IsSwapOrder"] = pOrder->IsSwapOrder;
        data["BranchID"] = toUtf(pOrder->BranchID);
        data["InvestUnitID"] = toUtf(pOrder->InvestUnitID);
        data["AccountID"] = toUtf(pOrder->AccountID);
        data["CurrencyID"] = toUtf(pOrder->CurrencyID);
        data["IPAddress"] = toUtf(pOrder->IPAddress);
        data["MacAddress"] = toUtf(pOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryOrder(data,error,nRequestID,bIsLast);
}

///请求查询成交响应
void PyTdApi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTrade)
    {
        data["BrokerID"] = toUtf(pTrade->BrokerID);
        data["InvestorID"] = toUtf(pTrade->InvestorID);
        data["InstrumentID"] = toUtf(pTrade->InstrumentID);
        data["OrderRef"] = toUtf(pTrade->OrderRef);
        data["UserID"] = toUtf(pTrade->UserID);
        data["ExchangeID"] = toUtf(pTrade->ExchangeID);
        data["TradeID"] = toUtf(pTrade->TradeID);
        data["Direction"] = pTrade->Direction;
        data["OrderSysID"] = toUtf(pTrade->OrderSysID);
        data["ParticipantID"] = toUtf(pTrade->ParticipantID);
        data["ClientID"] = toUtf(pTrade->ClientID);
        data["TradingRole"] = pTrade->TradingRole;
        data["ExchangeInstID"] = toUtf(pTrade->ExchangeInstID);
        data["OffsetFlag"] = pTrade->OffsetFlag;
        data["HedgeFlag"] = pTrade->HedgeFlag;
        data["Price"] = pTrade->Price;
        data["Volume"] = pTrade->Volume;
        data["TradeDate"] = toUtf(pTrade->TradeDate);
        data["TradeTime"] = toUtf(pTrade->TradeTime);
        data["TradeType"] = pTrade->TradeType;
        data["PriceSource"] = pTrade->PriceSource;
        data["TraderID"] = toUtf(pTrade->TraderID);
        data["OrderLocalID"] = toUtf(pTrade->OrderLocalID);
        data["ClearingPartID"] = toUtf(pTrade->ClearingPartID);
        data["BusinessUnit"] = toUtf(pTrade->BusinessUnit);
        data["SequenceNo"] = pTrade->SequenceNo;
        data["TradingDay"] = toUtf(pTrade->TradingDay);
        data["SettlementID"] = pTrade->SettlementID;
        data["BrokerOrderSeq"] = pTrade->BrokerOrderSeq;
        data["TradeSource"] = pTrade->TradeSource;
        data["InvestUnitID"] = toUtf(pTrade->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTrade(data,error,nRequestID,bIsLast);
}

///请求查询投资者持仓响应
void PyTdApi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestorPosition)
    {
        data["InstrumentID"] = toUtf(pInvestorPosition->InstrumentID);
        data["BrokerID"] = toUtf(pInvestorPosition->BrokerID);
        data["InvestorID"] = toUtf(pInvestorPosition->InvestorID);
        data["PosiDirection"] = pInvestorPosition->PosiDirection;
        data["HedgeFlag"] = pInvestorPosition->HedgeFlag;
        data["PositionDate"] = pInvestorPosition->PositionDate;
        data["YdPosition"] = pInvestorPosition->YdPosition;
        data["Position"] = pInvestorPosition->Position;
        data["LongFrozen"] = pInvestorPosition->LongFrozen;
        data["ShortFrozen"] = pInvestorPosition->ShortFrozen;
        data["LongFrozenAmount"] = pInvestorPosition->LongFrozenAmount;
        data["ShortFrozenAmount"] = pInvestorPosition->ShortFrozenAmount;
        data["OpenVolume"] = pInvestorPosition->OpenVolume;
        data["CloseVolume"] = pInvestorPosition->CloseVolume;
        data["OpenAmount"] = pInvestorPosition->OpenAmount;
        data["CloseAmount"] = pInvestorPosition->CloseAmount;
        data["PositionCost"] = pInvestorPosition->PositionCost;
        data["PreMargin"] = pInvestorPosition->PreMargin;
        data["UseMargin"] = pInvestorPosition->UseMargin;
        data["FrozenMargin"] = pInvestorPosition->FrozenMargin;
        data["FrozenCash"] = pInvestorPosition->FrozenCash;
        data["FrozenCommission"] = pInvestorPosition->FrozenCommission;
        data["CashIn"] = pInvestorPosition->CashIn;
        data["Commission"] = pInvestorPosition->Commission;
        data["CloseProfit"] = pInvestorPosition->CloseProfit;
        data["PositionProfit"] = pInvestorPosition->PositionProfit;
        data["PreSettlementPrice"] = pInvestorPosition->PreSettlementPrice;
        data["SettlementPrice"] = pInvestorPosition->SettlementPrice;
        data["TradingDay"] = toUtf(pInvestorPosition->TradingDay);
        data["SettlementID"] = pInvestorPosition->SettlementID;
        data["OpenCost"] = pInvestorPosition->OpenCost;
        data["ExchangeMargin"] = pInvestorPosition->ExchangeMargin;
        data["CombPosition"] = pInvestorPosition->CombPosition;
        data["CombLongFrozen"] = pInvestorPosition->CombLongFrozen;
        data["CombShortFrozen"] = pInvestorPosition->CombShortFrozen;
        data["CloseProfitByDate"] = pInvestorPosition->CloseProfitByDate;
        data["CloseProfitByTrade"] = pInvestorPosition->CloseProfitByTrade;
        data["TodayPosition"] = pInvestorPosition->TodayPosition;
        data["MarginRateByMoney"] = pInvestorPosition->MarginRateByMoney;
        data["MarginRateByVolume"] = pInvestorPosition->MarginRateByVolume;
        data["StrikeFrozen"] = pInvestorPosition->StrikeFrozen;
        data["StrikeFrozenAmount"] = pInvestorPosition->StrikeFrozenAmount;
        data["AbandonFrozen"] = pInvestorPosition->AbandonFrozen;
        data["ExchangeID"] = toUtf(pInvestorPosition->ExchangeID);
        data["YdStrikeFrozen"] = pInvestorPosition->YdStrikeFrozen;
        data["InvestUnitID"] = toUtf(pInvestorPosition->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestorPosition(data,error,nRequestID,bIsLast);
}

///请求查询资金账户响应
void PyTdApi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingAccount)
    {
        data["BrokerID"] = toUtf(pTradingAccount->BrokerID);
        data["AccountID"] = toUtf(pTradingAccount->AccountID);
        data["PreMortgage"] = pTradingAccount->PreMortgage;
        data["PreCredit"] = pTradingAccount->PreCredit;
        data["PreDeposit"] = pTradingAccount->PreDeposit;
        data["PreBalance"] = pTradingAccount->PreBalance;
        data["PreMargin"] = pTradingAccount->PreMargin;
        data["InterestBase"] = pTradingAccount->InterestBase;
        data["Interest"] = pTradingAccount->Interest;
        data["Deposit"] = pTradingAccount->Deposit;
        data["Withdraw"] = pTradingAccount->Withdraw;
        data["FrozenMargin"] = pTradingAccount->FrozenMargin;
        data["FrozenCash"] = pTradingAccount->FrozenCash;
        data["FrozenCommission"] = pTradingAccount->FrozenCommission;
        data["CurrMargin"] = pTradingAccount->CurrMargin;
        data["CashIn"] = pTradingAccount->CashIn;
        data["Commission"] = pTradingAccount->Commission;
        data["CloseProfit"] = pTradingAccount->CloseProfit;
        data["PositionProfit"] = pTradingAccount->PositionProfit;
        data["Balance"] = pTradingAccount->Balance;
        data["Available"] = pTradingAccount->Available;
        data["WithdrawQuota"] = pTradingAccount->WithdrawQuota;
        data["Reserve"] = pTradingAccount->Reserve;
        data["TradingDay"] = toUtf(pTradingAccount->TradingDay);
        data["SettlementID"] = pTradingAccount->SettlementID;
        data["Credit"] = pTradingAccount->Credit;
        data["Mortgage"] = pTradingAccount->Mortgage;
        data["ExchangeMargin"] = pTradingAccount->ExchangeMargin;
        data["DeliveryMargin"] = pTradingAccount->DeliveryMargin;
        data["ExchangeDeliveryMargin"] = pTradingAccount->ExchangeDeliveryMargin;
        data["ReserveBalance"] = pTradingAccount->ReserveBalance;
        data["CurrencyID"] = toUtf(pTradingAccount->CurrencyID);
        data["PreFundMortgageIn"] = pTradingAccount->PreFundMortgageIn;
        data["PreFundMortgageOut"] = pTradingAccount->PreFundMortgageOut;
        data["FundMortgageIn"] = pTradingAccount->FundMortgageIn;
        data["FundMortgageOut"] = pTradingAccount->FundMortgageOut;
        data["FundMortgageAvailable"] = pTradingAccount->FundMortgageAvailable;
        data["MortgageableFund"] = pTradingAccount->MortgageableFund;
        data["SpecProductMargin"] = pTradingAccount->SpecProductMargin;
        data["SpecProductFrozenMargin"] = pTradingAccount->SpecProductFrozenMargin;
        data["SpecProductCommission"] = pTradingAccount->SpecProductCommission;
        data["SpecProductFrozenCommission"] = pTradingAccount->SpecProductFrozenCommission;
        data["SpecProductPositionProfit"] = pTradingAccount->SpecProductPositionProfit;
        data["SpecProductCloseProfit"] = pTradingAccount->SpecProductCloseProfit;
        data["SpecProductPositionProfitByAlg"] = pTradingAccount->SpecProductPositionProfitByAlg;
        data["SpecProductExchangeMargin"] = pTradingAccount->SpecProductExchangeMargin;
        data["BizType"] = pTradingAccount->BizType;
        data["FrozenSwap"] = pTradingAccount->FrozenSwap;
        data["RemainSwap"] = pTradingAccount->RemainSwap;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTradingAccount(data,error,nRequestID,bIsLast);
}

///请求查询投资者响应
void PyTdApi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestor)
    {
        data["InvestorID"] = toUtf(pInvestor->InvestorID);
        data["BrokerID"] = toUtf(pInvestor->BrokerID);
        data["InvestorGroupID"] = toUtf(pInvestor->InvestorGroupID);
        data["InvestorName"] = toUtf(pInvestor->InvestorName);
        data["IdentifiedCardType"] = pInvestor->IdentifiedCardType;
        data["IdentifiedCardNo"] = toUtf(pInvestor->IdentifiedCardNo);
        data["IsActive"] = pInvestor->IsActive;
        data["Telephone"] = toUtf(pInvestor->Telephone);
        data["Address"] = toUtf(pInvestor->Address);
        data["OpenDate"] = toUtf(pInvestor->OpenDate);
        data["Mobile"] = toUtf(pInvestor->Mobile);
        data["CommModelID"] = toUtf(pInvestor->CommModelID);
        data["MarginModelID"] = toUtf(pInvestor->MarginModelID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestor(data,error,nRequestID,bIsLast);
}

///请求查询交易编码响应
void PyTdApi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingCode)
    {
        data["InvestorID"] = toUtf(pTradingCode->InvestorID);
        data["BrokerID"] = toUtf(pTradingCode->BrokerID);
        data["ExchangeID"] = toUtf(pTradingCode->ExchangeID);
        data["ClientID"] = toUtf(pTradingCode->ClientID);
        data["IsActive"] = pTradingCode->IsActive;
        data["ClientIDType"] = pTradingCode->ClientIDType;
        data["BranchID"] = toUtf(pTradingCode->BranchID);
        data["BizType"] = pTradingCode->BizType;
        data["InvestUnitID"] = toUtf(pTradingCode->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTradingCode(data,error,nRequestID,bIsLast);
}

///请求查询合约保证金率响应
void PyTdApi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrumentMarginRate)
    {
        data["InstrumentID"] = toUtf(pInstrumentMarginRate->InstrumentID);
        data["InvestorRange"] = pInstrumentMarginRate->InvestorRange;
        data["BrokerID"] = toUtf(pInstrumentMarginRate->BrokerID);
        data["InvestorID"] = toUtf(pInstrumentMarginRate->InvestorID);
        data["HedgeFlag"] = pInstrumentMarginRate->HedgeFlag;
        data["LongMarginRatioByMoney"] = pInstrumentMarginRate->LongMarginRatioByMoney;
        data["LongMarginRatioByVolume"] = pInstrumentMarginRate->LongMarginRatioByVolume;
        data["ShortMarginRatioByMoney"] = pInstrumentMarginRate->ShortMarginRatioByMoney;
        data["ShortMarginRatioByVolume"] = pInstrumentMarginRate->ShortMarginRatioByVolume;
        data["IsRelative"] = pInstrumentMarginRate->IsRelative;
        data["ExchangeID"] = toUtf(pInstrumentMarginRate->ExchangeID);
        data["InvestUnitID"] = toUtf(pInstrumentMarginRate->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInstrumentMarginRate(data,error,nRequestID,bIsLast);
}

///请求查询合约手续费率响应
void PyTdApi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrumentCommissionRate)
    {
        data["InstrumentID"] = toUtf(pInstrumentCommissionRate->InstrumentID);
        data["InvestorRange"] = pInstrumentCommissionRate->InvestorRange;
        data["BrokerID"] = toUtf(pInstrumentCommissionRate->BrokerID);
        data["InvestorID"] = toUtf(pInstrumentCommissionRate->InvestorID);
        data["OpenRatioByMoney"] = pInstrumentCommissionRate->OpenRatioByMoney;
        data["OpenRatioByVolume"] = pInstrumentCommissionRate->OpenRatioByVolume;
        data["CloseRatioByMoney"] = pInstrumentCommissionRate->CloseRatioByMoney;
        data["CloseRatioByVolume"] = pInstrumentCommissionRate->CloseRatioByVolume;
        data["CloseTodayRatioByMoney"] = pInstrumentCommissionRate->CloseTodayRatioByMoney;
        data["CloseTodayRatioByVolume"] = pInstrumentCommissionRate->CloseTodayRatioByVolume;
        data["ExchangeID"] = toUtf(pInstrumentCommissionRate->ExchangeID);
        data["BizType"] = pInstrumentCommissionRate->BizType;
        data["InvestUnitID"] = toUtf(pInstrumentCommissionRate->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInstrumentCommissionRate(data,error,nRequestID,bIsLast);
}

///请求查询交易所响应
void PyTdApi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExchange)
    {
        data["ExchangeID"] = toUtf(pExchange->ExchangeID);
        data["ExchangeName"] = toUtf(pExchange->ExchangeName);
        data["ExchangeProperty"] = pExchange->ExchangeProperty;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryExchange(data,error,nRequestID,bIsLast);
}

///请求查询产品响应
void PyTdApi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pProduct)
    {
        data["ProductID"] = toUtf(pProduct->ProductID);
        data["ProductName"] = toUtf(pProduct->ProductName);
        data["ExchangeID"] = toUtf(pProduct->ExchangeID);
        data["ProductClass"] = pProduct->ProductClass;
        data["VolumeMultiple"] = pProduct->VolumeMultiple;
        data["PriceTick"] = pProduct->PriceTick;
        data["MaxMarketOrderVolume"] = pProduct->MaxMarketOrderVolume;
        data["MinMarketOrderVolume"] = pProduct->MinMarketOrderVolume;
        data["MaxLimitOrderVolume"] = pProduct->MaxLimitOrderVolume;
        data["MinLimitOrderVolume"] = pProduct->MinLimitOrderVolume;
        data["PositionType"] = pProduct->PositionType;
        data["PositionDateType"] = pProduct->PositionDateType;
        data["CloseDealType"] = pProduct->CloseDealType;
        data["TradeCurrencyID"] = toUtf(pProduct->TradeCurrencyID);
        data["MortgageFundUseRange"] = pProduct->MortgageFundUseRange;
        data["ExchangeProductID"] = toUtf(pProduct->ExchangeProductID);
        data["UnderlyingMultiple"] = pProduct->UnderlyingMultiple;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryProduct(data,error,nRequestID,bIsLast);
}

///请求查询合约响应
void PyTdApi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrument)
    {
        data["InstrumentID"] = toUtf(pInstrument->InstrumentID);
        data["ExchangeID"] = toUtf(pInstrument->ExchangeID);
        data["InstrumentName"] = toUtf(pInstrument->InstrumentName);
        data["ExchangeInstID"] = toUtf(pInstrument->ExchangeInstID);
        data["ProductID"] = toUtf(pInstrument->ProductID);
        data["ProductClass"] = pInstrument->ProductClass;
        data["DeliveryYear"] = pInstrument->DeliveryYear;
        data["DeliveryMonth"] = pInstrument->DeliveryMonth;
        data["MaxMarketOrderVolume"] = pInstrument->MaxMarketOrderVolume;
        data["MinMarketOrderVolume"] = pInstrument->MinMarketOrderVolume;
        data["MaxLimitOrderVolume"] = pInstrument->MaxLimitOrderVolume;
        data["MinLimitOrderVolume"] = pInstrument->MinLimitOrderVolume;
        data["VolumeMultiple"] = pInstrument->VolumeMultiple;
        data["PriceTick"] = pInstrument->PriceTick;
        data["CreateDate"] = toUtf(pInstrument->CreateDate);
        data["OpenDate"] = toUtf(pInstrument->OpenDate);
        data["ExpireDate"] = toUtf(pInstrument->ExpireDate);
        data["StartDelivDate"] = toUtf(pInstrument->StartDelivDate);
        data["EndDelivDate"] = toUtf(pInstrument->EndDelivDate);
        data["InstLifePhase"] = pInstrument->InstLifePhase;
        data["IsTrading"] = pInstrument->IsTrading;
        data["PositionType"] = pInstrument->PositionType;
        data["PositionDateType"] = pInstrument->PositionDateType;
        data["LongMarginRatio"] = pInstrument->LongMarginRatio;
        data["ShortMarginRatio"] = pInstrument->ShortMarginRatio;
        data["MaxMarginSideAlgorithm"] = pInstrument->MaxMarginSideAlgorithm;
        data["UnderlyingInstrID"] = toUtf(pInstrument->UnderlyingInstrID);
        data["StrikePrice"] = pInstrument->StrikePrice;
        data["OptionsType"] = pInstrument->OptionsType;
        data["UnderlyingMultiple"] = pInstrument->UnderlyingMultiple;
        data["CombinationType"] = pInstrument->CombinationType;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInstrument(data,error,nRequestID,bIsLast);
}

///请求查询行情响应
void PyTdApi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
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
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryDepthMarketData(data,error,nRequestID,bIsLast);
}

///请求查询投资者结算结果响应
void PyTdApi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSettlementInfo)
    {
        data["TradingDay"] = toUtf(pSettlementInfo->TradingDay);
        data["SettlementID"] = pSettlementInfo->SettlementID;
        data["BrokerID"] = toUtf(pSettlementInfo->BrokerID);
        data["InvestorID"] = toUtf(pSettlementInfo->InvestorID);
        data["SequenceNo"] = pSettlementInfo->SequenceNo;
        data["Content"] = toUtf(pSettlementInfo->Content);
        data["AccountID"] = toUtf(pSettlementInfo->AccountID);
        data["CurrencyID"] = toUtf(pSettlementInfo->CurrencyID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySettlementInfo(data,error,nRequestID,bIsLast);
}

///请求查询转帐银行响应
void PyTdApi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTransferBank)
    {
        data["BankID"] = toUtf(pTransferBank->BankID);
        data["BankBrchID"] = toUtf(pTransferBank->BankBrchID);
        data["BankName"] = toUtf(pTransferBank->BankName);
        data["IsActive"] = pTransferBank->IsActive;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTransferBank(data,error,nRequestID,bIsLast);
}

///请求查询投资者持仓明细响应
void PyTdApi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestorPositionDetail)
    {
        data["InstrumentID"] = toUtf(pInvestorPositionDetail->InstrumentID);
        data["BrokerID"] = toUtf(pInvestorPositionDetail->BrokerID);
        data["InvestorID"] = toUtf(pInvestorPositionDetail->InvestorID);
        data["HedgeFlag"] = pInvestorPositionDetail->HedgeFlag;
        data["Direction"] = pInvestorPositionDetail->Direction;
        data["OpenDate"] = toUtf(pInvestorPositionDetail->OpenDate);
        data["TradeID"] = toUtf(pInvestorPositionDetail->TradeID);
        data["Volume"] = pInvestorPositionDetail->Volume;
        data["OpenPrice"] = pInvestorPositionDetail->OpenPrice;
        data["TradingDay"] = toUtf(pInvestorPositionDetail->TradingDay);
        data["SettlementID"] = pInvestorPositionDetail->SettlementID;
        data["TradeType"] = pInvestorPositionDetail->TradeType;
        data["CombInstrumentID"] = toUtf(pInvestorPositionDetail->CombInstrumentID);
        data["ExchangeID"] = toUtf(pInvestorPositionDetail->ExchangeID);
        data["CloseProfitByDate"] = pInvestorPositionDetail->CloseProfitByDate;
        data["CloseProfitByTrade"] = pInvestorPositionDetail->CloseProfitByTrade;
        data["PositionProfitByDate"] = pInvestorPositionDetail->PositionProfitByDate;
        data["PositionProfitByTrade"] = pInvestorPositionDetail->PositionProfitByTrade;
        data["Margin"] = pInvestorPositionDetail->Margin;
        data["ExchMargin"] = pInvestorPositionDetail->ExchMargin;
        data["MarginRateByMoney"] = pInvestorPositionDetail->MarginRateByMoney;
        data["MarginRateByVolume"] = pInvestorPositionDetail->MarginRateByVolume;
        data["LastSettlementPrice"] = pInvestorPositionDetail->LastSettlementPrice;
        data["SettlementPrice"] = pInvestorPositionDetail->SettlementPrice;
        data["CloseVolume"] = pInvestorPositionDetail->CloseVolume;
        data["CloseAmount"] = pInvestorPositionDetail->CloseAmount;
        data["InvestUnitID"] = toUtf(pInvestorPositionDetail->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestorPositionDetail(data,error,nRequestID,bIsLast);
}

///请求查询客户通知响应
void PyTdApi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pNotice)
    {
        data["BrokerID"] = toUtf(pNotice->BrokerID);
        data["Content"] = toUtf(pNotice->Content);
        data["SequenceLabel"] = toUtf(pNotice->SequenceLabel);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryNotice(data,error,nRequestID,bIsLast);
}

///请求查询结算信息确认响应
void PyTdApi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSettlementInfoConfirm)
    {
        data["BrokerID"] = toUtf(pSettlementInfoConfirm->BrokerID);
        data["InvestorID"] = toUtf(pSettlementInfoConfirm->InvestorID);
        data["ConfirmDate"] = toUtf(pSettlementInfoConfirm->ConfirmDate);
        data["ConfirmTime"] = toUtf(pSettlementInfoConfirm->ConfirmTime);
        data["SettlementID"] = pSettlementInfoConfirm->SettlementID;
        data["AccountID"] = toUtf(pSettlementInfoConfirm->AccountID);
        data["CurrencyID"] = toUtf(pSettlementInfoConfirm->CurrencyID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySettlementInfoConfirm(data,error,nRequestID,bIsLast);
}

///请求查询投资者持仓明细响应
void PyTdApi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestorPositionCombineDetail)
    {
        data["TradingDay"] = toUtf(pInvestorPositionCombineDetail->TradingDay);
        data["OpenDate"] = toUtf(pInvestorPositionCombineDetail->OpenDate);
        data["ExchangeID"] = toUtf(pInvestorPositionCombineDetail->ExchangeID);
        data["SettlementID"] = pInvestorPositionCombineDetail->SettlementID;
        data["BrokerID"] = toUtf(pInvestorPositionCombineDetail->BrokerID);
        data["InvestorID"] = toUtf(pInvestorPositionCombineDetail->InvestorID);
        data["ComTradeID"] = toUtf(pInvestorPositionCombineDetail->ComTradeID);
        data["TradeID"] = toUtf(pInvestorPositionCombineDetail->TradeID);
        data["InstrumentID"] = toUtf(pInvestorPositionCombineDetail->InstrumentID);
        data["HedgeFlag"] = pInvestorPositionCombineDetail->HedgeFlag;
        data["Direction"] = pInvestorPositionCombineDetail->Direction;
        data["TotalAmt"] = pInvestorPositionCombineDetail->TotalAmt;
        data["Margin"] = pInvestorPositionCombineDetail->Margin;
        data["ExchMargin"] = pInvestorPositionCombineDetail->ExchMargin;
        data["MarginRateByMoney"] = pInvestorPositionCombineDetail->MarginRateByMoney;
        data["MarginRateByVolume"] = pInvestorPositionCombineDetail->MarginRateByVolume;
        data["LegID"] = pInvestorPositionCombineDetail->LegID;
        data["LegMultiple"] = pInvestorPositionCombineDetail->LegMultiple;
        data["CombInstrumentID"] = toUtf(pInvestorPositionCombineDetail->CombInstrumentID);
        data["TradeGroupID"] = pInvestorPositionCombineDetail->TradeGroupID;
        data["InvestUnitID"] = toUtf(pInvestorPositionCombineDetail->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestorPositionCombineDetail(data,error,nRequestID,bIsLast);
}

///查询保证金监管系统经纪公司资金账户密钥响应
void PyTdApi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCFMMCTradingAccountKey)
    {
        data["BrokerID"] = toUtf(pCFMMCTradingAccountKey->BrokerID);
        data["ParticipantID"] = toUtf(pCFMMCTradingAccountKey->ParticipantID);
        data["AccountID"] = toUtf(pCFMMCTradingAccountKey->AccountID);
        data["KeyID"] = pCFMMCTradingAccountKey->KeyID;
        data["CurrentKey"] = toUtf(pCFMMCTradingAccountKey->CurrentKey);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryCFMMCTradingAccountKey(data,error,nRequestID,bIsLast);
}

///请求查询仓单折抵信息响应
void PyTdApi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pEWarrantOffset)
    {
        data["TradingDay"] = toUtf(pEWarrantOffset->TradingDay);
        data["BrokerID"] = toUtf(pEWarrantOffset->BrokerID);
        data["InvestorID"] = toUtf(pEWarrantOffset->InvestorID);
        data["ExchangeID"] = toUtf(pEWarrantOffset->ExchangeID);
        data["InstrumentID"] = toUtf(pEWarrantOffset->InstrumentID);
        data["Direction"] = pEWarrantOffset->Direction;
        data["HedgeFlag"] = pEWarrantOffset->HedgeFlag;
        data["Volume"] = pEWarrantOffset->Volume;
        data["InvestUnitID"] = toUtf(pEWarrantOffset->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryEWarrantOffset(data,error,nRequestID,bIsLast);
}

///请求查询投资者品种/跨品种保证金响应
void PyTdApi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestorProductGroupMargin)
    {
        data["ProductGroupID"] = toUtf(pInvestorProductGroupMargin->ProductGroupID);
        data["BrokerID"] = toUtf(pInvestorProductGroupMargin->BrokerID);
        data["InvestorID"] = toUtf(pInvestorProductGroupMargin->InvestorID);
        data["TradingDay"] = toUtf(pInvestorProductGroupMargin->TradingDay);
        data["SettlementID"] = pInvestorProductGroupMargin->SettlementID;
        data["FrozenMargin"] = pInvestorProductGroupMargin->FrozenMargin;
        data["LongFrozenMargin"] = pInvestorProductGroupMargin->LongFrozenMargin;
        data["ShortFrozenMargin"] = pInvestorProductGroupMargin->ShortFrozenMargin;
        data["UseMargin"] = pInvestorProductGroupMargin->UseMargin;
        data["LongUseMargin"] = pInvestorProductGroupMargin->LongUseMargin;
        data["ShortUseMargin"] = pInvestorProductGroupMargin->ShortUseMargin;
        data["ExchMargin"] = pInvestorProductGroupMargin->ExchMargin;
        data["LongExchMargin"] = pInvestorProductGroupMargin->LongExchMargin;
        data["ShortExchMargin"] = pInvestorProductGroupMargin->ShortExchMargin;
        data["CloseProfit"] = pInvestorProductGroupMargin->CloseProfit;
        data["FrozenCommission"] = pInvestorProductGroupMargin->FrozenCommission;
        data["Commission"] = pInvestorProductGroupMargin->Commission;
        data["FrozenCash"] = pInvestorProductGroupMargin->FrozenCash;
        data["CashIn"] = pInvestorProductGroupMargin->CashIn;
        data["PositionProfit"] = pInvestorProductGroupMargin->PositionProfit;
        data["OffsetAmount"] = pInvestorProductGroupMargin->OffsetAmount;
        data["LongOffsetAmount"] = pInvestorProductGroupMargin->LongOffsetAmount;
        data["ShortOffsetAmount"] = pInvestorProductGroupMargin->ShortOffsetAmount;
        data["ExchOffsetAmount"] = pInvestorProductGroupMargin->ExchOffsetAmount;
        data["LongExchOffsetAmount"] = pInvestorProductGroupMargin->LongExchOffsetAmount;
        data["ShortExchOffsetAmount"] = pInvestorProductGroupMargin->ShortExchOffsetAmount;
        data["HedgeFlag"] = pInvestorProductGroupMargin->HedgeFlag;
        data["ExchangeID"] = toUtf(pInvestorProductGroupMargin->ExchangeID);
        data["InvestUnitID"] = toUtf(pInvestorProductGroupMargin->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestorProductGroupMargin(data,error,nRequestID,bIsLast);
}

///请求查询交易所保证金率响应
void PyTdApi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExchangeMarginRate)
    {
        data["BrokerID"] = toUtf(pExchangeMarginRate->BrokerID);
        data["InstrumentID"] = toUtf(pExchangeMarginRate->InstrumentID);
        data["HedgeFlag"] = pExchangeMarginRate->HedgeFlag;
        data["LongMarginRatioByMoney"] = pExchangeMarginRate->LongMarginRatioByMoney;
        data["LongMarginRatioByVolume"] = pExchangeMarginRate->LongMarginRatioByVolume;
        data["ShortMarginRatioByMoney"] = pExchangeMarginRate->ShortMarginRatioByMoney;
        data["ShortMarginRatioByVolume"] = pExchangeMarginRate->ShortMarginRatioByVolume;
        data["ExchangeID"] = toUtf(pExchangeMarginRate->ExchangeID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryExchangeMarginRate(data,error,nRequestID,bIsLast);
}

///请求查询交易所调整保证金率响应
void PyTdApi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExchangeMarginRateAdjust)
    {
        data["BrokerID"] = toUtf(pExchangeMarginRateAdjust->BrokerID);
        data["InstrumentID"] = toUtf(pExchangeMarginRateAdjust->InstrumentID);
        data["HedgeFlag"] = pExchangeMarginRateAdjust->HedgeFlag;
        data["LongMarginRatioByMoney"] = pExchangeMarginRateAdjust->LongMarginRatioByMoney;
        data["LongMarginRatioByVolume"] = pExchangeMarginRateAdjust->LongMarginRatioByVolume;
        data["ShortMarginRatioByMoney"] = pExchangeMarginRateAdjust->ShortMarginRatioByMoney;
        data["ShortMarginRatioByVolume"] = pExchangeMarginRateAdjust->ShortMarginRatioByVolume;
        data["ExchLongMarginRatioByMoney"] = pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney;
        data["ExchLongMarginRatioByVolume"] = pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume;
        data["ExchShortMarginRatioByMoney"] = pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney;
        data["ExchShortMarginRatioByVolume"] = pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume;
        data["NoLongMarginRatioByMoney"] = pExchangeMarginRateAdjust->NoLongMarginRatioByMoney;
        data["NoLongMarginRatioByVolume"] = pExchangeMarginRateAdjust->NoLongMarginRatioByVolume;
        data["NoShortMarginRatioByMoney"] = pExchangeMarginRateAdjust->NoShortMarginRatioByMoney;
        data["NoShortMarginRatioByVolume"] = pExchangeMarginRateAdjust->NoShortMarginRatioByVolume;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryExchangeMarginRateAdjust(data,error,nRequestID,bIsLast);
}

///请求查询汇率响应
void PyTdApi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExchangeRate)
    {
        data["BrokerID"] = toUtf(pExchangeRate->BrokerID);
        data["FromCurrencyID"] = toUtf(pExchangeRate->FromCurrencyID);
        data["FromCurrencyUnit"] = pExchangeRate->FromCurrencyUnit;
        data["ToCurrencyID"] = toUtf(pExchangeRate->ToCurrencyID);
        data["ExchangeRate"] = pExchangeRate->ExchangeRate;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryExchangeRate(data,error,nRequestID,bIsLast);
}

///请求查询二级代理操作员银期权限响应
void PyTdApi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSecAgentACIDMap)
    {
        data["BrokerID"] = toUtf(pSecAgentACIDMap->BrokerID);
        data["UserID"] = toUtf(pSecAgentACIDMap->UserID);
        data["AccountID"] = toUtf(pSecAgentACIDMap->AccountID);
        data["CurrencyID"] = toUtf(pSecAgentACIDMap->CurrencyID);
        data["BrokerSecAgentID"] = toUtf(pSecAgentACIDMap->BrokerSecAgentID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySecAgentACIDMap(data,error,nRequestID,bIsLast);
}

///请求查询产品报价汇率
void PyTdApi::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pProductExchRate)
    {
        data["ProductID"] = toUtf(pProductExchRate->ProductID);
        data["QuoteCurrencyID"] = toUtf(pProductExchRate->QuoteCurrencyID);
        data["ExchangeRate"] = pProductExchRate->ExchangeRate;
        data["ExchangeID"] = toUtf(pProductExchRate->ExchangeID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryProductExchRate(data,error,nRequestID,bIsLast);
}

///请求查询产品组
void PyTdApi::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pProductGroup)
    {
        data["ProductID"] = toUtf(pProductGroup->ProductID);
        data["ExchangeID"] = toUtf(pProductGroup->ExchangeID);
        data["ProductGroupID"] = toUtf(pProductGroup->ProductGroupID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryProductGroup(data,error,nRequestID,bIsLast);
}

///请求查询做市商合约手续费率响应
void PyTdApi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pMMInstrumentCommissionRate)
    {
        data["InstrumentID"] = toUtf(pMMInstrumentCommissionRate->InstrumentID);
        data["InvestorRange"] = pMMInstrumentCommissionRate->InvestorRange;
        data["BrokerID"] = toUtf(pMMInstrumentCommissionRate->BrokerID);
        data["InvestorID"] = toUtf(pMMInstrumentCommissionRate->InvestorID);
        data["OpenRatioByMoney"] = pMMInstrumentCommissionRate->OpenRatioByMoney;
        data["OpenRatioByVolume"] = pMMInstrumentCommissionRate->OpenRatioByVolume;
        data["CloseRatioByMoney"] = pMMInstrumentCommissionRate->CloseRatioByMoney;
        data["CloseRatioByVolume"] = pMMInstrumentCommissionRate->CloseRatioByVolume;
        data["CloseTodayRatioByMoney"] = pMMInstrumentCommissionRate->CloseTodayRatioByMoney;
        data["CloseTodayRatioByVolume"] = pMMInstrumentCommissionRate->CloseTodayRatioByVolume;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryMMInstrumentCommissionRate(data,error,nRequestID,bIsLast);
}

///请求查询做市商期权合约手续费响应
void PyTdApi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pMMOptionInstrCommRate)
    {
        data["InstrumentID"] = toUtf(pMMOptionInstrCommRate->InstrumentID);
        data["InvestorRange"] = pMMOptionInstrCommRate->InvestorRange;
        data["BrokerID"] = toUtf(pMMOptionInstrCommRate->BrokerID);
        data["InvestorID"] = toUtf(pMMOptionInstrCommRate->InvestorID);
        data["OpenRatioByMoney"] = pMMOptionInstrCommRate->OpenRatioByMoney;
        data["OpenRatioByVolume"] = pMMOptionInstrCommRate->OpenRatioByVolume;
        data["CloseRatioByMoney"] = pMMOptionInstrCommRate->CloseRatioByMoney;
        data["CloseRatioByVolume"] = pMMOptionInstrCommRate->CloseRatioByVolume;
        data["CloseTodayRatioByMoney"] = pMMOptionInstrCommRate->CloseTodayRatioByMoney;
        data["CloseTodayRatioByVolume"] = pMMOptionInstrCommRate->CloseTodayRatioByVolume;
        data["StrikeRatioByMoney"] = pMMOptionInstrCommRate->StrikeRatioByMoney;
        data["StrikeRatioByVolume"] = pMMOptionInstrCommRate->StrikeRatioByVolume;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryMMOptionInstrCommRate(data,error,nRequestID,bIsLast);
}

///请求查询报单手续费响应
void PyTdApi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrumentOrderCommRate)
    {
        data["InstrumentID"] = toUtf(pInstrumentOrderCommRate->InstrumentID);
        data["InvestorRange"] = pInstrumentOrderCommRate->InvestorRange;
        data["BrokerID"] = toUtf(pInstrumentOrderCommRate->BrokerID);
        data["InvestorID"] = toUtf(pInstrumentOrderCommRate->InvestorID);
        data["HedgeFlag"] = pInstrumentOrderCommRate->HedgeFlag;
        data["OrderCommByVolume"] = pInstrumentOrderCommRate->OrderCommByVolume;
        data["OrderActionCommByVolume"] = pInstrumentOrderCommRate->OrderActionCommByVolume;
        data["ExchangeID"] = toUtf(pInstrumentOrderCommRate->ExchangeID);
        data["InvestUnitID"] = toUtf(pInstrumentOrderCommRate->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInstrumentOrderCommRate(data,error,nRequestID,bIsLast);
}

///请求查询资金账户响应
void PyTdApi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingAccount)
    {
        data["BrokerID"] = toUtf(pTradingAccount->BrokerID);
        data["AccountID"] = toUtf(pTradingAccount->AccountID);
        data["PreMortgage"] = pTradingAccount->PreMortgage;
        data["PreCredit"] = pTradingAccount->PreCredit;
        data["PreDeposit"] = pTradingAccount->PreDeposit;
        data["PreBalance"] = pTradingAccount->PreBalance;
        data["PreMargin"] = pTradingAccount->PreMargin;
        data["InterestBase"] = pTradingAccount->InterestBase;
        data["Interest"] = pTradingAccount->Interest;
        data["Deposit"] = pTradingAccount->Deposit;
        data["Withdraw"] = pTradingAccount->Withdraw;
        data["FrozenMargin"] = pTradingAccount->FrozenMargin;
        data["FrozenCash"] = pTradingAccount->FrozenCash;
        data["FrozenCommission"] = pTradingAccount->FrozenCommission;
        data["CurrMargin"] = pTradingAccount->CurrMargin;
        data["CashIn"] = pTradingAccount->CashIn;
        data["Commission"] = pTradingAccount->Commission;
        data["CloseProfit"] = pTradingAccount->CloseProfit;
        data["PositionProfit"] = pTradingAccount->PositionProfit;
        data["Balance"] = pTradingAccount->Balance;
        data["Available"] = pTradingAccount->Available;
        data["WithdrawQuota"] = pTradingAccount->WithdrawQuota;
        data["Reserve"] = pTradingAccount->Reserve;
        data["TradingDay"] = toUtf(pTradingAccount->TradingDay);
        data["SettlementID"] = pTradingAccount->SettlementID;
        data["Credit"] = pTradingAccount->Credit;
        data["Mortgage"] = pTradingAccount->Mortgage;
        data["ExchangeMargin"] = pTradingAccount->ExchangeMargin;
        data["DeliveryMargin"] = pTradingAccount->DeliveryMargin;
        data["ExchangeDeliveryMargin"] = pTradingAccount->ExchangeDeliveryMargin;
        data["ReserveBalance"] = pTradingAccount->ReserveBalance;
        data["CurrencyID"] = toUtf(pTradingAccount->CurrencyID);
        data["PreFundMortgageIn"] = pTradingAccount->PreFundMortgageIn;
        data["PreFundMortgageOut"] = pTradingAccount->PreFundMortgageOut;
        data["FundMortgageIn"] = pTradingAccount->FundMortgageIn;
        data["FundMortgageOut"] = pTradingAccount->FundMortgageOut;
        data["FundMortgageAvailable"] = pTradingAccount->FundMortgageAvailable;
        data["MortgageableFund"] = pTradingAccount->MortgageableFund;
        data["SpecProductMargin"] = pTradingAccount->SpecProductMargin;
        data["SpecProductFrozenMargin"] = pTradingAccount->SpecProductFrozenMargin;
        data["SpecProductCommission"] = pTradingAccount->SpecProductCommission;
        data["SpecProductFrozenCommission"] = pTradingAccount->SpecProductFrozenCommission;
        data["SpecProductPositionProfit"] = pTradingAccount->SpecProductPositionProfit;
        data["SpecProductCloseProfit"] = pTradingAccount->SpecProductCloseProfit;
        data["SpecProductPositionProfitByAlg"] = pTradingAccount->SpecProductPositionProfitByAlg;
        data["SpecProductExchangeMargin"] = pTradingAccount->SpecProductExchangeMargin;
        data["BizType"] = pTradingAccount->BizType;
        data["FrozenSwap"] = pTradingAccount->FrozenSwap;
        data["RemainSwap"] = pTradingAccount->RemainSwap;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySecAgentTradingAccount(data,error,nRequestID,bIsLast);
}

///请求查询二级代理商资金校验模式响应
void PyTdApi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSecAgentCheckMode)
    {
        data["InvestorID"] = toUtf(pSecAgentCheckMode->InvestorID);
        data["BrokerID"] = toUtf(pSecAgentCheckMode->BrokerID);
        data["CurrencyID"] = toUtf(pSecAgentCheckMode->CurrencyID);
        data["BrokerSecAgentID"] = toUtf(pSecAgentCheckMode->BrokerSecAgentID);
        data["CheckSelfAccount"] = pSecAgentCheckMode->CheckSelfAccount;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySecAgentCheckMode(data,error,nRequestID,bIsLast);
}

///请求查询二级代理商信息响应
void PyTdApi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pSecAgentTradeInfo)
    {
        data["BrokerID"] = toUtf(pSecAgentTradeInfo->BrokerID);
        data["BrokerSecAgentID"] = toUtf(pSecAgentTradeInfo->BrokerSecAgentID);
        data["InvestorID"] = toUtf(pSecAgentTradeInfo->InvestorID);
        data["LongCustomerName"] = toUtf(pSecAgentTradeInfo->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQrySecAgentTradeInfo(data,error,nRequestID,bIsLast);
}

///请求查询期权交易成本响应
void PyTdApi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOptionInstrTradeCost)
    {
        data["BrokerID"] = toUtf(pOptionInstrTradeCost->BrokerID);
        data["InvestorID"] = toUtf(pOptionInstrTradeCost->InvestorID);
        data["InstrumentID"] = toUtf(pOptionInstrTradeCost->InstrumentID);
        data["HedgeFlag"] = pOptionInstrTradeCost->HedgeFlag;
        data["FixedMargin"] = pOptionInstrTradeCost->FixedMargin;
        data["MiniMargin"] = pOptionInstrTradeCost->MiniMargin;
        data["Royalty"] = pOptionInstrTradeCost->Royalty;
        data["ExchFixedMargin"] = pOptionInstrTradeCost->ExchFixedMargin;
        data["ExchMiniMargin"] = pOptionInstrTradeCost->ExchMiniMargin;
        data["ExchangeID"] = toUtf(pOptionInstrTradeCost->ExchangeID);
        data["InvestUnitID"] = toUtf(pOptionInstrTradeCost->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryOptionInstrTradeCost(data,error,nRequestID,bIsLast);
}

///请求查询期权合约手续费响应
void PyTdApi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOptionInstrCommRate)
    {
        data["InstrumentID"] = toUtf(pOptionInstrCommRate->InstrumentID);
        data["InvestorRange"] = pOptionInstrCommRate->InvestorRange;
        data["BrokerID"] = toUtf(pOptionInstrCommRate->BrokerID);
        data["InvestorID"] = toUtf(pOptionInstrCommRate->InvestorID);
        data["OpenRatioByMoney"] = pOptionInstrCommRate->OpenRatioByMoney;
        data["OpenRatioByVolume"] = pOptionInstrCommRate->OpenRatioByVolume;
        data["CloseRatioByMoney"] = pOptionInstrCommRate->CloseRatioByMoney;
        data["CloseRatioByVolume"] = pOptionInstrCommRate->CloseRatioByVolume;
        data["CloseTodayRatioByMoney"] = pOptionInstrCommRate->CloseTodayRatioByMoney;
        data["CloseTodayRatioByVolume"] = pOptionInstrCommRate->CloseTodayRatioByVolume;
        data["StrikeRatioByMoney"] = pOptionInstrCommRate->StrikeRatioByMoney;
        data["StrikeRatioByVolume"] = pOptionInstrCommRate->StrikeRatioByVolume;
        data["ExchangeID"] = toUtf(pOptionInstrCommRate->ExchangeID);
        data["InvestUnitID"] = toUtf(pOptionInstrCommRate->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryOptionInstrCommRate(data,error,nRequestID,bIsLast);
}

///请求查询执行宣告响应
void PyTdApi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExecOrder)
    {
        data["BrokerID"] = toUtf(pExecOrder->BrokerID);
        data["InvestorID"] = toUtf(pExecOrder->InvestorID);
        data["InstrumentID"] = toUtf(pExecOrder->InstrumentID);
        data["ExecOrderRef"] = toUtf(pExecOrder->ExecOrderRef);
        data["UserID"] = toUtf(pExecOrder->UserID);
        data["Volume"] = pExecOrder->Volume;
        data["RequestID"] = pExecOrder->RequestID;
        data["BusinessUnit"] = toUtf(pExecOrder->BusinessUnit);
        data["OffsetFlag"] = pExecOrder->OffsetFlag;
        data["HedgeFlag"] = pExecOrder->HedgeFlag;
        data["ActionType"] = pExecOrder->ActionType;
        data["PosiDirection"] = pExecOrder->PosiDirection;
        data["ReservePositionFlag"] = pExecOrder->ReservePositionFlag;
        data["CloseFlag"] = pExecOrder->CloseFlag;
        data["ExecOrderLocalID"] = toUtf(pExecOrder->ExecOrderLocalID);
        data["ExchangeID"] = toUtf(pExecOrder->ExchangeID);
        data["ParticipantID"] = toUtf(pExecOrder->ParticipantID);
        data["ClientID"] = toUtf(pExecOrder->ClientID);
        data["ExchangeInstID"] = toUtf(pExecOrder->ExchangeInstID);
        data["TraderID"] = toUtf(pExecOrder->TraderID);
        data["InstallID"] = pExecOrder->InstallID;
        data["OrderSubmitStatus"] = pExecOrder->OrderSubmitStatus;
        data["NotifySequence"] = pExecOrder->NotifySequence;
        data["TradingDay"] = toUtf(pExecOrder->TradingDay);
        data["SettlementID"] = pExecOrder->SettlementID;
        data["ExecOrderSysID"] = toUtf(pExecOrder->ExecOrderSysID);
        data["InsertDate"] = toUtf(pExecOrder->InsertDate);
        data["InsertTime"] = toUtf(pExecOrder->InsertTime);
        data["CancelTime"] = toUtf(pExecOrder->CancelTime);
        data["ExecResult"] = pExecOrder->ExecResult;
        data["ClearingPartID"] = toUtf(pExecOrder->ClearingPartID);
        data["SequenceNo"] = pExecOrder->SequenceNo;
        data["FrontID"] = pExecOrder->FrontID;
        data["SessionID"] = pExecOrder->SessionID;
        data["UserProductInfo"] = toUtf(pExecOrder->UserProductInfo);
        data["StatusMsg"] = toUtf(pExecOrder->StatusMsg);
        data["ActiveUserID"] = toUtf(pExecOrder->ActiveUserID);
        data["BrokerExecOrderSeq"] = pExecOrder->BrokerExecOrderSeq;
        data["BranchID"] = toUtf(pExecOrder->BranchID);
        data["InvestUnitID"] = toUtf(pExecOrder->InvestUnitID);
        data["AccountID"] = toUtf(pExecOrder->AccountID);
        data["CurrencyID"] = toUtf(pExecOrder->CurrencyID);
        data["IPAddress"] = toUtf(pExecOrder->IPAddress);
        data["MacAddress"] = toUtf(pExecOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryExecOrder(data,error,nRequestID,bIsLast);
}

///请求查询询价响应
void PyTdApi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pForQuote)
    {
        data["BrokerID"] = toUtf(pForQuote->BrokerID);
        data["InvestorID"] = toUtf(pForQuote->InvestorID);
        data["InstrumentID"] = toUtf(pForQuote->InstrumentID);
        data["ForQuoteRef"] = toUtf(pForQuote->ForQuoteRef);
        data["UserID"] = toUtf(pForQuote->UserID);
        data["ForQuoteLocalID"] = toUtf(pForQuote->ForQuoteLocalID);
        data["ExchangeID"] = toUtf(pForQuote->ExchangeID);
        data["ParticipantID"] = toUtf(pForQuote->ParticipantID);
        data["ClientID"] = toUtf(pForQuote->ClientID);
        data["ExchangeInstID"] = toUtf(pForQuote->ExchangeInstID);
        data["TraderID"] = toUtf(pForQuote->TraderID);
        data["InstallID"] = pForQuote->InstallID;
        data["InsertDate"] = toUtf(pForQuote->InsertDate);
        data["InsertTime"] = toUtf(pForQuote->InsertTime);
        data["ForQuoteStatus"] = pForQuote->ForQuoteStatus;
        data["FrontID"] = pForQuote->FrontID;
        data["SessionID"] = pForQuote->SessionID;
        data["StatusMsg"] = toUtf(pForQuote->StatusMsg);
        data["ActiveUserID"] = toUtf(pForQuote->ActiveUserID);
        data["BrokerForQutoSeq"] = pForQuote->BrokerForQutoSeq;
        data["InvestUnitID"] = toUtf(pForQuote->InvestUnitID);
        data["IPAddress"] = toUtf(pForQuote->IPAddress);
        data["MacAddress"] = toUtf(pForQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryForQuote(data,error,nRequestID,bIsLast);
}

///请求查询报价响应
void PyTdApi::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pQuote)
    {
        data["BrokerID"] = toUtf(pQuote->BrokerID);
        data["InvestorID"] = toUtf(pQuote->InvestorID);
        data["InstrumentID"] = toUtf(pQuote->InstrumentID);
        data["QuoteRef"] = toUtf(pQuote->QuoteRef);
        data["UserID"] = toUtf(pQuote->UserID);
        data["AskPrice"] = pQuote->AskPrice;
        data["BidPrice"] = pQuote->BidPrice;
        data["AskVolume"] = pQuote->AskVolume;
        data["BidVolume"] = pQuote->BidVolume;
        data["RequestID"] = pQuote->RequestID;
        data["BusinessUnit"] = toUtf(pQuote->BusinessUnit);
        data["AskOffsetFlag"] = pQuote->AskOffsetFlag;
        data["BidOffsetFlag"] = pQuote->BidOffsetFlag;
        data["AskHedgeFlag"] = pQuote->AskHedgeFlag;
        data["BidHedgeFlag"] = pQuote->BidHedgeFlag;
        data["QuoteLocalID"] = toUtf(pQuote->QuoteLocalID);
        data["ExchangeID"] = toUtf(pQuote->ExchangeID);
        data["ParticipantID"] = toUtf(pQuote->ParticipantID);
        data["ClientID"] = toUtf(pQuote->ClientID);
        data["ExchangeInstID"] = toUtf(pQuote->ExchangeInstID);
        data["TraderID"] = toUtf(pQuote->TraderID);
        data["InstallID"] = pQuote->InstallID;
        data["NotifySequence"] = pQuote->NotifySequence;
        data["OrderSubmitStatus"] = pQuote->OrderSubmitStatus;
        data["TradingDay"] = toUtf(pQuote->TradingDay);
        data["SettlementID"] = pQuote->SettlementID;
        data["QuoteSysID"] = toUtf(pQuote->QuoteSysID);
        data["InsertDate"] = toUtf(pQuote->InsertDate);
        data["InsertTime"] = toUtf(pQuote->InsertTime);
        data["CancelTime"] = toUtf(pQuote->CancelTime);
        data["QuoteStatus"] = pQuote->QuoteStatus;
        data["ClearingPartID"] = toUtf(pQuote->ClearingPartID);
        data["SequenceNo"] = pQuote->SequenceNo;
        data["AskOrderSysID"] = toUtf(pQuote->AskOrderSysID);
        data["BidOrderSysID"] = toUtf(pQuote->BidOrderSysID);
        data["FrontID"] = pQuote->FrontID;
        data["SessionID"] = pQuote->SessionID;
        data["UserProductInfo"] = toUtf(pQuote->UserProductInfo);
        data["StatusMsg"] = toUtf(pQuote->StatusMsg);
        data["ActiveUserID"] = toUtf(pQuote->ActiveUserID);
        data["BrokerQuoteSeq"] = pQuote->BrokerQuoteSeq;
        data["AskOrderRef"] = toUtf(pQuote->AskOrderRef);
        data["BidOrderRef"] = toUtf(pQuote->BidOrderRef);
        data["ForQuoteSysID"] = toUtf(pQuote->ForQuoteSysID);
        data["BranchID"] = toUtf(pQuote->BranchID);
        data["InvestUnitID"] = toUtf(pQuote->InvestUnitID);
        data["AccountID"] = toUtf(pQuote->AccountID);
        data["CurrencyID"] = toUtf(pQuote->CurrencyID);
        data["IPAddress"] = toUtf(pQuote->IPAddress);
        data["MacAddress"] = toUtf(pQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryQuote(data,error,nRequestID,bIsLast);
}

///请求查询期权自对冲响应
void PyTdApi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOptionSelfClose)
    {
        data["BrokerID"] = toUtf(pOptionSelfClose->BrokerID);
        data["InvestorID"] = toUtf(pOptionSelfClose->InvestorID);
        data["InstrumentID"] = toUtf(pOptionSelfClose->InstrumentID);
        data["OptionSelfCloseRef"] = toUtf(pOptionSelfClose->OptionSelfCloseRef);
        data["UserID"] = toUtf(pOptionSelfClose->UserID);
        data["Volume"] = pOptionSelfClose->Volume;
        data["RequestID"] = pOptionSelfClose->RequestID;
        data["BusinessUnit"] = toUtf(pOptionSelfClose->BusinessUnit);
        data["HedgeFlag"] = pOptionSelfClose->HedgeFlag;
        data["OptSelfCloseFlag"] = pOptionSelfClose->OptSelfCloseFlag;
        data["OptionSelfCloseLocalID"] = toUtf(pOptionSelfClose->OptionSelfCloseLocalID);
        data["ExchangeID"] = toUtf(pOptionSelfClose->ExchangeID);
        data["ParticipantID"] = toUtf(pOptionSelfClose->ParticipantID);
        data["ClientID"] = toUtf(pOptionSelfClose->ClientID);
        data["ExchangeInstID"] = toUtf(pOptionSelfClose->ExchangeInstID);
        data["TraderID"] = toUtf(pOptionSelfClose->TraderID);
        data["InstallID"] = pOptionSelfClose->InstallID;
        data["OrderSubmitStatus"] = pOptionSelfClose->OrderSubmitStatus;
        data["NotifySequence"] = pOptionSelfClose->NotifySequence;
        data["TradingDay"] = toUtf(pOptionSelfClose->TradingDay);
        data["SettlementID"] = pOptionSelfClose->SettlementID;
        data["OptionSelfCloseSysID"] = toUtf(pOptionSelfClose->OptionSelfCloseSysID);
        data["InsertDate"] = toUtf(pOptionSelfClose->InsertDate);
        data["InsertTime"] = toUtf(pOptionSelfClose->InsertTime);
        data["CancelTime"] = toUtf(pOptionSelfClose->CancelTime);
        data["ExecResult"] = pOptionSelfClose->ExecResult;
        data["ClearingPartID"] = toUtf(pOptionSelfClose->ClearingPartID);
        data["SequenceNo"] = pOptionSelfClose->SequenceNo;
        data["FrontID"] = pOptionSelfClose->FrontID;
        data["SessionID"] = pOptionSelfClose->SessionID;
        data["UserProductInfo"] = toUtf(pOptionSelfClose->UserProductInfo);
        data["StatusMsg"] = toUtf(pOptionSelfClose->StatusMsg);
        data["ActiveUserID"] = toUtf(pOptionSelfClose->ActiveUserID);
        data["BrokerOptionSelfCloseSeq"] = pOptionSelfClose->BrokerOptionSelfCloseSeq;
        data["BranchID"] = toUtf(pOptionSelfClose->BranchID);
        data["InvestUnitID"] = toUtf(pOptionSelfClose->InvestUnitID);
        data["AccountID"] = toUtf(pOptionSelfClose->AccountID);
        data["CurrencyID"] = toUtf(pOptionSelfClose->CurrencyID);
        data["IPAddress"] = toUtf(pOptionSelfClose->IPAddress);
        data["MacAddress"] = toUtf(pOptionSelfClose->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryOptionSelfClose(data,error,nRequestID,bIsLast);
}

///请求查询投资单元响应
void PyTdApi::OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInvestUnit)
    {
        data["BrokerID"] = toUtf(pInvestUnit->BrokerID);
        data["InvestorID"] = toUtf(pInvestUnit->InvestorID);
        data["InvestUnitID"] = toUtf(pInvestUnit->InvestUnitID);
        data["InvestorUnitName"] = toUtf(pInvestUnit->InvestorUnitName);
        data["InvestorGroupID"] = toUtf(pInvestUnit->InvestorGroupID);
        data["CommModelID"] = toUtf(pInvestUnit->CommModelID);
        data["MarginModelID"] = toUtf(pInvestUnit->MarginModelID);
        data["AccountID"] = toUtf(pInvestUnit->AccountID);
        data["CurrencyID"] = toUtf(pInvestUnit->CurrencyID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryInvestUnit(data,error,nRequestID,bIsLast);
}

///请求查询组合合约安全系数响应
void PyTdApi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCombInstrumentGuard)
    {
        data["BrokerID"] = toUtf(pCombInstrumentGuard->BrokerID);
        data["InstrumentID"] = toUtf(pCombInstrumentGuard->InstrumentID);
        data["GuarantRatio"] = pCombInstrumentGuard->GuarantRatio;
        data["ExchangeID"] = toUtf(pCombInstrumentGuard->ExchangeID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryCombInstrumentGuard(data,error,nRequestID,bIsLast);
}

///请求查询申请组合响应
void PyTdApi::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCombAction)
    {
        data["BrokerID"] = toUtf(pCombAction->BrokerID);
        data["InvestorID"] = toUtf(pCombAction->InvestorID);
        data["InstrumentID"] = toUtf(pCombAction->InstrumentID);
        data["CombActionRef"] = toUtf(pCombAction->CombActionRef);
        data["UserID"] = toUtf(pCombAction->UserID);
        data["Direction"] = pCombAction->Direction;
        data["Volume"] = pCombAction->Volume;
        data["CombDirection"] = pCombAction->CombDirection;
        data["HedgeFlag"] = pCombAction->HedgeFlag;
        data["ActionLocalID"] = toUtf(pCombAction->ActionLocalID);
        data["ExchangeID"] = toUtf(pCombAction->ExchangeID);
        data["ParticipantID"] = toUtf(pCombAction->ParticipantID);
        data["ClientID"] = toUtf(pCombAction->ClientID);
        data["ExchangeInstID"] = toUtf(pCombAction->ExchangeInstID);
        data["TraderID"] = toUtf(pCombAction->TraderID);
        data["InstallID"] = pCombAction->InstallID;
        data["ActionStatus"] = pCombAction->ActionStatus;
        data["NotifySequence"] = pCombAction->NotifySequence;
        data["TradingDay"] = toUtf(pCombAction->TradingDay);
        data["SettlementID"] = pCombAction->SettlementID;
        data["SequenceNo"] = pCombAction->SequenceNo;
        data["FrontID"] = pCombAction->FrontID;
        data["SessionID"] = pCombAction->SessionID;
        data["UserProductInfo"] = toUtf(pCombAction->UserProductInfo);
        data["StatusMsg"] = toUtf(pCombAction->StatusMsg);
        data["IPAddress"] = toUtf(pCombAction->IPAddress);
        data["MacAddress"] = toUtf(pCombAction->MacAddress);
        data["ComTradeID"] = toUtf(pCombAction->ComTradeID);
        data["BranchID"] = toUtf(pCombAction->BranchID);
        data["InvestUnitID"] = toUtf(pCombAction->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryCombAction(data,error,nRequestID,bIsLast);
}

///请求查询转帐流水响应
void PyTdApi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTransferSerial)
    {
        data["PlateSerial"] = pTransferSerial->PlateSerial;
        data["TradeDate"] = toUtf(pTransferSerial->TradeDate);
        data["TradingDay"] = toUtf(pTransferSerial->TradingDay);
        data["TradeTime"] = toUtf(pTransferSerial->TradeTime);
        data["TradeCode"] = toUtf(pTransferSerial->TradeCode);
        data["SessionID"] = pTransferSerial->SessionID;
        data["BankID"] = toUtf(pTransferSerial->BankID);
        data["BankBranchID"] = toUtf(pTransferSerial->BankBranchID);
        data["BankAccType"] = pTransferSerial->BankAccType;
        data["BankAccount"] = toUtf(pTransferSerial->BankAccount);
        data["BankSerial"] = toUtf(pTransferSerial->BankSerial);
        data["BrokerID"] = toUtf(pTransferSerial->BrokerID);
        data["BrokerBranchID"] = toUtf(pTransferSerial->BrokerBranchID);
        data["FutureAccType"] = pTransferSerial->FutureAccType;
        data["AccountID"] = toUtf(pTransferSerial->AccountID);
        data["InvestorID"] = toUtf(pTransferSerial->InvestorID);
        data["FutureSerial"] = pTransferSerial->FutureSerial;
        data["IdCardType"] = pTransferSerial->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pTransferSerial->IdentifiedCardNo);
        data["CurrencyID"] = toUtf(pTransferSerial->CurrencyID);
        data["TradeAmount"] = pTransferSerial->TradeAmount;
        data["CustFee"] = pTransferSerial->CustFee;
        data["BrokerFee"] = pTransferSerial->BrokerFee;
        data["AvailabilityFlag"] = pTransferSerial->AvailabilityFlag;
        data["OperatorCode"] = toUtf(pTransferSerial->OperatorCode);
        data["BankNewAccount"] = toUtf(pTransferSerial->BankNewAccount);
        data["ErrorID"] = pTransferSerial->ErrorID;
        data["ErrorMsg"] = toUtf(pTransferSerial->ErrorMsg);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTransferSerial(data,error,nRequestID,bIsLast);
}

///请求查询银期签约关系响应
void PyTdApi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pAccountregister)
    {
        data["TradeDay"] = toUtf(pAccountregister->TradeDay);
        data["BankID"] = toUtf(pAccountregister->BankID);
        data["BankBranchID"] = toUtf(pAccountregister->BankBranchID);
        data["BankAccount"] = toUtf(pAccountregister->BankAccount);
        data["BrokerID"] = toUtf(pAccountregister->BrokerID);
        data["BrokerBranchID"] = toUtf(pAccountregister->BrokerBranchID);
        data["AccountID"] = toUtf(pAccountregister->AccountID);
        data["IdCardType"] = pAccountregister->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pAccountregister->IdentifiedCardNo);
        data["CustomerName"] = toUtf(pAccountregister->CustomerName);
        data["CurrencyID"] = toUtf(pAccountregister->CurrencyID);
        data["OpenOrDestroy"] = pAccountregister->OpenOrDestroy;
        data["RegDate"] = toUtf(pAccountregister->RegDate);
        data["OutDate"] = toUtf(pAccountregister->OutDate);
        data["TID"] = pAccountregister->TID;
        data["CustType"] = pAccountregister->CustType;
        data["BankAccType"] = pAccountregister->BankAccType;
        data["LongCustomerName"] = toUtf(pAccountregister->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryAccountregister(data,error,nRequestID,bIsLast);
}

///错误应答
void PyTdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspError(error,nRequestID,bIsLast);
}

///报单通知
void PyTdApi::OnRtnOrder(CThostFtdcOrderField *pOrder) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOrder)
    {
        data["BrokerID"] = toUtf(pOrder->BrokerID);
        data["InvestorID"] = toUtf(pOrder->InvestorID);
        data["InstrumentID"] = toUtf(pOrder->InstrumentID);
        data["OrderRef"] = toUtf(pOrder->OrderRef);
        data["UserID"] = toUtf(pOrder->UserID);
        data["OrderPriceType"] = pOrder->OrderPriceType;
        data["Direction"] = pOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pOrder->CombHedgeFlag);
        data["LimitPrice"] = pOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pOrder->TimeCondition;
        data["GTDDate"] = toUtf(pOrder->GTDDate);
        data["VolumeCondition"] = pOrder->VolumeCondition;
        data["MinVolume"] = pOrder->MinVolume;
        data["ContingentCondition"] = pOrder->ContingentCondition;
        data["StopPrice"] = pOrder->StopPrice;
        data["ForceCloseReason"] = pOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pOrder->BusinessUnit);
        data["RequestID"] = pOrder->RequestID;
        data["OrderLocalID"] = toUtf(pOrder->OrderLocalID);
        data["ExchangeID"] = toUtf(pOrder->ExchangeID);
        data["ParticipantID"] = toUtf(pOrder->ParticipantID);
        data["ClientID"] = toUtf(pOrder->ClientID);
        data["ExchangeInstID"] = toUtf(pOrder->ExchangeInstID);
        data["TraderID"] = toUtf(pOrder->TraderID);
        data["InstallID"] = pOrder->InstallID;
        data["OrderSubmitStatus"] = pOrder->OrderSubmitStatus;
        data["NotifySequence"] = pOrder->NotifySequence;
        data["TradingDay"] = toUtf(pOrder->TradingDay);
        data["SettlementID"] = pOrder->SettlementID;
        data["OrderSysID"] = toUtf(pOrder->OrderSysID);
        data["OrderSource"] = pOrder->OrderSource;
        data["OrderStatus"] = pOrder->OrderStatus;
        data["OrderType"] = pOrder->OrderType;
        data["VolumeTraded"] = pOrder->VolumeTraded;
        data["VolumeTotal"] = pOrder->VolumeTotal;
        data["InsertDate"] = toUtf(pOrder->InsertDate);
        data["InsertTime"] = toUtf(pOrder->InsertTime);
        data["ActiveTime"] = toUtf(pOrder->ActiveTime);
        data["SuspendTime"] = toUtf(pOrder->SuspendTime);
        data["UpdateTime"] = toUtf(pOrder->UpdateTime);
        data["CancelTime"] = toUtf(pOrder->CancelTime);
        data["ActiveTraderID"] = toUtf(pOrder->ActiveTraderID);
        data["ClearingPartID"] = toUtf(pOrder->ClearingPartID);
        data["SequenceNo"] = pOrder->SequenceNo;
        data["FrontID"] = pOrder->FrontID;
        data["SessionID"] = pOrder->SessionID;
        data["UserProductInfo"] = toUtf(pOrder->UserProductInfo);
        data["StatusMsg"] = toUtf(pOrder->StatusMsg);
        data["UserForceClose"] = pOrder->UserForceClose;
        data["ActiveUserID"] = toUtf(pOrder->ActiveUserID);
        data["BrokerOrderSeq"] = pOrder->BrokerOrderSeq;
        data["RelativeOrderSysID"] = toUtf(pOrder->RelativeOrderSysID);
        data["ZCETotalTradedVolume"] = pOrder->ZCETotalTradedVolume;
        data["IsSwapOrder"] = pOrder->IsSwapOrder;
        data["BranchID"] = toUtf(pOrder->BranchID);
        data["InvestUnitID"] = toUtf(pOrder->InvestUnitID);
        data["AccountID"] = toUtf(pOrder->AccountID);
        data["CurrencyID"] = toUtf(pOrder->CurrencyID);
        data["IPAddress"] = toUtf(pOrder->IPAddress);
        data["MacAddress"] = toUtf(pOrder->MacAddress);
    }
    OnRtnOrder(data);
}

///成交通知
void PyTdApi::OnRtnTrade(CThostFtdcTradeField *pTrade) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTrade)
    {
        data["BrokerID"] = toUtf(pTrade->BrokerID);
        data["InvestorID"] = toUtf(pTrade->InvestorID);
        data["InstrumentID"] = toUtf(pTrade->InstrumentID);
        data["OrderRef"] = toUtf(pTrade->OrderRef);
        data["UserID"] = toUtf(pTrade->UserID);
        data["ExchangeID"] = toUtf(pTrade->ExchangeID);
        data["TradeID"] = toUtf(pTrade->TradeID);
        data["Direction"] = pTrade->Direction;
        data["OrderSysID"] = toUtf(pTrade->OrderSysID);
        data["ParticipantID"] = toUtf(pTrade->ParticipantID);
        data["ClientID"] = toUtf(pTrade->ClientID);
        data["TradingRole"] = pTrade->TradingRole;
        data["ExchangeInstID"] = toUtf(pTrade->ExchangeInstID);
        data["OffsetFlag"] = pTrade->OffsetFlag;
        data["HedgeFlag"] = pTrade->HedgeFlag;
        data["Price"] = pTrade->Price;
        data["Volume"] = pTrade->Volume;
        data["TradeDate"] = toUtf(pTrade->TradeDate);
        data["TradeTime"] = toUtf(pTrade->TradeTime);
        data["TradeType"] = pTrade->TradeType;
        data["PriceSource"] = pTrade->PriceSource;
        data["TraderID"] = toUtf(pTrade->TraderID);
        data["OrderLocalID"] = toUtf(pTrade->OrderLocalID);
        data["ClearingPartID"] = toUtf(pTrade->ClearingPartID);
        data["BusinessUnit"] = toUtf(pTrade->BusinessUnit);
        data["SequenceNo"] = pTrade->SequenceNo;
        data["TradingDay"] = toUtf(pTrade->TradingDay);
        data["SettlementID"] = pTrade->SettlementID;
        data["BrokerOrderSeq"] = pTrade->BrokerOrderSeq;
        data["TradeSource"] = pTrade->TradeSource;
        data["InvestUnitID"] = toUtf(pTrade->InvestUnitID);
    }
    OnRtnTrade(data);
}

///报单录入错误回报
void PyTdApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOrder)
    {
        data["BrokerID"] = toUtf(pInputOrder->BrokerID);
        data["InvestorID"] = toUtf(pInputOrder->InvestorID);
        data["InstrumentID"] = toUtf(pInputOrder->InstrumentID);
        data["OrderRef"] = toUtf(pInputOrder->OrderRef);
        data["UserID"] = toUtf(pInputOrder->UserID);
        data["OrderPriceType"] = pInputOrder->OrderPriceType;
        data["Direction"] = pInputOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pInputOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pInputOrder->CombHedgeFlag);
        data["LimitPrice"] = pInputOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pInputOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pInputOrder->TimeCondition;
        data["GTDDate"] = toUtf(pInputOrder->GTDDate);
        data["VolumeCondition"] = pInputOrder->VolumeCondition;
        data["MinVolume"] = pInputOrder->MinVolume;
        data["ContingentCondition"] = pInputOrder->ContingentCondition;
        data["StopPrice"] = pInputOrder->StopPrice;
        data["ForceCloseReason"] = pInputOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pInputOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pInputOrder->BusinessUnit);
        data["RequestID"] = pInputOrder->RequestID;
        data["UserForceClose"] = pInputOrder->UserForceClose;
        data["IsSwapOrder"] = pInputOrder->IsSwapOrder;
        data["ExchangeID"] = toUtf(pInputOrder->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputOrder->InvestUnitID);
        data["AccountID"] = toUtf(pInputOrder->AccountID);
        data["CurrencyID"] = toUtf(pInputOrder->CurrencyID);
        data["ClientID"] = toUtf(pInputOrder->ClientID);
        data["IPAddress"] = toUtf(pInputOrder->IPAddress);
        data["MacAddress"] = toUtf(pInputOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnOrderInsert(data, error);
}

///报单操作错误回报
void PyTdApi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOrderAction)
    {
        data["BrokerID"] = toUtf(pOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pOrderAction->InvestorID);
        data["OrderActionRef"] = pOrderAction->OrderActionRef;
        data["OrderRef"] = toUtf(pOrderAction->OrderRef);
        data["RequestID"] = pOrderAction->RequestID;
        data["FrontID"] = pOrderAction->FrontID;
        data["SessionID"] = pOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pOrderAction->ExchangeID);
        data["OrderSysID"] = toUtf(pOrderAction->OrderSysID);
        data["ActionFlag"] = pOrderAction->ActionFlag;
        data["LimitPrice"] = pOrderAction->LimitPrice;
        data["VolumeChange"] = pOrderAction->VolumeChange;
        data["ActionDate"] = toUtf(pOrderAction->ActionDate);
        data["ActionTime"] = toUtf(pOrderAction->ActionTime);
        data["TraderID"] = toUtf(pOrderAction->TraderID);
        data["InstallID"] = pOrderAction->InstallID;
        data["OrderLocalID"] = toUtf(pOrderAction->OrderLocalID);
        data["ActionLocalID"] = toUtf(pOrderAction->ActionLocalID);
        data["ParticipantID"] = toUtf(pOrderAction->ParticipantID);
        data["ClientID"] = toUtf(pOrderAction->ClientID);
        data["BusinessUnit"] = toUtf(pOrderAction->BusinessUnit);
        data["OrderActionStatus"] = pOrderAction->OrderActionStatus;
        data["UserID"] = toUtf(pOrderAction->UserID);
        data["StatusMsg"] = toUtf(pOrderAction->StatusMsg);
        data["InstrumentID"] = toUtf(pOrderAction->InstrumentID);
        data["BranchID"] = toUtf(pOrderAction->BranchID);
        data["InvestUnitID"] = toUtf(pOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnOrderAction(data, error);
}

///合约交易状态通知
void PyTdApi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrumentStatus)
    {
        data["ExchangeID"] = toUtf(pInstrumentStatus->ExchangeID);
        data["ExchangeInstID"] = toUtf(pInstrumentStatus->ExchangeInstID);
        data["SettlementGroupID"] = toUtf(pInstrumentStatus->SettlementGroupID);
        data["InstrumentID"] = toUtf(pInstrumentStatus->InstrumentID);
        data["InstrumentStatus"] = pInstrumentStatus->InstrumentStatus;
        data["TradingSegmentSN"] = pInstrumentStatus->TradingSegmentSN;
        data["EnterTime"] = toUtf(pInstrumentStatus->EnterTime);
        data["EnterReason"] = pInstrumentStatus->EnterReason;
    }
    OnRtnInstrumentStatus(data);
}

///交易所公告通知
void PyTdApi::OnRtnBulletin(CThostFtdcBulletinField *pBulletin) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pBulletin)
    {
        data["ExchangeID"] = toUtf(pBulletin->ExchangeID);
        data["TradingDay"] = toUtf(pBulletin->TradingDay);
        data["BulletinID"] = pBulletin->BulletinID;
        data["SequenceNo"] = pBulletin->SequenceNo;
        data["NewsType"] = toUtf(pBulletin->NewsType);
        data["NewsUrgency"] = pBulletin->NewsUrgency;
        data["SendTime"] = toUtf(pBulletin->SendTime);
        data["Abstract"] = toUtf(pBulletin->Abstract);
        data["ComeFrom"] = toUtf(pBulletin->ComeFrom);
        data["Content"] = toUtf(pBulletin->Content);
        data["URLLink"] = toUtf(pBulletin->URLLink);
        data["MarketID"] = toUtf(pBulletin->MarketID);
    }
    OnRtnBulletin(data);
}

///交易通知
void PyTdApi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingNoticeInfo)
    {
        data["BrokerID"] = toUtf(pTradingNoticeInfo->BrokerID);
        data["InvestorID"] = toUtf(pTradingNoticeInfo->InvestorID);
        data["SendTime"] = toUtf(pTradingNoticeInfo->SendTime);
        data["FieldContent"] = toUtf(pTradingNoticeInfo->FieldContent);
        data["SequenceSeries"] = pTradingNoticeInfo->SequenceSeries;
        data["SequenceNo"] = pTradingNoticeInfo->SequenceNo;
        data["InvestUnitID"] = toUtf(pTradingNoticeInfo->InvestUnitID);
    }
    OnRtnTradingNotice(data);
}

///提示条件单校验错误
void PyTdApi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pErrorConditionalOrder)
    {
        data["BrokerID"] = toUtf(pErrorConditionalOrder->BrokerID);
        data["InvestorID"] = toUtf(pErrorConditionalOrder->InvestorID);
        data["InstrumentID"] = toUtf(pErrorConditionalOrder->InstrumentID);
        data["OrderRef"] = toUtf(pErrorConditionalOrder->OrderRef);
        data["UserID"] = toUtf(pErrorConditionalOrder->UserID);
        data["OrderPriceType"] = pErrorConditionalOrder->OrderPriceType;
        data["Direction"] = pErrorConditionalOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pErrorConditionalOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pErrorConditionalOrder->CombHedgeFlag);
        data["LimitPrice"] = pErrorConditionalOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pErrorConditionalOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pErrorConditionalOrder->TimeCondition;
        data["GTDDate"] = toUtf(pErrorConditionalOrder->GTDDate);
        data["VolumeCondition"] = pErrorConditionalOrder->VolumeCondition;
        data["MinVolume"] = pErrorConditionalOrder->MinVolume;
        data["ContingentCondition"] = pErrorConditionalOrder->ContingentCondition;
        data["StopPrice"] = pErrorConditionalOrder->StopPrice;
        data["ForceCloseReason"] = pErrorConditionalOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pErrorConditionalOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pErrorConditionalOrder->BusinessUnit);
        data["RequestID"] = pErrorConditionalOrder->RequestID;
        data["OrderLocalID"] = toUtf(pErrorConditionalOrder->OrderLocalID);
        data["ExchangeID"] = toUtf(pErrorConditionalOrder->ExchangeID);
        data["ParticipantID"] = toUtf(pErrorConditionalOrder->ParticipantID);
        data["ClientID"] = toUtf(pErrorConditionalOrder->ClientID);
        data["ExchangeInstID"] = toUtf(pErrorConditionalOrder->ExchangeInstID);
        data["TraderID"] = toUtf(pErrorConditionalOrder->TraderID);
        data["InstallID"] = pErrorConditionalOrder->InstallID;
        data["OrderSubmitStatus"] = pErrorConditionalOrder->OrderSubmitStatus;
        data["NotifySequence"] = pErrorConditionalOrder->NotifySequence;
        data["TradingDay"] = toUtf(pErrorConditionalOrder->TradingDay);
        data["SettlementID"] = pErrorConditionalOrder->SettlementID;
        data["OrderSysID"] = toUtf(pErrorConditionalOrder->OrderSysID);
        data["OrderSource"] = pErrorConditionalOrder->OrderSource;
        data["OrderStatus"] = pErrorConditionalOrder->OrderStatus;
        data["OrderType"] = pErrorConditionalOrder->OrderType;
        data["VolumeTraded"] = pErrorConditionalOrder->VolumeTraded;
        data["VolumeTotal"] = pErrorConditionalOrder->VolumeTotal;
        data["InsertDate"] = toUtf(pErrorConditionalOrder->InsertDate);
        data["InsertTime"] = toUtf(pErrorConditionalOrder->InsertTime);
        data["ActiveTime"] = toUtf(pErrorConditionalOrder->ActiveTime);
        data["SuspendTime"] = toUtf(pErrorConditionalOrder->SuspendTime);
        data["UpdateTime"] = toUtf(pErrorConditionalOrder->UpdateTime);
        data["CancelTime"] = toUtf(pErrorConditionalOrder->CancelTime);
        data["ActiveTraderID"] = toUtf(pErrorConditionalOrder->ActiveTraderID);
        data["ClearingPartID"] = toUtf(pErrorConditionalOrder->ClearingPartID);
        data["SequenceNo"] = pErrorConditionalOrder->SequenceNo;
        data["FrontID"] = pErrorConditionalOrder->FrontID;
        data["SessionID"] = pErrorConditionalOrder->SessionID;
        data["UserProductInfo"] = toUtf(pErrorConditionalOrder->UserProductInfo);
        data["StatusMsg"] = toUtf(pErrorConditionalOrder->StatusMsg);
        data["UserForceClose"] = pErrorConditionalOrder->UserForceClose;
        data["ActiveUserID"] = toUtf(pErrorConditionalOrder->ActiveUserID);
        data["BrokerOrderSeq"] = pErrorConditionalOrder->BrokerOrderSeq;
        data["RelativeOrderSysID"] = toUtf(pErrorConditionalOrder->RelativeOrderSysID);
        data["ZCETotalTradedVolume"] = pErrorConditionalOrder->ZCETotalTradedVolume;
        data["ErrorID"] = pErrorConditionalOrder->ErrorID;
        data["ErrorMsg"] = toUtf(pErrorConditionalOrder->ErrorMsg);
        data["IsSwapOrder"] = pErrorConditionalOrder->IsSwapOrder;
        data["BranchID"] = toUtf(pErrorConditionalOrder->BranchID);
        data["InvestUnitID"] = toUtf(pErrorConditionalOrder->InvestUnitID);
        data["AccountID"] = toUtf(pErrorConditionalOrder->AccountID);
        data["CurrencyID"] = toUtf(pErrorConditionalOrder->CurrencyID);
        data["IPAddress"] = toUtf(pErrorConditionalOrder->IPAddress);
        data["MacAddress"] = toUtf(pErrorConditionalOrder->MacAddress);
    }
    OnRtnErrorConditionalOrder(data);
}

///执行宣告通知
void PyTdApi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExecOrder)
    {
        data["BrokerID"] = toUtf(pExecOrder->BrokerID);
        data["InvestorID"] = toUtf(pExecOrder->InvestorID);
        data["InstrumentID"] = toUtf(pExecOrder->InstrumentID);
        data["ExecOrderRef"] = toUtf(pExecOrder->ExecOrderRef);
        data["UserID"] = toUtf(pExecOrder->UserID);
        data["Volume"] = pExecOrder->Volume;
        data["RequestID"] = pExecOrder->RequestID;
        data["BusinessUnit"] = toUtf(pExecOrder->BusinessUnit);
        data["OffsetFlag"] = pExecOrder->OffsetFlag;
        data["HedgeFlag"] = pExecOrder->HedgeFlag;
        data["ActionType"] = pExecOrder->ActionType;
        data["PosiDirection"] = pExecOrder->PosiDirection;
        data["ReservePositionFlag"] = pExecOrder->ReservePositionFlag;
        data["CloseFlag"] = pExecOrder->CloseFlag;
        data["ExecOrderLocalID"] = toUtf(pExecOrder->ExecOrderLocalID);
        data["ExchangeID"] = toUtf(pExecOrder->ExchangeID);
        data["ParticipantID"] = toUtf(pExecOrder->ParticipantID);
        data["ClientID"] = toUtf(pExecOrder->ClientID);
        data["ExchangeInstID"] = toUtf(pExecOrder->ExchangeInstID);
        data["TraderID"] = toUtf(pExecOrder->TraderID);
        data["InstallID"] = pExecOrder->InstallID;
        data["OrderSubmitStatus"] = pExecOrder->OrderSubmitStatus;
        data["NotifySequence"] = pExecOrder->NotifySequence;
        data["TradingDay"] = toUtf(pExecOrder->TradingDay);
        data["SettlementID"] = pExecOrder->SettlementID;
        data["ExecOrderSysID"] = toUtf(pExecOrder->ExecOrderSysID);
        data["InsertDate"] = toUtf(pExecOrder->InsertDate);
        data["InsertTime"] = toUtf(pExecOrder->InsertTime);
        data["CancelTime"] = toUtf(pExecOrder->CancelTime);
        data["ExecResult"] = pExecOrder->ExecResult;
        data["ClearingPartID"] = toUtf(pExecOrder->ClearingPartID);
        data["SequenceNo"] = pExecOrder->SequenceNo;
        data["FrontID"] = pExecOrder->FrontID;
        data["SessionID"] = pExecOrder->SessionID;
        data["UserProductInfo"] = toUtf(pExecOrder->UserProductInfo);
        data["StatusMsg"] = toUtf(pExecOrder->StatusMsg);
        data["ActiveUserID"] = toUtf(pExecOrder->ActiveUserID);
        data["BrokerExecOrderSeq"] = pExecOrder->BrokerExecOrderSeq;
        data["BranchID"] = toUtf(pExecOrder->BranchID);
        data["InvestUnitID"] = toUtf(pExecOrder->InvestUnitID);
        data["AccountID"] = toUtf(pExecOrder->AccountID);
        data["CurrencyID"] = toUtf(pExecOrder->CurrencyID);
        data["IPAddress"] = toUtf(pExecOrder->IPAddress);
        data["MacAddress"] = toUtf(pExecOrder->MacAddress);
    }
    OnRtnExecOrder(data);
}

///执行宣告录入错误回报
void PyTdApi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputExecOrder)
    {
        data["BrokerID"] = toUtf(pInputExecOrder->BrokerID);
        data["InvestorID"] = toUtf(pInputExecOrder->InvestorID);
        data["InstrumentID"] = toUtf(pInputExecOrder->InstrumentID);
        data["ExecOrderRef"] = toUtf(pInputExecOrder->ExecOrderRef);
        data["UserID"] = toUtf(pInputExecOrder->UserID);
        data["Volume"] = pInputExecOrder->Volume;
        data["RequestID"] = pInputExecOrder->RequestID;
        data["BusinessUnit"] = toUtf(pInputExecOrder->BusinessUnit);
        data["OffsetFlag"] = pInputExecOrder->OffsetFlag;
        data["HedgeFlag"] = pInputExecOrder->HedgeFlag;
        data["ActionType"] = pInputExecOrder->ActionType;
        data["PosiDirection"] = pInputExecOrder->PosiDirection;
        data["ReservePositionFlag"] = pInputExecOrder->ReservePositionFlag;
        data["CloseFlag"] = pInputExecOrder->CloseFlag;
        data["ExchangeID"] = toUtf(pInputExecOrder->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputExecOrder->InvestUnitID);
        data["AccountID"] = toUtf(pInputExecOrder->AccountID);
        data["CurrencyID"] = toUtf(pInputExecOrder->CurrencyID);
        data["ClientID"] = toUtf(pInputExecOrder->ClientID);
        data["IPAddress"] = toUtf(pInputExecOrder->IPAddress);
        data["MacAddress"] = toUtf(pInputExecOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnExecOrderInsert(data, error);
}

///执行宣告操作错误回报
void PyTdApi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pExecOrderAction)
    {
        data["BrokerID"] = toUtf(pExecOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pExecOrderAction->InvestorID);
        data["ExecOrderActionRef"] = pExecOrderAction->ExecOrderActionRef;
        data["ExecOrderRef"] = toUtf(pExecOrderAction->ExecOrderRef);
        data["RequestID"] = pExecOrderAction->RequestID;
        data["FrontID"] = pExecOrderAction->FrontID;
        data["SessionID"] = pExecOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pExecOrderAction->ExchangeID);
        data["ExecOrderSysID"] = toUtf(pExecOrderAction->ExecOrderSysID);
        data["ActionFlag"] = pExecOrderAction->ActionFlag;
        data["ActionDate"] = toUtf(pExecOrderAction->ActionDate);
        data["ActionTime"] = toUtf(pExecOrderAction->ActionTime);
        data["TraderID"] = toUtf(pExecOrderAction->TraderID);
        data["InstallID"] = pExecOrderAction->InstallID;
        data["ExecOrderLocalID"] = toUtf(pExecOrderAction->ExecOrderLocalID);
        data["ActionLocalID"] = toUtf(pExecOrderAction->ActionLocalID);
        data["ParticipantID"] = toUtf(pExecOrderAction->ParticipantID);
        data["ClientID"] = toUtf(pExecOrderAction->ClientID);
        data["BusinessUnit"] = toUtf(pExecOrderAction->BusinessUnit);
        data["OrderActionStatus"] = pExecOrderAction->OrderActionStatus;
        data["UserID"] = toUtf(pExecOrderAction->UserID);
        data["ActionType"] = pExecOrderAction->ActionType;
        data["StatusMsg"] = toUtf(pExecOrderAction->StatusMsg);
        data["InstrumentID"] = toUtf(pExecOrderAction->InstrumentID);
        data["BranchID"] = toUtf(pExecOrderAction->BranchID);
        data["InvestUnitID"] = toUtf(pExecOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pExecOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pExecOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnExecOrderAction(data, error);
}

///询价录入错误回报
void PyTdApi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputForQuote)
    {
        data["BrokerID"] = toUtf(pInputForQuote->BrokerID);
        data["InvestorID"] = toUtf(pInputForQuote->InvestorID);
        data["InstrumentID"] = toUtf(pInputForQuote->InstrumentID);
        data["ForQuoteRef"] = toUtf(pInputForQuote->ForQuoteRef);
        data["UserID"] = toUtf(pInputForQuote->UserID);
        data["ExchangeID"] = toUtf(pInputForQuote->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputForQuote->InvestUnitID);
        data["IPAddress"] = toUtf(pInputForQuote->IPAddress);
        data["MacAddress"] = toUtf(pInputForQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnForQuoteInsert(data, error);
}

///报价通知
void PyTdApi::OnRtnQuote(CThostFtdcQuoteField *pQuote) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pQuote)
    {
        data["BrokerID"] = toUtf(pQuote->BrokerID);
        data["InvestorID"] = toUtf(pQuote->InvestorID);
        data["InstrumentID"] = toUtf(pQuote->InstrumentID);
        data["QuoteRef"] = toUtf(pQuote->QuoteRef);
        data["UserID"] = toUtf(pQuote->UserID);
        data["AskPrice"] = pQuote->AskPrice;
        data["BidPrice"] = pQuote->BidPrice;
        data["AskVolume"] = pQuote->AskVolume;
        data["BidVolume"] = pQuote->BidVolume;
        data["RequestID"] = pQuote->RequestID;
        data["BusinessUnit"] = toUtf(pQuote->BusinessUnit);
        data["AskOffsetFlag"] = pQuote->AskOffsetFlag;
        data["BidOffsetFlag"] = pQuote->BidOffsetFlag;
        data["AskHedgeFlag"] = pQuote->AskHedgeFlag;
        data["BidHedgeFlag"] = pQuote->BidHedgeFlag;
        data["QuoteLocalID"] = toUtf(pQuote->QuoteLocalID);
        data["ExchangeID"] = toUtf(pQuote->ExchangeID);
        data["ParticipantID"] = toUtf(pQuote->ParticipantID);
        data["ClientID"] = toUtf(pQuote->ClientID);
        data["ExchangeInstID"] = toUtf(pQuote->ExchangeInstID);
        data["TraderID"] = toUtf(pQuote->TraderID);
        data["InstallID"] = pQuote->InstallID;
        data["NotifySequence"] = pQuote->NotifySequence;
        data["OrderSubmitStatus"] = pQuote->OrderSubmitStatus;
        data["TradingDay"] = toUtf(pQuote->TradingDay);
        data["SettlementID"] = pQuote->SettlementID;
        data["QuoteSysID"] = toUtf(pQuote->QuoteSysID);
        data["InsertDate"] = toUtf(pQuote->InsertDate);
        data["InsertTime"] = toUtf(pQuote->InsertTime);
        data["CancelTime"] = toUtf(pQuote->CancelTime);
        data["QuoteStatus"] = pQuote->QuoteStatus;
        data["ClearingPartID"] = toUtf(pQuote->ClearingPartID);
        data["SequenceNo"] = pQuote->SequenceNo;
        data["AskOrderSysID"] = toUtf(pQuote->AskOrderSysID);
        data["BidOrderSysID"] = toUtf(pQuote->BidOrderSysID);
        data["FrontID"] = pQuote->FrontID;
        data["SessionID"] = pQuote->SessionID;
        data["UserProductInfo"] = toUtf(pQuote->UserProductInfo);
        data["StatusMsg"] = toUtf(pQuote->StatusMsg);
        data["ActiveUserID"] = toUtf(pQuote->ActiveUserID);
        data["BrokerQuoteSeq"] = pQuote->BrokerQuoteSeq;
        data["AskOrderRef"] = toUtf(pQuote->AskOrderRef);
        data["BidOrderRef"] = toUtf(pQuote->BidOrderRef);
        data["ForQuoteSysID"] = toUtf(pQuote->ForQuoteSysID);
        data["BranchID"] = toUtf(pQuote->BranchID);
        data["InvestUnitID"] = toUtf(pQuote->InvestUnitID);
        data["AccountID"] = toUtf(pQuote->AccountID);
        data["CurrencyID"] = toUtf(pQuote->CurrencyID);
        data["IPAddress"] = toUtf(pQuote->IPAddress);
        data["MacAddress"] = toUtf(pQuote->MacAddress);
    }
    OnRtnQuote(data);
}

///报价录入错误回报
void PyTdApi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputQuote)
    {
        data["BrokerID"] = toUtf(pInputQuote->BrokerID);
        data["InvestorID"] = toUtf(pInputQuote->InvestorID);
        data["InstrumentID"] = toUtf(pInputQuote->InstrumentID);
        data["QuoteRef"] = toUtf(pInputQuote->QuoteRef);
        data["UserID"] = toUtf(pInputQuote->UserID);
        data["AskPrice"] = pInputQuote->AskPrice;
        data["BidPrice"] = pInputQuote->BidPrice;
        data["AskVolume"] = pInputQuote->AskVolume;
        data["BidVolume"] = pInputQuote->BidVolume;
        data["RequestID"] = pInputQuote->RequestID;
        data["BusinessUnit"] = toUtf(pInputQuote->BusinessUnit);
        data["AskOffsetFlag"] = pInputQuote->AskOffsetFlag;
        data["BidOffsetFlag"] = pInputQuote->BidOffsetFlag;
        data["AskHedgeFlag"] = pInputQuote->AskHedgeFlag;
        data["BidHedgeFlag"] = pInputQuote->BidHedgeFlag;
        data["AskOrderRef"] = toUtf(pInputQuote->AskOrderRef);
        data["BidOrderRef"] = toUtf(pInputQuote->BidOrderRef);
        data["ForQuoteSysID"] = toUtf(pInputQuote->ForQuoteSysID);
        data["ExchangeID"] = toUtf(pInputQuote->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputQuote->InvestUnitID);
        data["ClientID"] = toUtf(pInputQuote->ClientID);
        data["IPAddress"] = toUtf(pInputQuote->IPAddress);
        data["MacAddress"] = toUtf(pInputQuote->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnQuoteInsert(data, error);
}

///报价操作错误回报
void PyTdApi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pQuoteAction)
    {
        data["BrokerID"] = toUtf(pQuoteAction->BrokerID);
        data["InvestorID"] = toUtf(pQuoteAction->InvestorID);
        data["QuoteActionRef"] = pQuoteAction->QuoteActionRef;
        data["QuoteRef"] = toUtf(pQuoteAction->QuoteRef);
        data["RequestID"] = pQuoteAction->RequestID;
        data["FrontID"] = pQuoteAction->FrontID;
        data["SessionID"] = pQuoteAction->SessionID;
        data["ExchangeID"] = toUtf(pQuoteAction->ExchangeID);
        data["QuoteSysID"] = toUtf(pQuoteAction->QuoteSysID);
        data["ActionFlag"] = pQuoteAction->ActionFlag;
        data["ActionDate"] = toUtf(pQuoteAction->ActionDate);
        data["ActionTime"] = toUtf(pQuoteAction->ActionTime);
        data["TraderID"] = toUtf(pQuoteAction->TraderID);
        data["InstallID"] = pQuoteAction->InstallID;
        data["QuoteLocalID"] = toUtf(pQuoteAction->QuoteLocalID);
        data["ActionLocalID"] = toUtf(pQuoteAction->ActionLocalID);
        data["ParticipantID"] = toUtf(pQuoteAction->ParticipantID);
        data["ClientID"] = toUtf(pQuoteAction->ClientID);
        data["BusinessUnit"] = toUtf(pQuoteAction->BusinessUnit);
        data["OrderActionStatus"] = pQuoteAction->OrderActionStatus;
        data["UserID"] = toUtf(pQuoteAction->UserID);
        data["StatusMsg"] = toUtf(pQuoteAction->StatusMsg);
        data["InstrumentID"] = toUtf(pQuoteAction->InstrumentID);
        data["BranchID"] = toUtf(pQuoteAction->BranchID);
        data["InvestUnitID"] = toUtf(pQuoteAction->InvestUnitID);
        data["IPAddress"] = toUtf(pQuoteAction->IPAddress);
        data["MacAddress"] = toUtf(pQuoteAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnQuoteAction(data, error);
}

///询价通知
void PyTdApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) 
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
}

///保证金监控中心用户令牌
void PyTdApi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCFMMCTradingAccountToken)
    {
        data["BrokerID"] = toUtf(pCFMMCTradingAccountToken->BrokerID);
        data["ParticipantID"] = toUtf(pCFMMCTradingAccountToken->ParticipantID);
        data["AccountID"] = toUtf(pCFMMCTradingAccountToken->AccountID);
        data["KeyID"] = pCFMMCTradingAccountToken->KeyID;
        data["Token"] = toUtf(pCFMMCTradingAccountToken->Token);
    }
    OnRtnCFMMCTradingAccountToken(data);
}

///批量报单操作错误回报
void PyTdApi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pBatchOrderAction)
    {
        data["BrokerID"] = toUtf(pBatchOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pBatchOrderAction->InvestorID);
        data["OrderActionRef"] = pBatchOrderAction->OrderActionRef;
        data["RequestID"] = pBatchOrderAction->RequestID;
        data["FrontID"] = pBatchOrderAction->FrontID;
        data["SessionID"] = pBatchOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pBatchOrderAction->ExchangeID);
        data["ActionDate"] = toUtf(pBatchOrderAction->ActionDate);
        data["ActionTime"] = toUtf(pBatchOrderAction->ActionTime);
        data["TraderID"] = toUtf(pBatchOrderAction->TraderID);
        data["InstallID"] = pBatchOrderAction->InstallID;
        data["ActionLocalID"] = toUtf(pBatchOrderAction->ActionLocalID);
        data["ParticipantID"] = toUtf(pBatchOrderAction->ParticipantID);
        data["ClientID"] = toUtf(pBatchOrderAction->ClientID);
        data["BusinessUnit"] = toUtf(pBatchOrderAction->BusinessUnit);
        data["OrderActionStatus"] = pBatchOrderAction->OrderActionStatus;
        data["UserID"] = toUtf(pBatchOrderAction->UserID);
        data["StatusMsg"] = toUtf(pBatchOrderAction->StatusMsg);
        data["InvestUnitID"] = toUtf(pBatchOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pBatchOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pBatchOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnBatchOrderAction(data, error);
}

///期权自对冲通知
void PyTdApi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOptionSelfClose)
    {
        data["BrokerID"] = toUtf(pOptionSelfClose->BrokerID);
        data["InvestorID"] = toUtf(pOptionSelfClose->InvestorID);
        data["InstrumentID"] = toUtf(pOptionSelfClose->InstrumentID);
        data["OptionSelfCloseRef"] = toUtf(pOptionSelfClose->OptionSelfCloseRef);
        data["UserID"] = toUtf(pOptionSelfClose->UserID);
        data["Volume"] = pOptionSelfClose->Volume;
        data["RequestID"] = pOptionSelfClose->RequestID;
        data["BusinessUnit"] = toUtf(pOptionSelfClose->BusinessUnit);
        data["HedgeFlag"] = pOptionSelfClose->HedgeFlag;
        data["OptSelfCloseFlag"] = pOptionSelfClose->OptSelfCloseFlag;
        data["OptionSelfCloseLocalID"] = toUtf(pOptionSelfClose->OptionSelfCloseLocalID);
        data["ExchangeID"] = toUtf(pOptionSelfClose->ExchangeID);
        data["ParticipantID"] = toUtf(pOptionSelfClose->ParticipantID);
        data["ClientID"] = toUtf(pOptionSelfClose->ClientID);
        data["ExchangeInstID"] = toUtf(pOptionSelfClose->ExchangeInstID);
        data["TraderID"] = toUtf(pOptionSelfClose->TraderID);
        data["InstallID"] = pOptionSelfClose->InstallID;
        data["OrderSubmitStatus"] = pOptionSelfClose->OrderSubmitStatus;
        data["NotifySequence"] = pOptionSelfClose->NotifySequence;
        data["TradingDay"] = toUtf(pOptionSelfClose->TradingDay);
        data["SettlementID"] = pOptionSelfClose->SettlementID;
        data["OptionSelfCloseSysID"] = toUtf(pOptionSelfClose->OptionSelfCloseSysID);
        data["InsertDate"] = toUtf(pOptionSelfClose->InsertDate);
        data["InsertTime"] = toUtf(pOptionSelfClose->InsertTime);
        data["CancelTime"] = toUtf(pOptionSelfClose->CancelTime);
        data["ExecResult"] = pOptionSelfClose->ExecResult;
        data["ClearingPartID"] = toUtf(pOptionSelfClose->ClearingPartID);
        data["SequenceNo"] = pOptionSelfClose->SequenceNo;
        data["FrontID"] = pOptionSelfClose->FrontID;
        data["SessionID"] = pOptionSelfClose->SessionID;
        data["UserProductInfo"] = toUtf(pOptionSelfClose->UserProductInfo);
        data["StatusMsg"] = toUtf(pOptionSelfClose->StatusMsg);
        data["ActiveUserID"] = toUtf(pOptionSelfClose->ActiveUserID);
        data["BrokerOptionSelfCloseSeq"] = pOptionSelfClose->BrokerOptionSelfCloseSeq;
        data["BranchID"] = toUtf(pOptionSelfClose->BranchID);
        data["InvestUnitID"] = toUtf(pOptionSelfClose->InvestUnitID);
        data["AccountID"] = toUtf(pOptionSelfClose->AccountID);
        data["CurrencyID"] = toUtf(pOptionSelfClose->CurrencyID);
        data["IPAddress"] = toUtf(pOptionSelfClose->IPAddress);
        data["MacAddress"] = toUtf(pOptionSelfClose->MacAddress);
    }
    OnRtnOptionSelfClose(data);
}

///期权自对冲录入错误回报
void PyTdApi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputOptionSelfClose)
    {
        data["BrokerID"] = toUtf(pInputOptionSelfClose->BrokerID);
        data["InvestorID"] = toUtf(pInputOptionSelfClose->InvestorID);
        data["InstrumentID"] = toUtf(pInputOptionSelfClose->InstrumentID);
        data["OptionSelfCloseRef"] = toUtf(pInputOptionSelfClose->OptionSelfCloseRef);
        data["UserID"] = toUtf(pInputOptionSelfClose->UserID);
        data["Volume"] = pInputOptionSelfClose->Volume;
        data["RequestID"] = pInputOptionSelfClose->RequestID;
        data["BusinessUnit"] = toUtf(pInputOptionSelfClose->BusinessUnit);
        data["HedgeFlag"] = pInputOptionSelfClose->HedgeFlag;
        data["OptSelfCloseFlag"] = pInputOptionSelfClose->OptSelfCloseFlag;
        data["ExchangeID"] = toUtf(pInputOptionSelfClose->ExchangeID);
        data["InvestUnitID"] = toUtf(pInputOptionSelfClose->InvestUnitID);
        data["AccountID"] = toUtf(pInputOptionSelfClose->AccountID);
        data["CurrencyID"] = toUtf(pInputOptionSelfClose->CurrencyID);
        data["ClientID"] = toUtf(pInputOptionSelfClose->ClientID);
        data["IPAddress"] = toUtf(pInputOptionSelfClose->IPAddress);
        data["MacAddress"] = toUtf(pInputOptionSelfClose->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnOptionSelfCloseInsert(data, error);
}

///期权自对冲操作错误回报
void PyTdApi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOptionSelfCloseAction)
    {
        data["BrokerID"] = toUtf(pOptionSelfCloseAction->BrokerID);
        data["InvestorID"] = toUtf(pOptionSelfCloseAction->InvestorID);
        data["OptionSelfCloseActionRef"] = pOptionSelfCloseAction->OptionSelfCloseActionRef;
        data["OptionSelfCloseRef"] = toUtf(pOptionSelfCloseAction->OptionSelfCloseRef);
        data["RequestID"] = pOptionSelfCloseAction->RequestID;
        data["FrontID"] = pOptionSelfCloseAction->FrontID;
        data["SessionID"] = pOptionSelfCloseAction->SessionID;
        data["ExchangeID"] = toUtf(pOptionSelfCloseAction->ExchangeID);
        data["OptionSelfCloseSysID"] = toUtf(pOptionSelfCloseAction->OptionSelfCloseSysID);
        data["ActionFlag"] = pOptionSelfCloseAction->ActionFlag;
        data["ActionDate"] = toUtf(pOptionSelfCloseAction->ActionDate);
        data["ActionTime"] = toUtf(pOptionSelfCloseAction->ActionTime);
        data["TraderID"] = toUtf(pOptionSelfCloseAction->TraderID);
        data["InstallID"] = pOptionSelfCloseAction->InstallID;
        data["OptionSelfCloseLocalID"] = toUtf(pOptionSelfCloseAction->OptionSelfCloseLocalID);
        data["ActionLocalID"] = toUtf(pOptionSelfCloseAction->ActionLocalID);
        data["ParticipantID"] = toUtf(pOptionSelfCloseAction->ParticipantID);
        data["ClientID"] = toUtf(pOptionSelfCloseAction->ClientID);
        data["BusinessUnit"] = toUtf(pOptionSelfCloseAction->BusinessUnit);
        data["OrderActionStatus"] = pOptionSelfCloseAction->OrderActionStatus;
        data["UserID"] = toUtf(pOptionSelfCloseAction->UserID);
        data["StatusMsg"] = toUtf(pOptionSelfCloseAction->StatusMsg);
        data["InstrumentID"] = toUtf(pOptionSelfCloseAction->InstrumentID);
        data["BranchID"] = toUtf(pOptionSelfCloseAction->BranchID);
        data["InvestUnitID"] = toUtf(pOptionSelfCloseAction->InvestUnitID);
        data["IPAddress"] = toUtf(pOptionSelfCloseAction->IPAddress);
        data["MacAddress"] = toUtf(pOptionSelfCloseAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnOptionSelfCloseAction(data, error);
}

///申请组合通知
void PyTdApi::OnRtnCombAction(CThostFtdcCombActionField *pCombAction) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCombAction)
    {
        data["BrokerID"] = toUtf(pCombAction->BrokerID);
        data["InvestorID"] = toUtf(pCombAction->InvestorID);
        data["InstrumentID"] = toUtf(pCombAction->InstrumentID);
        data["CombActionRef"] = toUtf(pCombAction->CombActionRef);
        data["UserID"] = toUtf(pCombAction->UserID);
        data["Direction"] = pCombAction->Direction;
        data["Volume"] = pCombAction->Volume;
        data["CombDirection"] = pCombAction->CombDirection;
        data["HedgeFlag"] = pCombAction->HedgeFlag;
        data["ActionLocalID"] = toUtf(pCombAction->ActionLocalID);
        data["ExchangeID"] = toUtf(pCombAction->ExchangeID);
        data["ParticipantID"] = toUtf(pCombAction->ParticipantID);
        data["ClientID"] = toUtf(pCombAction->ClientID);
        data["ExchangeInstID"] = toUtf(pCombAction->ExchangeInstID);
        data["TraderID"] = toUtf(pCombAction->TraderID);
        data["InstallID"] = pCombAction->InstallID;
        data["ActionStatus"] = pCombAction->ActionStatus;
        data["NotifySequence"] = pCombAction->NotifySequence;
        data["TradingDay"] = toUtf(pCombAction->TradingDay);
        data["SettlementID"] = pCombAction->SettlementID;
        data["SequenceNo"] = pCombAction->SequenceNo;
        data["FrontID"] = pCombAction->FrontID;
        data["SessionID"] = pCombAction->SessionID;
        data["UserProductInfo"] = toUtf(pCombAction->UserProductInfo);
        data["StatusMsg"] = toUtf(pCombAction->StatusMsg);
        data["IPAddress"] = toUtf(pCombAction->IPAddress);
        data["MacAddress"] = toUtf(pCombAction->MacAddress);
        data["ComTradeID"] = toUtf(pCombAction->ComTradeID);
        data["BranchID"] = toUtf(pCombAction->BranchID);
        data["InvestUnitID"] = toUtf(pCombAction->InvestUnitID);
    }
    OnRtnCombAction(data);
}

///申请组合录入错误回报
void PyTdApi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInputCombAction)
    {
        data["BrokerID"] = toUtf(pInputCombAction->BrokerID);
        data["InvestorID"] = toUtf(pInputCombAction->InvestorID);
        data["InstrumentID"] = toUtf(pInputCombAction->InstrumentID);
        data["CombActionRef"] = toUtf(pInputCombAction->CombActionRef);
        data["UserID"] = toUtf(pInputCombAction->UserID);
        data["Direction"] = pInputCombAction->Direction;
        data["Volume"] = pInputCombAction->Volume;
        data["CombDirection"] = pInputCombAction->CombDirection;
        data["HedgeFlag"] = pInputCombAction->HedgeFlag;
        data["ExchangeID"] = toUtf(pInputCombAction->ExchangeID);
        data["IPAddress"] = toUtf(pInputCombAction->IPAddress);
        data["MacAddress"] = toUtf(pInputCombAction->MacAddress);
        data["InvestUnitID"] = toUtf(pInputCombAction->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnCombActionInsert(data, error);
}

///请求查询签约银行响应
void PyTdApi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pContractBank)
    {
        data["BrokerID"] = toUtf(pContractBank->BrokerID);
        data["BankID"] = toUtf(pContractBank->BankID);
        data["BankBrchID"] = toUtf(pContractBank->BankBrchID);
        data["BankName"] = toUtf(pContractBank->BankName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryContractBank(data,error,nRequestID,bIsLast);
}

///请求查询预埋单响应
void PyTdApi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pParkedOrder)
    {
        data["BrokerID"] = toUtf(pParkedOrder->BrokerID);
        data["InvestorID"] = toUtf(pParkedOrder->InvestorID);
        data["InstrumentID"] = toUtf(pParkedOrder->InstrumentID);
        data["OrderRef"] = toUtf(pParkedOrder->OrderRef);
        data["UserID"] = toUtf(pParkedOrder->UserID);
        data["OrderPriceType"] = pParkedOrder->OrderPriceType;
        data["Direction"] = pParkedOrder->Direction;
        data["CombOffsetFlag"] = toUtf(pParkedOrder->CombOffsetFlag);
        data["CombHedgeFlag"] = toUtf(pParkedOrder->CombHedgeFlag);
        data["LimitPrice"] = pParkedOrder->LimitPrice;
        data["VolumeTotalOriginal"] = pParkedOrder->VolumeTotalOriginal;
        data["TimeCondition"] = pParkedOrder->TimeCondition;
        data["GTDDate"] = toUtf(pParkedOrder->GTDDate);
        data["VolumeCondition"] = pParkedOrder->VolumeCondition;
        data["MinVolume"] = pParkedOrder->MinVolume;
        data["ContingentCondition"] = pParkedOrder->ContingentCondition;
        data["StopPrice"] = pParkedOrder->StopPrice;
        data["ForceCloseReason"] = pParkedOrder->ForceCloseReason;
        data["IsAutoSuspend"] = pParkedOrder->IsAutoSuspend;
        data["BusinessUnit"] = toUtf(pParkedOrder->BusinessUnit);
        data["RequestID"] = pParkedOrder->RequestID;
        data["UserForceClose"] = pParkedOrder->UserForceClose;
        data["ExchangeID"] = toUtf(pParkedOrder->ExchangeID);
        data["ParkedOrderID"] = toUtf(pParkedOrder->ParkedOrderID);
        data["UserType"] = pParkedOrder->UserType;
        data["Status"] = pParkedOrder->Status;
        data["ErrorID"] = pParkedOrder->ErrorID;
        data["ErrorMsg"] = toUtf(pParkedOrder->ErrorMsg);
        data["IsSwapOrder"] = pParkedOrder->IsSwapOrder;
        data["AccountID"] = toUtf(pParkedOrder->AccountID);
        data["CurrencyID"] = toUtf(pParkedOrder->CurrencyID);
        data["ClientID"] = toUtf(pParkedOrder->ClientID);
        data["InvestUnitID"] = toUtf(pParkedOrder->InvestUnitID);
        data["IPAddress"] = toUtf(pParkedOrder->IPAddress);
        data["MacAddress"] = toUtf(pParkedOrder->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryParkedOrder(data,error,nRequestID,bIsLast);
}

///请求查询预埋撤单响应
void PyTdApi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pParkedOrderAction)
    {
        data["BrokerID"] = toUtf(pParkedOrderAction->BrokerID);
        data["InvestorID"] = toUtf(pParkedOrderAction->InvestorID);
        data["OrderActionRef"] = pParkedOrderAction->OrderActionRef;
        data["OrderRef"] = toUtf(pParkedOrderAction->OrderRef);
        data["RequestID"] = pParkedOrderAction->RequestID;
        data["FrontID"] = pParkedOrderAction->FrontID;
        data["SessionID"] = pParkedOrderAction->SessionID;
        data["ExchangeID"] = toUtf(pParkedOrderAction->ExchangeID);
        data["OrderSysID"] = toUtf(pParkedOrderAction->OrderSysID);
        data["ActionFlag"] = pParkedOrderAction->ActionFlag;
        data["LimitPrice"] = pParkedOrderAction->LimitPrice;
        data["VolumeChange"] = pParkedOrderAction->VolumeChange;
        data["UserID"] = toUtf(pParkedOrderAction->UserID);
        data["InstrumentID"] = toUtf(pParkedOrderAction->InstrumentID);
        data["ParkedOrderActionID"] = toUtf(pParkedOrderAction->ParkedOrderActionID);
        data["UserType"] = pParkedOrderAction->UserType;
        data["Status"] = pParkedOrderAction->Status;
        data["ErrorID"] = pParkedOrderAction->ErrorID;
        data["ErrorMsg"] = toUtf(pParkedOrderAction->ErrorMsg);
        data["InvestUnitID"] = toUtf(pParkedOrderAction->InvestUnitID);
        data["IPAddress"] = toUtf(pParkedOrderAction->IPAddress);
        data["MacAddress"] = toUtf(pParkedOrderAction->MacAddress);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryParkedOrderAction(data,error,nRequestID,bIsLast);
}

///请求查询交易通知响应
void PyTdApi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pTradingNotice)
    {
        data["BrokerID"] = toUtf(pTradingNotice->BrokerID);
        data["InvestorRange"] = pTradingNotice->InvestorRange;
        data["InvestorID"] = toUtf(pTradingNotice->InvestorID);
        data["SequenceSeries"] = pTradingNotice->SequenceSeries;
        data["UserID"] = toUtf(pTradingNotice->UserID);
        data["SendTime"] = toUtf(pTradingNotice->SendTime);
        data["SequenceNo"] = pTradingNotice->SequenceNo;
        data["FieldContent"] = toUtf(pTradingNotice->FieldContent);
        data["InvestUnitID"] = toUtf(pTradingNotice->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryTradingNotice(data,error,nRequestID,bIsLast);
}

///请求查询经纪公司交易参数响应
void PyTdApi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pBrokerTradingParams)
    {
        data["BrokerID"] = toUtf(pBrokerTradingParams->BrokerID);
        data["InvestorID"] = toUtf(pBrokerTradingParams->InvestorID);
        data["MarginPriceType"] = pBrokerTradingParams->MarginPriceType;
        data["Algorithm"] = pBrokerTradingParams->Algorithm;
        data["AvailIncludeCloseProfit"] = pBrokerTradingParams->AvailIncludeCloseProfit;
        data["CurrencyID"] = toUtf(pBrokerTradingParams->CurrencyID);
        data["OptionRoyaltyPriceType"] = pBrokerTradingParams->OptionRoyaltyPriceType;
        data["AccountID"] = toUtf(pBrokerTradingParams->AccountID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryBrokerTradingParams(data,error,nRequestID,bIsLast);
}

///请求查询经纪公司交易算法响应
void PyTdApi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pBrokerTradingAlgos)
    {
        data["BrokerID"] = toUtf(pBrokerTradingAlgos->BrokerID);
        data["ExchangeID"] = toUtf(pBrokerTradingAlgos->ExchangeID);
        data["InstrumentID"] = toUtf(pBrokerTradingAlgos->InstrumentID);
        data["HandlePositionAlgoID"] = pBrokerTradingAlgos->HandlePositionAlgoID;
        data["FindMarginRateAlgoID"] = pBrokerTradingAlgos->FindMarginRateAlgoID;
        data["HandleTradingAccountAlgoID"] = pBrokerTradingAlgos->HandleTradingAccountAlgoID;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryBrokerTradingAlgos(data,error,nRequestID,bIsLast);
}

///请求查询监控中心用户令牌
void PyTdApi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pQueryCFMMCTradingAccountToken)
    {
        data["BrokerID"] = toUtf(pQueryCFMMCTradingAccountToken->BrokerID);
        data["InvestorID"] = toUtf(pQueryCFMMCTradingAccountToken->InvestorID);
        data["InvestUnitID"] = toUtf(pQueryCFMMCTradingAccountToken->InvestUnitID);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQueryCFMMCTradingAccountToken(data,error,nRequestID,bIsLast);
}

///银行发起银行资金转期货通知
void PyTdApi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspTransfer)
    {
        data["TradeCode"] = toUtf(pRspTransfer->TradeCode);
        data["BankID"] = toUtf(pRspTransfer->BankID);
        data["BankBranchID"] = toUtf(pRspTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pRspTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspTransfer->TradeDate);
        data["TradeTime"] = toUtf(pRspTransfer->TradeTime);
        data["BankSerial"] = toUtf(pRspTransfer->BankSerial);
        data["TradingDay"] = toUtf(pRspTransfer->TradingDay);
        data["PlateSerial"] = pRspTransfer->PlateSerial;
        data["LastFragment"] = pRspTransfer->LastFragment;
        data["SessionID"] = pRspTransfer->SessionID;
        data["CustomerName"] = toUtf(pRspTransfer->CustomerName);
        data["IdCardType"] = pRspTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspTransfer->IdentifiedCardNo);
        data["CustType"] = pRspTransfer->CustType;
        data["BankAccount"] = toUtf(pRspTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pRspTransfer->BankPassWord);
        data["AccountID"] = toUtf(pRspTransfer->AccountID);
        data["Password"] = toUtf(pRspTransfer->Password);
        data["InstallID"] = pRspTransfer->InstallID;
        data["FutureSerial"] = pRspTransfer->FutureSerial;
        data["UserID"] = toUtf(pRspTransfer->UserID);
        data["VerifyCertNoFlag"] = pRspTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspTransfer->CurrencyID);
        data["TradeAmount"] = pRspTransfer->TradeAmount;
        data["FutureFetchAmount"] = pRspTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pRspTransfer->FeePayFlag;
        data["CustFee"] = pRspTransfer->CustFee;
        data["BrokerFee"] = pRspTransfer->BrokerFee;
        data["Message"] = toUtf(pRspTransfer->Message);
        data["Digest"] = toUtf(pRspTransfer->Digest);
        data["BankAccType"] = pRspTransfer->BankAccType;
        data["DeviceID"] = toUtf(pRspTransfer->DeviceID);
        data["BankSecuAccType"] = pRspTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pRspTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pRspTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspTransfer->OperNo);
        data["RequestID"] = pRspTransfer->RequestID;
        data["TID"] = pRspTransfer->TID;
        data["TransferStatus"] = pRspTransfer->TransferStatus;
        data["ErrorID"] = pRspTransfer->ErrorID;
        data["ErrorMsg"] = toUtf(pRspTransfer->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspTransfer->LongCustomerName);
    }
    OnRtnFromBankToFutureByBank(data);
}

///银行发起期货资金转银行通知
void PyTdApi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspTransfer)
    {
        data["TradeCode"] = toUtf(pRspTransfer->TradeCode);
        data["BankID"] = toUtf(pRspTransfer->BankID);
        data["BankBranchID"] = toUtf(pRspTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pRspTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspTransfer->TradeDate);
        data["TradeTime"] = toUtf(pRspTransfer->TradeTime);
        data["BankSerial"] = toUtf(pRspTransfer->BankSerial);
        data["TradingDay"] = toUtf(pRspTransfer->TradingDay);
        data["PlateSerial"] = pRspTransfer->PlateSerial;
        data["LastFragment"] = pRspTransfer->LastFragment;
        data["SessionID"] = pRspTransfer->SessionID;
        data["CustomerName"] = toUtf(pRspTransfer->CustomerName);
        data["IdCardType"] = pRspTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspTransfer->IdentifiedCardNo);
        data["CustType"] = pRspTransfer->CustType;
        data["BankAccount"] = toUtf(pRspTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pRspTransfer->BankPassWord);
        data["AccountID"] = toUtf(pRspTransfer->AccountID);
        data["Password"] = toUtf(pRspTransfer->Password);
        data["InstallID"] = pRspTransfer->InstallID;
        data["FutureSerial"] = pRspTransfer->FutureSerial;
        data["UserID"] = toUtf(pRspTransfer->UserID);
        data["VerifyCertNoFlag"] = pRspTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspTransfer->CurrencyID);
        data["TradeAmount"] = pRspTransfer->TradeAmount;
        data["FutureFetchAmount"] = pRspTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pRspTransfer->FeePayFlag;
        data["CustFee"] = pRspTransfer->CustFee;
        data["BrokerFee"] = pRspTransfer->BrokerFee;
        data["Message"] = toUtf(pRspTransfer->Message);
        data["Digest"] = toUtf(pRspTransfer->Digest);
        data["BankAccType"] = pRspTransfer->BankAccType;
        data["DeviceID"] = toUtf(pRspTransfer->DeviceID);
        data["BankSecuAccType"] = pRspTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pRspTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pRspTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspTransfer->OperNo);
        data["RequestID"] = pRspTransfer->RequestID;
        data["TID"] = pRspTransfer->TID;
        data["TransferStatus"] = pRspTransfer->TransferStatus;
        data["ErrorID"] = pRspTransfer->ErrorID;
        data["ErrorMsg"] = toUtf(pRspTransfer->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspTransfer->LongCustomerName);
    }
    OnRtnFromFutureToBankByBank(data);
}

///银行发起冲正银行转期货通知
void PyTdApi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromBankToFutureByBank(data);
}

///银行发起冲正期货转银行通知
void PyTdApi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromFutureToBankByBank(data);
}

///期货发起银行资金转期货通知
void PyTdApi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspTransfer)
    {
        data["TradeCode"] = toUtf(pRspTransfer->TradeCode);
        data["BankID"] = toUtf(pRspTransfer->BankID);
        data["BankBranchID"] = toUtf(pRspTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pRspTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspTransfer->TradeDate);
        data["TradeTime"] = toUtf(pRspTransfer->TradeTime);
        data["BankSerial"] = toUtf(pRspTransfer->BankSerial);
        data["TradingDay"] = toUtf(pRspTransfer->TradingDay);
        data["PlateSerial"] = pRspTransfer->PlateSerial;
        data["LastFragment"] = pRspTransfer->LastFragment;
        data["SessionID"] = pRspTransfer->SessionID;
        data["CustomerName"] = toUtf(pRspTransfer->CustomerName);
        data["IdCardType"] = pRspTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspTransfer->IdentifiedCardNo);
        data["CustType"] = pRspTransfer->CustType;
        data["BankAccount"] = toUtf(pRspTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pRspTransfer->BankPassWord);
        data["AccountID"] = toUtf(pRspTransfer->AccountID);
        data["Password"] = toUtf(pRspTransfer->Password);
        data["InstallID"] = pRspTransfer->InstallID;
        data["FutureSerial"] = pRspTransfer->FutureSerial;
        data["UserID"] = toUtf(pRspTransfer->UserID);
        data["VerifyCertNoFlag"] = pRspTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspTransfer->CurrencyID);
        data["TradeAmount"] = pRspTransfer->TradeAmount;
        data["FutureFetchAmount"] = pRspTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pRspTransfer->FeePayFlag;
        data["CustFee"] = pRspTransfer->CustFee;
        data["BrokerFee"] = pRspTransfer->BrokerFee;
        data["Message"] = toUtf(pRspTransfer->Message);
        data["Digest"] = toUtf(pRspTransfer->Digest);
        data["BankAccType"] = pRspTransfer->BankAccType;
        data["DeviceID"] = toUtf(pRspTransfer->DeviceID);
        data["BankSecuAccType"] = pRspTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pRspTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pRspTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspTransfer->OperNo);
        data["RequestID"] = pRspTransfer->RequestID;
        data["TID"] = pRspTransfer->TID;
        data["TransferStatus"] = pRspTransfer->TransferStatus;
        data["ErrorID"] = pRspTransfer->ErrorID;
        data["ErrorMsg"] = toUtf(pRspTransfer->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspTransfer->LongCustomerName);
    }
    OnRtnFromBankToFutureByFuture(data);
}

///期货发起期货资金转银行通知
void PyTdApi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspTransfer)
    {
        data["TradeCode"] = toUtf(pRspTransfer->TradeCode);
        data["BankID"] = toUtf(pRspTransfer->BankID);
        data["BankBranchID"] = toUtf(pRspTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pRspTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspTransfer->TradeDate);
        data["TradeTime"] = toUtf(pRspTransfer->TradeTime);
        data["BankSerial"] = toUtf(pRspTransfer->BankSerial);
        data["TradingDay"] = toUtf(pRspTransfer->TradingDay);
        data["PlateSerial"] = pRspTransfer->PlateSerial;
        data["LastFragment"] = pRspTransfer->LastFragment;
        data["SessionID"] = pRspTransfer->SessionID;
        data["CustomerName"] = toUtf(pRspTransfer->CustomerName);
        data["IdCardType"] = pRspTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspTransfer->IdentifiedCardNo);
        data["CustType"] = pRspTransfer->CustType;
        data["BankAccount"] = toUtf(pRspTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pRspTransfer->BankPassWord);
        data["AccountID"] = toUtf(pRspTransfer->AccountID);
        data["Password"] = toUtf(pRspTransfer->Password);
        data["InstallID"] = pRspTransfer->InstallID;
        data["FutureSerial"] = pRspTransfer->FutureSerial;
        data["UserID"] = toUtf(pRspTransfer->UserID);
        data["VerifyCertNoFlag"] = pRspTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspTransfer->CurrencyID);
        data["TradeAmount"] = pRspTransfer->TradeAmount;
        data["FutureFetchAmount"] = pRspTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pRspTransfer->FeePayFlag;
        data["CustFee"] = pRspTransfer->CustFee;
        data["BrokerFee"] = pRspTransfer->BrokerFee;
        data["Message"] = toUtf(pRspTransfer->Message);
        data["Digest"] = toUtf(pRspTransfer->Digest);
        data["BankAccType"] = pRspTransfer->BankAccType;
        data["DeviceID"] = toUtf(pRspTransfer->DeviceID);
        data["BankSecuAccType"] = pRspTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pRspTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pRspTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspTransfer->OperNo);
        data["RequestID"] = pRspTransfer->RequestID;
        data["TID"] = pRspTransfer->TID;
        data["TransferStatus"] = pRspTransfer->TransferStatus;
        data["ErrorID"] = pRspTransfer->ErrorID;
        data["ErrorMsg"] = toUtf(pRspTransfer->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspTransfer->LongCustomerName);
    }
    OnRtnFromFutureToBankByFuture(data);
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void PyTdApi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromBankToFutureByFutureManual(data);
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void PyTdApi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromFutureToBankByFutureManual(data);
}

///期货发起查询银行余额通知
void PyTdApi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pNotifyQueryAccount)
    {
        data["TradeCode"] = toUtf(pNotifyQueryAccount->TradeCode);
        data["BankID"] = toUtf(pNotifyQueryAccount->BankID);
        data["BankBranchID"] = toUtf(pNotifyQueryAccount->BankBranchID);
        data["BrokerID"] = toUtf(pNotifyQueryAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pNotifyQueryAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pNotifyQueryAccount->TradeDate);
        data["TradeTime"] = toUtf(pNotifyQueryAccount->TradeTime);
        data["BankSerial"] = toUtf(pNotifyQueryAccount->BankSerial);
        data["TradingDay"] = toUtf(pNotifyQueryAccount->TradingDay);
        data["PlateSerial"] = pNotifyQueryAccount->PlateSerial;
        data["LastFragment"] = pNotifyQueryAccount->LastFragment;
        data["SessionID"] = pNotifyQueryAccount->SessionID;
        data["CustomerName"] = toUtf(pNotifyQueryAccount->CustomerName);
        data["IdCardType"] = pNotifyQueryAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pNotifyQueryAccount->IdentifiedCardNo);
        data["CustType"] = pNotifyQueryAccount->CustType;
        data["BankAccount"] = toUtf(pNotifyQueryAccount->BankAccount);
        data["BankPassWord"] = toUtf(pNotifyQueryAccount->BankPassWord);
        data["AccountID"] = toUtf(pNotifyQueryAccount->AccountID);
        data["Password"] = toUtf(pNotifyQueryAccount->Password);
        data["FutureSerial"] = pNotifyQueryAccount->FutureSerial;
        data["InstallID"] = pNotifyQueryAccount->InstallID;
        data["UserID"] = toUtf(pNotifyQueryAccount->UserID);
        data["VerifyCertNoFlag"] = pNotifyQueryAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pNotifyQueryAccount->CurrencyID);
        data["Digest"] = toUtf(pNotifyQueryAccount->Digest);
        data["BankAccType"] = pNotifyQueryAccount->BankAccType;
        data["DeviceID"] = toUtf(pNotifyQueryAccount->DeviceID);
        data["BankSecuAccType"] = pNotifyQueryAccount->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pNotifyQueryAccount->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pNotifyQueryAccount->BankSecuAcc);
        data["BankPwdFlag"] = pNotifyQueryAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pNotifyQueryAccount->SecuPwdFlag;
        data["OperNo"] = toUtf(pNotifyQueryAccount->OperNo);
        data["RequestID"] = pNotifyQueryAccount->RequestID;
        data["TID"] = pNotifyQueryAccount->TID;
        data["BankUseAmount"] = pNotifyQueryAccount->BankUseAmount;
        data["BankFetchAmount"] = pNotifyQueryAccount->BankFetchAmount;
        data["ErrorID"] = pNotifyQueryAccount->ErrorID;
        data["ErrorMsg"] = toUtf(pNotifyQueryAccount->ErrorMsg);
        data["LongCustomerName"] = toUtf(pNotifyQueryAccount->LongCustomerName);
    }
    OnRtnQueryBankBalanceByFuture(data);
}

///期货发起银行资金转期货错误回报
void PyTdApi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqTransfer)
    {
        data["TradeCode"] = toUtf(pReqTransfer->TradeCode);
        data["BankID"] = toUtf(pReqTransfer->BankID);
        data["BankBranchID"] = toUtf(pReqTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pReqTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqTransfer->TradeDate);
        data["TradeTime"] = toUtf(pReqTransfer->TradeTime);
        data["BankSerial"] = toUtf(pReqTransfer->BankSerial);
        data["TradingDay"] = toUtf(pReqTransfer->TradingDay);
        data["PlateSerial"] = pReqTransfer->PlateSerial;
        data["LastFragment"] = pReqTransfer->LastFragment;
        data["SessionID"] = pReqTransfer->SessionID;
        data["CustomerName"] = toUtf(pReqTransfer->CustomerName);
        data["IdCardType"] = pReqTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqTransfer->IdentifiedCardNo);
        data["CustType"] = pReqTransfer->CustType;
        data["BankAccount"] = toUtf(pReqTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pReqTransfer->BankPassWord);
        data["AccountID"] = toUtf(pReqTransfer->AccountID);
        data["Password"] = toUtf(pReqTransfer->Password);
        data["InstallID"] = pReqTransfer->InstallID;
        data["FutureSerial"] = pReqTransfer->FutureSerial;
        data["UserID"] = toUtf(pReqTransfer->UserID);
        data["VerifyCertNoFlag"] = pReqTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqTransfer->CurrencyID);
        data["TradeAmount"] = pReqTransfer->TradeAmount;
        data["FutureFetchAmount"] = pReqTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pReqTransfer->FeePayFlag;
        data["CustFee"] = pReqTransfer->CustFee;
        data["BrokerFee"] = pReqTransfer->BrokerFee;
        data["Message"] = toUtf(pReqTransfer->Message);
        data["Digest"] = toUtf(pReqTransfer->Digest);
        data["BankAccType"] = pReqTransfer->BankAccType;
        data["DeviceID"] = toUtf(pReqTransfer->DeviceID);
        data["BankSecuAccType"] = pReqTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pReqTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pReqTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqTransfer->OperNo);
        data["RequestID"] = pReqTransfer->RequestID;
        data["TID"] = pReqTransfer->TID;
        data["TransferStatus"] = pReqTransfer->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqTransfer->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnBankToFutureByFuture(data, error);
}

///期货发起期货资金转银行错误回报
void PyTdApi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqTransfer)
    {
        data["TradeCode"] = toUtf(pReqTransfer->TradeCode);
        data["BankID"] = toUtf(pReqTransfer->BankID);
        data["BankBranchID"] = toUtf(pReqTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pReqTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqTransfer->TradeDate);
        data["TradeTime"] = toUtf(pReqTransfer->TradeTime);
        data["BankSerial"] = toUtf(pReqTransfer->BankSerial);
        data["TradingDay"] = toUtf(pReqTransfer->TradingDay);
        data["PlateSerial"] = pReqTransfer->PlateSerial;
        data["LastFragment"] = pReqTransfer->LastFragment;
        data["SessionID"] = pReqTransfer->SessionID;
        data["CustomerName"] = toUtf(pReqTransfer->CustomerName);
        data["IdCardType"] = pReqTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqTransfer->IdentifiedCardNo);
        data["CustType"] = pReqTransfer->CustType;
        data["BankAccount"] = toUtf(pReqTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pReqTransfer->BankPassWord);
        data["AccountID"] = toUtf(pReqTransfer->AccountID);
        data["Password"] = toUtf(pReqTransfer->Password);
        data["InstallID"] = pReqTransfer->InstallID;
        data["FutureSerial"] = pReqTransfer->FutureSerial;
        data["UserID"] = toUtf(pReqTransfer->UserID);
        data["VerifyCertNoFlag"] = pReqTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqTransfer->CurrencyID);
        data["TradeAmount"] = pReqTransfer->TradeAmount;
        data["FutureFetchAmount"] = pReqTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pReqTransfer->FeePayFlag;
        data["CustFee"] = pReqTransfer->CustFee;
        data["BrokerFee"] = pReqTransfer->BrokerFee;
        data["Message"] = toUtf(pReqTransfer->Message);
        data["Digest"] = toUtf(pReqTransfer->Digest);
        data["BankAccType"] = pReqTransfer->BankAccType;
        data["DeviceID"] = toUtf(pReqTransfer->DeviceID);
        data["BankSecuAccType"] = pReqTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pReqTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pReqTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqTransfer->OperNo);
        data["RequestID"] = pReqTransfer->RequestID;
        data["TID"] = pReqTransfer->TID;
        data["TransferStatus"] = pReqTransfer->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqTransfer->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnFutureToBankByFuture(data, error);
}

///系统运行时期货端手工发起冲正银行转期货错误回报
void PyTdApi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqRepeal)
    {
        data["RepealTimeInterval"] = pReqRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pReqRepeal->RepealedTimes;
        data["BankRepealFlag"] = pReqRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pReqRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pReqRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pReqRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pReqRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pReqRepeal->TradeCode);
        data["BankID"] = toUtf(pReqRepeal->BankID);
        data["BankBranchID"] = toUtf(pReqRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pReqRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqRepeal->TradeDate);
        data["TradeTime"] = toUtf(pReqRepeal->TradeTime);
        data["BankSerial"] = toUtf(pReqRepeal->BankSerial);
        data["TradingDay"] = toUtf(pReqRepeal->TradingDay);
        data["PlateSerial"] = pReqRepeal->PlateSerial;
        data["LastFragment"] = pReqRepeal->LastFragment;
        data["SessionID"] = pReqRepeal->SessionID;
        data["CustomerName"] = toUtf(pReqRepeal->CustomerName);
        data["IdCardType"] = pReqRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqRepeal->IdentifiedCardNo);
        data["CustType"] = pReqRepeal->CustType;
        data["BankAccount"] = toUtf(pReqRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pReqRepeal->BankPassWord);
        data["AccountID"] = toUtf(pReqRepeal->AccountID);
        data["Password"] = toUtf(pReqRepeal->Password);
        data["InstallID"] = pReqRepeal->InstallID;
        data["FutureSerial"] = pReqRepeal->FutureSerial;
        data["UserID"] = toUtf(pReqRepeal->UserID);
        data["VerifyCertNoFlag"] = pReqRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqRepeal->CurrencyID);
        data["TradeAmount"] = pReqRepeal->TradeAmount;
        data["FutureFetchAmount"] = pReqRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pReqRepeal->FeePayFlag;
        data["CustFee"] = pReqRepeal->CustFee;
        data["BrokerFee"] = pReqRepeal->BrokerFee;
        data["Message"] = toUtf(pReqRepeal->Message);
        data["Digest"] = toUtf(pReqRepeal->Digest);
        data["BankAccType"] = pReqRepeal->BankAccType;
        data["DeviceID"] = toUtf(pReqRepeal->DeviceID);
        data["BankSecuAccType"] = pReqRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pReqRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pReqRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqRepeal->OperNo);
        data["RequestID"] = pReqRepeal->RequestID;
        data["TID"] = pReqRepeal->TID;
        data["TransferStatus"] = pReqRepeal->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqRepeal->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnRepealBankToFutureByFutureManual(data, error);
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void PyTdApi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqRepeal)
    {
        data["RepealTimeInterval"] = pReqRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pReqRepeal->RepealedTimes;
        data["BankRepealFlag"] = pReqRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pReqRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pReqRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pReqRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pReqRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pReqRepeal->TradeCode);
        data["BankID"] = toUtf(pReqRepeal->BankID);
        data["BankBranchID"] = toUtf(pReqRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pReqRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqRepeal->TradeDate);
        data["TradeTime"] = toUtf(pReqRepeal->TradeTime);
        data["BankSerial"] = toUtf(pReqRepeal->BankSerial);
        data["TradingDay"] = toUtf(pReqRepeal->TradingDay);
        data["PlateSerial"] = pReqRepeal->PlateSerial;
        data["LastFragment"] = pReqRepeal->LastFragment;
        data["SessionID"] = pReqRepeal->SessionID;
        data["CustomerName"] = toUtf(pReqRepeal->CustomerName);
        data["IdCardType"] = pReqRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqRepeal->IdentifiedCardNo);
        data["CustType"] = pReqRepeal->CustType;
        data["BankAccount"] = toUtf(pReqRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pReqRepeal->BankPassWord);
        data["AccountID"] = toUtf(pReqRepeal->AccountID);
        data["Password"] = toUtf(pReqRepeal->Password);
        data["InstallID"] = pReqRepeal->InstallID;
        data["FutureSerial"] = pReqRepeal->FutureSerial;
        data["UserID"] = toUtf(pReqRepeal->UserID);
        data["VerifyCertNoFlag"] = pReqRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqRepeal->CurrencyID);
        data["TradeAmount"] = pReqRepeal->TradeAmount;
        data["FutureFetchAmount"] = pReqRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pReqRepeal->FeePayFlag;
        data["CustFee"] = pReqRepeal->CustFee;
        data["BrokerFee"] = pReqRepeal->BrokerFee;
        data["Message"] = toUtf(pReqRepeal->Message);
        data["Digest"] = toUtf(pReqRepeal->Digest);
        data["BankAccType"] = pReqRepeal->BankAccType;
        data["DeviceID"] = toUtf(pReqRepeal->DeviceID);
        data["BankSecuAccType"] = pReqRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pReqRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pReqRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqRepeal->OperNo);
        data["RequestID"] = pReqRepeal->RequestID;
        data["TID"] = pReqRepeal->TID;
        data["TransferStatus"] = pReqRepeal->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqRepeal->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnRepealFutureToBankByFutureManual(data, error);
}

///期货发起查询银行余额错误回报
void PyTdApi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqQueryAccount)
    {
        data["TradeCode"] = toUtf(pReqQueryAccount->TradeCode);
        data["BankID"] = toUtf(pReqQueryAccount->BankID);
        data["BankBranchID"] = toUtf(pReqQueryAccount->BankBranchID);
        data["BrokerID"] = toUtf(pReqQueryAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqQueryAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqQueryAccount->TradeDate);
        data["TradeTime"] = toUtf(pReqQueryAccount->TradeTime);
        data["BankSerial"] = toUtf(pReqQueryAccount->BankSerial);
        data["TradingDay"] = toUtf(pReqQueryAccount->TradingDay);
        data["PlateSerial"] = pReqQueryAccount->PlateSerial;
        data["LastFragment"] = pReqQueryAccount->LastFragment;
        data["SessionID"] = pReqQueryAccount->SessionID;
        data["CustomerName"] = toUtf(pReqQueryAccount->CustomerName);
        data["IdCardType"] = pReqQueryAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqQueryAccount->IdentifiedCardNo);
        data["CustType"] = pReqQueryAccount->CustType;
        data["BankAccount"] = toUtf(pReqQueryAccount->BankAccount);
        data["BankPassWord"] = toUtf(pReqQueryAccount->BankPassWord);
        data["AccountID"] = toUtf(pReqQueryAccount->AccountID);
        data["Password"] = toUtf(pReqQueryAccount->Password);
        data["FutureSerial"] = pReqQueryAccount->FutureSerial;
        data["InstallID"] = pReqQueryAccount->InstallID;
        data["UserID"] = toUtf(pReqQueryAccount->UserID);
        data["VerifyCertNoFlag"] = pReqQueryAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqQueryAccount->CurrencyID);
        data["Digest"] = toUtf(pReqQueryAccount->Digest);
        data["BankAccType"] = pReqQueryAccount->BankAccType;
        data["DeviceID"] = toUtf(pReqQueryAccount->DeviceID);
        data["BankSecuAccType"] = pReqQueryAccount->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqQueryAccount->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqQueryAccount->BankSecuAcc);
        data["BankPwdFlag"] = pReqQueryAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pReqQueryAccount->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqQueryAccount->OperNo);
        data["RequestID"] = pReqQueryAccount->RequestID;
        data["TID"] = pReqQueryAccount->TID;
        data["LongCustomerName"] = toUtf(pReqQueryAccount->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnErrRtnQueryBankBalanceByFuture(data, error);
}

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void PyTdApi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromBankToFutureByFuture(data);
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void PyTdApi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pRspRepeal)
    {
        data["RepealTimeInterval"] = pRspRepeal->RepealTimeInterval;
        data["RepealedTimes"] = pRspRepeal->RepealedTimes;
        data["BankRepealFlag"] = pRspRepeal->BankRepealFlag;
        data["BrokerRepealFlag"] = pRspRepeal->BrokerRepealFlag;
        data["PlateRepealSerial"] = pRspRepeal->PlateRepealSerial;
        data["BankRepealSerial"] = toUtf(pRspRepeal->BankRepealSerial);
        data["FutureRepealSerial"] = pRspRepeal->FutureRepealSerial;
        data["TradeCode"] = toUtf(pRspRepeal->TradeCode);
        data["BankID"] = toUtf(pRspRepeal->BankID);
        data["BankBranchID"] = toUtf(pRspRepeal->BankBranchID);
        data["BrokerID"] = toUtf(pRspRepeal->BrokerID);
        data["BrokerBranchID"] = toUtf(pRspRepeal->BrokerBranchID);
        data["TradeDate"] = toUtf(pRspRepeal->TradeDate);
        data["TradeTime"] = toUtf(pRspRepeal->TradeTime);
        data["BankSerial"] = toUtf(pRspRepeal->BankSerial);
        data["TradingDay"] = toUtf(pRspRepeal->TradingDay);
        data["PlateSerial"] = pRspRepeal->PlateSerial;
        data["LastFragment"] = pRspRepeal->LastFragment;
        data["SessionID"] = pRspRepeal->SessionID;
        data["CustomerName"] = toUtf(pRspRepeal->CustomerName);
        data["IdCardType"] = pRspRepeal->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pRspRepeal->IdentifiedCardNo);
        data["CustType"] = pRspRepeal->CustType;
        data["BankAccount"] = toUtf(pRspRepeal->BankAccount);
        data["BankPassWord"] = toUtf(pRspRepeal->BankPassWord);
        data["AccountID"] = toUtf(pRspRepeal->AccountID);
        data["Password"] = toUtf(pRspRepeal->Password);
        data["InstallID"] = pRspRepeal->InstallID;
        data["FutureSerial"] = pRspRepeal->FutureSerial;
        data["UserID"] = toUtf(pRspRepeal->UserID);
        data["VerifyCertNoFlag"] = pRspRepeal->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pRspRepeal->CurrencyID);
        data["TradeAmount"] = pRspRepeal->TradeAmount;
        data["FutureFetchAmount"] = pRspRepeal->FutureFetchAmount;
        data["FeePayFlag"] = pRspRepeal->FeePayFlag;
        data["CustFee"] = pRspRepeal->CustFee;
        data["BrokerFee"] = pRspRepeal->BrokerFee;
        data["Message"] = toUtf(pRspRepeal->Message);
        data["Digest"] = toUtf(pRspRepeal->Digest);
        data["BankAccType"] = pRspRepeal->BankAccType;
        data["DeviceID"] = toUtf(pRspRepeal->DeviceID);
        data["BankSecuAccType"] = pRspRepeal->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pRspRepeal->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pRspRepeal->BankSecuAcc);
        data["BankPwdFlag"] = pRspRepeal->BankPwdFlag;
        data["SecuPwdFlag"] = pRspRepeal->SecuPwdFlag;
        data["OperNo"] = toUtf(pRspRepeal->OperNo);
        data["RequestID"] = pRspRepeal->RequestID;
        data["TID"] = pRspRepeal->TID;
        data["TransferStatus"] = pRspRepeal->TransferStatus;
        data["ErrorID"] = pRspRepeal->ErrorID;
        data["ErrorMsg"] = toUtf(pRspRepeal->ErrorMsg);
        data["LongCustomerName"] = toUtf(pRspRepeal->LongCustomerName);
    }
    OnRtnRepealFromFutureToBankByFuture(data);
}

///期货发起银行资金转期货应答
void PyTdApi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqTransfer)
    {
        data["TradeCode"] = toUtf(pReqTransfer->TradeCode);
        data["BankID"] = toUtf(pReqTransfer->BankID);
        data["BankBranchID"] = toUtf(pReqTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pReqTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqTransfer->TradeDate);
        data["TradeTime"] = toUtf(pReqTransfer->TradeTime);
        data["BankSerial"] = toUtf(pReqTransfer->BankSerial);
        data["TradingDay"] = toUtf(pReqTransfer->TradingDay);
        data["PlateSerial"] = pReqTransfer->PlateSerial;
        data["LastFragment"] = pReqTransfer->LastFragment;
        data["SessionID"] = pReqTransfer->SessionID;
        data["CustomerName"] = toUtf(pReqTransfer->CustomerName);
        data["IdCardType"] = pReqTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqTransfer->IdentifiedCardNo);
        data["CustType"] = pReqTransfer->CustType;
        data["BankAccount"] = toUtf(pReqTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pReqTransfer->BankPassWord);
        data["AccountID"] = toUtf(pReqTransfer->AccountID);
        data["Password"] = toUtf(pReqTransfer->Password);
        data["InstallID"] = pReqTransfer->InstallID;
        data["FutureSerial"] = pReqTransfer->FutureSerial;
        data["UserID"] = toUtf(pReqTransfer->UserID);
        data["VerifyCertNoFlag"] = pReqTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqTransfer->CurrencyID);
        data["TradeAmount"] = pReqTransfer->TradeAmount;
        data["FutureFetchAmount"] = pReqTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pReqTransfer->FeePayFlag;
        data["CustFee"] = pReqTransfer->CustFee;
        data["BrokerFee"] = pReqTransfer->BrokerFee;
        data["Message"] = toUtf(pReqTransfer->Message);
        data["Digest"] = toUtf(pReqTransfer->Digest);
        data["BankAccType"] = pReqTransfer->BankAccType;
        data["DeviceID"] = toUtf(pReqTransfer->DeviceID);
        data["BankSecuAccType"] = pReqTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pReqTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pReqTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqTransfer->OperNo);
        data["RequestID"] = pReqTransfer->RequestID;
        data["TID"] = pReqTransfer->TID;
        data["TransferStatus"] = pReqTransfer->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqTransfer->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspFromBankToFutureByFuture(data,error,nRequestID,bIsLast);
}

///期货发起期货资金转银行应答
void PyTdApi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqTransfer)
    {
        data["TradeCode"] = toUtf(pReqTransfer->TradeCode);
        data["BankID"] = toUtf(pReqTransfer->BankID);
        data["BankBranchID"] = toUtf(pReqTransfer->BankBranchID);
        data["BrokerID"] = toUtf(pReqTransfer->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqTransfer->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqTransfer->TradeDate);
        data["TradeTime"] = toUtf(pReqTransfer->TradeTime);
        data["BankSerial"] = toUtf(pReqTransfer->BankSerial);
        data["TradingDay"] = toUtf(pReqTransfer->TradingDay);
        data["PlateSerial"] = pReqTransfer->PlateSerial;
        data["LastFragment"] = pReqTransfer->LastFragment;
        data["SessionID"] = pReqTransfer->SessionID;
        data["CustomerName"] = toUtf(pReqTransfer->CustomerName);
        data["IdCardType"] = pReqTransfer->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqTransfer->IdentifiedCardNo);
        data["CustType"] = pReqTransfer->CustType;
        data["BankAccount"] = toUtf(pReqTransfer->BankAccount);
        data["BankPassWord"] = toUtf(pReqTransfer->BankPassWord);
        data["AccountID"] = toUtf(pReqTransfer->AccountID);
        data["Password"] = toUtf(pReqTransfer->Password);
        data["InstallID"] = pReqTransfer->InstallID;
        data["FutureSerial"] = pReqTransfer->FutureSerial;
        data["UserID"] = toUtf(pReqTransfer->UserID);
        data["VerifyCertNoFlag"] = pReqTransfer->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqTransfer->CurrencyID);
        data["TradeAmount"] = pReqTransfer->TradeAmount;
        data["FutureFetchAmount"] = pReqTransfer->FutureFetchAmount;
        data["FeePayFlag"] = pReqTransfer->FeePayFlag;
        data["CustFee"] = pReqTransfer->CustFee;
        data["BrokerFee"] = pReqTransfer->BrokerFee;
        data["Message"] = toUtf(pReqTransfer->Message);
        data["Digest"] = toUtf(pReqTransfer->Digest);
        data["BankAccType"] = pReqTransfer->BankAccType;
        data["DeviceID"] = toUtf(pReqTransfer->DeviceID);
        data["BankSecuAccType"] = pReqTransfer->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqTransfer->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqTransfer->BankSecuAcc);
        data["BankPwdFlag"] = pReqTransfer->BankPwdFlag;
        data["SecuPwdFlag"] = pReqTransfer->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqTransfer->OperNo);
        data["RequestID"] = pReqTransfer->RequestID;
        data["TID"] = pReqTransfer->TID;
        data["TransferStatus"] = pReqTransfer->TransferStatus;
        data["LongCustomerName"] = toUtf(pReqTransfer->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspFromFutureToBankByFuture(data,error,nRequestID,bIsLast);
}

///期货发起查询银行余额应答
void PyTdApi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pReqQueryAccount)
    {
        data["TradeCode"] = toUtf(pReqQueryAccount->TradeCode);
        data["BankID"] = toUtf(pReqQueryAccount->BankID);
        data["BankBranchID"] = toUtf(pReqQueryAccount->BankBranchID);
        data["BrokerID"] = toUtf(pReqQueryAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pReqQueryAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pReqQueryAccount->TradeDate);
        data["TradeTime"] = toUtf(pReqQueryAccount->TradeTime);
        data["BankSerial"] = toUtf(pReqQueryAccount->BankSerial);
        data["TradingDay"] = toUtf(pReqQueryAccount->TradingDay);
        data["PlateSerial"] = pReqQueryAccount->PlateSerial;
        data["LastFragment"] = pReqQueryAccount->LastFragment;
        data["SessionID"] = pReqQueryAccount->SessionID;
        data["CustomerName"] = toUtf(pReqQueryAccount->CustomerName);
        data["IdCardType"] = pReqQueryAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pReqQueryAccount->IdentifiedCardNo);
        data["CustType"] = pReqQueryAccount->CustType;
        data["BankAccount"] = toUtf(pReqQueryAccount->BankAccount);
        data["BankPassWord"] = toUtf(pReqQueryAccount->BankPassWord);
        data["AccountID"] = toUtf(pReqQueryAccount->AccountID);
        data["Password"] = toUtf(pReqQueryAccount->Password);
        data["FutureSerial"] = pReqQueryAccount->FutureSerial;
        data["InstallID"] = pReqQueryAccount->InstallID;
        data["UserID"] = toUtf(pReqQueryAccount->UserID);
        data["VerifyCertNoFlag"] = pReqQueryAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pReqQueryAccount->CurrencyID);
        data["Digest"] = toUtf(pReqQueryAccount->Digest);
        data["BankAccType"] = pReqQueryAccount->BankAccType;
        data["DeviceID"] = toUtf(pReqQueryAccount->DeviceID);
        data["BankSecuAccType"] = pReqQueryAccount->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pReqQueryAccount->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pReqQueryAccount->BankSecuAcc);
        data["BankPwdFlag"] = pReqQueryAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pReqQueryAccount->SecuPwdFlag;
        data["OperNo"] = toUtf(pReqQueryAccount->OperNo);
        data["RequestID"] = pReqQueryAccount->RequestID;
        data["TID"] = pReqQueryAccount->TID;
        data["LongCustomerName"] = toUtf(pReqQueryAccount->LongCustomerName);
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQueryBankAccountMoneyByFuture(data,error,nRequestID,bIsLast);
}

///银行发起银期开户通知
void PyTdApi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pOpenAccount)
    {
        data["TradeCode"] = toUtf(pOpenAccount->TradeCode);
        data["BankID"] = toUtf(pOpenAccount->BankID);
        data["BankBranchID"] = toUtf(pOpenAccount->BankBranchID);
        data["BrokerID"] = toUtf(pOpenAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pOpenAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pOpenAccount->TradeDate);
        data["TradeTime"] = toUtf(pOpenAccount->TradeTime);
        data["BankSerial"] = toUtf(pOpenAccount->BankSerial);
        data["TradingDay"] = toUtf(pOpenAccount->TradingDay);
        data["PlateSerial"] = pOpenAccount->PlateSerial;
        data["LastFragment"] = pOpenAccount->LastFragment;
        data["SessionID"] = pOpenAccount->SessionID;
        data["CustomerName"] = toUtf(pOpenAccount->CustomerName);
        data["IdCardType"] = pOpenAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pOpenAccount->IdentifiedCardNo);
        data["Gender"] = pOpenAccount->Gender;
        data["CountryCode"] = toUtf(pOpenAccount->CountryCode);
        data["CustType"] = pOpenAccount->CustType;
        data["Address"] = toUtf(pOpenAccount->Address);
        data["ZipCode"] = toUtf(pOpenAccount->ZipCode);
        data["Telephone"] = toUtf(pOpenAccount->Telephone);
        data["MobilePhone"] = toUtf(pOpenAccount->MobilePhone);
        data["Fax"] = toUtf(pOpenAccount->Fax);
        data["EMail"] = toUtf(pOpenAccount->EMail);
        data["MoneyAccountStatus"] = pOpenAccount->MoneyAccountStatus;
        data["BankAccount"] = toUtf(pOpenAccount->BankAccount);
        data["BankPassWord"] = toUtf(pOpenAccount->BankPassWord);
        data["AccountID"] = toUtf(pOpenAccount->AccountID);
        data["Password"] = toUtf(pOpenAccount->Password);
        data["InstallID"] = pOpenAccount->InstallID;
        data["VerifyCertNoFlag"] = pOpenAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pOpenAccount->CurrencyID);
        data["CashExchangeCode"] = pOpenAccount->CashExchangeCode;
        data["Digest"] = toUtf(pOpenAccount->Digest);
        data["BankAccType"] = pOpenAccount->BankAccType;
        data["DeviceID"] = toUtf(pOpenAccount->DeviceID);
        data["BankSecuAccType"] = pOpenAccount->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pOpenAccount->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pOpenAccount->BankSecuAcc);
        data["BankPwdFlag"] = pOpenAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pOpenAccount->SecuPwdFlag;
        data["OperNo"] = toUtf(pOpenAccount->OperNo);
        data["TID"] = pOpenAccount->TID;
        data["UserID"] = toUtf(pOpenAccount->UserID);
        data["ErrorID"] = pOpenAccount->ErrorID;
        data["ErrorMsg"] = toUtf(pOpenAccount->ErrorMsg);
        data["LongCustomerName"] = toUtf(pOpenAccount->LongCustomerName);
    }
    OnRtnOpenAccountByBank(data);
}

///银行发起银期销户通知
void PyTdApi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCancelAccount)
    {
        data["TradeCode"] = toUtf(pCancelAccount->TradeCode);
        data["BankID"] = toUtf(pCancelAccount->BankID);
        data["BankBranchID"] = toUtf(pCancelAccount->BankBranchID);
        data["BrokerID"] = toUtf(pCancelAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pCancelAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pCancelAccount->TradeDate);
        data["TradeTime"] = toUtf(pCancelAccount->TradeTime);
        data["BankSerial"] = toUtf(pCancelAccount->BankSerial);
        data["TradingDay"] = toUtf(pCancelAccount->TradingDay);
        data["PlateSerial"] = pCancelAccount->PlateSerial;
        data["LastFragment"] = pCancelAccount->LastFragment;
        data["SessionID"] = pCancelAccount->SessionID;
        data["CustomerName"] = toUtf(pCancelAccount->CustomerName);
        data["IdCardType"] = pCancelAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pCancelAccount->IdentifiedCardNo);
        data["Gender"] = pCancelAccount->Gender;
        data["CountryCode"] = toUtf(pCancelAccount->CountryCode);
        data["CustType"] = pCancelAccount->CustType;
        data["Address"] = toUtf(pCancelAccount->Address);
        data["ZipCode"] = toUtf(pCancelAccount->ZipCode);
        data["Telephone"] = toUtf(pCancelAccount->Telephone);
        data["MobilePhone"] = toUtf(pCancelAccount->MobilePhone);
        data["Fax"] = toUtf(pCancelAccount->Fax);
        data["EMail"] = toUtf(pCancelAccount->EMail);
        data["MoneyAccountStatus"] = pCancelAccount->MoneyAccountStatus;
        data["BankAccount"] = toUtf(pCancelAccount->BankAccount);
        data["BankPassWord"] = toUtf(pCancelAccount->BankPassWord);
        data["AccountID"] = toUtf(pCancelAccount->AccountID);
        data["Password"] = toUtf(pCancelAccount->Password);
        data["InstallID"] = pCancelAccount->InstallID;
        data["VerifyCertNoFlag"] = pCancelAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pCancelAccount->CurrencyID);
        data["CashExchangeCode"] = pCancelAccount->CashExchangeCode;
        data["Digest"] = toUtf(pCancelAccount->Digest);
        data["BankAccType"] = pCancelAccount->BankAccType;
        data["DeviceID"] = toUtf(pCancelAccount->DeviceID);
        data["BankSecuAccType"] = pCancelAccount->BankSecuAccType;
        data["BrokerIDByBank"] = toUtf(pCancelAccount->BrokerIDByBank);
        data["BankSecuAcc"] = toUtf(pCancelAccount->BankSecuAcc);
        data["BankPwdFlag"] = pCancelAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pCancelAccount->SecuPwdFlag;
        data["OperNo"] = toUtf(pCancelAccount->OperNo);
        data["TID"] = pCancelAccount->TID;
        data["UserID"] = toUtf(pCancelAccount->UserID);
        data["ErrorID"] = pCancelAccount->ErrorID;
        data["ErrorMsg"] = toUtf(pCancelAccount->ErrorMsg);
        data["LongCustomerName"] = toUtf(pCancelAccount->LongCustomerName);
    }
    OnRtnCancelAccountByBank(data);
}

///银行发起变更银行账号通知
void PyTdApi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pChangeAccount)
    {
        data["TradeCode"] = toUtf(pChangeAccount->TradeCode);
        data["BankID"] = toUtf(pChangeAccount->BankID);
        data["BankBranchID"] = toUtf(pChangeAccount->BankBranchID);
        data["BrokerID"] = toUtf(pChangeAccount->BrokerID);
        data["BrokerBranchID"] = toUtf(pChangeAccount->BrokerBranchID);
        data["TradeDate"] = toUtf(pChangeAccount->TradeDate);
        data["TradeTime"] = toUtf(pChangeAccount->TradeTime);
        data["BankSerial"] = toUtf(pChangeAccount->BankSerial);
        data["TradingDay"] = toUtf(pChangeAccount->TradingDay);
        data["PlateSerial"] = pChangeAccount->PlateSerial;
        data["LastFragment"] = pChangeAccount->LastFragment;
        data["SessionID"] = pChangeAccount->SessionID;
        data["CustomerName"] = toUtf(pChangeAccount->CustomerName);
        data["IdCardType"] = pChangeAccount->IdCardType;
        data["IdentifiedCardNo"] = toUtf(pChangeAccount->IdentifiedCardNo);
        data["Gender"] = pChangeAccount->Gender;
        data["CountryCode"] = toUtf(pChangeAccount->CountryCode);
        data["CustType"] = pChangeAccount->CustType;
        data["Address"] = toUtf(pChangeAccount->Address);
        data["ZipCode"] = toUtf(pChangeAccount->ZipCode);
        data["Telephone"] = toUtf(pChangeAccount->Telephone);
        data["MobilePhone"] = toUtf(pChangeAccount->MobilePhone);
        data["Fax"] = toUtf(pChangeAccount->Fax);
        data["EMail"] = toUtf(pChangeAccount->EMail);
        data["MoneyAccountStatus"] = pChangeAccount->MoneyAccountStatus;
        data["BankAccount"] = toUtf(pChangeAccount->BankAccount);
        data["BankPassWord"] = toUtf(pChangeAccount->BankPassWord);
        data["NewBankAccount"] = toUtf(pChangeAccount->NewBankAccount);
        data["NewBankPassWord"] = toUtf(pChangeAccount->NewBankPassWord);
        data["AccountID"] = toUtf(pChangeAccount->AccountID);
        data["Password"] = toUtf(pChangeAccount->Password);
        data["BankAccType"] = pChangeAccount->BankAccType;
        data["InstallID"] = pChangeAccount->InstallID;
        data["VerifyCertNoFlag"] = pChangeAccount->VerifyCertNoFlag;
        data["CurrencyID"] = toUtf(pChangeAccount->CurrencyID);
        data["BrokerIDByBank"] = toUtf(pChangeAccount->BrokerIDByBank);
        data["BankPwdFlag"] = pChangeAccount->BankPwdFlag;
        data["SecuPwdFlag"] = pChangeAccount->SecuPwdFlag;
        data["TID"] = pChangeAccount->TID;
        data["Digest"] = toUtf(pChangeAccount->Digest);
        data["ErrorID"] = pChangeAccount->ErrorID;
        data["ErrorMsg"] = toUtf(pChangeAccount->ErrorMsg);
        data["LongCustomerName"] = toUtf(pChangeAccount->LongCustomerName);
    }
    OnRtnChangeAccountByBank(data);
}

///请求查询分类合约响应
void PyTdApi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pInstrument)
    {
        data["InstrumentID"] = toUtf(pInstrument->InstrumentID);
        data["ExchangeID"] = toUtf(pInstrument->ExchangeID);
        data["InstrumentName"] = toUtf(pInstrument->InstrumentName);
        data["ExchangeInstID"] = toUtf(pInstrument->ExchangeInstID);
        data["ProductID"] = toUtf(pInstrument->ProductID);
        data["ProductClass"] = pInstrument->ProductClass;
        data["DeliveryYear"] = pInstrument->DeliveryYear;
        data["DeliveryMonth"] = pInstrument->DeliveryMonth;
        data["MaxMarketOrderVolume"] = pInstrument->MaxMarketOrderVolume;
        data["MinMarketOrderVolume"] = pInstrument->MinMarketOrderVolume;
        data["MaxLimitOrderVolume"] = pInstrument->MaxLimitOrderVolume;
        data["MinLimitOrderVolume"] = pInstrument->MinLimitOrderVolume;
        data["VolumeMultiple"] = pInstrument->VolumeMultiple;
        data["PriceTick"] = pInstrument->PriceTick;
        data["CreateDate"] = toUtf(pInstrument->CreateDate);
        data["OpenDate"] = toUtf(pInstrument->OpenDate);
        data["ExpireDate"] = toUtf(pInstrument->ExpireDate);
        data["StartDelivDate"] = toUtf(pInstrument->StartDelivDate);
        data["EndDelivDate"] = toUtf(pInstrument->EndDelivDate);
        data["InstLifePhase"] = pInstrument->InstLifePhase;
        data["IsTrading"] = pInstrument->IsTrading;
        data["PositionType"] = pInstrument->PositionType;
        data["PositionDateType"] = pInstrument->PositionDateType;
        data["LongMarginRatio"] = pInstrument->LongMarginRatio;
        data["ShortMarginRatio"] = pInstrument->ShortMarginRatio;
        data["MaxMarginSideAlgorithm"] = pInstrument->MaxMarginSideAlgorithm;
        data["UnderlyingInstrID"] = toUtf(pInstrument->UnderlyingInstrID);
        data["StrikePrice"] = pInstrument->StrikePrice;
        data["OptionsType"] = pInstrument->OptionsType;
        data["UnderlyingMultiple"] = pInstrument->UnderlyingMultiple;
        data["CombinationType"] = pInstrument->CombinationType;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryClassifiedInstrument(data,error,nRequestID,bIsLast);
}

///请求组合优惠比例响应
void PyTdApi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *pCombPromotionParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    py::gil_scoped_acquire acquire;
    py::dict data;
    if (pCombPromotionParam)
    {
        data["ExchangeID"] = toUtf(pCombPromotionParam->ExchangeID);
        data["InstrumentID"] = toUtf(pCombPromotionParam->InstrumentID);
        data["CombHedgeFlag"] = toUtf(pCombPromotionParam->CombHedgeFlag);
        data["Xparameter"] = pCombPromotionParam->Xparameter;
    }
    py::dict error;
    if (pRspInfo)
    {
        error["ErrorID"] = pRspInfo->ErrorID;
        error["ErrorMsg"] = toUtf(pRspInfo->ErrorMsg);
    }
    OnRspQryCombPromotionParam(data,error,nRequestID,bIsLast);
}

//-------------------------------------------------------------------------------------
//python重载函数
//data：回调函数的数据字典
//error：回调函数的错误字典
//id：请求id
//last：是否为最后返回
//i：整数
//-------------------------------------------------------------------------------------

void PyTdApi::OnRspAuthenticate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspUserLogin(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspUserLogout(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspUserPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspTradingAccountPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspUserAuthMethod(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspGenUserCaptcha(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspGenUserText(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspParkedOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryMaxOrderVolume(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspSettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspRemoveParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspRemoveParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspExecOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspExecOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspForQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQuoteAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspBatchOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspOptionSelfCloseInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspOptionSelfCloseAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspCombActionInsert(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryOrder(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTrade(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestorPosition(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestor(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTradingCode(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInstrumentMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryExchange(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryProduct(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryDepthMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySettlementInfo(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTransferBank(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestorPositionDetail(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryNotice(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestorPositionCombineDetail(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryCFMMCTradingAccountKey(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryEWarrantOffset(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestorProductGroupMargin(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryExchangeMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryExchangeMarginRateAdjust(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryExchangeRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySecAgentACIDMap(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryProductExchRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryProductGroup(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryMMInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryMMOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInstrumentOrderCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySecAgentTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySecAgentCheckMode(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQrySecAgentTradeInfo(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryOptionInstrTradeCost(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryExecOrder(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryForQuote(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryQuote(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryOptionSelfClose(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryInvestUnit(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryCombInstrumentGuard(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryCombAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTransferSerial(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryAccountregister(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspError(const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRtnOrder(const py::dict &data) {}

void PyTdApi::OnRtnTrade(const py::dict &data) {}

void PyTdApi::OnErrRtnOrderInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnOrderAction(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnInstrumentStatus(const py::dict &data) {}

void PyTdApi::OnRtnBulletin(const py::dict &data) {}

void PyTdApi::OnRtnTradingNotice(const py::dict &data) {}

void PyTdApi::OnRtnErrorConditionalOrder(const py::dict &data) {}

void PyTdApi::OnRtnExecOrder(const py::dict &data) {}

void PyTdApi::OnErrRtnExecOrderInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnExecOrderAction(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnForQuoteInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnQuote(const py::dict &data) {}

void PyTdApi::OnErrRtnQuoteInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnQuoteAction(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnForQuoteRsp(const py::dict &data) {}

void PyTdApi::OnRtnCFMMCTradingAccountToken(const py::dict &data) {}

void PyTdApi::OnErrRtnBatchOrderAction(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnOptionSelfClose(const py::dict &data) {}

void PyTdApi::OnErrRtnOptionSelfCloseInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnOptionSelfCloseAction(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnCombAction(const py::dict &data) {}

void PyTdApi::OnErrRtnCombActionInsert(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRspQryContractBank(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryTradingNotice(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryBrokerTradingParams(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryBrokerTradingAlgos(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQueryCFMMCTradingAccountToken(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRtnFromBankToFutureByBank(const py::dict &data) {}

void PyTdApi::OnRtnFromFutureToBankByBank(const py::dict &data) {}

void PyTdApi::OnRtnRepealFromBankToFutureByBank(const py::dict &data) {}

void PyTdApi::OnRtnRepealFromFutureToBankByBank(const py::dict &data) {}

void PyTdApi::OnRtnFromBankToFutureByFuture(const py::dict &data) {}

void PyTdApi::OnRtnFromFutureToBankByFuture(const py::dict &data) {}

void PyTdApi::OnRtnRepealFromBankToFutureByFutureManual(const py::dict &data) {}

void PyTdApi::OnRtnRepealFromFutureToBankByFutureManual(const py::dict &data) {}

void PyTdApi::OnRtnQueryBankBalanceByFuture(const py::dict &data) {}

void PyTdApi::OnErrRtnBankToFutureByFuture(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnFutureToBankByFuture(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnRepealBankToFutureByFutureManual(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnRepealFutureToBankByFutureManual(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnErrRtnQueryBankBalanceByFuture(const py::dict &data, const py::dict &error) {}

void PyTdApi::OnRtnRepealFromBankToFutureByFuture(const py::dict &data) {}

void PyTdApi::OnRtnRepealFromFutureToBankByFuture(const py::dict &data) {}

void PyTdApi::OnRspFromBankToFutureByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspFromFutureToBankByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQueryBankAccountMoneyByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRtnOpenAccountByBank(const py::dict &data) {}

void PyTdApi::OnRtnCancelAccountByBank(const py::dict &data) {}

void PyTdApi::OnRtnChangeAccountByBank(const py::dict &data) {}

void PyTdApi::OnRspQryClassifiedInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) {}

void PyTdApi::OnRspQryCombPromotionParam(const py::dict &data, const py::dict &error, int reqid, bool last) {}

//-------------------------------------------------------------------------------------
//req:主动函数的请求字典
//-------------------------------------------------------------------------------------

void PyTdApi::createFtdcTraderApi(std::string pszFlowPath)
{
    api = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath.c_str());
    api->RegisterSpi(this);
};

void PyTdApi::release()
{
    api->Release();
};

void PyTdApi::init()
{
    active = true;
    api->Init();
};

int PyTdApi::join()
{
    int i = api->Join();
    return i;
};

void PyTdApi::exit()
{
    active = false;
    api->RegisterSpi(NULL);
    api->Release();
    api = NULL;
};

std::string PyTdApi::GetApiVersion()
{
    std::string ver = api->GetApiVersion();
    return ver;
};

std::string PyTdApi::getTradingDay()
{
    std::string day = api->GetTradingDay();
    return day;
};

void PyTdApi::registerFront(std::string pszFrontAddress)
{
    api->RegisterFront((char*)pszFrontAddress.c_str());
};

void PyTdApi::subscribePrivateTopic(int nType)
{
    api->SubscribePrivateTopic((THOST_TE_RESUME_TYPE) nType);
};

void PyTdApi::subscribePublicTopic(int nType)
{
    api->SubscribePublicTopic((THOST_TE_RESUME_TYPE)nType);
};

int PyTdApi::reqAuthenticate(const py::dict &req, int reqid)
{
    CThostFtdcReqAuthenticateField myreq = CThostFtdcReqAuthenticateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "UserProductInfo", myreq.UserProductInfo);
    getString(req, "AuthCode", myreq.AuthCode);
    getString(req, "AppID", myreq.AppID);
    int i = api->ReqAuthenticate(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserLogin(const py::dict &req, int reqid)
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
    getInt(req, "ClientIPPort", &myreq.ClientIPPort);
    int i = api->ReqUserLogin(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserLogout(const py::dict &req, int reqid)
{
    CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    int i = api->ReqUserLogout(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserPasswordUpdate(const py::dict &req, int reqid)
{
    CThostFtdcUserPasswordUpdateField myreq = CThostFtdcUserPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "OldPassword", myreq.OldPassword);
    getString(req, "NewPassword", myreq.NewPassword);
    int i = api->ReqUserPasswordUpdate(&myreq, reqid);
    return i;
};

int PyTdApi::reqTradingAccountPasswordUpdate(const py::dict &req, int reqid)
{
    CThostFtdcTradingAccountPasswordUpdateField myreq = CThostFtdcTradingAccountPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "OldPassword", myreq.OldPassword);
    getString(req, "NewPassword", myreq.NewPassword);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqTradingAccountPasswordUpdate(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserAuthMethod(const py::dict &req, int reqid)
{
    CThostFtdcReqUserAuthMethodField myreq = CThostFtdcReqUserAuthMethodField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    int i = api->ReqUserAuthMethod(&myreq, reqid);
    return i;
};

int PyTdApi::reqGenUserCaptcha(const py::dict &req, int reqid)
{
    CThostFtdcReqGenUserCaptchaField myreq = CThostFtdcReqGenUserCaptchaField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    int i = api->ReqGenUserCaptcha(&myreq, reqid);
    return i;
};

int PyTdApi::reqGenUserText(const py::dict &req, int reqid)
{
    CThostFtdcReqGenUserTextField myreq = CThostFtdcReqGenUserTextField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    int i = api->ReqGenUserText(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserLoginWithCaptcha(const py::dict &req, int reqid)
{
    CThostFtdcReqUserLoginWithCaptchaField myreq = CThostFtdcReqUserLoginWithCaptchaField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "Password", myreq.Password);
    getString(req, "UserProductInfo", myreq.UserProductInfo);
    getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
    getString(req, "ProtocolInfo", myreq.ProtocolInfo);
    getString(req, "MacAddress", myreq.MacAddress);
    getString(req, "ClientIPAddress", myreq.ClientIPAddress);
    getString(req, "LoginRemark", myreq.LoginRemark);
    getString(req, "Captcha", myreq.Captcha);
    getInt(req, "ClientIPPort", &myreq.ClientIPPort);
    int i = api->ReqUserLoginWithCaptcha(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserLoginWithText(const py::dict &req, int reqid)
{
    CThostFtdcReqUserLoginWithTextField myreq = CThostFtdcReqUserLoginWithTextField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "Password", myreq.Password);
    getString(req, "UserProductInfo", myreq.UserProductInfo);
    getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
    getString(req, "ProtocolInfo", myreq.ProtocolInfo);
    getString(req, "MacAddress", myreq.MacAddress);
    getString(req, "ClientIPAddress", myreq.ClientIPAddress);
    getString(req, "LoginRemark", myreq.LoginRemark);
    getString(req, "Text", myreq.Text);
    getInt(req, "ClientIPPort", &myreq.ClientIPPort);
    int i = api->ReqUserLoginWithText(&myreq, reqid);
    return i;
};

int PyTdApi::reqUserLoginWithOTP(const py::dict &req, int reqid)
{
    CThostFtdcReqUserLoginWithOTPField myreq = CThostFtdcReqUserLoginWithOTPField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "Password", myreq.Password);
    getString(req, "UserProductInfo", myreq.UserProductInfo);
    getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
    getString(req, "ProtocolInfo", myreq.ProtocolInfo);
    getString(req, "MacAddress", myreq.MacAddress);
    getString(req, "ClientIPAddress", myreq.ClientIPAddress);
    getString(req, "LoginRemark", myreq.LoginRemark);
    getString(req, "OTPPassword", myreq.OTPPassword);
    getInt(req, "ClientIPPort", &myreq.ClientIPPort);
    int i = api->ReqUserLoginWithOTP(&myreq, reqid);
    return i;
};

int PyTdApi::reqOrderInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputOrderField myreq = CThostFtdcInputOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "OrderRef", myreq.OrderRef);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "OrderPriceType", &myreq.OrderPriceType);
    getChar(req, "Direction", &myreq.Direction);
    getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
    getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
    getDouble(req, "LimitPrice", &myreq.LimitPrice);
    getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
    getChar(req, "TimeCondition", &myreq.TimeCondition);
    getString(req, "GTDDate", myreq.GTDDate);
    getChar(req, "VolumeCondition", &myreq.VolumeCondition);
    getInt(req, "MinVolume", &myreq.MinVolume);
    getChar(req, "ContingentCondition", &myreq.ContingentCondition);
    getDouble(req, "StopPrice", &myreq.StopPrice);
    getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
    getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
    getString(req, "BusinessUnit", myreq.BusinessUnit);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "UserForceClose", &myreq.UserForceClose);
    getInt(req, "IsSwapOrder", &myreq.IsSwapOrder);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqOrderInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqParkedOrderInsert(const py::dict &req, int reqid)
{
    CThostFtdcParkedOrderField myreq = CThostFtdcParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "OrderRef", myreq.OrderRef);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "OrderPriceType", &myreq.OrderPriceType);
    getChar(req, "Direction", &myreq.Direction);
    getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
    getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
    getDouble(req, "LimitPrice", &myreq.LimitPrice);
    getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
    getChar(req, "TimeCondition", &myreq.TimeCondition);
    getString(req, "GTDDate", myreq.GTDDate);
    getChar(req, "VolumeCondition", &myreq.VolumeCondition);
    getInt(req, "MinVolume", &myreq.MinVolume);
    getChar(req, "ContingentCondition", &myreq.ContingentCondition);
    getDouble(req, "StopPrice", &myreq.StopPrice);
    getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
    getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
    getString(req, "BusinessUnit", myreq.BusinessUnit);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "UserForceClose", &myreq.UserForceClose);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "ParkedOrderID", myreq.ParkedOrderID);
    getChar(req, "UserType", &myreq.UserType);
    getChar(req, "Status", &myreq.Status);
    getInt(req, "ErrorID", &myreq.ErrorID);
    getString(req, "ErrorMsg", myreq.ErrorMsg);
    getInt(req, "IsSwapOrder", &myreq.IsSwapOrder);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqParkedOrderInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqParkedOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcParkedOrderActionField myreq = CThostFtdcParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "OrderActionRef", &myreq.OrderActionRef);
    getString(req, "OrderRef", myreq.OrderRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "OrderSysID", myreq.OrderSysID);
    getChar(req, "ActionFlag", &myreq.ActionFlag);
    getDouble(req, "LimitPrice", &myreq.LimitPrice);
    getInt(req, "VolumeChange", &myreq.VolumeChange);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ParkedOrderActionID", myreq.ParkedOrderActionID);
    getChar(req, "UserType", &myreq.UserType);
    getChar(req, "Status", &myreq.Status);
    getInt(req, "ErrorID", &myreq.ErrorID);
    getString(req, "ErrorMsg", myreq.ErrorMsg);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqParkedOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcInputOrderActionField myreq = CThostFtdcInputOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "OrderActionRef", &myreq.OrderActionRef);
    getString(req, "OrderRef", myreq.OrderRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "OrderSysID", myreq.OrderSysID);
    getChar(req, "ActionFlag", &myreq.ActionFlag);
    getDouble(req, "LimitPrice", &myreq.LimitPrice);
    getInt(req, "VolumeChange", &myreq.VolumeChange);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryMaxOrderVolume(const py::dict &req, int reqid)
{
    CThostFtdcQryMaxOrderVolumeField myreq = CThostFtdcQryMaxOrderVolumeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getChar(req, "Direction", &myreq.Direction);
    getChar(req, "OffsetFlag", &myreq.OffsetFlag);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getInt(req, "MaxVolume", &myreq.MaxVolume);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryMaxOrderVolume(&myreq, reqid);
    return i;
};

int PyTdApi::reqSettlementInfoConfirm(const py::dict &req, int reqid)
{
    CThostFtdcSettlementInfoConfirmField myreq = CThostFtdcSettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ConfirmDate", myreq.ConfirmDate);
    getString(req, "ConfirmTime", myreq.ConfirmTime);
    getInt(req, "SettlementID", &myreq.SettlementID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqSettlementInfoConfirm(&myreq, reqid);
    return i;
};

int PyTdApi::reqRemoveParkedOrder(const py::dict &req, int reqid)
{
    CThostFtdcRemoveParkedOrderField myreq = CThostFtdcRemoveParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ParkedOrderID", myreq.ParkedOrderID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqRemoveParkedOrder(&myreq, reqid);
    return i;
};

int PyTdApi::reqRemoveParkedOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcRemoveParkedOrderActionField myreq = CThostFtdcRemoveParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ParkedOrderActionID", myreq.ParkedOrderActionID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqRemoveParkedOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqExecOrderInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputExecOrderField myreq = CThostFtdcInputExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExecOrderRef", myreq.ExecOrderRef);
    getString(req, "UserID", myreq.UserID);
    getInt(req, "Volume", &myreq.Volume);
    getInt(req, "RequestID", &myreq.RequestID);
    getString(req, "BusinessUnit", myreq.BusinessUnit);
    getChar(req, "OffsetFlag", &myreq.OffsetFlag);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getChar(req, "ActionType", &myreq.ActionType);
    getChar(req, "PosiDirection", &myreq.PosiDirection);
    getChar(req, "ReservePositionFlag", &myreq.ReservePositionFlag);
    getChar(req, "CloseFlag", &myreq.CloseFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqExecOrderInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqExecOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcInputExecOrderActionField myreq = CThostFtdcInputExecOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "ExecOrderActionRef", &myreq.ExecOrderActionRef);
    getString(req, "ExecOrderRef", myreq.ExecOrderRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
    getChar(req, "ActionFlag", &myreq.ActionFlag);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqExecOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqForQuoteInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputForQuoteField myreq = CThostFtdcInputForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ForQuoteRef", myreq.ForQuoteRef);
    getString(req, "UserID", myreq.UserID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqForQuoteInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqQuoteInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputQuoteField myreq = CThostFtdcInputQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "QuoteRef", myreq.QuoteRef);
    getString(req, "UserID", myreq.UserID);
    getDouble(req, "AskPrice", &myreq.AskPrice);
    getDouble(req, "BidPrice", &myreq.BidPrice);
    getInt(req, "AskVolume", &myreq.AskVolume);
    getInt(req, "BidVolume", &myreq.BidVolume);
    getInt(req, "RequestID", &myreq.RequestID);
    getString(req, "BusinessUnit", myreq.BusinessUnit);
    getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
    getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
    getChar(req, "AskHedgeFlag", &myreq.AskHedgeFlag);
    getChar(req, "BidHedgeFlag", &myreq.BidHedgeFlag);
    getString(req, "AskOrderRef", myreq.AskOrderRef);
    getString(req, "BidOrderRef", myreq.BidOrderRef);
    getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqQuoteInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqQuoteAction(const py::dict &req, int reqid)
{
    CThostFtdcInputQuoteActionField myreq = CThostFtdcInputQuoteActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "QuoteActionRef", &myreq.QuoteActionRef);
    getString(req, "QuoteRef", myreq.QuoteRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "QuoteSysID", myreq.QuoteSysID);
    getChar(req, "ActionFlag", &myreq.ActionFlag);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqQuoteAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqBatchOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcInputBatchOrderActionField myreq = CThostFtdcInputBatchOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "OrderActionRef", &myreq.OrderActionRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqBatchOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqOptionSelfCloseInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputOptionSelfCloseField myreq = CThostFtdcInputOptionSelfCloseField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
    getString(req, "UserID", myreq.UserID);
    getInt(req, "Volume", &myreq.Volume);
    getInt(req, "RequestID", &myreq.RequestID);
    getString(req, "BusinessUnit", myreq.BusinessUnit);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getChar(req, "OptSelfCloseFlag", &myreq.OptSelfCloseFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "ClientID", myreq.ClientID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqOptionSelfCloseInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqOptionSelfCloseAction(const py::dict &req, int reqid)
{
    CThostFtdcInputOptionSelfCloseActionField myreq = CThostFtdcInputOptionSelfCloseActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getInt(req, "OptionSelfCloseActionRef", &myreq.OptionSelfCloseActionRef);
    getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "FrontID", &myreq.FrontID);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
    getChar(req, "ActionFlag", &myreq.ActionFlag);
    getString(req, "UserID", myreq.UserID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    int i = api->ReqOptionSelfCloseAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqCombActionInsert(const py::dict &req, int reqid)
{
    CThostFtdcInputCombActionField myreq = CThostFtdcInputCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "CombActionRef", myreq.CombActionRef);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "Direction", &myreq.Direction);
    getInt(req, "Volume", &myreq.Volume);
    getChar(req, "CombDirection", &myreq.CombDirection);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "IPAddress", myreq.IPAddress);
    getString(req, "MacAddress", myreq.MacAddress);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqCombActionInsert(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryOrder(const py::dict &req, int reqid)
{
    CThostFtdcQryOrderField myreq = CThostFtdcQryOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "OrderSysID", myreq.OrderSysID);
    getString(req, "InsertTimeStart", myreq.InsertTimeStart);
    getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryOrder(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTrade(const py::dict &req, int reqid)
{
    CThostFtdcQryTradeField myreq = CThostFtdcQryTradeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "TradeID", myreq.TradeID);
    getString(req, "TradeTimeStart", myreq.TradeTimeStart);
    getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryTrade(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestorPosition(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestorPositionField myreq = CThostFtdcQryInvestorPositionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInvestorPosition(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTradingAccount(const py::dict &req, int reqid)
{
    CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getChar(req, "BizType", &myreq.BizType);
    getString(req, "AccountID", myreq.AccountID);
    int i = api->ReqQryTradingAccount(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestor(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestorField myreq = CThostFtdcQryInvestorField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    int i = api->ReqQryInvestor(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTradingCode(const py::dict &req, int reqid)
{
    CThostFtdcQryTradingCodeField myreq = CThostFtdcQryTradingCodeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "ClientID", myreq.ClientID);
    getChar(req, "ClientIDType", &myreq.ClientIDType);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryTradingCode(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInstrumentMarginRate(const py::dict &req, int reqid)
{
    CThostFtdcQryInstrumentMarginRateField myreq = CThostFtdcQryInstrumentMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInstrumentMarginRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInstrumentCommissionRate(const py::dict &req, int reqid)
{
    CThostFtdcQryInstrumentCommissionRateField myreq = CThostFtdcQryInstrumentCommissionRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInstrumentCommissionRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryExchange(const py::dict &req, int reqid)
{
    CThostFtdcQryExchangeField myreq = CThostFtdcQryExchangeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryExchange(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryProduct(const py::dict &req, int reqid)
{
    CThostFtdcQryProductField myreq = CThostFtdcQryProductField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "ProductID", myreq.ProductID);
    getChar(req, "ProductClass", &myreq.ProductClass);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryProduct(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInstrument(const py::dict &req, int reqid)
{
    CThostFtdcQryInstrumentField myreq = CThostFtdcQryInstrumentField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "ExchangeInstID", myreq.ExchangeInstID);
    getString(req, "ProductID", myreq.ProductID);
    int i = api->ReqQryInstrument(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryDepthMarketData(const py::dict &req, int reqid)
{
    CThostFtdcQryDepthMarketDataField myreq = CThostFtdcQryDepthMarketDataField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryDepthMarketData(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySettlementInfo(const py::dict &req, int reqid)
{
    CThostFtdcQrySettlementInfoField myreq = CThostFtdcQrySettlementInfoField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "TradingDay", myreq.TradingDay);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqQrySettlementInfo(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTransferBank(const py::dict &req, int reqid)
{
    CThostFtdcQryTransferBankField myreq = CThostFtdcQryTransferBankField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBrchID", myreq.BankBrchID);
    int i = api->ReqQryTransferBank(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestorPositionDetail(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestorPositionDetailField myreq = CThostFtdcQryInvestorPositionDetailField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInvestorPositionDetail(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryNotice(const py::dict &req, int reqid)
{
    CThostFtdcQryNoticeField myreq = CThostFtdcQryNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    int i = api->ReqQryNotice(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySettlementInfoConfirm(const py::dict &req, int reqid)
{
    CThostFtdcQrySettlementInfoConfirmField myreq = CThostFtdcQrySettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqQrySettlementInfoConfirm(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestorPositionCombineDetail(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestorPositionCombineDetailField myreq = CThostFtdcQryInvestorPositionCombineDetailField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "CombInstrumentID", myreq.CombInstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInvestorPositionCombineDetail(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryCFMMCTradingAccountKey(const py::dict &req, int reqid)
{
    CThostFtdcQryCFMMCTradingAccountKeyField myreq = CThostFtdcQryCFMMCTradingAccountKeyField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    int i = api->ReqQryCFMMCTradingAccountKey(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryEWarrantOffset(const py::dict &req, int reqid)
{
    CThostFtdcQryEWarrantOffsetField myreq = CThostFtdcQryEWarrantOffsetField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryEWarrantOffset(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestorProductGroupMargin(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestorProductGroupMarginField myreq = CThostFtdcQryInvestorProductGroupMarginField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "ProductGroupID", myreq.ProductGroupID);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInvestorProductGroupMargin(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryExchangeMarginRate(const py::dict &req, int reqid)
{
    CThostFtdcQryExchangeMarginRateField myreq = CThostFtdcQryExchangeMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryExchangeMarginRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryExchangeMarginRateAdjust(const py::dict &req, int reqid)
{
    CThostFtdcQryExchangeMarginRateAdjustField myreq = CThostFtdcQryExchangeMarginRateAdjustField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    int i = api->ReqQryExchangeMarginRateAdjust(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryExchangeRate(const py::dict &req, int reqid)
{
    CThostFtdcQryExchangeRateField myreq = CThostFtdcQryExchangeRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "FromCurrencyID", myreq.FromCurrencyID);
    getString(req, "ToCurrencyID", myreq.ToCurrencyID);
    int i = api->ReqQryExchangeRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySecAgentACIDMap(const py::dict &req, int reqid)
{
    CThostFtdcQrySecAgentACIDMapField myreq = CThostFtdcQrySecAgentACIDMapField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "UserID", myreq.UserID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqQrySecAgentACIDMap(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryProductExchRate(const py::dict &req, int reqid)
{
    CThostFtdcQryProductExchRateField myreq = CThostFtdcQryProductExchRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "ProductID", myreq.ProductID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryProductExchRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryProductGroup(const py::dict &req, int reqid)
{
    CThostFtdcQryProductGroupField myreq = CThostFtdcQryProductGroupField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "ProductID", myreq.ProductID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryProductGroup(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryMMInstrumentCommissionRate(const py::dict &req, int reqid)
{
    CThostFtdcQryMMInstrumentCommissionRateField myreq = CThostFtdcQryMMInstrumentCommissionRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    int i = api->ReqQryMMInstrumentCommissionRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryMMOptionInstrCommRate(const py::dict &req, int reqid)
{
    CThostFtdcQryMMOptionInstrCommRateField myreq = CThostFtdcQryMMOptionInstrCommRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    int i = api->ReqQryMMOptionInstrCommRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInstrumentOrderCommRate(const py::dict &req, int reqid)
{
    CThostFtdcQryInstrumentOrderCommRateField myreq = CThostFtdcQryInstrumentOrderCommRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    int i = api->ReqQryInstrumentOrderCommRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySecAgentTradingAccount(const py::dict &req, int reqid)
{
    CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getChar(req, "BizType", &myreq.BizType);
    getString(req, "AccountID", myreq.AccountID);
    int i = api->ReqQrySecAgentTradingAccount(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySecAgentCheckMode(const py::dict &req, int reqid)
{
    CThostFtdcQrySecAgentCheckModeField myreq = CThostFtdcQrySecAgentCheckModeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    int i = api->ReqQrySecAgentCheckMode(&myreq, reqid);
    return i;
};

int PyTdApi::reqQrySecAgentTradeInfo(const py::dict &req, int reqid)
{
    CThostFtdcQrySecAgentTradeInfoField myreq = CThostFtdcQrySecAgentTradeInfoField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "BrokerSecAgentID", myreq.BrokerSecAgentID);
    int i = api->ReqQrySecAgentTradeInfo(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryOptionInstrTradeCost(const py::dict &req, int reqid)
{
    CThostFtdcQryOptionInstrTradeCostField myreq = CThostFtdcQryOptionInstrTradeCostField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getChar(req, "HedgeFlag", &myreq.HedgeFlag);
    getDouble(req, "InputPrice", &myreq.InputPrice);
    getDouble(req, "UnderlyingPrice", &myreq.UnderlyingPrice);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryOptionInstrTradeCost(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryOptionInstrCommRate(const py::dict &req, int reqid)
{
    CThostFtdcQryOptionInstrCommRateField myreq = CThostFtdcQryOptionInstrCommRateField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryOptionInstrCommRate(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryExecOrder(const py::dict &req, int reqid)
{
    CThostFtdcQryExecOrderField myreq = CThostFtdcQryExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
    getString(req, "InsertTimeStart", myreq.InsertTimeStart);
    getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
    int i = api->ReqQryExecOrder(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryForQuote(const py::dict &req, int reqid)
{
    CThostFtdcQryForQuoteField myreq = CThostFtdcQryForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InsertTimeStart", myreq.InsertTimeStart);
    getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryForQuote(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryQuote(const py::dict &req, int reqid)
{
    CThostFtdcQryQuoteField myreq = CThostFtdcQryQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "QuoteSysID", myreq.QuoteSysID);
    getString(req, "InsertTimeStart", myreq.InsertTimeStart);
    getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryQuote(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryOptionSelfClose(const py::dict &req, int reqid)
{
    CThostFtdcQryOptionSelfCloseField myreq = CThostFtdcQryOptionSelfCloseField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
    getString(req, "InsertTimeStart", myreq.InsertTimeStart);
    getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
    int i = api->ReqQryOptionSelfClose(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryInvestUnit(const py::dict &req, int reqid)
{
    CThostFtdcQryInvestUnitField myreq = CThostFtdcQryInvestUnitField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryInvestUnit(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryCombInstrumentGuard(const py::dict &req, int reqid)
{
    CThostFtdcQryCombInstrumentGuardField myreq = CThostFtdcQryCombInstrumentGuardField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    int i = api->ReqQryCombInstrumentGuard(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryCombAction(const py::dict &req, int reqid)
{
    CThostFtdcQryCombActionField myreq = CThostFtdcQryCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryCombAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTransferSerial(const py::dict &req, int reqid)
{
    CThostFtdcQryTransferSerialField myreq = CThostFtdcQryTransferSerialField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "BankID", myreq.BankID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqQryTransferSerial(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryAccountregister(const py::dict &req, int reqid)
{
    CThostFtdcQryAccountregisterField myreq = CThostFtdcQryAccountregisterField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBranchID", myreq.BankBranchID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    int i = api->ReqQryAccountregister(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryContractBank(const py::dict &req, int reqid)
{
    CThostFtdcQryContractBankField myreq = CThostFtdcQryContractBankField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBrchID", myreq.BankBrchID);
    int i = api->ReqQryContractBank(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryParkedOrder(const py::dict &req, int reqid)
{
    CThostFtdcQryParkedOrderField myreq = CThostFtdcQryParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryParkedOrder(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryParkedOrderAction(const py::dict &req, int reqid)
{
    CThostFtdcQryParkedOrderActionField myreq = CThostFtdcQryParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryParkedOrderAction(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryTradingNotice(const py::dict &req, int reqid)
{
    CThostFtdcQryTradingNoticeField myreq = CThostFtdcQryTradingNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQryTradingNotice(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryBrokerTradingParams(const py::dict &req, int reqid)
{
    CThostFtdcQryBrokerTradingParamsField myreq = CThostFtdcQryBrokerTradingParamsField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "AccountID", myreq.AccountID);
    int i = api->ReqQryBrokerTradingParams(&myreq, reqid);
    return i;
};

int PyTdApi::reqQryBrokerTradingAlgos(const py::dict &req, int reqid)
{
    CThostFtdcQryBrokerTradingAlgosField myreq = CThostFtdcQryBrokerTradingAlgosField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "ExchangeID", myreq.ExchangeID);
    getString(req, "InstrumentID", myreq.InstrumentID);
    int i = api->ReqQryBrokerTradingAlgos(&myreq, reqid);
    return i;
};

int PyTdApi::reqQueryCFMMCTradingAccountToken(const py::dict &req, int reqid)
{
    CThostFtdcQueryCFMMCTradingAccountTokenField myreq = CThostFtdcQueryCFMMCTradingAccountTokenField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "InvestorID", myreq.InvestorID);
    getString(req, "InvestUnitID", myreq.InvestUnitID);
    int i = api->ReqQueryCFMMCTradingAccountToken(&myreq, reqid);
    return i;
};

int PyTdApi::reqFromBankToFutureByFuture(const py::dict &req, int reqid)
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradeCode", myreq.TradeCode);
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBranchID", myreq.BankBranchID);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "BrokerBranchID", myreq.BrokerBranchID);
    getString(req, "TradeDate", myreq.TradeDate);
    getString(req, "TradeTime", myreq.TradeTime);
    getString(req, "BankSerial", myreq.BankSerial);
    getString(req, "TradingDay", myreq.TradingDay);
    getInt(req, "PlateSerial", &myreq.PlateSerial);
    getChar(req, "LastFragment", &myreq.LastFragment);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "CustomerName", myreq.CustomerName);
    getChar(req, "IdCardType", &myreq.IdCardType);
    getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
    getChar(req, "CustType", &myreq.CustType);
    getString(req, "BankAccount", myreq.BankAccount);
    getString(req, "BankPassWord", myreq.BankPassWord);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "Password", myreq.Password);
    getInt(req, "InstallID", &myreq.InstallID);
    getInt(req, "FutureSerial", &myreq.FutureSerial);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getDouble(req, "TradeAmount", &myreq.TradeAmount);
    getDouble(req, "FutureFetchAmount", &myreq.FutureFetchAmount);
    getChar(req, "FeePayFlag", &myreq.FeePayFlag);
    getDouble(req, "CustFee", &myreq.CustFee);
    getDouble(req, "BrokerFee", &myreq.BrokerFee);
    getString(req, "Message", myreq.Message);
    getString(req, "Digest", myreq.Digest);
    getChar(req, "BankAccType", &myreq.BankAccType);
    getString(req, "DeviceID", myreq.DeviceID);
    getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
    getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
    getString(req, "BankSecuAcc", myreq.BankSecuAcc);
    getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
    getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
    getString(req, "OperNo", myreq.OperNo);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "TID", &myreq.TID);
    getChar(req, "TransferStatus", &myreq.TransferStatus);
    getString(req, "LongCustomerName", myreq.LongCustomerName);
    int i = api->ReqFromBankToFutureByFuture(&myreq, reqid);
    return i;
};

int PyTdApi::reqFromFutureToBankByFuture(const py::dict &req, int reqid)
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradeCode", myreq.TradeCode);
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBranchID", myreq.BankBranchID);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "BrokerBranchID", myreq.BrokerBranchID);
    getString(req, "TradeDate", myreq.TradeDate);
    getString(req, "TradeTime", myreq.TradeTime);
    getString(req, "BankSerial", myreq.BankSerial);
    getString(req, "TradingDay", myreq.TradingDay);
    getInt(req, "PlateSerial", &myreq.PlateSerial);
    getChar(req, "LastFragment", &myreq.LastFragment);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "CustomerName", myreq.CustomerName);
    getChar(req, "IdCardType", &myreq.IdCardType);
    getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
    getChar(req, "CustType", &myreq.CustType);
    getString(req, "BankAccount", myreq.BankAccount);
    getString(req, "BankPassWord", myreq.BankPassWord);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "Password", myreq.Password);
    getInt(req, "InstallID", &myreq.InstallID);
    getInt(req, "FutureSerial", &myreq.FutureSerial);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getDouble(req, "TradeAmount", &myreq.TradeAmount);
    getDouble(req, "FutureFetchAmount", &myreq.FutureFetchAmount);
    getChar(req, "FeePayFlag", &myreq.FeePayFlag);
    getDouble(req, "CustFee", &myreq.CustFee);
    getDouble(req, "BrokerFee", &myreq.BrokerFee);
    getString(req, "Message", myreq.Message);
    getString(req, "Digest", myreq.Digest);
    getChar(req, "BankAccType", &myreq.BankAccType);
    getString(req, "DeviceID", myreq.DeviceID);
    getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
    getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
    getString(req, "BankSecuAcc", myreq.BankSecuAcc);
    getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
    getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
    getString(req, "OperNo", myreq.OperNo);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "TID", &myreq.TID);
    getChar(req, "TransferStatus", &myreq.TransferStatus);
    getString(req, "LongCustomerName", myreq.LongCustomerName);
    int i = api->ReqFromFutureToBankByFuture(&myreq, reqid);
    return i;
};

int PyTdApi::reqQueryBankAccountMoneyByFuture(const py::dict &req, int reqid)
{
    CThostFtdcReqQueryAccountField myreq = CThostFtdcReqQueryAccountField();
    memset(&myreq, 0, sizeof(myreq));
    getString(req, "TradeCode", myreq.TradeCode);
    getString(req, "BankID", myreq.BankID);
    getString(req, "BankBranchID", myreq.BankBranchID);
    getString(req, "BrokerID", myreq.BrokerID);
    getString(req, "BrokerBranchID", myreq.BrokerBranchID);
    getString(req, "TradeDate", myreq.TradeDate);
    getString(req, "TradeTime", myreq.TradeTime);
    getString(req, "BankSerial", myreq.BankSerial);
    getString(req, "TradingDay", myreq.TradingDay);
    getInt(req, "PlateSerial", &myreq.PlateSerial);
    getChar(req, "LastFragment", &myreq.LastFragment);
    getInt(req, "SessionID", &myreq.SessionID);
    getString(req, "CustomerName", myreq.CustomerName);
    getChar(req, "IdCardType", &myreq.IdCardType);
    getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
    getChar(req, "CustType", &myreq.CustType);
    getString(req, "BankAccount", myreq.BankAccount);
    getString(req, "BankPassWord", myreq.BankPassWord);
    getString(req, "AccountID", myreq.AccountID);
    getString(req, "Password", myreq.Password);
    getInt(req, "FutureSerial", &myreq.FutureSerial);
    getInt(req, "InstallID", &myreq.InstallID);
    getString(req, "UserID", myreq.UserID);
    getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
    getString(req, "CurrencyID", myreq.CurrencyID);
    getString(req, "Digest", myreq.Digest);
    getChar(req, "BankAccType", &myreq.BankAccType);
    getString(req, "DeviceID", myreq.DeviceID);
    getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
    getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
    getString(req, "BankSecuAcc", myreq.BankSecuAcc);
    getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
    getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
    getString(req, "OperNo", myreq.OperNo);
    getInt(req, "RequestID", &myreq.RequestID);
    getInt(req, "TID", &myreq.TID);
    getString(req, "LongCustomerName", myreq.LongCustomerName);
    int i = api->ReqQueryBankAccountMoneyByFuture(&myreq, reqid);
    return i;
};


//-------------------------------------------------------------------------------------
