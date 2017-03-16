/**


**/

#include "Channel.h"
#include "SelectReactor.h"
#include "Handler.h"
#include "Channel.h"
#include "Server.h"

class CSessionBase:public CSelectReactor, public CHandler
{
	
public:
	CSessionBase(CSelectReactor* selecter,const char* location );
	virtual ~CSessionBase();

	virtual void GetIds( int* readid,int* writeid );

	virtual void HandleInput();

	virtual void HandleOupt();

	virtual int HandleEvent( int event,DWORD dwParam,void* pParam );

	virtual void SyncRun();

private:
	CServer* m_server;
	CChannel* m_channel;
	CSelectReactor* m_serverreactor;
};