#ifndef PYCTPTD_H
#define PYCTPTD_H

#include "pybind11/pybind11.h"
#include "ThostFtdcTraderApi.h"
#include <string>
#include <iostream>

namespace py = pybind11;
///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class PyTdApi : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi* api;            //API对象
    bool active = false;                //工作状态

public:
    PyTdApi() = default;

    ~PyTdApi()
    {
        if (active)
        {
            exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API回调函数
    //-------------------------------------------------------------------------------------

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason);
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse);
	
	///客户端认证响应
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
	
	///登录请求响应
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///登出请求响应
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///用户口令更新请求响应
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///查询用户当前支持的认证模式的回复
	virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///获取图形验证码请求的回复
	virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///获取短信验证码请求的回复
	virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单录入请求响应
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///预埋单录入请求响应
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///预埋撤单录入请求响应
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单操作请求响应
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///查询最大报单数量响应
	virtual void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///投资者结算结果确认响应
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///删除预埋单响应
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///删除预埋撤单响应
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///执行宣告录入请求响应
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///执行宣告操作请求响应
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///询价录入请求响应
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价录入请求响应
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价操作请求响应
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///批量报单操作请求响应
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期权自对冲录入请求响应
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期权自对冲操作请求响应
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///申请组合录入请求响应
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询报单响应
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询成交响应
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓响应
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者响应
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易编码响应
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约保证金率响应
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约手续费率响应
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所响应
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询产品响应
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约响应
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者结算结果响应
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询转帐银行响应
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询客户通知响应
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询结算信息确认响应
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///查询保证金监管系统经纪公司资金账户密钥响应
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询仓单折抵信息响应
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者品种/跨品种保证金响应
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所保证金率响应
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所调整保证金率响应
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询汇率响应
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询二级代理操作员银期权限响应
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询产品报价汇率
	virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询产品组
	virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询做市商合约手续费率响应
	virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询做市商期权合约手续费响应
	virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询报单手续费响应
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询资金账户响应
	virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询二级代理商资金校验模式响应
	virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询二级代理商信息响应
	virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权交易成本响应
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权合约手续费响应
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询执行宣告响应
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询询价响应
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询报价响应
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权自对冲响应
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资单元响应
	virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询组合合约安全系数响应
	virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询申请组合响应
	virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询转帐流水响应
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询银期签约关系响应
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///错误应答
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单通知
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) ;

	///成交通知
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) ;

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) ;

	///交易所公告通知
	virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin) ;

	///交易通知
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) ;

	///提示条件单校验错误
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) ;

	///执行宣告通知
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) ;

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///询价录入错误回报
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///报价通知
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote) ;

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) ;

	///询价通知
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) ;

	///保证金监控中心用户令牌
	virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) ;

	///批量报单操作错误回报
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///期权自对冲通知
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose) ;

	///期权自对冲录入错误回报
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo) ;

	///期权自对冲操作错误回报
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo) ;

	///申请组合通知
	virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction) ;

	///申请组合录入错误回报
	virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) ;

	///请求查询签约银行响应
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询预埋单响应
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询预埋撤单响应
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易通知响应
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询经纪公司交易参数响应
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询经纪公司交易算法响应
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询监控中心用户令牌
	virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///银行发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) ;

	///银行发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) ;

	///银行发起冲正银行转期货通知
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) ;

	///银行发起冲正期货转银行通知
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) ;

	///期货发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) ;

	///期货发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) ;

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) ;

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) ;

	///期货发起查询银行余额通知
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) ;

	///期货发起银行资金转期货错误回报
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;

	///期货发起期货资金转银行错误回报
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;

	///系统运行时期货端手工发起冲正银行转期货错误回报
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;

	///系统运行时期货端手工发起冲正期货转银行错误回报
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;

	///期货发起查询银行余额错误回报
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) ;

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) ;

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) ;

	///期货发起银行资金转期货应答
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期货发起期货资金转银行应答
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期货发起查询银行余额应答
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///银行发起银期开户通知
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) ;

	///银行发起银期销户通知
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) ;

	///银行发起变更银行账号通知
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) ;

	///请求查询分类合约响应
	virtual void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求组合优惠比例响应
	virtual void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *pCombPromotionParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

    //-------------------------------------------------------------------------------------
	//python重载函数
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------

    virtual void OnRspAuthenticate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspUserLogin(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspUserLogout(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspUserPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspTradingAccountPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspUserAuthMethod(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspGenUserCaptcha(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspGenUserText(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspParkedOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryMaxOrderVolume(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspSettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspRemoveParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspRemoveParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspExecOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspExecOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspForQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQuoteAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspBatchOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspOptionSelfCloseInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspOptionSelfCloseAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspCombActionInsert(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryOrder(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTrade(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestorPosition(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestor(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTradingCode(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInstrumentMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryExchange(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryProduct(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryDepthMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySettlementInfo(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTransferBank(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestorPositionDetail(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryNotice(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestorPositionCombineDetail(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryCFMMCTradingAccountKey(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryEWarrantOffset(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestorProductGroupMargin(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryExchangeMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryExchangeMarginRateAdjust(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryExchangeRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySecAgentACIDMap(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryProductExchRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryProductGroup(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryMMInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryMMOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInstrumentOrderCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySecAgentTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySecAgentCheckMode(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQrySecAgentTradeInfo(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryOptionInstrTradeCost(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryExecOrder(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryForQuote(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryQuote(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryOptionSelfClose(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryInvestUnit(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryCombInstrumentGuard(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryCombAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTransferSerial(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryAccountregister(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspError(const py::dict &error, int reqid, bool last) ;

    virtual void OnRtnOrder(const py::dict &data) ;

    virtual void OnRtnTrade(const py::dict &data) ;

    virtual void OnErrRtnOrderInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnOrderAction(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnInstrumentStatus(const py::dict &data) ;

    virtual void OnRtnBulletin(const py::dict &data) ;

    virtual void OnRtnTradingNotice(const py::dict &data) ;

    virtual void OnRtnErrorConditionalOrder(const py::dict &data) ;

    virtual void OnRtnExecOrder(const py::dict &data) ;

    virtual void OnErrRtnExecOrderInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnExecOrderAction(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnForQuoteInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnQuote(const py::dict &data) ;

    virtual void OnErrRtnQuoteInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnQuoteAction(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnForQuoteRsp(const py::dict &data) ;

    virtual void OnRtnCFMMCTradingAccountToken(const py::dict &data) ;

    virtual void OnErrRtnBatchOrderAction(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnOptionSelfClose(const py::dict &data) ;

    virtual void OnErrRtnOptionSelfCloseInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnOptionSelfCloseAction(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnCombAction(const py::dict &data) ;

    virtual void OnErrRtnCombActionInsert(const py::dict &data, const py::dict &error) ;

    virtual void OnRspQryContractBank(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryTradingNotice(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryBrokerTradingParams(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQryBrokerTradingAlgos(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQueryCFMMCTradingAccountToken(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRtnFromBankToFutureByBank(const py::dict &data) ;

    virtual void OnRtnFromFutureToBankByBank(const py::dict &data) ;

    virtual void OnRtnRepealFromBankToFutureByBank(const py::dict &data) ;

    virtual void OnRtnRepealFromFutureToBankByBank(const py::dict &data) ;

    virtual void OnRtnFromBankToFutureByFuture(const py::dict &data) ;

    virtual void OnRtnFromFutureToBankByFuture(const py::dict &data) ;

    virtual void OnRtnRepealFromBankToFutureByFutureManual(const py::dict &data) ;

    virtual void OnRtnRepealFromFutureToBankByFutureManual(const py::dict &data) ;

    virtual void OnRtnQueryBankBalanceByFuture(const py::dict &data) ;

    virtual void OnErrRtnBankToFutureByFuture(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnFutureToBankByFuture(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnRepealBankToFutureByFutureManual(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnRepealFutureToBankByFutureManual(const py::dict &data, const py::dict &error) ;

    virtual void OnErrRtnQueryBankBalanceByFuture(const py::dict &data, const py::dict &error) ;

    virtual void OnRtnRepealFromBankToFutureByFuture(const py::dict &data) ;

    virtual void OnRtnRepealFromFutureToBankByFuture(const py::dict &data) ;

    virtual void OnRspFromBankToFutureByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspFromFutureToBankByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRspQueryBankAccountMoneyByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    virtual void OnRtnOpenAccountByBank(const py::dict &data) ;

    virtual void OnRtnCancelAccountByBank(const py::dict &data) ;

    virtual void OnRtnChangeAccountByBank(const py::dict &data) ;

	virtual void OnRspQryClassifiedInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) ;

	virtual void OnRspQryCombPromotionParam(const py::dict &data, const py::dict &error, int reqid, bool last) ;

    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------

    void createFtdcTraderApi(std::string pszFlowPath = "");

    void release();

    void init();

    int join();

    void exit();

    std::string GetApiVersion();

    std::string getTradingDay();

    void registerFront(std::string pszFrontAddress);

    void subscribePrivateTopic(int nType);

    void subscribePublicTopic(int nType);

    int reqAuthenticate(const py::dict &req, int reqid);

    int reqUserLogin(const py::dict &req, int reqid);

    int reqUserLogout(const py::dict &req, int reqid);

    int reqUserPasswordUpdate(const py::dict &req, int reqid);

    int reqTradingAccountPasswordUpdate(const py::dict &req, int reqid);

    int reqUserAuthMethod(const py::dict &req, int reqid);

    int reqGenUserCaptcha(const py::dict &req, int reqid);

    int reqGenUserText(const py::dict &req, int reqid);

    int reqUserLoginWithCaptcha(const py::dict &req, int reqid);

    int reqUserLoginWithText(const py::dict &req, int reqid);

    int reqUserLoginWithOTP(const py::dict &req, int reqid);

    int reqOrderInsert(const py::dict &req, int reqid);

    int reqParkedOrderInsert(const py::dict &req, int reqid);

    int reqParkedOrderAction(const py::dict &req, int reqid);

    int reqOrderAction(const py::dict &req, int reqid);

    int reqQryMaxOrderVolume(const py::dict &req, int reqid);

    int reqSettlementInfoConfirm(const py::dict &req, int reqid);

    int reqRemoveParkedOrder(const py::dict &req, int reqid);

    int reqRemoveParkedOrderAction(const py::dict &req, int reqid);

    int reqExecOrderInsert(const py::dict &req, int reqid);

    int reqExecOrderAction(const py::dict &req, int reqid);

    int reqForQuoteInsert(const py::dict &req, int reqid);

    int reqQuoteInsert(const py::dict &req, int reqid);

    int reqQuoteAction(const py::dict &req, int reqid);

    int reqBatchOrderAction(const py::dict &req, int reqid);

    int reqOptionSelfCloseInsert(const py::dict &req, int reqid);

    int reqOptionSelfCloseAction(const py::dict &req, int reqid);

    int reqCombActionInsert(const py::dict &req, int reqid);

    int reqQryOrder(const py::dict &req, int reqid);

    int reqQryTrade(const py::dict &req, int reqid);

    int reqQryInvestorPosition(const py::dict &req, int reqid);

    int reqQryTradingAccount(const py::dict &req, int reqid);

    int reqQryInvestor(const py::dict &req, int reqid);

    int reqQryTradingCode(const py::dict &req, int reqid);

    int reqQryInstrumentMarginRate(const py::dict &req, int reqid);

    int reqQryInstrumentCommissionRate(const py::dict &req, int reqid);

    int reqQryExchange(const py::dict &req, int reqid);

    int reqQryProduct(const py::dict &req, int reqid);

    int reqQryInstrument(const py::dict &req, int reqid);

    int reqQryDepthMarketData(const py::dict &req, int reqid);

    int reqQrySettlementInfo(const py::dict &req, int reqid);

    int reqQryTransferBank(const py::dict &req, int reqid);

    int reqQryInvestorPositionDetail(const py::dict &req, int reqid);

    int reqQryNotice(const py::dict &req, int reqid);

    int reqQrySettlementInfoConfirm(const py::dict &req, int reqid);

    int reqQryInvestorPositionCombineDetail(const py::dict &req, int reqid);

    int reqQryCFMMCTradingAccountKey(const py::dict &req, int reqid);

    int reqQryEWarrantOffset(const py::dict &req, int reqid);

    int reqQryInvestorProductGroupMargin(const py::dict &req, int reqid);

    int reqQryExchangeMarginRate(const py::dict &req, int reqid);

    int reqQryExchangeMarginRateAdjust(const py::dict &req, int reqid);

    int reqQryExchangeRate(const py::dict &req, int reqid);

    int reqQrySecAgentACIDMap(const py::dict &req, int reqid);

    int reqQryProductExchRate(const py::dict &req, int reqid);

    int reqQryProductGroup(const py::dict &req, int reqid);

    int reqQryMMInstrumentCommissionRate(const py::dict &req, int reqid);

    int reqQryMMOptionInstrCommRate(const py::dict &req, int reqid);

    int reqQryInstrumentOrderCommRate(const py::dict &req, int reqid);

    int reqQrySecAgentTradingAccount(const py::dict &req, int reqid);

    int reqQrySecAgentCheckMode(const py::dict &req, int reqid);

    int reqQrySecAgentTradeInfo(const py::dict &req, int reqid);

    int reqQryOptionInstrTradeCost(const py::dict &req, int reqid);

    int reqQryOptionInstrCommRate(const py::dict &req, int reqid);

    int reqQryExecOrder(const py::dict &req, int reqid);

    int reqQryForQuote(const py::dict &req, int reqid);

    int reqQryQuote(const py::dict &req, int reqid);

    int reqQryOptionSelfClose(const py::dict &req, int reqid);

    int reqQryInvestUnit(const py::dict &req, int reqid);

    int reqQryCombInstrumentGuard(const py::dict &req, int reqid);

    int reqQryCombAction(const py::dict &req, int reqid);

    int reqQryTransferSerial(const py::dict &req, int reqid);

    int reqQryAccountregister(const py::dict &req, int reqid);

    int reqQryContractBank(const py::dict &req, int reqid);

    int reqQryParkedOrder(const py::dict &req, int reqid);

    int reqQryParkedOrderAction(const py::dict &req, int reqid);

    int reqQryTradingNotice(const py::dict &req, int reqid);

    int reqQryBrokerTradingParams(const py::dict &req, int reqid);

    int reqQryBrokerTradingAlgos(const py::dict &req, int reqid);

    int reqQueryCFMMCTradingAccountToken(const py::dict &req, int reqid);

    int reqFromBankToFutureByFuture(const py::dict &req, int reqid);

    int reqFromFutureToBankByFuture(const py::dict &req, int reqid);

    int reqQueryBankAccountMoneyByFuture(const py::dict &req, int reqid);
};


class PyTdWrapper : public PyTdApi
{

public:
    void OnFrontConnected() override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnFrontConnected);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnFrontDisconnected(int nReason) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnFrontDisconnected, nReason);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnHeartBeatWarning(int nTimeLapse) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnHeartBeatWarning, nTimeLapse);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspAuthenticate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspAuthenticate, data, error, reqid, last);
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
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspUserLogin, data, error, reqid, last);
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
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspUserLogout, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUserPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspUserPasswordUpdate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspTradingAccountPasswordUpdate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspTradingAccountPasswordUpdate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspUserAuthMethod(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspUserAuthMethod, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspGenUserCaptcha(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspGenUserCaptcha, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspGenUserText(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspGenUserText, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspOrderInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspParkedOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspParkedOrderInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspParkedOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryMaxOrderVolume(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryMaxOrderVolume, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspSettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspSettlementInfoConfirm, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspRemoveParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspRemoveParkedOrder, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspRemoveParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspRemoveParkedOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspExecOrderInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspExecOrderInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspExecOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspExecOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspForQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspForQuoteInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQuoteInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQuoteInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQuoteAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQuoteAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspBatchOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspBatchOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspOptionSelfCloseInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspOptionSelfCloseInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspOptionSelfCloseAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspOptionSelfCloseAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspCombActionInsert(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspCombActionInsert, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryOrder(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryOrder, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTrade(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTrade, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestorPosition(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestorPosition, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTradingAccount, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestor(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestor, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTradingCode(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTradingCode, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInstrumentMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInstrumentMarginRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInstrumentCommissionRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryExchange(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryExchange, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryProduct(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryProduct, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInstrument, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryDepthMarketData(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryDepthMarketData, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySettlementInfo(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySettlementInfo, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTransferBank(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTransferBank, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestorPositionDetail(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestorPositionDetail, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryNotice(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryNotice, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySettlementInfoConfirm(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySettlementInfoConfirm, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestorPositionCombineDetail(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestorPositionCombineDetail, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryCFMMCTradingAccountKey(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryCFMMCTradingAccountKey, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryEWarrantOffset(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryEWarrantOffset, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestorProductGroupMargin(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestorProductGroupMargin, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryExchangeMarginRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryExchangeMarginRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryExchangeMarginRateAdjust(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryExchangeMarginRateAdjust, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryExchangeRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryExchangeRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySecAgentACIDMap(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySecAgentACIDMap, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryProductExchRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryProductExchRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryProductGroup(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryProductGroup, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryMMInstrumentCommissionRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryMMInstrumentCommissionRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryMMOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryMMOptionInstrCommRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInstrumentOrderCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInstrumentOrderCommRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySecAgentTradingAccount(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySecAgentTradingAccount, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySecAgentCheckMode(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySecAgentCheckMode, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQrySecAgentTradeInfo(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQrySecAgentTradeInfo, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryOptionInstrTradeCost(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryOptionInstrTradeCost, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryOptionInstrCommRate(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryOptionInstrCommRate, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryExecOrder(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryExecOrder, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryForQuote(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryForQuote, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryQuote(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryQuote, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryOptionSelfClose(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryOptionSelfClose, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryInvestUnit(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryInvestUnit, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryCombInstrumentGuard(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryCombInstrumentGuard, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryCombAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryCombAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTransferSerial(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTransferSerial, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryAccountregister(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryAccountregister, data, error, reqid, last);
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
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspError, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnOrder(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnOrder, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnTrade(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnTrade, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnOrderInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnOrderInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnOrderAction(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnOrderAction, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnInstrumentStatus(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnInstrumentStatus, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnBulletin(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnBulletin, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnTradingNotice(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnTradingNotice, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnErrorConditionalOrder(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnErrorConditionalOrder, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnExecOrder(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnExecOrder, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnExecOrderInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnExecOrderInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnExecOrderAction(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnExecOrderAction, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnForQuoteInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnForQuoteInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnQuote(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnQuote, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnQuoteInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnQuoteInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnQuoteAction(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnQuoteAction, data, error);
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
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnForQuoteRsp, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnCFMMCTradingAccountToken(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnCFMMCTradingAccountToken, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnBatchOrderAction(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnBatchOrderAction, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnOptionSelfClose(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnOptionSelfClose, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnOptionSelfCloseInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnOptionSelfCloseInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnOptionSelfCloseAction(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnOptionSelfCloseAction, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnCombAction(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnCombAction, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnCombActionInsert(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnCombActionInsert, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryContractBank(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryContractBank, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryParkedOrder(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryParkedOrder, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryParkedOrderAction(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryParkedOrderAction, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryTradingNotice(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryTradingNotice, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryBrokerTradingParams(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryBrokerTradingParams, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQryBrokerTradingAlgos(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryBrokerTradingAlgos, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQueryCFMMCTradingAccountToken(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQueryCFMMCTradingAccountToken, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnFromBankToFutureByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnFromBankToFutureByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnFromFutureToBankByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnFromFutureToBankByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromBankToFutureByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromBankToFutureByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromFutureToBankByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromFutureToBankByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnFromBankToFutureByFuture(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnFromBankToFutureByFuture, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnFromFutureToBankByFuture(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnFromFutureToBankByFuture, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromBankToFutureByFutureManual(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromBankToFutureByFutureManual, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromFutureToBankByFutureManual(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromFutureToBankByFutureManual, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnQueryBankBalanceByFuture(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnQueryBankBalanceByFuture, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnBankToFutureByFuture(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnBankToFutureByFuture, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnFutureToBankByFuture(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnFutureToBankByFuture, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnRepealBankToFutureByFutureManual(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnRepealBankToFutureByFutureManual, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnRepealFutureToBankByFutureManual(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnRepealFutureToBankByFutureManual, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnErrRtnQueryBankBalanceByFuture(const py::dict &data, const py::dict &error) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnErrRtnQueryBankBalanceByFuture, data, error);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromBankToFutureByFuture(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromBankToFutureByFuture, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnRepealFromFutureToBankByFuture(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnRepealFromFutureToBankByFuture, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspFromBankToFutureByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspFromBankToFutureByFuture, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspFromFutureToBankByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspFromFutureToBankByFuture, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRspQueryBankAccountMoneyByFuture(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQueryBankAccountMoneyByFuture, data, error, reqid, last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnOpenAccountByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnOpenAccountByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnCancelAccountByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnCancelAccountByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    void OnRtnChangeAccountByBank(const py::dict &data) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRtnChangeAccountByBank, data);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

	void OnRspQryClassifiedInstrument(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryClassifiedInstrument, data,error,reqid,last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

	void OnRspQryCombPromotionParam(const py::dict &data, const py::dict &error, int reqid, bool last) override
    {
        try
        {
            PYBIND11_OVERLOAD(void, PyTdApi, OnRspQryClassifiedInstrument, data,error,reqid,last);
        }
        catch (const py::error_already_set &e)
        {
            std::cout << e.what() << std::endl;
        }
    };

};
#endif