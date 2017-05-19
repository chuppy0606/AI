#include <stdio.h>
#include <string.h>


void main() {
	char* dictionary[20] = { "artificial", "bug", "classification", "computer", "data", "fat", "human",
		"interface", "language", "loan", "man", "message", "promotion", "replica",
		"sale", "science", "system", "user", "viagra", "video" };
	//prior = spam이었던 확률, spam이 아니었던 확률
	double prior[2] = { 0.6, 0.4 };
	//spam인 확률
	double spam[20] = { 0.02, 0.1, 0.01, 0.02, 0.01, 0.3, 0.1, 0.03, 0.05, 0.3, 0.2, 0.2, 0.1, 0.2, 0.2, 0.1, 0.02, 0.1, 0.4, 0.2 };
	//ham인 확률
	double ham[20] = { 0.2, 0.2, 0.1, 0.4, 0.2, 0.05, 0.2, 0.1, 0.2, 0.01, 0.1, 0.1, 0.01, 0.02, 0.1, 0.2, 0.3, 0.2, 0.01, 0.1 };

	//검사해야 하는 문서 5개
	char* Doc1[20] = { "computer", "system", "programming", "Java", "video", "network" };
	char* Doc2[20] = { "viagra", "replica", "woman", "artificial", "internet" };
	char* Doc3[20] = { "sale", "user", "promotion" };
	char* Doc4[20] = { "man", "machine", "interface", "system", "video" };
	char* Doc5[20] = { "reply", "this", "message", "system", "loan", "without", "credit" };

	char** Docs[5];
	Docs[0] = Doc1;
	Docs[1] = Doc2;
	Docs[2] = Doc3;
	Docs[3] = Doc4;
	Docs[4] = Doc5;
	int count[5] = { 6,5,3,5,7 };

	//!----------------------------compute-------------------------!//

	int check[20];
	bool check_strcmp = false;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 20; j++) {
			for (int z = 0; z < count[i]; z++) {
				if (strcmp(Docs[i][z], dictionary[j]) == 0) {
					check_strcmp = true;
					break;
				}
			}
			//check[20]배열에 문서와 같은 단어가 있다면 그 위치에 1을 표기, 아닐시 0을 표기
			if (check_strcmp == true) {
				check[j] = 1;
			}
			else
				check[j] = 0;
			check_strcmp = false;
		}

		//check배열을 가지고 spam일 확률 계산
		double spam_sum = 1;
		for (int j = 0; j < 20; j++) {
			if (check[j] == 1) {
				spam_sum *= spam[j];
			}
			else if (check[j] == 0) {
				spam_sum *= (1 - spam[j]);
			}
		}
		spam_sum *= prior[0];

		//check배열을 가지고 ham일 확률 계산
		double ham_sum = 1;
		for (int j = 0; j < 20; j++) {
			if (check[j] == 1) {
				ham_sum *= ham[j];
			}
			else if (check[j] == 0) {
				ham_sum *= (1 - ham[j]);
			}
		}
		ham_sum *= prior[1];

		//!--------------------print result------------------------!//
		printf(">>>DOCS%d\n", i);
		//ham일 확률이 더 크다면
		if (ham_sum > spam_sum) {
			printf("This is HAM!!\n");
			printf(" spam : %lf\n ham : %lf\n spam_probability : %lf\n ham_probability : %lf\n\n", spam_sum, ham_sum, spam_sum / (spam_sum + ham_sum), ham_sum / (ham_sum + spam_sum));
		}
		//spam일 확률이 더 크다면
		else {
			printf("This is SPAM!!\n");
			printf(" spam : %lf\n ham : %lf\n spam_probability : %lf\n ham_probability : %lf\n\n", spam_sum, ham_sum, spam_sum / (spam_sum + ham_sum), ham_sum / (ham_sum + spam_sum));
		}
	}
}