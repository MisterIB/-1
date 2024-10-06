#include <fstream>
#include <string>

#include "ForwardList.h"
#include "List.h"
#include "Array.h"
#include "Queue.h"
#include "Stack.h"
#include "Hash.h"
#include "CompleteBinaryTree.h"

using namespace std;

struct Data {
    string command;
    string nameStructure;
    string value = "NULL";
    string key = "NULL";
};

void chekTheOpenFile(ifstream& file) {
    if (!file.is_open()) throw runtime_error("Error open file");
}

void chekTheOpenFile(ofstream& file) {
    if (!file.is_open()) throw runtime_error("Error open file");
}

void writeToFileFrwdList(const string& nameFile, ForwardList<string>& myFrwdList) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myFrwdList.printInFile(dataFile);
    dataFile.close();
}

void writeToFileList(const string& nameFile, List<string>& myList) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myList.printInFile(dataFile);
    dataFile.close();
}

void writeToFileArray(const string& nameFile, Array<string>& myArray) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myArray.printInFile(dataFile);
    dataFile.close();
}

void writeToFileStack(const string& nameFile, Stack<string>& myStack) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myStack.printInFile(dataFile);
    dataFile.close();
}

void writeToFileQueue(const string& nameFile, Queue<string>& myQueue) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myQueue.printInFile(dataFile);
    dataFile.close();
}

void writeToFileHash(const string& nameFile, Hash<string>& myHash) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myHash.printInFile(dataFile);
    dataFile.close();
}

void writeToFileTree(const string& nameFile, CompleteBinaryTree<string>& myTree) {
    ofstream dataFile(nameFile);
    chekTheOpenFile(dataFile);
    myTree.printInFile(dataFile);
    dataFile.close();
}

void performingAnActionFrwdList(const Data& data, ForwardList<string>& myFrwdList) {//Проверка на не ту команду
    if (data.command == "LPUSH_BACK") myFrwdList.push_back(data.value);
    if (data.command == "LPUSH_FRONT") myFrwdList.push_front(data.value);
    if (data.command == "LDEL_BACK") myFrwdList.remove_back();
    if (data.command == "LDEL_FRONT") myFrwdList.remove_front();
    if (data.command == "LGET") cout << myFrwdList.find(data.value);
    if (data.command == "PRINT") myFrwdList.print();
}

void performingAnActionList(const Data& data, List<string>& myList) {
    if (data.command == "LPUSH_BACK") myList.push_back(data.value);
    if (data.command == "LPUSH_FRONT") myList.push_front(data.value);
    if (data.command == "LDEL_BACK") myList.remove_back();
    if (data.command == "LDEL_FRONT") myList.remove_front();
    if (data.command == "LGET") cout << myList.find(data.value);
    if (data.command == "PRINT") myList.print();
}

void performingAnActionStack(const Data& data, Stack<string>& myStack) {
    if (data.command == "SPUSH") myStack.push(data.value);
    if (data.command == "SPOP") cout << myStack.pop();
    if (data.command == "PRINT") myStack.print();
}

void performingAnActionQueue(const Data& data, Queue<string>& myQueue) {
    if (data.command == "QPUSH") myQueue.push(data.value);
    if (data.command == "QPOP") cout << myQueue.pop();
    if (data.command == "PRINT") myQueue.print();
}

void performingAnActionArray(const Data& data, Array<string>& myArray) {
    if (data.command == "MPUSH") myArray.push_back(data.value);
    if (data.command == "MDEL") myArray.erase(stoi(data.value));
    if (data.command == "MGET") cout << myArray[stoi(data.value)];
    if (data.command == "PRINT") myArray.print();
}

void performingAnActionHash(const Data& data, Hash<string>& myHash) {
    if (data.command == "HSET") myHash.HSET(data.key, data.value);
    if (data.command == "HDEL") myHash.HDEL(data.value);
    if (data.command == "PRINT") myHash.print();
    if (data.command == "HGET") cout << myHash.HGET(data.value);
}

void performingAnActionTree(const Data& data, CompleteBinaryTree<string>& myTree) {
    if (data.command == "TINSERT") myTree.TINSERT(data.value);
    if (data.command == "TDEL") myTree.TDEL();
    if (data.command == "TCHEK") cout << "true";
    if (data.command == "PRINT") myTree.print();
}

void readFromFileInFrwdList(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    ForwardList<string> myFrwdList;
    while (fileData >> item) myFrwdList.push_back(item);
    fileData.close();
    performingAnActionFrwdList(data, myFrwdList);
    writeToFileFrwdList(nameFile, myFrwdList);
}

void readFromFileInList(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    List<string> myList;
    while (fileData >> item) myList.push_back(item);
    fileData.close();
    performingAnActionList(data, myList);
    writeToFileList(nameFile, myList);
}

void readFromFileInArray(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    Array<string> myArray;
    while (fileData >> item) myArray.push_back(item);
    fileData.close();
    performingAnActionArray(data, myArray);
    writeToFileArray(nameFile, myArray);
}

void readFromFileInStack(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    Stack<string> myStack;
    while (fileData >> item) myStack.push(item);
    fileData.close();
    performingAnActionStack(data, myStack);
    writeToFileStack(nameFile, myStack);
}

void readFromFileInQueue(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    Queue<string> myQueue;
    while (fileData >> item) myQueue.push(item);
    fileData.close();
    performingAnActionQueue(data, myQueue);
    writeToFileQueue(nameFile, myQueue);
}

void readFromFileInHash(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string key, value;
    Hash<string> myHash;
    while (fileData >> key and fileData >> value) myHash.HSET(key, value);
    fileData.close();
    performingAnActionHash(data, myHash);
    writeToFileHash(nameFile, myHash);
}

void readFromFileInBinTree(const string& nameFile, const Data& data) {
    ifstream fileData(nameFile);
    chekTheOpenFile(fileData);
    string item;
    CompleteBinaryTree<string> myTree;
    while (fileData >> item) myTree.TINSERT(item);
    fileData.close();
    performingAnActionTree(data, myTree);
    writeToFileTree(nameFile, myTree);
}

void readStructureView(const string& nameFile, const Data& data) {
    if (data.nameStructure == "ForwardList") readFromFileInFrwdList(nameFile, data);
    else if (data.nameStructure == "List") readFromFileInList(nameFile, data);
    else if (data.nameStructure == "Array") readFromFileInArray(nameFile, data);
    else if (data.nameStructure == "Stack") readFromFileInStack(nameFile, data);
    else if (data.nameStructure == "Queue") readFromFileInQueue(nameFile, data);
    else if (data.nameStructure == "Hash") readFromFileInHash(nameFile, data);
    else if (data.nameStructure == "CompleteBinaryTree") readFromFileInBinTree(nameFile, data);
    else throw runtime_error("The structure was entered incorrectly");
}

void checkForExtraCharacters(Data& data) {
    if (data.command[0] == '\'') data.command.erase(0, 1);
    if (data.value[data.value.size() - 1] == '\'') data.value.erase(data.value.size() - 1);
    if (data.key[data.key.size() - 1] == '\'') data.key.erase(data.key.size() - 1);
}

void readInputData(Data& data, string inputData) {
    string name;
    int32_t i = 0;
    for (unsigned char character : inputData) {
        if (character == ' ') {
            if (i == 0) data.command = name;
            if (i == 1) data.nameStructure = name;
            if (i == 2) data.value = name;
            name = "";
            i++;
        }
        else name += character;
    }
    if (i == 1) data.nameStructure = name;
    if (i == 2) data.value = name;
    if (i == 3) data.key = name;
}

void handlingCommand(int argc, const char** argv) {
    string nameFile;
    Data data;
    for (int32_t i = 0; i < argc; i++) {
        string str = argv[i];
        if (str == "--file" and i + 1 < argc) {
            nameFile = argv[i + 1];
        }
        if (str == "--query" and i + 1 < argc) {
            readInputData(data, argv[i + 1]);
        }
    }
    checkForExtraCharacters(data);
    readStructureView(nameFile, data);
}

int main(int argc, const char** argv) {
    try {
        handlingCommand(argc, argv);
    }
    catch (exception& e) {
        cout << e.what();
    }
}
