#include<iostream>
#include<math.h>

class Segment{

private:

float x1;
float y1;
float x2;
float y2;
float Longueur;

public:
Segment();
Segment(float x11, float x22, float y11, float y22);
float longueur(float x11, float x22, float y11, float y22);
float milieu(float x11, float x22, float y11, float y22);

//friend ostream& operator << (ostream& os, const Segment& s);
};

using namespace::std;

Segment::Segment(){
x1 = -1;
x2 = -1;
y1 = -1;
y2 = -1;
Longueur = -1;
}

Segment::Segment(float x11, float x22, float y11, float y22){
x1 = x11;
x2 = x22;
y1 = y11;
y2 = y22;
Longueur = sqrt((x2 - x1) * (x2 -x1) + (y2 - y1) * (y2 - y1));
}



float Segment::longueur(float x11, float x22, float y11, float y22){
Longueur = sqrt((x22 - x11) * (x22 - x11) + (y22-y11) * (y22-y11));
return Longueur;
}


float Segment::milieu(float x11, float x22, float y11, float y22){
float milieu = 0;
milieu = (sqrt((x22 - x11) * (x22 - x11) + (y22 - y11) * (y22 - y11))) / 2 ;

return milieu;
}


int main(){
return 0;
}
