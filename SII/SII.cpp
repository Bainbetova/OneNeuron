// SII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

// глобальные переменные
char* docs[60];
float vectors[60][256];
float w[256];
float final_w[256];
float neuron[256];

// прототипы функций
void start();
void readFile_docs();
void files_docs();
void start_w();
int raschet();

int main()
{
	start();
	files_docs();	
	readFile_docs();
	start_w();
	// если не получится, то сперва посчитать, а потом только исправлять коэф
	int count = raschet();
	 
	while (count <= 50) {
		count = raschet();
	}
	
	for (int r = 0; r < 256; r++) {
		final_w[r] = w[r];
	}

	// проверка файла по полученным "верным" коэфф.
	FILE *file = NULL;
	int k[60]; // кол-во символов в файле
	unsigned char ch = 0;
	docs[0] = "files\\123.doc";
	if (fopen_s(&file, docs[0], "rb") == 0) {	// файл открыт	
		// пока не достигнут конец файла
		while (!feof(file)) {
			ch = getc(file);
			int numb = (unsigned int)ch;
			vectors[0][numb] = vectors[0][numb] + 1;
			k[0] = k[0] + 1; // считаем кол-во символов в файле
		}
		// вычислениe доли символа в файле
		for (int j = 0; j < 256; j++) {
			if (vectors[0][j] != 0) {
				vectors[0][j] = vectors[0][j] / (k[0] - 1);
			}
		}
		fclose(file);
	} else {	// не удалось открыть файл
		printf("The file not opened.\n");
	}
	float rezult = 0.0;
	for (int j = 0; j < 256; j++) {
		rezult += vectors[0][j] * final_w[j];
	}
	if (rezult > 0) {
		// подаем на вход нейрона 1
		neuron[0] = 1;
		if (docs[0][strlen(docs[0]) - 1] == 'c') {
			// это файл док
			printf("The file its doc.\n");
			return 1;
		} else {
			// это файл не док
			printf("Error: The file its nedoc.\n");
			return 0;
		}
	} else {
		// подаем на вход нейрона -1
		neuron[0] = -1;
		if (docs[0][strlen(docs[0]) - 1] == 'c') {
			// это файл док
			printf("Error: The file its doc.\n");
			return 0;
		} else {
			// это файл не док	
			printf("The file its nedoc.\n");
			return 1;
		}
	}

	return 0;
}

/* Обнуление массива Code */
void start() {
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= 256; j++) {
			vectors[i][j] = 0.0;
		}
	}
	return;
}

/* Функция для подсчета символов в файле и заполнения массива */
void readFile_docs() {
	FILE *file = NULL;
	int k[60]; // кол-во символов в файле
	unsigned char ch = 0;

	for (int i = 0; i <= 60; i++) {
		k[i] = 0;
	}	

	// цикл по файлам
	for (int i = 0; i < 60; i++) {
		// Open for read (will fail if file "files\\1.txt" does not exist)  
		if (fopen_s(&file, docs[i], "rb") == 0) {	// файл открыт	
			// пока не достигнут конец файла
			while (!feof(file)) {
				ch = getc(file);
				int numb = (unsigned int)ch;
				vectors[i][numb] = vectors[i][numb] + 1;
				k[i] = k[i] + 1; // считаем кол-во символов в файле
			}
			// вычислениe доли символа в файле
  			for (int j = 0; j < 256; j++) {
				if (vectors[i][j] != 0) {
					vectors[i][j] = vectors[i][j] / (k[i] - 1);
				}
			}
			fclose(file); 
		} else {	// не удалось открыть файл
			printf("The file not opened.\n");
		}		
	}
	return;
}

/* Фунция для инициализации массива doc */
void files_docs() {

	docs[0] = "files\\1.doc";
	
	docs[1] = "files\\2.doc";
	
	docs[2] = "files\\3.doc";
	
	docs[3] = "files\\4.doc";
	
	docs[4] = "files\\5.doc";
	
	docs[5] = "files\\6.doc";
	
	docs[6] = "files\\7.doc";
	
	docs[7] = "files\\8.doc";
	
	docs[8] = "files\\9.doc";
	
	docs[9] = "files\\10.doc";
	
	docs[10] = "files\\11.doc";
	
	docs[11] = "files\\12.doc";
	
	docs[12] = "files\\13.doc";
	
	docs[13] = "files\\14.doc";
	
	docs[14] = "files\\17.doc";
	
	docs[15] = "files\\18.doc";
	
	docs[16] = "files\\19.doc";
	
	docs[17] = "files\\20.doc";
	
	docs[18] = "files\\21.doc";
	
	docs[19] = "files\\22.doc";
	
	docs[20] = "files\\m.txt";

	docs[21] = "files\\1.txt";

	docs[22] = "files\\1.ppt";

	docs[23] = "files\\1.xlsx";

	docs[24] = "files\\1.jpg";

	docs[25] = "files\\1.pdf";

	docs[26] = "files\\1.mdb";

	docs[27] = "files\\2.jpg";

	docs[28] = "files\\2.txt";

	docs[29] = "files\\2.pdf";

	docs[30] = "files\\2.ppt";

	docs[31] = "files\\2.xls";

	docs[32] = "files\\3.jpg";

	docs[33] = "files\\3.pdf";

	docs[34] = "files\\3.ppt";

	docs[35] = "files\\3.xlsx";

	docs[36] = "files\\4.pdf";

	docs[37] = "files\\4.ppt";

	docs[38] = "files\\4.xlsx";

	docs[39] = "files\\5.pdf";

	docs[40] = "files\\5.ppt";

	docs[41] = "files\\5.pptx";

	docs[42] = "files\\5.txt";

	docs[43] = "files\\6.ppt";

	docs[44] = "files\\6.txt";

	docs[45] = "files\\6.xlsx";

	docs[46] = "files\\7.pdf";

	docs[47] = "files\\7.ppt";

	docs[48] = "files\\7.pptx";

	docs[49] = "files\\7.xlsx";

	docs[50] = "files\\8.pdf";

	docs[51] = "files\\8.ppt";

	docs[52] = "files\\8.pptx";

	docs[52] = "files\\8.xlsx";

	docs[53] = "files\\9.pdf";

	docs[54] = "files\\9.pptx";

	docs[55] = "files\\10.pptx";

	docs[56] = "files\\11.pptx";

	docs[57] = "files\\12.pptx";

	docs[58] = "files\\13.pptx";

	docs[59] = "files\\14.pptx";
	return;

	//docs[60] = "files\\m.txt";
	
	/*readFile(r63);
	const char * r64 = "files\\24.doc";
	readFile(r64);
	const char * r65 = "files\\25.doc";
	readFile(r65);
	const char * r66 = "files\\26.doc";
	readFile(r66);
	const char * r67 = "files\\27.doc";
	readFile(r67);
	const char * r68 = "files\\28.doc";
	readFile(r68);
	const char * r69 = "files\\29.doc";
	readFile(r69);
	const char * r70 = "files\\30.doc";
	readFile(r70);
	const char * r71 = "files\\31.doc";
	readFile(r72);

	const char * r73 = "files\\32.doc";
	readFile(r73);
	const char * r74 = "files\\33.doc";
	readFile(r74);
	const char * r75 = "files\\34.doc";
	readFile(r75);
	const char * r76 = "files\\35.doc";
	readFile(r76);
	const char * r77 = "files\\36.doc";
	readFile(r77);
	const char * r78 = "files\\37.doc";
	readFile(r78);
	const char * r79 = "files\\38.doc";
	readFile(r79);
	const char * r80 = "files\\39.doc";
	readFile(r80);
	const char * r10 = "files\\40.doc";
	readFile(r10);
	const char * r82 = "files\\LR1.doc";
	readFile(r82);*/
}

/* Заполнение массива w стартовыми значениями */
void start_w() {
	for (int i = 0; i < 256; i++) {
		w[i] = (rand() % 7) - float(3.0);
	}
	return;
}

/* Функция подсчета коэффициент */
int raschet() {
	float rezult[60];
	int verno = 0; 
	for (int t = 0; t < 60; t++) {
		rezult[t] = 0.0;
	}
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 256; j++) {
			rezult[i] = rezult[i] + vectors[i][j] * w[j];
		}
		if (rezult[i] > 0) {
			// подаем на вход нейрона 1
			neuron[i] = 1; 
			if (docs[i][strlen(docs[i]) - 1] == 'c') {
				// это файл док
				verno++;
			} else {
				// это файл не док
				for (int j = 0; j < 256; j++) {
					w[j] = w[j] - 2 * (float)0.2 * vectors[i][j];
				} 
			}
		} else {
			// подаем на вход нейрона -1
			neuron[i] = -1;
			if (docs[i][strlen(docs[i]) - 1] == 'c') {
				// это файл док
				for (int j = 0; j < 256; j++) {
					w[j] = w[j] + 2 * (float)0.2 * vectors[i][j];
				}
			} else {
				// это файл не док	
				verno++;
			}
		}
	}
	return verno;
}