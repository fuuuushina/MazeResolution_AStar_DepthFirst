#include<iostream>
#include<fstream>
#include<cstring>
#include<list>
#include<cstdlib>
#include<thread>
#include<chrono>
#include<vector>


class maze{

private:
int map[21*12];
std::string shareMap[21*12];
int pose;
int oldPose;
int objectif;
int visits[21*12] = {0};
std::vector<int> chemin;

public:
maze(std::string nomFichier);
void mapTrans();
void deplacement();
void deplacementDfs();
void deplacementOpt();
int getPose();
int getMap();
friend std:: ostream& operator <<(std::ostream& os, const maze& m); 
};

using namespace::std;

maze::maze( string nomFichier){
ifstream f ("maze.txt");
pose = 1;
int i = 0;

for (i=0; i < 21*12; i++){
	f >> map[i];

}

f.close();
};

int maze::getPose(){
return pose;
}


int maze::getMap(){
return map[pose];
}



void maze::deplacement(){

//oldPose = pose
list<int> randSet;
if (pose + 1 < 21*12 && (map[pose + 1] == 0 || map[pose +1] == 3)) randSet.push_back(pose + 1);
cout<< pose<<endl;
if (pose - 1 >= 0 && map[pose - 1] == 0) randSet.push_back(pose - 1);
if (pose + 21 < 21*12 && (map[pose + 21] == 0 || map[pose + 21] == 3)) randSet.push_back(pose + 21);
if (pose - 21 >= 0 && map[pose - 21] == 0) randSet.push_back(pose -21);

        if (!randSet.empty()){
                 int index = std::rand() % randSet.size();
		 auto it = randSet.begin();
		 advance(it, index);
		 oldPose = pose;
		 pose = *it;
		 visits[pose]++;
                 //shareMap[pose] = '@';
		// cout<<"Curseur"<< shareMap[pose]<<endl;
		 //shareMap[oldPose] = ' ';
                 shareMap[1] = "🚪";
		  mapTrans();  

}
}



void maze::deplacementOpt(){

//oldPose = pose
vector<int> randSet;
vector<int> randDir;
if (pose + 1 < 21*12 && (map[pose + 1] == 0 || map[pose +1] == 3)) randSet.push_back(pose + 1);
//cout<< pose<<endl;
if (pose - 1 >= 0 && (map[pose - 1] == 0 || map[pose - 1] == 3)) randSet.push_back(pose - 1);
if (pose + 21 < 21*12 && (map[pose + 21] == 0 || map[pose + 21] == 3)) randSet.push_back(pose + 21);
if (pose - 21 >= 0 && (map[pose - 21] == 0 || map[pose - 21] == 3)) randSet.push_back(pose -21);

		 
                 int minVal = visits[randSet[0]];
		 for(int j = 0; j < randSet.size(); j++){
		 if (visits[randSet[j]] < minVal){
		 minVal = visits[randSet[j]];
		 }
		 }


		 for (int i = 0; i < randSet.size(); i++){
		 if (visits[randSet[i]] == minVal){
		 randDir.push_back(randSet[i]);
		 }
		 }
		
		 srand(time(0));
        	 int randomIndex = rand() % randDir.size();

                 oldPose = pose;
                 pose = randDir[randomIndex];
                 visits[pose]++;
                 //shareMap[pose] = '@';
                 //cout<<"Curseur"<< shareMap[pose]<<endl;
                 //shareMap[oldPose] = ' ';
                 shareMap[1] = "🚪";
                  mapTrans();


}









void maze::deplacementDfs(){

vector<int> randSet;


	if (pose + 1 < 21*12 && (map[pose + 1] == 0 || map[pose +1] == 3)) randSet.push_back(pose + 1);
	if (pose - 1 >= 0 && map[pose - 1] == 0) randSet.push_back(pose - 1);
	if (pose + 21 < 21*12 && (map[pose + 21] == 0 || map[pose + 21] == 3)) randSet.push_back(pose + 21);
	if (pose - 21 >= 0 && map[pose - 21] == 0) randSet.push_back(pose -21);

	int next = -1;
	int bestScore = 10000;
	for(int i = 0; i < randSet.size(); i++){
	int r = randSet[i];

	int ligne = r / 21;
	int col = r % 21;
	int ligneObj = objectif / 21;
	int colObj = objectif % 21;
	int distance = abs(ligneObj - ligne) + abs(colObj - col);
	int score = visits[r] * 2 + distance;
	if(score < bestScore){
	bestScore = score;
	next = r;
	}

	}

                 	oldPose = pose;
                 	pose = next;
			chemin.push_back(oldPose);
                 	visits[pose]++;
                 	//shareMap[pose] = '@';
                 	//cout<<"Curseur"<< shareMap[pose]<<endl;
                 	//shareMap[oldPose] = ' ';
                  	mapTrans();

                        shareMap[1] = "🚪";


}





void maze::mapTrans(){
/*int i = 0;
for (i = 0; i < 21*12; i++){
	if (map[i] == 1) shareMap[i] ='N';
	if (i < 21*12 -1 && map[i] == 1 && map[i-1] == 1 && map[i+1] == 1) shareMap[i] = 'M';
	if (map[i] == 2) shareMap[i] = '@';
	if (map[i] == 3) shareMap[i] = '3';
	    if (map[i] == 0) {
        if (visits[i] >= 20)
            shareMap[i] = 'O';
        else if (visits[i] >= 10)
            shareMap[i] = 'o';
        else if (visits[i] > 0)
            shareMap[i] = '.';
        else
            shareMap[i] = ' ';  // jamais visité
    }

}
*/
for (int i = 0; i < 21 * 12; i++) {
        if (map[i] == 1)  shareMap[i] = "⬜";  // mur
        if (map[i] == 3)  shareMap[i] = "🏁";  // objectif 
        if (map[i] == 0) {
	    if (visits[i] >= 80) 
		shareMap[i] = "🟣";
	    else if (visits[i] >= 40)
		shareMap[i] = "🔺";
            else if (visits[i] >= 20)
                shareMap[i] = "🔸";
            else if (visits[i] >= 10)
                shareMap[i] = "🔹";
            else if (visits[i] > 0)
                shareMap[i] = ". ";
            else
                shareMap[i] = "  ";
        }


    }
       shareMap[pose] = "🧍";  // position actuelle

}





ostream& operator << (ostream& os, const maze& m) 
{
int j;
for (j = 0; j < 21*12; j++ ){
	
	if ( j % 21 ==0 && j != 0 ) cout<<endl;

	os << m.shareMap[j]<<" ";}
return os;}

int main(){
srand(10);
int runs = 1000;
int minMoves = 0; 
int maxMoves = 0;
long long totalMoves = 0;

//maze m("maze.txt");
//m.mapTrans();
//cout<<m<<endl;
//m.deplacement();
//int moves = 0;

for (int i = 0; i < runs; i++){
	maze m("maze.txt");
        m.mapTrans();

        int moves = 0;

while (m.getMap() != 3) {
	int oldPose = m.getPose();
	m.deplacementOpt();

    //  Effacer l’écran
    //#ifdef _WIN32
      //  system("cls");
    //#else
      //  system("clear");
    //#endif

    //  Déplacer le joueur

    // compteur
if(m.getPose() != oldPose) {
    moves++;
}
}
    //  Afficher le labyrinthe
    //std::cout << m << std::endl;

    //  Petite pause pour ralentir la boucle
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));

//cout << "Déplacements totaux: " << moves << endl;
 if (i == 0) {
            minMoves = moves;
            maxMoves = moves;
}
    if (moves < minMoves) minMoves = moves;
        if (moves > maxMoves) maxMoves = moves;
        totalMoves += moves;
}
 double moyenne = static_cast<double>(totalMoves) / runs;

    cout << "Résultats sur " << runs << " labyrinthes :" << endl;
    cout << "   Minimum déplacements : " << minMoves << endl;
    cout << "   Maximum déplacements : " << maxMoves << endl;
    cout << "   Moyenne déplacements : " << moyenne << endl;



return 0;
}

