
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
void clearMemory(int N, T **&tab);
template <typename T>
void allocMemory(int N, T **&tab);

void parseMatrix(int N, bool ** &Grill__);
void parseMsg(int N, char ** &Msg_);
void decodeMsg(int N, bool ** &Grill_, char ** &Msg_, std::string& decoded);
void rotateMatrix(int N, bool ** &Grill_);


int main()
{
	std::ifstream inf;
	//std::istream&in = inf;				// Section dealing with console/file i/o
	std::istream&in = std::cin;

	int N = 0;
	std::string decoded = "";
	std::cin >> N;

	while (N != 0) {
		bool ** Grill;
		allocMemory(N, Grill);

		char ** Msg;
		allocMemory(N, Msg);

		parseMatrix(N, Grill);
		parseMsg(N, Msg);
		decodeMsg(N, Grill, Msg, decoded);

		clearMemory(N, Grill);
		clearMemory(N, Msg);

		std::cout << decoded << std::endl;
		decoded = "";
		in >> N;
	}


}

void parseMatrix(int N, bool ** &Grill_) {
	char temp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> temp;
			if (temp == '#')
				*(*(Grill_ + i) + j) = true;
			else
				*(*(Grill_ + i) + j) = false;

		}
	}

}

void parseMsg(int N, char ** &Msg_) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> *(*(Msg_ + i) + j);
		}
	}
}

void decodeMsg(int N, bool ** &Grill_, char ** &Msg_, std::string& decoded) {

	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (*(*(Grill_ + i) + j) == false)
					decoded += *(*(Msg_ + i) + j);
			}
		}
		rotateMatrix(N, Grill_);
	}
}

void rotateMatrix(int N, bool ** &Grill_) {

	bool ** tempMatrix;
	allocMemory(N, tempMatrix);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(*(tempMatrix + j) + (N - i - 1)) = *(*(Grill_ + i) + j);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(*(Grill_ + i) + j) = *(*(tempMatrix + i) + j);
		}
	}

	clearMemory(N, tempMatrix);
}

template <typename T>
void clearMemory(int N, T **&tab) {

	for (int i = 0; i < N; i++) {
		delete[]tab[i];
	}
	delete[]tab;
}

template <typename T>
void allocMemory(int N, T **&tab) {

	tab = new T*[N];
	for (int i = 0; i < N; i++) {
		tab[i] = new T[N];
	}

}