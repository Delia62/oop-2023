#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CsvIterator {
    vector<vector<string>>& myString;
    int size;

  public:
    CsvIterator(vector<vector<string>>& myString, int size) : myString(myString), size(size) {
    }

    bool operator!=(const CsvIterator& other) {
        return size != other.size;
    }

    CsvIterator& operator++() {
        size++;
        return *this;
    }

    vector<string> operator*() {
        return myString[size];
    }
};

class CsvReader {
    ifstream& file;
    vector<vector<string>> myString;

  public:
    CsvReader(ifstream& file) : file(file) {
        Read();
    }

    vector<string> split(string s) {
        vector<string> v;
        string s2;

        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == '"') {
                i++;
                while (s[i] != '"') {
                    s2 += s[i];
                    i++;
                }
                v.push_back(s2);
                s2.resize(0);
            }

            else {
                if (s[i] == ',' || i == s.size()) {
                    v.push_back(s2);
                    s2.resize(0);
                } else {
                    s2 += s[i];
                }
            }
        }
        return v;
    }

    void Read() {
        string line;
        while (getline(file, line)) {
            myString.push_back(split(line));
        }
    }

    CsvIterator begin() {
        return { myString, 0 };
    }

    CsvIterator end() {
        return { myString, (int) myString.size() };
    }
};
struct Episode {
    string title;
    struct Data {
        int zi = 0;
        int luna = 0;
        int an = 0;
    } data;
    struct Time {
        int minute = 0;
        int secunde = 0;
    } timp;
    float vizionari = 0;
    int scor = 0;
} s[500], cop;

string title;
string date;
string length;
vector<Episode> episodes;

void Top_10_apreciate() {
    for (int i = 1; i < episodes.size() - 1; i++) {
        for (int j = i + 1; j < episodes.size(); j++) {
            if (episodes[i].scor < episodes[j].scor) {
                cop = episodes[i];
                episodes[i] = episodes[j];
                episodes[j] = cop;
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        cout << "i. " << episodes[i].scor << " -> " << episodes[i].title << endl;
    }
}
void Top_10_longest() {
    for (int i = 1; i < episodes.size() - 1; i++) {
        for (int j = i + 1; j < episodes.size(); j++) {
            if (episodes[i].timp.minute < episodes[j].timp.minute) {
                if (episodes[i].timp.secunde < episodes[j].timp.secunde) {
                    cop = episodes[i];
                    episodes[i] = episodes[j];
                    episodes[j] = cop;
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        cout << "i. " << episodes[i].timp.minute << "m" << episodes[i].timp.secunde << "s"
             << " -> " << episodes[i].title << endl;
    }
}
void Most_episodes() {
    int carac[2023], max = 0, index;
    for (int i = 1; i < episodes.size() - 1; i++) {
        carac[episodes[i].data.an]++;
        if (carac[episodes[i].data.an] > max) {
            max = carac[episodes[i].data.an];
            index = episodes[i].data.an;
        }
    }
    cout << "The year " << index << " has the most episodes: " << max;
}

int main() {
    ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    int m = 0;
    for (vector<string> columns : reader) {
        // Transform the columns into an Episode and push it in a vector
        title = columns[0];
        s[m++].title = title;
        date = columns[1];
        char n1[4], n2[2], n3[2];
        int i = 0, j = 0, k = 0, l = 0;
        while (date[i] != '-') {
            if (date[i] != '0') {
                n1[j++] = date[i];
            }
            i++;
        }
        i++;
        while (date[i] != '-') {
            if (date[i] != '0') {
                n2[k++] = date[i];
            }
            i++;
        }
        if (date[i] == '-') {
            i++;
            while (i < date.size()) {
                if (date[i] != '0') {
                    n3[l++] = date[i];
                }
                i++;
            }
        }
        s[m].data.an = stoi(n1);
        s[m].data.luna = stoi(n2);
        s[m].data.zi = stoi(n3);

        length = columns[2];
        char n4[2], n5[2];
        i = 0;
        j = 0;
        k = 0;
        while (length[i] != ':') {
            if (length[i] != '0') {
                n4[j++] = length[i];
            }
            i++;
        }
        if (length[i] == ':') {
            i++;
            while (i < length.size()) {
                if (length[i] != '0') {
                    n5[k++] = length[i];
                }
                i++;
            }
        }
        s[m].timp.minute = stoi(n4);
        s[m].timp.secunde = stoi(n5);

        s[m].vizionari = stof(columns[3]);

        s[m].scor = stoi(columns[4]);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    ofstream output_file("output.txt");

    for (auto& [title, date, length, viewersmm, score] : episodes) {
        // Pretty print the episode in the output file
        for (int i = 1; i < episodes.size(); i++) {
            output_file << "EPISODE " << i << " LOOKS THIS WAY:"
                        << "\n";
            output_file << "The title is: " << title << "\n";
            // output_file << "The date is: " << data << "\n";
            // output_file << "The length is: " << length << "\n";
            output_file << "The viewersmm is: " << viewersmm << "\n";
            output_file << "The score is: " << score << "\n";
            output_file << "************************************************************************"
                        << "\n";
        }
    }
    cout << "The most appreciated episodes:";
    Top_10_apreciate();
    cout << "The longest episodes:";
    Top_10_longest();
    Most_episodes();
}
