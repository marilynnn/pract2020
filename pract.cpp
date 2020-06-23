#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <ctime>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void wait(int seconds) // в зависимости от параметра seconds будет изменяться частота вывода строк
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	std::ifstream out(argv[1]); //открываем файл с нужным выводом
		
	int Time = atoi(argv[2]);

	char* buf = new char[1024];
	while (Time!=0) {
		out.getline(buf, 512);
		cout << buf << endl;
		wait(1);			
		Time--;
		if (out.eof()) {
			out.seekg(0);
		}
    }
	out.close();
	delete[] buf;

	time_t now = time(0);
	tm* ltm = localtime(&now);

	cout << 1 + ltm->tm_hour << ":"
		<< 1 + ltm->tm_min << ":"
		<< 1 + ltm->tm_sec << ":  "
		<< "Процесс *** завершился успешно.";
		

	     fs::copy_file(argv[3],argv[4]);
		 // перемещение нужного .exe в директорию

}