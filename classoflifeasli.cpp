#include <iostream>
#include <string>
using namespace std;
class Genome
{
    string RNA;
    string DNA;
    string x;
    string sakhtDNA()
    {
        for (int i = 0; i < RNA.length(); i++)
        {
            if (RNA[i] == 'A')
            {
                x = x + 'T';
            }
            else if (RNA[i] == 'T')
            {
                x = x + 'A';
            }
            else if (RNA[i] == 'C')
            {
                x = x + 'G';
            }
            else
            {
                x = x + 'C';
            }
        }
        DNA = RNA + '\n' + x;
        return DNA;
    }
};
int main()
{
    return 0;
}