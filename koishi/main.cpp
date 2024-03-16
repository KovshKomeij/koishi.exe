#include <iostream>
#include <thread>
#include <cstdlib>
#include <Windows.h>

using namespace std;

bool running = true;
int seconds = 0;

void timelater() {
	while (true) {
		Sleep(1000);
		seconds++;
		if (!running) {
			break;
		}
	}
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	thread t(timelater);
	t.detach();

	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC);

	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);

	// Это то что сгенерировал ChatGPT

	HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, TEXT("pic1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	BITMAP bm;
	GetObject(hBitmap, sizeof(BITMAP), &bm);
	int width = bm.bmWidth;
	int height = bm.bmHeight;

	HDC hdcBitmap = CreateCompatibleDC(NULL);
	HGDIOBJ hOldBitmap = SelectObject(hdcBitmap, hBitmap);

	// Дальше я сам писал этот треш

	while (true) {
		BitBlt(hdc, rand() % w, rand() % h, width, height, hdcBitmap, 0, 0, SRCCOPY);
		Sleep(250);

		if (seconds >= 20) {
			break;
		}
	}

	while (true) {
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
		BitBlt(hdc, rand() % w, rand() % h, rand() % w, rand() % h, hdc, rand() % w, rand() % h, NOTSRCCOPY);
		
		Sleep(50);

		if (seconds >= 32) {
			break;
		}
	}

	while (true) {
		BitBlt(hdc, rand() % w, rand() % h, width, height, hdcBitmap, 0, 0, SRCCOPY);
		Sleep(250);

		if (seconds >= 62) {
			break;
		}
	}

	while (true) {
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
		BitBlt(hdc, rand() % w, rand() % h, rand() % w, rand() % h, hdc, rand() % w, rand() % h, NOTSRCCOPY);
		Sleep(50);

		if (seconds >= 74) {
			break;
		}
	}

	while (true) {
		BitBlt(hdc, rand() % w, rand() % h, width, height, hdcBitmap, 0, 0, SRCCOPY);
		Sleep(250);

		if (seconds >= 97) {
			running = false;
			break;
		}
	}

	return 0;
}