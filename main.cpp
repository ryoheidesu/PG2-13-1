#include <Novice.h>
#include"enemy.h"
#include"Player.h"
#include<math.h>

const char kWindowTitle[] = "GC1A_23_ミツイ_リョウヘイ_タイトル";


bool Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy* enemyA = new Enemy(30, 500, 400, Living, RED);
	Enemy* enemyB = new Enemy(30, 80, 30, Living, RED);

	Player* player = new Player(400, 700);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);

		enemyA->Update();
		enemyB->Update();


		for (int i = 0; i < 5; i++) {
			float a, b, c;
			a = player->getBulletPos_(i).X - enemyA->getPosX();
			b = player->getBulletPos_(i).Y - enemyA->getPosY();
			c = sqrtf(pow(a, 2) + pow(b, 2));

			if (c <= 50) {
				Enemy::isAlive_ = false;
			}

			float d, e, f;
			d = player->getBulletPos_(i).X - enemyB->getPosX();
			e = player->getBulletPos_(i).Y - enemyB->getPosY();
			f = sqrtf(pow(d, 2) + pow(e, 2));

			if (f <= 50) {
				Enemy::isAlive_ = false;
			}
		}

		if (keys[DIK_R] && preKeys[DIK_R] == 0) {
			Enemy::isAlive_ = true;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemyA->Draw();
		enemyB->Draw();

		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
