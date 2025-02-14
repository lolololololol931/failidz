#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//n1
void compFiles(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    string line1, line2;
    bool match = true;

    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Рядки не співпадають:\n";
            cout << "Файл 1: " << line1 << "\nФайл 2: " << line2 << "\n";
            match = false;
        }
    }
    while (getline(f1, line1)) {
        cout << "Файл 1 містить додатковий рядок: " << line1 << "\n";
        match = false;
    }
    while (getline(f2, line2)) {
        cout << "Файл 2 містить додатковий рядок: " << line2 << "\n";
        match = false;
    }
    if (match) cout << "Файли ідентичні." << endl;
}

//n2
void findCol(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);
    string line;
    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;

    while (getline(fin, line)) {
        lineCount++;
        for (char с : line) {
            if (isalpha(с)) {
                с = tolower(с);
                if (string("aeiouаеєиіїоуюя").find(с) != string::npos)
                    vowelCount++;
                else
                    consonantCount++;
            }
            else if (isdigit(с)) {
                digitCount++;
            }
            charCount++;
        }
        charCount++; 
    }
    fout << "Кількість символів: " << charCount << "\n";
    fout << "Кількість рядків: " << lineCount << "\n";
    fout << "Кількість голосних: " << vowelCount << "\n";
    fout << "Кількість приголосних: " << consonantCount << "\n";
    fout << "Кількість цифр: " << digitCount << "\n";
}
//n3
void remove(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    vector<string> lines;
    string line;

    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    ofstream fout(outputFile);
    for (size_t i = 0; i < lines.size() - 1; ++i) {
        fout << lines[i] << "\n";
    }
}

//n4
void longest(const string& inputFile) {
    ifstream fin(inputFile);
    string line;
    size_t maxLength = 0;

    while (getline(fin, line)) {
        maxLength = max(maxLength, line.length());
    }
    cout << "Довжина найдовшого рядка: " << maxLength << endl;
}

int main() {
    system("chcp 1251>nul");
    ifstream f1("file1.txt"), f2("file2.txt"), f3("input.txt");
    ofstream f4("stats.txt"),f5("output.txt");
    if (!f1 || !f2) {
        cout << "помилка" << endl;
        return 1;
    }
    if (!f3) {
        cout << "файл відсутній" << endl;
        return 1;
    }
    cout << "N1:" << endl;
    compFiles("file1.txt", "file2.txt");
    cout << "N2:" << endl;
    findCol("input.txt", "stats.txt");
    cout << "N3:" << endl;
    remove("input.txt", "output.txt");
    cout << "N4:" << endl;
    longest("input.txt");
    return 0;
}