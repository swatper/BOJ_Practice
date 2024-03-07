#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string variable_name;
	int orthography_num;
	cin >> orthography_num >> variable_name;
	//각각의 표기법을 저장할 문자열 변수, 빈 문자열로 초기화
	string camelcase, snake_case, pascalCase;
	camelcase = "";
	snake_case = "";
	pascalCase = "";

	//카멜 표기법으로 입력받을 경우
	if (orthography_num == 1) {
		//카멜 표기법은 그대로 저장
		camelcase += variable_name;
		for (int i = 0; i < variable_name.size(); i++) {	
			//스네이크 표기법으로 저장
			//대문자면 _를 추가하고 소문자로 바꿈
			if (variable_name[i] >= 'A' && variable_name[i] <= 'Z') {
				snake_case +='_';
				snake_case += variable_name[i] + 32;
			}
			else {
				snake_case += variable_name[i];
			}
			//파스칼 표기법으로 저장, 첫글자 대문자
			if (i ==0) {
				pascalCase += variable_name[i] - 32;
			}
			else {
				pascalCase += variable_name[i];
			}
		}
	}
	//스네이크 표기법으로 입력받을 경우
	if(orthography_num == 2) {
		//스네이크 표기법 그대로 저장
		snake_case += variable_name;
		for (int i = 0; i < variable_name.size(); i++) {

			//카멜 표기법으로 저장
			if (variable_name[i] != '_') {
				//'_'다음의 소문자를 대문자로 바꿈
				if (i != 0 && variable_name[i - 1] == '_') {
					camelcase += variable_name[i] - 32;
				}
				else {
					camelcase += variable_name[i];
				}
			}

			//파스칼 표기법으로 저장
			if (i == 0) {
				//단어의 첫 문자를 대문자로 저장
				pascalCase += variable_name[i] - 32;
			}
			else if (variable_name[i] != '_') {
				//'_'다음의 소문자를 대문자로 바꿈
				if (variable_name[i - 1] == '_') {
					pascalCase += variable_name[i] - 32;
				}
				else {
					pascalCase += variable_name[i];
				}
			} 
		}
	}
	//파스칼 표기법으로 입력받을 경우
	 if (orthography_num == 3) {
		 //파스칼 표기법 그대로 저장
		 pascalCase += variable_name;
		for (int i = 0; i < variable_name.size(); i++) {
			//카멜 표기법으로 저장
			if (i == 0) {//첫 단어의 대문자만 소문자로 저장
				camelcase += variable_name[i] + 32;
			}
			else {		//나머지는 그대로 저장
				camelcase += variable_name[i];
			}
			//스네이크 표기법으로 저장
			if (i == 0) { //첫 단어의 대문자를 소문자로 저장
				snake_case += variable_name[i] + 32;
			}
			else if (variable_name[i] >= 'A' && variable_name[i] <= 'Z') {
				//'_'를 추가한 후 소문자로 바꿈
				snake_case += '_';
				//대문자를 소문자로 바꿈
				snake_case += variable_name[i] + 32;
			}
			else {
				snake_case += variable_name[i];
			}

		}
	 }
	 //각각의 표기법으로 출력
	 cout << camelcase << "\n";
	 cout << snake_case << "\n";
	 cout << pascalCase << "\n";
	return 0;
}