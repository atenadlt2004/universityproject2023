#include <iostream>
#include <string>
#include <algorithm>
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
    string jaheshbozorg(string S1, string S2)
    {
        RNA.replace(RNA.find(S1), S1.size(), S2);
        return RNA;
    }
    string JaheshmakoosRNA(string S3)
    {
        string makoosS3 = "";
        for (int i = (S3.size() - 1); 0 <= i; i--)
        {
            makoosS3 = makoosS3 + S3[i];
        }
        RNA.replace(RNA.find(S3), S3.size(), makoosS3);

        return RNA;
    }
    string sakhtDNAjaheshbozorg(string u)
    {
        x = "";
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == 'A')
            {
                x = x + 'T';
            }
            else if (u[i] == 'T')
            {
                x = x + 'A';
            }
            else if (u[i] == 'C')
            {
                x = x + 'G';
            }
            else
            {
                x = x + 'C';
            }
        }
        DNA = u + '\n' + x;
        RNA = u;
        return DNA;
    }
};
int main()
{
    string voroodi;
    char a;
    char b;
    string S1;
    string S2;
    string S3;
    string u;
    string l;
    int c;
    cout << "Enter your RNA :"
         << "\n";
    cin >> voroodi;
    Genome Gen;
    Gen.setRNA(voroodi);
    cout << "\n"
         << "Your RNA is :"
         << "\n"
         << voroodi << "\n";
    cout << "Your DNA is";
    cout << "\n"
         << Gen.sakhtDNA()
         << "\n";

    cout << "Enter two characters and one number for small mutation "
         << ">>\n";
    cin >> a >> b >> c;
    cout << "\n"
         << "Your RNA after a small mutation is:";
    cout << "\n"
         << Gen.taghirRNA(a, b, c);
    cout << "\n"
         << "Your DNA after a small mutation is:";
    cout << "\n"
         << Gen.taghirDNA()
         << "\n";
    cout << "Enter two strings for a big  mutation :"
         << "\n";
    cin >> S1 >> S2;
    cout << "\n"
         << "your RNA after a big mutation is :";
    u = Gen.jaheshbozorg(S1, S2);
    cout << "\n"
         << u
         << "\n"
         << "your DNA after a big mutation is :";
    cout << "\n"
         << Gen.sakhtDNAjaheshbozorg(u)
         << "\n";
    cout << "Enter one string for a reverse mutation :"
         << "\n";
    cin >> S3;
    cout << "\n"
         << "Your RNA after a reverse mutation is :";
    cout << "\n";
    l = Gen.JaheshmakoosRNA(S3);
    cout << l;
    cout << "\n"
         << "Your DNA after a reverse mutation is :";
    cout << "\n"
         << Gen.sakhtDNAjaheshbozorg(l);
    return 0;
}