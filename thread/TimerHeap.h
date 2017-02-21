#ifndef  TIMERHEAP_H
#define  TIMERHEAP_H
#include "TimerQueue.h"
#include <queue>
#include <map>
using namespace  std;

class CTimerHeapNode
{
public:
	CHandler* handler;
	DWORD event;
	int elapse;
	DWORD expire;
};

class CNodeCom
{
public:
	bool operator ()(const CTimerHeapNode& node1, const CTimerHeapNode& node2)
	{
		return node1.expire < node1.expire;
	}
};
bool NodeCom(const CTimerHeapNode &node1, const  CTimerHeapNode& node2) 
{
	if(node1.expire < node2.expire)
		return true;
	else
		return false;
}

//typedef bool (*Com)(const CTimerHeapNode& node1, const CTimerHeapNode& node2);
//����ֻ�ܴ���һ������ָ�����ͣ���ʹ��ʱ���ܴ���һ������ĺ���ָ�롣
//����ֻ��ͨ�����ع��캯���������Ӧ�ĺ���ָ��
//���һ���õķ����Ǵ��뺯������
//class CTimerHeap:public CTimerQueue,public priority_queue<CTimerHeapNode,vector<CTimerHeapNode>,Com>
class CTimerHeap:public CTimerQueue,public priority_queue<CTimerHeapNode,vector<CTimerHeapNode>,CNodeCom>
{
public:

	virtual void RegisterTimer( CHandler* handler,DWORD event,DWORD elapse );

	virtual void RemoverTime( CHandler* handler,DWORD event );

	virtual void Expire( DWORD curclock );
	virtual ~CTimerHeap();
private:
	
};
#endif