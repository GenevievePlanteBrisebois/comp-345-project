
#pragma once
using namespace std;
class Borough
{
    public:
        Borough();
        Borough(bool status, string name);
        ~Borough();
        void setName(string name);
        void setStatus(bool stat);
        string getName();
        bool getStatus();

    protected:

    private:
};


