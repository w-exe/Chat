/*The main file where the program starts and stops working.*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <list>

using namespace std;

/*Clients imitation*/
void client(string path, list<int> times, list<string> messages) {
	string message = messages.front();
	messages.pop_front();
	int time = times.front();
	times.pop_front();

	if (false == times.empty()) {
		client(path, times, messages);
	}

	for (int i = 0; i < 10; i++) {
		ofstream fout; // file content
		SYSTEMTIME st; //system time
		GetLocalTime(&st);

		/*opens the file for add text to the end of the file*/
		fout.open(path, ios::app);

		if (fout.is_open()) {
			fout << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " " << message << endl;
		}
		
		/*closes the file*/
		fout.close(); // закрываем файл

		Sleep(time);
	}
}

int main() {
	string path = "C:/newfolder/myfile.txt"; // file location and name
	int clients = 2; // number of clients
	list<int> times = {}; // time delays (in seconds)
	list<string> messages = {}; // message lines
	int time;
	string message;

	/*data input*/
	cout << "Please enter the path to the file:" << endl;
	cin >> path; // EXAMPLE C:/newfolder/myfile.txt
	cout << "...number of clients:" << endl;
	cin >> clients; // EXAMPLE 2

	while (clients > 0) {
		clients--;
		cout << "...time delay :" << endl;
		cin >> time; // EXAMPLE 5
		time = time * 1000;
		times.push_back(time);
		cout << "...message line:" << endl;
		cin >> message; // Hi!
		messages.push_back(message);
	}

	client(path, times, messages);

	return 0;
}