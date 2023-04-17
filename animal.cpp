#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

// Define a random number generator for use in the breeding functions
std::mt19937 rng(std::random_device{}());

// Define a function to calculate the genetic similarity between two chromosomes
double calculateGeneticSimilarity(const std::string& chromosome1, const std::string& chromosome2) {
    if (chromosome1.length() != chromosome2.length()) {
        throw std::invalid_argument("Chromosomes must be of equal length");
    }
    int matches = 0;
    for (int i = 0; i < chromosome1.length(); i++) {
        if (chromosome1[i] == chromosome2[i]) {
            matches++;
        }
    }
    return static_cast<double>(matches) / chromosome1.length();
}

// Define a function to check if two animals are of the same species
bool operator==(const Animal& animal1, const Animal& animal2) {
    if (animal1.getChromosomes().size() != animal2.getChromosomes().size()) {
        return false;
    }
    double similarityThreshold = 0.7;  // Adjust this as desired
    for (int i = 0; i < animal1.getChromosomes().size(); i++) {
        double similarity = calculateGeneticSimilarity(animal1.getChromosomes()[i], animal2.getChromosomes()[i]);
        if (similarity < similarityThreshold) {
            return false;
        }
    }
    return true;
}

// Define a function to generate a new asexual offspring from a single parent
Animal generateAsexualOffspring(const Animal& parent) {
    std::vector<std::string> parentChromosomes = parent.getChromosomes();
    std::vector<std::string> offspringChromosomes = parentChromosomes;
    int numChromosomes = parentChromosomes.size();
    int numInheritedChromosomes = numChromosomes / 2;
    std::uniform_int_distribution<int> dist(0, numChromosomes - 1);
    for (int i = 0; i < numInheritedChromosomes; i++) {
        int index = dist(rng);
        offspringChromosomes[index] = parentChromosomes[index];
    }
    return Animal(offspringChromosomes);
}

// Define a function to generate a new sexual offspring from two parents
Animal generateSexualOffspring(const Animal& parent1, const Animal& parent2) {
    if (parent1.getChromosomes().size() != parent2.getChromosomes().size()) {
        throw std::invalid_argument("Parents must have the same number of chromosomes");
    }
    std::vector<std::string> parent1Chromosomes = parent1.getChromosomes();
    std::vector<std::string> parent2Chromosomes = parent2.getChromosomes();
    std::vector<std::string> offspringChromosomes;
    int numChromosomes = parent1Chromosomes.size();
    int numInheritedChromosomes = numChromosomes / 2;
    std::uniform_int_distribution<int> dist(0, numChromosomes - 1);
    for (int i = 0; i < numInheritedChromosomes; i++) {
        int index = dist(rng);
        offspringChromosomes.push_back(parent1Chromosomes[index]);
    }
    for (int i = 0; i < numInheritedChromosomes; i++) {
        int index = dist(rng);
        offspringCh