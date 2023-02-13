# include <Siv3D.hpp> // OpenSiv3D v0.6.5

//int life = 5;//ライフの数

int num = 1;//表示する数字

int score = 0;//スコア

int types = 6;//素数の種類数

Grid<int> mp{//左から2,3,5,7...の個数
	{0,0,0,0,0,0,0,0,0}
};

void make_num() {//乱数によって素数の個数を設定

	for (int i = 0; i < types ; i++) {
		int r = Random<int>(0, 3);
		mp[0][i] = r;
	}

}

void get_num() {//表示するように合成数の形にする

	num = 1;

	for (int i = 0; i < mp[0][0]; i++) num *= 2;
	for (int i = 0; i < mp[0][1]; i++) num *= 3;
	for (int i = 0; i < mp[0][2]; i++) num *= 5;
	for (int i = 0; i < mp[0][3]; i++) num *= 7;
	for (int i = 0; i < mp[0][4]; i++) num *= 11;
	for (int i = 0; i < mp[0][5]; i++) num *= 13;

}

void game() {

	String text_num = U"{}"_fmt(num);//画面に表示する数
	String text_score = U"{}"_fmt(score);//自分のスコア

	const Font font{ 50 };

	int fontsize = 100;

	while (System::Update()) {

		text_num = U"{}"_fmt(num);
		text_score = U"score:{}"_fmt(score);

		if (SimpleGUI::Button(U"2", Vec2{ 20, 500 }, 100)) {
			if (mp[0][0] > 0) {
				mp[0][0]--;
				get_num();
				score++;
			}
		}

		if (SimpleGUI::Button(U"3", Vec2{ 130, 500 }, 100)) {
			if (mp[0][1] > 0) {
				mp[0][1]--;
				get_num();
				score++;
			}
		}

		if (SimpleGUI::Button(U"5", Vec2{ 240, 500 }, 100)) {
			if (mp[0][2] > 0) {
				mp[0][2]--;
				get_num();
				score++;
			}
		}

		if (SimpleGUI::Button(U"7", Vec2{ 350, 500 }, 100)) {
			if (mp[0][3] > 0) {
				mp[0][3]--;
				get_num();
				score++;
			}
		}

		if (SimpleGUI::Button(U"11", Vec2{ 460, 500 }, 100)) {
			if (mp[0][4] > 0) {
				mp[0][4]--;
				get_num();
				score++;
			}
		}

		if (SimpleGUI::Button(U"13", Vec2{ 570, 500 }, 100)) {
			if (mp[0][5] > 0) {
				mp[0][5]--;
				get_num();
				score++;
			}
		}

		if (num == 1) {
			make_num();
			get_num();
			score += 10;
		}

		font(text_num).drawAt(Vec2(300, 320), ColorF{ 0.25 });
		font(text_score).drawAt(Vec2(150, 50), ColorF{ 0.25 });
	}
}

void Main() {

	Window::SetTitle(U"素因数分解ゲーム");

	Scene::SetBackground(Palette::White);

	while (System::Update())
	{
		make_num();
		get_num();
		game();
	}
}
