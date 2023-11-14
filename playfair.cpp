#include<iostream>
using namespace std;

/*
	테이블 만들기.
	

	멤버:
	table 5*5   -> string 으로 할 예정 (예외 조건 때문에  Q/Z)
	num = 0   -> 테이블 인덱수 갯수
	except -> Q/Z 가 뭔지 넣을거

	함수:
	요소 넣기
	
	
	암호문(2글자씩 끊어 넣기)

	인풋 넣기_
	조건1. 같은 글자면 x 넣기
	조건2. except 면 x 넣기
	조건3. 최종 글자수 혼수면 끝에 x 넣기

	결과
	조건1. i,j 모두 다를경우 ab  cd  -> ad  cb
	조건 2. 높이가 같을 경우 ab ac -> ac ab
	조건 3.  _               ab cb -> cb ab
	
	멤버:
	input 초기
	output 결과
	count = 0
	a_i  = -1
	a_j  = -1

	b_i  = -1
	b_j  = -1

	함수:
	fill_input(string) 
		for (0 부터 string 길이까지 i = i+2)  //짝수 일때만
			만약 i == i+1  insert(i, 'X')

		만약 string 길이가 홀수면 append('x')

	fill_output() //////테이블 만들기와 프렌드
		while(count <input.len)
			for(i, 5, ++)
				for(j,5,++)
					for(k, table[i][j] 의 길이까지)
						만약 input 의 글자가 table[i],[j] 와 같으면 a_i = i  a_j = j
			
			count++

			for(i, 5, ++)
				for(j,5,++)
					for(k, table[i][j] 의 길이까지)
						만약 input 의 글자가 table[i],[j] 와 같으면 b_i = i  b_j = j	
			count++
			조건1
			조건2
			조건3

		


*/

class table {
	string t[5][5];
	int num;
	string except = "QZ";
public:
	void print();
	void filltable_with_key(string& key);
	void filltable_with_except(string& key);
};

void table::print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}

void table::filltable_with_key(string& key) {
	int keyptr = 0;  //key pointer
	string tmp = key;
	string key_tmp;


	if (key.empty()) {
		cout << "키값 없음" << endl;
		return;
	}

	num = 0;   //초기화

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			t[i][j] = "";
		}
	}

	while (keyptr < key.length()) {

		key_tmp = key.substr(keyptr, 1);
		keyptr++;
		
		if (num == 0) {
			if (key_tmp == except.substr(0, 1) || key_tmp == except.substr(1, 1)) {   //만약 조건에 들어가면 바꿔치기
				key_tmp = except;
			}
			t[0][0] = key_tmp;
			cout << key_tmp << "추가" << endl;
			num++;
			continue;
		}

		int flag = 0;  //중복

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				
				if (t[i][j] == key_tmp) {      //중복
					cout << key_tmp << "중복" << endl;
					flag = 1;
					break;
				}


				
			}
			if (flag == 1)  break;   
		}

		if (flag == 0) {
			if (key_tmp == except.substr(0, 1) || key_tmp == except.substr(1, 1)) {   //만약 조건에 들어가면 바꿔치기
				key_tmp = except;
			}
			cout << key_tmp << "추가" << endl;
			t[num/5][num%5] = key_tmp;  //삽입
			num++;
		}
	}
	
	
	
}


void table::filltable_with_except(string& key){

	filltable_with_key(key);

	char alpha = 65;

	int flag = 0;
	int blank_flag = 0;
	while (alpha < 91 && num<25) {
		string alphabet(1, alpha++);
		flag = 0;
		blank_flag = 0;
		cout << alphabet << "탐색 시작" << endl;

		if (alphabet == except.substr(0, 1) || alphabet == except.substr(1, 1)) {   //만약 조건에 들어가면 바꿔치기
			alphabet = except;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (t[i][j] == alphabet) {
					flag = 1; cout << alphabet << "중복 확인" << endl; break;
				}																														//중복 탐색 종료
				if (t[i][j] == "") {
					cout << alphabet << "중복 없음" << endl;
					blank_flag = 1;
				}
			}
			if (flag == 1) break;
		}
		if (blank_flag == 1) {
			cout << alphabet << "추가" << endl;
			t[num / 5][num % 5] = alphabet;  //삽입
			num++;
		}
	}
	
}
int main() {
	table myTable;
	string a = "ASSASINATOR";
	myTable.filltable_with_except(a);
	myTable.print();

	return 0;
}






