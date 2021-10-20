#include<iostream>
#include<vector>
#include<string>
using namespace std;
string Xor(string s1, string s2);
//IP�ı��
int IP[64] = {
58,50,42,34,26,18,10,2,
60,52,44,36,28,20,12,4,
62,54,46,38,30,22,14,6,
64,56,48,40,32,24,16,8,
57,49,41,33,25,17,9,1,
59,51,43,35,27,19,11,3,
61,53,45,37,29,21,13,5,
63,55,47,39,31,23,15,7
};
string IPex(string a) {
	string ans = "";
	for (int i = 0; i < a.size(); i++)
	{
		ans = ans + a[IP[i]-1];
	}
	return ans;
}
//��IP�ı��
int ivIP[64] = {
40,8,48,16,56,24,64,32,
39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,
37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,
33,1,41,9,49,17,57,25
};
string IP_inver(string a) {
	string ans = "";
	for (int i = 0; i < a.size(); i++)
	{
		ans = ans + a[ivIP[i]-1];
	}
	return ans;
}


//���ܺ�������
//S��
int S0[4][16] = {
	{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 },
	{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
	{ 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
	{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};
int S1[4][16] = {
	{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
	{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
	{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
	{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }
};
int S2[4][16] = {
	{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
	{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
	{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
	{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }
};
int S3[4][16] = {
	 { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
	{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
	{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 3 },
	{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }
};
int S4[4][16] = {
	{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
	{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
	{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
	{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }
};
int S5[4][16] = {
	{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
	{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
	{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
	{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }
};
int S6[4][16] = {
	{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
	{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
	{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
	{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }
};
int S7[4][16] = {
	{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
	{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
	{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
	{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
};
string schange(string ans, int i)
{
	string col = ans.substr(1, 4);
	ans.erase(1, 4);
	string row = ans;
	int vcol = 8 * (col[0] - '0') + 4 * (col[1] - '0') + 2 * (col[2] - '0') + (col[3] - '0');
	int vrow = 2 * (row[0] - '0') + (row[1] - '0');
	int tmp;
	switch (i)
	{
	case 0:  tmp = S0[vrow][vcol]; break;
	case 1:  tmp = S1[vrow][vcol]; break;
	case 2:  tmp = S2[vrow][vcol]; break;
	case 3:  tmp = S3[vrow][vcol]; break;
	case 4:  tmp = S4[vrow][vcol]; break;
	case 5:  tmp = S5[vrow][vcol]; break;
	case 6:  tmp = S6[vrow][vcol]; break;
	case 7:  tmp = S7[vrow][vcol]; break;
	default: break;					 
	}
	string ss = "";
	while (tmp) {
		char tmpc = (tmp % 2) + '0';
		ss = tmpc+ ss;
		tmp /= 2;
	}
	while (ss.size() < 4) {
		ss = "0" + ss;
	}
	return ss;
}
string replace(string a);
string select(string A);
string f(string A, string K) {
	//select(A)��K[i]ȡ���
	string ans = Xor(select(A),K);//��ȷ
	vector<string> subans(8);
	for (int i = 0; i < 8; i++) {
		subans[i] = ans.substr(6 * i, 6);
	}
	string newans = "";
	for (int i = 0; i < 8; i++) {
		newans=newans+schange(subans[i], i);
	}
	return replace(newans);//replaceû����
}
//ѡ������E����32λ����ת��Ϊ48λ�м���������K���в���
int selE[48] = {
	32,1,2,3,4,5,
	4,5,6,7,8,9,
	8,9,10,11,12,13,
	12,13,14,15,16,17,
	16,17,18,19,20,21,
	20,21,22,23,24,25,
	24,25,26,27,28,29,
	28,29,30,31,32,1
};
string select(string A)
{
	string E="";
	for (int i = 0; i < 48; i++)
	{
		E = E + A[selE[i] - 1];
	}
	return E;
}
//�û�����P�ı��
int rep[32] = {
	16,7,20,21,
	29,12,28,17,
	1,15,23,26,
	5,18,31,10,
	2,8,24,14,
	32,27,3,9,
	19,13,30,6,
	22,11,4,25
};
string replace(string a) {
	string ans = "";
	for (int i = 0; i < 32; i++)
	{
		ans = ans + a[rep[i] - 1];
	}
	return ans;
}


//��������Կ����
//K��64λ������������Կ��48λ
//�Ѳ��ԣ����Բ�����ȷ������Կ
string C0 = "";string D0 = "";
string C = ""; string D = "";//���ڱ����²�����C��D
vector<string> K;
int replaceC[28] = {
	57,49,41,33,25,17,9,
	1,57,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36
};
int replaceD[28]={
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
};
int shiftnum[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
int rp2[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
};
string replace2(string C, string D) {
	string s = C + D;
	string ans = "";
	for (int i = 0; i < 48; i++)
	{
		ans = ans + s[rp2[i] - 1];
	}
	return ans;
}
string circleleftshift(string s, int n)
{
	string tmp = s.substr(0, n);
	s.erase(0, n);
	s = s + tmp;
	return s;
}//�Ѳ���
void generatekey(string Ko)//Ko ��ʾԭʼ��Կ
{
	//generatekey��������K1��K2......���浽K������
	//replace1
	for (int i = 0; i < 28; i++) {
		C0 = C0 + Ko[replaceC[i]-1];
		D0 = D0 + Ko[replaceD[i]-1];
	}

	//ѭ�����𰸱�����K[]��
	for (int i = 0; i < 16; i++)
	{
		C = circleleftshift(C0, shiftnum[i]);
		D = circleleftshift(D0, shiftnum[i]);
		K.push_back(replace2(C, D));
		C0 = C;
		D0 = D;
	}//���Բ�����ȷ��Ci��Di����
}



//s1��s2����48λ
string Xor(string s1, string s2) {
	for (int i = 0; i <s1.size(); i++)
	{
		s1[i] = (s1[i] - '0') ^ (s2[i] - '0') + '0';
	}
	return s1;
}
//�Ѳ���

void DES(string input) {
	//�û�
	string s = IPex(input);
	//�������Ϊ����
	string Lp = s.substr(0, 32);
	string Rp = s.substr(32, 32);
	string L, R;
	//�������
	for (int i = 0; i < 16; i++)
	{
		L = Rp;
		R = Xor(Lp, f(Rp, K[i]));
		Lp = L;
		Rp = R;
	}
	//���û�
	s=IP_inver(R+L);

	//���
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
}
void decrypt(string input) {
	//�û�
	string s = IPex(input);
	//�������Ϊ����
	string Lp = s.substr(32, 32);
	string Rp = s.substr(0, 32);
	string L, R;
	//�������
	for (int i = 0; i < 16; i++)
	{
		R = Lp;
		L = Xor(Rp, f(Lp, K[15-i]));
		Lp = L;
		Rp = R;
	}
	//���û�
	s = IP_inver(L+R);

	//���
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
}
void test() {
	string K_0 = "0011000100110010001100110011010000110101001101100011011100111000";
	generatekey(K_0);
	string word = "1000101110110100011110100000110011110000101010010110001001101101";
	decrypt(word);
}
int main()
{
	//test();
	string K_0;
	cout << "��������Կ��"<<endl;
	cin >> K_0;
	generatekey(K_0);
	string word;
	cout << "���������ģ�"<<endl;
	cin >> word;
	DES(word);
	cout << endl;
	cout << "���������ģ�" << endl;
	cin >> word;
	decrypt(word);
	return 0;
}
//��Կ����������0011000100110010001100110011010000110101001101100011011100111000
//���Ĳ���������0011000000110001001100100011001100110100001101010011011000110111
//N=1 32λ���� 00000000111111110000000011001100
//���ģ�1000101110110100011110100000110011110000101010010110001001101101