/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/wrench_symbolBase.hpp>
#include <touchgfx/Color.hpp>

wrench_symbolBase::wrench_symbolBase()
{
    setWidth(60);
    setHeight(60);
    circle1.setPosition(0, 0, 60, 60);
    circle1.setCenter(30, 30);
    circle1.setRadius(30);
    circle1.setLineWidth(0);
    circle1.setArc(0, 360);
    circle1Painter.setColor(touchgfx::Color::getColorFromRGB(84, 84, 84));
    circle1.setPainter(circle1Painter);
    add(circle1);

    line1.setPosition(0, 0, 60, 60);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(15.3f, 43.6f);
    line1.setEnd(35.2f, 23.6f);
    line1.setLineWidth(10);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line1);

    circle2.setPosition(0, 0, 60, 60);
    circle2.setCenter(40, 19);
    circle2.setRadius(8);
    circle2.setLineWidth(0);
    circle2.setArc(0, 360);
    circle2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle2.setPainter(circle2Painter);
    add(circle2);

    line2.setPosition(0, 0, 60, 60);
    line2Painter.setColor(touchgfx::Color::getColorFromRGB(84, 84, 84));
    line2.setPainter(line2Painter);
    line2.setStart(40.7f, 18.0f);
    line2.setEnd(45.7f, 13.3f);
    line2.setLineWidth(5.5f);
    line2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line2);
}

wrench_symbolBase::~wrench_symbolBase()
{

}

void wrench_symbolBase::initialize()
{

}
