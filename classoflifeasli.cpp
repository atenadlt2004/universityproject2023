#include "cell.h"
using namespace std;

int main()
{
    while ("atena")
    {

        cout << "Which part of the program do you want to work with?\n";
        cout << "Genome: Enter number 1 :)\n";
        cout << "Cell: Enter number 2 :)\n";
        cout << "Exit: Enter numbar 3 :)\n";
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
            cout << "Which part of this do you want to work whit?"
                 << "\n";
            cout << "Small mutation : Enter number 1 :)"
                 << "\n";
            cout << "Big mutation : Enter number 2 :)"
                 << "\n";
            cout << "Reverse mutation : Enter number 3 :)"
                 << "\n";
            int entekhab;
            cin >> entekhab;
            if (entekhab == 1)
            {
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
            }
            if (entekhab == 2)
            {
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
            }
            else if (entekhab == 3)
            {
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
            else
            {
                cout << "Enter a number between 1 to 3 +_+";
            }
        }
        else if (dastoor == 2)
        {
            cout << "Enter the number of chromosomes:\n";
            int tedad;
            cin >> tedad;
            cell cellule;
            string k;
            string d;
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
                cout << "\nEnter your second part: ";
                cin >> k;
                cellule.makechromosome(d + "\n" + k);
            }
            cout << "Your chromosome is:\n";
            cellule.printchromosome();
            int entekhab;
            cout << "Which part of this do you want to work whit?"
                 << "\n";
            cout << "Small mutation : Enter number 1 :)"
                 << "\n";
            cout << "Big mutation : Enter number 2 :)"
                 << "\n";
            cout << "Reverse mutation : Enter number 3 :)"
                 << "\n";
            cout << "find all palinromes : Enter numbar 4 :)"
                 << "\n";
            cin >> entekhab;
            if (entekhab == 2)
            {
                cout << "Enter two strings and two numbers like this (string  number   string  number ) for a big mutation";
                cout << "\n";
                cin >> v1 >> n >> v2 >> m;
                cout << "\n"
                     << "Your cellule after a big mutation is:";
                cout << "\n";
                cellule.jaheshbozorgcell(v1, n - 1, v2, m - 1);
                cellule.printchromosome();
                cout << "\n";
            }
            else if (entekhab == 3)
            {
                cout << "Enter a string and a number for reverse mutation:"
                     << "\n";
                cin >> y1 >> y2;
                cout << "\n";
                cellule.JaheshmakoosRNAcell(y1, y2 - 1);
                cout << "Your cellule after a reverse mutation:";
                cout << "\n";
                cellule.printchromosome();
            }
            else if (entekhab == 3)
            {
                cout << "Enter two characters and two numbers for small mutation:"
                     << "\n";
                cin >> k1 >> k2 >> p1 >> p2;
                cellule.jaheshkoochikcell(k1, k2, p1, p2 - 1);
                cout << "\n"
                     << "Your cellule after a small mutation is:";
                cout << "\n";
                cellule.printchromosome();
                cout << "\n";
            }
            else if (entekhab == 4)
            {
                cellule.palindromeyab();
            }
            else
            {
                cout << "Enter a number between 1 to 4  +_+";
            }
        }
        else if (dastoor == 3)
        {
            cout << "\nEnd *_*";
            break;
        }
    }
    return 0;
}