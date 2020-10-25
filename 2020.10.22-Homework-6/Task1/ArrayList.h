class ArrayList
{
private:
	int count;
	int capacity;
	int* data;
	char* str;

public:
	ArrayList(int capacity = 10) :count(0), capacity(capacity), data(new int[capacity]), str(nullptr) {}
	ArrayList(const ArrayList& list);
	~ArrayList();

private:
	void expand();
	int numLength(int number);
	void addToStr(int& index, char symbol);
	void addToStr(int& index, int number);

public:
	/// <summary>
	/// äîáàâëÿåò ýëåìåíò â êîíåö
	/// </summary>
	/// <param name="element">äîáàâëÿåìûé ýëåìåíò</param>
	/// <returns></returns>
	bool add(int element);

	/// <summary>
	/// äîáàâëÿåò ýëåìåíò â ïîçèöèþ index, âñå ïîñëåäóþùèå ýëåìåíòû ñäâèãàþòñÿ íà 1 âïðàâî
	/// </summary>
	/// <param name="index">èíäåêñ âñòàâëÿåìîãî ýëåìåíòà</param>
	/// <param name="element">âñòàâëÿåìûé ýëåìåíò</param>
	/// <returns>true, åñëè âñå ïðîøëî õîðîøî, false - åñëè âîçíèêëè ïðîáëåìû</returns>
	bool add(int index, int element);

	/// <summary>
	/// äîáàâëÿåò âñå ýëåìåíòû èç ñïèñêà list â êîíåö
	/// </summary>
	/// <param name="list">äîáàâëÿåìûé ñïèñîê</param>
	/// <returns>true, åñëè ïîëó÷èëîñü äîáàâèòü, false - åñëè íå ïîëó÷èëîñü</returns>
	bool addAll(ArrayList& list);

	/// <summary>
	/// äîáàâëÿåò âñå ýëåìåíòû èç ñïèñêà list, íà÷èíàÿ ñ ïîçèöèè index.
	/// âñå ïîñëåäóþùèå ýëåìåíòû ñäâèãàþòñÿ âïðàâî
	/// </summary>
	/// <param name="list">äîáàâëÿåìûé ñïèñîê</param>
	/// <returns>true, åñëè ïîëó÷èëîñü äîáàâèòü, false - åñëè íå ïîëó÷èëîñü</returns>
	bool addAll(int index, ArrayList& list);

	/// <summary>
	/// óäàëèòü âñå ýëåìåíòû èç ñïèñêà
	/// </summary>
	void clear();

	/// <summary>
	/// ñîäåðæèòñÿ ëè ýëåìåíò â ñïèñêå
	/// </summary>
	/// <param name="element">èñêîìûé ýëåìåíò</param>
	/// <returns>true - ñîäåðæèòñÿ, false - íå ñîäåðæèòñÿ</returns>
	bool contains(int element);

	/// <summary>
	/// ïîëó÷èòü ýëåìåíò ïî èíäåêñó
	/// </summary>
	/// <param name="index">èíäåêñ çàïðàøèâàåìîãî ýëåìåíòà</param>
	/// <returns>data[index], åñëè èíäåêñ êîððåêòåí, -1 - åñëè èíäåêñ íåêîððåêòåí</returns>
	int get(int index);

	/// <summary>
	/// Óñòàíîâèòü çíà÷åíèå ýëåìåíòà, íàõîäÿùåãîñÿ íà ìåñòå index.
	/// </summary>
	/// <param name="index">èíäåêñ èçìåíÿåìîãî ýëåìåíòà</param>
	/// <param name="element">íîâîå çíà÷åíèå</param>
	/// <returns>true, åñëè èíäåêñ áûë êîððåêòåí, false - åñëè èíäåêñ áûë íåêîððåêòåí</returns>
	bool set(int index, int element);

	/// <summary>
	/// ïîèñê ýëåìåíòà â ñïèñêå
	/// </summary>
	/// <param name="element">èñêîìûé ýëåìåíò</param>
	/// <returns>èíäåêñ ýëåìåíòà, åñëè îí íàéäåí, -1 - åñëè íå íàéäåí</returns>
	int indexOf(int element);

	/// <summary>
	/// ïðîâåðêà ñïèñêà íà ïóñòîòó
	/// </summary>
	/// <returns>true - åñëè ñïèñîê ïóñò, false - åñëè åñòü õîòÿ áû 1 ýëåìåíò</returns>
	bool isEmpty();

	/// <summary>
	/// Ïðåîáðàçîâàòü ìàññèâ â ñòðîêó âèäà [count/capacity] {el1, el2, el3, ...}
	/// </summary>
	/// <returns>ñîîòâåòñòâóþùóþ ñòðîêó</returns>
	char* toString();

	/// <summary>
	/// óäàëåíèå ýëåìåíòà èç ñïèñêà
	/// </summary>
	/// <param name="index">èíäåêñ óäàëÿåìîãî ýëåìåíòà</param>
	/// <returns>true - âñå ïðîøëî õîðîøî, false - âîçíèêëè ïðîáëåìû</returns>
	bool remove(int index);

	/// <summary>
	/// ïîìåíÿòü ìåñòàìè ýëåìåíòû
	/// </summary>
	/// <param name="index1">èíäåêñ ïåðâîãî ýëåìåíòà</param>
	/// <param name="index2">èíäåêñ âòîðîãî ýëåìåíòà</param>
	/// <returns>true - âñå ïðîøëî õîðîøî, false - âîçíèêëè ïðîáëåìû</returns>
	bool swap(int index1, int index2);

	/// <summary>
	/// Êîëè÷åñòâî ýëåìåíòîâ â ìàññèâå
	/// </summary>
	/// <returns>ïîëå count</returns>
	int length();
}; 
