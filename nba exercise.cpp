#include<iostream>
#include<string>
#include<stdio.h>


using namespace std;

class NBA2K20{
    private:
        string name;
        int OR;
        int TO;
        int FTA;
    public:
        NBA2K20(string s, int o, int t, int f){
            name = s;
            OR = o;
            TO = t;
            FTA = f;
        }

        string getName(){
            return name;
        }

        int getOR(){
            return OR;
        }

        int getTO(){
            return TO;
        }

        int getFTA(){
            return FTA;
        }

        virtual double possessionPoints() = 0;

};

class Teams : public NBA2K20{
    private:
        int teamsFGA;
        int teamsPTS;
    public:
        Teams(string s, int o, int t, int f, int tf, int tp) : NBA2K20(s,o,t,f) {
            teamsFGA = tf;
            teamsPTS = tp;
        }

        double possessionPoints(){
            return (double) teamsFGA - getOR() + getTO() + (double)(0.512 * getFTA()) + (double)(1.4 * teamsPTS);
        }

};

class GamePlayers: public NBA2K20{
    private:
        int playersFGA;
        int playersPTS;
    public:
        GamePlayers(string s, int o, int t, int f, int pf, int pt) : NBA2K20(s,t,o,f) {
            playersFGA = pf;
            playersPTS = pt;
        }

        double possessionPoints(){
            return (double) (playersPTS)/(playersFGA + (0.44 * getFTA()) + getTO());
        }

};


void display(NBA2K20 *nba){
        cout << "Name:" << nba->getName() << ", Ribound:" << nba->getOR() << ", Lost ball:" << nba->getTO() << ", Free throw:" << nba->getFTA() << ", Possession point:" << nba->possessionPoints() << endl;
        //printf("Name:%s, Ribound:%d, Lost ball:%d, Free throw:%d, Possession point: %lf, \n", nba.getName().c_str(),nba.getOr(),nba.getTO(),nba.getFTA(), nba.possessionPoints)

}

int main(){
    NBA2K20 *ar[2];
    ar[0] = new Teams("Lakers", 12, 7,10,55,111);
    ar[1] = new GamePlayers("Kobe Bryant",3,5,5,33,101);
    display(ar[0]);
    display(ar[1]);

}
