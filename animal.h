#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

class Chromosome
{
          std::string genetic_code;

public:
          Chromosome(std::string genetic_code) : genetic_code(genetic_code) {}

          double calculate_similarity(const Chromosome &other) const
          {
                    if (genetic_code.length() != other.genetic_code.length())
                              throw std::invalid_argument("Chromosomes must have the same length for similarity calculation");

                    int match_count = 0;
                    for (size_t i = 0; i < genetic_code.length(); i++)
                    {
                              if (genetic_code[i] == other.genetic_code[i])
                                        match_count++;
                    }

                    return (match_count * 100.0) / genetic_code.length();
          }
};

class Animal
{
protected:
          std::vector<Chromosome> chromosomes;

public:
          Animal(const std::vector<Chromosome> &chromosomes) : chromosomes(chromosomes) {}

          bool operator==(const Animal &other) const
          {
                    if (chromosomes.size() != other.chromosomes.size())
                              return false;

                    for (size_t i = 0; i < chromosomes.size(); i++)
                    {
                              double similarity = chromosomes[i].calculate_similarity(other.chromosomes[i]);
                              if (similarity < 70)
                                        return false;
                    }

                    return true;
          }

          Animal asexual_reproduction() const
          {
                    std::vector<Chromosome> new_chromosomes;
                    new_chromosomes.reserve(2 * chromosomes.size());

                    for (size_t i = 0; i < chromosomes.size(); i++)
                    {
                              new_chromosomes.push_back(chromosomes[i]);
                              new_chromosomes.push_back(chromosomes[i]);
                    }

                    std::random_shuffle(new_chromosomes.begin(), new_chromosomes.end());

                    return Animal(std::vector<Chromosome>(new_chromosomes.begin(), new_chromosomes.begin() + chromosomes.size()));
          }

          friend Animal sexual_reproduction(const Animal &parent1, const Animal &parent2)
          {
                    if (parent1.chromosomes.size() != parent2.chromosomes.size() || parent1.chromosomes.size() % 2 == 1)
                              throw std::invalid_argument("Invalid chromosome count for sexual reproduction");

                    std::vector<size_t> indices(parent1.chromosomes.size());
                    for (size_t i = 0; i < indices.size(); i++)
                              indices[i] = i;

                    std::random_shuffle(indices.begin(), indices.end());

                    std::vector<Chromosome>
          }
}