#include <iostream>
#include <conio.h>
#include <time.h>
#include <cctype>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <ctime>
using namespace std;

int game = 0;
ifstream read;
ofstream write;

// Snake indificators -START-
void snakemain();
void run();
void printMap();
void initMap();
void move(int dx, int dy);
void update();
void changeDirection(char key);
void clearScreen();
void generateFood();

char getMapValue(int value);

// Map dimensions

const int mapwidth = 20;

const int mapheight = 20;

const int size = mapwidth * mapheight;

// The tile values for the map
int map[size];

// Snake head details
int headxpos;
int headypos;
int direction;

// Amount of food the snake has (How long the body is)
int food = 3;

// Determine if game is running
bool running;

// Snake indificators -END-

void devide();
int answer = 0;
int score = 0;

// MB indificators -START-
char field[11][11];
char fieldEnemy[11][11];
char fieldHidden[11][11];
char abc[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
char nums[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
void ShowField();
void FillBackground();
void ShowFieldEnemy();
void FillBackgroundEnemy();
void ShowFieldHidden();
void FillBackgroundHidden();
void play();
void playEnemy();
void begin();
void Win();
void mbmain();
void SetBoatsEnemy();
// MB indificators -END-
// --

void main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	system("color 0a");
	system("cls");
	int a = 0;
	int b = 0;
	int times = rand() % 50;
	char name[50];

	cout << "R.Beat presents..." << endl;
	_sleep(3000);
	cout << "Open-source project for children..." << endl;
	_sleep(3000);
	system("cls");
	cout << "  _                         " << endl;
	cout << " /_`._ _  _  /   /|,/_ _/_/_" << endl;
	cout << "._/// / //_///_//  //_|/ / /" << endl;
	cout << "        /    _/             " << endl;
	_sleep(1000);
	system("color 01");
	system("cls");
	cout << "  _                         " << endl;
	cout << " /_`._ _  _  /   /|,/_ _/_/_" << endl;
	cout << "._/// / //_///_//  //_|/ / /" << endl;
	cout << "        /    _/             " << endl;
	_sleep(1000);
	system("color 03");
	system("cls");
	cout << "  _                         " << endl;
	cout << " /_`._ _  _  /   /|,/_ _/_/_" << endl;
	cout << "._/// / //_///_//  //_|/ / /" << endl;
	cout << "        /    _/             " << endl;
	_sleep(1000);
	system("color 04");
	system("cls");
	cout << "  _                         " << endl;
	cout << " /_`._ _  _  /   /|,/_ _/_/_" << endl;
	cout << "._/// / //_///_//  //_|/ / /" << endl;
	cout << "        /    _/             " << endl;
	_sleep(1000);
	system("color 05");
	system("cls");
	cout << "  _                         " << endl;
	cout << " /_`._ _  _  /   /|,/_ _/_/_" << endl;
	cout << "._/// / //_///_//  //_|/ / /" << endl;
	cout << "        /    _/             " << endl;
	_sleep(1000);
	system("color 08");
	system("cls");
	cout << "This project is open-source, so you can edit it like you want!" << endl;
	cout << "Этот проект содержит открытый исходный код, \nпоэтому Вы можете изменять параметры программы как вам нравиться!" << endl;
	_sleep(5000);
	system("cls");
	cout << "Спасибо TheKittyKat из http://codereview.stackexchange.com/ \nза предоставленную змейку!\x02\n" << endl;
	cout << "Спасибо Дорохину Богдану Павловичу за полученые знание в C++! \x02" << endl;
	_sleep(5000);
	system("color 0a");
	system("cls");
	cout << "Введи своё имя на английском языке: " << endl;
	cin >> name;
	write.open("C:\\SimplyMathResults.txt", ios::app);
	write << "________________________________________"<< endl;
	system("cls");
	write << "Имя: " << name << endl;
	write << "Дата/Время тестирования: " << asctime(timeinfo) << endl;
	for (int i = 0; i < times; i++){
		if (times < 15){
			times = 0;
			times = rand() % 50;
			continue;
		}
		answer = 0;
		a = rand() % 5;
		b = rand() % 11;
		cout << a << "*" << b << " - ?" << endl;
		cin >> answer;
		if (answer == a*b){
			cout << "\n\nМолодец!\x01 " << endl;
			score = score + 1;
			cout << "Счет: " << score << "\n\n";
		}
		else{
			cout << "\n\nОшибка! Попробуй еще раз:" << endl;
			i = i + 1;
			score = score - 1;
			cout << "Счет: " << score << "\n\n";
			continue;
		}
		if (score == times){
			system("cls");
			cout << "Время отдохнуть!" << endl;
			_sleep(5000);
			snakemain();
		}
	}
}

void devide(){
	srand(time(NULL));
	system("color 0e");
	system("cls");
	int a = 0;
	int b = 0;
	int times = rand() % 50;

	for (int i = 0; i < times; i++){
		if (times < 15){
			times = 0;
			times = rand() % 50;
			continue;
		}
		answer = 0;
		a = rand() % 5;
		b = rand() % 11;
		if (a != 0){
			if (b%a > 0){
				continue;
			}
		}
		else{
			continue;
		}
		cout << b << "/" << a << " - ?" << endl;
		cin >> answer;
		if (answer == b / a){
			cout << "\n\nМолодец!\x01 " << endl;
			score = score + 1;
			cout << "Счет: " << score << "\n\n";
		}
		else{
			cout << "\n\nОшибка! Попробуй еще раз." << endl;
			score = score - 1;
			cout << "Счет: " << score << "\n\n";
			continue;
		}
		if (score == times){
			cout << "Ты молодец! Ты прошел все тесты! Поздравляем!\x02";
			_sleep(2000);
			write << "Результат: " << score << " очков." << endl;
			write << "________________________________________" << endl;
			write.close();
			system("cls");
			cout << "Результат сохранен в: C:\SimplyMathResults.txt" << endl;
			_sleep(3000);
			system("cls");
			cout << "Ты можешь поиграть в новую игру!" << endl;
			_sleep(3000);
			system("cls");
			mbmain();

		}
	}
}

// Snake function -START-
void snakemain(){
	system("cls");
	cout << "ЗМЕЙКА!" << endl;
	_sleep(1000);
	system("color 02");
	system("cls");
	cout << "ЗМЕЙКА!" << endl;
	_sleep(1000);
	system("color 03");
	system("cls");
	cout << "ЗМЕЙКА!" << endl;
	_sleep(1000);
	system("color 04");
	system("cls");
	cout << "ЗМЕЙКА!" << endl;
	_sleep(1000);
	system("color 05");
	system("cls");
	cout << "ЗМЕЙКА!" << endl;
	_sleep(1000);
	system("color 0a");
	system("cls");
	cout << "(Игра начнется через 10 сек.) \nПРАВИЛА ИГРЫ: " << endl;
	cout << "Цель игры: Съесть все фрукты не врезавшись в стенку.\n" << endl;
	cout << "Графика: 1 - Змейка" << endl;
	cout << "         ! - Стенка" << endl;
	cout << "         @ - Фрукты" << endl;
	cout << "         a или \" \" - Поле\n" << endl;
	cout << "Управление: Стрелочки\n" << endl;
	cout << "УДАЧИ ТЕБЕ!" << endl;
	_sleep(10000);
	system("color 0a");
	system("cls");
	run();
}

void run()
{

	initMap();
	running = true;
	while (running) {

		if (kbhit()) {

			changeDirection(getch());
		}

		update();


		clearScreen();


		printMap();


		_sleep(500);
	}


	cout << "\t\t!!!Конец игры!" << endl << "\t\tСчет: " << food;
	_sleep(5000);
	score = score + food;
	devide();


	cin.ignore();
}

void changeDirection(char key) {

	switch (key) {
	case 72:
		if (direction != 2) direction = 0;
		break;
	case 77:
		if (direction != 3) direction = 1;
		break;
	case 80:
		if (direction != 4) direction = 2;
		break;
	case 75:
		if (direction != 5) direction = 3;
		break;
	}
}

void move(int dx, int dy) {

	int newx = headxpos + dx;
	int newy = headypos + dy;


	if (map[newx + newy * mapwidth] == -2) {

		food++;


		generateFood();
	}


	else if (map[newx + newy * mapwidth] != 0) {
		running = false;
	}


	headxpos = newx;
	headypos = newy;
	map[headxpos + headypos * mapwidth] = food + 1;

}

void clearScreen() {

	system("cls");
}

void generateFood() {
	int x = 0;
	int y = 0;
	do {

		x = rand() % (mapwidth - 2) + 1;
		y = rand() % (mapheight - 2) + 1;


	} while (map[x + y * mapwidth] != 0);


	map[x + y * mapwidth] = -2;
}

void update() {

	switch (direction) {
	case 0: move(-1, 0);
		break;
	case 1: move(0, 1);
		break;
	case 2: move(1, 0);
		break;
	case 3: move(0, -1);
		break;
	}


	for (int i = 0; i < size; i++) {
		if (map[i] > 0) map[i]--;
	}
}

void initMap()
{

	headxpos = mapwidth / 2;
	headypos = mapheight / 2;
	map[headxpos + headypos * mapwidth] = 1;


	for (int x = 0; x < mapwidth; ++x) {
		map[x] = -1;
		map[x + (mapheight - 1) * mapwidth] = -1;
	}


	for (int y = 0; y < mapheight; y++) {
		map[0 + y * mapwidth] = -1;
		map[(mapwidth - 1) + y * mapwidth] = -1;
	}


	generateFood();
}

void printMap()
{
	for (int x = 0; x < mapwidth; ++x) {
		for (int y = 0; y < mapheight; ++y) {

			cout << getMapValue(map[x + y * mapwidth]);
		}

		cout << endl;
	}
}

char getMapValue(int value)
{

	if (value > 0) return '1';

	switch (value) {

	case -1: return '!';

	case -2: return '@';
	}
}
// Snake funtcion -END-

// --

// Pac-Man's function -START-
/*Функции создания поля*/
void FillBackground(){
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j == 0)
			{
				field[i][j] = ' ';
			}
			else
			{
				if (i == 0 && (j > 0 && j <= 11))
					field[i][j] = abc[j - 1];
				if (j == 0 && (i > 0 && i < 11))
					field[i][j] = nums[i - 1];
			}
			if (i != 0 && j != 0)
			{
				field[i][j] = ' ';
			}
		}
	}
}

void FillBackgroundEnemy(){
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j == 0)
			{
				fieldEnemy[i][j] = ' ';
			}
			else
			{
				if (i == 0 && (j > 0 && j <= 11))
					fieldEnemy[i][j] = abc[j - 1];
				if (j == 0 && (i > 0 && i < 11))
					fieldEnemy[i][j] = nums[i - 1];
			}
			if (i != 0 && j != 0)
			{
				fieldEnemy[i][j] = ' ';
			}
		}
	}
}

void FillBackgroundHidden(){
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j == 0)
			{
				fieldHidden[i][j] = ' ';
			}
			else
			{
				if (i == 0 && (j > 0 && j <= 11))
					fieldHidden[i][j] = abc[j - 1];
				if (j == 0 && (i > 0 && i < 11))
					fieldHidden[i][j] = nums[i - 1];
			}
			if (i != 0 && j != 0)
			{
				fieldHidden[i][j] = ' ';
			}
		}
	}
}
/*Функции вывода поля*/
void ShowField(){
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			cout << field[i][j] << ' ';
		}
		cout << endl;
	}
}

void ShowFieldEnemy(){
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			cout << fieldEnemy[i][j] << ' ';
		}
		cout << endl;
	}
}

void ShowFieldHidden(){
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			cout << fieldHidden[i][j] << ' ';
		}
		cout << endl;
	}
}
/*Функции расстоновки кораблей*/
void SetBoats(){
	FillBackground();
	int segments = 5;
	char abc_temp;
	int num = 0;
	int abc1 = 0;
	for (int i = 0; i < 4; i++){
		system("cls");
		ShowField();
		cout << "Сейчас у Вас " << segments - 1 << " ярусный корабль." << endl;
		cout << "Цифра - ?";
		cin >> num;
		cout << "\nБуква - ?";
		cin >> abc_temp;
		for (int i = 1; i < 10; i++){
			if (abc[i - 1] == abc_temp){
				abc1 = i;
			}
		}
		cout << "\nВ каком направлении пойдет корабль?\n(Нажмите на стрелки для задания направления)" << endl;
		int key = _getch();
		key = _getch();
		switch (key){
		case 72:
			for (int i = 1; i < segments; i++){
				field[num + 1 - i][abc1] = '1';
			}
			segments = segments - 1;
			break;
		case 75:
			for (int i = 1; i < segments; i++){
				field[num][abc1 - i + 1] = '1';
			}
			segments = segments - 1;
			break;
		case 77:
			for (int i = 1; i < segments; i++){
				field[num][abc1 - 1 + i] = '1';
			}
			segments = segments - 1;
			break;
		case 80:
			for (int i = 1; i < segments; i++){
				field[num + i - 1][abc1] = '1';
			}
			segments = segments - 1;
			break;
		}

	}
	SetBoatsEnemy();
}

void SetBoatsEnemy(){
	system("cls");
	cout << "Сейчас корабли выстраивает соперник..." << endl;
	int segments = 5;
	char abc_temp;
	int num = 0;
	int abc1 = 0;
	for (int i = 0; i < 4; i++){
		num = rand() % 11;
		abc1 = rand() % 11;
		int key = rand() % 5;
		if (key == 0){
			key = rand() % 5;
		}
		switch (key){
		case 1:
			for (int i = 1; i < segments; i++){
				fieldEnemy[num + 1 - i][abc1] = '1';
			}
			segments = segments - 1;
			break;
		case 2:
			for (int i = 1; i < segments; i++){
				fieldEnemy[num][abc1 - i + 1] = '1';
			}
			segments = segments - 1;
			break;
		case 3:
			for (int i = 1; i < segments; i++){
				fieldEnemy[num][abc1 - 1 + i] = '1';
			}
			segments = segments - 1;
			break;
		case 4:
			for (int i = 1; i < segments; i++){
				fieldEnemy[num + i - 1][abc1] = '1';
			}
			segments = segments - 1;
			break;
		}

	}
	cout << "ГОТОВО!" << endl;
	system("pause");
	begin();
	play();
}
//Просто приветствие
void begin(){
	system("cls");
	system("color 01");
	cout << "НАЧИНАЕМ!" << endl;
	_sleep(1000);
	system("cls");
	system("color 02");
	cout << "НАЧИНАЕМ!" << endl;
	_sleep(1000);
	system("cls");
	system("color 03");
	cout << "НАЧИНАЕМ!" << endl;
	_sleep(1000);
	system("cls");
	system("color 04");
	cout << "НАЧИНАЕМ!" << endl;
	_sleep(1000);
	system("cls");
	system("color 05");
	cout << "НАЧИНАЕМ!" << endl;
	_sleep(1000);
	system("cls");
	system("color 03");
}
/*Сама игра*/
void play(){
	char abc_temp;
	int num = 0;
	int abc1 = 0;
	system("cls");
	cout << "Поле противника:\n" << endl;
	ShowFieldHidden();
	cout << "\n\n" << endl;
	cout << "Ваше поле:\n" << endl;
	ShowField();
	cout << "\n\n" << endl;
	cout << "Цифра - ?";
	cin >> num;
	cout << "\nБуква - ?";
	cin >> abc_temp;
	for (int i = 1; i < 10; i++){
		if (abc[i - 1] == abc_temp){
			abc1 = i;
		}
	}
	if (fieldEnemy[num][abc1] == '1'){
		cout << "ТЫ ПОПАЛ!\x02" << endl;
		fieldEnemy[num][abc1] = 'X';
		fieldHidden[num][abc1] = 'X';
		Win();
		system("pause");
		playEnemy();
	}
	else{
		cout << "ТЫ ПРОМАЗАЛ!" << endl;
		fieldEnemy[num][abc1] = '0';
		fieldHidden[num][abc1] = '0';
		Win();
		system("pause");
		playEnemy();
	}
}

void playEnemy(){
	char abc_temp;
	int num = 0;
	int abc1 = 0;
	system("cls");
	cout << "Поле противника:\n" << endl;
	ShowFieldHidden();
	cout << "\n\n" << endl;
	cout << "Ваше поле:\n" << endl;
	ShowField();
	cout << "\n\n" << endl;
	num = rand() % 11;
	abc1 = rand() % 11;
	if (field[num][abc1] == '1'){
		cout << "Противник попал!" << endl;
		field[num][abc1] = 'X';
		Win();
		system("pause");
		play();
	}
	else{
		cout << "ПРОТИВНИК ПРОМАЗАЛ!\x02" << endl;
		field[num][abc1] = '0';
		Win();
		system("pause");
		play();
	}
}
/*Проверка на победу*/
void Win(){
	int win = 0;
	int win1 = 0;
	for (int i = 0; i > 11; i++){
		for (int j = 0; j > 11; j++){
			if (fieldEnemy[i][j] != '1'){
				win = win + 1;
			}
		}
	}
	if (win == 21){
		system("cls");
		system("color 01");
		cout << "ТЫ ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 02");
		cout << "ТЫ ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 03");
		cout << "ТЫ ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 04");
		cout << "ТЫ ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 05");
		cout << "ТЫ ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 03");
		cout << "Поздравляем, ты победил!\x02\nСпасибо за игру!" << endl;
		_sleep(5000);
		int an = 0;
		cout << "Хочешь сыграть заново?\n1 - Да\n2 - Нет" << endl;
		cin >> an;
		if (an == 1){
			main();
		}
		else{
			if (an == 2){
				system("cls");
				cout << "Спасибо за игру, друг! До скорых встреч!" << endl;
				_sleep(5000);
				system("exit");
			}
		}
	}
	for (int i = 0; i > 11; i++){
		for (int j = 0; j > 11; j++){
			if (field[i][j] != '1'){
				win1 = win1 + 1;
			}
		}
	}
	if (win1 == 21){
		system("cls");
		system("color 01");
		cout << "ПРОТИВНИК ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 02");
		cout << "ПРОТИВНИК ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 03");
		cout << "ПРОТИВНИК ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 04");
		cout << "ПРОТИВНИК ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 05");
		cout << "ПРОТИВНИК ВЫИГРАЛ!" << endl;
		_sleep(1000);
		system("cls");
		system("color 03");
		cout << "Ну ничего, повезет в следующий раз...\nСпасибо за игру!" << endl;
		system("pause");
		system("exit");
	}

}

void mbmain(){
	setlocale(LC_ALL, "rus");
	system("color 03");
	FillBackground();
	FillBackgroundEnemy();
	FillBackgroundHidden();
	cout << "Добро пожаловать в Морской Бой!\nЧерез 5 сек. начнеться игра!\nПРИГОТОВТЕСЬ!" << endl;
	_sleep(5000);
	SetBoats();

}
// mb function -END-


