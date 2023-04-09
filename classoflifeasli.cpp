#include <iostream>
#include <string>
using namespace std;
class Genome
{
public:
    string RNA;
    string DNA;
    string x;
    void setRNA(string voroodiRNA)
    {
        RNA = voroodiRNA;
    }
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
    string taghirRNA(char j, char c, int z)
    {
        for (int i = 0;; i++)
        {
            if (RNA[i] == j)
            {
                z = z - 1;
                RNA[i] = c;
            }
            if (z < 1)
            {
                break;
            }
        }
        taghirDNA();
        return RNA;
    }
    string taghirDNA()
    {
        x = "";
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
    string voroodi;
    cin >> voroodi;
    char a;
    char b;
    int c;
    cin >> a >> b >> c;
    Genome Gen;
    Gen.setRNA(voroodi);
    cout << "Your RNA is :"
         << "\n"
         << voroodi << "\n";
    cout << "Your DNA is";
    cout << endl
         << Gen.sakhtDNA();
    cout << "\n"
         << "Your RNA after a small mutation is:";
    cout << "\n"
         << Gen.taghirRNA(a, b, c);
    cout << "\n"
         << "Your DNA after a small mutation is:";
    cout << endl
         << Gen.taghirDNA();

    return 0;
}