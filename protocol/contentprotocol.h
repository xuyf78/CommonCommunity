/************************************************************************/
/* 
����һ������package��protocol 
�˳ɻ�ά����Ӧ��contentpackage.ͬ�ṩ���ϲ�Ӧ�ò�Ľӿ�;
��Ҫ���ϲ�Э��XXXXProtocol����Protocol.Send()д�뵽CContentProtocol�㡣
CContentProtocol.Push()��д�뵽CChannelProtocol
���л��棬����ֱ�ӷ��͡�

��contentprotocol��send��push������

*/
/************************************************************************/

#ifndef CONTENTPROTOCOL_H 
#define CONTENTPROTOCOL_H

#include "Protocol.h"


class CContentProtocol:public CProtocol
{
public:
	CContentProtocol(CSelectReactor* reactor);
	virtual ~CContentProtocol();

	virtual int Pop( CPackage* package );

	virtual int OnRecvErrPackage( CPackage* package );

	//��channelprotocol����packageʱ������content���ͷ����
	virtual int Push( CPackage* package,CProtocol* protocol );

	virtual void OnTimer( int event );
	
	//����timeout���Է�����������
	void send_timeout(int timeout);

	//�����յ���CContentPackage���ö�Ӧ��������ʱʱ��
	void set_timeout(CPackage* package);

private:
	int m_timeOut;

};


#endif