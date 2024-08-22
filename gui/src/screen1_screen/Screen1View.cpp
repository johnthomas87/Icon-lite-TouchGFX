#include <gui/screen1_screen/Screen1View.hpp>
#include <string>
#include <algorithm> // For std::remove
#include <iostream>
#include <touchgfx/Color.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/Types.hpp>
#include <touchgfx/hal/HAL.hpp>

Screen1View::Screen1View()
{
    
}

// // Helper function to remove characters from a string
std::string Screen1View::removeChar(std::string str, char charToRemove) {
    str.erase(std::remove(str.begin(), str.end(), charToRemove), str.end());
    return str;
}

// // Helper function to remove leading zeros
std::string Screen1View::removeLeadingZeros(std::string str) {
    size_t nonZeroPos = str.find_first_not_of('0');
    if (nonZeroPos != std::string::npos) {
        return str.substr(nonZeroPos);
    }
    return "0"; // In case all characters are zeros
}

//void Screen1View::updateTextArea(char* text)
//{
//    Unicode::strncpy(textArea1Buffer, text, TEXTAREA1_SIZE);
//    textArea1.invalidate();  // Refresh the TextArea to display new data
//}

void Screen1View::uart_Data(char *data){
	Unicode::strncpy(textArea1Buffer, data, TEXTAREA1_SIZE);
	textArea1.invalidate();  // Refresh the TextArea to display new data
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    if(!runStatus){
        //change button states
    }
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::isValidInput(){
    if(std::stof(result) > 100){//invalid condition, change border color and touch feature false
        kvaluebox.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(220,53,69), touchgfx::Color::getColorFromRGB(220,53,69));
        kvaluebox.invalidate();
        kbtn1.setTouchable(false);
        kbtn1.setAlpha(100);
        kbtn1.invalidate();
        kbtn2.setTouchable(false);
        kbtn2.setAlpha(100);
        kbtn2.invalidate();
        kbtn3.setTouchable(false);
        kbtn3.setAlpha(100);
        kbtn3.invalidate();
        kbtn4.setTouchable(false);
        kbtn4.setAlpha(100);
        kbtn4.invalidate();
        kbtn5.setTouchable(false);
        kbtn5.setAlpha(100);
        kbtn5.invalidate();
        kbtn6.setTouchable(false);
        kbtn6.setAlpha(100);
        kbtn6.invalidate();
        kbtn7.setTouchable(false);
        kbtn7.setAlpha(100);
        kbtn7.invalidate();
        kbtn8.setTouchable(false);
        kbtn8.setAlpha(100);
        kbtn8.invalidate();
        kbtn9.setTouchable(false);
        kbtn9.setAlpha(100);
        kbtn9.invalidate();
        kbtn0.setTouchable(false);
        kbtn0.setAlpha(100);
        kbtn0.invalidate();
        kbtndone.setTouchable(false);
        kbtndone.setAlpha(100);
        kbtndone.invalidate();
    }else{//valid condition, set the origianl values back
        kvaluebox.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(198,206,214), touchgfx::Color::getColorFromRGB(198,206,214));
        kvaluebox.invalidate();
        kbtn1.setTouchable(true);
        kbtn1.setAlpha(255);
        kbtn1.invalidate();
        kbtn2.setTouchable(true);
        kbtn2.setAlpha(255);
        kbtn2.invalidate();
        kbtn3.setTouchable(true);
        kbtn3.setAlpha(255);
        kbtn3.invalidate();
        kbtn4.setTouchable(true);
        kbtn4.setAlpha(255);
        kbtn4.invalidate();
        kbtn5.setTouchable(true);
        kbtn5.setAlpha(255);
        kbtn5.invalidate();
        kbtn6.setTouchable(true);
        kbtn6.setAlpha(255);
        kbtn6.invalidate();
        kbtn7.setTouchable(true);
        kbtn7.setAlpha(255);
        kbtn7.invalidate();
        kbtn8.setTouchable(true);
        kbtn8.setAlpha(255);
        kbtn8.invalidate();
        kbtn9.setTouchable(true);
        kbtn9.setAlpha(255);
        kbtn9.invalidate();
        kbtn0.setTouchable(true);
        kbtn0.setAlpha(255);
        kbtn0.invalidate();
        kbtndone.setTouchable(true);
        kbtndone.setAlpha(255);
        kbtndone.invalidate();
    }
    if(std::stof(result) == 0){
        kdelete.setAlpha(90);
        kdelete.setTouchable(false);
        kdelete.invalidate();
    }else{
        kdelete.setAlpha(255);
        kdelete.setTouchable(true);
        kdelete.invalidate();
    }
}
std::string Screen1View::unicodeToStdString(const Unicode::UnicodeChar* unicodeStr)
{
    std::string result;
    while (*unicodeStr != 0) // Continue until we reach the null terminator
    {
        // Convert each UnicodeChar to a char and append to the std::string
        // Note: This is a simple conversion and may need to handle encoding properly
        result += static_cast<char>(*unicodeStr);
        unicodeStr++;
    }
    return result;
}

//Water OFF -  percent text box clicked when water OFF
void Screen1View::percentClicked(){
    keypadMode = 1;    
    decimal = 2;
    kyboardmodal.setVisible(true);
    kyboardmodal.invalidate();
    // Retrieve the text value from the TextAreaWithOneWildcard
    const Unicode::UnicodeChar* textValue = percentTxtBox.getWildcard1();
    // Convert the UnicodeChar array to std::string
    valueEntered = unicodeToStdString(textValue);
    result = valueEntered;
    Unicode::snprintf(kvalueBuffer, KVALUE_SIZE, "%s", percentTxtBoxBuffer);
    kvalue.invalidate();
}

//Water ON - depth text box clicked when water ON
void Screen1View::depthOnClicked(){
    keypadMode = 3;
    decimal = 1;
    kyboardmodal.setVisible(true);
    kyboardmodal.invalidate();

    const Unicode::UnicodeChar* textValue = depthOnTxtBox.getWildcard1();
    valueEntered = unicodeToStdString(textValue);
    //valueEntered = depthOnTxtBoxBuffer;
    Unicode::snprintf(kvalueBuffer, KVALUE_SIZE, "%s", depthOnTxtBoxBuffer);
    kvalue.invalidate();    
}

//Water ON - percent text box clicked when water ON
void Screen1View::percentOnClicked(){
    keypadMode = 2;
    decimal = 2;
    kyboardmodal.setVisible(true);
    kyboardmodal.invalidate();

    const Unicode::UnicodeChar* textValue = percentOnTxtBox.getWildcard1();
    valueEntered = unicodeToStdString(textValue);
    //valueEntered = percentOnTxtBoxBuffer;
    Unicode::snprintf(kvalueBuffer, KVALUE_SIZE, "%s", percentOnTxtBoxBuffer);
    kvalue.invalidate();    
}

void Screen1View::deleteInput()
{
    result = Screen1View::removeChar(valueEntered, '.');
    if (!result.empty())  // Ensure the string is not empty
    {
        result.pop_back();  // Removes the last character

        // // Step 2: Insert decimal point at the correct position
        if (result.length() > static_cast<size_t>(decimal)) {
            result.insert(result.length() - decimal, ".");
        } else {
            // If result is shorter than the decimal places, prepend zeros
            result.insert(0, decimal - result.length(), '0');
            result.insert(0, ".");
        }
        valueEntered = result;
        Screen1View::isValidInput();
    }
}

//calculations and rendering in keypad text box
void Screen1View::calculateAndRender(){
    // // Step 2: Insert decimal point at the correct position
    if (result.length() > static_cast<size_t>(decimal)) {
        result.insert(result.length() - decimal, ".");
    } else {
        // If result is shorter than the decimal places, prepend zeros
        result.insert(0, decimal - result.length(), '0');
        result.insert(0, ".");
    }

    // // Step 3: Remove leading zeros
    result = Screen1View::removeLeadingZeros(result);
    valueEntered = result;
    
    Unicode::snprintfFloat(kvalueBuffer, KVALUE_SIZE,(decimal == 1)?"%#3.1f":"%#3.2f", std::stof(result));    
    kvalue.invalidate();  
    Screen1View::isValidInput();
}

void Screen1View::keyOneClicked()
{

    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "1";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender();    
    
}
void Screen1View::keyTwoClicked()
{

    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "2";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender();
}
void Screen1View::keyThreeClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "3";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keyFourClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "4";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keyFiveClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "5";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keySixClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "6";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keySevenClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "7";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keyEightClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "8";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keyNineClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "9";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}
void Screen1View::keyZeroClicked()
{
    // Step 1: Remove the decimal point and append 'data'
    result = Screen1View::removeChar(valueEntered, '.');
    result += "0";

    // // Step 2: Insert decimal point at the correct position
    // // Step 3: Remove leading zeros
    Screen1View::calculateAndRender(); 
}

void Screen1View::RS232ValueReceived(){
	#ifndef SIMUlATOR
		//do bind receivedvalue
	#endif
}
void Screen1View::keyDoneClicked()
{
    if(keypadMode == 1 && std::stof(result) > 0){
        Unicode::snprintfFloat(percentTxtBoxBuffer, PERCENTTXTBOX_SIZE, (decimal == 1)?"%#3.1f":"%#3.2f", std::stof(result));
        percentTxtBox.invalidate();
		#ifndef SIMUlATOR
				presenter->RS232ValueChanged(std::stof(result));
		#endif
    }
    else if(keypadMode == 2){// Hiding since no depth support for this phase
        //Unicode::snprintfFloat(percentOnTxtBoxBuffer, PERCENTONTXTBOX_SIZE, (decimal == 1)?"%#3.1f":"%#3.2f", std::stof(result));
        //percentOnTxtBox.invalidate();
    }else if(keypadMode == 3){// Hiding since no depth support for this phase
        //Unicode::snprintfFloat(depthOnTxtBoxBuffer, DEPTHONTXTBOX_SIZE, (decimal == 1)?"%#3.1f":"%#3.2f", std::stof(result));
        //depthOnTxtBox.invalidate();
    }else{
        //do nothing...
    }    
    kyboardmodal.setVisible(false);
    kyboardmodal.invalidate();
}
void Screen1View::keyDeleteClicked()
{
    Screen1View::deleteInput();
    Unicode::snprintfFloat(kvalueBuffer, KVALUE_SIZE,(decimal == 1)?"%#3.1f":"%#3.2f", std::stof(result));    
    kvalue.invalidate(); 
    Screen1View::isValidInput(); 
}

void Screen1View::waterToggleClicked()
{
    //------ Hiding the below logic sinc we are not supporting depth right now
    // if (percent.isVisible()) {
    //     percent.setVisible(false);
    //     percent.invalidate();        
    //     percenton.setVisible(true);
    //     percenton.invalidate();
    //     percentOnTxtBox.setVisible(true);
    //     percentOnTxtBox.invalidate();
    //     depthon.setVisible(true);
    //     depthon.invalidate();
    //     depthOnTxtBox.setVisible(true);
    //     depthOnTxtBox.invalidate();
    //     depthicon.setVisible(true);
    //     depthicon.invalidate();
    // }else{
    //     percent.setVisible(true);
    //     percent.invalidate();
    //     percenton.setVisible(false);
    //     percenton.invalidate();
    //     percentOnTxtBox.setVisible(false);
    //     percentOnTxtBox.invalidate();
    //     depthon.setVisible(false);
    //     depthon.invalidate();
    //     depthOnTxtBox.setVisible(false);
    //     depthOnTxtBox.invalidate();
    //     depthicon.setVisible(false);
    //     depthicon.invalidate();
    // }
    
    
}
