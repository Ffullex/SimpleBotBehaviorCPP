#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

// ��������� �� ���� ������, �������������� � ������ �������
string to_lower(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

// ���� �������� � �������
map<string, string> knowledge = { 
	{"hello", "Oh, hello human!"},
	{"how are you", "Not too bad for a machine"},
	{"what is your name","My creator gave me name ChatBot3000"},
	{"what you up to","Answering stupid questions"}
};

string exitPhrases[] = {"exit", "bye", "have a good day "};

void botSay(string text) {
	cout << "[BOT]: " << text << "\n";
}

// �������� ������ �� ������������ � ���������� ���
string userQuestion() {
	string question;
	cout << "[User]: ";
	getline(cin, question);
	question = to_lower(question);
	return question; 
}

// �������� �� ��������� ������
bool isExit(string text) {
	for (auto phrase : exitPhrases) {
		regex expression = regex(".*" + phrase + ".*");
		if (regex_match(text, expression)) {
			botSay("OK, bye");
			return true; // ���� ����� �������� ����� ��� ������
		}
	}
	return false;
}

// ���������� ����� �� ������ question
void botAnswer(string question) {
	bool foundAnswer = false; // ������ �� �����
	for (auto entry : knowledge) { // ��� ������ ������ � ����
		//entry.first 
		//entry.second
		regex expression = regex(".*" + entry.first + ".*");
		if (regex_match(question, expression)) { // ���� ���������
			botSay(entry.second);
			foundAnswer = true;
		}
	}
	if (!foundAnswer){
		botSay("Do not comprende");
	}
}

int main() 
{
	cout << "Hello, welcome to ChatBot3000!\n";
	
	string question;
	while (!isExit(question)) { // ���� ����� ������� �� �������� ����� ��� ������
		question = userQuestion(); // ��������� ������� �� ������������
		botAnswer(question); // ��������� � ��������� ������ �� ����
	}
}