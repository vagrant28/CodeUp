#include <stdio.h>
#include <string.h>

int main(){
	char strA[15], strB[15];
	char Da, Db;
	while(scanf("%s %c %s %c", strA, &Da, strB, &Db) != EOF){
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		int da = Da - '0';
		int db = Db - '0';
		int Pa = 0, Pb = 0;
		for(int i = 0; i < lenA; i++){
			if(strA[i] == Da)
				Pa = Pa * 10 + da;
		}
		for(int i = 0; i < lenB; i++){
			if(strB[i] == Db)
				Pb = Pb * 10 + db;
		}
//		printf("Pa = %d; Pb = %d\n", Pa, Pb);
		printf("%d\n", Pa + Pb);
	}
	return 0;
}	
