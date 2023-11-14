#include<iostream>
using namespace std;

/*
	���̺� �����.
	

	���:
	table 5*5   -> string ���� �� ���� (���� ���� ������  Q/Z)
	num = 0   -> ���̺� �ε��� ����
	except -> Q/Z �� ���� ������

	�Լ�:
	��� �ֱ�
	
	
	��ȣ��(2���ھ� ���� �ֱ�)

	��ǲ �ֱ�_
	����1. ���� ���ڸ� x �ֱ�
	����2. except �� x �ֱ�
	����3. ���� ���ڼ� ȥ���� ���� x �ֱ�

	���
	����1. i,j ��� �ٸ���� ab  cd  -> ad  cb
	���� 2. ���̰� ���� ��� ab ac -> ac ab
	���� 3.  _               ab cb -> cb ab
	
	���:
	input �ʱ�
	output ���
	count = 0
	a_i  = -1
	a_j  = -1

	b_i  = -1
	b_j  = -1

	�Լ�:
	fill_input(string) 
		for (0 ���� string ���̱��� i = i+2)  //¦�� �϶���
			���� i == i+1  insert(i, 'X')

		���� string ���̰� Ȧ���� append('x')

	fill_output() //////���̺� ������ ������
		while(count <input.len)
			for(i, 5, ++)
				for(j,5,++)
					for(k, table[i][j] �� ���̱���)
						���� input �� ���ڰ� table[i],[j] �� ������ a_i = i  a_j = j
			
			count++

			for(i, 5, ++)
				for(j,5,++)
					for(k, table[i][j] �� ���̱���)
						���� input �� ���ڰ� table[i],[j] �� ������ b_i = i  b_j = j	
			count++
			����1
			����2
			����3

		


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
		cout << "Ű�� ����" << endl;
		return;
	}

	num = 0;   //�ʱ�ȭ

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			t[i][j] = "";
		}
	}

	while (keyptr < key.length()) {

		key_tmp = key.substr(keyptr, 1);
		keyptr++;
		
		if (num == 0) {
			if (key_tmp == except.substr(0, 1) || key_tmp == except.substr(1, 1)) {   //���� ���ǿ� ���� �ٲ�ġ��
				key_tmp = except;
			}
			t[0][0] = key_tmp;
			cout << key_tmp << "�߰�" << endl;
			num++;
			continue;
		}

		int flag = 0;  //�ߺ�

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				
				if (t[i][j] == key_tmp) {      //�ߺ�
					cout << key_tmp << "�ߺ�" << endl;
					flag = 1;
					break;
				}


				
			}
			if (flag == 1)  break;   
		}

		if (flag == 0) {
			if (key_tmp == except.substr(0, 1) || key_tmp == except.substr(1, 1)) {   //���� ���ǿ� ���� �ٲ�ġ��
				key_tmp = except;
			}
			cout << key_tmp << "�߰�" << endl;
			t[num/5][num%5] = key_tmp;  //����
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
		cout << alphabet << "Ž�� ����" << endl;

		if (alphabet == except.substr(0, 1) || alphabet == except.substr(1, 1)) {   //���� ���ǿ� ���� �ٲ�ġ��
			alphabet = except;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (t[i][j] == alphabet) {
					flag = 1; cout << alphabet << "�ߺ� Ȯ��" << endl; break;
				}																														//�ߺ� Ž�� ����
				if (t[i][j] == "") {
					cout << alphabet << "�ߺ� ����" << endl;
					blank_flag = 1;
				}
			}
			if (flag == 1) break;
		}
		if (blank_flag == 1) {
			cout << alphabet << "�߰�" << endl;
			t[num / 5][num % 5] = alphabet;  //����
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






