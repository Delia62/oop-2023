#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <string.h>
#include <map>
#include <string>
using namespace std;

class CommandManager {
  private:
    map<string, function<void(vector<string>)>> commands;

  public:
    void add(string name, function<void(vector<string>)> fn);
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    vector<string> args;
    while (true) {
        string line;
        getline(cin, line);

        if (line.empty())
            continue;

        size_t pos = 0;
        string delimiter = " ";
        while ((pos = line.find(delimiter)) != string::npos) {
            args.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
        }
        args.push_back(line);

        string cmd = args[0];
        args.erase(args.begin());

        if (cmd == "stop") {
            return;
        }

        auto it = commands.find(cmd);
        if (it == commands.end()) {
            printf("command not found: %s\n", cmd.c_str());
        } else {
            try {
                it->second(args);
            } catch (exception& e) {
                printf("exception: %s\n", e.what());
            }
        }
    }
}
class FileException : public exception {
  private:
    string fileName;
    string message;

  public:
    FileException(const string& filename, const string& message) : fileName(filename), message(message) {
    }

    const char* what() const throw() {
        return (fileName + ": " + message).c_str();
    }
};

int main() {
    CommandManager manager;

    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](vector<string> args) { printf("counted %d args\n", args.size()); };
    manager.add("count", count);

    auto times = [n = 0](vector<string> args) mutable {
        n++;
        printf("times called: %d\n", n);
    };
    manager.add("times", times);

    auto copy = [](vector<string> args) {
        if (args.size() != 2) {
            printf("Expected: copy <source> <destination>\n");
            return;
        }
        string source = args[0];
        string destination = args[1];

        ifstream Source(source, ios::binary);
        ofstream dest(destination, ios::binary);

        if (!Source) {
            throw FileException(source, "Could not open file for reading");
        }

        if (!dest) {
            throw FileException(destination, "Could not open file for writing");
        }
        char c;
        int ok = 1;
        while (Source.get(c) && ok == 1) {
            if (c < 32 || c > 126) {
                ok = 0;
            }
        }
        Source.close();

        if (ok == 1) { // este fisier text
            Source.open(source, ios::in);
            string line;
            while (getline(Source, line)) {
                dest << line << endl;
            }
        } else { // este fisier binar
            Source.open(source, ios::binary);
            char* buffer = (char*) malloc(2048 * sizeof(char));
            //char buffer[2048]; asa nu imi copie poza in intregime
            while (Source.read(buffer, sizeof(buffer))) {
                dest.write(buffer, Source.gcount());
            }
        }

        Source.close();
        dest.close();
        printf("Copied %s to %s\n", source.c_str(), destination.c_str());
    };
    manager.add("copy", copy);

    // add one more command of anything you'd like
    auto allocate = [](vector<string> args) {
        int size = stoi(args[0]);
        printf("allocating %d bytes\n", size);
        int* ptr = new int[size];
        delete[] ptr;
    };
    manager.add("allocate", allocate);
    manager.run();

    printf("goodbye.\n");
}