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
          void setRNA(string voroodiRNA)//Receiving the input and storing it in the RNA variable
          {
                    RNA = voroodiRNA;
          }
          string sakhtDNA()//Making a complement from RNA and then making DNA from RNA and its complenet 
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
          string taghirRNA(char j, char c, int z)//A function for small mutation in RNA
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
          string taghirDNA()//A function for small mutation in DNA
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
          string jaheshbozorg(string S1, string S2)//A function for big mutation in RNA
          {
                    RNA.replace(RNA.find(S1), S1.size(), S2);
                    return RNA;
          }
          string JaheshmakoosRNA(string S3)//A function for reverse mutation in RNA
          {
                    string makoosS3 = "";
                    for (int i = (S3.size() - 1); 0 <= i; i--)
                    {
                              makoosS3 = makoosS3 + S3[i];
                    }
                    RNA.replace(RNA.find(S3), S3.size(), makoosS3);

                    return RNA;
          }
          string sakhtDNAjaheshbozorg(string u)//A fuction for big mutation in DNA
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

class cell : public Genome// The second class: Cell
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
          void check(string k, string u)//A function for checking 
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
          string mokammelsaz(string u)
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
                    return rev;
          }
          void jaheshbozorgcell(string v1, int n, string v2, int m)
          {
                    string mokammelv1 = "";
                    string mokammelv2 = "";
                    chromosome[n].replace(chromosome[n].find(v1), v1.size(), v2);
                    chromosome[m].replace(chromosome[m].find(v2), v2.size(), v1);
                    mokammelv1 = mokammelsaz(v1);
                    mokammelv2 = mokammelsaz(v2);
                    chromosome[n].replace(chromosome[n].find(mokammelv1), mokammelv1.size(), mokammelv2);
                    chromosome[m].replace(chromosome[m].find(mokammelv2), mokammelv2.size(), mokammelv1);
          }

          void jaheshmakooscell(string y1, int y2)
          {
                    string y3;
                    string mokammely1;
                    string mokammely3;
                    y3 = makooascell(y1);
                    chromosome[y2].replace(chromosome[y2].find(y1), y1.size(), y3);
                    mokammely3 = mokammelgiri(y3);
                    mokammely1 = mokammelgiri(y1);
                    chromosome[y2].replace(chromosome[y2].find(mokammely1), mokammely1.size(), mokammely3);
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
          void jaheshkoochikcell(char k1, char k2, int p1, int p2)
          {
                    int pp = p1;
                    string z = chromosome[p2];
                    char q, p;
                    if (k2 == 'A')
                    {
                              q = 'T';
                    }
                    else if (k2 == 'T')
                    {
                              q = 'A';
                    }
                    else if (k2 == 'C')
                    {
                              q = 'G';
                    }
                    else
                    {
                              q = 'C';
                    }
                    ////////////
                    if (k1 == 'A')
                    {
                              p = 'T';
                    }
                    else if (k1 == 'T')
                    {
                              p = 'A';
                    }
                    else if (k1 == 'C')
                    {
                              p = 'G';
                    }
                    else
                    {
                              p = 'C';
                    }

                    int i = 0;
                    while (p1 > 0)
                    {
                              if (z[i] == k1)
                              {
                                        z[i] = k2;
                                        p1 = p1 - 1;
                              }
                              i++;
                    }
                    i = (z.length() - 1) / 2;
                    while (pp > 0)
                    {
                              if (z[i] == p)
                              {
                                        z[i] = q;
                                        pp = pp - 1;
                              }
                              i++;
                    }

                    chromosome[p1].replace(0, z.length(), z);
          }

          void JaheshmakoosRNAcell(string y1, int y2)
          {
                    string rev = y1;
                    string SS = chromosome[y2];
                    string S3 = "";
                    for (int i = 0; SS[i] != '\n'; i++)
                    {
                              S3 += SS[i];
                    }
                    reverse(rev.begin(), rev.end());
                    S3.replace(S3.find(y1), rev.size(), rev);
                    chromosome[y2] = mokammelgiri(S3);
          }
          bool check_palindrome(string str, int start, int end)
          {
                    bool ans = true;
                    while (start < end)
                    {
                              if (str[start] != str[end])
                                        ans = false;
                              start++;
                              end--;
                    }
                    return ans;
          }

          void palindromeyab()
          {
                    for (int k = 0; k < chromosome.size(); k++)
                    {
                              string str = chromosome[k];
                              for (int i = 0; i < str.length(); i++)
                              {
                                        for (int j = i + 2; j < str.length(); j++)
                                        {
                                                  if (check_palindrome(str, i, j) == 1)
                                                  {
                                                            cout << (str.substr(i, j - i + 1)) << endl;
                                                  }
                                        }
                              }
                    }
          }
};