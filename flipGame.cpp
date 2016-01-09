//// Flip Game ：枚举 +　位运算 + DFS
//
//#include <iostream>
//#include <bitset>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::bitset;
//
//// 翻转第i个棋子，所影响的位，即当前棋盘 ^ round[i];
//long round[16] = {0xC800, 0xE400, 0x7200, 0x3100, 
//				  0x8C80, 0x4E40, 0x2720, 0x1310,
//				  0x08C8, 0x04E4, 0x0272, 0x0131, 
//				  0x008C, 0x004E, 0x0027, 0x0013};
//const long ALL_WHITE = 0x0;
//const long ALL_BLACK = 0xFFFF;
//int step = 16;
//
//// 输入并转换
//long Input()
//{
//	bitset<16> current;
//	for (int i = 0; i < 16;)
//	{
//		char c;
//		cin >> c;
//		int flag = (c == 'w' ? 0 : 1);
//		current.set(i, flag);
//		++i;
//	}
//	return current.to_ulong();
//}
//
//void Flip(long current, int flip, int deep)
//{
//	if (deep >= 16)
//	{
//		if (current == ALL_WHITE || current == ALL_BLACK)
//			if (flip < step) step = flip;
//		return;
//	}
//	Flip(current ^ round[deep], flip + 1, deep + 1);
//	Flip(current, flip, deep + 1);
//}
//
//int main()
//{
//	Flip(Input(), 0, 0);
//	if (step == 16)
//		cout << "Impossible" << endl;
//	else
//		cout << step << endl;
//	cin >> step;
//}