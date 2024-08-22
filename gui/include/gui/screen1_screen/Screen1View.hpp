#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <string>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //custom functions for keypad
    virtual void keyOneClicked();
    virtual void keyTwoClicked();
    virtual void keyThreeClicked();
    virtual void keyFourClicked();
    virtual void keyFiveClicked();
    virtual void keySixClicked();
    virtual void keySevenClicked();
    virtual void keyEightClicked();
    virtual void keyNineClicked();
    virtual void keyZeroClicked();
    virtual void keyDoneClicked();
    virtual void keyDeleteClicked();
    virtual void waterToggleClicked();
    virtual void percentClicked();
    virtual void depthOnClicked();
    virtual void percentOnClicked();

    //void updateTextArea(char* text);
    virtual void uart_Data(char *data);
    void RS232ValueReceived();


    void convertFloatToString(float value, Unicode::UnicodeChar* buffer, uint16_t bufferSize);

    void isValidInput();
    void deleteInput();
    void calculateAndRender();

    std::string valueEntered = "0.00";//User entry from keypad
    std::string result = "";//store final result
    //std::string decimalString = "%#3.2f";
    int decimal = 2; // Number of decimal places
    int runStatus = 0;//0 - STOP, 1 - RUN Forward, 2 - Run Reverse
    int keypadMode = 1;//1 - water OFF - percent, 2 - water ON - percent, 3 - Water ON - depth

    std::string unicodeToStdString(const Unicode::UnicodeChar* unicodeStr);
    static std::string removeChar(const std::string str, char charToRemove);
    static std::string removeLeadingZeros(const std::string str);

    static const int BUFFER_SIZE = 20;
    Unicode::UnicodeChar buffer[BUFFER_SIZE];
protected:
};

#endif // SCREEN1VIEW_HPP
