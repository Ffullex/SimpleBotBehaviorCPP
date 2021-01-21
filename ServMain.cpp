#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

// Принимает на вход строку, трансформирует в нижний регистр
string to_lower(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

// База вопросов и ответов
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

// Получает вопрос от пользователя и возвращает его
string userQuestion() {
	string question;
	cout << "[User]: ";
	getline(cin, question);
	question = to_lower(question);
	return question; 
}

// Проверка на выражения выхода
bool isExit(string text) {
	for (auto phrase : exitPhrases) {
		regex expression = regex(".*" + phrase + ".*");
		if (regex_match(text, expression)) {
			botSay("OK, bye");
			return true; // Этот текст содержит фразу для выхода
		}
	}
	return false;
}

// Возвращает ответ на вопрос question
void botAnswer(string question) {
	bool foundAnswer = false; // Найден ли ответ
	for (auto entry : knowledge) { // Для каждой записи в базе
		//entry.first 
		//entry.second
		regex expression = regex(".*" + entry.first + ".*");
		if (regex_match(question, expression)) { // Если совпадает
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
	while (!isExit(question)) { // Пока текст вопроса не содержит фразу для выхода
		question = userQuestion(); // Получение вопроса от пользователя
		botAnswer(question); // Обработка и получение ответа от бота
	}
}