/*The main file where the program starts and stops working.*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <list>

using namespace std;

/*The function Client recursively calls the same function
	until it creates the required number of chat participants*/
void client(int clients, string path, list<int> times, list<string> messages) {
	string message = messages.front();
	messages.pop_front();
	int time = times.front();
	times.pop_front();

	int myNum = clients;

	if (clients > 1) {
		--clients;
		/*recursion*/
		client(clients, path, times, messages);
	}

	for (int i = 0; i < 10; i++) {
		ofstream fout; // file content
		SYSTEMTIME st; //system time
		GetLocalTime(&st);

		/*opens the file for add text to the end of the file*/
		fout.open(path, ios::app);

		if (fout.is_open()) {
			fout << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "; "
				<< myNum << ": " << message << endl;
		}

		/*closes the file*/
		fout.close();

		Sleep(time);
	}
}

int main() {
	string path; // file location and name like = "C:/newfolder/myfile.txt"
	int clients; // number of clients
	list<int> times = {}; // time delays (in seconds)
	list<string> messages = {}; // message lines
	int time;
	string message;

	/*data input*/
	cout << "Please enter the path to the file:" << endl;
	cin >> path; // EXAMPLE C:/newfolder/myfile.txt
	cout << "...number of clients:" << endl;
	cin >> clients; // EXAMPLE 2

	for (int c = clients; c > 0; c--) {
		cout << "...time delay :" << endl;
		cin >> time; // EXAMPLE 5
		time = time * 1000;
		times.push_back(time);
		cout << "...message line:" << endl;
		cin >> message; // Hi!
		messages.push_back(message);
	}

	client(clients, path, times, messages);

	return 0;
}
