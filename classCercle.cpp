#include<iostream>

class Cercle{

//données privées
private:
float rayon;
float diametre;
float aire;
float perimetre;

//donnée public
public:
Cercle();
Cercle(float r);

//setters / getters 
float getrayon();
float getDiametre();
float getAire();
float getPerimetre();

void setRayon(float r);


//surcharge
friend std:: ostream& operator <<( std::ostream& os, const Cercle& c);

};

using namespace::std;

//constructeur vide pour prevenir les erreurs 
Cercle::Cercle() {
rayon = -1;
diametre = -1;
aire = -1;
perimetre = -1;
}

//création du cercle 
Cercle::Cercle(float r){
rayon = r;
diametre = 2*r;
aire = 3.14 *r*r;
perimetre = 2*3.14*r;


}
//initialisaton de la fonction set
void Cercle::setRayon(float r){
rayon = r;
diametre = 2*r;
aire = 3.14*r*r;
perimetre = 2*3.14*r;
}
ostream& operator << (ostream& os, const Cercle& c) {os <<"rayon:"<<c.rayon <<"diametre:"<<c.diametre<<" perimetre :"<<c.perimetre<<"aire:"<<c.aire<<endl; return os;}


//main qui va executer les fonctions
int main (){

Cercle toto(6);
cout<< toto<<endl; 
return 0;
}
