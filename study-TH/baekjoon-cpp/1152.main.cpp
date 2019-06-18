#include <iostream>
using namespace std;
 
int main()
{
	string sentence;
	int count = 0; // 단어 수
 
	getline(cin, sentence); // cin을 이용하여 공백을 포함한 string값을 입력 받음
 
	for(char c : sentence)
	{
		if(c == ' ') count++; // 공백의 수 count
	}
	count++; // '공백의 수 + 1 = 단어 수' 이므로 count를 1증가
	if(sentence[0] == ' ') count--; // 문장의 첫 글자가 공백이면 count--
	if(sentence[sentence.size() - 1] == ' ') count--; // 문장의 마지막 글자가 공백이면 count--
 
	cout << count << endl; // 단어 수 출력
 
	return 0;
}