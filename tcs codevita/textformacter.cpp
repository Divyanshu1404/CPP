#include <bits/stdc++.h>
using namespace std;

bool isEmailOrUrl(const string &word) {
    return word.find('@') != string::npos ||
           word.rfind("http://", 0) == 0 ||
           word.rfind("https://", 0) == 0;
}

bool isBullet(const string &word) {
    if (word == "*" || word == "-") return true;
    if (word.size() >= 2 && isdigit(word[0]) && (word[1] == '.' || word[1] == ')')) return true;
    return false;
}

vector<string> splitWords(const string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

void printFormatted(vector<string> words, int evenWidth, int oddWidth, bool hyphen, vector<string> &result) {
    string currentLine;
    int lineIndex = 0;
    int i = 0;

    while (i < (int)words.size()) {
        string w = words[i];
        int width = (lineIndex % 2 == 0 ? evenWidth : oddWidth);

        // Handle bullets
        if (isBullet(w)) {
            if (!currentLine.empty()) {
                result.push_back(currentLine);
                currentLine.clear();
                lineIndex++;
            }
            currentLine = w + " ";
            i++;
            continue;
        }

        // Handle emails/URLs — never split
        if (isEmailOrUrl(w)) {
            if (!currentLine.empty() && (int)currentLine.size() + 1 + (int)w.size() > width) {
                result.push_back(currentLine);
                currentLine.clear();
                lineIndex++;
            }
            if (!currentLine.empty()) currentLine += " ";
            currentLine += w;
            i++;
            continue;
        }

        int available = width - (int)currentLine.size() - (currentLine.empty() ? 0 : 1);

        // Fits normally
        if ((int)w.size() <= available) {
            if (!currentLine.empty()) currentLine += " ";
            currentLine += w;
            i++;
            continue;
        }

        // Hyphenation for long words
        if (hyphen && (int)w.size() > width) {
            if (available > 1) {
                // Split and move remainder to next iteration
                int cut = max(1, available - 1);
                string part1 = w.substr(0, cut) + "-";
                string part2 = w.substr(cut);
                if (!currentLine.empty()) currentLine += " ";
                currentLine += part1;
                result.push_back(currentLine);
                currentLine.clear();
                lineIndex++;
                // Replace current word with remaining part
                words.insert(words.begin() + i + 1, part2);
                i++;
                continue;
            } else {
                // No space left — new line
                if (!currentLine.empty()) {
                    result.push_back(currentLine);
                    currentLine.clear();
                    lineIndex++;
                } else {
                    int cut = width - 1;
                    string part1 = w.substr(0, cut) + "-";
                    string part2 = w.substr(cut);
                    result.push_back(part1);
                    lineIndex++;
                    words.insert(words.begin() + i + 1, part2);
                    i++;
                }
                continue;
            }
        }

        // If no hyphenation possible, move word to next line
        if (!currentLine.empty()) {
            result.push_back(currentLine);
            currentLine.clear();
            lineIndex++;
        } else {
            currentLine = w;
            i++;
        }
    }

    if (!currentLine.empty()) result.push_back(currentLine);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    vector<string> inputLines;
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        inputLines.push_back(line);
    }

    string cmd;
    getline(cin, cmd);

    int evenWidth = 75, oddWidth = 75;
    bool hyphen = false;

    vector<string> cmdWords = splitWords(cmd);
    for (size_t i = 0; i < cmdWords.size(); i++) {
        if (cmdWords[i] == "-w" && i + 1 < cmdWords.size())
            evenWidth = oddWidth = stoi(cmdWords[++i]);
        else if (cmdWords[i] == "-w-e" && i + 1 < cmdWords.size())
            evenWidth = stoi(cmdWords[++i]);
        else if (cmdWords[i] == "-w-o" && i + 1 < cmdWords.size())
            oddWidth = stoi(cmdWords[++i]);
        else if (cmdWords[i] == "h")
            hyphen = true;
    }

    // Paragraph handling
    vector<vector<string>> paragraphs;
    vector<string> currentParagraph;

    for (auto &line : inputLines) {
        if (line.find_first_not_of(" \t\r\n") == string::npos) {
            if (!currentParagraph.empty()) {
                paragraphs.push_back(currentParagraph);
                currentParagraph.clear();
            }
        } else {
            vector<string> words = splitWords(line);
            currentParagraph.insert(currentParagraph.end(), words.begin(), words.end());
        }
    }
    if (!currentParagraph.empty()) paragraphs.push_back(currentParagraph);

    vector<string> finalOutput;
    for (size_t p = 0; p < paragraphs.size(); p++) {
        vector<string> formatted;
        printFormatted(paragraphs[p], evenWidth, oddWidth, hyphen, formatted);
        for (auto &line : formatted) finalOutput.push_back(line);
        if (p != paragraphs.size() - 1) finalOutput.push_back("");
    }

    for (size_t i = 0; i < finalOutput.size(); i++) {
        cout << finalOutput[i];
        if (i != finalOutput.size() - 1) cout << "\n";
    }

    return 0;
}