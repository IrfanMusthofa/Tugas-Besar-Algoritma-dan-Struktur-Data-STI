#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main()
{
	char *file = "file.txt";
	printf("Test ADT Mesin Karakter dan Mesin Kata\n");
	
	/* Tes Mesin Karakter */
	printf("Tes Mesin Karakter\n");

	printf("Tes START dari file\n");
	START(file);
	printf("Tes GetCC dan ADV\n");
	while (!EOP)
	{
		printf("GetCC: %c\n", GetCC());
		ADV();
	}

	printf("Tes STARTINPUT dari inputan pengguna\n");
	STARTINPUT();
	printf("Tes GetCC dan ADV\n");
	while (currentChar != '\n')
	{
		printf("%c\n", GetCC());
		ADV();
	}
	printf("----------------------\n\n");

	/* Tes Mesin Kata */
	printf("Tes Mesin Kata\n");

	printf("Tes STARTWORD dari file\n");
	STARTWORD(file);
	char *kata;
	printf("Tes WordToString dari currentWord\n");
	printf("WordLength: %d\n", currentWord.Length);
	kata = WordToString(currentWord);
	printf("kata = %s\n", kata);

	printf("Tes takenonspace, ngilangin spasi\n");
	Word w1 = takenonspace(currentWord);
	char *kata2 = WordToString(w1);
	printf("kata2 = %s\n", kata2);


	ADVWORD();
	printf("Tes WordToInt dari currentWord\n");
	int kata_int = WordToInt(currentWord);
	char *kata3 = WordToString(currentWord);
	printf("kata sekarang = %s\n", kata3);
	printf("kata (dalam format int) = %d\n", kata_int);


	printf("Tes ADVWORD\n");
	while (!EOP)
	{
		ADVWORD();
		kata = WordToString(currentWord);
		printf("kata = %s\n", kata);
	}


	printf("Tes STARTINPUTKATA dari inputan pengguna\n");
	STARTINPUTKATA();


	printf("Tes IsEqual\n");
	printf("Tes apakah currentWord dan kata sama.\n");
	printf("Kata merupakan kata terakhir yang dibaca di file sebelumnya.\n");
	char* cW = WordToString(currentWord);
	printf("currentWord = %s\n", cW);
	printf("kata = %s\n", kata);
	printf("IsEqual = %d\n\n", IsEqual(currentWord, kata));

	printf("Tes IsEqual dari currentWord dan kata.\n");
	printf("Kata merupakan bentuk string dari currentWord.\n");
	printf("currentWord = %s\n", cW);
	kata = WordToString(currentWord);
	printf("kata = %s\n", kata);
	printf("IsEqual = %d\n", IsEqual(currentWord, cW));


	printf("Tes IsInWord\n");
	printf("Tes apakah huruf c ada di dalam currentWord.\n");
	printf("currentWord = %s\n", kata);
	printf("IsInWord = %d\n", IsInWord("C", currentWord));

	printf("Tes takeWord\n");
	printf("Tes mengambil kata kedua dari currentWord\n");
	printf("currentWord = %s\n", kata);
	Word take2 = takeword(currentWord, 2);
	kata = WordToString(take2);
	printf("kata kedua = %s\n", kata);

	printf("Tes StringtoWord\n");
	printf("Tes mengubah char* ke word, lalu mengubahnya lagi ke char*.\n");
	printf("Jika kedua operasi berhasil, char* awal akan sama dengan hasil konversi akhirnya.\n");
	char* awal = "Tes";
	Word kata1 = StringtoWord(awal);
	char* akhir = WordToString(kata1);
	printf("awal = %s\n", awal);
	printf("akhir = %s\n", akhir);


	printf("Tes ConcateChar\n");
	printf("Tes menggabungkan dua buah string, yaitu char* awal dan char* akhir tadi.\n");
	char* awal_akhir = ConcateChar(awal, akhir);
	printf("awal_akhir = %s\n", awal_akhir);

	printf("Tes hapustikom\n");
	STARTINPUTKATA();
	char* katas = WordToString(currentWord);
	hapustikom(&currentWord);
	char* tikom = WordToString(currentWord);
	printf("kata sekarang: %s\n", katas);
	printf("hapus tikom: %s\n", tikom);

	printf("Tes isequal\n");
	int cekES = IsEqualString(katas, tikom);
	printf("%d\n", cekES);
	return 0;
}