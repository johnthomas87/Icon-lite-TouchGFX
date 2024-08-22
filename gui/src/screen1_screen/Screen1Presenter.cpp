#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

//void Screen1Presenter::updateUIWithReceivedData(char* data)
//{
//    // Convert data to a string or appropriate format
//	//char text[100];
//	    //snprintf(text, sizeof(text), "%s", data);
//	    //view.updateTextArea(text);
//}

//void Screen1Presenter::uart_Data(char *data){
//	view.uart_Data(data);
//}

void Screen1Presenter::RS232ValueChanged(uint8_t value){
	#ifndef SIMULATOR
		model->SendRS232(value);
	#endif
}

void Screen1Presenter::RS232ValueReceived(){
	#ifndef SIMULATOR
		//view->RS232ValueReceived();
	#endif
}
