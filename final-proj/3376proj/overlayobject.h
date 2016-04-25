#ifndef OVERLAYOBJECT_H
#define OVERLAYOBJECT_H

#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

class OverlayObject
{
public:
    static virtual Mat produceOutput(Mat inputframes)=0;
private:
    std::string name = "default";
};

#endif // OVERLAYOBJECT_H
