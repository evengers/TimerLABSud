// 
// 
// 
#include "Energia.h"
#include "TimerLABSud.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <inc/tm4c1294ncpdt.h>
#include <inc/hw_memmap.h>
#include <inc/hw_types.h>
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"


static const unsigned long timerBase[] =
{
	TIMER0_BASE, TIMER1_BASE
};

static const unsigned long timerCtrl[] =
{
	SYSCTL_PERIPH_TIMER0, SYSCTL_PERIPH_TIMER1
};

static const unsigned long timerList[] = 
{
	TIMER_A, TIMER_A
};

static const unsigned long timerTimeOut[] =
{
	TIMER_TIMA_TIMEOUT, TIMER_TIMA_TIMEOUT
};

static const unsigned long timerInt[] =
{
	INT_TIMER0A, INT_TIMER1A
};

static void(*func[2])(void);

static void (*intFunc[2])(void) =
{
	Timer0IntHandler, Timer1IntHandler
};

TimerLABSud::TimerLABSud()
{
	m_uiTimer = 0;

}

TimerLABSud::TimerLABSud(uint8_t timer)
{
	m_uiTimer = timer;
}

void TimerLABSud::set(uint32_t periode, void(*f)(void))
{
	//unsigned long ulPeriod = (SysCtlClockGet() / 1000); //En ms
	unsigned long ulPeriod = 120000;
	ulPeriod = ulPeriod * periode;
	SysCtlPeripheralEnable(timerCtrl[m_uiTimer]);


	TimerIntRegister(timerBase[m_uiTimer], timerList[m_uiTimer], intFunc[m_uiTimer]);
	TimerConfigure(timerBase[m_uiTimer], TIMER_CFG_PERIODIC);
	TimerLoadSet(timerBase[m_uiTimer], timerList[m_uiTimer], ulPeriod - 1);

	IntEnable(timerInt[m_uiTimer]);
	TimerIntEnable(timerBase[m_uiTimer], timerTimeOut[m_uiTimer]);
	IntMasterEnable();

	func[m_uiTimer] = f;
}

void TimerLABSud::start(void)
{
	TimerEnable(timerBase[m_uiTimer], timerList[m_uiTimer]);
}

void TimerLABSud::stop(void)
{
	TimerDisable(timerBase[m_uiTimer], timerList[m_uiTimer]);
}

void TimerLABSud::TimerIntHandler()
{
	TimerIntClear(timerBase[m_uiTimer], timerTimeOut[m_uiTimer]);
	if (func[m_uiTimer])
	{
		func[m_uiTimer]();
	}
}

void Timer0IntHandler(void)
{
	Timer0.TimerIntHandler();
}

void Timer1IntHandler(void)
{
	Timer1.TimerIntHandler();
}

TimerLABSud Timer0;
TimerLABSud Timer1(1);