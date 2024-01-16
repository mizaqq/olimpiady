#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
namespace fs = std::filesystem;

using namespace std;


int program(vector<int>values) {
    const int MM = 1e5 + 13;
    int tab[MM];
    vector<int> czas;

    int n=values[0];
    
    for (int i = 0; i < n; i++) {
        tab[i]=values[i+1];
    }
    czas.push_back(tab[0]);
    czas.push_back(tab[1]);
    czas.push_back(tab[0] + tab[1] + tab[2]);

    int a, b;
    for (int i = 3; i < n; i++) {
        a = czas[i - 2] + tab[0] + 2 * tab[1] + tab[i];
        b = czas[i - 1] + tab[0] + tab[i];
        czas.push_back(min(a, b));
    }
    if (n == 1) {
        return  tab[0];
    }
    else if (n == 2) {
        return  czas[1];
    }
    else if (n == 3) {
        return  czas[2];
    }
    else {
        return czas[czas.size() - 1];
    }

}

int main()
{
	//nazwa zadania
	string zadanie = "Most";
//inputs
	string folderPath = "C://Users//zarbe//source//repos//olimpiady//checkcorrect//"+zadanie;
    vector<string> tabin;
    string s;
    try {
        // Iterate through the files in the folder
        for (const auto& entry : fs::directory_iterator(folderPath))
            if (entry.path().extension() == ".in") {
               s=entry.path().stem().string();
               tabin.push_back(s);
            }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing the folder: " << e.what() << std::endl;
        return 1;
    }
    string filePath;
    string filePath2;
    int value;
    int answer;
    vector<int>fileValues;
    vector<int>fileAnswers;
    vector<int> response;
    bool f = true;
    for (const auto& element : tabin) {
        filePath = folderPath +"//" + element + ".in";
        ifstream inputFile(filePath);
        while (inputFile >> value) {
            fileValues.push_back(value);
        }
        inputFile.close();
        
        response.push_back(program(fileValues));

        filePath2 = folderPath + "//" + element + ".out";
        ifstream inputFile2(filePath2);
        while (inputFile2 >> answer) {
            fileAnswers.push_back(answer);
        }
        inputFile2.close();
        
        for (int i = 0; i < fileAnswers.size(); i++) {
            if (fileAnswers[i] != response[i]) {
                cout << element<<" Wynik niepoprawny Twoj: " << response[i] << " oczekiwany: " << fileAnswers[i] << endl;
                f = false;
            }
        }
        if (f == true) {
            cout << element << " Wynik poprawny" << endl;
        }
        f = true;
        fileValues.clear();
        response.clear();
        fileAnswers.clear();
    }
}

