#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"
#include "cmsis_os2.h"
#include "string.h"
#include "edt_bsp_uart.h"
#include <cstdio>
extern "C"
{

	extern osMessageQueueId_t uartQueueHandle;
	uartData_t *uartData_r;
}
#endif
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	//strncpy(RData, uartData_r->Data, uartData_r->size);
	//modelListener->updateUIWithReceivedData(RData);
//	if(osMessageQueueGetCount(uartQueueHandle) > 0){
//		if(osMessageQueueGet(uartQueueHandle, &uartData_r, 0, 0) == osOK){
//			strncpy(RData, uartData_r->Data, uartData_r->size);
//			modelListener->uart_Data(RData);
//		}
//	}
#endif
}

void Model::SendRS232(uint8_t value){
	#ifndef SIMULATOR
		char TX_Buffer[30];
		sprintf((char *) TX_Buffer, "Value = %d\n\r", (int) value);
		int n = (uint16_t) strlen(TX_Buffer);
		EDT_UART_Transmit_IT(&hRs232, (uint8_t *)TX_Buffer, n);
	#endif
}
