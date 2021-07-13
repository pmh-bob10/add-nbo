#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main (int argc, char **argv) {
  if (argc < 3) {
  	printf("syntax : add-nbo <file1> <file2> ...\n");
  	printf("sample : add-nbo a.bin b.bin\n");
  	printf("\tadd-nbo a.bin b.bin c.bin\n");
  	return 0;
  }

  uint32_t sum = 0;
  for (int i = 1; argv[i] != NULL; i++) {
  	FILE *file = fopen(argv[i], "rb");
  	if (file == NULL) {
  		fprintf(stderr, "\nERROR: file \"%s\" not found", argv[i]);
  		return 1;
  	}

  	uint32_t nbo;
  	fread(&nbo, sizeof(uint32_t), 1, file);

  	uint32_t hbo = ntohl(nbo); // convert nbo to hbo
  	printf("%s%d(0x%x)", i-1?" + ":"", hbo, hbo);

  	sum += hbo;
  	fclose(file);
  }

  printf(" = %d(0x%x)\n", sum, sum);
}

