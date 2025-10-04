#include <iostream>

class Rectangle{

private:

float Longueur;
float Largeur;
float Aire;

public:

//constructeur
Rectangle();
Rectangle(float a, float b);

//set and get 
float getLongueur();
float getLargeur();
float getAire();
void setLongueur(float a);
void setLargeur(float b);

};

using namespace::std;

Rectangle::Rectangle(){
Longueur = -1;
Largeur  = -1;
Aire = -1;

}

Rectangle::Rectangle(float a, float b){
Longueur = a;
Largeur = b;
Aire = a * b;
}

Rectangle::getLongueur(){

return Longueur;
}

Rectangle::getLargeur(){

return Largeur;
}

Rectangle::getAire(){

return Aire;
}

Rectangle::setLongueur(float a){
Longueur = a;
}

Rectangle::setLargeur(float b){
Largeur = b;
}

int main(){

cout<<"Hello world !"<<endl;

return 0;
}
