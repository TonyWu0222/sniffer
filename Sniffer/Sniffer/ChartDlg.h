#pragma once
#include "teechart/TeeChartDefines.h"
//#include "teechart/axis.h"
//#include "teechart/axes.h"
//#include "teechart/scroll.h"
#include "teechart/series.h"
#include "teechart/tchart.h"
//#include "teechart/page.h"

#include "MyPcap.h"
#include "afxwin.h"

static CRITICAL_SECTION CapThreadCS;
// CChartDlg dialog
static UINT TrafficThread(LPVOID lpParameter);
static CString Chartfilter;//����ͳ���õ�filter
static int cDlg;//��ŵ�ǰ����ָ��
static long xtime;//����
class CChartDlg : public CDialog
{
	DECLARE_DYNAMIC(CChartDlg)

public:
	CChartDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CChartDlg();

// Dialog Data
	enum { IDD = IDD_CHART_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTChart m_chart;
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	WCHAR timestr[256];
	//�ص�����
	static void dispatcher_handler(u_char *state, const struct pcap_pkthdr *header, const u_char *pkt_data);
	HBRUSH hbrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnEnChangeChartEdit();
	CEdit m_ChartFilter;
	afx_msg void OnBnClickedChartbutton();
	CWinThread *hTrafficThread;
	BOOL HasThread;//�Ƿ�����߳���ͳ�Ƶı�־

	afx_msg void OnClose();
	int m_Radio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int chartnum;//ͳ��ֵΪ������������ı�־
};
