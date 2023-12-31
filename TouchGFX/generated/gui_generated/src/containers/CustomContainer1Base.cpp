/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/CustomContainer1Base.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

CustomContainer1Base::CustomContainer1Base()
{
    setWidth(194);
    setHeight(168);
    circle1.setPosition(0, 0, 80, 80);
    circle1.setCenter(40, 40);
    circle1.setRadius(40);
    circle1.setLineWidth(0);
    circle1.setArc(0, 360);
    circle1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle1.setPainter(circle1Painter);
    add(circle1);

    circle2.setPosition(0, 0, 80, 80);
    circle2.setCenter(40, 40);
    circle2.setRadius(35);
    circle2.setLineWidth(0);
    circle2.setArc(0, 360);
    circle2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle2.setPainter(circle2Painter);
    add(circle2);

    textArea1.setXY(22, 28);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZXPJ));
    add(textArea1);

    circle3.setPosition(97, 67, 80, 80);
    circle3.setCenter(40, 40);
    circle3.setRadius(40);
    circle3.setLineWidth(0);
    circle3.setArc(0, 360);
    circle3Painter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    circle3.setPainter(circle3Painter);
    add(circle3);

    circle4.setPosition(97, 67, 80, 80);
    circle4.setCenter(40, 40);
    circle4.setRadius(40);
    circle4.setLineWidth(0);
    circle4.setArc(0, 360);
    circle4Painter.setColor(touchgfx::Color::getColorFromRGB(0, 187, 255));
    circle4.setPainter(circle4Painter);
    add(circle4);
}

CustomContainer1Base::~CustomContainer1Base()
{

}

void CustomContainer1Base::initialize()
{

}
