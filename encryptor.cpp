














#include <stdio.h>
#include <stdlib.h>

typedef long long u64;
void encrypt_(FILE * input_f, FILE * output_f, u64 key, bool close_files = false)
{
	// declaring variables
	char a, b, c, d, e, f, g, h;
	u64 _s;
	int i;
	{
		char s1, s2, s3, s4;
		fscanf(input_f, "%c%c%c%c", &s1, &s2, &s3, &s4);
		i = s1;
		i = (((((i << 8) | s2) << 8) | s3) << 8) | s4;
		fprintf(output_f, "%c%c%c%c", s1, s2, s3, s4);
	}
	for (int x = 0; x < i; x++)
	{
		// reading the bytes from the file
		fscanf(input_f, "%c%c%c%c%c%c%c%c", &a, &b, &c, &d, &e, &f, &g, &h);
		// applying the logic and encrypting the data
		_s = ((u64(a) << 56) | (u64(b) << 48) | (u64(c) << 40) | (u64(d) << 32) | (u64(e) << 24) |
			  (u64(f) << 16) | (u64(g) << 8) | u64(h)) ^ key;
		// creating writable data from the encrypted 8 byte data
		a = (char)((_s << 0) >> 56);
		b = (char)((_s << 8) >> 56);
		c = (char)((_s << 16) >> 56);
		d = (char)((_s << 24) >> 56);
		e = (char)((_s << 32) >> 56);
		f = (char)((_s << 40) >> 56);
		g = (char)((_s << 48) >> 56);
		h = (char)((_s << 56) >> 56);
		// writing them accrodingly to the output_f
		fprintf(output_f, "%c%c%c%c%c%c%c%c", a, b, c, d, e, f, g, h);
	}
	// closong the files if close_files is true
	if (close_files)
	{
		fclose(input_f);
		fclose(output_f);
	}
}


int main()
{
	FILE *inp = fopen("haha.txt", "r");
	FILE *temp= fopen("temp","w+");
	FILE *out = fopen("haha_encrypted.txt", "w+");
	encrypt_(inp, temp, 0x1, false);
	encrypt_(temp,out,  0x1, true);
 // encrypt_(inp,out,0x01,true);
	fclose(inp);
	printf("DoNE!!");
	return 0;
}
