#include <iostream>
#include <string>
#include <vector>
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

class cell : public Genome
{
    vector<string> chromosome;

public:
    void makechromosome(string DNA)
    {
        chromosome.push_back(DNA);
    }
    void printchromosome()
    {
        for (int i = 0; i < chromosome.size(); i++)
        {
            cout << chromosome[i] << "\n\n";
        }
    }
    string mokammelgiri(string u)
    {
        string rev;
        rev = "";
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == 'A')
            {
                rev = rev + 'T';
            }
            else if (u[i] == 'T')
            {
                rev = rev + 'A';
            }
            else if (u[i] == 'C')
            {
                rev = rev + 'G';
            }
            else
            {
                rev = rev + 'C';
            }
        }
        string dnaM = u + '\n' + rev;
        return dnaM;
    }
    void check(string k, string u)
    {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        bool answer = true;
        for (int i = 1; i <= k.size(); i++)
        {
            if (k[i] != u[i])
            {
                count1 = count1 + 1;
            }
        }
        if (5 < count1)
        {
            answer = false;
        }
        for (int i = 1; i <= k.size(); i++)
        {
            if ((k[i] == 'A' && u[i] == 'T') || (k[i] == 'T' && u[i] == 'A'))
            {
                count2 = count2 + 1;
            }
            if ((k[i] == 'G' && u[i] == 'C') || (k[i] == 'C' && u[i] == 'G'))
            {
                count3 = count3 + 1;
            }
        }
        if ((count3 * 3) < count2)
        {
            answer = false;
        }

        if (answer == false)
        {
            cout << "cellule died :(";
            delete this;
        }
    }
    string jaheshbozorgcell(string v1, int n, string v2, int m)
    {
        string mokammelv1 = "";
        string mokammelv2 = "";
        chromosome[n].replace(chromosome[n].find(v1), v1.size(), v2);
        chromosome[m].replace(chromosome[m].find(v2), v2.size(), v1);
        mokammelv1 = mokammelgiri(v1);
        mokammelv2 = mokammelgiri(v2);
        chromosome[n].replace(chromosome[n].find(mokammelv1), mokammelv1.size(), mokammelv2);
        chromosome[m].replace(chromosome[m].find(mokammelv2), mokammelv2.size(), mokammelv1);
        return chromosome;
    }

    string jaheshmakooscell(string y1, int y2)
    {
        string y3;
        string mokammely1;
        string mokammely3;
        y3 = makooascell(y1);
        chromosome[y2].replace(chromosome[y2].find(y1), y1.size(), y3);
        mokammely3 = mokammelgiri(y3);
        mokammely1 = mokammelgiri(y1);
        chromosome[y2].replace(chromosome[y2].find(mokammely1), mokammely1.size(), mokammely3);
        return chromosome;
    }
    string makooascell(string y4)
    {
        string y5;
        for (int r = (y4.size() - 1); 0 <= r; r--)
        {
            y5 = y5 + y4[r];
        }
        return y5;
    }
};
int main()
{
    int dastoor;
    cout << "";
    cin >> dastoor;
    if (dastoor == 1)
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
    }

    else if (dastoor == 2)
    {
        int tedad;
        cin >> tedad;
        cell cellule;
        string d;
        string k;
        string v1;
        string v2;
        int n;
        int m;
        char k1;
        char k2;
        int p1;
        int p2;
        string y1;
        int y2;
        for (int i = 0; i < tedad; i++)
        {
            cout << "Enter your RNA: ";
            cin >> d;
            cout << "\n Enter your second part: ";
            cin >> k;
            cellule.makechromosome(d + "\n" + k);
        }
        cout << "Your chromosome is:\n";
        cellule.printchromosome();
        cout << "Enter two strings and two numbers like this (string  number   string  number ) for a big mutation";
        cout << "\n";
        cin >> v1 >> n >> v2 >> m;
        cout << "\n"
             << "Your cellule after a big mutation is:";
        cout << "\n"
             << cellule.jaheshbozorgcell(v1, n, v2, m);
        cout << "\n"
             << "Enter a string and a number for reverse mutation:"
             << "\n";
        cin >> y1 >> y2;
        cout << "\n"
             << "Your cellule after a reverse mutation:";
        cout << "\n"
             << cellule.JaheshmakoosRNA(y1, y2);
    }
    return 0;
}