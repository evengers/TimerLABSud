// TimerLABSud.h

#ifndef _TIMERTEST_h
#define _TIMERTEST_h

#include <inttypes.h>


class TimerLABSud
{
public:
	TimerLABSud();
	TimerLABSud(uint8_t timer);
	void set( uint32_t periode, void(*f)(void));
	void start(void);
	void stop(void);
	void TimerIntHandler(void);
private:
	uint8_t m_uiTimer;

};

extern TimerLABSud Timer0;
extern TimerLABSud Timer1;

void Timer0IntHandler(void);
void Timer1IntHandler(void);

#endif

