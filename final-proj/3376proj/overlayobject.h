#ifndef OVERLAYOBJECT_H
#define OVERLAYOBJECT_H

#include <QtCore>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

using namespace cv;

struct OverlayObject{
  virtual Mat getOverlay(){
      return Mat();
  }
};
Q_DECLARE_METATYPE(OverlayObject*)

struct SmileyOverlay: public OverlayObject{
   Mat getOverlay() override{
      Mat mtx = imread("overlays/smiley.png");

        return mtx;
   }
};

struct PowerRangerOverlay: public OverlayObject{
   Mat getOverlay(){
      Mat mtx = imread("overlays/powerRanger.jpg");
      return mtx;
   }
};

struct FootballOverlay: public OverlayObject{
   Mat getOverlay(){
      Mat mtx = imread("overlays/football.png",IMREAD_UNCHANGED);

      return mtx;
   }
};
struct PikachuOverlay: public OverlayObject{
   Mat getOverlay(){
      Mat mtx = imread("overlays/pikachu.jpg");
      return mtx;
   }
};
struct MadFaceOverlay: public OverlayObject{
   Mat getOverlay(){
      Mat mtx = imread("overlays/madFace.jpg");
      return mtx;
   }
};

#endif // OVERLAYOBJECT_H
