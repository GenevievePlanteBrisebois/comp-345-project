
#pragma once
#include <string>
using namespace std;

class Borough
{
    public:
        Borough();
        Borough(bool status, string name, string playerName);
        ~Borough();
        void setName(string name);
        void setBoroughStatus(bool stat);
		void setPlayerName(string name);
		string getPlayerName();
        string getBName();
        bool getBoroughStatus();


    protected:

    private:
};


